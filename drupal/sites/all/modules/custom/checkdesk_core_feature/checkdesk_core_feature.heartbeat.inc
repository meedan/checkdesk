<?php
/**
 * @file
 * checkdesk_core_feature.heartbeat.inc
 */

/**
 * Implements hook_heartbeat_template_info().
 */
function checkdesk_core_feature_heartbeat_template_info() {
  $export = array();

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'new_comment_report';
  $heartbeatmessagetemplate->description = 'New comment on a report';
  $heartbeatmessagetemplate->message = '!username said: !comment';
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
      4 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!username' => '',
    '!comment' => '',
  );
  $heartbeatmessagetemplate->attachments = array(
    'buttons' => array(
      'weight' => array(
        'flagattachment:like' => '0',
        'activitycomments' => '2',
      ),
      'settings' => array(
        'activitycomments' => array(
          'activitycomments_node' => 0,
        ),
      ),
      'enabled' => array(
        'flagattachment:like' => 0,
        'activitycomments' => 0,
      ),
    ),
    'content' => array(
      'weight' => array(
        'flagattachment:like' => '0',
        'activitycomments' => '2',
      ),
      'enabled' => array(
        'flagattachment:like' => 0,
        'activitycomments' => 0,
      ),
    ),
  );
  $export['new_comment_report'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'new_report';
  $heartbeatmessagetemplate->description = 'New report';
  $heartbeatmessagetemplate->message = '!title added by !username.';
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
      4 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!title' => '',
    '!username' => '',
  );
  $heartbeatmessagetemplate->attachments = array(
    'buttons' => array(
      'weight' => array(
        'flagattachment:like' => '0',
      ),
      'enabled' => array(
        'flagattachment:like' => 0,
      ),
    ),
    'content' => array(
      'weight' => array(
        'flagattachment:like' => '0',
      ),
      'enabled' => array(
        'flagattachment:like' => 0,
      ),
    ),
  );
  $export['new_report'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'publish_report';
  $heartbeatmessagetemplate->description = 'Report has been published to liveblog';
  $heartbeatmessagetemplate->message = 'Published to liveblog by !publisher to !story.';
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
      4 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!publisher' => '',
    '!story' => '',
  );
  $heartbeatmessagetemplate->attachments = array(
    'buttons' => array(
      'weight' => array(
        'flagattachment:like' => '0',
      ),
      'enabled' => array(
        'flagattachment:like' => 0,
      ),
    ),
    'content' => array(
      'weight' => array(
        'flagattachment:like' => '0',
      ),
      'enabled' => array(
        'flagattachment:like' => 0,
      ),
    ),
  );
  $export['publish_report'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'status_report';
  $heartbeatmessagetemplate->description = 'Change of report status';
  $heartbeatmessagetemplate->message = 'Status set to !status by !editor.';
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
      4 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!status' => '',
    '!editor' => '',
  );
  $heartbeatmessagetemplate->attachments = array(
    'buttons' => array(
      'weight' => array(
        'flagattachment:like' => '0',
        'activitycomments' => '2',
      ),
      'settings' => array(
        'activitycomments' => array(
          'activitycomments_node' => 0,
        ),
      ),
      'enabled' => array(
        'flagattachment:like' => 0,
        'activitycomments' => 0,
      ),
    ),
    'content' => array(
      'weight' => array(
        'flagattachment:like' => '0',
        'activitycomments' => '2',
      ),
      'enabled' => array(
        'flagattachment:like' => 0,
        'activitycomments' => 0,
      ),
    ),
  );
  $export['status_report'] = $heartbeatmessagetemplate;

  return $export;
}
