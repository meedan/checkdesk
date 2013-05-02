<?php
/**
 * @file
 * checkdesk_featured_stories_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function checkdesk_featured_stories_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'featured_stories';
  $context->description = 'Featured stories on the front page';
  $context->tag = 'checkdesk';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-featured_stories-block' => array(
          'module' => 'views',
          'delta' => 'featured_stories-block',
          'region' => 'widgets',
          'weight' => '-22',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Featured stories on the front page');
  t('checkdesk');
  $export['featured_stories'] = $context;

  return $export;
}
