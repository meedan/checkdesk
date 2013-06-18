<?php
/**
 * @file
 * checkdesk_api_feature.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function checkdesk_api_feature_locale_default_languages() {
  $languages = array();

  // Exported language: en-NG.
  $languages['en-NG'] = array(
    'language' => 'en-NG',
    'name' => 'English (Checkdesk UI)',
    'native' => 'English (Checkdesk UI)',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'en-NG',
    'weight' => 0,
  );
  return $languages;
}
