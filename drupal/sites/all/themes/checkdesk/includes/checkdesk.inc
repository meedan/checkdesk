<?php

/**
 * Returns navigational links based on a menu tree
 */
function checkdesk_menu_navigation_links($tree, $lvl = 0) {
  $result = array();

  if(count($tree) > 0) {
	foreach($tree as $id => $item) {
	  $new_item = array('title' => $item['link']['title'], 'link_path' => $item['link']['link_path'], 'href' => $item['link']['href']);
    if (isset($item['link']['class'])) $new_item['class'] = $item['link']['class'];
	  // Dont do drugs and don't do any levels deeper then 1
	  if($lvl < 1)
		$new_item['below'] = checkdesk_menu_navigation_links($item['below'], $lvl+1);
	  
	  $result['menu-'. $item['link']['mlid']] = $new_item;
	}
  }
  
  return $result;
}


/*
 * Custom theme functions
 *
 */

/**
 * Preprocess function for theme_checkdesk_btn_dropdown
 */
function checkdesk_preprocess_checkdesk_btn_dropdown(&$variables) {
  // Add default class
  $variables['attributes']['class'][] = 'btn-group';
  
  // Check if its a array of links so we need to theme it first here.
  if(is_array($variables['links'])) {
	$variables['links'] = theme('links', array(
	  'links' => $variables['links'],
	  'attributes' => array(
		'class' => array('dropdown-menu'),
	  ),
	));
  }
}  

/**
 * theme_checkdesk_btn_dropdown
 */
function checkdesk_checkdesk_btn_dropdown($variables) {
  $type_class = '';
  // Type class
  if(isset($variables['type']))
	$type_class = ' btn-'. $variables['type'];
  
  // Start markup
  $output = '<div'. drupal_attributes($variables['attributes']) .'>';

  // Show user 
  global $user;
  $output .= '<a class="btn btn-account'. $type_class .' dropdown-toggle" data-toggle="dropdown" href="#">';
  if(!empty($user->picture)) {
    $user_avatar = theme('image_style', array('path' => file_load($user->picture)->uri, 'alt' => t(check_plain($user->name)), 'style_name' => 'navigation_avatar'));
    $output .= '<i class="avatar">' . $user_avatar . '</i> ';
  }
  $output .= check_plain($user->name);
  
  // Finish markup 	
  $output .= '
  <span class="caret"></span>
	</a>
	' . $variables['links'] . '
  </div>';
  
  return $output;
} 




function checkdesk_theme_get_info($setting_name, $theme = NULL) {
// If no key is given, use the current theme if we can determine it.
  if (!isset($theme)) {
    $theme = !empty($GLOBALS['theme_key']) ? $GLOBALS['theme_key'] : '';
  }

  $output = array();

  if ($theme) {
    $themes = list_themes();
    $theme_object = $themes[$theme];

    // Create a list which includes the current theme and all its base themes.
    if (isset($theme_object->base_themes)) {
      $theme_keys = array_keys($theme_object->base_themes);
      $theme_keys[] = $theme;
    }
    else {
      $theme_keys = array($theme);
    }
    foreach ($theme_keys as $theme_key) {
      if (!empty($themes[$theme_key]->info[$setting_name])) {
        $output[$setting_name] = $themes[$theme_key]->info[$setting_name];
      }
    }
  }
  
  return $output;
}
