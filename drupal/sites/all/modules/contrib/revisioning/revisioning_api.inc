<?php

/**
 * @file
 * API functions of Revisioning module
 *
 * Reusable functions that do the dirty work.
 */

define('REVISION_ARCHIVED', 0);
define('REVISION_CURRENT', 1);
define('REVISION_PENDING', 2);

/**
 * Some naming conventions
 *
 * Pending:
 *   - revision with (vid > current_vid) of ANY node
 *     OR single revision of UNPUBLISHED node
 * Current, published:
 *   - revision with (vid == current_vid) of PUBLISHED node
 * Archived:
 *   - all other revisions, i.e.
 *     revision with (vid < current_vid) of ANY node
 *     OR revision with (vid == current_vid) of UNPUBLISHED node
 *
 * Note: these will change when Revisioning is going to store revision states
 * independently from vid number (e.g. in different table).
 */

/**
 * Set node revision info.
 *
 * We use this in revisioning_node_load() to set up some useful node properties
 * that may be read later, whether it be in this module or another, thus
 * removing the need for multiple calls in various places to retrieve the same
 * info.
 */
function revisioning_set_node_revision_info(&$node) {
  if (!isset($node->num_revisions) && isset($node->nid)) {
    // We need this info for updated content even if it is not moderated.
    // Luckily this info is easily retrieved.
    $node->num_revisions = revisioning_get_number_of_revisions($node->nid);
    $node->current_revision_id = revisioning_get_current_node_revision_id($node->nid);
    $node->is_current = revisioning_revision_is_current($node);
    $node->is_pending = _revisioning_node_is_pending($node);
  }
  // The revision_moderation flag may be overridden on the node edit form by
  // users with the "administer nodes" permission. By implication, the 'Publish'
  // link needs to be available to those users, for any content with a pending
  // revision, as the publish check box on the edit form applies to the current
  // rather than the pending revision(s).
  if (!isset($node->revision_moderation)) {
    $node->revision_moderation = revisioning_content_is_moderated($node->type, $node);
  }
  // $node->uid and $node->revision_uid were already set in node_load()
  // $node->revision is set as part of 'prepare'-op, see node_object_prepare()
}

/**
 * Get the number of revisions belonging to a node.
 *
 * @param int $nid
 *   id of the node
 *
 * @return int
 *   A count representing the number of revisions associated with the node
 */
function revisioning_get_number_of_revisions($nid) {
  $result = db_query("SELECT COUNT(vid) FROM {node_revision} WHERE nid = :nid", array(':nid' => $nid));
  return $result->fetchField();
}

/**
 * Get the number of archived revisions belonging to a node.
 *
 * @param object $node
 *   the node object
 *
 * @return int
 *   A count representing the number of archived revisions for the node
 *   Returns zero if there is only one (i.e. current) revision.
 */
function revisioning_get_number_of_archived_revisions($node) {
  $result = db_query("SELECT COUNT(vid) FROM {node_revision} WHERE nid = :nid AND vid < :vid", array(
    ':nid' => $node->nid,
    ':vid' => $node->current_revision_id,
  ));
  return $result->fetchField();
}

/**
 * Delete all revisions with a vid less than the current.
 *
 * Use node_revision_delete from node.module to ensure that we cleanup not
 * only node revisions but also all attached field revisions as well.
 */
function revisioning_delete_archived_revisions($node) {
  $revisions = db_select('node_revision', 'n')
    ->fields('n', array('vid'))
    ->condition('n.nid', $node->nid)
    ->condition('n.vid', $node->current_revision_id, '<')
    ->execute();

  foreach ($revisions as $rev) {
    node_revision_delete($rev->vid);
  }
}

/**
 * Get the id of the current revision that the supplied node is pointing to.
 *
 * Used in cases where the node object wasn't fully loaded or was loaded
 * with a different revision.
 *
 * @param int $nid
 *   The id of the node whose current revision id is to be returned.
 *
 * @return int
 *   A single number being the current revision id (vid).
 */
function revisioning_get_current_node_revision_id($nid) {
  $result = db_query("SELECT vid FROM {node} WHERE nid = :nid", array(':nid' => $nid));
  return $result->fetchField();
}

