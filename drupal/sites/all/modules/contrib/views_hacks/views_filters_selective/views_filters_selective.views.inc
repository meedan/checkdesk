<?php
/**
 * @file
 * Integration with Views.
 */

/**
 * Implementation of hook_views_data_alter()
 */
function views_filters_selective_views_data_alter(&$data) {
  foreach ($data as $table_name => $table_info) {
    foreach ($table_info as $field_name => $field_info) {
      if (!empty($field_info['filter']['handler']) && $field_info['filter']['handler'] != 'views_handler_filter_selective') {
        $selective = $field_info;
        $selective['title'] = (!empty($field_info['filter']['title']) ? $field_info['filter']['title'] : $field_info['title']) . ' (selective)';
        $selective['filter']['handler'] = 'views_handler_filter_selective';
        $selective['filter']['proxy'] = $field_info['filter']['handler'];
        $selective['filter']['field'] = $field_name;
        unset($selective['argument'], $selective['field'], $selective['relationship'], $selective['sort'], $selective['filter']['title']);
        $data[$table_name][$field_name . '_selective'] = $selective;
      }
    }
  }
}

/**
 * Implementation of hook_views_handlers()
 */
function views_filters_selective_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_filters_selective'),
    ),
    'handlers' => array(
      'views_handler_filter_selective' => array(
        'parent' => 'views_handler_filter_in_operator',
      ),
    ),
  );
}

