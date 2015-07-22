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

function checkdesk_preprocess_field(&$variables, $hook) {
  $element = $variables['element'];
  if ($element['#field_name'] == 'field_link') {
    $embed = $element['#object']->embed;
    $node = $element['#object'];
    $variables['embed'] = $embed;
    $variables['node'] = $node;
    $variables['theme_hook_suggestions'][] = $element['#formatter'] . '__' . strtolower(str_replace(' ', '_', $embed->provider_name));
    // set provider class name
    $provider = strtolower(str_replace(' ', '_', $embed->provider_name));
    $variables['provider_class_name'] = str_replace('.', '_', $provider) . '-wrapper';
    // set embed type as class name
    $item_type = strtolower($node->embed->type);
    $variables['media_type_class'] = 'media--' . str_replace(' ', '-', $item_type);

    // Set author name or provider name
    if (isset($embed->author_url) && isset($embed->author_name)) {
      $variables['author_name'] = $embed->author_url ? l($embed->author_name, $embed->author_url) : $embed->author_name;
    }
    elseif (isset($embed->original_url) && isset($embed->provider_name)) {
      $variables['provider_name'] = $embed->original_url ? l($embed->provider_name, $embed->original_url) : $embed->provider_name;
    }
    // Media description
    if (isset($node->body[LANGUAGE_NONE][0]['value'])) {
      $variables['media_description'] = check_markup($node->body[LANGUAGE_NONE][0]['value'], 'filtered_html');
    }
    // Set favicon
    if (isset($embed->favicon_link)) {
      $variables['favicon_link'] = l(
              theme('image', array('path' => $embed->favicon_link)), $embed->original_url, array('html' => TRUE, 'attributes' => array('class' => array('favicon')))
      );
    }
    // timestamp
    // TODO: make this source media timestamp
    global $language;
    // Set custom format based on language.
    if(date('Y') == format_date($node->created, 'custom', 'Y')) {
      $custom_format = ($language->language == 'en') ? t('D, F j\t\h \a\t g:i A') : t('D, j F g:i A');
    } else {
      $custom_format = ($language->language == 'en') ? t('D, F j\t\h Y \a\t g:i A') : t('D, j F Y g:i A');
    }

    $variables['media_creation_info'] =
      t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a> added by <a class="contributor" href="@user">!user</a>', array(
        '@url' => $node->embed->original_url,
        '!timestamp' => format_date($node->created, 'custom', 'Y-m-d\TH:i:sP'),
        '!daydatetime' => format_date($node->created, 'custom', $custom_format),
        '@user' => url('user/' . $node->uid),
        '!user' => $node->name,
    ));

    // Load report status
    if (isset($node->field_rating)) {
      if ($node->field_rating['und'][0]['tid'] != 4) {
        $variables['report_status'] = _checkdesk_report_status($node);
      }
    }
    // Inline thumbnail
    if ($element['#formatter'] == 'meedan_inline_thumbnail') {
      $variables['inline_thumbnail'] = _meedan_inline_thumbnail_bg($node, array('inline-img-thumb'));
    }
    // Large image in case of Flickr or imgur or instagram
    if ($element['#formatter'] == 'meedan_inline_full_mode' || $element['#formatter'] == 'meedan_full_mode') {
      if ($embed->type == 'photo' && isset($embed->url)) {
        $variables['full_image'] = l(theme_image(array('path' => $embed->url, 'attributes' => array('class' => array('img')))), 'node/' . $node->nid, array('html' => TRUE));
      }
      elseif (isset($embed->thumbnail_url)) {
        $variables['full_image'] = l(theme_image(array('path' => $embed->thumbnail_url, 'attributes' => array('class' => array('img')))), 'node/' . $node->nid, array('html' => TRUE));
      }
    }
  }
}

/**
 * Preprocess variables for html.tpl.php
 *
 * @see html.tpl.php
 */
function checkdesk_preprocess_html(&$variables) {
  if (arg(0) == 'user' && arg(1) == '') {
    $class = 'page-user-login';
    $variables['classes_array'][] = $class;
  }

  // set body class for language and language object to Drupal.settings
  if ($variables['language']) {
    $language_class = 'body-' . $variables['language']->language;
    $variables['classes_array'][] = $language_class;
    drupal_add_js(array('language' => $variables['language']), 'setting');
  }

  // 404 HTML template
  $status = drupal_get_http_header("status");
  if ($status == "404 Not Found") {
    if ($variables['language']->language == 'ar') {
      $variables['theme_hook_suggestions'][] = 'html__404__rtl';
    } else {
      $variables['theme_hook_suggestions'][] = 'html__404';
    }
  }

  // Add classes about widgets sidebar
  if (checkdesk_widgets_visibility()) {
    if (!empty($variables['page']['widgets'])) {
      $variables['classes_array'][] = 'widgets';
      // remove no-sidebars class from drupal
      $variables['classes_array'] = array_diff($variables['classes_array'], array('no-sidebars'));
    } else {
      $variables['classes_array'][] = 'no-widgets';
    }
  }

  // Set favicons
  $path_to_favicons = drupal_get_path('theme', 'checkdesk') . '/assets/imgs/icons';
  $favicons = '';
  $favicons .= '<link rel="icon" type="image/png" href="/' .  $path_to_favicons . '/favicon-16x16.png" sizes="16x16">';
  $favicons .= '<link rel="icon" type="image/png" href="/' . $path_to_favicons .'/favicon-32x32.png" sizes="32x32">';
  $variables['favicons'] = $favicons;

  $head_title = array();
  $title = drupal_get_title();
  if (!empty($title)) {
    $head_title[] = htmlspecialchars_decode($title);
  }
  $head_title[] = variable_get('site_name', 'Drupal');
  $variables['head_title'] = strip_tags(implode(' | ', $head_title));
  // Add meta tag for twitter:widgets:csp ticket #3628
  $twitter_csp = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'twitter:widgets:csp',
      'content' => 'on',
    ),
  );
  drupal_add_html_head($twitter_csp, 'twitter:widgets:csp');
}

/**
 * Override or insert variables into the region template.
 */
