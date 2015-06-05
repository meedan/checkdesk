<?php

// Common for all node types

abstract class CheckdeskNodeMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }

  /**
   * Implements Migration::prepareRow().
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    $row->comment = 0;
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

  public function getNewsroom() {
    $title = $this->getSourceVariable('site_name');
    
    $newsroom = db_select('node', 'n')
                ->fields('n', array('nid'))
                ->condition('type', 'newsroom', '=')
                ->condition('title', $title, '=')
                ->execute()
                ->fetchField();

    return $newsroom;
  }
}

// Stories

class CheckdeskStoryMigration extends CheckdeskNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $name = $this->arguments['name'];

    $this->addFieldMapping('body:format')->defaultValue('liveblog');
    $this->addFieldMapping('uid', 'uid')->sourceMigration('User_' . $name);

    // Lead image

    $this->addFieldMapping('field_lead_image:source_dir')->defaultValue('/mnt/' . $name);
    $this->addFieldMapping('field_lead_image', 'field_lead_image')->sourceMigration('Files_' . $name);
    $this->addFieldMapping('field_lead_image:file_class')->defaultValue('MigrateFileFid');

    // Tags

    $this->addFieldMapping('field_tags', 'field_tags')->sourceMigration('Term_' . $name);
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');
  }

  /**
   * Implements Migration::prepareRow().
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    $row->comment = 0;
  }

  /**
   * Implements Migration::complete().
   */
  public function complete($node, stdClass $row) {
    parent::complete($node, $row);

    // Assign to newsroom

    $values = array(
      'entity_type' => 'node',
      'entity' => $node,
      'state' => OG_STATE_ACTIVE,
    );

    og_group('node', $this->getNewsroom(), $values);
  }

}
