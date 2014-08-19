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
    'checkdesk_user_menu_content' => array(
      'variables' => array('items' => array()),
    ),
    'checkdesk_dropdown_menu_item' => array(
      'variables' => array('title' => NULL, 'attributes' => array()),
    ),
    'checkdesk_dropdown_menu_content' => array(
      'variables' => array('id' => NULL, 'content' => array()),
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

  // set body class for language and language object to Drupal.settings
  if ($variables['language']) {
    $class = 'body-' . $variables['language']->language;
    $variables['classes_array'][] = $class;
    drupal_add_js(array('language' => $variables['language']), 'setting');
  }

  // 404 HTML template
  $status = drupal_get_http_header("status");  
  if($status == "404 Not Found") {
    if ($variables['language']->language == 'ar') {
      $variables['theme_hook_suggestions'][] = 'html__404__rtl';
    } else {
      $variables['theme_hook_suggestions'][] = 'html__404';
    }
  }
  // dsm($variables['theme_hook_suggestions']);

  // Add classes about widgets sidebar
   if (checkdesk_widgets_visibility()) {
    if (!empty($variables['page']['widgets'])) {
      $variables['classes_array'][] = 'widgets';
      // remove no-sidebars class from drupal
      $variables['classes_array'] = array_diff($variables['classes_array'], array('no-sidebars'));
    }
    else {
      $variables['classes_array'][] = 'no-widgets';
    }
  }

  // Add conditional stylesheets for IE8.
  if ($variables['language']->language == 'ar') {
    $filename = 'ie8-rtl.css';
  } else {
    $filename = 'ie8.css';
  }
  drupal_add_css(
    drupal_get_path('theme', 'checkdesk') . '/assets/css/' . $filename,
    array(
      'group' => CSS_THEME,
      'browsers' => array(
        'IE' => 'IE 8',
        '!IE' => FALSE,
      ),
      'weight' => 999,
      'every_page' => TRUE,
    )
  );
  drupal_add_js(
    drupal_get_path('theme', 'checkdesk') . '/assets/js/ie8.js',
    array(
      'group' => JS_THEME,
      // Not supported yet: http://drupal.org/node/865536
      'browsers' => array(
        'IE' => 'IE 8',
        '!IE' => FALSE,
      ),
      'weight' => 999,
      'every_page' => TRUE,
    )
  );
  
  $head_title = array();
  $title = drupal_get_title();
  if (!empty($title)) {
    $head_title[] = htmlspecialchars_decode($title);
  }
  $head_title[] = variable_get('site_name', 'Drupal');
  $variables['head_title'] = strip_tags(implode(' | ', $head_title));

}

/**
 * Override or insert variables into the region template.
 */
function checkdesk_preprocess_region(&$variables) {
  global $language;

  if ($variables['region'] == 'widgets') {
    // define custom header settings
    $variables['header_image'] = '';
    $image = theme_get_setting('header_image_path');
    
    if (!empty($image) && theme_get_setting('header_image_enabled')) {
      $header_image_data = array(
        'style_name' => 'partner_logo',
        'path' => $image,
      );
      $variables['header_image'] = l(theme('image_style', $header_image_data), '<front>', array('html' => TRUE, 'attributes' => array('class' => array('partner_logo'))));
    }

    $position = theme_get_setting('header_image_position');
    $variables['header_image_position'] = (empty($position) ? 'left' : $position);

    $bg = theme_get_setting('header_bg_path');
    $variables['header_bg'] = (empty($bg) ? '' : file_create_url($bg));

    $slogan = $variables['header_slogan'] = t('A Checkdesk live blog by <a href="@partner_url" target="_blank"><span class="checkdesk-slogan-partner">@partner</span></a>', array('@partner' => variable_get_value('checkdesk_site_owner', array('language' => $language)), '@partner_url' => variable_get_value('checkdesk_site_owner_url', array('language' => $language)) ));
    $variables['header_slogan'] = (empty($slogan) ? '' : $slogan);
    $variables['header_slogan_position'] = ((!empty($position) && in_array($position, array('center', 'right'))) ? 'left' : 'right'); 
  }

  if ($variables['region'] == 'footer') {
    // define custom header settings
    $variables['footer_image'] = '';
    $image = theme_get_setting('footer_image_path');
    
    if (!empty($image)) {
      $footer_image_data = array(
        'style_name' => 'footer_partner_logo',
        'path' => $image,
      );
      $variables['footer_image'] = theme('image_style', $footer_image_data);
      $variables['partner_url'] = variable_get_value('checkdesk_site_owner_url', array('language' => $language));
    }
  }

}


/**
 * Preprocess variables for blocks
 */
