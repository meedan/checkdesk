<?php
/**
 * @file
 * Implementation of DrupalFileMigration for Drupal 5 sources.
 */

class DrupalFile5Migration extends DrupalFileMigration {
  protected $legacyPath;

  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->addFieldMapping('value', 'filepath')
         ->callbacks(array($this, 'fixUri'));
    $this->addFieldMapping('destination_file', 'filepath')
      ->callbacks(array($this, 'fixUri'));

    $this->legacyPath = unserialize(
      Database::getConnection('default', $this->sourceConnection)
                 ->select('variable', 'v')
                 ->fields('v', array('value'))
                 ->condition('name', 'file_directory_path')
                 ->execute()
                 ->fetchField());
    // Strip ./ from the beginning
    if (substr($this->legacyPath, 0, 2) == './') {
      $this->legacyPath = substr($this->legacyPath, 2);
    }

    $this->addUnmigratedDestinations(array('timestamp'));
    $this->addUnmigratedSources(array('nid'));
  }

  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('files', 'f')
             ->fields('f');
    return $query;
  }

  protected function fixUri($uri) {
    // Get the URI relative the the file directory
    $result = str_replace($this->legacyPath, '', $uri);
    return $result;
  }
}

/**
 * Pull user pictures in their own migration class, based on normal file migration.
 */
class DrupalPicture5Migration extends DrupalFile5Migration {
  public function __construct(array $arguments) {
    // Drupal 5 pictures are filespecs, so we override the map to use the paths
    // as the source key. Must do this before calling the parent constructor,
    // which will default it to an integer key.
    $this->map = new MigrateSQLMap($arguments['machine_name'],
      array(
        'filepath' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Source filespec',
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );
    parent::__construct($arguments);

    if (!$this->newOnly) {
      // Override the highwater definition, the best timestamp we have in this
      // case is users.access.
      $this->highwaterField = array(
        'name' => 'access',
        'alias' => 'f',
        'type' => 'int',
      );
    }

    // No appropriate timestamp to save, so let it default.
    $this->addFieldMapping('timestamp', NULL, FALSE);

    // Not mapped directly, just used for highwater
    $this->addUnmigratedSources(array('access'));

    // Clear references to normal file source fields
    $this->removeFieldMapping(NULL, 'filename');
    $this->removeFieldMapping(NULL, 'filemime');
    $this->removeFieldMapping(NULL, 'filesize');
    $this->removeFieldMapping(NULL, 'status');
    $this->removeFieldMapping(NULL, 'type');
  }

  /**
   * We override the file query to get the pictures from the user table.
   *
   * @return SelectQueryInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('users', 'f')
             ->condition('picture', '', '<>')
             ->orderBy('access');
    $query->addField('f', 'access');
    // Return the field name the file migration expects.
    $query->addField('f', 'picture', 'filepath');
    return $query;
  }
}
