<?php
/**
 * @file
 * checkdesk_featured_stories_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function checkdesk_featured_stories_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodequeue_tab_name';
  $strongarm->value = 'Add to';
  $export['nodequeue_tab_name'] = $strongarm;

  return $export;
}
