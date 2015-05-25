<?php
/**
 * @file
 * Implementation of DrupalFileMigration for Drupal 6 sources.
 */

class DrupalFile6Migration extends DrupalFileMigration {
  protected $legacyPath;

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'timestamp',
        'alias' => 'f',
        'type' => 'int',
      );
    }

    $this->addFieldMapping('value', 'filepath');
    $this->addFieldMapping('destination_file', 'filepath')
      ->callbacks(array($this, 'fixUri'));
    $this->addFieldMapping('timestamp', 'timestamp');

    $this->legacyPath = unserialize(
      Database::getConnection('default', $this->sourceConnection)
                 ->select('variable', 'v')
                 ->fields('v', array('value'))
                 ->condition('name', 'file_directory_path')
                 ->execute()
                 ->fetchField());
    if (!$this->legacyPath) {
      // If features are in use, the variable may not be in the variables table,
      // but we might find it strongarmed in cache.
      $strongarm = Database::getConnection('default', $this->sourceConnection)
               ->select('cache', 'c')
               ->fields('c', array('data'))
               ->condition('cid', 'strongarm')
               ->execute()
               ->fetchField();
      if ($strongarm) {
        $strongarm = unserialize($strongarm);
        foreach ($strongarm as $key => $value) {
          if ($key == 'file_directory_path') {
            $this->legacyPath = $value;
            break;
          }
        }
      }
    }

    if (!$this->legacyPath) {
      $this->legacyPath = 'sites/default/files/';
    }

    // Strip ./ from the beginning
    if (substr($this->legacyPath, 0, 2) == './') {
      $this->legacyPath = substr($this->legacyPath, 2);
    }

    $this->addUnmigratedSources(array('status'));
  }

  /**
   * Implements DrupalMigration::query().
   *
   * @return QueryConditionInterface|SelectQueryInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('files', 'f')
             ->fields('f')
             ->orderBy($this->newOnly ? 'f.fid' : 'f.timestamp');
    return $query;
  }

  /**
   * Field mapping callback: Get the URI relative to the file directory.
   *
   * @param $uri
   *
   * @return mixed
   */
  protected function fixUri($uri) {
    // Try the legacy path, as best we could determine it.
    $result = str_replace($this->legacyPath, '', $uri);
    if ($result == $uri) {
      // That didn't work, so assume the prefix is of the form sites/%/files.
      $result = preg_replace('|^sites/[^/]+/files/|i', '', $uri);
    }
    return $result;
  }
}

/**
 * Pull user pictures in their own migration class, based on normal file migration.
 */
class DrupalPicture6Migration extends DrupalFile6Migration {
  public function __construct(array $arguments) {
    // Drupal 6 pictures are filespecs, so we override the map to use the paths
    // as the source key. Must do this before calling the parent constructor,
    // which will default it to an integer key.
    $this->map = new MigrateSQLMap($arguments['machine_name'],
      array(
        'picture' => array(
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

    // Override these mappings to use 'picture' instead of 'filepath'.
    $this->addFieldMapping('value', 'picture', FALSE);
    $this->addFieldMapping('destination_file', 'picture', FALSE)
      ->callbacks(array($this, 'fixUri'));

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
    $query->addField('f', 'picture');
    return $query;
  }
}
