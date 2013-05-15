<?php
/**
 * @file
 * Implementation of DrupalVersion for Drupal 7 sources.
 */

class DrupalVersion7 extends DrupalVersion {
  /**
   * Generate default format mappings based on matching names.
   */
  public function getDefaultFormatMappings() {
    $format_mappings = array();
    $result = Database::getConnection('default', $this->arguments['source_connection'])
              ->select('filter_format', 'f')
              ->fields('f', array('format'))
              ->execute();
    foreach ($result as $format_row) {
      $format_mappings[$format_row->format] = $format_row->format;
    }
    return $format_mappings;
  }

  /**
   * Given a source path (e.g, 'node/123'), return the first alias for that path.
   *
   * @param $source
   * @return string
   */
  public function getPath($source) {
    if (Database::getConnection('default', $this->arguments['source_connection'])
          ->schema()->tableExists('url_alias')) {
      $path = Database::getConnection('default', $this->arguments['source_connection'])
                    ->select('url_alias', 'ua')
                    ->fields('ua', array('alias'))
                    ->condition('source', $source)
                    ->execute()
                    ->fetchField();
    }
    else {
      $path = $source;
    }
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
    if (empty($this->sourceFieldInfo)) {
      migrate_instrument_start('DrupalVersion7::sourceFieldInfo');

      $this->entityType = $entity_type;
      $this->bundle = $bundle;

      // Get each field attached to this type.
      if (Database::getConnection('default', $this->arguments['source_connection'])
            ->schema()->tableExists('field_config_instance')) {
        $query = Database::getConnection('default', $this->arguments['source_connection'])
                 ->select('field_config_instance', 'i')
                 ->fields('i', array('data'))
                 ->condition('entity_type', $entity_type)
                 ->condition('bundle', $bundle)
                 ->condition('i.deleted', 0);
        $query->innerJoin('field_config', 'f', 'i.field_name = f.field_name');
        $query->fields('f', array('field_name', 'type', 'module'));
        $result = $query->execute();
        foreach ($result as $row) {
          $data = !empty($row->data) ? unserialize($row->data) : array();
          // Although a format column is present for text fields with text
          // filtering disabled, we want to skip it
          if (substr($row->type, 0, 4) == 'text' &&
              $data['settings']['text_processing'] == 0) {
            $skip_format = TRUE;
          }
          else {
            $skip_format = FALSE;
          }
          $this->sourceFieldInfo[trim($row->field_name)] = array(
            'label' => $data['label'],
            'type' => $row->type,
            'columns' => $this->getSourceFieldColumns($row->field_name, $skip_format),
          );
        }
      }
      migrate_instrument_stop('DrupalVersion7::sourceFieldInfo');
    }
  }

  /**
   * Pick up the list of database columns used for a given field. Unlike D6 CCK,
   * we don't have a definitive list in the configuration tables, so we query
   * the field table.
   *
   * @param $field_name
   *
   * @return array
   */
  protected function getSourceFieldColumns($field_name, $skip_format = FALSE) {
    $table = 'field_data_' . $field_name;
    $row = Database::getConnection('default', $this->arguments['source_connection'])
                     ->select($table, 'r')
                     ->fields('r')
                     ->range(0, 1)
                     ->execute()
                     ->fetchAssoc();
    $columns = array();
    if (!empty($row)) {
      $prefix = $field_name . '_';
      $prefix_len = strlen($prefix);
      foreach ($row as $column_name => $value) {
        if ($prefix == substr($column_name, 0, $prefix_len)) {
          $suffix = substr($column_name, $prefix_len);
          if ($suffix != 'format' || !$skip_format) {
            $display_name = $field_name . ':' . $suffix;
            $columns[$display_name] = $column_name;
          }
        }
      }
    }
    return $columns;
  }

  /**
   * Populate a migration's source row object with field values.
   *
   * @param $row
   * @param $entity_id
   */
  public function getSourceValues($row, $entity_id) {
    // Load up field data for dynamically mapped fields
    foreach ($this->sourceFieldInfo as $field_name => $field_info) {
      // Find the data in field_data_$field_name.
      $table = "field_data_$field_name";
      $result = Database::getConnection('default', $this->arguments['source_connection'])
                ->select($table, 'f')
                ->fields('f')
                ->condition('entity_type', $this->entityType)
                ->condition('bundle', $this->bundle)
                ->condition('entity_id', $entity_id)
                ->orderBy('delta')
                ->execute();
      foreach ($result as $field_row) {
        $i = 0;
        // We assume the first column is the "primary" value of the field, and
        // assign the field name rather than the column name for it.
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