function checkdesk_preprocess_region(&$variables) {
  global $language;

  if ($variables['region'] == 'header') {
    // header logo
    $variables['header_logo'] = '';
    $header_logo_uri = theme_get_setting('header_logo_path');
    // badge logo
    $variables['badge_logo'] = '';
    $badge_logo_uri = theme_get_setting('badge_logo_path');

    if (!empty($header_logo_uri) && !empty($badge_logo_uri)) {

      $header_logo_data = array(
        'style_name' => 'header_logo',
        'path' => $header_logo_uri,
      );

      $badge_logo_data = array(
        'style_name' => 'header_logo',
        'path' => $badge_logo_uri,
      );

      // add hidden class to logo with default class
      if($variables['is_front']) {
        $logo_classes = array('header_logo', 'hidden-on-frontpage');
      } else {
        $logo_classes = array('header_logo');
      }

      // use badge logo when in portrait mode
      $header_logo_image_path = image_style_url($header_logo_data['style_name'], $header_logo_data['path']);
      $badge_logo_image_path = image_style_url($badge_logo_data['style_name'], $badge_logo_data['path']);
      $header_logo_image = '<picture>';
      $header_logo_image .= '<source media="(min-width: 750px)" srcset="' . $header_logo_image_path . '" />';
      $header_logo_image .= '<source srcset="' . $badge_logo_image_path . '" />';
      $header_logo_image .= '<img src="' . $header_logo_image_path . '" />';
      $header_logo_image .= '</picture>';

      $variables['header_logo'] = l($header_logo_image, '<front>',
        array('html' => TRUE, 'attributes' => array('class' => $logo_classes))
      );
    }
  }

  if ($variables['region'] == 'widgets') {
    // frontpage logo
    $variables['frontpage_logo'] = '';
    $image = theme_get_setting('frontpage_logo_path');

    if (!empty($image)) {
      $frontpage_logo_data = array(
          'style_name' => 'partner_logo',
          'path' => $image,
          'attributes' => array(
            'class' => 'partner-logo',
          )
      );
      $variables['frontpage_logo'] = theme('image_style', $frontpage_logo_data);
    }
    $bg = theme_get_setting('header_bg_path');
    $variables['header_bg'] = (empty($bg) ? '' : file_create_url($bg));
    $variables['header_slogan'] = variable_get('site_slogan', '');
  }

  if ($variables['region'] == 'footer') {
    // define custom header settings
    $partner_name = variable_get('site_name', 'Drupal');
    if (!empty($partner_name)) {
      $variables['partner_name'] = $partner_name;
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
}

/**
 * Preprocess variables for page.tpl.php
 *
 * @see page.tpl.php
 */
function checkdesk_preprocess_page(&$variables) {
  global $user, $language;

  // load timeago library along with localized file
  drupal_add_js(drupal_get_path('theme', 'checkdesk') . "/assets/js/libs/jquery.timeago.js");
  $localized_timeago = drupal_get_path('theme', 'checkdesk') . "/assets/js/libs/jquery.timeago." . $language->language . ".js";
  if (file_exists($localized_timeago)) {
    drupal_add_js($localized_timeago);
  }

  // 404 PAGE template
  $status = drupal_get_http_header("status");
  if ($status == "404 Not Found") {
    if ($variables['language']->language == 'ar') {
      $variables['theme_hook_suggestions'][] = 'page__404__rtl';
    } else {
      $variables['theme_hook_suggestions'][] = 'page__404';
    }
  }

  // Page templates for each node type
  if (isset($variables['node'])) {
    // If the node type is "discussion" the template suggestion will be "page--discussion.tpl.php".
    if($variables['node']->type == 'discussion' || $variables['node']->type == 'media') {
      $variables['theme_hook_suggestions'][] = 'page__content';
    }
  }

  // Unescape HTML in title
  $variables['title'] = htmlspecialchars_decode(drupal_get_title());

  // Add a path to the theme so checkdesk_inject_bootstrap.js can load libraries
  $variables['basePathCheckdeskTheme'] = url(drupal_get_path('theme', 'checkdesk'), array('language' => (object) array('language' => FALSE)));
  drupal_add_js(array('basePathCheckdeskTheme' => $variables['basePathCheckdeskTheme']), 'setting');

  // Add JS file for front page only
  if ($variables['is_front']) {
    drupal_add_js(drupal_get_path('theme', 'checkdesk') . '/assets/js/front.js', array('scope' => 'footer', 'weight' => 99));
  }

  // Responsive Nav JS
  drupal_add_js(drupal_get_path('theme', 'checkdesk') . '/assets/js/libs/responsive-nav.min.js', array('scope' => 'header', 'weight' => 98, 'group' => JS_THEME, 'every_page' => TRUE));
  drupal_add_js(libraries_get_path('mediaCheck') . '/mediaCheck-min.js', array('scope' => 'header', 'group' => JS_THEME, 'every_page' => TRUE));
  drupal_add_js(drupal_get_path('theme', 'checkdesk') . '/assets/js/responsive-nav.js', array('scope' => 'footer', 'weight' => 99));
  // Add picture polyfill for responsive images in browsers that don't support it yet
  // @todo: #1664602: D7 does not yet support "async" in drupal_add_js().
  drupal_add_js(drupal_get_path('theme', 'checkdesk') . '/assets/js/libs/picturefill.min.js', array('scope' => 'footer', 'weight' => 99));

  // logo icon for header
  $svg_file = base_path() . drupal_get_path('theme', 'checkdesk') . '/assets/imgs/icons/icons.svg';
  $variables['logo_icon'] = '<svg class="logo-icon" preserveAspectRatio="xMinYMin meet" viewBox="0 0 27 39"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="' . $svg_file . '#logo-icon"></use></svg>';

  // Secondary nav
  $variables['secondary_nav'] = FALSE;
  $menu = menu_load('menu-common');
  $tree = menu_tree_page_data($menu['menu_name']);

  // Remove items that are not from this language or that does not have children, or are not enabled
  foreach ($tree as $id => $item) {
    if ((preg_match('/^<[^>]*>$/', $item['link']['link_path']) && $item['link']['expanded'] && count($item['below']) == 0) || $item['link']['hidden']) {
      unset($tree[$id]);
    }

    if ($item['link']['language'] != LANGUAGE_NONE && $item['link']['language'] != $language->language) {
      unset($tree[$id]);
    }

    foreach ($item['below'] as $subid => $subitem) {
      if ( $subitem['link']['hidden'] || ($subitem['link']['language'] != LANGUAGE_NONE && $subitem['link']['language'] != $language->language)) {
        unset($tree[$id]['below'][$subid]);
      }
    }
  }

  $variables['secondary_menu'] = checkdesk_menu_navigation_links($tree);

  $layout = checkdesk_core_direction_settings();

  // Change links
  foreach ($variables['secondary_menu'] as $id => $item) {

    if ($item['title'] === '<user>') {
      foreach ($item['below'] as $subid => $subitem) {
        if ($subitem['link_path'] == 'checkdesk/nojs/sign_in_up') {
          if (user_is_logged_in())
            unset($variables['secondary_menu'][$id]['below'][$subid]);
          else
            $variables['secondary_menu'][$id] = $subitem;
        }
      }
      if (user_is_logged_in()) {
        $variables['secondary_menu'][$id]['html'] = TRUE;
        $variables['secondary_menu'][$id]['title'] = theme('checkdesk_user_menu_item');
        $variables['secondary_menu'][$id]['attributes']['data-toggle'] = 'dropdown';
        $variables['secondary_menu'][$id]['attributes']['class'] = 'dropdown-toggle';
        $variables['secondary_menu'][$id]['attributes']['id'] = 'my-account-link';
        $variables['secondary_menu'][$id]['suffix'] = theme('checkdesk_user_menu_content', array('items' => $variables['secondary_menu'][$id]['below']));

        unset($variables['secondary_menu'][$id]['below']);
      }
    } else if ($item['link_path'] == 'my-notifications') {
      if (user_is_logged_in()) {
        $count = checkdesk_notifications_number_of_new_items($user);
        $variables['secondary_menu'][$id]['attributes']['id'] = 'my-notifications-menu-link';
        $variables['secondary_menu'][$id]['html'] = TRUE;
        if($count > 0) {
          $variables['secondary_menu'][$id]['title'] = '<span class="icon-bell-o"></span><span class="badge notifications-count">' . $count . '</span>';
        } else {
          $variables['secondary_menu'][$id]['title'] = '<span class="icon-bell-o"></span><span class="notifications-count"></span>';
        }
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
    if ($item['link']['language'] != LANGUAGE_NONE && $item['link']['language'] != $language->language)
      unset($tree[$id]);
    foreach ($item['below'] as $subid => $subitem) {
      if ($subitem['link']['language'] != LANGUAGE_NONE && $subitem['link']['language'] != $language->language)
        unset($tree[$id]['below'][$subid]);
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

  if (user_is_logged_in()) {
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
  }
  // define custom header settings
  $variables['header_logo'] = '';
  $image = theme_get_setting('header_logo_path');

  if (!empty($image)) {
    $variables['header_logo'] = l(theme('image', array('path' => file_create_url($image))), '<front>', array('html' => TRUE));
  }

  $variables['header_slogan'] = t('A <span class="checkdesk-slogan-logo">Checkdesk</span> Liveblog by <span class="checkdesk-slogan-partner">@partner</span>', array('@partner' => variable_get_value('checkdesk_site_owner', array('language' => $language))));

  // set page variable if widgets should be visible
  $variables['show_widgets'] = checkdesk_widgets_visibility();


  // set page variable if header logo should be visible
  $variables['show_header'] = checkdesk_header_logo_visibility();

  // set page variable if widgets should be visible
  $variables['show_footer'] = checkdesk_footer_visibility();
}

/**
 * Override or insert variables into the node template.
 */
function checkdesk_preprocess_node(&$variables) {
  global $language;
  $node = @$variables['elements']['#node'];

  // get $alpha and $omega
  $variables['layout'] = checkdesk_core_direction_settings();
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'];

  if ($variables['view_mode'] == 'checkdesk_collaborate') {
    if ($variables['type'] == 'media') {
      $message_id = $variables['heartbeat_row']->heartbeat_activity_message_id;
      $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $variables['view_mode'] . '__' . $message_id;
    }
  } elseif ($variables['type'] == 'discussion' && !empty($variables['heartbeat_row'])) {
    $message_id = $variables['heartbeat_row']->heartbeat_activity_message_id;
    $variables['theme_hook_suggestions'][] = 'node__' . $variables['type'] . '__' . $message_id;
  }

  // Do nothing if view mode is search index
  // as we only need to index title & body
  // check search index display settings
  if ($variables['view_mode'] == 'search_index') {
    return;
  }

  if ($variables['type'] == 'post') {
    $parent_story_id = $variables['field_desk'][LANGUAGE_NONE][0]['target_id'];
    $update_anchor = 'update-' . $variables['nid'];
    $update_link = url('node/' . $parent_story_id, array('fragment' => $update_anchor, 'language' => $language));
    $variables['update_link'] = $update_link;
    global $language;
    // Set custom format based on language.
    if(date('Y') == format_date($node->created, 'custom', 'Y')) {
      $custom_format = ($language->language == 'en') ? t('D, F j\t\h \a\t g:i A') : t('D, j F g:i A');
    } else {
      $custom_format = ($language->language == 'en') ? t('D, F j\t\h Y \a\t g:i A') : t('D, j F Y g:i A');
    }
    $variables['media_creation_info'] =
      t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a>', array(
        '@url' => $update_link,
        '!timestamp' => format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP'),
        '!daydatetime' => format_date($variables['created'], 'custom', $custom_format),
    ));

    $variables['created_by'] = t('<a class="actor" href="@user">!user</a>', array(
        '@user' => url('user/' . $variables['uid']),
        '!user' => $node->name,
    ));
    $variables['created_at'] = t('<time datetime="!isodatetime" class="timeago">!interval ago</time>', array(
        '!date' => format_date($variables['created'], 'custom', 'Y-m-d'),
        '!datetime' => format_date($variables['created'], 'custom', t('M d, Y \a\t g:ia')),
        '!interval' => format_interval((time() - $variables['created']), 1),
        '!isodatetime' => format_date($variables['created'], 'custom', 'c'),
    ));
    $user = user_load($variables['uid']);
    $variables['user_avatar'] = _set_user_avatar_bg($user, array('avatar', 'thumb-22'));
    if (isset($variables['title'])) {
      if ($variables['title'] === _checkdesk_core_auto_title($node) || $variables['title'] === t('Update')) {
        unset($variables['title']);
      }
    }
  }

  if ($variables['type'] == 'discussion') {
    // get authors
    $variables['story_authors'] = _checkdesk_story_authors($variables['node']);

    // get timezone information to display in timestamps e.g. Cairo, Egypt
    $site_timezone = checkdesk_get_timezone();
    $timezone = t('!city, !country', array('!city' => t($site_timezone['city']), '!country' => t($site_timezone['country'])));
    // FIXME: Ugly hack
    if ($site_timezone['city'] == 'Jerusalem') {
      $timezone = t('Jerusalem, Palestine');
    }

    if ($variables['view_mode'] == 'checkdesk_collaborate' || $variables['view_mode'] == 'full' ) {
      $variables['creation_info_short'] =
        t('!authors <span class="separator">&#9679;</span> <time datetime="!date">!datetime</time>', array(
        '!authors' => $variables['story_authors'],
        '!date' => format_date($variables['created'], 'custom', 'Y-m-d'),
        '!datetime' => format_date($variables['created'], 'custom', t('M d Y')),
      ));

      $variables['updated_at'] = t('<time datetime="!date">!datetime !timezone</time>', array(
        '!date' => format_date($variables['changed'], 'custom', 'Y-m-d'),
        '!datetime' => format_date($variables['changed'], 'custom', t('g:ia \o\n M d, Y')),
        '!timezone' => $timezone,
      ));
      // Add tab (update & collaborate) to story
      $variables['story_tabs'] = _checkdesk_story_tabs($variables['nid']);
      // Add follow story flag
      global $user;
      if ($user->uid) {
        $follow_story = flag_create_link('follow_story', $variables['nid']);
      } else {
        $flag_count = flag_get_counts('node', $variables['nid']);
        $follow_story = l(t('Follow story'), 'user/login', array('query' => array(drupal_get_destination())));
        // append count
        if (isset($flag_count['follow_story'])) {
          $follow_story .= '<span class="follow-count" >' . $flag_count['follow_story'] . '</span>';
        }
      }
      $variables['follow_story'] = $follow_story;
      // Collaboration header for story.
      $variables['story_links'] = _checkdesk_story_links($variables['nid']);
      $variables['story_collaborators'] = _checkdesk_story_get_collaborators($variables['nid']);
      // Facebook comments count
      if (!variable_get('meedan_facebook_comments_disable', FALSE)) {
        $variables['story_commentcount'] = array(
          '#theme' => 'facebook_commentcount',
          '#node' => node_load($variables['nid']),
        );
      }
      if ($variables['view_mode'] == 'checkdesk_collaborate') {
        // Get heartbeat activity for particular story
        $variables['story_collaboration'] = views_embed_view('story_collaboration', 'page', $variables['nid']);
      }
      elseif ($variables['view_mode'] == 'full') {
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
    }
    elseif ($variables['view_mode'] == 'checkdesk_search') {
      $variables['story_collaborators'] = _checkdesk_story_get_collaborators($variables['nid']);
    }

    if ($variables['view_mode'] == 'checkdesk_search' || !empty($variables['heartbeat_row'])) {
      // Format lead image as thumbnail for activity template & search template
      $variables['inline_thumbnail'] = '';

      if (isset($variables['field_lead_image'][0]['uri'])) {
        $variables['inline_thumbnail'] = _meedan_inline_thumbnail_bg($node, array('inline-img-thumb'));
      }

      // use media creation info for activity templates & search template
      global $language;
      // Set custom format based on language.
      if(date('Y') == format_date($node->created, 'custom', 'Y')) {
        $custom_format = ($language->language == 'en') ? t('D, F j\t\h \a\t g:i A') : t('D, j F g:i A');
      } else {
        $custom_format = ($language->language == 'en') ? t('D, F j\t\h Y \a\t g:i A') : t('D, j F Y g:i A');
      }
      $variables['media_creation_info'] =
        t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a>', array(
        '@url' => url('node/' . $variables['nid']),
        '!timestamp' => format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP'),
        '!daydatetime' => format_date($variables['created'], 'custom', $custom_format),
      ));
    }
  }


  $variables['icon'] = '';

  if ($variables['type'] == 'media') {
    global $language;
    //Add author info to variables
    $user = user_load($node->uid);
    $user_picture = $user->picture;
    if (!empty($user_picture)) {
      $options = array(
          'html' => TRUE,
          'attributes' => array(
              'class' => 'gravatar'
          )
      );
    }
    // set provider class name
    $provider = strtolower($node->embed->provider_name);
    $variables['provider_class_name'] = str_replace('.', '_', $provider) . '-wrapper';
    // set status class name
    if (isset($node->field_rating['und'][0]['taxonomy_term']->name)) {
      $status = strtolower($node->field_rating['und'][0]['taxonomy_term']->name);
      $variables['status_class'] = 'status-' . str_replace(' ', '-', $status);
    }
    // set embed type as class name
    $item_type = strtolower($node->embed->type);
    $variables['media_type_class'] = 'media--' . str_replace(' ', '-', $item_type);

    //Add node creation info(author name plus creation time
    if ($variables['view_mode'] == 'checkdesk_collaborate') {
      global $language;
      // Set custom format based on language.
      if(date('Y') == format_date($node->created, 'custom', 'Y')) {
        $custom_format = ($language->language == 'en') ? t('D, F j\t\h \a\t g:i A') : t('D, j F g:i A');
      } else {
        $custom_format = ($language->language == 'en') ? t('D, F j\t\h Y \a\t g:i A') : t('D, j F Y g:i A');
      }
      $variables['media_creation_info'] =
        t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a>', array(
          '@url' => $node->embed->original_url,
          '!timestamp' => format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP'),
          '!daydatetime' => format_date($variables['created'], 'custom', $custom_format),
      ));
    }
    else {
      $variables['media_timestamp'] =
        t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a>', array(
          '@url' => url('node/' . $variables['nid']),
          '!timestamp' => format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP'),
          '!datetime' => format_date($variables['created'], 'custom', t('M d, Y \a\t g:ia e')),
          '!daydatetime' => format_date($variables['created'], 'custom', t('D, F j\t\h \a\t g:i A')),
          '!interval' => format_interval(time() - $variables['created'], 1),
        )
      );
      $variables['media_creation_info'] =
        t('Added by <a class="contributor" href="@user">!user</a> <a href="@url"><time class="date-time" datetime="!timestamp">!datetime</time></a>', array(
          '@user' => url('user/' . $variables['uid']),
          '!user' => $node->name,
          '@url' => url('node/' . $variables['nid']),
          '!timestamp' => format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP'),
          '!datetime' => format_date($variables['created'], 'custom', t('M d, Y \a\t g:ia e')),
          '!interval' => format_interval(time() - $variables['created'], 1),
        )
      );

      // Set published stories.
      $variables['published_stories'] = '';
      $published_stories_links = array();
      $published_cond = user_access('access any drafts content') ? array(0, 1) : array(1);
      $published_stories = db_query('
        SELECT DISTINCT nid_target, n.title
        FROM {heartbeat_activity} ha
        INNER JOIN {node} n ON ha.nid_target = n.nid AND ha.nid = :nid AND n.status IN (:published)
        WHERE message_id IN (:status)
      ', array(
        ':nid' => $variables['nid'],
        ':published' => $published_cond,
        ':status' => array('checkdesk_report_suggested_to_story', 'publish_report')
      ))->fetchAllKeyed(0);
      // display published in story if more than one story or user access report/media page
      if (count($published_stories) > 1 || $variables['page'] == TRUE) {
        foreach ($published_stories as $k => $v) {
          array_push($published_stories_links, l($v, 'node/' . $k));
        }
        $variables['published_stories'] .= implode('<span class="separator">,</span> ', $published_stories_links);
      }
    }
    $variables['report_activity'] = theme(
      'checkdesk_core_report_activity', array('node' => $node, 'content' => $variables['content'], 'view_mode' => $variables['view_mode'])
    );

    // Inject lazy-loading.
    if (isset($variables['content']['field_link'])) {
      $field_link_rendered = render($variables['content']['field_link']);

      // Quick and easy, replace all src attributes with data-somethingelse
      // Drupal.behavior.lazyLoadSrc handles re-applying the src attribute when
      // the iframe tag enters the viewport. Skip doing this for src that addresses our own site.
      // See: http://stackoverflow.com/a/7154968/806988
      // use drupal_get_path to find imgs src instead on path_to_theme as imgs exist only on checkdesk theme
      global $base_url;
      $placeholder = base_path() . drupal_get_path('theme', 'checkdesk') . '/assets/imgs/icons/loader_white.gif';
      $field_link_rendered = preg_replace(
        '/<(iframe|img)([^>]*)(src=["\'](?!' . preg_quote($base_url, '/') . '))/i',
        '<\1\2src="' . $placeholder . '" data-lazy-load-\3',
        $field_link_rendered
      );

      // Lazy load classes as well (for dynamic-loaded content, like tweets, for example)
      $field_link_rendered = preg_replace('/<(blockquote)([^>]*)class=/i', '<\1\2data-lazy-load-class=', $field_link_rendered);
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
  if (user_is_logged_in()) {
    // Prepare for modal dialogs.
    ctools_include('modal');
    ctools_include('ajax');
    ctools_modal_add_js();
  }
  ctools_add_js('checkdesk_core', 'checkdesk_core');
  if (arg(0) != 'embed' && count($links) > 0) {
    $output = '<div' . drupal_attributes(array('class' => $class)) . '>';
    // Add share links
    $options = array('links' => $links, 'direction' => $links['dropdown-direction'],
        'type' => 'checkdesk-share', 'wrapper_class' => 'share-on', 'icon_class' => 'icon-share');
    $output .= theme('checkdesk_core_render_links', array('options' => $options));

    if (isset($links['flag-spam'])) {
      $links['flag-spam']['cd_group'] = 'checkdesk-flag';
    }
    if (isset($links['flag-graphic'])) {
      $links['flag-graphic']['cd_group'] = 'checkdesk-flag';
    }
    if (isset($links['flag-factcheck'])) {
      $links['flag-factcheck']['cd_group'] = 'checkdesk-flag';
    }
    if (isset($links['flag-delete'])) {
      $links['flag-delete']['cd_group'] = 'checkdesk-flag';
    }
    // add flag links
    $options = array('links' => $links, 'direction' => $layout['omega'],
        'type' => 'checkdesk-flag', 'wrapper_class' => 'flag-as', 'icon_class' => 'icon-flag-o');
    $output .= theme('checkdesk_core_render_links', array('options' => $options));

    if (isset($links['checkdesk-suggest'])) {
      $links['checkdesk-suggest']['cd_group'] = 'checkdesk-ellipsis';
      $links['checkdesk-suggest']['link_type'] = 'modal';
      $links['checkdesk-suggest']['modal_class'] = 'ctools-modal-modal-popup-medium';
    }
    if (isset($links['checkdesk-edit'])) {
      $links['checkdesk-edit']['cd_group'] = 'checkdesk-ellipsis';
      $links['checkdesk-edit']['link_type'] = 'link';
    }
    if (isset($links['checkdesk-delete'])) {
      $links['checkdesk-delete']['cd_group'] = 'checkdesk-ellipsis';
      $links['checkdesk-delete']['link_type'] = 'link';
    }
    if (isset($links['flag-factcheck_journalist'])) {
      $links['flag-factcheck_journalist']['cd_group'] = 'checkdesk-ellipsis';
    }
    if (isset($links['flag-graphic_journalist'])) {
      $links['flag-graphic_journalist']['cd_group'] = 'checkdesk-ellipsis';
    }

    $options = array('links' => $links, 'direction' => $layout['omega'],
        'type' => 'checkdesk-ellipsis', 'wrapper_class' => 'add-to', 'icon_class' => 'icon-ellipsis-h');
    $output .= theme('checkdesk_core_render_links', array('options' => $options));

    $output .= '</div>';
  }

  return $output;
}

