<?php
/**
 * @file
 * Implementation of DrupalVersion for Drupal 5 sources.
 */

/**
 * Drupal 5 implementations of functions shared among multiple types of objects.
 */
class DrupalVersion5 extends DrupalVersion {
  /**
   * A list of node types associated with content_profile.
   *
   * @var array
   */
  protected $profileTypes = array();

  /**
   * Generate default format mappings based on matching names. E.g., if the
   * Drupal 5 database has format 5 with name 'Filtered HTML', and the Drupal 7
   * databas has format filtered_html with name 'Filtered HTML', the resulting
   * array will contain the row '5' => 'filtered_html'.
   */
  public function getDefaultFormatMappings() {
    migrate_instrument_start('DrupalVersion5::getDefaultFormatMappings');
    $format_mappings = array();
    $result = Database::getConnection('default', $this->arguments['source_connection'])
              ->select('filter_formats', 'f')
              ->fields('f', array('format', 'name'))
              ->execute();
    foreach ($result as $format_row) {
      $format = db_select('filter_format', 'f')
                ->fields('f', array('format'))
                ->condition('name', $format_row->name)
                ->execute()
                ->fetchField();
      if ($format) {
        $format_mappings[$format_row->format] = $format;
      }
    }
    migrate_instrument_stop('DrupalVersion5::getDefaultFormatMappings');
    return $format_mappings;
  }

  /**
   * Given a source path (e.g, 'node/123'), return the first alias for that path.
   *
   * @param $source
   * @return string
   */
  public function getPath($source) {
    migrate_instrument_start('DrupalVersion5::getPath');
    if (Database::getConnection('default', $this->arguments['source_connection'])
          ->schema()->tableExists('url_alias')) {
      $path = Database::getConnection('default', $this->arguments['source_connection'])
                    ->select('url_alias', 'ua')
                    ->fields('ua', array('dst'))
                    ->condition('src', $source)
                    ->execute()
                    ->fetchField();
    }
    else {
      $path = $source;
    }
    migrate_instrument_stop('DrupalVersion5::getPath');
    return $path;
  }

  /**
   * Retrieve info on all fields attached to the given entity type and bundle.
   * Populates $this->sourceFieldInfo.
   *
   * @param $entity_type
   * @param $bundle
   */
  protected function populateSourceFieldInfo($entity_type, $bundle) {
    if ($entity_type == 'user') {
      // Get core profile fields.
      $this->profileFields();
      // If there are content profiles, the recursive calls set these to
      // the profile type, so reset them.
      $this->entityType = $entity_type;
      $this->bundle = $bundle;
    }
    elseif ($entity_type != 'node') {
      return;
    }
    elseif (empty($this->sourceFieldInfo)) {
      migrate_instrument_start('DrupalVersion5::sourceFieldInfo');

      $this->entityType = $entity_type;
      $this->bundle = $bundle;

      // Get each field attached to this type.
      if (Database::getConnection('default', $this->arguments['source_connection'])
            ->schema()->tableExists('node_field_instance')) {
        $query = Database::getConnection('default', $this->arguments['source_connection'])
                 ->select('node_field_instance', 'i')
                 ->fields('i', array('label', 'type_name'))
                 ->condition('type_name', $bundle);
        $query->innerJoin('node_field', 'f', 'i.field_name = f.field_name');
        $query->fields('f', array('field_name', 'type', 'multiple', 'db_storage'));
        $result = $query->execute();
        foreach ($result as $row) {
          $field_name = trim($row->field_name);
          $db_columns = $this->getFieldTypeColumns($row);
          $columns = array();
          foreach ($db_columns as $column_name) {
            $display_name = $field_name . ':' . $column_name;
            $column_name = $field_name . '_' . $column_name;
            $columns[$display_name] = $column_name;
          }
          $this->sourceFieldInfo[$field_name] = array(
            'label' => $row->label,
            'type' => $row->type,
            'columns' => $columns,
            'multiple' => $row->multiple,
            'db_storage' => $row->db_storage,
          );
        }
      }
      // Get each vocabulary attached to this type.
      $query = Database::getConnection('default', $this->arguments['source_connection'])
               ->select('vocabulary_node_types', 'vnt')
               ->fields('vnt', array('vid'));
      $query->innerJoin('vocabulary', 'v', 'vnt.vid=v.vid');
      $query->addField('v', 'name');
      $query->condition('vnt.type', $bundle);
      $result = $query->execute();
      foreach ($result as $row) {
        $this->sourceFieldInfo[$row->vid] = array('label' => $row->name, 'type' => 'taxonomy_term');
      }
      migrate_instrument_stop('DrupalVersion5::sourceFieldInfo');
    }
  }

