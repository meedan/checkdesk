<?php
/**
 * @file views_flipped_table.views.inc
 * Contains the flipped table style plugin, flipping rows and columns.
 */

/**
 * Implementation of hook_views_plugins().
 */
function views_flipped_table_views_plugins() {
  return array(
    'style' => array(
      'flipped' => array(
        'title' => t('Flipped table'),
        'help' => t('Displays a table with rows and columns flipped.'),
        'handler' => 'views_flipped_table_plugin_style_flipped_table',
        'parent' => 'table',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'theme' => 'views_flipped_table',
        'even empty' => TRUE,
      ),
    ),
  );
}