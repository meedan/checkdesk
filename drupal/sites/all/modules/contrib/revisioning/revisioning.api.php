<?php

/**
 * @file
 * API documentation for Revisioning module.
 */


/**
 * @addtogroup hooks
 * @{
 */

/**
 * Called when various revision operations happen.
 * 
 * @param string $op
 *   one of:
 *   'pre publish'
 *   'post publish'
 *   'pre unpublish'
 *   'post unpublish'
 *   'post update'
 *   'pre delete'
 *   'post delete'
 *   'pre revert'
 *   'post revert'
 *   
 * @param object $node_revision
 */
function hook_revisionapi($op, $node_revision) {
  if ($op == 'pre publish' && module_exists('rules')) {
    rules_invoke_event('revisioning_pre_publish', $node);
  }; 
}

/**
 * Let other modules weigh in when deciding wheter a node may be accessed.
 * 
 * @param string $revision_op
 *   For instance 'publish revisions', 'delete revisions'.
 * @param object $node
 *
 * @return
 *   one of NODE_ACCESS_ALLOW, NODE_ACCESS_DENY, NODE_ACCESS_IGNORE
 */
function hook_revisioning_access_node_revision($revision_op, $node) {
}

/**
 * Called when a node is published.
 *
 * @param object $node
 */
function hook_revision_publish($node) {
}

/**
 * Called when a node is unpublished.
 *
 * @param object $node
 */
function hook_revision_unpublish($node) {
}

/**
 * Called after a node has been reverted.
 *
 * @param object $node
 */
function hook_revision_revert($node) {
}

/**
 * @} End of "addtogroup hooks".
 */