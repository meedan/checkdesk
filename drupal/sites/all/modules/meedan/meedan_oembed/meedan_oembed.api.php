<?php

/**
 * @file
 * Hooks provided by the Meedan oEmbed module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Define oembed scraping bridge callbacks for domains which do not
 * support oembed.
 */
function hook_meedan_oembed() {
  return array(
    // The domain to add support for, ex: example.com -> 'example'
    'example' => array(
      'callback' => 'my_module_example_handler'
    )
  );
}

/**
 * Scrape page to extract oEmbed-relevent information.
 */
function my_module_example_handler(&$embed) {
  $embed->favicon_link = _meedan_oembed_fetch_favicon($embed->original_url);
  if (empty($embed->thumbnail_url)) {
    $embed->thumbnail_url = url(drupal_get_path('module', 'meedan_oembed') . '/theme/thumbnail.png', array('absolute' => TRUE, 'language' => (object) array('language' => FALSE)));
  }
}

/**
 * @} End of "addtogroup hooks".
 */