/**
 * Get the id of the user who last edited the supplied node.
 *
 * ie. the author of the latest revision.
 *
 * This is irrespective of whether this latest revision is pending or not,
 * unless TRUE is specified for the second argument, in which case the uid
 * of the creator of the current revision (published or not) is returned.
 *
 * @param int $nid
 *   The id of the node whose most recent editor id is to be returned.
 * @param bool $current
 *   Whether the uid of the current or very latest revision should be returned.
 *
 * @return int
 *   A single number being the user id (uid).
 */
function revisioning_get_last_editor($nid, $current = FALSE) {
  $sql = ($current) ? "SELECT vid FROM {node} WHERE nid = :nid" : "SELECT MAX(vid) FROM {node_revision} WHERE nid = :nid";
  $vid = db_query($sql, array(':nid' => $nid))->fetchField();
  $result = db_query("SELECT uid FROM {node_revision} WHERE vid = :vid", array(':vid' => $vid));
  return $result->fetchField();
}

/**
 * Return whether the currenly loaded revision is the current one.
 *
 * @param object $node
 *   The node object
 *
 * @return bool
 *   TRUE if the currently loaded node revision is the current revision
 */
function revisioning_revision_is_current($node) {
  return isset($node->vid) && isset($node->current_revision_id) && $node->vid == $node->current_revision_id;
}

/**
 * Return whether the supplied content type is subject to moderation.
 *
 * @param string $content_type
 *   i.e. machine name, ie. $node->type
 * @param object $node
 *   (optional) argument to implement "moderation opt-in" for nodes that are not
 *   moderated by default (i.e by their content type).
 *
 * @return bool
 *   TRUE, if the supplied type has the "New revision in draft, pending
 *   moderation" box ticked on the Structure >> Content types >> edit page OR
 *   when a pending revision exists. The latter is to support the feature of
 *   "moderate at any time" available to users with the "administer nodes"
 *   permission.
 */
function revisioning_content_is_moderated($content_type, $node = NULL) {
  $content_type_is_moderated = !empty($content_type) && in_array('revision_moderation', variable_get('node_options_' . $content_type, array()));
  if (!$content_type_is_moderated && isset($node->nid) && isset($node->current_revision_id)) {
    $latest_vid = revisioning_get_latest_revision_id($node->nid);
    return $latest_vid > $node->current_revision_id;
  }
  return $content_type_is_moderated;
}

/**
 * Return whether the user has permission to auto-publish the supplied node.
 *
 * Auto-publish applies only for content types for which this feature has been
 * activated on the content type form and only when "New revision in draft,
 * pending moderation" is ticked also.
 *
 * @param object $node
 *   The node object
 */
function revisioning_user_may_auto_publish($node) {
  return variable_get('revisioning_auto_publish_' . $node->type, FALSE) && revisioning_user_node_access('publish revisions', $node);
}

/**
 * Return a single or all possible revision state names.
 *
 * @param int $state
 *   (optional) state id, as defined in revisioning_api.inc
 *
 * @return array|string
 *   if $state is provided, state name. Otherwise, an array keyed by state id.
 */
function revisioning_revision_states($state = NULL) {
  $states = array(
    REVISION_ARCHIVED => t('Archived'),
    REVISION_CURRENT  => t('Current, published'),
    REVISION_PENDING  => t('Pending'),
  );
  return $state === NULL ? $states : $states[$state];
}

/**
 * Check for a pending revision.
 *
 * Return TRUE when either of the following is true:
 * o the supplied node has at least one revision more recent than the current
 * o the node is not yet published and consists of a single revision
 *
 * Relies on vid, current_revision_id and num_revisions set on the node object,
 * see function revisioning_set_node_revision_info()
 *
 * @param object $node
 *   The node object
 *
 * @return bool
 *   TRUE, if node is pending according to the above definition
 */
function _revisioning_node_is_pending($node) {
  return isset($node->vid) && isset($node->current_revision_id) &&
    ($node->vid > $node->current_revision_id || (!$node->status && $node->num_revisions == 1));
}

/**
 * Implements hook_revisionapi().
 *
 * Act on various revision events.
 *
 * "Pre" operations can be useful to get values before they are lost or changed,
 * for example, to save a backup of revision before it's deleted.
 * Also, for "pre" operations vetoing mechanics could be implemented, so it
 * would be possible to veto an operation via hook_revisionapi(). For example,
 * when the hook is returning FALSE, operation will be vetoed.
 */
