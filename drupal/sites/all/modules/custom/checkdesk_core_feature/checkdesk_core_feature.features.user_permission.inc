<?php
/**
 * @file
 * checkdesk_core_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function checkdesk_core_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: execute php code.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: save draft.
  $permissions['save draft'] = array(
    'name' => 'save draft',
    'roles' => array(
      0 => 'administrator',
      1 => 'journalist',
    ),
    'module' => 'save_draft',
  );

  return $permissions;
}
