<?php 

/**
 * Returns HTML for a set of links.
 */
function checkdesk_checkdesk_links($variables) {

  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  //$dropdown = $variables['dropdown'];

  global $language_url, $user;
  $output = '';

  if (count($links) > 0) {
    $output = '';
    $output .= '<ul' . drupal_attributes($attributes) . '>';
    
    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading. 
          'level' => 'li',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $num_links = count($links);
    $i = 1;
	
    foreach ($links as $key => $link) {
      $children = array();
      if(isset($link['below']))
        $children = $link['below'];

      $attributes = array('class' => array($key));

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1 && $num_links > 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_links && $i > 1) {
        $attributes['class'][] = 'last';
      }

      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page()))
      && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $attributes['class'][] = 'active';
      }

      if($link['href'] == '<front>') {
        $attributes['class'][] = 'home';
      }

      if ($link['href'] == '<sub>' && $link['title'] == '&nbsp;') {
        $attributes['class'][] = 'additional';
      }

      if ($link['link_path'] == 'node/add/media') {
        $attributes['class'][] = 'submit-report';
      }

      if ($link['link_path'] == 'node/add/discussion') {
        $attributes['class'][] = 'create-story';
      }

      if(count($children) > 0) {
        $attributes['class'][] = 'dropdown';
        $link['attributes']['data-toggle'] = 'dropdown';
        $link['attributes']['class'][] = 'dropdown-toggle';
      }

      if(!isset($link['attributes']))
        $link['attributes'] = array();

      $output .= '<li' . drupal_attributes(array('class' => $attributes['class'])) . '>';

      if (!empty($link['prefix'])) {
        $output .= $link['prefix'];
      }

      if (isset($link['class'])) {
        if (!isset($link['attributes']['class'])) $link['attributes']['class'] = array();
        $link['attributes']['class'] = array_merge($link['attributes']['class'], $link['class']);
      }

      if (isset($link['href'])) {
        if(count($children) > 0) { 
          $link['html'] = TRUE;
          $link['title'] .= '<span class="caret"></span>';
          $output .=  '<a' . drupal_attributes($link['attributes']) . ' href="#">'. $link['title'] .'</a>';
        } else {
          if($link['href'] == 'search') {
            $output .= '<a href="' . url('search') . '"><span class="icon-search"></span></a>';
          }
          // add notifications panel as drop down
          elseif($link['href'] == 'my-notifications') {
            $link['attributes']['class'][] = 'dropdown-toggle';
            $link['attributes']['data-toggle'] = 'dropdown';
            $output .= l($link['title'], $link['href'], $link);
            $output .= '<div id="my-notifications" class="dropdown-menu">';
            checkdesk_notifications_load_js();
            $block = module_invoke('views', 'block_view', 'my_notifications-block');
            @$block['content']['#markup'] .= '<p class="notifications-settings-link">' . l(t('Settings'), url('user/' . $user->uid . '/edit/notifications', array('absolute' => TRUE))) . '</p>';
            $output .= render($block['content']);
            $output .= '</div>';
          }
          elseif($link['href'] == 'checkdesk/nojs/sign_in_up') {
            $link['attributes']['class'][] = 'sign-in-up';
            $link['attributes']['class'][] = 'ctools_checkdesk_sign_in_up';
            $link['attributes']['class'][] = 'ctools-use-modal';
            $link['attributes']['class'][] = 'ctools-modal-modal-popup-medium';
            $link['query'] = drupal_get_destination();
            $output .= l($link['title'], $link['href'], $link);
          }
          else {
            $output .= l($link['title'], $link['href'], $link);  
          }
        }
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;

      if (!empty($link['suffix'])) {
        $output .= $link['suffix'];
      }

      if(count($children) > 0) {
        $attributes = array();
        $attributes['class'] = array('dropdown-menu');

        $output .= theme('checkdesk_links', array('links' => $children, 'attributes' => $attributes));
      }

      $output .= "</li>\n";	
    }

    $output .= '</ul>';
  }

  return $output;
}


/**
 * Implements hook_css_alter().
 *
 * Removes some CSS files.
 */