function revisioning_revisionapi($op, $node) {
  switch ($op) {

    case 'post update':
      if (module_exists('rules')) {
        rules_invoke_event('revisioning_post_update', $node);
      }
      break;

    case 'pre publish':
      if (module_exists('rules')) {
        rules_invoke_event('revisioning_pre_publish', $node);
      }
      break;

    case 'post publish':
      // Called from _revisioning_publish_revision.
      // Invoke hook_revision_publish() triggers, passing the node as argument.
      module_invoke_all('revision_publish', $node);

      if (module_exists('rules')) {
        rules_invoke_event('revisioning_post_publish', $node);
      }
      break;

    case 'post unpublish':
      // Called from _revisioning_unpublish_revision().
      // Invoke hook_revision_unpublish triggers passing the node as an arg.
      module_invoke_all('revision_unpublish', $node);

      if (module_exists('rules')) {
        rules_invoke_event('revisioning_post_unpublish', $node);
      }
      break;

    case 'pre revert':
      if (module_exists('rules')) {
        rules_invoke_event('revisioning_pre_revert', $node);
      }
      break;

    case 'post revert':
      // Called from revisioning_revert_confirm_post_submit().
      // Invoke hook_revision_revert() triggers passing the node as an arg.
      module_invoke_all('revision_revert', $node);

      if (module_exists('rules')) {
        rules_invoke_event('revisioning_post_revert', $node);
      }
      break;

    case 'pre delete':
      if (module_exists('rules')) {
        rules_invoke_event('revisioning_pre_delete', $node);
      }
      break;

    case 'post delete':
      break;
  }
}

/**
 * Get the id of the latest revision belonging to a node.
 *
 * @param int $nid
 *   id of the node
 *
 * @return int
 *   ID of the latest revision.
 */
function revisioning_get_latest_revision_id($nid) {
  $result = db_query("SELECT MAX(vid) FROM {node_revision} WHERE nid = :nid", array(':nid' => $nid));
  return $result->fetchField();
}

/**
 * Revert node to selected revision without changing its publication status.
 *
 * @param object|int $node
 *   Target $node object (loaded with target revision) or nid of target node
 * @param int $vid
 *   (optional) vid of revision to revert to, if provided $node must not be an
 *   object.
 */
function _revisioning_revertpublish_revision(&$node, $vid = NULL) {
  $node_revision = is_object($node) ? $node : node_load($node, $vid);
  $return = module_invoke_all('revisionapi', 'pre revert', $node_revision);
  if (in_array(FALSE, $return)) {
    drupal_goto('node/' . $node_revision->nid . '/revisions/' . $node_revision->vid . '/view');
  }
  _revisioning_revert_revision($node_revision);
  module_invoke_all('revisionapi', 'post revert', $node_revision);
}

/**
 * Revert node to selected revision without publishing it.
 *
 * This is same as node_revision_revert_confirm_submit() in node_pages.inc,
 * except it doesn't put any messages on screen.
 *
 * @param object|int $node
 *   Target $node object (loaded with target revision) or nid of target node
 * @param int $vid
 *   (optional) vid of revision to revert to, if provided $node is not an
 *   object.
 */
function _revisioning_revert_revision(&$node, $vid = NULL) {
  $node_revision = is_object($node) ? $node : node_load($node, $vid);
  $node_revision->revision = 1;
  $node_revision->log = t('Copy of the revision from %date.', array('%date' => format_date($node_revision->revision_timestamp)));
  if (module_exists('taxonomy')) {
    $node_revision->taxonomy = array_keys($node_revision->taxonomy);
  }
  node_save($node_revision);
  watchdog('content', '@type: reverted %title revision %revision.', array(
    '@type' => $node_revision->type,
    '%title' => $node_revision->title,
    '%revision' => $node_revision->vid,
  ));
}

/**
 * Unpublish node, without calling node_save().
 *
 * @param object|int $nid_or_node
 *   Target $node object or nid of target node
 * @param bool $clear_cache
 *   Whether to clear the cache afterwards or not. Clearing the cache on every
 *   node during bulk operations can be time-consuming.
 */
