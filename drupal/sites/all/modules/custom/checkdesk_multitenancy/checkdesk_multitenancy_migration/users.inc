<?php

class CheckdeskUserMigration extends DrupalUser7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }

  /**
   * Implements Migration::prepareRow().
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
  }

  /**
   * Implements Migration::prepare().
   */
  public function prepare($account, $row) {
    parent::prepare($account, $row);

    $db = Database::getConnection('default', $this->arguments['name']);
    $user_by_name = $db->select('users', 'u')
                       ->condition('name', $row->name, '=')
                       ->condition('mail', $row->mail, '!=')
                       ->fields('u', array('uid'))
                       ->execute();

    if ($user_by_name->rowCount() > 0) {
      $account->name = $row->name . '-' . $this->arguments['name'];
    }
  }

  /**
   * Implements Migration::complete().
   */
  public function complete($account, $row) {
    parent::complete($account, $row);

    // Assigns user to the correct newsroom

    $values = array(
      'entity_type' => 'user',
      'entity' => $account,
      'state' => OG_STATE_ACTIVE,
    );

    og_group('node', $this->newsroom_gid, $values);

    if ($row->uid == 1) {
      $newsroom = node_load($this->newsroom_gid);
      $newsroom->uid = $account->uid;
      node_save($newsroom);
    }

    $og_roles = og_roles('node', 'newsroom');
    
    foreach ($this->getUserSourceRoles($row->uid) as $role) {
      $rid = array_search($role, $og_roles);
      og_role_grant('node', $this->newsroom_gid, $account->uid, $rid);
    }
  }

  public function getUserSourceRoles($uid) {
    $db = Database::getConnection('default', $this->arguments['name']);
    $query = $db->select('users_roles', 'ur');
    $query->join('role', 'r', 'ur.rid = r.rid');
    $query->fields('r', array('name'))
          ->condition('ur.uid', $uid, '=');
    $result = $query->execute();
    $roles = array();
    while($record = $result->fetchAssoc()) {
      $roles[] = $record['name'];
    }
    return $roles;
  }

  public function getSourceVariable($name, $lang = 'en') {
    $db = Database::getConnection('default', $this->arguments['name']);

    $value = $db->select('variable_store', 'vs')
                ->fields('vs', array('value'))
                ->condition('name', $name, '=')
                ->condition('realm', 'language', '=')
                ->condition('realm_key', $lang, '=')
                ->execute()
                ->fetchField();

    if (!$value) {
      $value = $db->select('variable', 'v')
                  ->fields('v', array('value'))
                  ->condition('name', $name, '=')
                  ->execute()
                  ->fetchField();
    }

    $unserialized = @unserialize($value);

    return ($unserialized ? $unserialized : $value);
  }

  public function getSourceThemeSetting($name) {
    $theme_settings = $this->getSourceVariable('theme_checkdesk_settings');
    if (array_key_exists($name, $theme_settings)) {
      return $theme_settings[$name];
    }
    return NULL;
  }

  /**
   * Implements Migration::preImport().
   * Creates newsroom.
   */
  public function preImport() {
    parent::preImport();

    $name = $this->arguments['name'];
    $db = Database::getConnection('default', $name);

    // Common node properties

    $title = $this->getSourceVariable('site_name');
    $node = new stdClass();
    $node->title = $title;
    $node->type = 'newsroom';
    node_object_prepare($node);
    $node->language = 'en';
    $node->uid = 1;

    // Fields

    $node->newsroom_slogan['en'][0]['value'] = $this->getSourceVariable('site_slogan');
    $node->title_field['en'][0]['value'] = $this->getSourceVariable('site_name');
    $node->newsroom_owner_email[LANGUAGE_NONE][0]['value'] = $this->getSourceVariable('site_mail');
    $node->newsroom_owner_name[LANGUAGE_NONE][0]['value'] = $this->getSourceVariable('checkdesk_site_owner');
    $node->newsroom_owner_url[LANGUAGE_NONE][0]['value'] = $this->getSourceVariable('checkdesk_site_owner_url');
    $node->custom_css[LANGUAGE_NONE][0]['value'] = $this->getSourceThemeSetting('custom_css');

    // Logo

    $logo = $this->getSourceThemeSetting('header_image_path');
    if ($logo) {
      // FIXME: (?) Assuming that all files to be migrated are under /mnt/{name}
      $path = file_uri_target($logo);
      $image = file_get_contents('/mnt/' . $name . '/' . $path);
      $file = file_save_data($image, file_build_uri($path), FILE_EXISTS_REPLACE);
      if (isset($file->fid)) {
        $node->newsroom_logo[LANGUAGE_NONE][0]['fid'] = $file->fid;
      }
    }

    // Translations

    $node->newsroom_slogan['ar'][0]['value'] = $this->getSourceVariable('site_slogan', 'ar');
    $node->title_field['ar'][0]['value'] = $this->getSourceVariable('site_name', 'ar');

    $handler = entity_translation_get_handler('node', $node);

    $translation = array(
      'translate' => 0,
      'status' => 1,
      'language' => 'ar',
      'source' => 'en',
    );

    $handler->setTranslation($translation, $node);

    // Define path prefix based on title

    module_load_include('inc','pathauto','pathauto');
    $node->newsroom_url[LANGUAGE_NONE][0]['value'] = pathauto_cleanstring($title);

    // Define social links

    $block = $db->select('block_custom', 'b')
                ->fields('b', array('body'))
                ->condition('info', 'Follow us', '=')
                ->execute()
                ->fetchField();

    if ($block) {
      $matches = array();
      preg_match_all('#\bhttps?://[^\s()<>]+(?:\([\w\d]+\)|([^[:punct:]\s]|/))#', $block, $matches);

      foreach ($matches[0] as $i => $url) {
        $node->newsroom_social_networks[LANGUAGE_NONE][$i]['url'] = $url;
      }
    }

    // Save

    $node = node_submit($node);
    node_save($node);

    $this->newsroom_gid = $node->nid;
  }

  /**
   * Implements Migration::postRollback().
   * Deletes newsroom.
   */
  public function postRollback() {
    parent::postRollback();

    $title = $this->getSourceVariable('site_name');
    
    $newsroom = db_select('node', 'n')
                ->fields('n', array('nid'))
                ->condition('type', 'newsroom', '=')
                ->condition('title', $title, '=')
                ->execute()
                ->fetchField();

    if ($newsroom) {
      node_delete($newsroom);
    }

    $users = db_query('SELECT uid FROM {users} WHERE name LIKE :migrated', array(':migrated' => '%-' . $this->arguments['name']));
    foreach ($users as $user) {
      user_delete($user->uid);
    }
  }
}
