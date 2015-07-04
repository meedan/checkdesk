<?php
/**
 * @file
 * checkdesk_core_feature.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function checkdesk_core_feature_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'generator' => array(
        'value' => 'Drupal 7 (http://drupal.org)',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
      'twitter:card' => array(
        'value' => 'summary',
      ),
      'twitter:description' => array(
        'value' => '[site:slogan]',
      ),
      'twitter:title' => array(
        'value' => '[site:name]',
      ),
      'twitter:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:summary]',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]?fbrefresh=[node:changed:raw]',
      ),
      'og:type' => array(
        'value' => 'article',
      ),
      'og:url' => array(
        'value' => '[current-page:url:absolute]?fbrefresh=[node:changed:raw]',
      ),
      'og:title' => array(
        'value' => '[node:title]',
      ),
      'og:description' => array(
        'value' => '[node:summary]',
      ),
      'og:updated_time' => array(
        'value' => '[node:changed:raw]',
      ),
      'twitter:title' => array(
        'value' => '[node:title]',
      ),
      'twitter:description' => array(
        'value' => '[node:summary]',
      ),
    ),
  );

  // Exported Metatag config instance: node:discussion.
  $config['node:discussion'] = array(
    'instance' => 'node:discussion',
    'config' => array(
      'og:image' => array(
        'value' => '[node:field_lead_image]',
      ),
      'twitter:image' => array(
        'value' => '[node:field_lead_image]',
      ),
    ),
  );

  // Exported Metatag config instance: node:media.
  $config['node:media'] = array(
    'instance' => 'node:media',
    'config' => array(
      'description' => array(
        'value' => '[node:body]',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]?fbrefresh=[node:changed:raw]',
      ),
      'twitter:description' => array(
        'value' => '[node:body]',
      ),
    ),
  );

  // Exported Metatag config instance: node:page.
  $config['node:page'] = array(
    'instance' => 'node:page',
    'config' => array(
      'og:image' => array(
        'value' => '[theme:frontpage_logo_path]',
      ),
      'twitter:image' => array(
        'value' => '[theme:frontpage_logo_path]',
      ),
    ),
  );

  return $config;
}
