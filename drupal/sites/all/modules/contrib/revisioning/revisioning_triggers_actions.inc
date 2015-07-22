<?php

/**
 * @file
 * Triggers and actions supported by the Revisioning module.
 */

/**
 * Implements hook_triggr_info().
 *
 * Defines triggers available in this module.
 */
function revisioning_trigger_info() {
  $trigger_info = array(
    // First key is the group, which must be an existing module name.
    // This will be the name on the tab on the admin/structure/trigger page.
    // We could use 'node', which means that these triggers will apprear under
    // the node tab, /admin/structure/trigger/node
    // Second key has no functional meaning as the actual invocation of the
    // trigger is in code, typically via module_invoke_all('some_op', $node);
    // For clarity we have chosen the names below to equal 'some_op'.
    // Revisioning's implementations of hook_some_op are further down in this
    // file.
    'revisioning' => array(
      // Or 'node'.
      'revision_publish' => array(
        'label' => t('When publishing a pending revision'),
      ),
      'revision_unpublish' => array(
        'label' => t('When unpublishing the current revision'),
      ),
      'revision_revert' => array(
        'label' => t('When reverting to an archived revision'),
      ),
    ),
  );
  return $trigger_info;
}

/**
 * Implements hook_revision_publish().
 *
 * Called from revisioning_revisionapi().
 */
function revisioning_revision_publish($revision) {
  revisioning_action_revision_trigger($revision, 'revision_publish');
}

/**
 * Implements hook_revision_unpublish().
 *
 * Called from revisioning_revisionapi().
 */
function revisioning_revision_unpublish($revision) {
  revisioning_action_revision_trigger($revision, 'revision_unpublish');
}

/**
 * Implements hook_revision_revert().
 *
 * Called from revisioning_revisionapi().
 */
function revisioning_revision_revert($revision) {
  revisioning_action_revision_trigger($revision, 'revision_revert');
}

/**
 * Execute all actions associated with the supplied trigger.
 *
 * @param object $revision
 *   the node object as passed in from revisioning_revisionapi();
 *   if omitted this function will try to load the node object based on the URL
 *
 * @param string $hook
 *   trigger name, as passed in from revisioning_revision_hook() above, ie. one
 *   of 'revision_publish', 'revision_unpublish' or 'revision_revert'.
 */
function revisioning_action_revision_trigger($revision, $hook) {
  if (!module_exists('trigger')) {
    return;
  }
  $aids = trigger_get_assigned_actions($hook);
  if (empty($aids)) {
    // No actions defined for this trigger.
    return;
  }
  // Prepare a context to pass to all the actions to be invoked.
  // Include everything we can think of (important for token replacement).
  // See token_tokens()
  global $user;
  $context = array(
    'group' => 'revisioning',
    'hook' => $hook,
    'comment' => NULL,
    'file' => NULL,
    'menu-link' => NULL,
    'node' => $revision,
    'node_type' => node_type_get_type($revision),
    'revision' => $revision,
    'path' => NULL,
    // Use taxonomy_term_load() ?
    'term' => NULL,
    'user' => $user,
    'vocabulary' => NULL,
  );
  // Loop through all actions attached to this trigger and load up the
  // appropriate argument (eg node or user object) before invoking each action.
  foreach ($aids as $aid => $info) {
    $type = $info['type'];
    $objects[$type] = NULL;
    if (!isset($revision) && ($type == 'node' || $type == 'user')) {
      drupal_set_message(t('Trigger %hook: no argument supplied to pass to @type action %aid', array(
        '%hook' => $hook, '@type' => $type, '%aid' => $info['label'])), 'warning');
    }
    watchdog('revisioning', '%hook trigger is actioning %label',
      array('%hook' => $hook, '%label' => $info['label']));

    if (!isset($objects[$type])) {
      switch ($type) {
        case 'node':
          $objects[$type] = $revision;
          break;

        case 'user':
          $objects[$type] = user_load($revision->uid);
          break;

        case 'comment':
          // Not sure how.
          break;

        default:
      }
    }
    actions_do($aid, $objects[$type], $context);
  }
}

/* ---------------------------------- Actions ------------------------------ */

/**
 * Implements hook_action_info().
 *
 * Defines actions available in the Revisioning module.
 */
function revisioning_action_info() {
  $action_info = array(
    'revisioning_delete_archived_action' => array(
      'type' => 'node',
      'label' => t('Delete archived revisions'),
      'configurable' => FALSE,
      'triggers' => array('any'),
    ),
    'revisioning_publish_latest_revision_action' => array(
      'type' => 'node',
      'label' => t('Publish the most recent pending revision'),
      // For 'configurable' => TRUE, then we must define a form function with
      // the same name as the action function with '_form' appended.
      'configurable' => FALSE,
      // 'behavior' => array('changes_property'),
      // Unlike 'node_publish_action', this is NOT a 'node_presave' action:
      'triggers' => array('any'),
    ),
  );
  return $action_info;
}

/**
 * As declared in revisioning_action_info().
 *
 * Called from actions.inc/actions_do()
 *
 * @param object $entity
 *   in our case the node in question
 * @param array $context
 *   an array with $context['hook'] telling us which trigger
 *   instigated this call, eg 'node_update' as specified in the 'triggers'
 *   array, in hook_action_info()
 */
function revisioning_delete_archived_action(&$entity, $context = array()) {
  $node = $entity;
  if (empty($node->revision_moderation)) {
    // return;
  }
  $num_archived = revisioning_get_number_of_archived_revisions($node);
  if ($num_archived > 0) {
    $type = node_type_get_type($node->type);
    watchdog('revisioning',
      'Executing deleting archived revisions action for @type %title', array('@type' => $type->name, '%title' => $node->title),
      WATCHDOG_NOTICE, l(t('view'), "node/$node->nid"));
    if (revisioning_delete_archived_revisions($node)) {
      revisioning_set_status_message(format_plural($num_archived, '@type %title: one archived revision deleted.', '@type %title: @count archived revisions deleted.',
        array('@type' => $type->name, '%title' => $node->title)));
    }
  }
}

/**
 * As declared in revisioning_action_info().
 *
 * Called from actions.inc/actions_do().
 *
 * @param object $entity
 *   in our case the node in question
 * @param array $context
 *   an array with $context['hook'] telling us which trigger
 *   instigated this call, eg 'node_presave' as specified in the 'triggers'
 *   array, in hook_action_info()
 */
function revisioning_publish_latest_revision_action(&$entity, $context = array()) {
  $node = $entity;
  $type = node_type_get_type($node->type);
  watchdog('revisioning',
    'Executing publish_latest_revision action for @type %title', array('@type' => $type->name, '%title' => $node->title),
    WATCHDOG_NOTICE, l(t('view'), "node/$node->nid"));
  if (_revisioning_publish_latest_revision($node)) {
    revisioning_set_status_message(t('Revision has been published.'));
  }
  else {
    drupal_set_message(t('"%title" has no pending revision to be published.', array('%title' => $node->title)), 'warning');
  }
}
