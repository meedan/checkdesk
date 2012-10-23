<?php
/**
 * @file
 * checkdesk_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_core_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function checkdesk_core_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function checkdesk_core_node_info() {
  $items = array(
    'discussion' => array(
      'name' => t('Discussion'),
      'base' => 'node_content',
      'description' => t('A multimedia, multilingual discussion.'),
      'has_title' => '1',
      'title_label' => t('Topic'),
      'help' => '',
    ),
    'post' => array(
      'name' => t('Post'),
      'base' => 'node_content',
      'description' => t('Post emanating from a desk.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
