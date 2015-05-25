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

    // Skip the administrator
    if ($row->uid == 1) {
      return FALSE;
    }
  }

  /**
   * Implements Migration::complete().
   */
  public function complete($account, $row) {
    parent::complete($account, $row);
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

  /**
   * Implements Migration::preImport().
   * Creates newsroom.
   */
  public function preImport() {
    parent::preImport();

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

    // Save

    $node = node_submit($node);
    node_save($node);

    $this->newsroom = $node->nid;
  }

  /**
   * Implements Migration::postRollback().
   * Deletes newsroom.
   */
  public function postRollback() {
    parent::postRollback();

    $db = Database::getConnection('default', $this->arguments['name']);
    
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
  }
}
