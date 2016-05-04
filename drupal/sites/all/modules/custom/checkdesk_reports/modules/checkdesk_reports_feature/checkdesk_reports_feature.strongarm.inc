<?php
/**
 * @file
 * checkdesk_reports_feature.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function checkdesk_reports_feature_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_draft_enabled_media';
  $strongarm->value = 0;
  $export['save_draft_enabled_media'] = $strongarm;

  return $export;
}
