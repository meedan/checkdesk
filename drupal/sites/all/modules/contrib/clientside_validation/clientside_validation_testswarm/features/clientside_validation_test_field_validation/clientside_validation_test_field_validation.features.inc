<?php
/**
 * @file
 * clientside_validation_test_field_validation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function clientside_validation_test_field_validation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_node_info().
 */
function clientside_validation_test_field_validation_node_info() {
  $items = array(
    'cv_test_field_validation' => array(
      'name' => t('Clientside Validation Test Field Validation'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
