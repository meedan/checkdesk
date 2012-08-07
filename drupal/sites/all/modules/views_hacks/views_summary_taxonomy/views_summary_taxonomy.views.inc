<?php

/**
 * Implementation of hook_views_plugins().
 */
function views_summary_taxonomy_views_plugins() {
  return array(
    'style' => array(
      'taxonomy_summary' => array(
        'title' => t('Taxonomy'),
        'help' => t('Displays the summary as a taxonomy tree.'),
        'handler' => 'views_plugin_style_summary_taxonomy',
        'parent' => 'default_summary',
        'type' => 'summary', // only shows up as a summary style
        'uses options' => TRUE,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data_alter().
 */
function views_summary_taxonomy_views_data_alter(&$data) {
  $data['term_node']['term_node_tid_depth_summary'] = array(
    'group' => t('Taxonomy'),
    'title' => t('Term ID (with depth and summary)'),
    'help' => t('Taxonomy term argument that supports depth and summary view.'),
    'real field' => 'tid',
    'argument' => array(
      'handler' => 'views_handler_argument_term_node_tid_depth_summary',
      'accept depth modifier' => TRUE,
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function views_summary_taxonomy_views_handlers() {
  return array(
    'handlers' => array(
      'views_handler_argument_term_node_tid_depth_summary' => array(
        'parent' => 'views_handler_argument',
      ),
    ),
  );
}

