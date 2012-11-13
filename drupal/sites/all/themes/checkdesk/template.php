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
    'checkdesk_btn_dropdown' => array(
      'variables' => array('links' => array(), 'attributes' => array(), 'type' => NULL),
    ),
    'checkdesk_heartbeat_content' => array(
      'variables' => array('message' => array(), 'node' => array()),
    ), 
  );
}

/**
 * Preprocess variables for page.tpl.php
 *
 * @see page.tpl.php
 */
function checkdesk_preprocess_page(&$variables) {
  // Primary nav
  $variables['primary_nav'] = FALSE;
  if($variables['main_menu']) {
    // Build links
    $tree = menu_tree_page_data(variable_get('menu_main_links_source', 'main-menu'));
    $variables['main_menu'] = checkdesk_menu_navigation_links($tree);
    
    // Build list
    $variables['primary_nav'] = theme('checkdesk_links', array(
      'links' => $variables['main_menu'],
      'attributes' => array(
        'id' => 'main-menu',
        'class' => array('nav'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));
  }

  // Secondary nav
  $variables['secondary_nav'] = FALSE;
  if($variables['secondary_menu']) {
    $secondary_menu = menu_load(variable_get('menu_secondary_links_source', 'user-menu'));
    // Build links
    $tree = menu_tree_page_data($secondary_menu['menu_name']);
    $variables['secondary_menu'] = checkdesk_menu_navigation_links($tree);
  
    // Build list
    $variables['secondary_nav'] = theme('checkdesk_btn_dropdown', array(
      'links' => $variables['secondary_menu'],
      'label' => $secondary_menu['title'],
      'type' => 'btnBackground',
      'attributes' => array(
        'id' => 'user-menu',
        'class' => array('nav', 'pull-right'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));

  } else {
    // display sign in link
    $secondary_menu = menu_load('menu-utility-menu');
    $tree = menu_tree_page_data($secondary_menu['menu_name']);
    $variables['secondary_menu'] = checkdesk_menu_navigation_links($tree);
    // Build list
    $variables['secondary_nav'] = theme('checkdesk_links', array(
      'links' => $variables['secondary_menu'],
      'attributes' => array(
        'id' => 'utility-menu',
        'class' => array('nav', 'pull-right'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      ),
    ));
  }
}


/**
 * Override or insert variables into the node template.
 */
function checkdesk_preprocess_node(&$variables) {
  $variables['icon'] = '';
}

function checkdesk_links__node($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  //$dropdown = $variables['dropdown'];
  $class[] = 'report-actions';

  global $language_url;
  $output = '';

  global $base_url;
  if ($node = menu_get_object()) {
    $nid = $node->nid;
    $node_title = check_plain($node->title);
    $node_url = $base_url .'/'. drupal_lookup_path('alias',"node/".$node->nid);
    $tweet = $node_title;

  }

  if (count($links) > 0) {
    $output = '<ul' . drupal_attributes(array('class' => $class)) . '>';
    if (isset($node) && user_access('administer nodes')) {
      $output .= '<li class=""><a href="' . url('<front>') . 'node/' . $nid . '/edit"><i class="icon-edit"></i> Edit</a></li>';
    }
  
    if (user_is_logged_in()) {
      // Flag as
      $output .= '<li class="flag-as dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-flag"></i> Flag as</a>';
      $output .= '<ul class="dropdown-menu">';
      $output .= '<li>' . $links['flag-spam']['title'] . '</li>';
      $output .= '<li>' . $links['flag-graphic']['title'] . '</li>';
      $output .= '<li>' . $links['flag-factcheck']['title'] . '</li>';
      $output .= '</ul></li>'; 
    }
    
    if (isset($node)) {
      // Share on
      $output .= '<li class="share-on dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-share"></i> Share on</a>';
      $output .= '<ul class="dropdown-menu">';
      $output .= '<li><a href="https://www.facebook.com/sharer.php?u=' . $node_url . '&t=' . $node_title . '">Share on Facebook</a></li>';
      $output .= '<li><a href="http://twitter.com/intent/tweet?source=checkdesk&text=' . $tweet . '&url=' . $node_url . '">Share on Twitter</a></li>';
      $output .= '<li><a href="https://plus.google.com/share?url=' . $node_url . '">Share on Google+</a></li>';
      $output .= '</ul></li>'; 
    }
    if (user_access('administer nodes')) {
      // Add to
      $output .= '<li class="add-to dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-plus-sign"></i> Add to</a>';
      $output .= '<ul class="dropdown-menu">';
      $output .= '<li>' . l($links['checkdesk-suggest']['title'], $links['checkdesk-suggest']['href']) .'</li>';
      $output .= '<li>' . l($links['checkdesk-publish']['title'], $links['checkdesk-publish']['href']) .'</li>';
      $output .= '</ul></li>';
    }


    $output .= '</ul>';
  }

  return $output;
}

/**
 * Adjust report source markup
 */
function checkdesk_checkdesk_core_report_source(&$variables) {
  $output = '';

  $output .= '<span class="source-url">' . $variables['source_url'] . '</span> ';
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
  $form['actions']['submit']['#value'] = t('Add comment');
}

function checkdesk_field__field_rating(&$variables) {
  $output = '';
  foreach($variables['items'] as $key => $tag) {
      $output = $tag['#title']; 
  }
  return $output;
}
