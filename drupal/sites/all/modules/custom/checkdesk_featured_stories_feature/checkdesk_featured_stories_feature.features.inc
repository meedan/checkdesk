<?php
/**
 * @file
 * checkdesk_featured_stories_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_featured_stories_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function checkdesk_featured_stories_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function checkdesk_featured_stories_feature_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: featured_stories
  $nodequeues['featured_stories'] = array(
    'name' => 'featured_stories',
    'title' => 'Featured Stories',
    'subqueue_title' => '',
    'size' => 1,
    'link' => 'Feature this story',
    'link_remove' => 'Unfeature this story',
    'owner' => 'nodequeue',
    'show_in_ui' => 1,
    'show_in_tab' => 1,
    'show_in_links' => 1,
    'reference' => 0,
    'reverse' => 1,
    'i18n' => 0,
    'insert_at_front' => 0,
    'subqueues' => 1,
    'types' => array(
      0 => 'discussion',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
