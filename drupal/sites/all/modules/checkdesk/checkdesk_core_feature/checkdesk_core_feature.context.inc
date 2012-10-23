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
        'checkdesk_core-story_blogger' => array(
          'module' => 'checkdesk_core',
          'delta' => 'story_blogger',
          'region' => 'content',
          'weight' => '-10',
        ),
        'checkdesk_core-story_status' => array(
          'module' => 'checkdesk_core',
          'delta' => 'story_status',
          'region' => 'content',
          'weight' => '-9',
        ),
        'formblock-post' => array(
          'module' => 'formblock',
          'delta' => 'post',
          'region' => 'content',
          'weight' => '-8',
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
          'weight' => '-10',
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
