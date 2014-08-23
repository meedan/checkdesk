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
 * Template preprocessor for `checkdesk_core_update_reports`.
 */
function checkdesk_core_preprocess_checkdesk_core_update_reports(&$variables) {
  $reports_tmp = $users = array();
  $reports = $variables['reports'];
  foreach ($reports as $report) {
    $embed = $report->embed;
    // add custom favicons
    $providers = _checkdesk_providers();
    if(in_array(drupal_strtolower($embed->provider_name), $providers)) {
      $favicon = l(_checkdesk_favicons(drupal_strtolower($embed->provider_name)), 'node/'. $report->nid, array('html' => TRUE));
    } else {
      $favicon = l(theme('image', array('path' => $embed->favicon_link)), 'node/'. $report->nid, array('html' => TRUE));
    }

    $reports_tmp[] = array(
      'favicon_link' => $favicon,
      'title' => l($report->title, 'node/'. $report->nid),
      'description' => truncate_utf8($report->body[LANGUAGE_NONE][0]['value'], 150, TRUE, TRUE),
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

/**
 * Template preprocessor for `checkdesk_core_report_activity_status`.
 */
function checkdesk_core_preprocess_checkdesk_core_report_activity_status(&$variables) {
  dsm($variables);
  global $language;

  $activity = $variables['heartbeat_activity'];
  $icon = '';
  $status_name = $activity->variables['!status'];
  $status_class = '';
  if ($status_name == 'Verified') {
    $status_class = 'verified';
    $icon = '<span class="icon-check-circle"></span> ';
  }
  elseif ($status_name == 'In Progress') {
    $status_class = 'in-progress';
    $icon = '<span class="icon-random"></span> ';
  }    
  elseif ($status_name == 'Undetermined') {
    $status_class = 'undetermined';
    $icon = '<span class="icon-question-circle"></span> ';
  }    
  elseif ($status_name == 'False') {
    $status_class = 'false';
    $icon = '<span class="icon-times-circle"></span> ';
  }    
  $variables['activity_status'] = $icon . '<span class="status-name ' . $status_class . '">' . t($status_name) . '</span>';
  
  if($status_name != 'In Progress') {
    $status_by = t('by <span class="checkdesk-status-partner">@partner</span>', array('@partner' => variable_get_value('checkdesk_site_owner', array('language' => $language))));
  }

  // display status with an icon and "x by partner"
  if(isset($status_name) && isset($icon) && isset($status_by)) {
    $variables['activity_status'] = $icon . '<span class="status-name ' . $status_class . '">' . t($status_name) . '</span>&nbsp;<span class="status-by">' . $status_by . '</span>';
  } else { // display status with an icon only
    $variables['activity_status'] = $icon . '<span class="status-name ' . $status_class . '">' . t($status_name) . '</span>';
  }
  // Get status footnote if exist
  // always footnote for change status is uaid of status - 3
  $footnote_uaid = $activity->uaid - 3;
  $footnote =  heartbeat_activity_load($footnote_uaid);
  if ($footnote->message_id == 'new_comment_report' && $footnote->nid_target == $activity->nid_target) {
    $variables['activity_status_footnote'] = $footnote->variables['!comment'];
  }
}
