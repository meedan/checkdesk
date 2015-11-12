<?php

/**
 * @file
 * API documentation for the Views Auto-Refresh module.
 */

/**
 * Alter the node.js channel name for the current view being rendered.
 *
 * @param String &$channel
 *   Reference to the channel name. The default channel name is passed in
 *   and can be altered.
 * @param Object $view
 *   The current view being rendered.
 */
function hook_views_autorefresh_nodejs_channel_alter(&$channel, $view) {
	$node = menu_get_object();
	if ($node && $node->type == 'story') {
		$channel .= '-' . $node->nid;
	}
}

/**
 * Alter the node.js message that gets sent to a view.
 *
 * @param Object message
 *   A node.js message consisting of:
 *   - channel: the channel name
 *   - callback: the JavaScript node.js callback
 *   - view_name: the name of the view being notified
 * @param Mixed $context
 *   Any additional context that the caller cares to send to allow the
 *   message altering hook to perform its logic.
 */
function hook_views_autorefresh_nodejs_message_alter(&$message, $context) {
	if ($message->view_name == 'story_activity-page_1' && is_object($context) && !empty($context->nid)) {
		$message->channel .= '-' . $context->nid;
	}
}
