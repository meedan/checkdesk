<?php
/**
 * @file
 * Implementation of DrupalVersion for Drupal 6 sources.
 */

/**
 * Drupal 6 implementations of functions shared among multiple types of objects.
 */
class DrupalVersion6 extends DrupalVersion {
  /**
   * A list of node types associated with content_profile.
   *
   * @var array
   */
  protected $profileTypes = array();

  /**
   * Generate default format mappings based on matching names. E.g., if the
   * Drupal 6 database has format 5 with name 'Filtered HTML', and the Drupal 7
   * databas has format filtered_html with name 'Filtered HTML', the resulting
   * array will contain the row '5' => 'filtered_html'.
   */
  public function getDefaultFormatMappings() {
    migrate_instrument_start('DrupalVersion6::getDefaultFormatMappings');
    $format_mappings = array();
    $d6_formats = Database::getConnection('default', $this->arguments['source_connection'])
              ->select('filter_formats', 'f')
              ->fields('f', array('name', 'format'))
              ->execute()->fetchAllKeyed();
    $d7_formats = db_select('filter_format', 'f')
                ->fields('f', array('name', 'format'))
                ->condition('name', array_keys($d6_formats), 'IN')
                ->execute()
                ->fetchAllKeyed();
    foreach ($d6_formats as $name => $format) {
      if (isset($d7_formats[$name])) {
        $format_mappings[$format] = $d7_formats[$name];
      }
    }
    migrate_instrument_stop('DrupalVersion6::getDefaultFormatMappings');
    return $format_mappings;
  }

  /**
   * Given a source path (e.g, 'node/123'), return the first alias for that path.
   *
   * @param $source
   * @return string
   */
  public function getPath($source) {
    migrate_instrument_start('DrupalVersion6::getPath');
    if (Database::getConnection('default', $this->arguments['source_connection'])
          ->schema()->tableExists('url_alias')) {
      $path = Database::getConnection('default', $this->arguments['source_connection'])
                    ->select('url_alias', 'ua')
                    ->fields('ua', array('dst'))
                    ->condition('src', $source)
                    ->orderBy('pid', 'DESC')
                    ->execute()
                    ->fetchField();
    }
    else {
      $path = $source;
    }
    migrate_instrument_stop('DrupalVersion6::getPath');
    return $path;
  }

