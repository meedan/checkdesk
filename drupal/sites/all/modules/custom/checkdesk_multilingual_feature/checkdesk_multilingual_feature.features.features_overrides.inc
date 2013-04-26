<?php
/**
 * @file
 * checkdesk_multilingual_feature.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function checkdesk_multilingual_feature_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: views_view
  $overrides["views_view.liveblog.display|default|display_options|filters|language"] = array(
    'id' => 'language',
    'table' => 'node',
    'field' => 'language',
    'value' => array(
      '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    ),
  );
  $overrides["views_view.stories_for_updates.display|default|display_options|filters|language"] = array(
    'id' => 'language',
    'table' => 'node',
    'field' => 'language',
    'value' => array(
      '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    ),
  );

 return $overrides;
}
