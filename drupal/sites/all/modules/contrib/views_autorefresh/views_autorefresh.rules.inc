<?php

/**
 * @file
 * Rules integration for the views autorefresh module.
 */

/**
 * Implements hook_rules_action_info().
 */
function views_autorefresh_rules_action_info() {
  $items = array();
  $items['views_autorefresh'] = array(
      'label' => t('Autorefresh a View through Node.js'),
      'group' => t('Views Autorefresh'),
      'parameter' => array(
          'views' => array(
              'type' => 'list<integer>',
              'label' => t('Views'),
              'description' => t('Select one or more views that should refreshed.'),
              'options list' => 'views_autorefresh_get_nodejs_views',
          ),
      ),
      'base' => 'views_autorefresh_rules_process',
  );

  return $items;
}

/**
 * Action: Process and send Message to node.js.
 */
function views_autorefresh_rules_process($views) {
    views_autorefresh_nodejs_refresh($views);
}

/**
 * Helper function to get all views.
 */
function views_autorefresh_get_nodejs_views() {
  $eligable_views = array();
  $views = views_get_all_views();

  foreach ($views as $view) {
    // Skip disabled views or views without displays.
    if (!empty($views[$view->name]->disabled) || empty($view->display)) {
      continue;
    }

    foreach ($view->display as $id => $display) {
      if (isset($display->display_options['header']['autorefresh'])) {
        $eligable_views[$view->name] = $view->human_name;
        break;
      }
    }
  }
  natsort($eligable_views);
  return $eligable_views;
}
