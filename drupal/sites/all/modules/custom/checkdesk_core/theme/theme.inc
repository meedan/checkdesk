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
    '@date' => format_date(time(), 'custom', 'g:ia'),
    '!city' => $city,
    '!country' => $country,
  ));
}

/**
 * Template preprocessor for `checkdesk_core_report_source`.
 */
function checkdesk_core_preprocess_checkdesk_core_report_source(&$variables) {
  $report = $variables['report'];
  $embed = meedan_oembed_data($report->field_link[LANGUAGE_NONE][0]['display_url']);
  $variables['source_url'] = l($embed->original_url, $embed->original_url, array('external' => TRUE));
  $variables['source_author'] = empty($embed->author_url) ? '' : t('added by !link', array('!link' => l($embed->author_name, $embed->author_url, array('external' => TRUE))));
}





