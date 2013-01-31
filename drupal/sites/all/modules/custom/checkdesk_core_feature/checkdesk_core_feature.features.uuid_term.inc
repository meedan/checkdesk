<?php
/**
 * @file
 * checkdesk_core_feature.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function checkdesk_core_feature_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Verified',
    'description' => '',
    'format' => 'liveblog',
    'weight' => '3',
    'uuid' => '3c7ab283-8d43-4913-a293-0db16f025fb1',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'media_rating',
  );
  $terms[] = array(
    'name' => 'In Progress',
    'description' => '',
    'format' => 'liveblog',
    'weight' => '1',
    'uuid' => '502ab059-26b9-4947-92e5-3e1a6de4d91e',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'media_rating',
  );
  $terms[] = array(
    'name' => 'False',
    'description' => '',
    'format' => 'liveblog',
    'weight' => '4',
    'uuid' => '547bb9d2-1dd3-4116-9001-61dfdf877a78',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'media_rating',
  );
  $terms[] = array(
    'name' => 'Not Applicable',
    'description' => '',
    'format' => 'liveblog',
    'weight' => '0',
    'uuid' => 'a312dcad-5904-423c-9be9-d8537a2e72cb',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'media_rating',
  );
  $terms[] = array(
    'name' => 'Undetermined',
    'description' => '',
    'format' => 'liveblog',
    'weight' => '2',
    'uuid' => 'ba27bacf-4d99-4c1d-bdce-a7fb35fafd43',
    'language' => 'und',
    'i18n_tsid' => '0',
    'vocabulary_machine_name' => 'media_rating',
  );
  return $terms;
}
