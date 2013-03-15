<?php

/**
 * Implements hook_views_data_alter().
 */
function checkdesk_core_views_data_alter(&$data) {
  // tid field (translated)
  $data['taxonomy_term_data']['tid_i18n'] = array(
    'title' => t('Term ID (translated)'),
    'help' => t('The translated taxonomy term ID.'),
    'filter' => array(
      'title' => t('Term (translated)'),
      'help' => t('Taxonomy term chosen from autocomplete or select widget.'),
      'handler' => 'checkdesk_core_handler_filter_taxonomy_index_tid',
      'hierarchy table' => 'taxonomy_term_hierarchy',
      'numeric' => TRUE,
    ),
  );

  // Add Term name field (translated)
  $data['taxonomy_term_data']['name_i18n'] = array(
    'title' => t('Name (translated)'),
    'help' => t('The translated taxonomy term name.'),
    'field' => array(
      'handler' => 'checkdesk_core_handler_field_taxonomy_term_name',
      'click sortable' => TRUE,
      // name_i18n is not a real field in the database but we could actually let's just add the name, that's we need too.
      'real field' => 'name',
    ),
  );
}

/**
 * Implements hook_field_views_data_alter().
 */
function checkdesk_core_field_views_data_alter(&$data, &$field, $module) {
  if ($module == 'taxonomy' && module_exists('i18n_taxonomy')) {
    foreach ($data as $table_name => $table_data) {
      foreach ($table_data as $field_name => $field_data) {
        if (isset($field_data['filter'])) {
          $data[$table_name][$field_name . '_i18n'] = $data[$table_name][$field_name];
          $data[$table_name][$field_name . '_i18n']['real field'] = $field_name;
          $data[$table_name][$field_name . '_i18n']['title'] .= ' (translated)';
          $data[$table_name][$field_name . '_i18n']['filter']['handler'] = 'checkdesk_core_handler_filter_taxonomy_index_tid';
        }
      }
    }
  }
}

