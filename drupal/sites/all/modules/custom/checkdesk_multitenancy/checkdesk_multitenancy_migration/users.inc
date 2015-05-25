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

    $unserialized = @unserialize($value);

    return ($unserialized ? $unserialized : $value);
  }

  /**
   * Implements Migration::preImport().
   * Creates newsroom.
   */
  public function preImport() {
    parent::preImport();

    $title = $this->getSourceVariable('site_name');

    $node = new stdClass();
    $node->title = $title;
    $node->type = 'newsroom';
    node_object_prepare($node);
    $node->language = 'en';
    $node->uid = 1;

    // Fields
    foreach (array('en', 'ar') as $lang) {
      $node->newsroom_slogan[$lang][0]['value'] = $this->getSourceVariable('site_slogan', $lang);
    }

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
