<?php
/**
 * @file
 * checkdesk_sources_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function checkdesk_sources_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create source content'.
  $permissions['create source content'] = array(
    'name' => 'create source content',
    'roles' => array(
      'administrator' => 'administrator',
      'citizen journalist' => 'citizen journalist',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any source content'.
  $permissions['delete any source content'] = array(
    'name' => 'delete any source content',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own source content'.
  $permissions['delete own source content'] = array(
    'name' => 'delete own source content',
    'roles' => array(
      'administrator' => 'administrator',
      'citizen journalist' => 'citizen journalist',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any source content'.
  $permissions['edit any source content'] = array(
    'name' => 'edit any source content',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own source content'.
  $permissions['edit own source content'] = array(
    'name' => 'edit own source content',
    'roles' => array(
      'administrator' => 'administrator',
      'citizen journalist' => 'citizen journalist',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  return $permissions;
}
