<?php

/**
 * Template preprocessor for `checkdesk_core_report_source`.
 */
function checkdesk_reports_preprocess_checkdesk_core_report_source(&$variables) {
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
 * Template preprocessor for `checkdesk_core_update_reports`.
 */
function checkdesk_reports_preprocess_checkdesk_core_update_reports(&$variables) {
  $reports_tmp = $users = array();
  $reports = $variables['reports'];
  foreach ($reports as $report) {
    $embed = $report->embed;
    // add custom favicons
    $providers = _checkdesk_providers();
    if(in_array(drupal_strtolower($embed->provider_name), $providers)) {
      $favicon = l(_checkdesk_favicons(drupal_strtolower($embed->provider_name)), 'node/'. $report->nid, array('html' => TRUE, 'attributes' => array('class' => array('favicon'))));
    } else {
      $favicon = l(theme('image', array('path' => $embed->favicon_link)), 'node/'. $report->nid, array('html' => TRUE, 'attributes' => array('class' => array('favicon'))));
    }

    $reports_tmp[] = array(
      'favicon_link' => $favicon,
      'title' => l($report->title, 'node/'. $report->nid),
      'description' => isset($report->body[LANGUAGE_NONE][0]['value']) ? truncate_utf8($report->body[LANGUAGE_NONE][0]['value'], 150, TRUE, TRUE) : NULL,
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
 * Template preprocessor for `checkdesk_reports_report_activity_status`.
 */
function checkdesk_reports_preprocess_checkdesk_reports_report_activity_status(&$variables) {
  global $language;

  $activity = $variables['heartbeat_activity'];
  $icon_class = '';
  $status_name = $activity->variables['!status'];
  $status_class = empty($status_name) ? '' : strtolower(str_replace(' ', '-', $status_name));
  $status_term = taxonomy_get_term_by_name($status_name, 'media_rating');
  $icon = _checkdesk_report_status_icon(reset($status_term));
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

/**
 * Template preprocessor for `checkdesk_reports_report_activity`.
 */
function checkdesk_reports_preprocess_checkdesk_reports_report_activity(&$variables) {
  global $language;
  $node = $variables['node'];
  $variables['nid'] = $node->nid;
  $variables['collapsed'] = ($variables['view_mode'] == 'full') ? 'open' : '';
  //Add activity report with status
  $term = isset($node->field_rating[LANGUAGE_NONE][0]['taxonomy_term']) ?
    $node->field_rating[LANGUAGE_NONE][0]['taxonomy_term'] :
    taxonomy_term_load($node->field_rating[LANGUAGE_NONE][0]['tid']);
  $status_name = $term->name;
  $total_rows = '';
  $variables['show_activity'] = ($variables['view_mode'] == 'checkdesk_search') ? FALSE : TRUE;
  if ($status_name !== 'Not Applicable') {
    $activity_report = _checkdesk_load_activity_report($variables['nid']);
    $total_rows = $activity_report['total_rows'];
    if ($variables['show_activity']) {
      if ($total_rows) {
        $variables['media_activity_report'] = theme(
          'checkdesk_reports_report_activity_stream', array('activity' => $activity_report['view_output'], 'nid' => $variables['nid'])
        );
        $variables['status_class'] = strtolower(str_replace(' ', '-', $status_name));

      }
      if (user_is_logged_in() || arg(0) == 'embed' ) {
        $variables['media_activity_footer'] = '';
      }
      else {
        $icon = '<span class="icon-question-circle"></span> ';
        $link = l(t('About verification process'), 'modal/ajax/content/fact-checking-statement', array('html' => 'true', 'language' => $language, 'attributes' => array('class' => array('use-ajax', 'ctools-modal-modal-popup-large'))));
        $variables['media_activity_footer'] = '<span class="cta">' . t('To help verify this report, please <a href="@login_url">sign in</a>', array('@login_url' => url('user/login'))) . '</span><span class="helper">' . $icon . $link . '</span>';
      }
    }
  }
  if ($variables['show_activity'] || empty($total_rows)) {
    $variables['media_activity_report_count'] = theme(
      'checkdesk_reports_report_activity_count', array('count' => $total_rows, 'nid' => $variables['nid'])
    );
  }
  else {
    $variables['media_activity_report_count'] = theme(
      'checkdesk_reports_report_activity_count', array('count' => $total_rows, 'nid' => $variables['nid'], 'link_count' => TRUE)
    );
  }

}

/**
 * Template preprocessor for `checkdesk_reports_metadata_fields`.
 */
function checkdesk_reports_preprocess_checkdesk_reports_metadata_fields(&$variables) {
  $node = $variables['node'];
  $fields = _checkdesk_metadata_group_fields();
  $metadata_fields = array();
  foreach ($fields as $field) {
    $metadata_fields[] = field_view_field('node', $node, $field, 'full');
  }
  $variables['metadata_fields'] = $metadata_fields;
}