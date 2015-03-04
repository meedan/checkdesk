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
    // Include the CTools tools that we need.
    ctools_include('ajax');
    ctools_include('modal');
    ctools_modal_add_js();
    // Custom modal settings arrays
    $modal_style_login = array(
      'modal-popup-login' => array(
        'modalSize' => array(
          'type' => 'fixed',
          'width' => 700,
          'height' => 450,
          'addWidth' => 0,
          'addHeight' => 0
        ),
        'modalOptions' => array(
          'opacity' => .5,
          'background-color' => '#000',
        ),
        'animation' => 'show',
        'animationSpeed' => 40,
        'modalTheme' => 'CheckDeskModal',
        'throbber' => theme('image', array('path' => ctools_image_path('ajax-loader.gif', 'checkdesk_core'), 'alt' => t('Loading'), 'title' => t('Loading'))),
      ),
    );
    drupal_add_js($modal_style_login, 'setting');
    $output .= '<div id="cd-collaboration-semi-frosted" style="display:none">' . ctools_modal_text_button(t('Modal Login (custom style)'),
      'story-collaboration-anonymous/nojs/login/'. arg(1), t('Login via modal'),
      'ctools-modal-modal-popup-login') .'</div>';
    drupal_add_js('
      jQuery(window).bind("load", function() {
        jQuery(".ctools-modal-modal-popup-login").click();
      });
      jQuery(function() {
        Drupal.behaviors.collanon = {
          attach: function (context, settings) {
            jQuery(".ctools-modal-content .modal-header").hide();
            jQuery(document).unbind("keydown", modalEventEscapeCloseHandler);
            jQuery("#modalBackdrop").unbind("click");
          }
        };
      });
      ', 'inline');
  }
  $node_view = node_view($node, 'checkdesk_collaborate');
  $output .= render($node_view);
  return $output;
}

/**
 * A modal login callback.
 */
function story_collaboration_anonymous_login($js = NULL) {
  $story_nid = arg(3);
  // Fall back if $js is not set.
  if (!$js) {
    return drupal_get_form('user_login');
  }

  ctools_include('modal');
  ctools_include('ajax');
  $form_state = array(
    'title' => t('Login'),
    'ajax' => TRUE,
    'story' => $story_nid,
  );

  $output = ctools_modal_form_wrapper('user_login', $form_state);
  if (!empty($form_state['executed'])) {
    ctools_add_js('ajax-responder');
    //$commands[] = ctools_modal_command_dismiss();
    $commands[] = ctools_ajax_command_redirect('node/' . $form_state['story'] . '/collaboration');
    print ajax_render($commands);
    exit();
  }
  print ajax_render($output);
  exit;
}