function checkdesk_css_alter(&$css) {
  // Remove style.css if style-rtl.css is included.
  global $language;
  if ($language->direction == LANGUAGE_RTL) {
    unset($css['sites/all/themes/checkdesk/assets/css/style.css']);
  }
  // keep css for some modules
  $keep_css = array(
    'misc/ui/jquery.ui.theme.css',
    'sites/all/modules/contrib/extlink/extlink.css',
  );
  $restore_css = array();
  foreach ($keep_css as $k) {
    if (isset($css[$k])) {
      $restore_css[$k] = $css[$k];
    }
  }
  // Excludes from .info
  $excludes = _checkdesk_alter(checkdesk_theme_get_info('exclude'), 'css');

  $pattern = str_replace('/', '\/', implode('|', array_keys($excludes)));
  foreach ($css as $path => $data) {
    if (preg_match("/^($pattern)/", $path)) unset($css[$path]);
  }
  // add css again to $css
  $css = $css + $restore_css;
}

/**
 * Implements hook_js_alter().
 */
function checkdesk_js_alter(&$js) {
  $excludes = _checkdesk_alter(checkdesk_theme_get_info('exclude'), 'js');
  $js = array_diff_key($js, $excludes);
}

function _checkdesk_alter($files, $type) {
  $output = array();
  
  foreach($files as $key => $value) {
    if(isset($files[$key][$type])) {
    foreach($files[$key][$type] as $file => $name) {
      $output[$name] = FALSE;
    }
    }
  }
  return $output;
}


/**
 * Returns HTML for status and/or error messages, grouped by type.
 *
 */
// function checkdesk_status_messages($variables) {
//   $display = $variables['display'];
//   $output = '';

//   $status_heading = array(
//     'status' => t('Status'),
//     'error' => t('Errors occurred'),
//     'warning' => t('Warning'),
//   );

//   foreach (drupal_get_messages($display) as $type => $messages) {
//     $output .= "<div class=\"alert alert-block alert-$type\">\n";
//     $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\">x</a>\n";

//     if (!empty($status_heading[$type])) {
//       $output .= '<h4 class="alert-heading">' . $status_heading[$type] . "</h4>\n";
//     }

//     if (count($messages) > 1) {
//       $output .= " <ul>\n";
//       foreach ($messages as $message) {
//         $output .= '  <li>' . $message . "</li>\n";
//       }
//       $output .= " </ul>\n";
//     }
//     else {
//       $output .= $messages[0];
//     }

//     $output .= "</div>\n";
//   }
//   return $output;
// }

function checkdesk_checkdesk_heartbeat_content($variables) {
  $message = $variables['message'];

  // prep user picture
  $user = user_load($message->uid);
  $avatar = _set_user_avatar_bg($user,array('avatar', 'thumb-38'));
  // set variables for new comment aka fact-checking footnote
  if ($message->message_id == 'new_comment_report') {
    // set actor / editor / user
    $actor = l($message->variables['!username'], 'user/'. $message->uid, array('html' => TRUE, 'attributes' => array('class' => array('actor'))));
    // 
    $comment_text = $message->variables['!comment'];
    if (isset($message->cid) && user_access('administer comments')) {
      $delete_footnote = l('<span class="icon-trash-o"></span>', 'comment/'. $message->cid .'/delete', array(
        //'query' => drupal_get_destination(),
        'attributes' => array('class' => 'inline-delete-item', 'title' => t('Delete')),
        'html' => TRUE,
      ));
    }
  }


  // set variables for status report 
  if ($message->message_id == 'status_report') {

    // set icons
    if ($status = $message->variables['!status']) {
      $status_class_name = strtolower(str_replace(' ', '-', $status));
      if ($status == 'Verified') {
        $icon = '<span class="icon-check-circle"></span>';
      }
      if ($status == 'False') {
        $icon = '<span class="icon-times-circle"></span>'; 
      }
      if ($status == 'Undetermined') {
        $icon = '<span class="icon-question-circle"></span>'; 
      }
      if ($status == 'In Progress') {
        // $icon = '<span class="icon-stack">';
        // $icon .= '<span class="icon-circle icon-stack-base"></span>';
        $icon = '<span class="icon-random"></span>'; 
        // $icon .= '</span>';
      }
    }

    // set actor / editor / user
    $actor = l($message->variables['!editor'], 'user/'. $message->uid, array('html' => TRUE, 'attributes' => array('class' => array('actor'))));
    $title = t('changed status to ');
    if (isset($icon)) {
      $title .= '<span class="media-status"><span class="icon">' . $icon . '</span>';
    }
    $title .= ' <span class="status-name ' . $status_class_name . '">' . strtolower($message->variables['!status']) . '</span></span>';
    
  }

  // set variables for publish_report
  if ($message->message_id == 'publish_report') {
    // set actor / editor / user / publisher
    $actor = l($message->variables['!publisher'], 'user/'. $message->uid, array('html' => TRUE, 'attributes' => array('class' => array('actor'))));
    $story = l($message->variables['!story'], $message->variables['!story_url'], array('html' => TRUE, 'attributes' => array('class' => array('story_link'))));
    $title = t('published on ') . $story;
  }

  // set variables for new_report
  if ($message->message_id == 'new_report') {
    // set actor / editor / user / publisher
    $actor = l($message->variables['!username'], 'user/'. $message->uid, array('html' => TRUE, 'attributes' => array('class' => array('actor'))));
    $title = t('added this report');
    // $title = t('Added ') . $message->variables['!title'];
  }

  // format status report as
  // Noha Aziz changed status to {status icon} verified (different color and add hover info on verified) {timestamp}

  // format comments as
  // Noha Aziz {comment} {timestamp}

  $output = '';
  $output = $avatar;

  $output .= t('<time title="!datetime" datetime="!datetime" class="timestamp">!inverval</time>', array(
      '!inverval' => checkdesk_core_custom_format_interval($message->timestamp),
      '!datetime' => format_date($message->timestamp, 'custom', t('l M d, Y \a\t g:i:sa'))
  ));


  if (isset($delete_footnote)) {
    $output .= $delete_footnote;
  }

  if(isset($actor)) {
    $output .= '<span>' . $actor . '</span> ';  
  }

  if(isset($title)) {
    $output .= '<span class="title">' . $title . '</span>';
  } elseif (isset($comment_text)) {
    $output .= '<span class="report-verification-footnote item-content-text">' . $comment_text . '</span>';
  } else {
    $output .= $message->message;
  }

  return $output;
}

