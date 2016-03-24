<?php
/**
 * @file
 * checkdesk_sources_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_sources_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function checkdesk_sources_feature_node_info() {
  $items = array(
    'source' => array(
      'name' => t('Source'),
      'base' => 'node_content',
      'description' => t('A source is a URL that contains reports'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