function _revisioning_unpublish_node($nid_or_node, $clear_cache = TRUE) {
  $node = is_object($nid_or_node) ? $nid_or_node : node_load($nid_or_node);

  db_update('node')
    ->fields(array(
      'changed' => time(),
      'status' => NODE_NOT_PUBLISHED))
    ->condition('nid', $node->nid)
    ->execute();

  db_update('node_revision')
    ->fields(array('status' => NODE_NOT_PUBLISHED))
    ->condition('vid', $node->vid)
    ->execute();

  $node->status = NODE_NOT_PUBLISHED;

  // Make sure the alias, if present, is not changed when unpublishing.
  if (!isset($node->path['pathauto'])) {
    $node->path = array(
      // So that pathauto_node_update() does nothing.
      'alias' => '',
      // So that pathauto_node_update() does nothing.
      'pathauto' => FALSE,
    );
  }
  elseif (!isset($node->path['alias'])) {
    // [#1328180], [#1576552]
    $node->path['alias'] = '';
  }
  $node->original = clone $node;
  $node->original->status = NODE_PUBLISHED;

  module_invoke_all('node_update', $node);
  module_invoke_all('entity_update', $node, 'node');

  // Update node_access table.
  node_access_acquire_grants($node);

  if ($clear_cache) {
    cache_clear_all();
  }
}

/**
 * Delete selected revision of node, provided it's not current.
 *
 * This is same as node_revision_delete_confirm_submit() in node_pages.inc,
 * except it doesn't put any messages on the screen. This way it becomes
 * reusable (eg. in actions).
 *
 * @param object $node
 *   Target $node object (loaded with target revision) or nid of target node
 * @param int $vid
 *   (optional) vid of revision to delete, if provided $node is not object.
 *
 * @TODO: Insert check to prevent deletion of current revision of node.
 */
function _revisioning_delete_revision(&$node, $vid = NULL) {
  $node_revision = is_object($node) ? $node : node_load($node, $vid);
  module_invoke_all('revisionapi', 'pre delete', $node_revision);
  db_delete('node_revision')
    ->condition('vid', $node_revision->vid)
    ->execute();
  watchdog('content', '@type: deleted %title revision %revision.', array(
    '@type' => $node_revision->type,
    '%title' => $node_revision->title,
    '%revision' => $node_revision->vid,
  ));
  module_invoke_all('revisionapi', 'post delete', $node_revision);
}

/**
 * Unpublish revision (i.e. the node).
 *
 * Note that no check is made as to whether the initiating user has permission
 * to unpublish this node.
 *
 * @param object $node
 *   Target $node object or nid of target node
 */
function _revisioning_unpublish_revision(&$node) {
  $node_revision = is_object($node) ? $node : node_load($node);
  module_invoke_all('revisionapi', 'pre unpublish', $node_revision);
  _revisioning_unpublish_node($node_revision->nid);
  watchdog('content', 'Unpublished @type %title', array('@type' => $node_revision->type, '%title' => $node_revision->title), WATCHDOG_NOTICE, l(t('view'), "node/$node_revision->nid"));
  module_invoke_all('revisionapi', 'post unpublish', $node_revision);
}

/**
 * Make the supplied revision of the node current and publish it.
 *
 * It is the caller's responsibility to provide a proper revision.
 * Note that no check is made as to whether the initiating user has permission
 * to publish this revision.
 *
 * @param int $node_revision
 *   Target $node object (loaded with target revision)
 * @param bool $clear_cache
 *   Whether to clear the cache afterwards or not. Clearing the cache on every
 *   node during bulk operations can be time-consuming.
 */
