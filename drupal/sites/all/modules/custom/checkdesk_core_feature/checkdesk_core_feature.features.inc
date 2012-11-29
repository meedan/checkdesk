<?php
/**
 * @file
 * checkdesk_core_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_core_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "heartbeat" && $api == "heartbeat") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function checkdesk_core_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function checkdesk_core_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Delete".
  $flags['delete'] = array(
    'entity_type' => 'node',
    'title' => 'Delete',
    'global' => '0',
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Request deletion',
    'flag_long' => '',
    'flag_message' => 'This report was flagged for deletion.',
    'unflag_short' => 'Cancel deletion request',
    'unflag_long' => '',
    'unflag_message' => 'This report was unflagged for deletion.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => '-6',
    'show_on_form' => 0,
    'access_author' => 'own',
    'show_contextual_link' => 1,
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to flag this report?',
    'unflag_confirmation' => 'Are you sure you want to unflag this report?',
    'module' => 'checkdesk_core_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Fact-checking".
  $flags['factcheck'] = array(
    'entity_type' => 'node',
    'title' => 'Fact-checking',
    'global' => '0',
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Flag for fact-checking',
    'flag_long' => '',
    'flag_message' => 'This report was flagged for fact-checking.',
    'unflag_short' => 'Unflag for fact-checking',
    'unflag_long' => '',
    'unflag_message' => 'This report was unflagged for fact-checking.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => '-7',
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to flag this report?',
    'unflag_confirmation' => 'Are you sure you want to unflag this report?',
    'module' => 'checkdesk_core_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Fact-checking (journalist)".
  $flags['factcheck_journalist'] = array(
    'entity_type' => 'node',
    'title' => 'Fact-checking (journalist)',
    'global' => '1',
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Turn on fact-checking',
    'flag_long' => '',
    'flag_message' => 'Fact-checking has been enabled for this report.',
    'unflag_short' => 'Turn off fact-checking',
    'unflag_long' => '',
    'unflag_message' => 'Fact-checking has been disabled for this report.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => '-10',
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'i18n' => 0,
    'module' => 'checkdesk_core_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Graphic content".
  $flags['graphic'] = array(
    'entity_type' => 'node',
    'title' => 'Graphic content',
    'global' => '0',
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Flag graphic content',
    'flag_long' => '',
    'flag_message' => 'This report was flagged as containing graphic content.',
    'unflag_short' => 'Unflag graphic content',
    'unflag_long' => '',
    'unflag_message' => 'This report was unflagged as containing graphic content.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => '-8',
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to flag this report?',
    'unflag_confirmation' => 'Are you sure you want to unflag this report?',
    'module' => 'checkdesk_core_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Graphic content (journalist)".
  $flags['graphic_journalist'] = array(
    'entity_type' => 'node',
    'title' => 'Graphic content (journalist)',
    'global' => '1',
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Flag graphic content',
    'flag_long' => '',
    'flag_message' => 'This report was flagged as containing graphic content.',
    'unflag_short' => 'Unflag graphic content',
    'unflag_long' => '',
    'unflag_message' => 'This report was unflagged as containing graphic content.',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => '-11',
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'i18n' => 0,
    'module' => 'checkdesk_core_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Spam".
  $flags['spam'] = array(
    'entity_type' => 'node',
    'title' => 'Spam',
    'global' => '0',
    'types' => array(
      0 => 'media',
    ),
    'flag_short' => 'Flag spam',
    'flag_long' => '',
    'flag_message' => 'This report was flagged as spam.',
    'unflag_short' => 'Unflag spam',
    'unflag_long' => '',
    'unflag_message' => 'This report was unflagged as spam.',
    'unflag_denied_text' => '',
    'link_type' => 'confirm',
    'weight' => '-9',
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 1,
    'show_on_page' => 1,
    'show_on_teaser' => 0,
    'i18n' => 0,
    'flag_confirmation' => 'Are you sure you want to flag this report?',
    'unflag_confirmation' => 'Are you sure you want to unflag this report?',
    'module' => 'checkdesk_core_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function checkdesk_core_feature_image_default_styles() {
  $styles = array();

  // Exported image style: navigation_avatar.
  $styles['navigation_avatar'] = array(
    'name' => 'navigation_avatar',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '24',
          'height' => '24',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function checkdesk_core_feature_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'post' => array(
      'name' => t('Liveblog Post'),
      'base' => 'node_content',
      'description' => t('A liveblog post.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
