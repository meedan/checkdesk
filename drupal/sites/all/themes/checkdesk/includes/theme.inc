<?php 

/**
 * Returns HTML for a set of links.
 */
function checkdesk_checkdesk_links($variables) {

  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  //$dropdown = $variables['dropdown'];

  global $language_url;
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
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_links) {
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

      $attributes['class'][] = (count($children) > 0) ? 'dropdown' : NULL;
      $output .= '<li' . drupal_attributes(array('class' => $attributes['class'])) . '>';

      if (isset($link['href'])) {
        if(count($children) > 0) { 
          $link['html'] = TRUE;
          $link['title'] .= '<b class="caret"></b>';
          $output .=  '<a' . drupal_attributes($link['attributes']) . ' href="#">'. $link['title'] .'</a>';
        } else {
          if($link['href'] == '<front>') {
            $output .= '<a href="' . url('<front>') . '"><span class="icon-home"></span></a>';
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
 */
function checkdesk_css_alter(&$css) {  
  $excludes = _checkdesk_alter(checkdesk_theme_get_info('exclude'), 'css');
  $css = array_diff_key($css, $excludes);
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
  $node = $variables['node'];
  $title = '';

  // status report
  if($message->message_id == 'status_report') {
    if($status = $message->variables['!status']) {
      if($status == 'Verified') {
        $icon = '<span class="icon-ok-sign"></span>';
        $status_class = 'verified';
        $title = 'Status set to '. $message->variables['!status'] . ' by ' . $message->variables['!editor'];
      }
    }
  }

  // comment 
  if($message->message_id == 'new_comment_report') {
    $title = $message->variables['!username'] . ' said:';
  }

  // new_report 
  if($message->message_id == 'new_report') {
    $title = $message->variables['!title'] . ' added by ' . $message->variables['!username'];
  }


  $output = '';

  $user = user_load($message->uid);
  $output .= '<header>';
  if(isset($status_class)) {
    $output .= $icon;
  }
  $output .= '<span class="time">' . format_interval(time()-$message->timestamp) . ' ago</span>';
  $output .= '<span class="title">' . $title . '</span>';
  $output .= '</header>';
  if(isset($message->variables['!comment'])) {
    $output .= '<div class="message">' . $message->variables['!comment'] . '</div>';
  }

  return $output;
}