/**
 * Utitity function to determine whether to show widgets or not
 */
function checkdesk_widgets_visibility() {
  global $user;
  // Only display on front page
  if (drupal_is_front_page()) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Utitity function to determine whether to show header image or not
 */
function checkdesk_header_logo_visibility() {
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
    // Header
    if (in_array($region, array('header'))) {
      $page['header'] = array(
          '#region' => 'header',
          '#weight' => '-10',
          '#theme_wrappers' => array('region'),
      );
    }
    // Sidebar
    if (!isset($page['widgets'])) {
      if (in_array($region, array('widgets'))) {
        $page['widgets'] = array(
            '#region' => 'widgets',
            '#theme_wrappers' => array('region'),
        );
      }
    }
    // Navigation as toolbar
    if (!isset($page['navigation'])) {
      if (in_array($region, array('navigation'))) {
        $page['navigation'] = array(
            '#region' => 'navigation',
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

  $output .= '<div class="story-blogger ' . $variables['classes'] . '">';
  $output .= '<div class="avatar">' . $variables['blogger_picture'] . $variables['blogger_name'] . '</div>';
  $output .= '<div class="blogger-status ' . $variables['blogger_status_class'] . '"><span class="blogger-status-indicator"></span><span class="blogger-status-text">' . $variables['blogger_status_text'] . '</span></div>';
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

  if (isset($variables['story_drafts']) && !empty($variables['story_drafts']))
    $output .= '<div class="story-drafts">' . $variables['story_drafts'] . '</div>';

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
  foreach ($variables['items'] as $key => $tag) {
    $output = $tag['#title'];
  }
  return $output;
}


/**
 * Field: Tags
 */
function checkdesk_field__field_tags(&$variables) {
  if ($variables['element']['#view_mode'] == 'full' || $variables['element']['#view_mode'] == 'checkdesk_collaborate') {
    $type = $variables['element']['#bundle'];
    if ($type == 'media') {
      $alt_type = array(
          'singular' => t('Report'),
          'plural' => t('Reports'),
      );
    } elseif ($type == 'discussion') {
      $alt_type = array(
          'singular' => t('Story'),
          'plural' => t('Stories'),
      );
    }

    $output = '<section id="media-tags" class="cd-container">';
    $output .= '<div class="cd-container-inner">';
    $output .= '<div class="submeta"><h2 class="submeta-header">' . t('Published in') . '</h2>';
    $output .= '<ul class="tag-list u-unstyled inline-list submeta-content">';
    foreach ($variables['element']['#items'] as $key => $item) {
      $tag_name = '<span class="tag-name">' . $item['taxonomy_term']->name . '</span>';
      $tag_count = _checkdesk_term_nc($item['tid'], FALSE, $type);
      $count = '<span class="tag-count">' . format_plural($tag_count, '1 @singular', '@count @plural', array('@count' => $tag_count, '@singular' => $alt_type['singular'], '@plural' => $alt_type['plural'])) . '</span>';

      $output .= '<li class="inline-list-item">';

      $output .= l($tag_name . $count, 'taxonomy/term/' . $item['tid'], array(
          'html' => TRUE,
          'attributes' => array(
              'title' => t("@title", array('@title' => $item['taxonomy_term']->name)),
              'class' => array('tag-link'),
          ),
      ));

      $output .= '</li>';
    }
    $output .= '</ul></div></div></section>';
    return $output;
  }
}

/**
 * Field: Lead image
 */
function checkdesk_field__field_lead_image(&$variables) {
  // generate img tag with srcset
  $output = _checkdesk_generate_lead_image($variables['element']['#items'][0]['uri'], $variables['element']['#items'][0]['image_field_caption']['value']);
  return $output;
}

/**
 * Utiltiy function that generates a responsive img tag
 * for lead image in the story node
 */
function _checkdesk_generate_lead_image($image, $image_caption) {
  $output = '';
  // generate small, medium and large images
  if(isset($image)) {
    $lead_image_path = image_style_url('featured_image', $image);
    $lead_image_med_path = image_style_url('featured_image_med', $image);
    $lead_image_small_path = image_style_url('featured_image_small', $image);
    // set small, med and large images in srcset
    $output .= '<picture>';
    $output .= '<source media="(min-width: 740px)" srcset="' . $lead_image_path . '" />';
    $output .= '<source media="(min-width: 660px)" srcset="' . $lead_image_med_path   . '"/>';
    $output .= '<source srcset="' . $lead_image_small_path   . '"/>';
    $output .= '<img class="feature-image" src="' . $lead_image_small_path . '" />';
    $output .= '</picture>';
  }
  if(isset($image_caption)) {
    $output .= '<figcaption>' . check_markup($image_caption, 'filtered_html') . '</figcaption>';
  }

  return $output;
}

/**
 * Utiltiy function that generates a responsive img tag
 * for lead image in containers as thumbnails
 */
function _checkdesk_generate_lead_image_thumbnail($image) {
  $output = '';
  // generate small, medium and large images
  if(isset($image)) {
    $lead_image_path = image_style_url('item_image_medium', $image);
    $lead_image_uri = image_style_path('item_image_medium', $image);
    $lead_image_size = getimagesize($lead_image_uri);
    $lead_image_med_path = image_style_url('item_image_medium', $image);
    $lead_image_small_path = image_style_url('item_image_small', $image);
    // set small, med and large images in srcset
    $output .= '<img';
    $output .= ' srcset="' . $lead_image_med_path . ' 220w, ' . $lead_image_small_path . ' 120w"'; 
    $output .= ' sizes="(min-width: 980px) 220px, (min-width: 740px) 220px, 120px"';
    $output .= ' src="' . $lead_image_small_path . '"';
    $output .= ' class="feature-image"';
    $output .= '/>';
  }

  return $output;

}

/**
 * Implements hook_preprocess_button().
 */
function checkdesk_preprocess_button(&$variables) {
  $element = &$variables['element'];

  // Set the element's attributes.
  element_set_attributes($element, array('id', 'name', 'value', 'type'));

  // Add the base Bootstrap button class.
  $element['#attributes']['class'][] = 'btn';

  // Colorize button.
  _checkdesk_colorize_button($element);

  // Add in the button type class.
  // $element['#attributes']['class'][] = 'form-' . $element['#button_type'];

  // Ensure that all classes are unique, no need for duplicates.
  $element['#attributes']['class'] = array_unique($element['#attributes']['class']);
}

function checkdesk_fboauth_action__connect(&$variables) {
  $action = $variables['action'];
  $link = $variables['properties'];
  $url = url($link['href'], array('query' => $link['query']));
  $link['attributes']['class'] = isset($link['attributes']['class']) ? $link['attributes']['class'] : 'facebook-action-connect';
  $link['attributes']['class'] .= " btn btn-default";
  // Button i18n.
  $language = $GLOBALS['language']->language;
  $link['attributes']['class'] .= " fb-button-$language";
  $attributes = isset($link['attributes']) ? drupal_attributes($link['attributes']) : '';
  $title = isset($link['title']) ? check_plain($link['title']) : '';
  $text = t('Sign in with Facebook');
  return "<a $attributes href='$url' alt='$title'>$text</a>";
}

/**
 * Change Twitter login button from image to simple
 */
function checkdesk_twitter_signin_button() {
  $link['attributes']['class'] = array('btn', 'btn-default', 'twitter-action-signin');
  $link['attributes']['title'] = t('Sign in with Twitter');
  return l(t('Sign in with Twitter'), 'twitter/redirect', $link);
}

/**
 * Theme views
 */
function checkdesk_preprocess_views_view(&$vars) {
  global $base_path;
  $vars['base_path'] = $base_path;
  // set template functions for individual views
  if (isset($vars['view']->name)) {
    $function = 'checkdesk_preprocess_views_view__' . $vars['view']->name;
    if (function_exists($function)) {
      $function($vars);
    }
  }
}

/**
 * checkdesk_search view.
 */
function checkdesk_preprocess_views_view__checkdesk_search(&$vars) {
  // Set page title
  $view = $vars['view'];
  $page_title = t('Search');
  $get_args = $_GET;
  unset($get_args['q']);
  // Set title based on type filter
  if (count($get_args) == 1 && isset($get_args['type'])) {
    if ($_GET['type'] == 'report') {
      $page_title = t('Reports');
    } elseif ($_GET['type'] == 'update') {
      $page_title = t('Updates');
    } elseif ($_GET['type'] == 'story') {
      $page_title = t('Stories');
    }
  }
  // Set title based on tag filter
  elseif (count($get_args) == 1 && isset($get_args['field_tags_tid']) && is_numeric($_GET['field_tags_tid'])) {
    //Set taxonomy name as title
    $term = taxonomy_term_load($_GET['field_tags_tid']);
    $page_title = $term->name;
  }
  // Set title based on type and status filter
  elseif (count($get_args) == 2 && isset($get_args['type']) && isset($get_args['status'])) {
    if (!$get_args['status']) {
      if ($_GET['type'] == 'story') {
        $page_title = t('Draft stories');
      }
      elseif ($_GET['type'] == 'update') {
        $page_title = t('Draft updates');
      }
    }
  }
  $view->set_title($page_title);
}

/* Desk Reports */

function checkdesk_preprocess_views_view__desk_reports(&$vars) {
  if ($vars['display_id'] == 'block') {
    $story_nid = checkdesk_core__get_desk_reports_args();
    $filter_by_story = '';
    if (is_numeric($story_nid)) {
        $filter_by_story = '_checkdesk_filter_reports('. $story_nid . ');';
    }
    drupal_add_js('jQuery(function() {
      '. $filter_by_story .'
      window.onbeforeunload = _checkdesk_report_view_redirect;
      jQuery( "#post-node-form" ).submit(function( event ) {
        window.onbeforeunload = "";
      });
    });', 'inline');
  }
}

/**
 * Implements template_preprocess_views_view_fields().
 */
function checkdesk_preprocess_views_view_fields(&$vars) {
  global $user;

  if (in_array($vars['view']->name, array('desk_reports'))) {
    $report_nid = $vars['fields']['nid']->raw;
    $vars['name_i18n'] = isset($vars['fields']['field_rating']->content) ? t($vars['fields']['field_rating']->content) : NULL;

    if ((in_array('journalist', $user->roles) || in_array('administrator', $user->roles)) && checkdesk_core_report_published_on_update($report_nid)) {
      $vars['report_published'] = t('Published on update');
    } else {
      $vars['report_published'] = FALSE;
    }
    // Get embed type
    $vars['media_type_class'] = checkdesk_oembed_embed_class_type($report_nid);
  }

  if ($vars['view']->name === 'liveblog') {
    $vars['updates'] = isset($vars['view']->result[$vars['view']->row_index]->updates) ? $vars['view']->result[$vars['view']->row_index]->updates : '';

    // Facebook comments count
    if (!variable_get('meedan_facebook_comments_disable', FALSE)) {
      $vars['story_commentcount'] = array(
          '#theme' => 'facebook_commentcount',
          '#node' => node_load($vars['fields']['nid']->raw),
      );
    }
    // Add follow story flag
    if ($user->uid) {
      $follow_story = flag_create_link('follow_story', $vars['fields']['nid']->raw);
    }   else {
      $flag_count = flag_get_counts('node', $vars['fields']['nid']->raw);
      $follow_story = l(t('Follow story'), 'user/login', array('query' => array(drupal_get_destination())));
      // append count
      if (isset($flag_count['follow_story'])) {
        $follow_story .= '<span class="follow-count" >' . $flag_count['follow_story'] . '</span>';
      }
    }
    $vars['follow_story'] = $follow_story;
  }
  
  if ($vars['view']->name === 'updates_for_stories') {
    $vars['counter'] = intval($vars['view']->total_rows) - intval(strip_tags($vars['fields']['counter']->content)) + 1;
    $vars['update_id'] = $vars['fields']['nid']->raw;
    if ($vars['counter'] === $vars['view']->total_rows) {
      $vars['update'] = $vars['fields']['rendered_entity']->content;
    } else {
      $vars['update'] = $vars['fields']['rendered_entity_1']->content;
    }
  }
  
  if ($vars['view']->name === 'more_stories') {
    $vars['stories'] = isset($vars['view']->result[$vars['view']->row_index]->stories) ? $vars['view']->result[$vars['view']->row_index]->stories : '';
  }
  
  if ($vars['view']->name === 'recent_stories_by_tag') {
      // Facebook comments count
    if (!variable_get('meedan_facebook_comments_disable', FALSE)) {
      $vars['story_commentcount'] = array(
          '#theme' => 'facebook_commentcount',
          '#node' => node_load($vars['row']->nid),
      );
    }
    $vars['created_at'] = t('<time title="!datetime" datetime="!datetime" class="timestamp">!inverval</time>', array(
      '!inverval' => checkdesk_core_custom_format_interval($vars['row']->node_created),
      '!datetime' => format_date($vars['row']->node_created, 'custom', t('l M d, Y \a\t g:i:sa'))
    ));
    
  }
}

/**
 * Template preprocessor for `meedan_sensitive_content_display`.
 */
function checkdesk_preprocess_meedan_sensitive_content_display(&$vars) {
  $vars['meedan_sensitive_text'] = t(variable_get('meedan_sensitive_content_text', MEEDAN_SENSITIVE_CONTENT_DEFAULT_TEXT));
  $vars['meedan_sensitive_link'] = l(t('Display'), '', array('attributes' => array('class' => array('display-sensitive', 'btn', 'btn-default'), 'onclick' => 'meedanSensitiveContent.Update('. $vars['meedan_sensitive_nid'] .', true); return false;')));
}

/**
 * Process variables for user-profile.tpl.php.
 */
function checkdesk_preprocess_user_profile(&$variables) {
  $variables['member_for'] = t('Member for @time', array('@time' => $variables['user_profile']['summary']['member_for']['#markup']));
}

/*
 * Utility function to set timezone as City, Country
 */

function checkdesk_get_timezone() {
  // set timezone as Cairo, Egypt
  $site_timezone = array();
  $timezone = date_default_timezone();
  if ($timezone) {
    $timezone_array = explode('/', $timezone);
    $site_timezone['city'] = str_replace('_', ' ', array_pop($timezone_array));
  }
  $site_country_code = variable_get('site_default_country', '');
  if ($site_country_code) {
    $countries = country_get_list();
    foreach ($countries as $cc => $country) {
      if ($cc == $site_country_code) {
        $site_timezone['country'] = $country;
      }
    }
  }

  return $site_timezone;
}

/**
 * Theme function to render node-links - checkdesk style
 * $params array
 *  An associative array with the following keys.
 *  links => array of links
 *  wrapper_class => class for parent spam
 *  icon_class => title icon
 *
 */
function checkdesk_checkdesk_core_render_links($variables) {
  $output = '';
  $options = $variables['options'];
  $links = array();
  if (isset($options['type'])) {
    foreach ($options['links'] as $k => $link) {
      if (isset($link['cd_group']) && $link['cd_group'] == $options['type']) {
        $links[$k] = $link;
      }
    }
  }
  if (!isset($links[$options['type']])) {
    return $output;
  }
  $link_type = $links[$options['type']];
  $items = array();
  unset($links[$options['type']]);
  foreach ($links as $link) {
    if (isset($link['link_type'])) {
      if ($link['link_type'] == 'link') {
        // l link
        $items[] = l($link['title'], $link['href'], $link);
      } else {
        // modal link
        $items[] = ctools_modal_text_button($link['title'], $link['href'], $link['title'], $link['modal_class']);
      }
    } else {
      $items[] = $link['title'];
    }
  }
  if (count($items)) {
    $wrapper_class = $options['wrapper_class'];
    $icon_class = $options['icon_class'];
    $output .= '<span class="' . $wrapper_class . '">';
    $list_title = isset($link_type['title']) ? $link_type['title'] : '';
    $list_title = '<span class="' . $icon_class . '">' . $list_title . '</span>';
    $href = isset($link_type['href']) ? $link_type['href'] : '#';
    $output .= l($list_title, $href, $link_type);
    $output .= '<ul class="dropdown-menu pull-' . $options['direction'] . '">';
    foreach ($items as $item) {
      $output .= '<li>' . $item . '</li>';
    }
    $output .= '</ul></span>';
  }
  return $output;
}

/**
 * @param tid
 *   Term ID
 * @param child_count
 *   TRUE - Also count all nodes in child terms (if they exists) - Default
 *   FALSE - Count only nodes related to Term ID
 * @param type
 *   Type of Node
 */
function _checkdesk_term_nc($tid, $child_count = TRUE, $type) {
  $tids = array($tid);

  if ($child_count) {
    $tids = array_merge($tids, _checkdesk_term_get_children_ids($tid));
  }

  global $language;
  $langs = array($language->language);
  $langs[] = 'und';

  $query = db_select('taxonomy_index', 't');
  $query->condition('tid', $tids, 'IN');
  $query->addExpression('COUNT(*)', 'count_nodes');
  $query->join('node', 'n', 't.nid = n.nid');
  $query->condition('n.status', 1, '=');
  $query->condition('n.language', $langs, 'IN');
  if ($type) {
    $query->condition('n.type', $type);
  }

  $count = $query->execute()->fetchField();
  return $count;
}

/**
 * Retrieve ids of term children.
 *
 * @param $tid
 *   The term's ID.
 * @param $tids
 *   An array where ids of term children will be added
 */
function _checkdesk_term_get_children_ids($tid) {
  $children = taxonomy_get_children($tid);
  $tids = array();

  if (!empty($children)) {
    foreach ($children as $child) {
      $tids[] = $child->tid;
      $tids = array_merge($tids, term_get_children_ids($child->tid));
    }
  }
  return $tids;
}

/**
 * List story authors based on additional author field
 * @param $node
 * @return bool|string
 */
function _checkdesk_story_authors($node) {
  if (is_numeric($node)) {
    $node = node_load($node);
  }
  $query = db_select('field_data_field_additional_authors', 'fa');
  $query->fields('u', array('uid', 'name'));
  $query->join('users', 'u', 'u.uid = fa.field_additional_authors_target_id');
  $query->condition('fa.entity_id', $node->nid);
  $query->orderBy('fa.delta');
  $authors = $query->execute()->fetchAllKeyed(0);

  if (count($authors)) {
    $output = array();
    if (!array_key_exists($node->uid, $authors)) {
      $authors = array($node->uid => $node->name) + $authors;
    }
    foreach ($authors as $uid => $name) {
      $output[] = l($name, 'user/'. $uid, array('attributes' => array('class' => 'contributor')));
    }
    $story_authors = implode(', ', $output);
  }
  else {
    $story_authors = l($node->name, 'user/'. $node->uid, array('attributes' => array('class' => 'contributor')));
  }
  return $story_authors;
}
