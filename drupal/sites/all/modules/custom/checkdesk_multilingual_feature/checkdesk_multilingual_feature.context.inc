<?php
/**
 * @file
 * checkdesk_multilingual_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function checkdesk_multilingual_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'bilingual';
  $context->description = '';
  $context->tag = 'checkdesk';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'utility_menu',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('checkdesk');
  $export['bilingual'] = $context;

  return $export;
}