function checkdesk_preprocess_block(&$variables) {
  // remove subjects for all blocks
  $variables['elements']['#block']->subject = '';
  // Add Compose Update on update form
  if($variables['elements']['#block']->bid == 'checkdesk_core-post') {
    $variables['elements']['#block']->subject = t('Compose Update'); 
  }
}

/**
 * Preprocess variables for page.tpl.php
 *
 * @see page.tpl.php
 */
function checkdesk_preprocess_page(&$variables) {
  global $user, $language;
  
  // 404 PAGE template
  $status = drupal_get_http_header("status");  
  if($status == "404 Not Found") {
    if ($variables['language']->language == 'ar') {
      $variables['theme_hook_suggestions'][] = 'page__404__rtl';
    } else {
      $variables['theme_hook_suggestions'][] = 'page__404';
    }
  }

  // Page templates for each node type
  if (isset($variables['node'])) {
  // If the node type is "discussion" the template suggestion will be "page--discussion.tpl.php".
   $variables['theme_hook_suggestions'][] = 'page__'. str_replace('_', '--', $variables['node']->type);
  }

  // dsm($variables['language']->language);

  // Unescape HTML in title
  $variables['title'] = htmlspecialchars_decode(drupal_get_title());

  // Add a path to the theme so checkdesk_inject_bootstrap.js can load libraries
  $variables['basePathCheckdeskTheme'] = url(drupal_get_path('theme', 'checkdesk'), array('language' => (object) array('language' => FALSE)));
  drupal_add_js(array('basePathCheckdeskTheme' => $variables['basePathCheckdeskTheme']), 'setting');

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

      if (isset($item['below']) && $item['link']['title'] == t('...')) {
        $tree[$id]['link']['title'] = '&nbsp;';
        $tree[$id]['link']['link_title'] = '&nbsp;';
        $tree[$id]['link']['html'] = TRUE;
      }
    }

    $variables['main_menu'] = checkdesk_menu_navigation_links($tree);

    foreach ($variables['main_menu'] as $id => $item) {
      if ($item['link_path'] == 'node/add/media') {
        $variables['main_menu'][$id]['attributes']['id'] = 'menu-submit-report';
        if (arg(0) == 'node' && is_numeric(arg(1))) {
          $variables['main_menu'][$id]['query'] = array('ref_nid' => arg(1));
        }
      }
      else if ($item['link_path'] == 'node/add/discussion') {
        $variables['main_menu'][$id]['attributes']['id'] = 'discussion-form-menu-link';
      }
      else if ($item['link_path'] == 'node/add/post') {
        $variables['main_menu'][$id]['attributes']['id'] = 'update-story-menu-link';
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

  // Remove items that are not from this language or that does not have children, or are not enabled
  foreach ($tree as $id => $item) {
    if ((preg_match('/^<[^>]*>$/', $item['link']['link_path']) && $item['link']['expanded'] && count($item['below']) == 0) || $item['link']['hidden']) {
      unset($tree[$id]);
    }

    if ($item['link']['language'] != LANGUAGE_NONE && $item['link']['language'] != $language->language) unset($tree[$id]);
    foreach ($item['below'] as $subid => $subitem) {
      if ($subitem['link']['language'] != LANGUAGE_NONE && $subitem['link']['language'] != $language->language) unset($tree[$id]['below'][$subid]);
    }
  }

  // Add classes for modal
  foreach ($tree as $id => &$item) {
    // if (strpos($item['link']['link_path'], '/ajax/') !== FALSE) {
    //   $item['link']['class'] = array('use-ajax', 'ctools-modal-modal-popup-bookmarklet');
    // }
  }

  $variables['secondary_menu'] = checkdesk_menu_navigation_links($tree);

  // Change links
  foreach ($variables['secondary_menu'] as $id => $item) {

    if ($item['title'] === '<user>') {
      foreach ($item['below'] as $subid => $subitem) {
        if ($subitem['link_path'] == 'user/login') {
          if (user_is_logged_in()) unset($variables['secondary_menu'][$id]['below'][$subid]);
          else $variables['secondary_menu'][$id] = $subitem;
        }
      }
      if (user_is_logged_in()) {
        $variables['secondary_menu'][$id]['html'] = TRUE;
        $variables['secondary_menu'][$id]['title'] = theme('checkdesk_user_menu_item');
        $variables['secondary_menu'][$id]['attributes']['data-toggle'] = 'dropdown';
        $variables['secondary_menu'][$id]['attributes']['class'] = 'dropdown-toggle';
        $variables['secondary_menu'][$id]['suffix'] = theme('checkdesk_user_menu_content', array('items' => $variables['secondary_menu'][$id]['below']));

        unset($variables['secondary_menu'][$id]['below']);
      }
    }

    else if ($item['link_path'] == 'my-notifications') {
      if (user_is_logged_in()) {
        $count = checkdesk_notifications_number_of_new_items($user);
        $counter = '';
        if ($count > 0) $counter = '<span>' . $count . '</span>';
        $variables['secondary_menu'][$id]['attributes']['id'] = 'my-notifications-menu-link';
        $variables['secondary_menu'][$id]['html'] = TRUE;
        $variables['secondary_menu'][$id]['title'] = '<span class="icon-bell"></span><span class="notifications-count">' . $counter . '</span>';
      }
      else {
        unset($variables['secondary_menu'][$id]);
      }
    }

    else if ($item['link_path'] == 'checkdesk_take_tour') {
      $variables['secondary_menu'][$id]['attributes']['id'] = 'take-tour-menu-link';
      $variables['secondary_menu'][$id]['title'] = t('?');
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


  // information nav
  $variables['information_nav'] = FALSE;
  $menu = menu_load('menu-information');

  $tree = menu_tree_page_data($menu['menu_name']);
  
  // Remove items that are not from this language or that does not have children
  foreach ($tree as $id => $item) {
    if ($item['link']['hidden']) {
      unset($tree[$id]);
    }
    if ($item['link']['language'] != LANGUAGE_NONE && $item['link']['language'] != $language->language) unset($tree[$id]);
    foreach ($item['below'] as $subid => $subitem) {
      if ($subitem['link']['language'] != LANGUAGE_NONE && $subitem['link']['language'] != $language->language) unset($tree[$id]['below'][$subid]);
    }
  }
  

  // Add classes for modal
  foreach ($tree as $id => $item) {
    $classes = array();
    if (isset($item['link']['options']['attributes']['class'])) {
      $classes = $item['link']['options']['attributes']['class'];
    }
    if (in_array('checkdesk-use-modal', $classes)) {
      $alias = drupal_lookup_path('alias', $item['link']['href']);
      $path = $alias ? $alias : $item['link']['href'];
      $tree[$id]['link']['link_path'] = $path;
      $tree[$id]['link']['href'] = $path;
      $tree[$id]['link']['class'] = $classes;
    }
  }

  $variables['information_menu'] = checkdesk_menu_navigation_links($tree);

  // Build list
  $variables['information_nav'] = theme('checkdesk_links', array(
    'links' => $variables['information_menu'],
    'attributes' => array(
      'id' => 'information-menu',
      'class' => array('nav'),
    ),
    'heading' => NULL,
  ));

  // footer nav
  // $variables['footer_nav'] = FALSE;
  // $menu = menu_load('menu-footer');
  // $tree = menu_tree_page_data($menu['menu_name']);

  // Remove items that are not from this language or that does not have children
  // foreach ($tree as $id => $item) {
  //   if (preg_match('/^<[^>]*>$/', $item['link']['link_path']) && $item['link']['expanded'] && count($item['below']) == 0) {
  //     unset($tree[$id]);
  //   }
  //   if ($item['link']['language'] != LANGUAGE_NONE && $item['link']['language'] != $language->language) unset($tree[$id]);
  //   foreach ($item['below'] as $subid => $subitem) {
  //     if ($subitem['link']['language'] != LANGUAGE_NONE && $subitem['link']['language'] != $language->language) unset($tree[$id]['below'][$subid]);
  //   }
  // }

  // Add checkdesk logo class
  // foreach ($tree as $id => $item) {
  //   if($tree[$id]['link']['link_path'] == 'http://checkdesk.org') {
  //     $tree[$id]['link']['class'] = array('checkdesk');
  //   }
  // }
  
  // $partner_url = variable_get_value('checkdesk_site_owner_url', array('language' => $language));
  // Add partner logo class
  // foreach ($tree as $id => $item) {
    // if($tree[$id]['link']['link_path'] == $partner_url) {
      // $tree[$id]['link']['class'] = array('partner-logo');
    // }
  // }


  // $variables['footer_menu'] = checkdesk_menu_navigation_links($tree);

  // Build list
  // $variables['footer_nav'] = theme('checkdesk_links', array(
  //   'links' => $variables['footer_menu'],
  //   'attributes' => array(
  //     'id' => 'footer-menu',
  //     'class' => array('nav'),
  //   ),
  //   'heading' => NULL,
  // ));

  // ctools modal

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
        'width' => 700,
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
      'modalTheme' => 'CheckDeskModal',
      'throbber' => theme('image', array('path' => ctools_image_path('ajax-loader.gif', 'checkdesk_core'), 'alt' => t('Loading'), 'title' => t('Loading'))),
    ),
  );
  drupal_add_js($modal_style, 'setting');

  // define custom header settings
  $variables['header_image'] = '';
  $image = theme_get_setting('header_image_path');
  
  if (!empty($image) && theme_get_setting('header_image_enabled')) {
    $variables['header_image'] = l(theme('image', array('path' => file_create_url($image))), '<front>', array('html' => TRUE));
  }

  $position = theme_get_setting('header_image_position');
  $variables['header_image_position'] = (empty($position) ? 'left' : $position);

  $bg = theme_get_setting('header_bg_path');
  $variables['header_bg'] = (empty($bg) ? '' : file_create_url($bg));

  $variables['header_slogan'] = t('A <span class="checkdesk-slogan-logo">Checkdesk</span> Liveblog by <span class="checkdesk-slogan-partner">@partner</span>', array('@partner' => variable_get_value('checkdesk_site_owner', array('language' => $language))));
  $variables['header_slogan_position'] = ((!empty($position) && in_array($position, array('center', 'right'))) ? 'left' : 'right');

  // set page variable if widgets should be visible
  $variables['show_widgets'] = checkdesk_widgets_visibility();

  // set page variable if widgets should be visible
  $variables['show_footer'] = checkdesk_footer_visibility();

}


/**
 * Override or insert variables into the node template.
 */
function checkdesk_preprocess_node(&$variables) {

  if($variables['view_mode'] == 'checkdesk_collaborate' || $variables['view_mode'] == 'collaborate_status') {
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];
  }
  if ($variables['type'] == 'post' || $variables['type'] == 'discussion') {
    // get timezone information to display in timestamps e.g. Cairo, Egypt
    $site_timezone = checkdesk_get_timezone();
    $timezone = t('!city, !country', array('!city' => t($site_timezone['city']), '!country' => t($site_timezone['country'])));
    // FIXME: Ugly hack
    if ($site_timezone['city'] == 'Jerusalem') {
      $timezone = t('Jerusalem, Palestine');
    }

    // Add creation info
    $variables['creation_info'] = t('<a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <time datetime="!date">!datetime !timezone</time>', array(
      '@user' => url('user/'. $variables['uid']),
      '!user' => $variables['elements']['#node']->name,
      '!date' => format_date($variables['created'], 'custom', 'Y-m-d'),
      '!datetime' => format_date($variables['created'], 'custom', t('l M d, Y \a\t g:ia')),
      '!timezone' => $timezone,
    ));
    $variables['creation_info_short'] = t('<a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <time datetime="!date">!datetime</time>', array(
      '@user' => url('user/'. $variables['uid']),
      '!user' => $variables['elements']['#node']->name,
      '!date' => format_date($variables['created'], 'custom', 'Y-m-d'),
      '!datetime' => format_date($variables['created'], 'custom', t('M d Y')),
    ));
    $variables['created_by'] = t('<a href="@user">!user</a>', array(
      '@user' => url('user/'. $variables['uid']),
      '!user' => $variables['elements']['#node']->name,
    ));
    $variables['created_at'] = t('<time datetime="!date">!interval ago</time>', array(
      '!date' => format_date($variables['created'], 'custom', 'Y-m-d'),
      '!datetime' => format_date($variables['created'], 'custom', t('M d, Y \a\t g:ia')),
      '!interval' => format_interval((time() - $variables['created']), 1),
    ));
    $variables['updated_at'] = t('<time datetime="!date">!datetime !timezone</time>', array(
      '!date' => format_date($variables['changed'], 'custom', 'Y-m-d'),
      '!datetime' => format_date($variables['changed'], 'custom', t('M d, Y \a\t g:ia')),
      '!interval' => format_interval((time() - $variables['changed']), 1),
      '!timezone' => $timezone,
    ));
  }

  if($variables['type'] == 'post') {
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
  }

  if ($variables['type'] == 'discussion') {
    // Add tab (update & collaborate) to story
    $variables['story_tabs'] = _checkdesk_story_tabs($variables['nid']);
    if($variables['view_mode'] == 'checkdesk_collaborate') {
      // Add follow checkbox
      $story_follow = array();
      $story_follow['story_follow'] = array(
        '#type' => 'checkbox',
        '#title' => t('Follow story'),
        '#attributes'=> array('id' => array('checkdesk-follow-story')),
      );
      $variables['story_follow'] = drupal_render($story_follow);
      // Collaboration header for story.
      $variables['story_links'] = _checkdesk_story_links($variables['nid']);
      $variables['story_collaborators'] = _checkdesk_story_get_collaborators($variables['nid']);
      // Get heartbeat activity for particular story
      $variables['story_collaboration'] = views_embed_view('story_collaboration', 'page', $variables['nid']);
    }
    else {
      // get updates for a particular story
      $view = views_get_view('updates_for_stories');
      $view->set_arguments(array($variables['nid']));
      $view->get_total_rows = TRUE;
      $view_output = $view->preview('block');
      $total_rows = $view->total_rows;
      $view->destroy();
      if ($total_rows) {
        $variables['updates'] = $view_output;
      }
    }
    // Comments count
    $theme = NULL;
    // Livefyre comments count
    if (!variable_get('meedan_livefyre_disable', FALSE)) {
      $theme = 'livefyre_commentcount';
    }
    // Facebook comments count
    else if (!variable_get('meedan_facebook_comments_disable', FALSE)) {
      $theme = 'facebook_commentcount';
    }
    if ($theme) {
      $variables['story_commentcount'] = array(
        '#theme' => $theme,
        '#node' => node_load($variables['nid']),
      );
    }

  }

  if ($variables['type'] == 'post' && isset($variables['title'])) {
    if ($variables['title'] === _checkdesk_core_auto_title($variables['elements']['#node']) || $variables['title'] === t('Update')) {
      unset($variables['title']);
    }
  }

  $variables['icon'] = '';
  
  if ($variables['type'] == 'media') {
    global $language;
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
      // $variables['user_avatar'] = l(theme('image_style', array('path' => $user_picture->uri, 'alt' => t(check_plain($variables['elements']['#node']->name)), 'style_name' => 'navigation_avatar')), 'user/'. $variables['uid'], $options);
    }
    //Add node creation info(author name plus creation time
    if($variables['view_mode'] == 'checkdesk_collaborate') {
      $variables['media_creation_info'] = t('<a href="@url"><time class="date-time" datetime="!timestamp">!interval ago</time></a>', array(
        '@url' => url('node/'. $variables['nid']),
        '!timestamp' => format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP'),
        '!datetime' => format_date($variables['created'], 'custom', t('M d, Y \a\t g:ia e')),
        '!interval' => format_interval(time() - $variables['created'], 1),
      ));
      // Set favicon 
      if (isset($variables['embed']->favicon_link)) {
        $variables['favicon_link'] = l(
          theme('image', array( 'path' => $variables['embed']->favicon_link)),
          $variables['embed']->provider_url, array('html' => TRUE)
        );
      }
      // Set author name
      $variables['author_name'] = $variables['embed']->author_url ? l($variables['embed']->author_name, $variables['embed']->author_url) : $variables['embed']->author_name;
    }
    else {
      $variables['media_creation_info'] = t('Added by <a class="contributor" href="@user">!user</a> <span class="separator">&#9679;</span> <a href="@url"><time class="date-time" datetime="!timestamp">!interval ago</time></a>', array(
        '@user' => url('user/'. $variables['uid']),
        '!user' => $variables['elements']['#node']->name,
        '@url' => url('node/'. $variables['nid']),
        '!timestamp' => format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP'),
        '!datetime' => format_date($variables['created'], 'custom', t('M d, Y \a\t g:ia e')),
        '!interval' => format_interval(time() - $variables['created'], 1),
      ));
    }
    //Add activity report with status
    $term = isset($variables['elements']['#node']->field_rating[LANGUAGE_NONE][0]['taxonomy_term']) ? 
      $variables['elements']['#node']->field_rating[LANGUAGE_NONE][0]['taxonomy_term'] : 
      taxonomy_term_load($variables['elements']['#node']->field_rating[LANGUAGE_NONE][0]['tid']);
    $status_name = $term->name;
    if ($status_name !== 'Not Applicable') {
      $view = views_get_view('activity_report');
      $view->set_arguments(array($variables['nid']));
      $view->get_total_rows = TRUE;
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
          $icon = '<span class="icon-check-circle"></span> ';
        }
        elseif ($status_name == 'In Progress') {
          $status_class = 'in-progress';
          $icon = '<span class="icon-random"></span> ';
        }
        elseif ($status_name == 'Undetermined') {
          $status_class = 'undetermined';
          $icon = '<span class="icon-question-circle"></span> ';
        }
        elseif ($status_name == 'False') {
          $status_class = 'false';
          $icon = '<span class="icon-times-circle"></span> ';
        }
        // Display "{status} by {partner site name}" for all statuses
        // except when the report is in progress
        
        if($status_name != 'In Progress') {
          $status_by = t('by <span class="checkdesk-status-partner">@partner</span>', array('@partner' => variable_get_value('checkdesk_site_owner', array('language' => $language))));
        }

        $variables['status_class'] = $status_class;
        // display status with an icon and "x by partner"
        if(isset($status_name) && isset($icon) && isset($status_by)) {
          $variables['status'] = $icon . '<span class="status-name">' . t($status_name) . '</span>&nbsp;<span class="status-by">' . $status_by . '</span>';
        } else { // display status with an icon only
          $variables['status'] = $icon . '<span class="status-name">' . t($status_name) . '</span>';
        }
      }
      if (user_is_logged_in()) {
        $variables['media_activity_footer'] = '';
      }
      else {
        $icon = '<span class="icon-question-circle"></span> ';
        $link = l(t('About verification process'), 'modal/ajax/content/fact-checking-statement', array('html' => 'true', 'language' => $language, 'attributes' => array('class' => array('use-ajax', 'ctools-modal-modal-popup-large'))));
        $variables['media_activity_footer'] = '<span class="cta">' . t('To help verify this report, please <a href="@login_url">sign in</a>', array('@login_url' => url('user/login'))) . '</span><span class="helper">' . $icon . $link . '</span>';
      }
    }

    // HACK: Refs #1338, add a unique class to the ctools modal for a report
    if (arg(0) == 'report-view-modal') {
      $variables['modal_class_hack'] = '<script>jQuery("#modalContent, #modalBackdrop").addClass("modal-report");</script>';
    }

    if (isset($variables['content']['field_link'])) {
      $field_link_rendered = render($variables['content']['field_link']);

      // Never lazy-load inside the modal
      if (arg(0) != 'report-view-modal') {
        // Quick and easy, replace all src attributes with data-somethingelse
        // Drupal.behavior.lazyLoadSrc handles re-applying the src attribute when
        // the iframe tag enters the viewport.
        // See: http://stackoverflow.com/a/7154968/806988
        // use drupal_get_path to find imgs src instead on path_to_theme as imgs exist only on checkdesk theme
        $placeholder = base_path() . drupal_get_path('theme', 'checkdesk') . '/assets/imgs/icons/loader_white.gif';
        $field_link_rendered = preg_replace('/<(iframe|img)([^>]*)(src=["\'])/i', '<\1\2src="' . $placeholder . '" data-lazy-load-\3', $field_link_rendered);

        // Lazy load classes as well (for dynamic-loaded content, like tweets, for example)
        $field_link_rendered = preg_replace('/<(blockquote)([^>]*)class=/i', '<\1\2data-lazy-load-class=', $field_link_rendered);
      }

      $variables['field_link_lazy_load'] = $field_link_rendered;
    }
  }
}