function _revisioning_publish_revision(&$node_revision, $clear_cache = TRUE) {

  $return = module_invoke_all('revisionapi', 'pre publish', $node_revision);
  if (in_array(FALSE, $return)) {
    drupal_goto('node/' . $node_revision->nid . '/revisions/' . $node_revision->vid . '/view');
  }
  // Update {node} and {node_revision} tables setting status and other flags.
  db_update('node')
    ->fields(array(
      'vid' => $node_revision->vid,
      'title' => $node_revision->title,
      'changed' => time(),
      'status' => NODE_PUBLISHED,
      'comment' => $node_revision->comment,
      'promote' => $node_revision->promote,
      'sticky' => $node_revision->sticky))
    ->condition('nid', $node_revision->nid)
    ->execute();

  db_update('node_revision')
    ->fields(array('status' => NODE_PUBLISHED))
    ->condition('vid', $node_revision->vid)
    ->execute();

  if (empty($node_revision->is_current)) {
    // Need to set up $node_revision correctly before calling
    // revisioning_update_taxonomy_index(), via revisioning_node_update().
    $node_revision->current_revision_id = $node_revision->vid;
  }
  $node_revision->status = $node_revision->current_status = NODE_PUBLISHED;

  // Make sure the alias, if present, is not changed when publishing.
  if (!isset($node_revision->path['pathauto'])) {
    $node_revision->path = array(
      // So that path_node_update() does nothing.
      'alias' => '',
      // So that pathauto_node_update() does nothing.
      'pathauto' => FALSE,
    );
  }
  elseif (!isset($node_revision->path['alias'])) {
    // [#1328180], [#1576552]
    $node_revision->path['alias'] = '';
  }
  // Make sure the menu, if present, is not changed when publishing [#1698024]
  if (!isset($node_revision->menu)) {
    $node_revision->menu = array(
      'enabled' => '',
      'mlid' => '',
      'link_title' => '',
      'link_path' => '',
      'description' => '',
    );
  }
  elseif (!isset($node_revision->menu)) {
    $node_revision->menu = '';
  }
  $node_revision->original = clone $node_revision;
  $node_revision->original->status = NODE_NOT_PUBLISHED;

  module_invoke_all('node_update', $node_revision);
  module_invoke_all('entity_update', $node_revision, 'node');

  // Update node_access table only for existing nodes. When the node is newly
  // created via the node/add page, node_access_acquire_grants() is called by
  // node_save() anyway. See [#1243018].
  if (empty($node_revision->is_new)) {
    node_access_acquire_grants($node_revision);
  }

  if ($clear_cache) {
    cache_clear_all();
  }

  watchdog('content', 'Published rev #%revision of @type %title',
    array(
      '@type' => $node_revision->type,
      '%title' => $node_revision->title,
      '%revision' => $node_revision->vid,
    ),
    WATCHDOG_NOTICE,
    l(t('view'), "node/$node_revision->nid/revisions/$node_revision->vid/view")
  );
  module_invoke_all('revisionapi', 'post publish', $node_revision);
}

/**
 * Publish latest revision.
 *
 * Find the most recent pending revision, make it current, unless it already is
 * and publish it and its node.
 *
 * Note that no check is made as to whether the initiating user has permission
 * to publish this node.
 *
 * Note that this is a post-save operation that should not be called in
 * response to hook_node_presave(), as invoked from node_save().
 *
 * @param object $node
 *   The node object whose latest pending revision is to be published
 *
 * @return bool
 *   TRUE if operation was successful, FALSE if there is no pending revision to
 *   publish
 */
