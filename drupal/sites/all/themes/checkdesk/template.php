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


function checkdesk_field__field_rating(&$variables) {
  $output = '';
  foreach($variables['items'] as $key => $tag) {
      $output = $tag['#title']; 
  }
  return $output;
}