/**
 * Returns HTML for a list or nested list of items with custom container id or class
 * If a container class or id isn't specified it will not create a wrapping div
 * See: https://api.drupal.org/api/drupal/includes%21theme.inc/function/theme_item_list/7
 */

function checkdesk_item_list($variables) {
  $items = $variables ['items'];
  $title = $variables ['title'];
  $type = $variables ['type'];
  $attributes = $variables ['attributes'];

  // set custom container id or class
  $container_class = isset($variables['container_class']) ? ' class="' . $variables['container_class'] . '"' : '';
  $container_id = isset($variables['container_id']) ? ' id="' . $variables['container_id'] . '"' : '';

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.

  // Add container id or class
  if (!empty($container_class) || !empty($container_id)) {
    $output = '<div' . $container_class . $container_id . '>';  
  } else {
    $output = '';
  }
  
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);
    $i = 0;
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes [$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }
      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }
      if ($i == 1) {
        $attributes ['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes ['class'][] = 'last';
      }
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }
    $output .= "</$type>";
  }
  if (!empty($container_class) || !empty($container_id)) {
    $output .= '</div>';
  }
  return $output;
}


/**
 * Helper function for determining whether an element is a button.
 *
 * @param array $element
 *   A renderable element.
 *
 * @return bool
 *   TRUE or FALSE.
 */
function _checkdesk_is_button($element) {
  return
    !empty($element['#type']) &&
    !empty($element['#value']) && (
      $element['#type'] === 'button' ||
      $element['#type'] === 'submit' ||
      $element['#type'] === 'image_button'
    );
}

/**
 * Helper function for adding colors to button elements.
 *
 * @param array $element
 *   The form element, passed by reference.
 */
function _checkdesk_colorize_button(&$element) {
  if (_checkdesk_is_button($element)) {
    // Do not add the class if one is already present in the array.
    $button_classes = array(
      'btn-default',
      'btn-primary',
      'btn-success',
      'btn-info',
      'btn-warning',
      'btn-danger',
      'btn-link',
    );
    $class_intersection = array_intersect($button_classes, $element['#attributes']['class']);
    if (empty($class_intersection)) {
      // Get the matched class.
      $class = _checkdesk_colorize_button_type($element);
      // If no particular class matched, use the default style.
      if (!$class) {
        $class = 'default';
      }
      $element['#attributes']['class'][] = 'btn-' . $class;
    }
  }
}
/**
 * Helper function for adding class to button elements based on the type.
 *
 * @param array $element
 *   The form element, passed by reference.
 */
function _checkdesk_colorize_button_type($element, $default = '') { 
  
  // Specify which button ids to set primary class for
  $primary_buttons_ids = array('edit-submit', 'edit-submit-desk-reports');
  
  // Add primary class to only pure submit buttons
  if(in_array($element['#id'], $primary_buttons_ids)) {
    return 'primary';
  }

  // Return the default if nothing was matched.
  return $default;

} 