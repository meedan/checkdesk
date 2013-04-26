<?php
/**
 * @file
 * checkdesk_core_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function checkdesk_core_feature_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: citizen journalist.
  $roles['citizen journalist'] = array(
    'name' => 'citizen journalist',
    'weight' => 4,
  );

  // Exported role: journalist.
  $roles['journalist'] = array(
    'name' => 'journalist',
    'weight' => 3,
  );

  return $roles;
}
