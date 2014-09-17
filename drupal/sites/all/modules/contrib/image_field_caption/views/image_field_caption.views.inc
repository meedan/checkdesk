<?php

/**
 * Implementation of hook_views_data().
 */
function image_field_caption_views_data() {
  $data = array();

  foreach (field_info_instances() as $entity_type => $bundles) {
    foreach ($bundles as $bundle => $fields) {
      foreach ($fields as $field_name => $field) {
        // Skip any deleted and non image widget fields.
        if ($field['deleted'] == 1) {
          continue;
        }
        if ($field['widget']['type'] != 'image_image') {
          continue;
        }

        $field_info = field_info_field($field_name);
        // The list of entity:bundle that this field is used in.
        $bundles_names = array();

        //$group_name = count($field_info['bundles']) > 1 ? t('Field') : NULL;

        // Build the relationships between the field table and the entity tables.
        foreach ($field_info['bundles'] as $entity => $bundles) {
          foreach ($bundles as $bundle) {
            $bundles_names[] = t('@entity:@bundle', array('@entity' => $entity, '@bundle' => $bundle));
          }
        }

        list($label, $all_labels) = field_views_field_label($field_name);

        $current_table = 'field_image_field_caption';
        $revision_table = 'field_image_field_caption_revision';

        $entity_info = entity_get_info($entity_type);

        $group = t('Image field caption');

        $data[$field_name . '_' . $current_table]['table']['join'][$entity_info['base table']] = array(
          'table' => $current_table,
          'handler' => 'image_field_caption_handler_join',
          'left_table' =>  _field_sql_storage_tablename($field),
          'left_field' => 'entity_id',
          'field' => 'entity_id',
          'extra' => array(
            array('field' => 'entity_type', 'value' => $entity_type),
            array('field' => 'field_name', 'value' => $field_name),
          ),
        );

        $data[$field_name . '_' . $current_table]['caption'] = array(
          'title' => $label . t(' (caption)'),
          'help' =>  t('Appears in: @bundles.', array('@bundles' => implode(', ', $bundles_names))),
          // Information for accepting a nid as an argument
          'field' => array(
            'handler' => 'views_handler_field',
            'name field' => 'caption', // the field to display in the summary.
          ),
        );
        foreach ($all_labels as $entity_name => $labels) {
          foreach ($labels as $label_name => $true) {
            if ($label_name != $label) {
              $data[$field_name . '_' . $current_table]['caption']['aliases'][] = array(
                'title' => $label_name . t(' (caption)'),
                'help' => t('This is an alias of @field.', array('@field' => $label)),
                'group' => $group,
              );
            }
          }
        }

        $data[$field_name . '_' . $current_table]['table']['group'] = $group;

        if (!empty($entity_info['entity keys']['revision']) && !empty($entity_info['revision table'])) {
          $group .= ' ' . t('(historical data)');

          $data[$field_name . '_' . $revision_table]['table']['join'][$entity_info['revision table']] = array(
            'table' => $revision_table,
            'handler' => 'image_field_caption_handler_join',
            'left_table' =>  _field_sql_storage_revision_tablename($field),
            'left_field' => 'revision_id',
            'field' => 'revision_id',
            'extra' => array(
              array('field' => 'entity_type', 'value' => $entity_type),
              array('field' => 'field_name', 'value' => $field_name),
            ),
          );

          $data[$field_name . '_' . $revision_table]['caption'] = array(
            'title' => $label . t(' (caption)'),
            'help' =>  t('Appears in: @bundles.', array('@bundles' => implode(', ', $bundles_names))),
            // Information for accepting a nid as an argument
            'field' => array(
              'handler' => 'views_handler_field',
              'name field' => 'caption', // the field to display in the summary.
            ),
          );

          $data[$field_name . '_' . $revision_table]['table']['group'] = $group;

          foreach ($all_labels as $entity_name => $labels) {
            foreach ($labels as $label_name => $true) {
              if ($label_name != $label) {
                $data[$field_name . '_' . $revision_table]['caption']['aliases'][] = array(
                  'title' => $label_name . t(' (caption)'),
                  'help' => t('This is an alias of @field.', array('@field' => $label)),
                  'group' => $group,
                );
              }
            }
          }

        }
      }
    }
  }

  return $data;
}
