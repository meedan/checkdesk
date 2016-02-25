<?php
/**
 * @file
 * checkdesk_reports_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function checkdesk_reports_feature_context_default_contexts() {
  $export = array();

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
  $context->reactions = array();
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Report page');
  t('checkdesk');
  $export['report'] = $context;

  return $export;
}
