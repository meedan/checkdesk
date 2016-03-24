<?php
/**
 * @file
 * checkdesk_sources_feature.heartbeat.inc
 */

/**
 * Implements hook_heartbeat_template_info().
 */
function checkdesk_sources_feature_heartbeat_template_info() {
  $export = array();

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_comment_on_source';
  $heartbeatmessagetemplate->description = 'A comment (footnote) was added to a source';
  $heartbeatmessagetemplate->message = '<a class="actor" href="!user_url">!username</a> added footnote to <a href="!source_url">source</a>';
  $heartbeatmessagetemplate->message_concat = '';
  $heartbeatmessagetemplate->perms = 4;
  $heartbeatmessagetemplate->group_type = 'single';
  $heartbeatmessagetemplate->concat_args = array(
    'group_by' => 'none',
    'group_target' => '',
    'group_by_target' => '',
    'group_num_max' => '',
    'merge_separator' => '',
    'merge_end_separator' => '',
    'roles' => array(
      1 => 0,
      2 => 0,
      3 => 0,
      5 => 0,
      4 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!user_url' => '',
    '!username' => '',
    '!source_url' => '',
  );
  $heartbeatmessagetemplate->attachments = array(
    'buttons' => array(
      'weight' => array(
        'activitycomments' => '2',
      ),
      'settings' => array(
        'activitycomments' => array(
          'activitycomments_node' => 0,
        ),
      ),
      'enabled' => array(
        'activitycomments' => 0,
      ),
    ),
    'content' => array(
      'weight' => array(
        'activitycomments' => '2',
      ),
      'enabled' => array(
        'activitycomments' => 0,
      ),
    ),
  );
  $export['checkdesk_comment_on_source'] = $heartbeatmessagetemplate;

  return $export;
}
