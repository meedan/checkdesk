<?php
/**
 * @file
 * Wizard implementation for Drupal-to-Drupal migrations.
 */

/*
 * Implementation of hook_migrate_api().
 */
function migrate_d2d_ui_migrate_api() {
  $api = array(
    'api' => 2,
    'wizard classes' => array('MigrateD2DWizard'),
  );
  return $api;
}

class MigrateD2DWizard extends MigrateUIWizard {
  /**
   * Database array for the source Drupal installation.
   *
   * @var array
   */
  protected $database;

  /**
   * Source Drupal version (5, 6, or 7).
   *
   * @var int
   */
  protected $sourceVersion;

  /**
   * Whether we will be importing users.
   *
   * @var bool
   */
  protected $userMigration = FALSE;

  protected $userCount;

  /**
   * Mappings of source vocabulary vids to destination vocabulary machine names.
   *
   * @var array
   */
  protected $vocabularyMappings = array();

  protected $termCounts = array();

  /**
   * Whether we will be importing user pictures.
   *
   * @var bool
   */
  protected $pictureMigration = FALSE;

  /**
   * Whether we will be importing files other than user pictures.
   *
   * @var bool
   */
  protected $fileMigration = FALSE;

  /**
   * Source site directory from which to fetch files.
   *
   * @var string
   */
  protected $sourceDirectory = '';

  /**
   * Mappings of source content types to destination content types (by machine
   * name).
   *
   * @var array
   */
  protected $typeMappings = array();

  protected $nodeCounts = array();

  /**
   * Mappings between role names.
   *
   * @var array
   */
  protected $roleMappings = array();

  /**
   * Default role to assign to users.
   *
   * @var string
   */
  protected $defaultRole = 'authenticated user';

  /**
   * Mappings between text formats.
   *
   * @var array
   */
  protected $formatMappings = array();

  /**
   * For each content type, whether to migrate its comments.
   *
   * @var array
   */
  protected $comments = array();

  /**
   * Lay out the basic steps of the wizard.
   */
  public function __construct() {
    parent::__construct();
    $this->addStep(t('Credentials'), 'sourceDataForm');
    $this->addStep(t('Users'), 'userForm');
    if (module_exists('taxonomy')) {
      $this->addStep(t('Taxonomy'), 'taxonomyForm');
    }
    $this->addStep(t('Files'), 'fileForm');
    $this->addStep(t('Content Types'), 'contentTypeForm');
    $this->addStep(t('Review'), 'reviewForm');
  }

  /**
   * Case-insensitively search for a value in an array.
   *
   * @param $value
   * @param $array
   */
  protected function caseArraySearch($needle, $haystack) {
    foreach ($haystack as $key => $value) {
      if (!strcasecmp($needle, $value)) {
        return $key;
      }
    }
    return FALSE;
  }

  /**
   * Identify ourselves.
   *
   * @return string
   */
  public function getSourceName() {
    return t('Drupal');
  }

  /**
   * Second step - find out how to get the source data.
   */
  public function sourceDataForm(&$form_state) {
    $form['description'] = array(
      '#prefix' => '<p>',
      '#markup' => t('You will be led through a series of steps, allowing you to ' .
        'customize what will be imported into Drupal and how it will be mapped. ' .
        'At the end of this process, a migration job will be '.
        'generated and you will be left at the dashboard, from which ' .
        'you can perform the import, monitor its progress, roll it back, etc.'),
      '#suffix' => '</p>',
    );

    $form['overview'] = array(
      '#prefix' => '<p>',
      '#markup' => t('External Drupal sites (versions 5, 6, or 7) can be imported ' .
       'into Drupal using this form. Please provide database credentials for the ' .
       'external Drupal site. It is recommended that this not be the same database ' .
       'user as is used by the site, but a user with read-only privileges.'),
      '#suffix' => '</p>',
    );

    // Copied from includes/install.core.inc, install_settings_form()
    require_once DRUPAL_ROOT . '/includes/install.inc';
    $drivers = drupal_get_database_types();
    $drivers_keys = array_keys($drivers);

    $form['driver'] = array(
      '#type' => 'radios',
      '#title' => t('Source database type'),
      '#required' => TRUE,
      '#default_value' => !empty($form_state['values']['driver']) ?
        $form_state['values']['driver'] : current($drivers_keys),
      '#description' => t('The type of database your source data is stored in.'),
    );
    if (count($drivers) == 1) {
      $form['driver']['#disabled'] = TRUE;
      $form['driver']['#description'] .= ' ' . st('Your PHP configuration only supports a single database type, so it has been automatically selected.');
    }

    // Add driver specific configuration options.
    foreach ($drivers as $key => $driver) {
      $form['driver']['#options'][$key] = $driver->name();
      $form['settings'][$key] = $driver->getFormOptions(array());
      // Rewrite descriptions, which assume the database is being selected to
      // install Drupal into.
      switch ($key) {
        case 'mysql':
        case 'pgsql':
          $form['settings'][$key]['database']['#description'] =
            t('The name of the database your legacy Drupal data is stored in.');
          break;
        case 'sqlite':
          $form['settings'][$key]['database']['#description'] =
            t('The absolute path to the file where your legacy Drupal data is stored');
          break;
      }
      // The host is likely to not be localhost, so move out of advanced options
      if (isset($form['settings'][$key]['advanced_options']['host'])) {
        $form['settings'][$key]['host'] = $form['settings'][$key]['advanced_options']['host'];
        unset($form['settings'][$key]['advanced_options']['host']);
      }
      $form['settings'][$key]['#prefix'] = '<h2 class="js-hide">' . t('@driver_name settings', array('@driver_name' => $driver->name())) . '</h2>';
      $form['settings'][$key]['#type'] = 'container';
      $form['settings'][$key]['#tree'] = TRUE;
      $form['settings'][$key]['advanced_options']['#parents'] = array($key);
      $form['settings'][$key]['#states'] = array(
        'visible' => array(
          ':input[name=driver]' => array('value' => $key),
        )
      );
    }

    return $form;
  }