  /**
   * Detect what database columns are available for the given field.
   *
   * @param $field_info
   *  Info describing the incoming field. We specifically are looking at the
   *  field_name, type_name, and db_storage values.
   *
   * @return array
   *  List of column suffixes relevant to the field ('value', 'fid', etc.).
   */
  protected function getFieldTypeColumns($field_info) {
    $field_name = $field_info->field_name;
    if ($field_info->db_storage) {
      $table_name = 'content_type_' . $field_info->type_name;
    }
    else {
      $table_name = 'content_' . $field_name;
    }
    $row = Database::getConnection('default', $this->arguments['source_connection'])
                   ->select($table_name, 't')
                   ->fields('t')
                   ->range(0, 1)
                   ->execute()
                   ->fetchObject();
    $type_columns = array();
    if ($row) {
      foreach ($row as $column_name => $column_value) {
        if (!strncmp($field_name, $column_name, strlen($field_name))) {
          $type_columns[] = substr($column_name, strlen($field_name) + 1);
        }
      }
    }

    return $type_columns;
  }

  /**
   * Populate a migration's source row object with field values.
   *
   * @param $row
   * @param $entity_id
   */
  public function getSourceValues($row, $entity_id) {
    if ($this->entityType == 'user') {
      // First get the core profile values.
      $this->getProfileValues($row, $entity_id);
      // Next, look for any associated profile nodes, and fall through to
      // process them.
      $entity_id_list = $revision_id_list = array();
      foreach ($this->profileTypes as $type) {
        $node = Database::getConnection('default', $this->arguments['source_connection'])
                ->select('node', 'n')
                ->fields('n', array('nid', 'vid'))
                ->condition('uid', $entity_id)
                ->condition('type', $type)
                ->execute()
                ->fetchObject();
        if ($node) {
          $entity_id_list[] = $node->nid;
          $revision_id_list[] = $node->vid;
        }
      }
    }
    elseif ($this->entityType == 'node') {
      $entity_id_list = array($entity_id);
      $revision_id_list = array($row->vid);
    }
    else {
      return;
    }
    $schema = Database::getConnection('default', $this->arguments['source_connection'])->schema();
    foreach ($entity_id_list as $index => $entity_id) {
      $revision_id = $revision_id_list[$index];
      // Load up field data for dynamically mapped fields
      foreach ($this->sourceFieldInfo as $field_name => $field_info) {
        if ($field_info['type'] != 'taxonomy_term') {
          // Fields in the base (content_type_foo) CCK table will have been
          // incorporated into the base query, so just look for the
          // shared/multiple field cases
          $table = "content_$field_name";
          if ($schema->tableExists($table)) {
            $query = Database::getConnection('default', $this->arguments['source_connection'])
                     ->select($table, 'f')
                     ->fields('f')
                     ->condition('nid', $entity_id);
            // There isn't always a delta,
            // @see http://drupal.org/node/1715244
            if ($schema->fieldExists($table, 'delta')) {
              $query->orderBy('delta');
            }
            $result = $query->execute();
            foreach ($result as $field_row) {
              $i = 0;
              foreach ($this->sourceFieldInfo[$field_name]['columns'] as $display_name => $column_name) {
                if ($i++ == 0) {
                  $index = $field_name;
                }
                else {
                  $index = $display_name;
                }
                $row->{$index}[] = $field_row->$column_name;
              }
            }
          }
        }
      }

      // Users only (nodes do this via their base query) - get the profile node
      // row
      if ($this->entityType == 'user') {
        foreach ($this->profileTypes as $type) {
          $cck_table = 'content_type_' . $type;
          $query = Database::getConnection('default', $this->arguments['source_connection'])
                   ->select($cck_table, 'f')
                   ->condition('vid', $revision_id);
          // The main column for the field should be rendered with
          // the field name, not the column name (e.g., field_foo rather
          // than field_foo_value).
          foreach ($this->sourceFieldInfo as $field_name => $info) {
            if (isset($info['columns']) && !$info['multiple'] && $info['db_storage']) {
              $i = 0;
              foreach ($info['columns'] as $display_name => $column_name) {
                if ($i++ == 0) {
                  $query->addField('f', $column_name, $field_name);
                }
                else {
                  $query->addField('f', $column_name, $display_name);
                }
              }
            }
          }
          $data_row = $query->execute()->fetchObject();
          foreach ($data_row as $name => $value) {
            $row->$name = $value;
          }
        }
      }

      // And. load up the data for taxonomy terms
      $query = Database::getConnection('default', $this->arguments['source_connection'])
               ->select('term_node', 'tn')
               ->fields('tn', array('tid'))
               ->condition('tn.nid', $row->nid);
      $query->innerJoin('term_data', 'td', 'tn.tid=td.tid');
      $query->fields('td', array('vid'));
      $result = $query->execute();
      foreach ($result as $term_row) {
        $row->{$term_row->vid}[] = $term_row->tid;
      }
    }
  }

