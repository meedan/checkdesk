<?php
/**
 * @file
 * checkdesk_core_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_core_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function checkdesk_core_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function checkdesk_core_feature_node_info() {
  $items = array(
    'discussion' => array(
      'name' => t('Desk'),
      'base' => 'node_content',
      'description' => t('A desk is where a story is discussed and media are verified.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
    'media' => array(
      'name' => t('Report'),
      'base' => 'node_content',
      'description' => t('A report containing a media item.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'post' => array(
      'name' => t('Liveblog Post'),
      'base' => 'node_content',
      'description' => t('A liveblog post.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
