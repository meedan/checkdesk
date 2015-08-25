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
  $heartbeatmessagetemplate->message = '<a class="actor" href="!user_url">!username</a> added a new <a href="!story_url">story</a>';
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
    '!story_url' => '',
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
  $export['checkdesk_add_story'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_comment_on_report';
  $heartbeatmessagetemplate->description = 'A comment (footnote) was added to a report';
  $heartbeatmessagetemplate->message = '<a class="actor" href="!user_url">!username</a> added footnote to <a href="!report_url">report</a>';
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
    '!report_url' => '',
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
  $export['checkdesk_comment_on_report'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_comment_on_update';
  $heartbeatmessagetemplate->description = 'Comment on an update';
  $heartbeatmessagetemplate->message = '<a href="!user_url" class="actor">!username</a> has commented on <a href="!update_url">!update_title</a>';
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
  $heartbeatmessagetemplate->message = '<a href="!user_url" class="actor">!username</a> has turned on fact-checking for a <a href="!report_url">report</a>';
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
  $heartbeatmessagetemplate->message_id = 'checkdesk_fact_checking_on_by_citizen';
  $heartbeatmessagetemplate->description = 'Fact-checking turned on for a report by citizen journalist';
  $heartbeatmessagetemplate->message = '<a href="!user_url" class="actor">!username</a> has turned on fact-checking for a <a href="!report_url">report</a> they submitted. Fact checking is in progress.';
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
    '!report_url' => '',
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
  $export['checkdesk_fact_checking_on_by_citizen'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_fact_checking_set';
  $heartbeatmessagetemplate->description = 'Fact-checking was set or changed';
  $heartbeatmessagetemplate->message = '<a href="!user_url" class="actor">!username</a> has changed the fact-checking status for a <a href="!report_url">report</a> you submitted to !fact_checking_status';
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
  $heartbeatmessagetemplate->message = '<a href="!user_url" class="actor">!username</a> has changed the fact-checking status for a <a href="!report_url">report</a> you added footnote to to !fact_checking_status';
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
  $heartbeatmessagetemplate->message = '<a class="actor" href="!flag_author_url">!flag_author_name</a> has flagged a <a href="!report_url">report</a> as <span class="notification-flag">!flag_type</span>';
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
  $heartbeatmessagetemplate->message_id = 'checkdesk_follow_story';
  $heartbeatmessagetemplate->description = 'Follow story';
  $heartbeatmessagetemplate->message = '<a href="!flag_author_url" class="actor">!flag_author_name</a> followed this story';
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
  $export['checkdesk_follow_story'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_new_update_on_story_i_commented_on_update';
  $heartbeatmessagetemplate->description = 'New update on a story I commented on an update before';
  $heartbeatmessagetemplate->message = '<a class="actor" href="!user_url">!username</a> added an <a href="!update_url">update</a> to <a href="!story_url">!story</a>';
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
    '!update_url' => '',
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
  $export['checkdesk_new_update_on_story_i_commented_on_update'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_new_user';
  $heartbeatmessagetemplate->description = 'New user registered';
  $heartbeatmessagetemplate->message = 'A new user <a href="!url">!name</a> has registered. Please mark him as <em>active</em>, if you want to accept this registration.';
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
  $heartbeatmessagetemplate->message = '<a href="!user_url" class="actor">!username</a> has replied to your <a href="!comment_url">comment</a>';
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
  $heartbeatmessagetemplate->message = 'A <a href="!report_url">report</a> which you have submitted has been published in an <a href="!update_url">update</a>';
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
  $heartbeatmessagetemplate->message = '<a class="actor" href="!user_url">!username</a> added a new  <a href="!report_url">report</a> to <a href="!story_url">!story</a>';
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
    '!report_url' => '',
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
  $export['checkdesk_report_suggested_to_story'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_update_draft_story';
  $heartbeatmessagetemplate->description = 'Existing draft story was updated';
  $heartbeatmessagetemplate->message = '<a class="actor" href="!user_url">!username</a> updated a draft <a href="!story_url">story</a>';
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
    '!story_url' => '',
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
  $export['checkdesk_update_draft_story'] = $heartbeatmessagetemplate;

  $heartbeatmessagetemplate = new HeartbeatMessageTemplate();
  $heartbeatmessagetemplate->disabled = FALSE; /* Edit this to true to make a default heartbeatmessagetemplate disabled initially */
  $heartbeatmessagetemplate->api_version = 1;
  $heartbeatmessagetemplate->message_id = 'checkdesk_update_story';
  $heartbeatmessagetemplate->description = 'Existing story was updated';
  $heartbeatmessagetemplate->message = '<a class="actor" href="!user_url">!username</a> updated <a href="!story_url">story</a>';
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
    '!story_url' => '',
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
  $export['checkdesk_update_story'] = $heartbeatmessagetemplate;

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
  $heartbeatmessagetemplate->message = '<a class="actor" href="!user_url">!username</a> added a new <a href="!report_url">report</a>';
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
    '!report_url' => '',
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
  $heartbeatmessagetemplate->message = '<a class="actor" href="!editor_url">!editor</a> changed <a href="!report_url">report</a> status to !status';
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
    '!editor_url' => '',
    '!editor' => '',
    '!report_url' => '',
    '!status' => '',
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
  $export['status_report'] = $heartbeatmessagetemplate;

  return $export;
}
