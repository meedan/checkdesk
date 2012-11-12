<?php
/**
 * @file
 * checkdesk_core_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function checkdesk_core_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all';
  $context->description = 'All pages';
  $context->tag = 'checkdesk';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-my_notifications-block' => array(
          'module' => 'views',
          'delta' => 'my_notifications-block',
          'region' => 'navigation',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('All pages');
  t('checkdesk');
  $export['all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'desk';
  $context->description = 'Story page';
  $context->tag = 'checkdesk';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'discussion' => 'discussion',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-desk_reports-block' => array(
          'module' => 'views',
          'delta' => 'desk_reports-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'checkdesk_core-post' => array(
          'module' => 'checkdesk_core',
          'delta' => 'post',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-desk_updates-block' => array(
          'module' => 'views',
          'delta' => 'desk_updates-block',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Story page');
  t('checkdesk');
  $export['desk'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'report';
  $context->description = 'Report page';
  $context->tag = 'checkdesk';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'media' => 'media',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-activity_report-block' => array(
          'module' => 'views',
          'delta' => 'activity_report-block',
          'region' => 'content',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Report page');
  t('checkdesk');
  $export['report'] = $context;

  return $export;
}
