<?php
/**
 * @file
 * checkdesk_sources_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function checkdesk_sources_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Sockpuppet',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '1f826df0-ed70-4dc7-b320-add71b9c0dc0',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'source_status',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Not Credible',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '24d1fc3f-6913-4880-b1f8-cb2a5cb63745',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'source_status',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Slightly Credible',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '448e6370-f504-4136-8bf2-51a65906eabb',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'source_status',
    'path' => array(
      'pathauto' => 1,
    ),
  );
  return $terms;
}
