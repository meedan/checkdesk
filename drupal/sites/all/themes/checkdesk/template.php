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

  // Information menu
  $info_menu = menu_load('menu-information');
  $tree = menu_tree_page_data($info_menu['menu_name']);

  // Add modal class for first-level children
  foreach ($tree as $pid => $parent) {
    foreach ($parent['below'] as $cid => $item) {
      $tree[$pid]['below'][$cid]['link']['class'] = array('ctools-use-modal');
    }
  }
  // Load the modal library and add the modal javascript.
  ctools_include('modal');
  ctools_modal_add_js();
  $variables['info_menu'] = checkdesk_menu_navigation_links($tree);
  $variables['info_nav'] = theme('checkdesk_links', array(
    'links' => $variables['info_menu'],
    'attributes' => array(
      'id' => 'info-menu',
      'class' => array('nav', 'pull-right'),
    ),
    'heading' => array(
      'text' => t('Information menu'),
      'level' => 'h2',
      'class' => array('element-invisible'),
    ),
  ));

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
  if ($variables['type'] == 'media') {
    //Add author info to variables
    $user_picture = $variables['elements']['#node']->picture;
    if (!empty($user_picture)) {
      $options = array(
        'html' => TRUE,
        'attributes' => array(
          'class' => 'gravatar'
        )    
      );
      $variables['user_avatar'] = l(theme('image_style', array('path' => $user_picture->uri, 'alt' => t(check_plain($variables['elements']['#node']->name)), 'style_name' => 'navigation_avatar')), 'user/'. $variables['uid'], $options);
    }
    //Add node creation info(author name plus creation time)
    $variables['media_creation_info'] = l($variables['elements']['#node']->name, 'user/'. $variables['uid']) . t(' added this ') .
      '<time class="time-ago" pubdate datetime="'. format_date($variables['created'], 'custom', 'Y-m-d\TH:i:sP') .'">' .
      format_interval(time()-$variables['created']) . t('ago') .'</time>';
    //Add activity report with status
    $view = views_get_view('activity_report');
    $view->set_arguments(array($variables['nid']));
    $view_output = $view->preview('block');
    $total_rows = count($view->result);
    $view->destroy();
    if ($total_rows) {
      $variables['media_activity_report_count'] = $total_rows;
      $variables['media_activity_report'] = $view_output;
      $status_name = $variables['field_rating'][0]['taxonomy_term']->name;
      if ($status_name == 'Verified') {
        $status_class = 'verified';
        $icon = '<i class="icon-ok-sign"></i> ';
      }
      elseif ($status_name == 'Undetermined') {
        $status_class = 'undetermined';
        $icon = '<i class="icon-question-sign"></i> ';
      }
      elseif ($status_name == 'False') {
        $status_class = 'false';
        $icon = '<i class="icon-remove-sign"></i> ';
      }
      elseif($status_name == 'Not Applicable') {
        $status_class = '';
        $icon = '';
      }
      $variables['status_class'] = $status_class;
      $variables['status_icon'] = $icon . t($status_name);
    }
  }
}

