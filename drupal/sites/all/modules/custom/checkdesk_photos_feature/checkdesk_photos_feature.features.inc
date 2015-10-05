<?php
/**
 * @file
 * checkdesk_photos_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_photos_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
