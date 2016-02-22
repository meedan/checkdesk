<?php

/**
 * Template preprocessor for `checkdesk_core_story_blogger`.
 */
function checkdesk_core_preprocess_checkdesk_core_story_blogger(&$variables) {
  $story = $variables['story'];
  $author = user_load($story->uid);
  $variables['blogger_picture'] = theme('user_picture', array('account' => $author));
  $variables['blogger_name'] = theme('username', array('account' => $author));
  $online = checkdesk_core_user_online($author);
  $factchecking = checkdesk_core_fact_checking($story);
  $variables['blogger_status_class'] = $online ? 'story-blogger-status-online' : 'story-blogger-status-offline';
  $variables['blogger_status_text'] = $online ?
    ($factchecking ? t('I\'m online and fact-checking new reports.') : t('I\'m online.')) :
    t('I\'m offline.');
}

/**
 * Template preprocessor for `checkdesk_core_story_status`.
 */
function checkdesk_core_preprocess_checkdesk_core_story_status(&$variables) {
  $story = $variables['story'];
  $site_owner = variable_get('checkdesk_site_owner', '');
  $site_owner_url = variable_get('checkdesk_site_owner_url', '');
  if (checkdesk_core_fact_checking($story)) {
    $variables['story_status'] = t('A <span class="story-status-factchecking">fact-checking</span> blog by <a href="@url">!owner</a>.', array(
      '@url' => url($site_owner_url, array('external' => TRUE)),
      '!owner' => $site_owner,
    ));
  }
  else {
    $variables['story_status'] = t('A blog by <a href="@url">!owner</a>.', array(
      '@url' => url($site_owner_url, array('external' => TRUE)),
      '!owner' => $site_owner,
    ));
  }
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  $country_list = country_get_list();
  $country = $country_list[ variable_get('site_default_country', '') ];
  list($continent, $city) = explode('/', variable_get('date_default_timezone'), 2);
  $variables['story_context'] = t('Currently @date in !city, !country.', array(
    '@date' => format_date(time(), 'custom', t('g:ia')),
    '!city' => $city,
    '!country' => $country,
  ));
}

/**
 * Template preprocessor for `checkdesk_core_story_drafts`.
 */
function checkdesk_core_preprocess_checkdesk_core_story_drafts(&$variables) {
  $story = $variables['story'];
  $count = checkdesk_core_story_updates_count($story, TRUE);
  if ($count > 0) $variables['story_drafts'] = t('(Has one or more drafted updates)');
}

/**
 * @param type $variables
 */
function checkdesk_core_preprocess_checkdesk_core_most_popular_stories(&$variables) {
    foreach ($variables['stories'] as &$story) {
        if ($story->uri) {
            $story->image =  _checkdesk_generate_lead_image_thumbnail($story->uri);
        }
        $story->url = url('node/'. $story->nid, array('absolute' => TRUE));
    }
}
