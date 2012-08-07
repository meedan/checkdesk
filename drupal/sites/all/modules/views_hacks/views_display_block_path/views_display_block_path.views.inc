<?php

/**
 * Implementation of hook_views_plugins().
 */
function views_display_block_path_views_plugins() {
  return array(
    'display' => array(
      'block_path' => array(
        'title' => t('Block Path'),
        'help' => t('Extend standard block display with a URL path.'),
        'handler' => 'views_plugin_display_block_path',
        'parent' => 'block',
        'theme' => 'views_view',
        'uses hook block' => TRUE,
        'use ajax' => TRUE,
        'use pager' => TRUE,
        'use more' => TRUE,
        'accept attachments' => TRUE,
        'admin' => t('Block Path'),
      ),
    ),
  );
}

