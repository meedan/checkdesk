<?php
/**
 * @file
 * checkdesk_featured_stories_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function checkdesk_featured_stories_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'nodequeue',
  );

  return $permissions;
}