function checkdesk_links__node($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];

  $class[] = 'content-actions';

  // get $alpha and $omega 
  $layout = checkdesk_core_direction_settings();

  $output = '';

  // Prepare for modal dialogs.
  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();
  ctools_add_js('checkdesk_core', 'checkdesk_core');

  if (arg(0) != 'embed' && count($links) > 0) {
    $output = '<ul' . drupal_attributes(array('class' => $class)) . '>';

    // if (isset($links['checkdesk-view-original'])) {
    //   $output .= '<li>' . l('<span class="icon-link"></span>', $links['checkdesk-view-original']['href'], array_merge($links['checkdesk-view-original'], array('html' => TRUE))) . '</li>';
    // }

    if (isset($links['checkdesk-share']) ||
        isset($links['checkdesk-share-facebook']) || 
        isset($links['checkdesk-share-twitter']) || 
        isset($links['checkdesk-share-google']) ||
        isset($links['checkdesk-share-embed'])
    ) {
      // Share on
      $output .= '<li class="share-on">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="icon-share">' . $links['checkdesk-share']['title'] . '</span></a>';
      
      $output .= '<ul class="dropdown-menu pull-'. $links['dropdown-direction'] .'">';

      if (isset($links['checkdesk-share-facebook'])) {
        $output .= '<li>' . l($links['checkdesk-share-facebook']['title'], $links['checkdesk-share-facebook']['href'], $links['checkdesk-share-facebook']) . '</li>';
      }
      if (isset($links['checkdesk-share-twitter'])) {
        $output .= '<li>' . l($links['checkdesk-share-twitter']['title'], $links['checkdesk-share-twitter']['href'], $links['checkdesk-share-twitter']) . '</li>';
      }
      if (isset($links['checkdesk-share-google'])) {
        $output .= '<li>' . l($links['checkdesk-share-google']['title'], $links['checkdesk-share-google']['href'], $links['checkdesk-share-google']) . '</li>';
      }
      if (isset($links['checkdesk-share-embed'])) {
        $output .= '<li class="divider"></li>';
        $output .= '<li>' . l($links['checkdesk-share-embed']['title'], $links['checkdesk-share-google']['href'], $links['checkdesk-share-embed']) . '</li>';
      }
      $output .= '</ul></li>'; 
    }

    if (isset($links['flag-spam']) || 
        isset($links['flag-graphic']) || 
        isset($links['flag-factcheck']) || 
        isset($links['flag-delete'])
    ) {
      // Flag as
      $output .= '<li class="flag-as">';
      $output .= l('<span class="icon-flag"></span>', $links['checkdesk-flag']['href'], $links['checkdesk-flag']);
      $output .= '<ul class="dropdown-menu pull-'. $layout['omega'] .'">';

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
      $output .= '<li class="add-to">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="icon-ellipsis-h"><span>' . t('Actions') . '</span></span></a>';
      $output .= '<ul class="dropdown-menu pull-'. $layout['omega'] .'">';
      if (isset($links['checkdesk-suggest'])) {
        $output .= '<li>' . ctools_modal_text_button($links['checkdesk-suggest']['title'], $links['checkdesk-suggest']['href'], $links['checkdesk-suggest']['title'],  'ctools-modal-modal-popup-medium') .'</li>';
      }
      if (isset($links['checkdesk-edit'])) {
        $output .= '<li>' . l($links['checkdesk-edit']['title'], $links['checkdesk-edit']['href'], $links['checkdesk-edit']) .'</li>';
      }
      if (isset($links['checkdesk-delete'])) {
        $output .= '<li>' . l($links['checkdesk-delete']['title'], $links['checkdesk-delete']['href'], $links['checkdesk-delete']) .'</li>';
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
 * Utitity function to determine whether to show widgets or not
 */
function checkdesk_widgets_visibility() {
  global $user;
  $current_node = menu_get_object();
  // what to check for
  $roles = array('administrator', 'journalist');
  $check_role = array_intersect($roles, array_values($user->roles));
  $check_role = empty($check_role) ? FALSE : TRUE;
  // for 404s
  $status = drupal_get_http_header("status");

  $pages = array('edit', 'delete');
  $check_page = array_intersect($pages, array_values(arg()));
  $check_page = empty($check_page) ? FALSE : TRUE;

  $user_pages = array('login', 'password', 'register');
  $check_user_page = array_intersect($user_pages, array_values(arg()));
  $check_user_page = empty($check_user_page) ? FALSE : TRUE;

  // node types to check for anonymous user
  $anon_node_types = array('media', 'discussion', 'post');
  // node types to check for logged in user
  $user_node_types = array('media', 'post');

  // for anonymous user
  if (isset($current_node->type) && !$check_role && $status != "404 Not Found") {
    foreach ($anon_node_types as $node_type) {
      // matches node types
      if ($node_type == $current_node->type) return TRUE;
    }
  // for logged in users with specific role
  } elseif (isset($current_node->type) && $check_role) {
    foreach ($user_node_types as $node_type) {
      // matches node types and does not include any pages
      if ($node_type == $current_node->type && arg(0) == 'node' && !$check_page && $status != "404 Not Found") {
        return TRUE; 
      }
      
    }
  // for user login, register and forgot pass page
  } elseif (arg(0) == 'user' && $check_user_page) {
      return TRUE;
  }

  // Always display on front page
  if (drupal_is_front_page()) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Utitity function to determine whether to show footer or not
 */
function checkdesk_footer_visibility() {
  global $user;
  $current_node = menu_get_object();
  // what to check for
  $pages = array('edit', 'delete');
  $check_page = array_intersect($pages, array_values(arg()));
  $check_page = empty($check_page) ? FALSE : TRUE;

  // node types to check
  $node_types = array('media', 'discussion', 'post');

  // for anonymous user
  if (isset($current_node->type)) {
    foreach ($node_types as $node_type) {
      // matches node types and does not include any pages
      if ($node_type == $current_node->type && arg(0) == 'node' && !$check_page) {
        return TRUE; 
      } 
    }
  } 

  // Always display on front page
  if (drupal_is_front_page()) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Force footer and sidebar to show
 */
function checkdesk_page_alter(&$page) {
  foreach (system_region_list($GLOBALS['theme'], REGIONS_ALL) as $region => $name) {
    // Footer
    if (in_array($region, array('footer'))) {
      $page['footer'] = array(
        '#region' => 'footer',
        '#weight' => '-10',
        '#theme_wrappers' => array('region'),
      );
    }
    // Sidebar
    if(!isset($page['widgets'])){
      if (in_array($region, array('widgets'))) {
        $page['widgets'] = array(
          '#region' => 'widgets',
          '#theme_wrappers' => array('region'),
        );
      }  
    }
  }
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

function checkdesk_field__field_rating(&$variables) {
  $output = '';
  foreach($variables['items'] as $key => $tag) {
      $output = $tag['#title']; 
  }
  return $output;
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
  $text = t('Facebook');
  return "<a $attributes href='$url' alt='$title'>$text</a>";
}

/**
 * Change Twitter login button from image to simple
 */
function checkdesk_twitter_signin_button() {
  $link['attributes']['class'][] = 'twitter-action-signin';
  $link['attributes']['title'] = t('Sign In with Twitter');
  return l(t('Twitter'), 'twitter/redirect', $link);
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
  if ($vars['display_id'] == 'block') {
    _checkdesk_ensure_reports_modal_js();
  }
}

/* Desk Updates */
function checkdesk_preprocess_views_view__desk_updates(&$vars) {
  if ($vars['display_id'] == 'block') {
    
  }
}

/* Reports page */
function checkdesk_preprocess_views_view__reports(&$vars) {
  // add masonry library
  drupal_add_js(drupal_get_path('theme', 'checkdesk') .'/assets/js/libs/jquery.masonry.min.js', 'file', array('group' => JS_THEME, 'every_page' => FALSE));
  _checkdesk_ensure_reports_modal_js();
}

function _checkdesk_ensure_reports_modal_js() {
  ctools_include('modal');
  ctools_modal_add_js();
  $modal_style = array(
    'modal-popup-report' => array(
      'modalSize' => array(
        'type' => 'fixed',
        'width' => 700,
        'height' => 540,
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
}

/**
 * Implements template_preprocess_views_view_fields().
 */
function checkdesk_preprocess_views_view_fields(&$vars) {
  global $user;

  if (in_array($vars['view']->name, array('reports', 'desk_reports'))) {
    $vars['name_i18n'] = isset($vars['fields']['field_rating']->content) ? t($vars['fields']['field_rating']->content) : NULL;

    if ((in_array('journalist', $user->roles) || in_array('administrator', $user->roles)) && checkdesk_core_report_published_on_update($vars['fields']['nid']->raw)) {
      $vars['report_published'] = t('Published on update');
    }
    else {
      $vars['report_published'] = FALSE;
    }
  }

  if ($vars['view']->name === 'liveblog') {
    $vars['updates'] = isset($vars['view']->result[$vars['view']->row_index]->updates) ? $vars['view']->result[$vars['view']->row_index]->updates : '';

    // Comments count
    $theme = NULL;
    // Livefyre comments count
    if (!variable_get('meedan_livefyre_disable', FALSE)) {
      $theme = 'livefyre_commentcount';
    }
    // Facebook comments count
    else if (!variable_get('meedan_facebook_comments_disable', FALSE)) {
      $theme = 'facebook_commentcount';
    }
    if ($theme) {
      $vars['story_commentcount'] = array(
        '#theme' => $theme,
        '#node' => node_load($vars['fields']['nid']->raw),
      );
    }
  }

  if ($vars['view']->name === 'updates_for_stories') {
    $vars['counter'] = intval($vars['view']->total_rows) - intval(strip_tags($vars['fields']['counter']->content)) + 1;
    if ($vars['counter'] === $vars['view']->total_rows) {
      $vars['update_id'] = $vars['fields']['nid']->raw;
      $vars['update'] = $vars['fields']['rendered_entity']->content;
    }
    else {
      $vars['update_id'] = $vars['fields']['nid']->raw;
      $vars['update'] = $vars['fields']['rendered_entity_1']->content;
    }
  }
}

/**
 * Process variables for user-profile.tpl.php.
 */
function checkdesk_preprocess_user_profile(&$variables) {
  $profile = $variables['elements']['#account'];

  $variables['member_for'] = t('Member for @time', array('@time' => $variables['user_profile']['summary']['member_for']['#markup']));

  // User reports
  $reports = views_get_view('reports');
  $reports->set_arguments(array($profile->uid));
  $variables['reports'] = $reports->preview('block_1');
  $reports->destroy();
}

/* 
 * Utility function to set timezone as City, Country
 */
function checkdesk_get_timezone() {
  // set timezone as Cairo, Egypt
  $site_timezone = array();
  $timezone = date_default_timezone();
  if($timezone) {
    $timezone_array = explode('/', $timezone);
    $site_timezone['city'] = str_replace('_', ' ', array_pop($timezone_array));  
  }
  $site_country_code = variable_get('site_default_country', '');
  if($site_country_code) {
    $countries = country_get_list();
    foreach ($countries as $cc => $country) {
      if($cc == $site_country_code) {
          $site_timezone['country'] = $country;
      }
    }
  }

  return $site_timezone;
}
