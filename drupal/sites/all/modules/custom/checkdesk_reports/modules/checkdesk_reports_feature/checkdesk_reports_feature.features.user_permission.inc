<?php
/**
 * @file
 * checkdesk_reports_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function checkdesk_reports_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add report to story'.
  $permissions['add report to story'] = array(
    'name' => 'add report to story',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'checkdesk_reports',
  );

  // Exported permission: 'change report status'.
  $permissions['change report status'] = array(
    'name' => 'change report status',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'checkdesk_reports',
  );

  // Exported permission: 'create media content'.
  $permissions['create media content'] = array(
    'name' => 'create media content',
    'roles' => array(
      'administrator' => 'administrator',
      'citizen journalist' => 'citizen journalist',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any media content'.
  $permissions['delete any media content'] = array(
    'name' => 'delete any media content',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own media content'.
  $permissions['delete own media content'] = array(
    'name' => 'delete own media content',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any media content'.
  $permissions['edit any media content'] = array(
    'name' => 'edit any media content',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own media content'.
  $permissions['edit own media content'] = array(
    'name' => 'edit own media content',
    'roles' => array(
      'administrator' => 'administrator',
      'citizen journalist' => 'citizen journalist',
      'journalist' => 'journalist',
    ),
    'module' => 'node',
  );

  // Exported permission: 'export reports'.
  $permissions['export reports'] = array(
    'name' => 'export reports',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'checkdesk_reports',
  );

  return $permissions;
}
