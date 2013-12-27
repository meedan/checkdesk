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
  $heartbeatmessagetemplate->message_id = 'checkdesk_add_story';
  $heartbeatmessagetemplate->description = 'A new story was added';
  $heartbeatmessagetemplate->message = '<p>!username created a new story.</p>';
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
  $export['checkdesk_add_story'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_comment_on_report';
  $heartbeatmessagetemplate->description = 'A comment (footnote) was added to a report';
  $heartbeatmessagetemplate->message = '<p><strong><a href="!user_url">!username</a></strong> has added footnote to report <strong><a href="!report_url">!report_title</a></strong></p>';
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
    '!user_url' => '',
    '!username' => '',
    '!report_url' => '',
    '!report_title' => '',
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
  $export['checkdesk_comment_on_report'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_comment_on_update';
  $heartbeatmessagetemplate->description = 'Comment on an update';
  $heartbeatmessagetemplate->message = '<p><strong><a href="!user_url">!username</a></strong> has commented on <strong><a href="!update_url">!update_title</a></strong></p>';
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
    '!user_url' => '',
    '!username' => '',
    '!update_url' => '',
    '!update_title' => '',
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
  $export['checkdesk_comment_on_update'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_fact_checking_on';
  $heartbeatmessagetemplate->description = 'Fact-checking turned on for a report';
  $heartbeatmessagetemplate->message = '<p><strong><a href="!user_url">!username</a></strong> has turned on fact-checking for a <strong><a href="!report_url">report</a></strong> you submitted. Fact checking is in progress.</p>';
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
    '!user_url' => '',
    '!username' => '',
    '!report_url' => '',
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
  $export['checkdesk_fact_checking_on'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_fact_checking_set';
  $heartbeatmessagetemplate->description = 'Fact-checking was set or changed';
  $heartbeatmessagetemplate->message = '<p><strong><a href="!user_url">!username</a></strong> has changed the fact-checking status for a <strong><a href="!report_url">report</a></strong> you submitted to <strong>!fact_checking_status</strong></p>';
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
    '!user_url' => '',
    '!username' => '',
    '!report_url' => '',
    '!fact_checking_status' => '',
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
  $export['checkdesk_fact_checking_set'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_fact_status_changed_for_commenter';
  $heartbeatmessagetemplate->description = 'Fact status changed on a report commented';
  $heartbeatmessagetemplate->message = '<p><strong><a href="!user_url">!username</a></strong> has changed the fact-checking status for a <strong><a href="!report_url">report</a></strong> you added footnote to to <strong>!fact_checking_status</strong></p>';
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
      5 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!user_url' => '',
    '!username' => '',
    '!report_url' => '',
    '!fact_checking_status' => '',
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
  $export['checkdesk_fact_status_changed_for_commenter'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_flag_report';
  $heartbeatmessagetemplate->description = 'Report was flagged';
  $heartbeatmessagetemplate->message = '<p><strong><a href="!flag_author_url">!flag_author_name</a></strong> has flagged a <strong><a href="!report_url">report</a></strong> as <span class="notification-flag">!flag_type</span>.</p>';
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
    '!flag_author_url' => '',
    '!flag_author_name' => '',
    '!report_url' => '',
    '!flag_type' => '',
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
  $export['checkdesk_flag_report'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_new_update_on_story_i_commented_on_update';
  $heartbeatmessagetemplate->description = 'New update on a story I commented on an update before';
  $heartbeatmessagetemplate->message = '<p>Story <strong><a href="!story_url">!story_title</a></strong> which you commented on has a new <strong><a href="!update_url">update</a></strong></p>';
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
    '!story_url' => '',
    '!story_title' => '',
    '!update_url' => '',
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
  $export['checkdesk_new_update_on_story_i_commented_on_update'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_new_user';
  $heartbeatmessagetemplate->description = 'New user registered';
  $heartbeatmessagetemplate->message = '<p>A new user called <strong><a href="!url">!name</a></strong> has registered. Please mark him as <em>active</em>, if you want to accept this registration.</p>';
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
    '!url' => '',
    '!name' => '',
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
  $export['checkdesk_new_user'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_reply_to_comment';
  $heartbeatmessagetemplate->description = 'A comment was replied';
  $heartbeatmessagetemplate->message = '<p><strong><a href="!user_url">!username</a></strong> has replied to your <strong><a href="!comment_url">comment</a></strong></p>';
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
    '!user_url' => '',
    '!username' => '',
    '!comment_url' => '',
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
  $export['checkdesk_reply_to_comment'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_report_published_in_update';
  $heartbeatmessagetemplate->description = 'A report was published in an update';
  $heartbeatmessagetemplate->message = '<p>A <strong><a href="!report_url">report</a></strong> which you have submitted has been published in an <strong><a href="!update_url">update</a></strong></p>';
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
    '!report_url' => '',
    '!update_url' => '',
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
  $export['checkdesk_report_published_in_update'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_report_suggested_to_story';
  $heartbeatmessagetemplate->description = 'Report suggested to story';
  $heartbeatmessagetemplate->message = '<p><strong><a href="!user_url">!username</a></strong> has suggested a <strong><a href="!report_url">report</a></strong> to <strong><a href="!story_url">!story</a></strong></p>';
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
    '!user_url' => '',
    '!username' => '',
    '!report_url' => '',
    '!story_url' => '',
    '!story' => '',
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
  $export['checkdesk_report_suggested_to_story'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'new_comment_report';
  $heartbeatmessagetemplate->description = 'New comment on a report';
  $heartbeatmessagetemplate->message = '!username said: <div class="message">!comment</div>';
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
  $heartbeatmessagetemplate->message = 'Published to liveblog by !publisher to <a href="!story_url">!story</a>';
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
      5 => 0,
    ),
  );
  $heartbeatmessagetemplate->variables = array(
    '!publisher' => '',
    '!story_url' => '',
    '!story' => '',
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