function _revisioning_publish_latest_revision(&$node) {
  // Get the latest pending revision.
  $pending_revisions = _revisioning_get_pending_revisions($node->nid);
  $latest_pending = array_shift($pending_revisions);
  if ($latest_pending) {
    $node_revision = node_load($node->nid, $latest_pending->vid);
    _revisioning_publish_revision($node_revision);
    return TRUE;
  }
  // If there is no pending revision, take the current revision, provided it is
  // NOT published.
  if (!$node->status) {
    if (!isset($node->is_current)) {
      $node->current_revision_id = revisioning_get_current_node_revision_id($node->nid);
      $node->is_current = revisioning_revision_is_current($node);
    }
    if ($node->is_current) {
      _revisioning_publish_revision($node);
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Return a count of the number of revisions newer than the supplied vid.
 *
 * @param int $vid
 *   The reference vid.
 * @param int $nid
 *   The id of the node.
 *
 * @return int
 *   count of the number of revisions newer than the supplied vid
 */
function _revisioning_get_number_of_revisions_newer_than($vid, $nid) {
  $result = db_query("SELECT COUNT(vid) FROM {node_revision} WHERE nid = :nid AND vid > :vid",
    array(
      ':vid' => $vid,
      ':nid' => $nid,
    )
  );
  return $result->fetchField();
}

/**
 * Return a count of the number of revisions newer than the current revision.
 *
 * @param int $nid
 *   The id of the node.
 *
 * @return int
 *   count of the number of revisions newer than the current revision
 */
function _revisioning_get_number_of_pending_revisions($nid) {
  $result = db_query("SELECT COUNT(r.vid) FROM {node} n INNER JOIN {node_revision} r ON n.nid = r.nid WHERE (r.vid > n.vid AND n.nid = :nid)", array(
    ':nid' => $nid)
  );
  return $result->fetchField();
}

/**
 * Retrieve a list of revisions with a vid greater than the current.
 *
 * @param int $nid
 *   The node id to retrieve.
 *
 * @return array
 *   An array of revisions (latest first), each containing vid, title and
 *   content type.
 */
function _revisioning_get_pending_revisions($nid) {
  $sql = "SELECT r.vid, r.title, n.type FROM {node} n INNER JOIN {node_revision} r ON n.nid = r.nid WHERE (r.vid > n.vid AND n.nid = :nid) ORDER BY r.vid DESC";
  $result = db_query($sql, array(
    ':nid' => $nid)
  );
  $revisions = array();
  foreach ($result as $revision) {
    $revisions[$revision->vid] = $revision;
  }
  return $revisions;
}

/**
 * Return revision type of the supplied node.
 *
 * @param object $node
 *   Node object to check
 *
 * @return int
 *   Revision type
 */
function _revisioning_revision_is(&$node) {
  if ($node->is_pending) {
    return REVISION_PENDING;
  }
  return ($node->is_current && $node->status == NODE_PUBLISHED) ? REVISION_CURRENT : REVISION_ARCHIVED;
}

/**
 * Return a string with details about the node that is about to be displayed.
 *
 * @param object $node
 *   The node that is about to be viewed
 *
 * @return string
 *   A translatable message containing details about the node
 */
function _revisioning_node_info_msg($node) {
  // Get username for the revision, not the creator of the node.
  $revision_author = user_load($node->revision_uid);
  $placeholder_data = array(
    '@content_type' => $node->type,
    '%title' => $node->title,
    '!author' => theme('username', array('account' => $revision_author)),
    '@date' => format_date($node->revision_timestamp, 'short'),
  );
  $revision_type = _revisioning_revision_is($node);
  switch ($revision_type) {

    case REVISION_PENDING:
      return t('Displaying <em>pending</em> revision of @content_type %title, last modified by !author on @date', $placeholder_data);

    case REVISION_CURRENT:
      return t('Displaying <em>current, published</em> revision of @content_type %title, last modified by !author on @date', $placeholder_data);

    case REVISION_ARCHIVED:
      return t('Displaying <em>archived</em> revision of @content_type %title, last modified by !author on @date', $placeholder_data);
  }
}

/**
 * Return TRUE only if the user account has ALL of the supplied permissions.
 *
 * @param array $permissions
 *   An array of permissions (strings)
 * @param object $account
 *   (optional) The user account object. Defaults to current user if omitted.
 *
 * @return bool
 *   Whether the user has access to all permissions
 */
function revisioning_user_access_all($permissions, $account = NULL) {
  foreach ($permissions as $permission) {
    if (!user_access($permission, $account)) {
      return FALSE;
    }
  }
  return TRUE;
}

/**
 * Return an array of names of content types that are subject to moderation.
 *
 * @return array
 *   array of strings, may be empty
 */
function revisioning_moderated_content_types($machine_name = TRUE) {
  $moderated_content_types = array();
  foreach (node_type_get_types() as $type) {
    $content_type = check_plain($type->type);
    if (revisioning_content_is_moderated($content_type)) {
      $moderated_content_types[] = ($machine_name ? $content_type : $type->name);
    }
  }
  return $moderated_content_types;
}

define('NO_FILTER', '-1');

/**
 * Get list of revisions accessible to the logged-in user via the operation.
 *
 * @param string $op
 *   Revision operation, eg 'view revision list' (as used by Pending Revisions
 *   block)
 * @param int $is_published
 *   (optional) 1 to return only published content
 *   0 to return only content that isn't published
 *  -1 (default) no filter, return content regardles of publication status
 * @param int $creator_uid
 *   (optional) Only return content created by the user with the supplied id.
 *   Defaults to -1, which means don't care who the creator is.
 * @param int $modifier_uid
 *   (optional) Only return content last modified by user with the supplied id.
 *   Defaults to -1, which means don't care who last modifed the node.
 * @param bool|int $is_moderated
 *   (optional) TRUE to return only content of types subject to moderation
 *   FALSE to return only content that isn't subject to moderation
 *   -1 (default) no filter, return content regardles of moderation flag
 * @param bool $is_pending
 *   (optional) bool indicating whether only nodes pending publication should be
 *   returned; a pending node is defined as a node that has a revision newer
 *   than the current OR a node with a single revision that is not published.
 * @param int $max
 *   (optional) Maximum number of nodes to be returned, defaults to 1000
 * @param string $order_by_override
 *   (optional) "ORDER BY ..." clause to be added, defaults to "timestamp DESC".
 *
 * @return array
 *   An array of revision objects each containing nid, content type, published
 *   flag, creator-id, title+vid+modifier-id+timestamp of the current revision,
 *   plus tags and taxonomy terms.
 *
 * @todo
 *   This code may need to be reviewed if used for purposes other than the
 *   Pending Revisions block.
 */
function revisioning_get_revisions($op, $is_published = -1, $creator_uid = -1, $modifier_uid = -1,
  $is_moderated = -1, $is_pending = FALSE, $max = 1000, $order_by_override = NULL) {
  $sql_select = 'SELECT n.nid, r.vid, n.uid AS creator_uid, r.uid, n.type, n.status, r.title, r.timestamp';
  // Join on current revision (vid) except when looking for pending revisions.
  $sql_from   = ' FROM {node} n INNER JOIN {node_revision} r ' . ($is_pending ? 'ON n.nid=r.nid' : 'ON n.vid=r.vid');
  $sql_where  = ($is_published < 0) ? '' : " WHERE n.status=$is_published";
  if ($creator_uid >= 0) {
    $sql_where  = empty($sql_where) ? " WHERE n.uid=$creator_uid" : $sql_where . " AND n.uid=$creator_uid";
  }
  if ($modifier_uid >= 0) {
    $sql_where  = empty($sql_where) ? " WHERE r.uid=$modifier_uid" : $sql_where . " AND r.uid=$modifier_uid";
  }
  if ($is_pending) {
    $sql_where  = empty($sql_where) ? ' WHERE' : $sql_where . ' AND';
    $sql_where .= ' (r.vid>n.vid OR (n.status=0 AND (SELECT COUNT(vid) FROM {node_revision} WHERE nid=n.nid)=1))';
  }
  $sql_order = " ORDER BY " . (empty($order_by_override) ? _revisioning_extract_order_clause_from_URI() : $order_by_override);
  $include_taxonomy_terms = module_exists('taxonomy') &&
    variable_get('revisioning_show_taxonomy_terms', TRUE) && (count(taxonomy_get_vocabularies()) > 0);
  if ($include_taxonomy_terms) {
    $conditions = array('type' => 'taxonomy_term_reference');
    $fields = field_read_fields($conditions);
    foreach ($fields as $field => $data) {
      $sql_select .= ", ttd_$field.name AS " . ($field == 'field_tags' ? 'tags' : 'term');
      $sql_from .= " LEFT JOIN {field_revision_$field} r_$field ON r.vid = r_$field.revision_id LEFT JOIN {taxonomy_term_data} ttd_$field ON r_$field.{$field}_tid=ttd_$field.tid";
    }
  }
  $sql = $sql_select . $sql_from . $sql_where . $sql_order;
  $node_query_result = db_query_range($sql, 0, $max);
  $revisions = array();
  foreach ($node_query_result as $revision) {
    // Need to set revision_moderation for revisioning_node_access() to work
    // properly.
    $revision->revision_moderation = revisioning_content_is_moderated($revision->type/*, $revision*/);

    $filter = ($is_moderated < 0) || ($is_moderated == $revision->revision_moderation);

    if ($filter && _revisioning_access_node_revision($op, $revision)) {
      if (empty($revisions[$revision->vid])) {
        $revisions[$revision->vid] = $revision;
      }
      // If a revision has more than one taxonomy term, these will be returned
      // by the query as seperate objects differing only in their terms.
      elseif ($include_taxonomy_terms) {
        $existing_revision = $revisions[$revision->vid];
        if (!empty($revision->term)) {
          if (strpos($existing_revision->term, $revision->term) === FALSE) {
            // Bit of a quick & dirty -- goes wrong if a term is substr of
            // another.
            $existing_revision->term .= ", $revision->term";
          }
        }
        if (!empty($revision->tags)) {
          if (strpos($existing_revision->tags, $revision->tags) === FALSE) {
            $existing_revision->tags .= ", $revision->tags";
          }
        }
      }
    }
  }
  return $revisions;
}

/**
 * Retrieve a list of all revisions belonging to the supplied node.
 *
 * Includes archive, current, and pending revisions.
 *
 * @param int $nid
 *   The node id to retrieve.
 * @param bool $include_taxonomy_terms
 *   Whether to also retrieve the taxonomy terms for each revision
 *
 * @return array
 *   An array of revision objects, each with published flag, log message, vid,
 *   title, timestamp and name of user that created the revision
 */
function _revisioning_get_all_revisions_for_node($nid, $include_taxonomy_terms = FALSE) {
  $node = node_load($nid);

  $sql_select = 'SELECT r.vid, r.status, r.title, r.log, r.uid, r.timestamp, u.name';
  $sql_from   = ' FROM {node_revision} r INNER JOIN {users} u ON r.uid=u.uid';
  $sql_where  = ' WHERE r.nid = :nid ORDER BY r.vid DESC';
  if ($include_taxonomy_terms) {
    $conditions = array('type' => 'taxonomy_term_reference');
    $fields = field_read_fields($conditions);
    foreach ($fields as $field => $data) {
      $field_instance = field_read_instance('node', $field, $node->type);
      if ($field_instance) {
        $sql_select .= ", ttd_$field.name AS " . ($field == 'field_tags' ? 'tags' : 'term');
        $sql_from .= " LEFT JOIN {field_revision_$field} r_$field ON r.vid = r_$field.revision_id LEFT JOIN {taxonomy_term_data} ttd_$field ON r_$field.{$field}_tid=ttd_$field.tid";
      }
    }
  }
  $sql = $sql_select . $sql_from . $sql_where;
  $result = db_query($sql, array(':nid' => $nid));
  $revisions = array();
  foreach ($result as $revision) {
    if (empty($revisions[$revision->vid])) {
      $revision->current = $node->vid;
      $revisions[$revision->vid] = $revision;
    }
    // If a revision has more than one tag or taxonomy term, these will be
    // returned by the query as seperate objects differing only in their terms.
    elseif ($include_taxonomy_terms) {
      $existing_revision = $revisions[$revision->vid];
      if (!empty($revision->term)) {
        if (strpos($existing_revision->term, $revision->term) === FALSE) {
          // Bit of a quick & dirty -- goes wrong if a term is substr of
          // another.
          $existing_revision->term .= ", $revision->term";
        }
      }
      if (!empty($revision->tags)) {
        if (strpos($existing_revision->tags, $revision->tags) === FALSE) {
          $existing_revision->tags .= ", $revision->tags";
        }
      }
    }
  }
  return $revisions;
}

/**
 * Extract order clause.
 *
 * Extract from the incoming URI (as in the table column header href)
 * the sort field and order for use in an SQL 'ORDER BY' clause.
 *
 * @return string
 *   db table field name and sort direction as a string
 */
function _revisioning_extract_order_clause_from_URI() {
  // We shouldn't have to do this, as tablesort.inc/tablesort_header(), called
  // from theme_table() is meant to look after it, but it's got a bug [#480382].
  // Note: this function is secure, as we're only allowing recognised values,
  // all unknown values, result in a descending sort by 'timestamp'.
  switch ($order_by = drupal_strtolower($_REQUEST['order'])) {
    case 'creator':
      $order_by = 'n.uid';
      break;

    case 'by':
      $order_by = 'r.uid';
      break;

    case 'published?':
      $order_by = 'status';
      break;

    case 'workflow state':
      $order_by = 'state';
      break;

    // List names that are fine the way they are here:
    case 'title':
    case 'type':
    case 'term':
      break;

    default:
      $order_by = 'timestamp';
      break;
  }
  $direction = (drupal_strtolower($_REQUEST['sort']) == 'asc') ? 'ASC' : 'DESC';
  return "$order_by $direction";
}
