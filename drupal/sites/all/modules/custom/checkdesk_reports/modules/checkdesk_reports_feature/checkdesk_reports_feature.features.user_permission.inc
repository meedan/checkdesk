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

  // Exported permission: 'access graphic journalist flag'.
  $permissions['access graphic journalist flag'] = array(
    'name' => 'access graphic journalist flag',
    'roles' => array(),
    'module' => 'checkdesk_reports',
  );

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

  // Exported permission: 'create field_rating'.
  $permissions['create field_rating'] = array(
    'name' => 'create field_rating',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'delete terms in media_rating'.
  $permissions['delete terms in media_rating'] = array(
    'name' => 'delete terms in media_rating',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'edit field_rating'.
  $permissions['edit field_rating'] = array(
    'name' => 'edit field_rating',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_rating'.
  $permissions['edit own field_rating'] = array(
    'name' => 'edit own field_rating',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'field_permissions',
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

  // Exported permission: 'edit terms in media_rating'.
  $permissions['edit terms in media_rating'] = array(
    'name' => 'edit terms in media_rating',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
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

  // Exported permission: 'view field_rating'.
  $permissions['view field_rating'] = array(
    'name' => 'view field_rating',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_rating'.
  $permissions['view own field_rating'] = array(
    'name' => 'view own field_rating',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
