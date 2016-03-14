<?php
/**
 * @file
 * checkdesk_core_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function checkdesk_core_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
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
function checkdesk_core_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function checkdesk_core_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow story".
  $flags['follow_story'] = array(
    'entity_type' => 'node',
    'title' => 'Follow story',
    'global' => 0,
    'types' => array(
      0 => 'discussion',
    ),
    'flag_short' => 'Follow story',
    'flag_long' => 'Follow a story to stay up to date with the latest developments',
    'flag_message' => '',
    'unflag_short' => 'Following story',
    'unflag_long' => 'Unfollow story',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'checkdesk_collaborate' => 'checkdesk_collaborate',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'meedan_oembed' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
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

  // Exported image style: featured_image.
  $styles['featured_image'] = array(
    'label' => 'featured_image',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 720,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: featured_image_med.
  $styles['featured_image_med'] = array(
    'label' => 'featured_image_med',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 550,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: featured_image_small.
  $styles['featured_image_small'] = array(
    'label' => 'featured_image_small',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 350,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: featured_stories_lead_image.
  $styles['featured_stories_lead_image'] = array(
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 360,
          'height' => 220,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'featured_stories_lead_image',
  );

  // Exported image style: footer_partner_logo.
  $styles['footer_partner_logo'] = array(
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 150,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'footer_partner_logo',
  );

  // Exported image style: header_logo.
  $styles['header_logo'] = array(
    'label' => 'header_logo',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 36,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: item_image_large.
  $styles['item_image_large'] = array(
    'label' => 'item_image_large',
    'effects' => array(
      7 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 880,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
      8 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 700,
          'height' => 420,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: item_image_list.
  $styles['item_image_list'] = array(
    'label' => 'item_image_list',
    'effects' => array(
      19 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 180,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      20 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 160,
          'height' => 96,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: item_image_list_small.
  $styles['item_image_list_small'] = array(
    'label' => 'item_image_list_small',
    'effects' => array(
      11 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 140,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      12 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 120,
          'height' => 72,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: item_image_medium.
  $styles['item_image_medium'] = array(
    'label' => 'item_image_medium',
    'effects' => array(
      15 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 555,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      16 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 520,
          'height' => 312,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: item_image_small.
  $styles['item_image_small'] = array(
    'label' => 'item_image_small',
    'effects' => array(
      17 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 240,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      18 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 220,
          'height' => 132,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: navigation_avatar.
  $styles['navigation_avatar'] = array(
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 24,
          'height' => 24,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'navigation_avatar',
  );

  // Exported image style: partner_logo.
  $styles['partner_logo'] = array(
    'label' => 'partner_logo',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 235,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: report_thumbnail.
  $styles['report_thumbnail'] = array(
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 350,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 320,
          'height' => 144,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
    'label' => 'report_thumbnail',
  );

  // Exported image style: status_icon.
  $styles['status_icon'] = array(
    'label' => 'status icon',
    'effects' => array(
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 16,
          'height' => 16,
        ),
        'weight' => 2,
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
    'discussion' => array(
      'name' => t('Story'),
      'base' => 'node_content',
      'description' => t('Where reports are verified and blog posts created.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'post' => array(
      'name' => t('Update'),
      'base' => 'node_content',
      'description' => t('A liveblog post.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
