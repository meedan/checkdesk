<?php
/**
 * @file
 * checkdesk_core_feature.default_demo_tour_presets.inc
 */

/**
 * Implements hook_default_demo_tour_presets().
 */
function checkdesk_core_feature_default_demo_tour_presets() {
  $export = array();

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'citizen';
  $preset->title = 'Citizen';
  $preset->roles = array(
    4 => '4',
    1 => 0,
    2 => 0,
    3 => 0,
    5 => 0,
  );
  $preset->paths = '';
  $preset->steps = array(
    0 => array(
      'element' => '#menu-submit-report',
      'title' => 'Submit Report',
      'content' => 'Send us newsworthy links from social media; we\'ll fact-check and publish them.',
    ),
    1 => array(
      'element' => '#my-notifications-menu-link',
      'title' => 'Notifications',
      'content' => 'You will be notified here when your reports are published or fact-checked.',
    ),
    2 => array(
      'element' => '#user-menu',
      'title' => 'Profile',
      'content' => 'Complete your profile (add a profile pic!) and edit your settings.',
    ),
  );
  $preset->auto = 1;
  $export['citizen'] = $preset;

  $preset = new stdClass();
  $preset->disabled = FALSE; /* Edit this to true to make a default preset disabled initially */
  $preset->api_version = 1;
  $preset->name = 'journalist';
  $preset->title = 'Journalist';
  $preset->roles = array(
    5 => '5',
    1 => 0,
    2 => 0,
    3 => 0,
    4 => 0,
  );
  $preset->paths = '';
  $preset->steps = array(
    0 => array(
      'element' => '#discussion-form-menu-link',
      'title' => 'Create a Story',
      'content' => 'Pen a headline and brief intro about the topic. Include a featured image, and start adding updates!',
    ),
    1 => array(
      'element' => '#menu-submit-report',
      'title' => 'Submit Report',
      'content' => 'Quickly add newsworthy links from social media. Then you can fact-check and publish them.',
    ),
    2 => array(
      'element' => '#update-story-menu-link',
      'title' => 'Update a Story',
      'content' => 'A story begins with your first update. Then add more updates as the story evolves.',
    ),
    3 => array(
      'element' => '#my-notifications-menu-link',
      'title' => 'Notifications',
      'content' => 'You will be notified here when users submit reports to a story, or flag published reports for fact-checking.',
    ),
    4 => array(
      'element' => '#user-menu',
      'title' => 'Complete Your Profile',
      'content' => 'Complete your profile (add a profile pic!) and edit your settings.',
    ),
  );
  $preset->auto = 1;
  $export['journalist'] = $preset;

  return $export;
}
