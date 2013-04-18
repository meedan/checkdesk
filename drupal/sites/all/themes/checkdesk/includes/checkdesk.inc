<?php

/**
 * Returns navigational links based on a menu tree
 */
function checkdesk_menu_navigation_links($tree, $lvl = 0) {
  $result = array();

  if(count($tree) > 0) {
	foreach($tree as $id => $item) {
	  $new_item = array('title' => $item['link']['title'], 'link_path' => $item['link']['link_path'], 'href' => $item['link']['href']);
    if (isset($item['link']['class'])) {
      $new_item['class'] = $item['link']['class'];
    }
    if (isset($item['link']['html'])) {
      $new_item['html'] = $item['link']['html'];
    }
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
 * theme_checkdesk_dropdown_menu_content
 *
 * Renders a dropdown-menu div suitable for use with a Twitter Bootstrap menu.
 */
function checkdesk_checkdesk_dropdown_menu_content($variables) {
  return '<div id="' . $variables['id'] . '" class="dropdown-menu">' . drupal_render($variables['content']) . '</div>';
}

/**
 * theme_checkdesk_dropdown_menu_item
 */
function checkdesk_checkdesk_dropdown_menu_item($variables) {
  global $user;

  $output  = '<span'. drupal_attributes($variables['attributes']) .'>';
  $output .=   isset($variables['prefix']) ? $variables['prefix'] : '';
  $output .=   $variables['title'];
  $output .=   isset($variables['suffix']) ? $variables['suffix'] : '';
  $output .=   '<span class="caret"></span>';
  $output .= '</span>';

  return $output;
}

/**
 * theme_checkdesk_user_menu_item
 */
function checkdesk_checkdesk_user_menu_item($variables) {
  global $user;

  $title = '';

  if (!empty($user->picture)) {
    $user_avatar = theme('image_style', array('path' => file_load($user->picture)->uri, 'alt' => t(check_plain($user->name)), 'style_name' => 'navigation_avatar'));
    $title .= '<span class="avatar">' . $user_avatar . '</span> ';
  }

  $title .= check_plain($user->name);

  return theme('checkdesk_dropdown_menu_item', array('title' => $title));
}

/**
 * theme_checkdesk_user_menu_content
 */
function checkdesk_checkdesk_user_menu_content($variables) {
  // Need to load the full account to get access to all fields
  $account = user_load($GLOBALS['user']->uid);

  $items = $variables['items'];

  $linked_accounts = '';
  if ($account->twitter_accounts) {
    $linked_accounts .= '<span class="icon-twitter"></span> ';

    $to_join = array();
    foreach ($account->twitter_accounts as $twitter_account) {
      // See: http://stackoverflow.com/a/8920821/806988
      $to_join[] = l(
        '@' . $twitter_account->screen_name,
        'https://twitter.com/account/redirect_by_id?id=' . $twitter_account->id,
        array(
          'attributes' => array('class' => array('twitter-name'))
        )
      );
    }
    $linked_accounts .= implode(', ', $to_join);

    $linked_accounts .= ' <small>';
    $linked_accounts .=   format_plural(count($account->twitter_accounts), '(Linked account)', '(Linked accounts)');
    $linked_accounts .= '</small>';
  }

  $bio = isset($account->field_bio) && $account->field_bio ? $account->field_bio[LANGUAGE_NONE][0]['safe_value'] : '';

  $account_menu = theme('checkdesk_links', array(
    'links' => $variables['items'],
    'attributes' => array(
      'id' => 'account-menu',
    ),
    'heading' => NULL,
  ));

  $content = array(
    '#type'   => 'markup',
    '#markup' => theme('user_picture', array('account' => $account))
               . '<div class="info">'
               .   theme('username', array('account' => $account))
               .   '<div class="linked-account">' . $linked_accounts . '</div>'
               .   '<div class="bio">' . $bio . '</div>'
               . '</div>'
               . $account_menu
  );

  return theme('checkdesk_dropdown_menu_content', array('id' => 'my-account', 'content' => $content));
}

/**
 * theme_checkdesk_related_updates_bar
 */
function checkdesk_checkdesk_related_updates_bar($variables) {
  $story = $variables['story'];
  $count = checkdesk_core_story_updates_count($story);

  $output  = '';
  $output .= '<div class="related-updates">';
  $output .=   l(format_plural($count - 1, '1 more update', '@count more updates'), "node/$story->nid");
  $output .= '</div>';

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
