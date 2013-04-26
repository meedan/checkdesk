<?php
/**
 * @file
 * checkdesk_multilingual_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_multilingual_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function checkdesk_multilingual_feature_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_views_default_views_alter().
 */
function checkdesk_multilingual_feature_views_default_views_alter(&$data) {
  if (isset($data['liveblog'])) {
    $data['liveblog']->display['default']->display_options['filters']['language'] = array(
      'id' => 'language',
      'table' => 'node',
      'field' => 'language',
      'value' => array(
        '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
      ),
    ); /* WAS: '' */
  }
  if (isset($data['stories_for_updates'])) {
    $data['stories_for_updates']->display['default']->display_options['filters']['language'] = array(
      'id' => 'language',
      'table' => 'node',
      'field' => 'language',
      'value' => array(
        '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
      ),
    ); /* WAS: '' */
  }
}
