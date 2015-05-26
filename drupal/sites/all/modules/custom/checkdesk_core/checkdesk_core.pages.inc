<?php


/**
 * Render collaborate page.
 *
 * @parm object $node
 *    story node object
 *
 * @return
 *   Return a story collaboration page.
 */
function _checkdesk_story_collaboration($node) {
  global $user;
  $output = '';
  if ($user->uid == 0) {
    drupal_add_js('
      jQuery(window).bind("load", function() {
        jQuery("a.ctools_checkdesk_sign_in_up").click();
      });
      ', 'inline');
  }
  $node_view = node_view($node, 'checkdesk_collaborate');
  $output .= render($node_view);
  return $output;
}
