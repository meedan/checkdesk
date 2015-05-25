<?php
/**
 * @file
 * Implementation of DrupalNodeMigration for Drupal 6 sources.
 */

/**
 * Handling specific to a Drupal 6 source for nodes.
 */
class DrupalNode6Migration extends DrupalNodeMigration {
  /**
   * Translation from field names assigned when executing the query to our
   * subfield notation.
   *
   * @var array
   *  key: DB-compatible name (e.g., field_buy_link_title).
   *  value: Subfield notation (e.g., field_buy_link:title).
   */
  protected $fixFieldNames = array();

  /**
   * Keep track of any file field data columns we'll need to unpack in
   * prepareRow().
   *
   * @var array
   */
  protected $fileDataFields = array();

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $query = $this->query();

    $this->sourceOptions['fix_field_names'] = $this->fixFieldNames;

    $this->source = new MigrateDrupal6SourceSQL($query, $this->sourceFields, NULL,
      $this->sourceOptions);

    $this->addFieldMapping('language', 'language')
         ->defaultValue($this->defaultLanguage);
    $this->addFieldMapping('body:language', 'language', FALSE)
         ->defaultValue($this->defaultLanguage);

    if (field_info_instance('node', 'body', $this->destinationType)) {
      $this->addFieldMapping('body:summary', 'teaser');
      $this->addFieldMapping('body:format', 'format')
           ->callbacks(array($this, 'mapFormat'));
    }
    else {
      $this->addUnmigratedSources(array('teaser', 'format'));
    }

    $this->addFieldMapping(NULL, 'moderate');

    $this->addSimpleMappings(array('tnid', 'translate'));
  }

  /**
   * Query for basic node fields from Drupal 6.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('node', 'n')
             ->fields('n', array('nid', 'vid', 'language', 'title',
                 'uid', 'status', 'created', 'changed', 'comment', 'promote',
                 'moderate', 'sticky', 'tnid', 'translate'))
             ->condition('n.type', $this->sourceType)
             ->orderBy($this->newOnly ? 'n.nid' : 'n.changed');
    $query->innerJoin('node_revisions', 'nr', 'n.vid=nr.vid');
    $query->fields('nr', array('body', 'teaser', 'format'));
    // Pick up simple CCK fields
    $cck_table = 'content_type_' . $this->sourceType;
    if (Database::getConnection('default', $this->sourceConnection)
          ->schema()->tableExists($cck_table)) {
      $query->leftJoin($cck_table, 'f', 'n.vid=f.vid');
      // The main column for the field should be rendered with
      // the field name, not the column name (e.g., field_foo rather
      // than field_foo_value).
      $field_info = $this->version->getSourceFieldInfo();
      foreach ($field_info as $field_name => $info) {
        if (isset($info['columns']) && !$info['multiple'] && $info['db_storage']) {
          $i = 0;
          $data = FALSE;
          foreach ($info['columns'] as $display_name => $column_name) {
            if ($i++ == 0) {
              $query->addField('f', $column_name, $field_name);
            }
            else {
              // The database API won't allow colons in column aliases, so we
              // will accept the default alias, and fix up the field names later.
              // Remember how to translate the field names.
              $clean_name = str_replace(':', '_', $display_name);
              $this->fixFieldNames[$clean_name] = $display_name;
              if ($info['type'] == 'filefield' &&
                  (strpos($display_name, ':list') || strpos($display_name, ':description') || strpos($display_name, ':alt') || strpos($display_name, ':title'))) {
                if (!$data) {
                  $this->fileDataFields[] = $field_name . '_data';
                  $query->addField('f', $field_name . '_data');
                  $data = TRUE;
                }
              }
              else {
                $query->addField('f', $column_name);
              }
            }
          }
        }
      }
    }
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

    // The property 'tnid' cannot be handled via the sourceMigration() method
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

    foreach ($this->fileDataFields as $data_field) {
      if (isset($row->$data_field)) {
        $data = unserialize($row->$data_field);
        $base_field = substr($data_field, 0, strpos($data_field, '_data'));
        if (!empty($data)) {
          foreach ($data as $key => $value) {
            $field_name = $base_field . '_' . $key;
            $row->$field_name = $value;
          }
          unset($row->$data_field);
        }
      }
    }
    // Convert the default field names to the nice-looking ones.
    foreach ($this->fixFieldNames as $clean => $display) {
      if (isset($row->$clean)) {
        $row->$display = $row->$clean;
        unset($row->$clean);
      }
    }

    // Don't populate summary if the teaser matches the generated summary.
    if (empty($row->teaser) || $row->teaser == text_summary($row->body)) {
      $row->teaser = '';
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

}

/**
 * We override the default SQL source class just so we can clean up subfield
 * names for the UI.
 */
class MigrateDrupal6SourceSQL extends MigrateSourceSQL {
  /**
   * Translation from field names assigned when executing the query to our
   * subfield notation.
   *
   * @var array
   *  key: DB-compatible name (e.g., field_buy_link_title).
   *  value: Subfield notation (e.g., field_buy_link:title).
   */
  public $fixFieldNames = array();

  public function __construct(SelectQueryInterface $query, array $fields = array(),
        SelectQueryInterface $count_query = NULL, array $options = array()) {
    $this->fixFieldNames = $options['fix_field_names'];
    parent::__construct($query, $fields, $count_query, $options);
  }

  public function fields() {
    $fields = parent::fields();

    // Remove the default subfield names in favor of the nice-looking ones.
    foreach ($this->fixFieldNames as $clean => $display) {
      if (isset($fields[$clean])) {
        unset($fields[$clean]);
      }
    }
    return $fields;
  }
}
