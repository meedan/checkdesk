<?php


include_once(drupal_get_path('theme', 'checkdesk') . '/includes/checkdesk.inc');
include_once(drupal_get_path('theme', 'checkdesk') . '/includes/theme.inc');
include_once(drupal_get_path('theme', 'checkdesk') . '/includes/menu.inc');

/**
 * hook_theme() 
 */
function checkdesk_theme() {
  return array(
    'checkdesk_links' => array(
      'variables' => array('links' => array(), 'attributes' => array(), 'heading' => NULL),
    ),
    'checkdesk_user_menu_item' => array(
      'variables' => array('attributes' => array(), 'type' => NULL),
    ),
    'checkdesk_heartbeat_content' => array(
      'variables' => array('message' => array(), 'node' => array()),
    ),
  );
}

/**
 * Preprocess variables for html.tpl.php
 *
 * @see html.tpl.php
 */
function checkdesk_preprocess_html(&$variables) {
  
  if(arg(0) == 'user' && arg(1) == '') {
   $class = 'page-user-login';
   $variables['classes_array'][] = $class;
  }

  // set body class for language
  if ($variables['language']) {
    $class = 'body-' . $variables['language']->language;
    $variables['classes_array'][] = $class;
  }
  
}

/**
 * Preprocess variables for page.tpl.php
 *
 * @see page.tpl.php
 */
