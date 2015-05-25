<?php

/**
 * Common mappings for the Drupal 6 node migrations.
 */
abstract class ExampleNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('field_legacy_nid', 'nid')
         ->description('We have a common field to save the D6 nid');
  }
}

/**
 * Image-specific mappings and handling.
 */
class ExampleImageMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    $this->sourceFields['copyright'] = 'Media copyright notice';
    $this->sourceFields['filename'] = 'Path of image within mounted filesystem';

    parent::__construct($arguments);

    $this->addFieldMapping('field_credit', 'copyright');
    $this->addFieldMapping('field_main_image', 'filename');
    $this->addFieldMapping('field_main_image:source_path')
         ->defaultValue('/mnt/source_images');
  }

  /**
   * Implementation of Migration::prepareRow().
   *
   * Here we pull in additional data from a non-core, non-CCK table.
   *
   * @param $row
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $image_row = Database::getConnection('default', $this->sourceConnection)
                 ->select('custom_image_table', 'i')
                 ->fields('i', array('copyright', 'filename'))
                 ->condition('vid', $row->vid)
                 ->execute()
                 ->fetchObject();
    if ($image_row) {
      $row->copyright = $image_row->copyright;
      $row->filename = $image_row->filename;
    }
    else {
      $this->saveMessage(t('No custom_image_table data for image node with vid !vid',
                         array('!vid' => $row->vid)));
    }
  }
}

class ExampleArticleMigration extends ExampleNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    $this->sourceFields['lead_graphic'] = 'Lead graphic string from D6';
    $this->sourceFields['summary'] = 'Summary string from D6';

    parent::__construct($arguments);

    $this->addFieldMapping('field_image', 'field_lead_graphic')
         ->sourceMigration('Image');
    // Note that we map migrated terms by the vocabulary ID.
    $this->addFieldMapping('field_countries', '1')
         ->sourceMigration('Countries');
    $this->addFieldMapping('field_countries:source_type')
         ->defaultValue('tid');
    $this->addFieldMapping('field_topics', '2')
         ->sourceMigration('Topics');
    $this->addFieldMapping('field_topics:source_type')
         ->defaultValue('tid');
  }
}
