<?php
/**
 * @file
 * checkdesk_reports_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_reports_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "heartbeat" && $api == "heartbeat") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function checkdesk_reports_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function checkdesk_reports_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Needing deletion".
  $flags['delete'] = array(
    'entity_type' => 'node',
    'title' => 'Needing deletion',
    'global' => 0,
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Request deletion',
    'flag_long' => '',
    'flag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged for deletion.',
    'unflag_short' => 'Cancel deletion request',
    'unflag_long' => '',
    'unflag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged for deletion.',
    'unflag_denied_text' => 'Flagged for deletion',
    'link_type' => 'checkdesk_modal',
    'weight' => -6,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 'rss',
      'search_index' => 'search_index',
      'search_result' => 'search_result',
      'meedan_oembed' => 'meedan_oembed',
      'checkdesk_collaborate' => 'checkdesk_collaborate',
      'collaborate_status' => 'collaborate_status',
      'token' => 'token',
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => 'own',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'confirm_modal_style' => 'modal-popup-small',
    'flag_confirmation' => 'Are you sure you want to flag this report?',
    'unflag_confirmation' => 'Are you sure you want to unflag this report?',
    'module' => 'checkdesk_reports_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Needing fact-checking".
  $flags['factcheck'] = array(
    'entity_type' => 'node',
    'title' => 'Needing fact-checking',
    'global' => 0,
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Flag for fact-checking',
    'flag_long' => '',
    'flag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged for fact-checking.',
    'unflag_short' => 'Unflag for fact-checking',
    'unflag_long' => '',
    'unflag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged for fact-checking.',
    'unflag_denied_text' => 'Flagged for fact-checking',
    'link_type' => 'checkdesk_modal',
    'weight' => -7,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 'rss',
      'search_index' => 'search_index',
      'search_result' => 'search_result',
      'meedan_oembed' => 'meedan_oembed',
      'checkdesk_collaborate' => 'checkdesk_collaborate',
      'collaborate_status' => 'collaborate_status',
      'token' => 'token',
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'confirm_modal_style' => 'modal-popup-small',
    'flag_confirmation' => 'Are you sure you want to flag this report?',
    'unflag_confirmation' => 'Are you sure you want to unflag this report?',
    'module' => 'checkdesk_reports_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Needing fact-checking".
  $flags['factcheck_journalist'] = array(
    'entity_type' => 'node',
    'title' => 'Needing fact-checking',
    'global' => 1,
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Turn on fact-checking',
    'flag_long' => '',
    'flag_message' => 'Fact-checking has been enabled for <a href="[node:url:unaliased]">[node:author]\'s report</a>.',
    'unflag_short' => 'Turn off fact-checking',
    'unflag_long' => '',
    'unflag_message' => 'Fact-checking has been disabled for <a href="[node:url:unaliased]">[node:author]\'s report</a>.',
    'unflag_denied_text' => 'Fact-checking activated',
    'link_type' => 'toggle',
    'weight' => -10,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 'rss',
      'search_index' => 'search_index',
      'search_result' => 'search_result',
      'meedan_oembed' => 'meedan_oembed',
      'checkdesk_collaborate' => 'checkdesk_collaborate',
      'collaborate_status' => 'collaborate_status',
      'token' => 'token',
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'module' => 'checkdesk_reports_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Graphic content".
  $flags['graphic'] = array(
    'entity_type' => 'node',
    'title' => 'Graphic content',
    'global' => 0,
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Flag graphic content',
    'flag_long' => '',
    'flag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged as containing graphic content.',
    'unflag_short' => 'Unflag graphic content',
    'unflag_long' => '',
    'unflag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged as containing graphic content.',
    'unflag_denied_text' => 'Flagged for graphic content',
    'link_type' => 'checkdesk_modal',
    'weight' => -8,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 'rss',
      'search_index' => 'search_index',
      'search_result' => 'search_result',
      'meedan_oembed' => 'meedan_oembed',
      'checkdesk_collaborate' => 'checkdesk_collaborate',
      'collaborate_status' => 'collaborate_status',
      'token' => 'token',
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'confirm_modal_style' => 'modal-popup-small',
    'flag_confirmation' => 'Are you sure you want to flag this report?',
    'unflag_confirmation' => 'Are you sure you want to unflag this report?',
    'module' => 'checkdesk_reports_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Graphic content".
  $flags['graphic_journalist'] = array(
    'entity_type' => 'node',
    'title' => 'Graphic content',
    'global' => 1,
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Flag graphic content',
    'flag_long' => '',
    'flag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged as containing graphic content.',
    'unflag_short' => 'Unflag graphic content',
    'unflag_long' => '',
    'unflag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged as containing graphic content.',
    'unflag_denied_text' => 'Flagged for graphic content',
    'link_type' => 'toggle',
    'weight' => -11,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 'rss',
      'search_index' => 'search_index',
      'search_result' => 'search_result',
      'meedan_oembed' => 'meedan_oembed',
      'checkdesk_collaborate' => 'checkdesk_collaborate',
      'collaborate_status' => 'collaborate_status',
      'token' => 'token',
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'module' => 'checkdesk_reports_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Spam".
  $flags['spam'] = array(
    'entity_type' => 'node',
    'title' => 'Spam',
    'global' => 0,
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Flag spam',
    'flag_long' => '',
    'flag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was flagged as spam.',
    'unflag_short' => 'Unflag spam',
    'unflag_long' => '',
    'unflag_message' => '<a href="[node:url:unaliased]">[node:author]\'s report</a> was unflagged as spam.',
    'unflag_denied_text' => 'Flagged for spam',
    'link_type' => 'checkdesk_modal',
    'weight' => -9,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 'rss',
      'search_index' => 'search_index',
      'search_result' => 'search_result',
      'meedan_oembed' => 'meedan_oembed',
      'checkdesk_collaborate' => 'checkdesk_collaborate',
      'collaborate_status' => 'collaborate_status',
      'token' => 'token',
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'confirm_modal_style' => 'modal-popup-small',
    'flag_confirmation' => 'Are you sure you want to flag this report?',
    'unflag_confirmation' => 'Are you sure you want to unflag this report?',
    'module' => 'checkdesk_reports_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function checkdesk_reports_feature_node_info() {
  $items = array(
    'media' => array(
      'name' => t('Report'),
      'base' => 'node_content',
      'description' => t('A report containing a media item.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
