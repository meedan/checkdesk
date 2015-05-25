<?php
/**
 * @file
 * Implementation of DrupalFileMigration for Drupal 7 sources.
 */

/**
 * Handling specific to a Drupal 7 source for files.
 *
 * The following optional arguments may be passed:
 *
 * skip_pictures - Set to TRUE if the file migration should skip any file_managed
 *  entries being used as user pictures. You would do this if you are migrating
 *  user pictures in a separate step (DrupalPicture7Migration).
 */
class DrupalFile7Migration extends DrupalFileMigration {
  protected $skipPictures = FALSE;
  public function __construct(array $arguments) {
    if (isset($arguments['skip_pictures']) && $arguments['skip_pictures']) {
      $this->skipPictures = TRUE;
    }
    parent::__construct($arguments);

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'timestamp',
        'alias' => 'f',
        'type' => 'int',
      );
    }

    $this->addFieldMapping('value', 'uri')
         ->callbacks(array($this, 'fixUri'));
    $this->addFieldMapping('destination_file', 'uri')
      ->callbacks(array($this, 'fixUri'));
    $this->addFieldMapping('timestamp', 'timestamp');

    $this->addUnmigratedSources(array('status'));
  }

  protected function baseQuery() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('file_managed', 'f')
             ->fields('f')
             ->orderBy($this->newOnly ? 'f.fid' : 'f.timestamp');
    return $query;
  }

  protected function query() {
    $query = $this->baseQuery();
    if ($this->skipPictures) {
      $query->leftJoin('users', 'u', 'f.fid=u.picture');
      $query->isNull('u.uid');
    }
    return $query;
  }

  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with the CCK fields.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $this->version->getSourceValues($row, $row->fid);

    // Do our best to apply the appropriate file_class to the import of this
    // "file". Assume if we don't recognize a special case, we'll treat it as
    // a real file to be copied.
    if ($row->filemime == 'video/youtube' && class_exists('MigrateExtrasFileYoutube')) {
      if (strpos($row->uri, 'youtube://') !== FALSE) {
        $this->destination->setFileClass('MigrateFileUriAsIs');
      } else {
        $this->destination->setFileClass('MigrateExtrasFileYoutube');
      }
    }
    elseif (preg_match('|/oembed$|i', $row->filemime)) {
      $this->destination->setFileClass('MigrateFileUriAsIs');
    }
    else {
      $this->destination->setFileClass('MigrateFileUri');
    }
  }

  protected function fixUri($uri) {
    $result = str_replace('public://', '', $uri);
    return $result;
  }
}

/**
 * Pull user pictures in their own migration class, based on normal file migration.
 */
class DrupalPicture7Migration extends DrupalFile7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    // Clear references to normal file source fields
    $this->removeFieldMapping(NULL, 'filename');
    $this->removeFieldMapping(NULL, 'filemime');
    $this->removeFieldMapping(NULL, 'filesize');
    $this->removeFieldMapping(NULL, 'status');
    $this->removeFieldMapping(NULL, 'type');
  }

  /**
   * We override the file query to identify which files are user pictures.
   *
   * @return SelectQueryInterface
   */
  protected function query() {
    $query = $this->baseQuery();
    $query->innerJoin('users', 'u', 'f.fid=u.picture');
    return $query;
  }
}

/**
 * Pull youtube links in their own migration class, based on normal file migration.
 */
class DrupalYoutube7Migration extends DrupalFile7Migration {
  public function __construct(array $arguments) {
    $arguments['file_class'] = 'MigrateExtrasFileYoutube';
    parent::__construct($arguments);
    // Clear references to normal file fields
    $this->removeFieldMapping('destination_dir');
    $this->removeFieldMapping('source_dir');
    $this->removeFieldMapping('file_replace');
    $this->removeFieldMapping('preserve_files');
    $this->removeFieldMapping('destination_file');
  }

  /**
   * We override the file query to identify which files are user pictures.
   *
   * @return SelectQueryInterface
   */
  protected function query() {
    $query = $this->baseQuery();
    $query->condition('uri', 'youtube://%', 'LIKE');
    return $query;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->uri = str_replace('youtube://v/', 'http://www.youtube.com/watch?v=',
                            $row->uri);
  }
}
