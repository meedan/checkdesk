<?php

module_load_include('inc', 'link', 'link.migrate');

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

  public function updateReports($name, $body) {
    $matches = array();
    $new_body = $body;

    preg_match_all("|\[[^:]+:[0-9]+\]|", $body, $matches);

    if (!empty($matches)) {
      $reports = $matches[0];
      foreach ($reports as $report) {
        $nid = preg_replace("/^\[[^:]+:([0-9]+)\]$/", "$1", $report);
        $new_nid = db_select('migrate_map_report_' . $name, 'm')
                   ->fields('m', array('destid1'))
                   ->condition('sourceid1', $nid, '=')
                   ->extend('PagerDefault')
                   ->limit(1)
                   ->execute()
                   ->fetchField();
        $replacement = '';
        if ($new_nid) {
          $replacement = str_replace($nid, $new_nid, $report);
        }
        $new_body = str_replace($report, $replacement, $new_body);
      }
    }

    return $new_body;
  }
}

// Stories

class CheckdeskStoryMigration extends CheckdeskNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $name = $this->arguments['name'];

    $this->addFieldMapping('body:format')->defaultValue('liveblog');
    $this->addFieldMapping('uid', 'uid')->sourceMigration('User_' . $name);
    
    // Additional authors
    
    $this->addFieldMapping('field_additional_authors', 'field_additional_authors')->sourceMigration('User_' . $name);
    $this->addFieldMapping('field_additional_authors:source_type')->defaultValue('uid');

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
    
    $name = $this->arguments['name'];
    
    $row->body[0] = $this->updateReports($name, $row->body[0]);

    $row->comment = 0;
  }

  /**
   * Implements Migration::complete().
   */
  public function complete($node, stdClass $row) {
    parent::complete($node, $row);

    // Set caption

    $db = Database::getConnection('default', $this->arguments['name']);

    $caption = $db->select('field_image_field_caption', 'fifc')
                  ->fields('fifc', array('caption'))
                  ->condition('field_name', 'field_lead_image', '=')
                  ->condition('entity_type', 'node', '=')
                  ->condition('bundle', 'discussion', '=')
                  ->condition('entity_id', $row->nid, '=')
                  ->execute()
                  ->fetchField();
    $node->field_lead_image[LANGUAGE_NONE]['0']['image_field_caption']['value'] = $caption;
    $node->field_lead_image[LANGUAGE_NONE]['0']['image_field_caption']['format'] = 'filtered_html';
    node_save($node);

    // Assign to newsroom

    $values = array(
      'entity_type' => 'node',
      'entity' => $node,
      'state' => OG_STATE_ACTIVE,
    );

    og_group('node', $this->getNewsroom(), $values);
  }

}

// Updates

class CheckdeskUpdateMigration extends CheckdeskNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    $name = $this->arguments['name'];
    
    $this->addFieldMapping('field_desk', 'field_desk')->sourceMigration('Story_' . $name);
  }

  /**
   * Implements Migration::prepareRow().
   */
  public function prepareRow($row) {
    parent::prepareRow($row);

    // Update reports
    $name = $this->arguments['name'];
    $row->body[0] = $this->updateReports($name, $row->body[0]);
  }
}

// Reports

class CheckdeskReportMigration extends CheckdeskNodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    $name = $this->arguments['name'];
    
    $this->addFieldMapping('field_stories', 'field_stories')->sourceMigration('Story_' . $name);
    
    $this->addFieldMapping('field_tags', 'field_tags')->sourceMigration('Term_' . $name);
    $this->addFieldMapping('field_tags:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_rating', 'field_rating')->sourceMigration('Rating_' . $name);
    $this->addFieldMapping('field_rating:source_type')->defaultValue('tid');

    $this->addFieldMapping('field_link', 'field_link');
    $this->addFieldMapping('field_link:url', 'field_link:url');
    $this->addFieldMapping('field_link:title', 'field_link:title');
    $this->addFieldMapping('field_link:attributes', 'field_link:attributes');
  }

  /**
   * Implements Migration::prepareRow().
   */
  public function prepareRow($row) {
    parent::prepareRow($row);
  }

  /**
   * Implements Migration::complete().
   */
  public function complete($node, stdClass $row) {
    parent::complete($node, $row);

    // Force callbacks

    node_save($node);
  }
}
