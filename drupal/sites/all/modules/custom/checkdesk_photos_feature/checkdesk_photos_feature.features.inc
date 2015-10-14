<?php
/**
 * @file
 * checkdesk_photos_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_photos_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function checkdesk_photos_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function checkdesk_photos_feature_image_default_styles() {
  $styles = array();

  // Exported image style: inline_image_large.
  $styles['inline_image_large'] = array(
    'label' => 'inline_image_large',
    'effects' => array(
      21 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 660,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: inline_image_medium.
  $styles['inline_image_medium'] = array(
    'label' => 'inline_image_medium',
    'effects' => array(
      22 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 605,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: inline_image_small.
  $styles['inline_image_small'] = array(
    'label' => 'inline_image_small',
    'effects' => array(
      23 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 445,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