  /**
   * Override the basic form to add appropriate driver validation.
   *
   * @return array
   */
  public function form(&$form_state) {
    $form = parent::form($form_state);

    // Detect if we are on the DB step of migrate_d2d_ui wizard.
    if (isset($form['driver'])) {
      // Limit validation errors to fields associated with the selected DB
      // driver. e.g. validate DB name/host for mysql but not for sqlite.
      $validation = array();
      $validation[] = array('driver');
      if (isset($form_state['input']['driver'])) {
        $validation[] = array('settings', $form_state['input']['driver']);
      }
      $form['actions']['next']['#limit_validation_errors'] = $validation;
    }

    return($form);
  }

  /**
   * Save the database access information, and make sure we can actually connect.
   *
   * @param array $form_state
   */
  protected function sourceDataFormValidate(&$form_state) {
    $this->database = $form_state['values'][$form_state['values']['driver']];
    $this->database['driver'] = $form_state['values']['driver'];
    $form_state['storage']['database'] = $this->database;

    // Make sure we can connect
    try {
      $admin_uid = $this->connection()->select('users', 'u')
                   ->fields('u', array('uid'))
                   ->condition('uid', 1)
                   ->execute()
                   ->fetchField();
      if ($admin_uid) {
        // Format module is required by D6 and D7, table name changed.
        if ($this->connection()->schema()->tableExists('filter_format')) {
          $this->sourceVersion = '7';
        }
        // Menus refactored in D6.
        elseif ($this->connection()->schema()->tableExists('menu_router')) {
          $this->sourceVersion = '6';
        }
        else {
          $this->sourceVersion = '5';
        }

        // Use the site_name as the group name
        $site_name = $this->connection()->select('variable', 'v')
                     ->fields('v', array('value'))
                     ->condition('name', 'site_name')
                     ->execute()
                     ->fetchField();
        $site_name = unserialize($site_name);
        if ($site_name) {
          $this->groupTitle = $site_name;
          if (function_exists('transliteration_get')) {
            $site_name = transliteration_get($site_name);
          }
          $this->groupName = preg_replace('/[^A-Za-z0-9]/', '', $site_name);
          if (strlen($this->groupName) > 9) {
            $this->groupName = substr(md5($this->groupName), 0, 9);
          }
          elseif (empty($this->groupName)) {
            $this->groupName = substr(md5($site_name), 0, 9);
          }
        }
        else {
          $this->groupName = $this->groupTitle = 'd' . $this->sourceVersion;
        }
      }
      else {
        form_set_error('driver', t('The source database does not appear to be a Drupal database.'));
      }
    }
    catch (Exception $e) {
      form_set_error('driver', t('Failed to connect to source database, message returned: %message',
        array('%message' => $e->getMessage())));
      return;
    }
  }

