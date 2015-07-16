<?php

function checkdesk_menu_tree(&$variables) {
  return '<ul class="menu nav">' . $variables['tree'] . '</ul>';
}

/**
 * Returns HTML for primary and secondary local tasks.
 */
function checkdesk_menu_local_tasks(&$variables) {
  $output = '';

  if ( !empty($variables['primary']) ) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['primary']['#prefix'] = '<ul class="nav admin-nav-tabs">';
    $variables['primary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['primary']);
  }

  if ( !empty($variables['secondary']) ) {
    $variables['primary']['#prefix'] = '<h2 class="element-invisible">' . t('Primary tabs') . '</h2>';
    $variables['secondary']['#prefix'] = '<ul class="nav nav-pills">';
    $variables['secondary']['#suffix'] = '</ul>';
    $output .= drupal_render($variables['secondary']);
  }

  return $output;
}


/**
 * Returns HTML for primary and secondary local tasks.
 *
 * @ingroup themeable
 */
function checkdesk_menu_local_task($variables) {
  
  $link = $variables['element']['#link'];
  $link_text = $link['title'];
  $classes = array();

  if (!empty($variables['element']['#active'])) {
    // Add text to indicate active tab for non-visual users.
    $active = '<span class="element-invisible">' . t('(active tab)') . '</span>';

    // If the link does not contain HTML already, check_plain() it now.
    // After we set 'html'=TRUE the link will not be sanitized by l().
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }
    $link_text = t('!local-task-title!active', array('!local-task-title' => $link['title'], '!active' => $active));
    $classes[] = 'active';
  }

  $link['localized_options']['html'] = TRUE;

  // add admin tabs css
  drupal_add_css(
    drupal_get_path('theme', 'checkdesk') . '/assets/css/components/admin_nav.css',
    array(
      'scope' => 'footer',
      'group' => CSS_THEME,
      'weight' => '9999',
      'every_page' => FALSE,
    )
  );

  // add icons
  // view tab
  $icon = '';
  if($link['path'] == 'node/%/view') {
    $icon = '<span class="icon-file"></span> ';
  }
  // edit tab
  if($link['path'] == 'node/%/edit') {
    $icon = '<span class="icon-pencil"></span> ';
  }
  // add to tab
  if($link['path'] == 'node/%/nodequeue') {
    $icon = '<span class="icon-plus"></span> ';
  }
  // delete tab
  if($link['path'] == 'node/%/delete') {
    $icon = '<span class="icon-trash-o"></span> ';
  }
  // devel tab
  if($link['path'] == 'node/%/devel') {
    $icon = '<span class="icon-wrench"></span> ';
  }
  // devel tab
  if($link['path'] == 'node/%/collaboration') {
    $icon = '<span class="icon-group"></span> ';
  }
  if(isset($icon)) {
    $link_text = $icon . $link_text;  
  }
  

  return '<li class="' . implode(' ', $classes) . '">' . l($link_text, $link['href'], $link['localized_options']) . "</li>\n";
}