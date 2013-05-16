<?php
/**
 * @file
 * Base class for migrating users into Drupal.
 */

/**
 * Base class for all user migrations - handles commonalities across all
 * supported source Drupal versions.
 */
abstract class DrupalUserMigration extends DrupalMigration {
  /**
   * If there's a user picture migration, keep track of the machine name
   * for dependency management and sourceMigration.
   *
   * @var string
   */
  protected $pictureMigration = '';

  /**
   * If there's a user role migration, keep track of the machine name
   * for dependency management and sourceMigration.
   *
   * @var string
   */
  protected $roleMigration = '';

  /**
   * @param array $arguments
   * picture_migration - Machine name of a picture migration, used to establish
   *   dependencies and a sourceMigration for the picture mapping.
   * role_migration - Machine name of a role migration, used to establish
   *   dependencies and a sourceMigration for the picture mapping.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    if (!empty($arguments['picture_migration'])) {
      $this->pictureMigration = $arguments['picture_migration'];
      $this->dependencies[] = $this->pictureMigration;
    }
    if (!empty($arguments['role_migration'])) {
      $this->roleMigration = $arguments['role_migration'];
      $this->dependencies[] = $this->roleMigration;
    }

    // Get any CCK/core fields attached to users.
    $this->sourceFields += $this->version->getSourceFields(
      'user', 'user');

    if ($this->moduleExists('path')) {
      $this->sourceFields['path'] = array('label' => t('User: Path alias'));
    }
    if ($this->roleMigration) {
      $this->sourceFields['roles'] = array('label' => t('User: Roles'));
    }

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'uid' => array('type' => 'int',
                       'unsigned' => TRUE,
                       'not null' => TRUE,
                       'description' => 'Source user ID',
                       'alias' => 'u',
                      ),
      ),
      DrupalDestinationUser::getKeySchema()
    );

    // We don't have a proper last-changed timestamp on users, access is the
    // best we can do.
    // @todo: Doesn't work in a straight-forward way, because access is 0 for
    // accounts that haven't been logged in. Disabled until we come up with a
    // good solution
/*    $this->highwaterField = array(
      'name' => 'access',
      'alias' => 'u',
      'type' => 'int',
    );*/

    // Most mappings are straight-forward
    $this->addSimpleMappings(array('pass', 'mail', 'theme', 'signature',
      'created', 'access', 'login', 'status', 'language', 'init', 'timezone'));
    // user_save() expects the data field to be unpacked
    $this->addFieldMapping('data', 'data')
         ->callbacks('unserialize');
    // Dedupe username collisions by appending _1, _2, etc.
    $this->addFieldMapping('name', 'name')
         ->dedupe('users', 'name');
    if (isset($this->pictureMigration)) {
      $this->addFieldMapping('picture', 'picture')
           ->sourceMigration($this->pictureMigration);
    }
    else {
      $this->addFieldMapping('picture', 'picture');
    }
    if (isset($this->roleMigration)) {
      $this->addFieldMapping('roles', 'roles')
           ->sourceMigration($this->roleMigration);
    }
    else {
      $this->addFieldMapping('roles');
    }

    $this->addFieldMapping('signature_format', 'signature_format')
         ->callbacks(array($this, 'mapFormat'));

    $this->addUnmigratedDestinations(array('is_new', 'role_names'));

    if (module_exists('path') && $this->moduleExists('path')) {
      $this->addFieldMapping('path', 'path')
           ->description('Handled in prepareRow');
    }
    else {
      if (module_exists('path')) {
        $this->addUnmigratedDestinations(array('path'));
      }
      elseif ($this->moduleExists('path')) {
        $this->addUnmigratedSources(array('path'));
      }
    }

    if (module_exists('pathauto')) {
      $this->addFieldMapping('pathauto')
           ->description('By default, disable in favor of migrated paths')
           ->defaultValue(0);
    }
  }

  /**
   * Query for the basic user data. Same query is used for all currently-supported
   * versions of Drupal.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    // Do not attempt to migrate the anonymous or admin user rows.
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('users', 'u')
             ->fields('u')
             ->condition('u.uid', 1, '>');
//             ->orderBy('access');
    return $query;
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    /*
    // On initial import, skip accounts with email addresses already existing
    // on the destination side (we assume these are manually-created staff
    // accounts or the like).
    // TODO: Add options to overwrite such accounts, throw errors, etc.
    if (empty($row->migrate_map_sourceid1)) {
      $uid = db_select('users', 'u')
             ->fields('u', array('uid'))
             ->condition('mail', $row->mail)
             ->execute()
             ->fetchField();
      if ($uid) {
        return FALSE;
      }
    }*/

    // Add the path to the source row, if relevant
    if ($this->moduleExists('path')) {
      $path = $this->version->getPath('user/' . $row->uid);
      if ($path) {
        $row->path = $path;
      }
    }

    // Pick up profile data.
    $this->version->getSourceValues($row, $row->uid);

    // Populate the source roles
    if ($this->roleMigration) {
      $result = Database::getConnection('default', $this->sourceConnection)
                ->select('users_roles', 'ur')
                ->fields('ur', array('rid'))
                ->condition('uid', $row->uid)
                ->execute();
      foreach ($result as $role_row) {
        $row->roles[] = $role_row->rid;
      }
    }
    return TRUE;
  }

  /**
   * Actions to take after a user account has been saved.
   *
   * @param $account
   * @param $row
   */
  public function complete($account, $row) {
    // If we've migrated a picture, update its ownership
    if (isset($this->pictureMigration)) {
      if ($account->picture) {
        db_update('file_managed')
          ->fields(array('uid' => $account->uid))
          ->condition('fid', $account->picture)
          ->execute();
      }
    }
  }
}

/**
 * We add support for user paths, which is not supported by the core destination,
 * so document the presence of the field.
 */
class DrupalDestinationUser extends MigrateDestinationUser {
  public function fields($migration = NULL) {
    $fields = parent::fields($migration);
    $fields['path'] = t('Node: Path alias');
    return $fields;
  }
}
