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
      jQuery(".ctools-modal-content .modal-header").hide();
      jQuery(document).unbind("keydown", modalEventEscapeCloseHandler);
      setTimeout(function(){
        jQuery("#modalBackdrop").unbind("click");
        }, 300);
    });', 'inline');
  }
  $output .= render(node_view($node, 'checkdesk_collaborate'));
  return $output;
}

/**
 *
 *
 */
function _checkdesk_story_links($nid) {
  global $user;
  $output = '';
  if ($user->uid) {
    $items = array();
    // Add tooltip for add a report.
    if (isset($_SESSION['report_tooltip'])) {
      $tour = checkdesk_tour_preset_load('journalist');
      $tooltip = '<div class="popover tour-tour fade right in collaboration-report-tooltip">';
      $tooltip .= '  <div class="popover-arrow"></div>';
      $tooltip .= '  <div class="popover-close" data-role="end" onclick="jQuery(this).parent().hide();"><span>[X]</span></div>';
      $tooltip .= '  <h3><span class="popover-title">' . t($tour->steps[0]['title']) . '</span></h3>';
      $tooltip .= '  <div class="popover-content">' . t($tour->steps[0]['content']) . '</div>';
      $tooltip .= '</div>';
      $output .= $tooltip;
      unset($_SESSION['report_tooltip']);
    }
    $items[] = array(
      'data' => l(t('Add a report'), 'node/add/media', array('query' => array('ref_nid' => $nid, drupal_get_destination()))),
      'class' => array('submit-report'),
    );

    if (user_access('create post content')) {
      $items[] = array(
        'data' => l(t('Compose update'), 'node/add/post', array('query' => array('story' => $nid, drupal_get_destination()))),
        'class' => array('compose-update'),
      );
    }
    $output .= theme('item_list', array('items' => $items, 'title' => '', 'attributes' => array('class' => 'story-collaborate-links')));
  }
  return $output;
}

/**
 * List story collaborators 
 *  @param story_nid
 *
 */
function _checkdesk_story_get_collaborators($nid) {
  $output = '';
  //ToDO check node type
  $users = db_query('
    SELECT DISTINCT ha.uid, u.name, f.fid, f.uri 
    FROM {heartbeat_activity} ha 
    INNER JOIN {users} u ON ha.uid = u.uid 
    LEFT JOIN {file_managed} f ON u.picture = f.fid 
    WHERE nid_target = :nid AND message_id != :message_id
    ', array(':nid' => arg(1), ':message_id' => 'checkdesk_follow_story'))->fetchAll();
  if (count($users)) {
    $title = format_plural(count($users), '1 collaborator', '@count collaborators');
    $uitems = $pitems = array();
    foreach ($users as $user) {
      // split user name into first name and last
      $fullname = explode(' ', $user->name);
      $fname = array_shift($fullname);
      $uitems[] = l($fname, 'user/'. $user->uid);
      $avatar = _set_user_avatar_bg(user_load($user->uid));
      if ($avatar) {
        $pitems[] = $avatar;
      }
    }
    $output .= '<div class="story-collaborators-wrapper"><div class="story-collaborators"><span class="sc-users"><h3>' . $title . '</h3>' . implode(', ', $uitems) . '</span>';
    $output .= '<span class="sc-avatars">';
    foreach ($pitems as $pitem) {
      $output .= $pitem;
    }
    $output .= '</span></div></div>';
  }
  return $output;
}

/**
 * Menu function for `report-view-leave/%ctools_js`.
 */
function _checkdesk_modal_report_view_leave($js = FALSE) {
  $nid = arg(2);
  if (!$js) {
    drupal_goto('node/' . $nid);
    return;
  }

  ctools_include('modal');
  ctools_include('ajax');

  $form_state = array(
    'ajax' => TRUE,
    'title' => t('Are you sure you want to leave this page?'),
    'report_nid' => $nid,
  );

  $commands = ctools_modal_form_wrapper('_checkdesk_core_report_details', $form_state);

  if (!empty($form_state['executed'])) {
    // Add the responder javascript, required by ctools
    ctools_add_js('ajax-responder');
    // Array with ajax response.
    $commands = array();
    $commands[] = ctools_modal_command_dismiss();
    $commands[] = ctools_ajax_command_redirect('node/' . $nid);
  }
  print ajax_render($commands);
  exit;
}

/**
 * Form for confirm leave post.
 */
function _checkdesk_core_report_details($form, $form_state) {
  $form['report_nid'] = array(
    '#type' => 'hidden',
    '#value' => $form_state['report_nid'],
  );
  $form['description'] = array(
    '#markup' => t('You haven\'t finish your post yet. Do you want to leave without finishing?'),
  );
  $form['cancel'] = array(
    '#markup' => '<div><a id="close" class="btn" data-dismiss="modal" aria-hidden="true"
                onClick="jQuery(\'#close\').trigger(\'click\');" >' . t('Stay on this page') . '</a></div>',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Leave this page'),
  );

  return $form;
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
    $commands[] = ctools_ajax_command_redirect('story-collaboration/' . $form_state['story']);
    print ajax_render($commands);
    exit();
  }
  print ajax_render($output);
  exit;
}