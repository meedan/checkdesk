<?php

/**
 * Common mappings for the Drupal 6 node migrations.
 */
abstract class NodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->removeFieldMapping('body');
    $this->removeFieldMapping('body:format');
    $this->addFieldMapping('body', 'body')->callbacks('handleTags');
  }

  // Force keeping old paths - not necessary so far,
  // because paths are kept automatically
  public function complete($destiny, stdClass $source) {
  /*
    if (module_exists('path')) {
      if (!empty($source->path)) {
        $path = array(
          'source' => 'node/' . $destiny->nid,
          'alias' => $source->path,
        );
        path_save($path);
      }
    }
  */
  }
}

/**
 * Reports
 */
class ReportMigration extends NodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Map fields here
    $this->addFieldMapping('field_link', 'field_media_embed');
    $this->addFieldMapping('body:format', 'body:format');
  }

  // Map other stuff here
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if (!empty($row->field_translation)) {
      $row->body = $row->body . "\n" . $row->field_translation;
    }
    return TRUE;
  }

  // Specific destination-application stuff
  public function complete($destiny, stdClass $source) {
    parent::complete($destiny, $source);

    // Flag as offensive content
    if ($source->field_offensive_content == 1) {
      $user = user_load($destiny->uid);
      $roles = array_values($user->roles);
      $flag = ((in_array('journalist', $roles) || in_array('administrator', $roles)) ? 'graphic_journalist' : 'graphic');
      flag('flag', $flag, $destiny->nid, $user);
    }
  }
}

/**
 * Updates
 */
class UpdateMigration extends NodeMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    $this->addFieldMapping('body:format')->defaultValue('liveblog');
  }

  // Map other stuff here
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Force our input format

    // Save reports
    if (is_array($row->field_report)) {
      foreach ($row->field_report as $old_nid) {
        if ($old_nid) {
          $new_nid = $this->handleSourceMigration('Report', $old_nid); 
          $report = node_load($new_nid);
          if ($report) {
            $row->body = $row->body . "\n" . checkdesk_core_droppable_reference($report);
          }
        }
      }
    }
  
    return TRUE;
  }

}

// Handle HTML tags in fields
function handleTags($value) {
  $value = str_replace("</p>", "\n", $value); // Our filter will turn line breaks into paragraphs
  $value = strip_tags($value);
  $value = html_entity_decode($value, ENT_COMPAT, 'UTF-8');
  return $value;
}
