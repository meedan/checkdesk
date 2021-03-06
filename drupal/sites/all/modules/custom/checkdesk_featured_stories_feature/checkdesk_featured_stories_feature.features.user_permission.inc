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

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'edit revisions'.
  $permissions['edit revisions'] = array(
    'name' => 'edit revisions',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'flag delete'.
  $permissions['flag delete'] = array(
    'name' => 'flag delete',
    'roles' => array(
      'citizen journalist' => 'citizen journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag factcheck'.
  $permissions['flag factcheck'] = array(
    'name' => 'flag factcheck',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: 'flag factcheck_journalist'.
  $permissions['flag factcheck_journalist'] = array(
    'name' => 'flag factcheck_journalist',
    'roles' => array(
      'administrator' => 'administrator',
      'citizen journalist' => 'citizen journalist',
      'journalist' => 'journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag follow_story'.
  $permissions['flag follow_story'] = array(
    'name' => 'flag follow_story',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag graphic'.
  $permissions['flag graphic'] = array(
    'name' => 'flag graphic',
    'roles' => array(
      'citizen journalist' => 'citizen journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag graphic_journalist'.
  $permissions['flag graphic_journalist'] = array(
    'name' => 'flag graphic_journalist',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag spam'.
  $permissions['flag spam'] = array(
    'name' => 'flag spam',
    'roles' => array(
      'citizen journalist' => 'citizen journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'override discussion promote to front page option'.
  $permissions['override discussion promote to front page option'] = array(
    'name' => 'override discussion promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override discussion revision option'.
  $permissions['override discussion revision option'] = array(
    'name' => 'override discussion revision option',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'publish revisions'.
  $permissions['publish revisions'] = array(
    'name' => 'publish revisions',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'unflag delete'.
  $permissions['unflag delete'] = array(
    'name' => 'unflag delete',
    'roles' => array(
      'citizen journalist' => 'citizen journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag factcheck'.
  $permissions['unflag factcheck'] = array(
    'name' => 'unflag factcheck',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: 'unflag factcheck_journalist'.
  $permissions['unflag factcheck_journalist'] = array(
    'name' => 'unflag factcheck_journalist',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag follow_story'.
  $permissions['unflag follow_story'] = array(
    'name' => 'unflag follow_story',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag graphic'.
  $permissions['unflag graphic'] = array(
    'name' => 'unflag graphic',
    'roles' => array(
      'citizen journalist' => 'citizen journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag graphic_journalist'.
  $permissions['unflag graphic_journalist'] = array(
    'name' => 'unflag graphic_journalist',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag spam'.
  $permissions['unflag spam'] = array(
    'name' => 'unflag spam',
    'roles' => array(),
    'module' => 'flag',
  );

  // Exported permission: 'unpublish current revision'.
  $permissions['unpublish current revision'] = array(
    'name' => 'unpublish current revision',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view any unpublished discussion content'.
  $permissions['view any unpublished discussion content'] = array(
    'name' => 'view any unpublished discussion content',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished post content'.
  $permissions['view any unpublished post content'] = array(
    'name' => 'view any unpublished post content',
    'roles' => array(
      'administrator' => 'administrator',
      'journalist' => 'journalist',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view revision status messages'.
  $permissions['view revision status messages'] = array(
    'name' => 'view revision status messages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: 'view revisions of own discussion content'.
  $permissions['view revisions of own discussion content'] = array(
    'name' => 'view revisions of own discussion content',
    'roles' => array(
      'citizen journalist' => 'citizen journalist',
    ),
    'module' => 'revisioning',
  );

  return $permissions;
}
