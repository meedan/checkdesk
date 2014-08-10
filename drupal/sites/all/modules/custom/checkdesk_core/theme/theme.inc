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
 * Template preprocessor for `checkdesk_core_report_source`.
 */
function checkdesk_core_preprocess_checkdesk_core_report_source(&$variables) {
  $report = $variables['report'];
  $embed = meedan_oembed_data($report->field_link[LANGUAGE_NONE][0]['url']);

  $parsed_url = parse_url($embed->original_url);
  $stripped_url = preg_replace('#^www\.(.+\.)#i', '$1', $parsed_url['host']) . $parsed_url['path'];
  $display_url = substr($stripped_url, 0, 35) . '...';

  $variables['source_url'] = l($embed->original_url, $embed->original_url, array('external' => TRUE));
  $variables['source_url_short'] = l($display_url, $embed->original_url, array('external' => TRUE, 'attributes' => array('title' => $embed->original_url),));
  $variables['source_author'] = empty($embed->author_url) ? '' : t('added by !link', array('!link' => l($embed->author_name, $embed->author_url, array('external' => TRUE))));
}

/**
 * Template preprocessor for `checkdesk_core_user_info`.
 */
function checkdesk_core_preprocess_checkdesk_core_user_info(&$variables) {
  global $user;
  $account = $variables['user'];

  // Avatar
  $variables['user_picture'] = theme('user_picture', array('account' => $account));

  // Linked accounts
  $linked_accounts = '';
  if ($account->twitter_accounts) {
    $linked_accounts = '<span class="icon-twitter"></span> ';

    $to_join = array();
    foreach ($account->twitter_accounts as $twitter_account) {
      // See: http://stackoverflow.com/a/8920821/806988
      $to_join[] = l(
        '@' . $twitter_account->screen_name,
        'https://twitter.com/account/redirect_by_id?id=' . $twitter_account->id,
        array(
          'attributes' => array('class' => array('twitter-name'))
        )
      );
    }
    $linked_accounts .= implode(', ', $to_join);
  }
  $variables['linked_accounts'] = $linked_accounts;

  // Just show links when the current user is seeing his own profile
  if ($user->uid === $account->uid) {
    $variables['edit_profile'] = l(t('Edit profile'), 'user/' . $account->uid . '/edit');
    $variables['edit_notifications'] = l(t('Notifications'), 'user/' . $account->uid . '/notifications');
  }
}

/**
 * Template preprocessor for `checkdesk_core_report_source`.
 */
function checkdesk_core_preprocess_checkdesk_core_update_reports(&$variables) {
  $reports_tmp = $users = array();
  $reports = $variables['reports'];
  foreach ($reports as $report) {
    $embed = $report->embed;
    $reports_tmp[] = array(
      'favicon_link' => l(theme('image', array('path' => $embed->favicon_link)), $embed->provider_url, array('html' => TRUE)),
      'title' => l($report->title, 'node/'. $report->nid),
      'description' => $report->body[LANGUAGE_NONE][0]['value'],
    );
    $users[$report->uid] = l($report->name, 'user/'. $report->uid);
  }
  if (count($users) > 2) {
    $last_user = array_pop($users);
    $reports_author = implode(', ', $users) . t(' and ') . $last_user;
  }
  else {
    $reports_author  = implode(t(' and '), $users);
  }
  $variables['reports_author'] = t('Uses reports added by !users', array('!users' => $reports_author));
  $variables['reports'] = $reports_tmp;
 }

