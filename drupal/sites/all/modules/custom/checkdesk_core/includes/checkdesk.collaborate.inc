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
    global $language;
    $url = url('node/' . $node->nid, array('absolute' => TRUE, 'language' => $language,));
    drupal_add_js('
      jQuery(window).bind("load", function() {
        jQuery("a.ctools_checkdesk_sign_in_up").click();
      });

      jQuery(function() {
        Drupal.behaviors.collanon = {
          attach: function (context, settings) {
            jQuery( "#modalContent .popups-close" ).click(function() {
              window.location =  "'. $url .'";
            });
            jQuery(document).keyup(function (e) {
              if ( e.keyCode === 27 ) {
                window.location =  "'. $url .'";
              }
            });
          }
        };
      });

      ', 'inline');
  }
  else {
    // Jump to collaboration tab.
    drupal_add_js('  
      jQuery(function() {
       jQuery("html, body").animate({ scrollTop: jQuery(".story-tabs-wrapper").offset().top + jQuery(".story-body").height() }, 1000);
      });
      ', 'inline');
  }
  
  $node_view = node_view($node, 'checkdesk_collaborate');
  $output .= render($node_view);
  return $output;
}