function checkdesk_links__node($variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];

  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();

  $class[] = 'report-actions';
  $output = '';

  if (count($links) > 0) {
    $output = '<ul' . drupal_attributes(array('class' => $class)) . '>';

    if (isset($links['checkdesk-suggest']) || 
        isset($links['checkdesk-edit']) || 
        isset($links['checkdesk-delete']) ||
        isset($links['flag-factcheck_journalist']) ||
        isset($links['flag-graphic_journalist'])
    ) {
      // Add to
      $output .= '<li class="add-to dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-edit"></i></a>';
      $output .= '<ul class="dropdown-menu">';
      if (isset($links['checkdesk-suggest'])) {
        $name = t('Add to story');
        // Create a path for the url that is like our hook_menu() declaration above.
        $href = 'modal/suggest/nojs/';
        // Here's the ctools function that generates the trigger inside the link
        // ctools_modal_text_button($text, $dest, $alt, $class = '')
        // http://api.drupalize.me/api/drupal/function/ctools_modal_text_button/7
        // IMPORTANT: Include ctools-modal-[your declared style name] as a class so 
        // Ctools knows what Javascript settings to use in generating the modal:
        $suggest_link = ctools_modal_text_button($name, $href, t('Add to story'),  'ctools-modal-cd-style');
        // $output .= '<li>' . l($links['checkdesk-suggest']['title'], $links['checkdesk-suggest']['href'], $links['checkdesk-suggest']) .'</li>';
        $output .= '<li>' . $suggest_link .'</li>';
      }
      if (isset($links['checkdesk-edit'])) {
        $output .= '<li>' . l($links['checkdesk-edit']['title'], $links['checkdesk-edit']['href'], $links['checkdesk-edit']) .'</li>';
      }
      if (isset($links['checkdesk-delete'])) {
        $output .= '<li>' . l($links['checkdesk-delete']['title'], $links['checkdesk-delete']['href'], $links['checkdesk-edit']) .'</li>';
      }
      if (isset($links['flag-factcheck_journalist'])) {
        $output .= '<li>' . l($links['flag-factcheck_journalist']['title'], @$links['flag-factcheck_journalist']['href'], $links['flag-factcheck_journalist']) .'</li>';
      }
      if (isset($links['flag-graphic_journalist'])) {
        $output .= '<li>' . l($links['flag-graphic_journalist']['title'], @$links['flag-graphic_journalist']['href'], $links['flag-graphic_journalist']) .'</li>';
      }
      $output .= '</ul></li>';
    }

    if (isset($links['flag-spam']) || 
        isset($links['flag-graphic']) || 
        isset($links['flag-factcheck'] || 
        isset($links['flag-delete'])
    ) {
      // Flag as
      $output .= '<li class="flag-as dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-flag"></i> Flag</a>';
      $output .= '<ul class="dropdown-menu">';
      if (isset($links['flag-spam'])) {
        $output .= '<li>' . l($links['flag-spam']['title'], @$links['flag-spam']['href'], $links['flag-spam']) . '</li>';
      }
      if (isset($links['flag-graphic'])) {
        $output .= '<li>' . l($links['flag-graphic']['title'], @$links['flag-graphic']['href'], $links['flag-graphic']) . '</li>';
      }
      if (isset($links['flag-factcheck'])) {
        $output .= '<li>' . l($links['flag-factcheck']['title'], @$links['flag-factcheck']['href'], $links['flag-factcheck']) . '</li>';
      }
      if (isset($links['flag-delete'])) {
        $output .= '<li>' . l($links['flag-delete']['title'], @$links['flag-delete']['href'], $links['flag-delete']) . '</li>';
      }
      $output .= '</ul></li>'; 
    }
    
    if (isset($links['checkdesk-share-facebook']) || 
        isset($links['checkdesk-share-twitter']) || 
        isset($links['checkdesk-share-google'])
    ) {
      // Share on
      $output .= '<li class="share-on dropdown">';
      $output .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-share"></i> Share</a>';
      $output .= '<ul class="dropdown-menu">';
      if (isset($links['checkdesk-share-facebook'])) {
        $output .= '<li>' . l($links['checkdesk-share-facebook']['title'], $links['checkdesk-share-facebook']['href'], $links['checkdesk-share-facebook']) . '</li>';
      }
      if (isset($links['checkdesk-share-twitter'])) {
        $output .= '<li>' . l($links['checkdesk-share-twitter']['title'], $links['checkdesk-share-twitter']['href'], $links['checkdesk-share-twitter']) . '</li>';
      }
      if (isset($links['checkdesk-share-google'])) {
        $output .= '<li>' . l($links['checkdesk-share-google']['title'], $links['checkdesk-share-google']['href'], $links['checkdesk-share-google']) . '</li>';
      }
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
  $form['actions']['submit']['#value'] = t('Add footnote');
}

function checkdesk_field__field_rating(&$variables) {
  $output = '';
  foreach($variables['items'] as $key => $tag) {
      $output = $tag['#title']; 
  }
  return $output;
}