  /**
   * Retrieve info on all fields attached to the given entity type and bundle.
   * Populates $this->sourceFieldInfo.
   *
   * @param $entity_type
   * @param $bundle
   * @param $include_title_body
   */
  protected function populateSourceFieldInfo($entity_type, $bundle, $include_title_body = FALSE) {
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
    else {
      migrate_instrument_start('DrupalVersion6::sourceFieldInfo');

      $this->entityType = $entity_type;
      $this->bundle = $bundle;
      // Standalone nodes handle the title and body through the core migration,
      // but for content_profile nodes we need to deal with them here.
      if ($include_title_body) {
        $type_info = Database::getConnection('default',
                                         $this->arguments['source_connection'])
                         ->select('node_type', 'nt')
                         ->fields('nt', array('has_title', 'title_label',
                                              'has_body', 'body_label'))
                         ->condition('type', $bundle)
                         ->execute()
                         ->fetchObject();
        // To hopefully uniquify the machine names, use the content_profile
        // node type, with '_node_type' appended, in the name.
        if (is_object($type_info)) {
          if (!empty($type_info->has_title)) {
            $this->sourceFieldInfo['field_' . $bundle . '_node_type_title'] =
              array('label' => $type_info->title_label, 'type' => 'title');
          }
          if (!empty($type_info->has_body)) {
            $this->sourceFieldInfo['field_' . $bundle . '_node_type_body'] =
              array('label' => $type_info->body_label, 'type' => 'body');
          }
        }
      }

      // Get each field attached to this type.
      if (Database::getConnection('default',
                                  $this->arguments['source_connection'])
            ->schema()->tableExists('content_node_field_instance')) {
        $query = Database::getConnection('default',
                                         $this->arguments['source_connection'])
                 ->select('content_node_field_instance', 'i')
                 ->fields('i', array('label', 'widget_settings'))
                 ->condition('type_name', $bundle);
        $query->innerJoin('content_node_field', 'f',
                          'i.field_name = f.field_name');
        $query->fields('f', array('field_name', 'type', 'db_columns',
                                  'global_settings', 'multiple', 'db_storage'));
        $result = $query->execute();
        foreach ($result as $row) {
          $field_name = trim($row->field_name);
          $db_columns = $db_columns = !empty($row->db_columns) ?
            unserialize($row->db_columns) : array();
          $columns = array();
          foreach ($db_columns as $column_name => $column_info) {
            // Special handling for the stuff packed into filefield's "data"
            if ($row->type == 'filefield' && $column_name == 'data') {
              $widget_settings = unserialize($row->widget_settings);
              $global_settings = unserialize($row->global_settings);
              if (!empty($widget_settings['custom_alt'])) {
                $columns[$field_name . ':alt'] = $field_name . '_alt';
              }
              if (!empty($widget_settings['custom_title'])) {
                $columns[$field_name . ':title'] = $field_name . '_title';
              }
              if (!empty($global_settings['description_field'])) {
                $columns[$field_name . ':description'] = $field_name . '_description';
              }
            }
            else {
              $display_name = $field_name . ':' . $column_name;
              $column_name = $field_name . '_' . $column_name;
              $columns[$display_name] = $column_name;
            }
          }
          $this->sourceFieldInfo[$field_name] = array(
            'label' => $row->label,
            'type' => $row->type,
            'columns' => $columns,
            'multiple' => $row->multiple,
            'db_storage' => $row->db_storage,
            'bundle' => $bundle,
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
      // If the upload table exists and the type has attachments enabled,
      // include upload data.
      if (Database::getConnection('default',
                                  $this->arguments['source_connection'])
            ->schema()->tableExists('upload')) {
        $upload =
          Database::getConnection('default', $this->arguments['source_connection'])
                     ->select('variable', 'v')
                     ->fields('v', array('value'))
                     ->condition('name', 'upload_' . $bundle)
                     ->execute()
                     ->fetchField();
        if ($upload) {
          $upload = unserialize($upload);
        }
        else {
          $upload = 1;
        }
        if ($upload) {
          $this->sourceFieldInfo['upload'] = array('label' => t('Upload'),
            'type' => 'upload');
          $this->sourceFieldInfo['upload:description'] =
            array('label' => t('Upload description'), 'type' => 'upload');
          $this->sourceFieldInfo['upload:list'] =
            array('label' => t('Upload list'), 'type' => 'upload');
          $this->sourceFieldInfo['upload:weight'] =
            array('label' => t('Upload weight'), 'type' => 'upload');
        }
      }

      migrate_instrument_stop('DrupalVersion6::sourceFieldInfo');
    }
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

    $schema = Database::getConnection('default',
      $this->arguments['source_connection'])->schema();
    foreach ($entity_id_list as $index => $entity_id) {
      $revision_id = $revision_id_list[$index];
      // Load up field data for dynamically mapped fields
      foreach ($this->sourceFieldInfo as $field_name => $field_info) {
        if ($field_info['type'] != 'taxonomy_term') {
          if ($field_info['type'] == 'body' || $field_info['type'] == 'title') {
            // Special handling to accomodate content_profile titles and bodies.
            $value = Database::getConnection('default',
                       $this->arguments['source_connection'])
                     ->select('node_revisions', 'nr')
                     ->fields('nr', array($field_info['type']))
                     ->condition('vid', $revision_id)
                     ->execute()
                     ->fetchField();
            if ($value) {
              $row->$field_name = $value;
            }
          }
          else {
            // Fields in the base (content_type_foo) CCK table will have been
            // incorporated into the base query, so just look for the
            // shared/multiple field cases
            $table = "content_$field_name";
            if ($schema->tableExists($table)) {
              $query = Database::getConnection('default', $this->arguments['source_connection'])
                       ->select($table, 'f')
                       ->fields('f')
                       ->condition('vid', $revision_id);
              // There isn't always a delta,
              // @see http://drupal.org/node/1715244
              if ($schema->fieldExists($table, 'delta')) {
                $query->orderBy('delta');
              }
              $result = $query->execute();
              foreach ($result as $field_row) {
                $data = NULL;
                // Unserialize file field data to break into alt/title/description.
                if ($this->sourceFieldInfo[$field_name]['type'] == 'filefield') {
                  $data_column_name = $field_name . '_data';
                  if (isset($field_row->$data_column_name)) {
                    $data = unserialize($field_row->$data_column_name);
                  }
                }
                $i = 0;
                foreach ($this->sourceFieldInfo[$field_name]['columns'] as $display_name => $column_name) {
                  if ($i++ == 0) {
                    $index = $field_name;
                  }
                  else {
                    $index = $display_name;
                  }
                  if (isset($row->$index) && !is_array($row->$index)) {
                    $row->$index = array($row->$index);
                  }
                  // File field subfields need to be pulled from $data.
                  if ($display_name == "$field_name:alt" &&
                      isset($data['alt'])) {
                    $row->{$index}[] = $data['alt'];
                  }
                  elseif ($display_name == "$field_name:title" &&
                          isset($data['title'])) {
                    $row->{$index}[] = $data['title'];
                  }
                  elseif ($display_name == "$field_name:description" &&
                          isset($data['description'])) {
                    $row->{$index}[] = $data['description'];
                  }
                  elseif (isset($field_row->$column_name)) {
                    $row->{$index}[] = $field_row->$column_name;
                  }
                }
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
          if (Database::getConnection('default', $this->arguments['source_connection'])
                    ->schema()->tableExists($cck_table)) {
            $query = Database::getConnection('default', $this->arguments['source_connection'])
                     ->select($cck_table, 'f')
                     ->condition('vid', $revision_id);
            // The main column for the field should be rendered with
            // the field name, not the column name (e.g., field_foo rather
            // than field_foo_value).
            $fix_field_names = array();
            $field_found = FALSE;
            foreach ($this->sourceFieldInfo as $field_name => $info) {
              // All fields are stored in sourceFieldInfo. If there are
              // multiple non-core profile node types, we need to specify
              // which one each field belongs to.
              if (isset($info['bundle']) && $info['bundle'] != $type) {
                continue;
              }

              if (isset($info['columns']) && !$info['multiple'] && $info['db_storage']) {
                $i = 0;
                foreach ($info['columns'] as $display_name => $column_name) {
                  if ($i++ == 0) {
                    $query->addField('f', $column_name, $field_name);
                  }
                  else {
                    // The database API won't allow colons in column aliases, so we
                    // will accept the default alias, and fix up the field names later.
                    // Remember how to translate the field names.
                    $clean_name = str_replace(':', '_', $display_name);
                    $fix_field_names[$clean_name] = $display_name;
                    $query->addField('f', $column_name);
                  }
                  $field_found = TRUE;
                }
              }
            }
            if ($field_found) {
              $data_row = $query->execute()->fetchObject();
              if (is_object($data_row)) {
                foreach ($data_row as $name => $value) {
                  if (isset($fix_field_names[$name])) {
                    $name = $fix_field_names[$name];
                  }
                  $row->$name = $value;
                }
              }
            }
          }
        }
      }

      // And, load up the data for taxonomy terms.
      $query = Database::getConnection('default',
                                       $this->arguments['source_connection'])
               ->select('term_node', 'tn')
               ->fields('tn', array('tid'))
               ->condition('tn.vid', $revision_id);
      $query->innerJoin('term_data', 'td', 'tn.tid=td.tid');
      $query->fields('td', array('vid'));
      $result = $query->execute();
      foreach ($result as $term_row) {
        $row->{$term_row->vid}[] = $term_row->tid;
      }

      if (Database::getConnection('default',
                                  $this->arguments['source_connection'])
            ->schema()->tableExists('upload')) {
        $result =
          Database::getConnection('default', $this->arguments['source_connection'])
                     ->select('upload', 'u')
                     ->fields('u', array('fid', 'description', 'list', 'weight'))
                     ->condition('vid', $revision_id)
                     ->orderBy('weight')
                     ->execute();
        foreach ($result as $upload_row) {
          $row->upload[] = $upload_row->fid;
          $row->{'upload:description'}[] = $upload_row->description;
          $row->{'upload:list'}[] = $upload_row->list;
          $row->{'upload:weight'}[] = $upload_row->weight;
        }
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
    migrate_instrument_start('DrupalVersion6::profileFields');

    // Get any content_profile node types. A variable named content_profile_use_foo
    // with a serialized value of 1 means foo is a node type of interest.
    $names = Database::getConnection('default', $this->arguments['source_connection'])
             ->select('variable', 'v')
             ->fields('v', array('name'))
             ->condition('name', 'content_profile_use_%', 'LIKE')
             ->condition(db_or()
                 ->condition('value', 'i:1;')
                 ->condition('value', 'b:1;')
               )
             ->execute()
             ->fetchCol();
    $index = strlen('content_profile_use_');
    foreach ($names as $name) {
      $type_name = substr($name, $index);
      $this->profileTypes[] = $type_name;
      // Populates sourceFieldInfo directly
      $this->populateSourceFieldInfo('node', $type_name, TRUE);
    }

    // If the profile node type is defined by a feature, the content_profile
    // variable may not be in the variables table, but we might find it
    // strongarmed in cache.
    $strongarm = Database::getConnection('default', $this->arguments['source_connection'])
             ->select('cache', 'c')
             ->fields('c', array('data'))
             ->condition('cid', 'strongarm')
             ->execute()
             ->fetchField();
    if ($strongarm) {
      $strongarm = unserialize($strongarm);
      $prefix = 'content_profile_use_';
      $prefix_len = strlen($prefix);
      foreach ($strongarm as $key => $value) {
        if (substr($key, 0, $prefix_len) == $prefix && $value == 1) {
          $type_name = substr($key, $prefix_len);
          if (!in_array($type_name, $this->profileTypes)) {
            $this->profileTypes[] = $type_name;
            // Populates sourceFieldInfo directly
            $this->populateSourceFieldInfo('node', $type_name, TRUE);
          }
        }
      }
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

    migrate_instrument_stop('DrupalVersion6::profileFields');
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
      migrate_instrument_start('DrupalVersion6::getProfileValues');
      $query = Database::getConnection('default', $this->arguments['source_connection'])
               ->select('profile_values', 'v')
               ->fields('v', array('value'))
               ->condition('uid', $entity_id)
               ->condition('value', '', '<>');
      $query->innerJoin('profile_fields', 'f', 'v.fid=f.fid');
      $query->fields('f', array('name', 'type'));
      $result = $query->execute();
      foreach ($result as $data_row) {
        switch ($data_row->type) {
          case 'checkbox':
            switch (trim(strtolower($data_row->value))) {
              case 'n':
                $data_row->value = 0;
                break;
              case 'y':
                $data_row->value = 1;
                break;
              default:
                break;
            }
            break;
          case 'date':
            // Dates may be serialized arrays or NULLs.
            if (strpos($data_row->value, 'a:') === 0) {
              $date_array = unserialize($data_row->value);
              $data_row->value = $date_array['year'] . '-' . $date_array['month']
                . '-' . $date_array['day'];
            }
            elseif (strpos($data_row->value, 'N;') === 0) {
              $data_row->value = NULL;
            }
            break;
        }
        $row->{$data_row->name} = $data_row->value;
      }

      migrate_instrument_stop('DrupalVersion6::getProfileValues');
    }
  }
}
