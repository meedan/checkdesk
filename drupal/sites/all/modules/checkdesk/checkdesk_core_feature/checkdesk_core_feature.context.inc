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
  $context->description = '';
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
        'formblock-post' => array(
          'module' => 'formblock',
          'delta' => 'post',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-desk_reports-block' => array(
          'module' => 'views',
          'delta' => 'desk_reports-block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('checkdesk');
  $export['desk'] = $context;

  return $export;
}
