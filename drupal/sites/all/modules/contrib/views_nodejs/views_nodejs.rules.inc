<?php

/**
 * @file
 * Rules integration for the views node.js module.
 */

/**
 * Implements hook_rules_action_info().
 */
function views_nodejs_rules_action_info() {
  $items = array();
  $items['views_nodejs'] = array(
    'label' => t('Views update'),
    'group' => t('node.js'),
    'parameter' => array(
      'views' => array(
        'type' => 'list<integer>',
        'label' => t('Views'),
        'description' => t('One can select views which need dynamical update.'),
        'options list' => 'views_nodejs_get_views',
      ),
    ),
    'base' => 'views_nodejs_rules_process',
  );

  return $items;
}


/**
 * Action: Process and send Message to node.js.
 */
function views_nodejs_rules_process($views) {

  foreach ($views as $view) {
    $view = unserialize($view);
    $view_update = (object) array(
      'channel' => 'views_nodejs_' . $view['name'] . $view['display_id'],
      'callback' => 'viewsNodejs',
      'view_id' => $view['name'],
      'display_id' => $view['display_id'],
    );
    // One can change some settings (or add new) which are
    // going to node.js channel.
    drupal_alter('views_nodejs_channel', $view_update);
    nodejs_send_content_channel_message($view_update);
  }

}


/**
 * Helper function to get all views.
 */
function views_nodejs_get_views() {
  $displays = array();
  $views = views_get_all_views();

  foreach ($views as $view) {
    // Skip disabled views or views without displays.
    if (!empty($views[$view->name]->disabled) || empty($view->display)) {
      continue;
    }

    foreach ($view->display as $id => $display) {
      $displays[serialize(array('name' => $view->name, 'display_id' => $id))] = $view->name . ' | ' . $id . ': ' . $display->display_title;
    }
  }
  natsort($displays);
  return $displays;
}