function checkdesk_preprocess_page(&$variables) {
  global $user, $language;

  // Add a path to the theme so checkdesk_inject_bootrap.js can load libraries
  $vars['basePathCheckdeskTheme'] = url(drupal_get_path('theme', 'checkdesk'), array('language' => (object) array('language' => FALSE)));
  drupal_add_js(array('basePathCheckdeskTheme' => $vars['basePathCheckdeskTheme']), 'setting');

  // Primary nav
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Build links
    $tree = menu_tree_page_data(variable_get('menu_main_links_source', 'main-menu'));

    // Remove empty expanded menus
    foreach ($tree as $id => $item) {
      if (preg_match('/^<[^>]*>$/', $item['link']['link_path']) && $item['link']['expanded'] && count($item['below']) == 0) {
        unset($tree[$id]);
      }
    }
    
    $variables['main_menu'] = checkdesk_menu_navigation_links($tree);

    // Change "Submit Report" link
    foreach ($variables['main_menu'] as $id => $item) {
      if ($item['link_path'] == 'node/add/media') {
        $variables['main_menu'][$id]['href'] = meedan_bookmarklet_get_code();
        $variables['main_menu'][$id]['external'] = TRUE;
        $variables['main_menu'][$id]['absolute'] = TRUE;
        $variables['main_menu'][$id]['attributes'] = array('onclick' => 'jQuery(this).addClass("open")', 'id' => 'menu-submit-report');
      }
    }

    // Build list
    $variables['primary_nav'] = theme('checkdesk_links', array(
      'links' => $variables['main_menu'],
      'attributes' => array(
        'id' => 'main-menu',
        'class' => array('nav'),
      ),
      'heading' => NULL,
    ));
  }

  // Secondary nav
  $variables['secondary_nav'] = FALSE;
  $menu = menu_load('menu-common');
  $tree = menu_tree_page_data($menu['menu_name']);

  // Remove items that are not from this language or that does not have children
  foreach ($tree as $id => $item) {
    if (preg_match('/^<[^>]*>$/', $item['link']['link_path']) && $item['link']['expanded'] && count($item['below']) == 0) {
      unset($tree[$id]);
    }

    if ($item['link']['language'] != 'und' && $item['link']['language'] != $language->language) unset($tree[$id]);
    foreach ($item['below'] as $subid => $subitem) {
      if ($subitem['link']['language'] != 'und' && $subitem['link']['language'] != $language->language) unset($tree[$id]['below'][$subid]);
    }
  }

  // Add classes for modal
  foreach ($tree as $id => $item) {
    if ($item['link']['link_title'] == t('Information') || $item['link']['link_title'] == 'Information') {
      foreach ($item['below'] as $subid => $subitem) {
        $tree[$id]['below'][$subid]['link']['class'] = array('use-ajax', 'ctools-modal-modal-popup-bookmarklet');
      }
    }
  }

  $variables['secondary_menu'] = checkdesk_menu_navigation_links($tree);

  // Change links
  foreach ($variables['secondary_menu'] as $id => $item) {

    if ($item['title'] === '<user>') {
      if (user_is_logged_in()) {
        $variables['secondary_menu'][$id]['html'] = TRUE;
        $variables['secondary_menu'][$id]['title'] = theme('checkdesk_user_menu_item');
      }
      foreach ($item['below'] as $subid => $subitem) {
        if ($subitem['link_path'] == 'user/login') {
          if (user_is_logged_in()) unset($variables['secondary_menu'][$id]['below'][$subid]);
          else $variables['secondary_menu'][$id] = $subitem;
        }
      }
    }

    else if ($item['link_path'] == 'my-notifications') {
      if (user_is_logged_in()) {
        $count = checkdesk_notifications_number_of_new_items($user);
        $counter = '';
        if ($count > 0) $counter = '<span>' . $count . '</span>';
        $variables['secondary_menu'][$id]['attributes']['id'] = 'my-notifications-menu-link';
        $variables['secondary_menu'][$id]['html'] = TRUE;
        $variables['secondary_menu'][$id]['title'] = '<span class="notifications-count">' . $counter . '</span> <span class="notifications-label">' . $item['title'] . '</span>';
      }
      else {
        unset($variables['secondary_menu'][$id]);
      }
    }

  }

  // Build list
  $variables['secondary_nav'] = theme('checkdesk_links', array(
    'links' => $variables['secondary_menu'],
    'attributes' => array(
      'id' => 'user-menu',
      'class' => array('nav'),
    ),
    'heading' => NULL,
  ));

  ctools_include('modal');
  ctools_modal_add_js();

  // Custom modal settings arrays
  $modal_style = array(
    'modal-popup-small' => array(
      'modalSize' => array(
        'type' => 'fixed',
        'width' => 420,
        'height' => 300,
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
    'modal-popup-medium' => array(
      'modalSize' => array(
        'type' => 'fixed',
        'width' => 520,
        'height' => 350,
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
    'modal-popup-large' => array(
      'modalSize' => array(
        'type' => 'fixed',
        'width' => 420,
        'height' => 380,
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
  drupal_add_js($modal_style, 'setting');
}

/**
 * Override or insert variables into the node template.
 */
function checkdesk_preprocess_node(&$variables) {

  // set $alpha and $omega for language directions
  global $language;
  if ($language->direction == LANGUAGE_RTL) {
    $variables['alpha'] = 'right';
    $variables['omega'] = 'left';
  } else {
    $variables['alpha'] = 'left';
    $variables['omega'] = 'right';
  }

  if ($variables['type'] == 'post') {
    //Add author info to variables
    $user = user_load($variables['elements']['#node']->uid);
    $user_picture = $user->picture;
    if (!empty($user_picture)) {
      $options = array(
        'html' => TRUE,
        'attributes' => array(
          'class' => 'gravatar'
        )    
      );
      $variables['user_avatar'] = l(theme('image_style', array('path' => $user_picture->uri, 'alt' => t(check_plain($variables['elements']['#node']->name)), 'style_name' => 'navigation_avatar')), 'user/'. $variables['uid'], $options);
    }
    // Add update creation info
    $variables['update_creation_info'] = t('Update by <a href="@user">!user</a> <time datetime="!date">!datetime</time>', array(
      '@user' => url('user/'. $variables['uid']),
      '!user' => $variables['elements']['#node']->name,
      '!date' => format_date($variables['created'], 'custom', 'Y-m-d'),
      '!datetime' => format_date($variables['created'], 'custom', t('M d, Y \a\t g:ia')),
    ));
  }

  $variables['icon'] = '';
  
  if ($variables['type'] == 'media') {
    //Add author info to variables
    $user = user_load($variables['elements']['#node']->uid);
    $user_picture = $user->picture;
    if (!empty($user_picture)) {
      $options = array(
        'html' => TRUE,
        'attributes' => array(
          'class' => 'gravatar'
        )    
      );
      $variables['user_avatar'] = l(theme('image_style', array('path' => $user_picture->uri, 'alt' => t(check_plain($variables['elements']['#node']->name)), 'style_name' => 'navigation_avatar')), 'user/'. $variables['uid'], $options);
    }
    //Add node creation info(author name plus creation time)
    $variables['media_creation_info'] = t('<a href="@user">!user</a> added this <time class="time-ago" datetime="!timestamp">!interval ago</time>', array(
      '@user' => url('user/'. $variables['uid']),
      '!user' => $variables['elements']['#node']->name,
      '!timestamp' => format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP'),
      '!interval' => format_interval(time()-$variables['created']),
    ));
    //Add activity report with status
    $term = isset($variables['elements']['#node']->field_rating[LANGUAGE_NONE][0]['taxonomy_term']) ? 
      $variables['elements']['#node']->field_rating[LANGUAGE_NONE][0]['taxonomy_term'] : 
      taxonomy_term_load($variables['elements']['#node']->field_rating[LANGUAGE_NONE][0]['tid']);
    $status_name = $term->name;
    if ($status_name !== 'Not Applicable') {
      $view = views_get_view('activity_report');
      $view->set_arguments(array($variables['nid']));
      $view_output = $view->preview('block');
      $total_rows = $view->total_rows;
      $view->destroy();
      if ($total_rows) {
        $variables['media_activity_report_count'] = $total_rows;
        $variables['media_activity_report'] = $view_output;
        $status_class = '';
        $icon = '';
        if ($status_name == 'Verified') {
          $status_class = 'verified';
          $icon = '<span class="icon-ok-sign"></span> ';
        }
        elseif ($status_name == 'Undetermined') {
          $status_class = 'undetermined';
          $icon = '<span class="icon-question-sign"></span> ';
        }
        elseif ($status_name == 'False') {
          $status_class = 'false';
          $icon = '<span class="icon-remove-sign"></span> ';
        }
        $variables['status_class'] = $status_class;
        $variables['status_icon'] = $icon . '<span class="status-name">' . t($status_name) . '</span>';
      }
    }
  }
}

function checkdesk_links__node($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];

  $class[] = 'content-actions';
  $output = '';

  // Prepare for modal dialogs.
  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();
  ctools_add_js('checkdesk_core', 'checkdesk_core');

  if (count($links) > 0) {
    $output = '<ul' . drupal_attributes(array('class' => $class)) . '>';
   
    if (isset($links['checkdesk-share-facebook']) || 
        isset($links['checkdesk-share-twitter']) || 
        isset($links['checkdesk-share-google'])
    ) {
      // Share on
      $output .= '<li class="share-on dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="icon-share"></span>' . t('Share') . '</a>';
      $output .= '<ul class="dropdown-menu">';
      if (isset($links['checkdesk-share-facebook'])) {
        $output .= '<li>' . l($links['checkdesk-share-facebook']['title'], $links['checkdesk-share-facebook']['href'], $links['checkdesk-share-facebook']) . '</li>';
      }
      if (isset($links['checkdesk-share-twitter'])) {
        $output .= '<li>' . l($links['checkdesk-share-twitter']['title'], $links['checkdesk-share-twitter']['href'], $links['checkdesk-share-twitter']) . '</li>';
      }
      if (isset($links['checkdesk-share-google'])) {
        $output .= '<li>' . l($links['checkdesk-share-google']['title'], $links['checkdesk-share-google']['href'], $links['checkdesk-share-google']) . '</li>';
      }
      $output .= '</ul></li>'; 
    }

    if (isset($links['flag-spam']) || 
        isset($links['flag-graphic']) || 
        isset($links['flag-factcheck']) || 
        isset($links['flag-delete'])
    ) {
      // Flag as
      $output .= '<li class="flag-as dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="icon-flag"></span>' . t('Flag') . '</a>';
      $output .= '<ul class="dropdown-menu">';

      if (isset($links['flag-spam'])) {
        $output .= '<li>' . $links['flag-spam']['title'] . '</li>';
      }
      if (isset($links['flag-graphic'])) {
        // $output .= '<li>' . ctools_modal_text_button('Custom title', 'node/nojs/flag/confirm/flag/graphic/74', 'Another title',  'ctools-modal-checkdesk-style') .'</li>';
        $output .= '<li>' . $links['flag-graphic']['title'] . '</li>';
      }
      if (isset($links['flag-factcheck'])) {
        $output .= '<li>' . $links['flag-factcheck']['title'] . '</li>';
      }

      if (isset($links['flag-delete'])) {
        $output .= '<li class="divider"></li>';
        $output .= '<li>' . $links['flag-delete']['title'] . '</li>';
      }
      $output .= '</ul></li>'; 
    }
     
    if (isset($links['checkdesk-suggest']) || 
        isset($links['checkdesk-edit']) || 
        isset($links['checkdesk-delete']) ||
        isset($links['flag-factcheck_journalist']) ||
        isset($links['flag-graphic_journalist'])
    ) {
      // Add to
      $output .= '<li class="add-to dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="icon-edit"></span> ';
      $output .=  t('...');
      $output .= '</a>';
      $output .= '<ul class="dropdown-menu">';
      if (isset($links['checkdesk-suggest'])) {
        $output .= '<li>' . ctools_modal_text_button($links['checkdesk-suggest']['title'], $links['checkdesk-suggest']['href'], $links['checkdesk-suggest']['title'],  'ctools-modal-modal-popup-medium') .'</li>';
      }
      if (isset($links['checkdesk-edit'])) {
        $output .= '<li>' . l($links['checkdesk-edit']['title'], $links['checkdesk-edit']['href'], $links['checkdesk-edit']) .'</li>';
      }
      if (isset($links['checkdesk-delete'])) {
        $output .= '<li>' . l($links['checkdesk-delete']['title'], $links['checkdesk-delete']['href'], $links['checkdesk-edit']) .'</li>';
      }
      if (isset($links['flag-factcheck_journalist'])) {
        $output .= '<li class="divider"></li>';
        $output .= '<li>' . $links['flag-factcheck_journalist']['title'] .'</li>';
      }
      if (isset($links['flag-graphic_journalist'])) {
        $output .= '<li>' . $links['flag-graphic_journalist']['title'] .'</li>';
      }
      $output .= '</ul></li>';
    }

    if (isset($links['checkdesk-edit-flat']) || 
        isset($links['checkdesk-delete-flat'])
    ) {
      // Edit or delete, but not as a dropdown menu
      if (isset($links['checkdesk-edit-flat'])) {
        $output .= '<li>' . l($links['checkdesk-edit-flat']['title'], $links['checkdesk-edit-flat']['href'], $links['checkdesk-edit-flat']) .'</li>';
      }
      if (isset($links['checkdesk-delete-flat'])) {
        $output .= '<li>' . l($links['checkdesk-delete-flat']['title'], $links['checkdesk-delete-flat']['href'], $links['checkdesk-delete-flat']) .'</li>';
      }
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * Adjust story blogger markup
 */
function checkdesk_checkdesk_core_story_blogger(&$variables) {
  $output = '';

  $output .= '<div class="story-blogger '. $variables['classes'] .'">';
  $output .= '<div class="avatar">' . $variables['blogger_picture'] . $variables['blogger_name'] . '</div>';
  $output .= '<div class="blogger-status '. $variables['blogger_status_class'] .'"><span class="blogger-status-indicator"></span><span class="blogger-status-text">' . $variables['blogger_status_text'] . '</span></div>';
  $output .= '</div>';

  return $output;
}

/**
 * Adjust story status (blog by and it is currently)
 */
function checkdesk_checkdesk_core_story_status(&$variables) {
  $output = '';

  $output .= '<div class="story-by">' . $variables['story_status'] . '</div>';
  $output .= '<div class="story-context">' . $variables['story_context'] . '</div>';

  return $output;
}

/**
 * Inform if story has drafts
 */
function checkdesk_checkdesk_core_story_drafts(&$variables) {
  $output = '';

  if (isset($variables['story_drafts']) && !empty($variables['story_drafts'])) $output .= '<div class="story-drafts">' . $variables['story_drafts'] . '</div>';

  return $output;
}

/**
 * Adjust report source markup
 */
function checkdesk_checkdesk_core_report_source(&$variables) {
  $output = '';

  $output .= '<span class="source-url">' . $variables['source_url_short'] . '</span> ';
  $output .= $variables['source_author'];

  return $output;
}


/**
 * Adjust node comments form
 */
function checkdesk_form_comment_form_alter(&$form, &$form_state) {
  $form['author']['homepage'] = NULL;
  $form['author']['mail'] = NULL;
  $form['actions']['submit']['#attributes']['class'] = array('btn');
  $form['actions']['submit']['#value'] = t('Add footnote');
}

function checkdesk_field__field_rating(&$variables) {
  $output = '';
  foreach($variables['items'] as $key => $tag) {
      $output = $tag['#title']; 
  }
  return $output;
}


/**
 * Adjust user login form
 */
function checkdesk_form_alter(&$form, &$form_state) {
  if($form['form_id']['#id'] == 'edit-user-login') {
    unset($form['social_media_signin']['#title']);
    $form['social_media_signin']['#suffix'] = '<div class="or"><span>' . t('or') . '</span></div>';
    unset($form['name']['#description']);
    unset($form['name']['#title']);
    unset($form['pass']['#description']);
    unset($form['pass']['#title']);
    $form['name']['#attributes']['placeholder'] = t('Username');
    $form['pass']['#attributes']['placeholder'] = t('Password');
    // Add forgot link and a wrapper around forgot pass and remember me
    $forgot_pass_link = l(t('Forgot your password?'), 'user/password');
    $form['pass']['#suffix'] = '<div class="user-links"><div class="user-forgot-pass-link">' . $forgot_pass_link . '</div>';
    $form['remember_me']['#suffix'] = '</div>';
    // add a wrapper around new account link
    unset($form['links']);
    $link['attributes']['class'][] = 'register';
    $link['attributes']['title'] = t('Sign Up');
    $new_account_link = l(t('Sign Up'), 'user/register', $link);
    $form['actions']['submit']['#suffix'] = '<div class="user-new-account-link"><span>' . t('Don\'t have an account? ') . '</span>
    ' . $new_account_link . '</div>';    
  }
}

function checkdesk_fboauth_action__connect(&$variables) {
  $action = $variables['action'];
  $link = $variables['properties'];
  $url = url($link['href'], array('query' => $link['query']));
  $link['attributes']['class'] = isset($link['attributes']['class']) ? $link['attributes']['class'] : 'facebook-action-connect';
  // Button i18n.
  $language = $GLOBALS['language']->language;
  $link['attributes']['class'] .= " fb-button-$language";
  $attributes = isset($link['attributes']) ? drupal_attributes($link['attributes']) : '';
  $title = isset($link['title']) ? check_plain($link['title']) : '';
  $text = '<span class="icon-facebook"></span> ' . t('Facebook');
  return "<a $attributes href='$url' alt='$title'>$text</a>";
}

/**
 * Change Twitter login button from image to simple
 */
function checkdesk_twitter_signin_button() {
  $url = 'twitter/redirect';
  $title = t('Sign In with Twitter');
  $attributes = isset($link['attributes']) ? drupal_attributes($link['attributes']) : '';
  $text = '<span class="icon-twitter"></span> ' . t('Twitter');
  return "<a $attributes href='$url' alt='$title'>$text</a>";
}



/**
 * Adjust compose update form
 */
function checkdesk_form_post_node_form_alter(&$form, &$form_state) {
  $form['title']['#title'] = NULL;
  $form['title']['#attributes']['placeholder'] = t('Add headline');

  $form['body']['und'][0]['#title'] = NULL;
  $form['body']['und'][0]['#attributes']['placeholder'] = t('Drag and drop reports here to compose your update');
}

/**
 * Theme views
 */
function checkdesk_preprocess_views_view(&$vars) {
  global $base_path;
  $vars['base_path'] = $base_path;
  // set template functions for individual views
  if (isset($vars['view']->name)) {
    $function = 'checkdesk_preprocess_views_view__'.$vars['view']->name; 
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/* Desk Reports */
function checkdesk_preprocess_views_view__desk_reports(&$vars) {
  if($vars['display_id'] == 'block') {

    ctools_include('modal');
    ctools_modal_add_js();
    $modal_style = array(
     'modal-popup-report' => array(
          'modalSize' => array(
            'type' => 'fixed',
            'width' => 450,
            'height' => 400,
            'addWidth' => 0,
            'addHeight' => 0
          ),
          'modalOptions' => array(
            'opacity' => .5,
            'background-color' => '#000',
          ),
          'animation' => 'show',
          'animationSpeed' => 40,
          'modalTheme' => 'CToolsModalDialog',
          'throbber' => theme('image', array('path' => ctools_image_path('ajax-loader.gif', 'checkdesk_core'), 'alt' => t('Loading...'), 'title' => t('Loading'))),
        ),
      );
      drupal_add_js($modal_style, 'setting');

    // foreach($vars['view']->result as $delta => $item) {
            
    // }
  }
}

