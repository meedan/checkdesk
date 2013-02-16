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

      if(count($children) > 0) {
        $attributes['class'][] = 'dropdown';
        $link['attributes']['data-toggle'] = 'dropdown';
        $link['attributes']['class'][] = 'dropdown-toggle';
      }

      if(!isset($link['attributes']))
        $link['attributes'] = array();

      $output .= '<li' . drupal_attributes(array('class' => $attributes['class'])) . '>';

      if (isset($link['class'])) {
        if (!isset($link['attributes']['class'])) $link['attributes']['class'] = array();
        $link['attributes']['class'] = array_merge($link['attributes']['class'], $link['class']);
      }

      if (isset($link['href'])) {
        if(count($children) > 0) { 
          $link['html'] = TRUE;
          $link['title'] .= '<b class="caret"></b>';
          $output .=  '<a' . drupal_attributes($link['attributes']) . ' href="#">'. $link['title'] .'</a>';
        } else {
          // add home icon for homepage menu item link
          if($link['href'] == '<front>') {
            $output .= '<a href="' . url('<front>') . '"><span class="icon-home"></span></a>';
          } 
          // add notifications panel as drop down
          elseif($link['href'] == 'my-notifications') {
            $link['attributes']['class'][] = 'dropdown-toggle';
            $link['attributes']['data-toggle'] = 'dropdown';
            $output .= l($link['title'], $link['href'], $link);
            $output .= '<div id="my-notifications" class="dropdown-menu">';
            checkdesk_notifications_load_js();
            $block = module_invoke('views', 'block_view', 'my_notifications-block');
            @$block['content']['#markup'] .= '<p class="notifications-settings-link">' . l(t('Settings'), url('user/' . $user->uid . '/notifications', array('absolute' => TRUE))) . '</p>';
            $output .= render($block['content']);
            $output .= '</div>';
          } else {
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
  // Excludes from .info
  $excludes = _checkdesk_alter(checkdesk_theme_get_info('exclude'), 'css');

  $pattern = str_replace('/', '\/', implode('|', array_keys($excludes)));
  foreach ($css as $path => $data) {
    if (preg_match("/^($pattern)/", $path)) unset($css[$path]);
  }
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
function checkdesk_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );

  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= "<div class=\"alert alert-block alert-$type\">\n";
    $output .= "  <a class=\"close\" data-dismiss=\"alert\" href=\"#\">x</a>\n";

    if (!empty($status_heading[$type])) {
      $output .= '<h4 class="alert-heading">' . $status_heading[$type] . "</h4>\n";
    }

    if (count($messages) > 1) {
      $output .= " <ul>\n";
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . "</li>\n";
      }
      $output .= " </ul>\n";
    }
    else {
      $output .= $messages[0];
    }

    $output .= "</div>\n";
  }
  return $output;
}

function checkdesk_checkdesk_heartbeat_content($variables) {
  $message = $variables['message'];

  // status report
  if ($message->message_id == 'status_report') {
    if ($status = $message->variables['!status']) {
      if ($status == 'Verified') {
        $icon = '<span class="icon-ok-sign"></span>';
      }
    }
  }

  $output = '';
  $output .= '<header>';
  if (isset($icon)) {
    $output .= $icon;
  }
  $output .= '<time class="time" title=' . format_date($message->timestamp, 'custom', 'Y-m-d')  .'>' . _theme_time_ago($message->timestamp) . '</time>';
  $output .= '<span class="title">' . $message->message . '</span>';
  $output .= '</header>';
  return $output;
}

