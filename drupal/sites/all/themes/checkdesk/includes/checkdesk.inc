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
 * theme_checkdesk_user_menu_item
 */
function checkdesk_checkdesk_user_menu_item($variables) {
  $type_class = '';
  // Type class
  if(isset($variables['type']))
	$type_class = ' btn-'. $variables['type'];
  
  // Start markup
  $output = '<span'. drupal_attributes($variables['attributes']) .'>';

  // Show user 
  global $user;
  if(!empty($user->picture)) {
    $user_avatar = theme('image_style', array('path' => file_load($user->picture)->uri, 'alt' => t(check_plain($user->name)), 'style_name' => 'navigation_avatar'));
    $output .= '<span class="avatar">' . $user_avatar . '</span> ';
  }
  $output .= check_plain($user->name);
  
  // Finish markup 	
  $output .= '
  <span class="caret"></span>
	</a>
  </span>';
  
  return $output;
} 

// /**
//  * Override theme_button to add custom classes
//  */
// function checkdesk_button(&$vars) {
//   $element = $vars['element'];
//   // Set attributes
//   element_set_attributes($element, array('id', 'name', 'value'));
//   // Add default class
//   $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  
//   // Add custom classes
  
//   // Default Submit button
//   if($element['#id'] == 'edit-submit') {
//     $element['#attributes']['class'] = array('btn', 'btn-primary');
//   }
//   // Preview button
//   if(($element['#id'] == 'edit-preview-changes') || ($element['#id'] == 'edit-draft'))  {
//     $element['#attributes']['class'] = array('btn', 'btn-warning');
//   }
//   // Delete button
//   if($element['#id'] == 'edit-delete') {
//     $element['#attributes']['class'] = array('btn', 'btn-danger', 'pull-right');
//   }
  
//   // disabled state
//   if (!empty($element['#attributes']['disabled'])) {
//     $element['#attributes']['class'][] = 'form-button-disabled';
//   }
  
//   // dpm($element);
  
//   // Wrap the final button with a few extra elements
//   return '<input type="submit" '. (empty($element['#name']) ? '' : 'name="'. $element['#name'] .'" ')  .'id="'. $element['#id'].'" value="'. $element['#value'] .'" '. drupal_attributes($element['#attributes']) ." />";
// }


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
