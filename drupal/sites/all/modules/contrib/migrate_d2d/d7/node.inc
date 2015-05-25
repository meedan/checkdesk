<?php
/**
 * @file
 * Implementation of DrupalNodeMigration for Drupal 7 sources.
 */

/**
 * Handling specific to a Drupal 7 source for nodes.
 */
class DrupalNode7Migration extends DrupalNodeMigration {

  /**
   * Holds the fileMigration attached to this migration.
   *
   * @var string
   */
  protected $fileMigration;

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Remove fields no longer relevent in D7 (now part of the body field).
    unset($this->sourceFields['format']);
    unset($this->sourceFields['teaser']);

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);

    $this->addFieldMapping('language', 'language')
         ->defaultValue($this->defaultLanguage);

    if (field_info_instance('node', 'body', $this->destinationType)) {
      $this->addFieldMapping('body:summary', 'body:summary');
      $this->addFieldMapping('body:format', 'body:format')
           ->callbacks(array($this, 'mapFormat'));
    }
    else {
      $this->addUnmigratedSources(array('body:summary', 'body:format'));
    }

    if (module_exists('media')) {
      $this->addFieldMapping('body', 'body', FALSE)
           ->callbacks(array($this, 'remapMediaJson'));
    }

    $this->addSimpleMappings(array('tnid', 'translate'));
  }

  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('node', 'n')
             ->fields('n', array('nid', 'vid', 'language', 'title', 'uid',
               'status', 'created', 'changed', 'comment', 'promote', 'sticky',
               'tnid', 'translate'))
             ->condition('n.type', $this->sourceType)
             ->orderBy($this->newOnly ? 'n.nid' : 'n.changed');
    // Join node_counter for Statistics support
    if (Database::getConnection('default', $this->sourceConnection)
        ->schema()->tableExists('node_counter')) {
      $query->leftJoin('node_counter', 'nc', 'n.nid=nc.nid');
      $query->addField('nc', 'daycount');
      $query->addField('nc', 'timestamp');
      $query->addField('nc', 'totalcount');
    }
    return $query;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // The property 'tnid' cannot be handled via sourceMigration() method
    // because it might be 0 or the main node of translation set. We don't want
    // to create a stub for such cases.
    if (!empty($row->tnid)) {
      $destination_ids = $this->getMap()->lookupDestinationID(array($row->tnid));
      // There's no destination yet. Create a stub.
      if (empty($destination_ids)) {
        // Don't create stub for itself.
        if ($row->tnid != $row->nid) {
          // Check if 'tnid' is a node in the source set to prevent not
          // updatable stubs.
          $query = clone $this->query();
          $query->condition('n.nid', $row->tnid);
          $nid = $query->execute()->fetchField();
          unset($query);
          if ($nid) {
            if ($tnids = $this->createStub(NULL)) {
              // Save the mapping.
              $this->map->saveIDMapping((object) array('nid' => $row->tnid), $tnids, MigrateMap::STATUS_NEEDS_UPDATE, $this->defaultRollbackAction);
              $row->tnid = reset($tnids);
            }
          }
        }
        else {
          $row->tnid = 0;
          $row->_is_translation_source = TRUE;
        }
      }
      else {
        $row->tnid = $destination_ids['destid1'];
      }
    }
  }

  public function complete($node, stdClass $row) {
    if (empty($row->_is_translation_source)) {
      return;
    }

    db_update('node')
      ->fields(array('tnid' => $node->nid))
      ->condition('nid', $node->nid)
      ->execute();
  }

  /**
   * Rewrites the fids contained within media module text json.
   *
   * @param array $values
   *   Incoming text values
   *
   * @return array
   *   The values array.
   */
  protected function remapMediaJson($values) {
    if (!is_array($values)) {
      $values = array($values);
    }

    $media_regex = '#\[\[(.*?\"type":"media".*?)\]\]#';

    if (!isset($this->fileMigration)) {
      $this->fileMigration = $this->findFileMigration();
    }

    // By this point, if we don't know the file migration we have to bail.
    if (empty($this->fileMigration)) {
      return $values;
    }

    $map = $this->fileMigration->getMap();

    foreach ($values as &$value) {
      preg_match_all($media_regex, $value, $matches);

      if (empty($matches[1])) {
        continue;
      }

      foreach ($matches[1] as $idx => $match) {
        $media_item = json_decode($match, TRUE);

        if (empty($media_item)) {
          continue;
        }

        $fid = $media_item['fid'];

        $destination = $map->lookupDestinationID(array($fid));

        if (empty($destination['destid1'])) {
          continue;
        }

        $media_item['fid'] = $destination['destid1'];
        $replace = '[[' . json_encode($media_item) . ']]';

        $value = str_replace($matches[0][$idx], $replace, $value);
      }
    }
    unset($value);

    return $values;
  }

  /**
   * Attempts to find a file migration for this class.
   *
   * First it will check for an argument passed in. Then it will look at
   * the migration's dependencies to try and find something with a destination
   * which is an instanceof MigrateDestinationFile.
   *
   * Returns FALSE if it can't find one.
   *
   * @return bool|Migration
   *   The Migration, or boolean FALSE.
   */
  protected function findFileMigration() {
    if (isset($this->arguments['file_migration'])) {
      return Migration::getInstance($this->arguments['file_migration']);
    }

    if (isset($this->arguments['soft_dependencies'])) {
      foreach ($this->arguments['soft_dependencies'] as $dep) {
        $migration = Migration::getInstance($dep);

        if ($migration->getDestination() instanceof MigrateDestinationFile) {
          return $migration;
        }
      }
    }

    if (isset($this->arguments['dependencies'])) {
      foreach ($this->arguments['dependencies'] as $dep) {
        $migration = Migration::getInstance($dep);

        if ($migration->getDestination() instanceof MigrateDestinationFile) {
          return $migration;
        }
      }
    }

    return FALSE;
  }

}
