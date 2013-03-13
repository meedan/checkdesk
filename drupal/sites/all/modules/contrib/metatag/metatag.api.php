<?php
/**
 * @file
 * API documentation for the Metatag module.
 */

/**
 * 
 */
function hook_metatag_config_default() {
  return array();
}

/**
 * 
 */
function hook_metatag_config_default_alter(&$config) {
}

/**
 * 
 */
function hook_metatag_config_delete($type, $ids) {
}

/**
 * 
 */
function hook_metatag_config_insert($config) {
}

/**
 * 
 */
function hook_metatag_config_instance_info() {
  return array();
}

/**
 * 
 */
function hook_metatag_config_instance_info_alter(&$info) {
}

/**
 * 
 */
function hook_metatag_config_load() {
}

/**
 * 
 */
function hook_metatag_config_load_presave() {
}

/**
 * 
 */
function hook_metatag_config_presave($config) {
}

/**
 * 
 */
function hook_metatag_config_update($config) {
}

/**
 * 
 */
function hook_metatag_info() {
  return array();
}

/**
 * 
 */
function hook_metatag_info_alter(&$info) {
}

/**
 * 
 */
function hook_metatag_load_entity_from_path_alter(&$path, $result) {
}

/**
 * Alter metatags before being cached.
 *
 * This hook is invoked prior to the meta tags for a given page are cached.
 *
 * @param array $output
 *   All of the meta tags to be output for this page in their raw format. This
 *   is a heavily nested array.
 * @param string $instance
 *   An identifier for the current page's page type, typically a combination
 *   of the entity name and bundle name, e.g. "node:story".
 */
function hook_metatag_metatags_view_alter(&$output, $instance) {
  if (isset($output['description']['#attached']['drupal_add_html_head'][0][0]['#value'])) {
    $output['description']['#attached']['drupal_add_html_head'][0][0]['#value'] = 'O rly?';
  }
}

/**
 * 
 */
function hook_metatag_page_cache_cid_parts_alter(&$cid_parts) {
}

/**
 * 
 */
function hook_metatag_presave(&$metatags, $type, $id) {
}