  /**
   * Present information and options around user migration.
   */
  protected function userForm(&$form_state) {
    $form['overview'] = array(
      '#prefix' => '<p>',
      '#markup' => t('User accounts other than the admin account (user ID 1)
         may be imported to this site.'),
      '#suffix' => '</p>',
    );
    $form['#tree'] = TRUE;
    if (!isset($this->userCount)) {
      $this->userCount = $this->connection()->select('users', 'u')
                  ->condition('uid', 1, '>')
                  ->countQuery()
                  ->execute()
                  ->fetchField();
    }
    $form['users'] = array(
      '#prefix' => '<div>',
      '#markup' => t('Number of users available to be migrated from your Drupal !version site: !count',
                     array('!version' => $this->sourceVersion, '!count' => $this->userCount)),
      '#postfix' => '</div>',
    );
    $form['do_migration'] = array(
      '#type' => 'checkbox',
      '#title' => t('Perform import of users'),
      '#default_value' => TRUE,
    );

    // Build select list from destination roles.
    $base_options = array(
      '-1' => t('--Do not import--'),
      '0' => t('--Create role--'),
    );
    $result = db_select('role', 'r')
              ->fields('r', array('name'))
              ->condition('name', array('anonymous user', 'authenticated user'), 'NOT IN')
              ->execute();
    $role_options = array();
    foreach ($result as $row) {
      $role_options[$row->name] = $row->name;
    }

    // Go through the non-trivial source roles.
    $result = $this->connection()->select('role', 'r')
              ->fields('r', array('rid', 'name'))
              ->condition('name', array('anonymous user', 'authenticated user'), 'NOT IN')
              ->execute();
    $source_roles = array();
    foreach ($result as $row) {
      $source_roles[$row->rid] = $row->name;
    }

    if (!empty($source_roles)) {
      // Description
      $form['role_overview'] = array(
        '#prefix' => '<div>',
        '#markup' => t('For each user role on the legacy site, choose whether ' .
          'to ignore that role, to create it on this site, or to assign a different ' .
          'role to users with that legacy role.'),
        '#suffix' => '</div>',
      );
      foreach ($source_roles as $rid => $name) {
        $options = $base_options + $role_options;
        // If we have a match on role name, default the mapping to that match
        // and remove the option to create a new type of that name.
        if (in_array($name, $role_options)) {
          $default_value = $name;
          unset($options['0']);
        }
        else {
          $default_value = '-1';
        }
        $count = $this->connection()->select('users_roles', 'ur')
                      ->condition('rid', $rid)
                      ->countQuery()
                      ->execute()
                      ->fetchField();
        $title = t('@name (@count)', array('@name' => $name,
          '@count' => format_plural($count, '1 user', '@count users')));
        $form['role'][$name] = array(
          '#type' => 'select',
          '#title' => $title,
          '#options' => $options,
          '#default_value' => $default_value,
        );
      }
      // Set our theme function for this form
      $form['role']['#theme'][] = 'migrate_d2d_ui_role_form';
    }
    else {
      $form['role_overview'] = array(
        '#prefix' => '<div>',
        '#markup' =>t('There are no user roles in the source site that are not already
          in the destination site'),
        '#suffix' => '</div>',
      );
    }

    $options = array('authenticated user' => 'authenticated user') +
               $role_options;
    $form['default_role'] = array(
      '#type' => 'select',
      '#title' => t('Default role'),
      '#description' => t('Choose the role to assign to any user accounts who ' .
        'had none of the above roles on the legacy site'),
      '#options' => $options,
      '#default_value' => DRUPAL_AUTHENTICATED_RID,
    );

    return $form;
  }

  /**
   * Prepare for registration of any user-related migrations.
   *
   * @param array $form_state
   */
  protected function userFormValidate(&$form_state) {
    if ($form_state['values']['do_migration']) {
      $this->userMigration = TRUE;
      $this->roleMappings = $form_state['values']['role'];
      $this->defaultRole = $form_state['values']['default_role'];
      // Map "do not import" roles to the default role, and remove roles
      // to be created so they get imported naturally.
      foreach ($this->roleMappings as $source_role => $destination_role) {
        if ($destination_role == '-1') {
          $this->roleMappings[$source_role] = $this->defaultRole;
        }
        elseif ($destination_role == '0') {
          unset($this->roleMappings[$source_role]);
        }
      }
      // Default role needs to be a rid
      $this->defaultRole = db_select('role', 'r')
                           ->fields('r', array('rid'))
                           ->condition('name', $this->defaultRole)
                           ->execute()
                           ->fetchField(0);
    }
    else {
      $this->userMigration = FALSE;
    }
  }

  /**
   * Choose what source vocabularies to import into what destination vocabularies.
   */
  protected function taxonomyForm(&$form_state) {
    if ($this->connection()->schema()->tableExists('taxonomy_vocabulary')) {
      $vocab_table = 'taxonomy_vocabulary';
      $term_table = 'taxonomy_term_data';
    }
    elseif ($this->connection()->schema()->tableExists('vocabulary')) {
      $vocab_table = 'vocabulary';
      $term_table = 'term_data';
    }
    else {
      $vocab_table = '';
      $term_table = '';
    }

    if ($vocab_table) {
      $vocab_count = $this->connection()->select($vocab_table, 'v')
                     ->fields('v', array('vid'))
                     ->countQuery()
                     ->execute()
                     ->fetchField();
    }
    else {
      $vocab_count = 0;
    }
    if (!$vocab_count) {
      $form['description'] = array(
        '#prefix' => '<div>',
        '#markup' => t('There is no vocabulary data to be migrated from the source database.'),
        '#suffix' => '</div>',
      );
      return $form;
    }
    $form['#tree'] = TRUE;
    $form['description'] = array(
      '#prefix' => '<div>',
/*
      '#markup' => t('For each vocabulary on the source site, choose the destination
        site vocabulary to import its terms. You may also choose not to import a given
        vocabulary, or automatically create a new vocabulary of the same name if
        one does not already exist.'),*/
      '#markup' => t('For each vocabulary on the source site, choose the destination
        site vocabulary to import its terms. You may also choose not to import a given
        vocabulary.'),
      '#suffix' => '</div>',
    );

    if (empty($this->termCounts)) {
      $get_term_counts = TRUE;
    }
    else {
      $get_term_counts = FALSE;
    }
    $base_options = array(
      -1 => t('--Do not import--'),
      // @todo: Not yet supported
//      0 => t('--Create vocabulary--'),
    );
    $vocab_options = array();
    $local_vocabs = taxonomy_get_vocabularies();
    foreach ($local_vocabs as $vocab) {
      $vocab_options[$vocab->machine_name] = $vocab->name;
    }
    $result = $this->connection()->select($vocab_table, 'v')
              ->fields('v', array('vid', 'name'))
              ->execute();
    foreach ($result as $vocab) {
      $options = $base_options + $vocab_options;
      // If we have a match on vocabulary name, default the mapping to that match
      // and remove the option to create a new vocabulary of that name.
      if ($vid = array_search($vocab->name, $vocab_options)) {
        $default_value = $vid;
        unset($options[0]);
      }
      else {
        $default_value = -1;
      }

      if ($get_term_counts) {
        $this->termCounts[$vocab->vid] = $this->connection()->select($term_table, 't')
                      ->condition('vid', $vocab->vid)
                      ->countQuery()
                      ->execute()
                      ->fetchField();
      }
      $title = t('@name (@count)', array('@name' => $vocab->name,
        '@count' => format_plural($this->termCounts[$vocab->vid], '1 term', '@count terms')));
      $form['vocab'][$vocab->vid] = array(
        '#type' => 'select',
        '#title' => $title,
        '#options' => $options,
        '#default_value' => $default_value,
      );
    }

    // Set our theme function for this form
    $form['vocab']['#theme'][] = 'migrate_d2d_ui_vocab_form';

    return $form;
  }

  /**
   * Save the selected vocabulary mappings, as an array keyed by source vid and
   * containing the destination machine_name (bundle).
   */
  protected function taxonomyFormValidate(&$form_state) {
    $this->vocabularyMappings = $form_state['values']['vocab'];
  }

  /**
   * Configure file migration.
   */
  protected function fileForm(&$form_state) {
    if ($this->connection()->schema()->tableExists('file_managed')) {
      $file_table = 'file_managed';
    }
    else {
      $file_table = 'files';
    }

    $file_count = $this->connection()->select($file_table, 'f')
                     ->fields('f', array('fid'))
                     ->countQuery()
                     ->execute()
                     ->fetchField();

    if ($file_count) {
      if ($this->userMigration) {
        $form['picture_migration'] = array(
          '#type' => 'checkbox',
          '#title' => t('Perform import of user pictures'),
          '#default_value' => TRUE,
        );
      }
      else {
        $form['picture_migration'] = array(
          '#type' => 'value',
          '#value' => FALSE,
        );
      }
      $form['file_migration'] = array(
        '#type' => 'checkbox',
        '#title' => t('Perform import of files other than user pictures'),
        '#default_value' => TRUE,
      );

      if ($this->sourceVersion == 7) {
        $form['instructions'] = array(
          '#prefix' => '<div>',
          '#markup' => t('To be able to retrieve any uploaded files from your ' .
            'legacy site, we need to know where to find them. If your legacy site '.
            'is on the same web server as the destination site, or you have copied '.
            'your file directory to the web server, please provide the full ' .
            'file directory - for example, <em>/var/www/drupal/sites/example.com/files/</em>. ' .
            'Otherwise, we need the web address of that directory. To determine that address: ' .
            '<ol><li>Please visit a node on the site containing images, or a user ' .
            'profile with an uploaded picture. Try to find an example where the ' .
            'full resolution image is displayed.</li> '.
            '<li>Right-click on the picture and look for an operation such as ' .
            '<em>View Image</em>.</li> '.
            '<li>Choose that function and look at the URL of the image - it will ' .
            'usually look something like ' .
            '<em>http://example.com/sites/default/files/pictures/picture-3.jpg</em> ' .
            '(for user pictures) or ' .
            '<em>http://example.com/sites/default/files/my-photo.jpg</em> ' .
            '(for files uploaded to nodes).</li> ' .
            '<li>If you see after the <em>files</em> portion of the path something ' .
            'like <em>styles</em> or <em>imagecache</em>, you are most likely ' .
            'looking at an automatically generated variation of the image, not the ' .
            'original. It will take some trial and error, removing intermediate ' .
            'portions of the path (such as <em>styles/medium/</em>) to find the ' .
            'original image.</li> ' .
            '<li>Please enter the full address of the files directory ' .
            '(<em>http://example.com/sites/default/files/</em>) below. Leave the ' .
            'field empty to skip migrating files.</li></ol>'),
          '#suffix' => '</div>',
        );
      }
      else {
        $form['instructions'] = array(
          '#prefix' => '<div>',
          '#markup' => t('To be able to retrieve any uploaded files from your ' .
            'legacy site, we need to know where to find them. If your legacy site '.
            'is on the same web server as the destination site, or you have copied '.
            'your file directory to the web server, please provide the full ' .
            'file directory - for example, <em>/var/www/drupal/sites/example.com/files/</em>. ' .
            'Otherwise, please provide the address of your legacy site (e.g., ' .
            '<em>http://example.com/</em> below. Leave the ' .
            'field empty to skip migrating files.'),
          '#suffix' => '</div>',
        );
      }

      $form['description'] = array(
        '#prefix' => '<div>',
        '#markup' => t('There are !count files (including user pictures) ' .
                'available to be migrated.', array('!count' => $file_count)),
        '#suffix' => '</div>',
      );

      $form['source_directory'] = array(
        '#type' => 'textfield',
        '#size' => 60,
        '#title' => t('File prefix'),
      );
    }
    else {
      $form['description'] = array(
        '#prefix' => '<div>',
        '#markup' => t('There are no files to be migrated from your source site.'),
        '#suffix' => '</div>',
      );
    }

    return $form;
  }

  /**
   * Save the selected vocabulary mappings, as an array keyed by source vid and
   * containing the destination machine_name (bundle).
   */
  protected function fileFormValidate(&$form_state) {
    if (isset($form_state['values']['source_directory'])) {
      $this->sourceDirectory = $form_state['values']['source_directory'];
      if ($form_state['values']['picture_migration']) {
        $this->pictureMigration = TRUE;
      }
      if ($form_state['values']['file_migration']) {
        $this->fileMigration = TRUE;
      }
    }
  }

  /**
   * Form for mapping source content (node) types to destination types.
   */
  protected function contentTypeForm(&$form_state) {
    $type_count = $this->connection()->select('node_type', 't')
                    ->fields('t', array('type', 'name'))
                    ->countQuery()
                    ->execute()
                    ->fetchField();
    if (!$type_count) {
      $form['description'] = array(
        '#prefix' => '<div>',
        '#markup' => t('There is no node data to be migrated from the source database.'),
        '#suffix' => '</div>',
      );
      return $form;
    }
    $form['#tree'] = TRUE;
    $form['description'] = array(
      '#prefix' => '<div>',
      '#markup' => t('For each content type on the source site, choose the destination
        site content type to import its content. You may also choose not to import a given
        content type.'),
      '#suffix' => '</div>',
    );

    if (empty($this->nodeCounts)) {
      $get_node_counts = TRUE;
    }
    else {
      $get_node_counts = FALSE;
    }
    $base_options = array(
      '-1' => t('--Do not import--'),
      // @todo: Not yet supported
//      '0' => t('--Create content type--'),
    );
    $node_options = array();
    $local_types = node_type_get_types();
    foreach ($local_types as $type => $info) {
      $node_options[$type] = $info->name;
    }
    asort($node_options);

    $result = $this->connection()->select('node_type', 't')
              ->fields('t', array('type', 'name'))
              ->orderBy('name')
              ->execute();
    foreach ($result as $row) {
      // @todo: Skip any node type used by content_profile
      $options = $base_options + $node_options;
      // If we have a match on type name, default the mapping to that match
      // and remove the option to create a new type of that name.
      if (isset($node_options[$row->type])) {
        $default_value = $row->type;
        unset($options['0']);
      }
      else {
        $default_value = '-1';
      }
      if ($get_node_counts) {
        $this->nodeCounts[$row->type] = $this->connection()->select('node', 'n')
                      ->condition('type', $row->type)
                      ->countQuery()
                      ->execute()
                      ->fetchField();
        // But, always default to do-not-import if there are no nodes.
        if ($this->nodeCounts[$row->type] == 0) {
          $default_value = '-1';
        }
      }
      if ($this->nodeCounts[$row->type] > 0) {
        $title = t('@name (@count)', array('@name' => $row->name,
          '@count' => format_plural($this->nodeCounts[$row->type], '1 node', '@count nodes')));
        $form['type'][$row->type] = array(
          '#type' => 'select',
          '#title' => $title,
          '#options' => $options,
          '#default_value' => $default_value,
        );

      }
    }

    // Set our theme function for this form
    $form['type']['#theme'] = 'migrate_d2d_ui_content_type_form';

    // Build select list from destination formats.
    $base_options = array(
      '-1' => t('--Do not import--'),
//      '0' => t('--Create format--'),
    );

    // Destination formats
    $result = db_select('filter_format', 'f')
              ->fields('f', array('format', 'name'))
              ->execute();
    foreach ($result as $row) {
      $format_options[$row->format] = $row->name;
    }
    if ($this->sourceVersion == '7') {
      $table = 'filter_format';
    }
    else {
      $table = 'filter_formats';
    }
    $result = $this->connection()->select($table, 'f')
              ->fields('f', array('format', 'name'))
              ->execute();
    $form['format_overview'] = array(
      '#prefix' => '<div>',
      '#markup' => t('For each text format on the legacy site, choose whether ' .
        'to ignore that format, or to assign a different format to content ' .
        'with that legacy format.'),
      '#suffix' => '</div>',
    );
    foreach ($result as $row) {
      $options = $base_options + $format_options;
      // If we have a match on format name, default the mapping to that match.
      if ($match = $this->caseArraySearch($row->name, $format_options)) {
        $default_value = $match;
        unset($options['0']);
      }
      else {
        $default_value = '-1';
      }
      $form['format'][$row->format] = array(
        '#type' => 'select',
        '#title' => $row->name,
        '#options' => $options,
        '#default_value' => $default_value,
      );
    }
    // Set our theme function for this form
    $form['format']['#theme'][] = 'migrate_d2d_ui_format_form';

    return $form;
  }

  /**
   * Save the selected type mappings, as an array keyed by source type and
   * containing the destination type (bundle).
   */
  protected function contentTypeFormValidate(&$form_state) {
    // Start with ourselves
    $after = $this->currentStep;
    $this->typeMappings = array();
    if (isset($form_state['values']['type'])) {
      foreach ($form_state['values']['type'] as $source_type => $dest_type) {
        $this->typeMappings[$source_type] = $dest_type;
      }
    }
    $this->formatMappings = $form_state['values']['format'];
  }

  /**
   * Show the user what they've chosen to migrate, and give them one last chance
   * to say yay or nay.
   */
  protected function reviewForm(&$form_state) {
    // In case we've been going back-and-forth with Previous, make sure we
    // start with no migrations - all migrations will be added here.
    $this->migrations = array();

    $this->groupArguments = array(
      'encrypted_arguments' => array('source_database'),
      'source_version' => $this->sourceVersion,
      'source_connection' => $this->groupName . '_legacy',
      'source_database' => $this->database,
      'source_system' => t('Drupal @version', array('@version' => $this->sourceVersion)),
      'format_mappings' => $this->formatMappings,
    );

    $message = t('<p>Please review your migration settings. When you submit this
      form, a migration job containing a migration task for each type of item to be
      imported will be created and you will be left at the
      dashboard.</p>');

    $form['description'] = array(
      '#prefix' => '<div>',
      '#markup' => $message,
      '#suffix' => '</div>',
    );

    $imports = $non_imports = '';
    if ($this->userMigration) {
      $arguments = array(
        'description' => t('Migration of roles from Drupal @version',
                         array('@version' => $this->sourceVersion)),
        'role_mappings' => $this->roleMappings,
      );
      $this->addMigration('Role', "DrupalRole{$this->sourceVersion}Migration",
                          $arguments);

      $admin_name = $this->connection()->select('users', 'u')
                    ->fields('u', array('name'))
                    ->condition('uid', 1)
                    ->execute()
                    ->fetchField();
      $imports .= t('<li>%count user accounts (omitting the administrative account ' .
        '%admin) will be imported.</li>',
        array('%admin' => $admin_name, '%count' => $this->userCount));
      $arguments = array(
        'description' => t('Migration of users from Drupal @version',
                 array('@version' => $this->sourceVersion)),
        'role_migration' => $this->groupName . 'Role',
      );
      $mapping = new MigrateFieldMapping('roles', 'roles');
      $mapping->sourceMigration($this->groupName . 'Role')
              ->defaultValue($this->defaultRole);
      $arguments['field_mappings'][] = $mapping;
      if ($this->pictureMigration) {
        $picture_arguments = array(
          'source_dir' => $this->sourceDirectory,
          'description' => t('Migration of user pictures from Drupal @version',
            array('@version' => $this->sourceVersion)),
        );
        $this->addMigration('Picture', "DrupalPicture{$this->sourceVersion}Migration",
                            $picture_arguments);
        $arguments['picture_migration'] = $this->groupName . 'Picture';
        $mapping = new MigrateFieldMapping('picture', 'picture');
        $mapping->sourceMigration($this->groupName . 'Picture');
        $arguments['field_mappings'][] = $mapping;
      }
      $this->addMigration('User', "DrupalUser{$this->sourceVersion}Migration", $arguments);
    }
    else {
      $non_imports .= t('<li>User accounts will not be migrated</li>');
    }

    if ($this->connection()->schema()->tableExists('taxonomy_vocabulary')) {
      $vocab_table = 'taxonomy_vocabulary';
    }
    elseif ($this->connection()->schema()->tableExists('vocabulary')) {
      $vocab_table = 'vocabulary';
    }

    foreach ($this->vocabularyMappings as $source_vid => $destination_name) {
      $source_vocabulary = $this->connection()->select($vocab_table, 'v')
                           ->fields('v', array('name'))
                           ->condition('vid', $source_vid)
                           ->execute()
                           ->fetchField();
      $count = format_plural($this->termCounts[$source_vid], '1 term', '@count terms');
      if ($destination_name == '-1') {
        $non_imports .= t('<li>The %vocabulary vocabulary will not be imported.</li>',
          array('%vocabulary' => $source_vocabulary));
      }
      else {
        if ($destination_name == '0') {
          $imports .= t('<li>The %vocabulary vocabulary will be created with %count.</li>',
                           array('%vocabulary' => $source_vocabulary, '%count' => $count));
        }
        else {
          $destination_vocabulary = db_select('taxonomy_vocabulary', 'v')
            ->fields('v', array('name'))
            ->condition('machine_name', $destination_name)
            ->execute()
            ->fetchField();
          $imports .= t('<li>%count from %source will be imported into the %destination vocabulary.</li>',
                           array('%source' => $source_vocabulary, '%destination' => $destination_vocabulary,
                             '%count' => $count));
        }
        $arguments = array(
          'destination_vocabulary' => $destination_name,
          'description' => t('Migration of @vocabulary terms from Drupal @version',
                   array('@vocabulary' => $source_vocabulary,
                         '@version' => $this->sourceVersion)),
        );
        if ($this->sourceVersion == 7) {
          $arguments['source_vocabulary'] = $this->connection()->select($vocab_table, 'v')
                                            ->fields('v', array('machine_name'))
                                            ->condition('vid', $source_vid)
                                            ->execute()
                                            ->fetchField();
        }
        else {
          $arguments['source_vocabulary'] = $source_vid;
        }
        $this->addMigration('Term' . $arguments['source_vocabulary'],
                            "DrupalTerm{$this->sourceVersion}Migration", $arguments);
      }
    }

    if ($this->fileMigration) {
      $arguments = array(
        'source_dir' => $this->sourceDirectory,
        'description' => t('Migration of files from Drupal @version',
                 array('@version' => $this->sourceVersion)),
      );
      if ($this->userMigration) {
        $arguments['user_migration'] = $this->groupName . 'User';
      }
      $this->addMigration('File', "DrupalFile{$this->sourceVersion}Migration",
                          $arguments);
    }

    if (module_exists('comment')) {
      if ($this->connection()->schema()->tableExists('comments')) {
        $comment_table = 'comments';
      }
      elseif ($this->connection()->schema()->tableExists('comment')) {
        $comment_table = 'comment';
      }
      else {
        $comment_table = '';
      }
    }
    else {
      $comment_table = '';
    }

    foreach ($this->typeMappings as $source_type => $destination_type) {
      $source_name = $this->connection()->select('node_type', 'nt')
                           ->fields('nt', array('name'))
                           ->condition('type', $source_type)
                           ->execute()
                           ->fetchField();
      $count = format_plural($this->nodeCounts[$source_type], '1 node', '@count nodes');
      if ($destination_type == '-1') {
        $non_imports .= t('<li>The %type content type will not be imported.</li>',
          array('%type' => $source_name));
      }
      else {
        if ($destination_type == '0') {
          $imports .= t('<li>The %type content type will be created with %count.</li>',
                           array('%type' => $source_name, '%count' => $count));
        }
        else {
          $destination_type_name = db_select('node_type', 'nt')
            ->fields('nt', array('name'))
            ->condition('type', $destination_type)
            ->execute()
            ->fetchField();
          $imports .= t('<li>%count from %source will be imported into the %destination content type.</li>',
                           array('%count' => $count, '%source' => $source_name, '%destination' => $destination_type_name));
        }
        $arguments = array(
          'source_type' => $source_type,
          'destination_type' => $destination_type,
          'description' => t('Migration of @source_type nodes from Drupal @version',
                   array('@source_type' => $source_name,
                         '@version' => $this->sourceVersion)),
        );
        if ($this->userMigration) {
          $arguments['user_migration'] = $this->groupName . 'User';
          $mapping = new MigrateFieldMapping('uid', 'uid');
          $mapping->sourceMigration($this->groupName . 'User');
          $arguments['field_mappings'][] = $mapping;
        }
        // Hard to tell what node migrations might need files, so make sure they
        // all fall after it. @todo: Be smarter about this
        if ($this->fileMigration) {
          $arguments['soft_dependencies'] = array('File');
        }
        $this->addMigration('Node' . $arguments['source_type'],
                            "DrupalNode{$this->sourceVersion}Migration", $arguments);
        $num_comments = 0;
        if ($comment_table &&
            (variable_get('comment_' . $destination_type, COMMENT_NODE_OPEN) != COMMENT_NODE_CLOSED)) {
          $query = $this->connection()->select('node', 'n')
                   ->condition('n.type', $source_type);
          $query->innerJoin($comment_table, 'c', 'n.nid=c.nid');
          $num_comments = $query->countQuery()->execute()->fetchField();
        }

        if ($num_comments) {
          $arguments['description'] = t('Migration of @source_type comments from Drupal @version',
                             array('@vocabulary' => $source_name,
                                   '@version' => $this->sourceVersion));
          $arguments['node_migration'] = $this->groupName . 'Node' . $arguments['source_type'];
          $this->addMigration('Comment' . $arguments['source_type'],
                              "DrupalComment{$this->sourceVersion}Migration", $arguments);
        }
      }
    }

    $form['import_list'] = array(
      '#prefix' => '<ul>',
      '#markup' => $imports,
      '#suffix' => '</ul><br />',
    );

    $form['non_import_list'] = array(
      '#prefix' => '<ul>',
      '#markup' => $non_imports,
      '#suffix' => '</ul>',
    );

    return $form;
  }

  /**
   * Gets a connection to the source Drupal database, based on the database
   * information saved by the sourceDataForm.
   *
   * @return DatabaseConnection
   */
  protected function connection() {
    // The Wizard class must be serializable so it can be saved between steps.
    // Thus, the connection cannot be a member of the class - we need to
    // keep it in memory.
    static $connection;
    if (!isset($connection)) {
      $connection_key = $this->groupName . '_legacy';
      $this->database['prefix'] = $this->database['db_prefix'];
      Database::addConnectionInfo($connection_key, 'default', $this->database);
      $connection = Database::getConnection('default', $connection_key);
    }
    return $connection;
  }
}

/**
 * Theme function to layout field mappings in a table.
 *
 * @param array $variables
 *
 * @return string
 *  Rendered markup.
 */
function theme_migrate_d2d_ui_content_type_form($variables) {
  $output = '';
  $form = $variables['type'];
  $elements = element_children($form);
  if (!empty($elements)) {
    $header = array(t('Source type'), t('Destination type'));
    $rows = array();
    foreach ($elements as $source_type) {
      if ($form[$source_type]['#type'] == 'select') {
        $row = array();
        $title = $form[$source_type]['#title'];
        unset($form[$source_type]['#title']);
        $row[] = $title;
        $row[] = drupal_render($form[$source_type]);
        $rows[] = $row;
      }
    }
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
  }
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Theme function to layout vocabulary mappings in a table.
 *
 * @param array $variables
 *
 * @return string
 *  Rendered markup.
 */
function theme_migrate_d2d_ui_vocab_form($variables) {
  $output = '';
  $form = $variables['vocab'];
  $elements = element_children($form);
  if (!empty($elements)) {
    $header = array(t('Source vocabulary'), t('Destination vocabulary'));
    $rows = array();
    foreach ($elements as $source_type) {
      if ($form[$source_type]['#type'] == 'select') {
        $row = array();
        $title = $form[$source_type]['#title'];
        unset($form[$source_type]['#title']);
        $row[] = $title;
        $row[] = drupal_render($form[$source_type]);
        $rows[] = $row;
      }
    }
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
  }
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Theme function to layout role mappings in a table.
 *
 * @param array $variables
 *
 * @return string
 *  Rendered markup.
 */
function theme_migrate_d2d_ui_role_form($variables) {
  $output = '';
  $form = $variables['role'];
  $elements = element_children($form);
  if (!empty($elements)) {
    $header = array(t('Source role'), t('Destination role'));
    $rows = array();
    foreach ($elements as $source_role) {
      $row = array();
      $title = $form[$source_role]['#title'];
      unset($form[$source_role]['#title']);
      $row[] = $title;
      $row[] = drupal_render($form[$source_role]);
      $rows[] = $row;
    }
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
  }
  $output .= drupal_render_children($form);
  return $output;
}

/**
 * Theme function to layout format mappings in a table.
 *
 * @param array $variables
 *
 * @return string
 *  Rendered markup.
 */
function theme_migrate_d2d_ui_format_form($variables) {
  $output = '';
  $form = $variables['format'];
  $elements = element_children($form);
  if (!empty($elements)) {
    $header = array(t('Source format'), t('Destination format'));
    $rows = array();
    foreach ($elements as $source_format) {
      $row = array();
      $title = $form[$source_format]['#title'];
      unset($form[$source_format]['#title']);
      $row[] = $title;
      $row[] = drupal_render($form[$source_format]);
      $rows[] = $row;
    }
    $output .= theme('table', array('header' => $header, 'rows' => $rows));
  }
  $output .= drupal_render_children($form);
  return $output;
}
