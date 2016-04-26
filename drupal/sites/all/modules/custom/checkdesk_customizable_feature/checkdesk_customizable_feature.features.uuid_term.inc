<?php
/**
 * @file
 * checkdesk_customizable_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function checkdesk_customizable_feature_uuid_features_default_terms() {
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
    'name' => 'Verified',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 3,
    'uuid' => '3c7ab283-8d43-4913-a293-0db16f025fb1',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'media_rating',
    'field_status_icon' => array(),
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
  $terms[] = array(
    'name' => 'In Progress',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 1,
    'uuid' => '502ab059-26b9-4947-92e5-3e1a6de4d91e',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'media_rating',
    'field_status_icon' => array(),
  );
  $terms[] = array(
    'name' => 'False',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 4,
    'uuid' => '547bb9d2-1dd3-4116-9001-61dfdf877a78',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'media_rating',
    'field_status_icon' => array(),
  );
  $terms[] = array(
    'name' => 'Not Applicable',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'a312dcad-5904-423c-9be9-d8537a2e72cb',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'media_rating',
    'field_status_icon' => array(),
    'path' => array(
      'pathauto' => 1,
    ),
  );
  $terms[] = array(
    'name' => 'Undetermined',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 2,
    'uuid' => 'ba27bacf-4d99-4c1d-bdce-a7fb35fafd43',
    'language' => 'und',
    'i18n_tsid' => 0,
    'vocabulary_machine_name' => 'media_rating',
    'field_status_icon' => array(),
  );
  return $terms;
}