  /**
   * Retrieve any user profile fields from the core profile module or
   * content_profile.
   *
   * @return array
   */
  protected function profileFields() {
    migrate_instrument_start('DrupalVersion5::profileFields');

    // Get any content_profile node types. A variable named content_profile_use_foo
    // with a serialized value of 1 means foo is a node type of interest.
    $names = Database::getConnection('default', $this->arguments['source_connection'])
             ->select('variable', 'v')
             ->fields('v', array('name'))
             ->condition('name', 'content_profile_use_%', 'LIKE')
             ->condition('value', 'i:1;')
             ->execute()
             ->fetchCol();
    $index = strlen('content_profile_use_');
    foreach ($names as $name) {
      $type_name = substr($name, $index);
      $this->profileTypes[] = $type_name;
      // Populates sourceFieldInfo directly
      $this->populateSourceFieldInfo('node', $type_name);
    }
    // Then, check the core profile
    if (Database::getConnection('default', $this->arguments['source_connection'])
          ->schema()->tableExists('profile_fields')) {
      $query = Database::getConnection('default', $this->arguments['source_connection'])
               ->select('profile_fields', 'f')
               ->fields('f', array('title', 'name', 'type'));
      $result = $query->execute();
      foreach ($result as $row) {
        $this->sourceFieldInfo[trim($row->name)] = array('label' => $row->title, 'type' => $row->type);
      }
    }

    migrate_instrument_stop('DrupalVersion5::profileFields');
  }

  /**
   * Get any core profile values associated with this user.
   *
   * @param $row
   * @param $entity_id
   */
  public function getProfileValues($row, $entity_id) {
    if (Database::getConnection('default', $this->arguments['source_connection'])
          ->schema()->tableExists('profile_values')) {
      migrate_instrument_start('DrupalVersion5::getProfileValues');
      $query = Database::getConnection('default', $this->arguments['source_connection'])
               ->select('profile_values', 'v')
               ->fields('v', array('value'))
               ->condition('uid', $entity_id)
               ->condition('value', '', '<>');
      $query->innerJoin('profile_fields', 'f', 'v.fid=f.fid');
      $query->fields('f', array('name'));
      $result = $query->execute();
      foreach ($result as $data_row) {
        $row->{$data_row->name} = $data_row->value;
      }

      migrate_instrument_stop('DrupalVersion5::getProfileValues');
    }
  }
}
