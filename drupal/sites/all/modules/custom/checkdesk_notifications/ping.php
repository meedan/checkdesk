<?php

header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT"); // Date in the past (HTTP 1.0)

$server_name = $_SERVER['HTTP_HOST'];

if (file_exists("../../../../{$server_name}/settings.php")) {
  require("../../../../{$server_name}/settings.php");
} else {
  require("../../../../default/settings.php");
}

// Connect to the database
global $databases;
$p = $databases['default']['default'];
$mysql = new PDO('mysql:host=' . $p['host'] . ';dbname=' . $p['database'], $p['username'], @$p['password']);
$mysql->exec('SET NAMES utf8mb4 COLLATE utf8mb4_general_ci');

function get_result($sql, $mysql) {
  $query = $mysql->prepare($sql);
  $query->execute();
  return $query->fetchColumn();
}

function get_followed_stories($sql, $mysql) {
  $followed_stories_condition = NULL;
  $query = $mysql->prepare($sql);
  $query->execute();
  $followed_stories = $query->fetchAll();
  if (count($followed_stories)) {
    $or_rows = array();
    foreach ($followed_stories as $flag_info) {
      // Build query condition
      $or_rows[] = "(nid_target = {$flag_info['entity_id']} AND timestamp > {$flag_info['timestamp']})";
    }
    $followed_stories_condition = implode(' OR ', $or_rows);
  }
  return $followed_stories_condition;
}

// Handle parameters - call intval to avoid injection of non-sense stuff
$timestamp = intval($_REQUEST['timestamp']);
$uid = intval($_REQUEST['user']);

// Get user notification preferences
$data = unserialize(get_result("SELECT data FROM users WHERE uid = $uid", $mysql));

function should_notify($data, $option) {
  return ((isset($data['meedan_notifications']) && isset($data['meedan_notifications'][$option])) ? $data['meedan_notifications'][$option] : TRUE);
}

// Is this user a journalist?
$is_journalist = get_result("SELECT COUNT(*) FROM users_roles ur INNER JOIN role r ON r.rid = ur.rid WHERE ur.uid = $uid AND r.name = 'journalist'", $mysql);

$query = "SELECT COUNT(DISTINCT(ha.uaid)) FROM heartbeat_activity ha LEFT JOIN node n ON n.nid = ha.nid LEFT JOIN comment c ON c.cid = ha.nid LEFT JOIN comment c2 ON c2.nid = n.nid WHERE (";

if ($is_journalist) {
  if (should_notify($data, 'site_report_flagged')) {
    $query .= "(ha.message_id = 'checkdesk_flag_report') OR ";
  }
  /*
  if (should_notify($data, 'site_report_suggested'))
    $query .= "(ha.message_id = 'checkdesk_report_suggested_to_story') OR ";
  */
  if (should_notify($data, 'site_comment_on_report')) {
    $query .= "(ha.message_id = 'checkdesk_comment_on_report') OR ";
  }
  if (should_notify($data, 'site_comment_on_update')) {
    $query .= "(ha.message_id = 'checkdesk_comment_on_update' AND n.uid = $uid) OR ";
  }
  if (should_notify($data, 'site_new_user')) {
    $query .= "(ha.message_id = 'checkdesk_new_user') OR ";
  }
  if (should_notify($data, 'site_fact_checking_set_by_citizen')) {
    $query .= "(ha.message_id = 'checkdesk_fact_checking_on_by_citizen') OR ";
  }
  if (should_notify($data, 'site_new_update')) {
    $query .= "(ha.message_id = 'checkdesk_new_update_on_story_i_commented_on_update') OR ";
  }
  if (should_notify($data, 'site_new_story')) {
    $query .= "(ha.message_id = 'checkdesk_add_story') OR ";
  }
  if (should_notify($data, 'site_update_story')) {
    $query .= "(ha.message_id = 'checkdesk_update_story') OR ";
  }
  if (should_notify($data, 'site_new_report')) {
    $query .= "(ha.message_id = 'new_report') OR ";
  }
}
else {
  if (should_notify($data, 'site_update_on_story_i_commented_on_update')) {
    $query .= "(ha.message_id = 'checkdesk_new_update_on_story_i_commented_on_update' AND ha.nid_target IN (SELECT field_desk_target_id FROM field_data_field_desk f INNER JOIN comment c ON c.nid = f.entity_id WHERE entity_type = 'node' AND bundle = 'post' AND c.uid = $uid AND c.created < ha.timestamp)) OR ";
  }
  if (should_notify($data, 'site_report_published_in_update')) {
    $query .= "(ha.message_id = 'checkdesk_report_published_in_update' AND ha.uid_target = $uid) OR ";
  }
  if (should_notify($data, 'site_comment_on_report')) {
    $query .= "(ha.message_id = 'checkdesk_comment_on_report' AND c2.uid = $uid AND ha.timestamp > c2.created) OR ";
  }
  if (should_notify($data, 'site_publish_own_story_revision')) {
    $query .= "(ha.message_id = 'checkdesk_publish_own_story_revision' AND ha.uid_target = $uid) OR ";
  }
}
// Activities for any user
if (should_notify($data, 'site_fact_checking_on')) {
  $query .= "(ha.message_id = 'checkdesk_fact_checking_on' AND n.uid = $uid) OR ";
}
if (should_notify($data, 'site_fact_checking_set')) {
  $query .= "(ha.message_id = 'checkdesk_fact_checking_set' AND n.uid = $uid) OR ";
}
if (should_notify($data, 'site_fact_status_changed_for_commenter')) {
  $query .= "(ha.message_id = 'checkdesk_fact_status_changed_for_commenter' AND c2.uid = $uid AND ha.timestamp > c2.created) OR ";
}
if (should_notify($data, 'site_reply_to_comment')) {
  $query .= "(ha.message_id = 'checkdesk_reply_to_comment' AND c.uid = $uid) OR ";
}

$follow_story_query = 'SELECT entity_id, timestamp FROM flag f INNER JOIN flagging fi ON f.fid = fi.fid AND f.name = "follow_story" WHERE uid = ' . $uid;
$followed_stories_condition = get_followed_stories($follow_story_query, $mysql);
if (should_notify($data, 'site_update_on_story_i_followed') && $followed_stories_condition) {
  $query .= "(ha.message_id = 'checkdesk_new_update_on_story_i_commented_on_update'
  AND ($followed_stories_condition)) OR ";
}
if (should_notify($data, 'site_report_on_story_i_followed') && $followed_stories_condition) {
  $query .= "(ha.message_id = 'checkdesk_report_suggested_to_story'
  AND ($followed_stories_condition)) OR ";
}
if (should_notify($data, 'site_report_status_on_story_i_followed') && $followed_stories_condition) {
  $query .= "(ha.message_id = 'status_report'
  AND ($followed_stories_condition)) OR ";
}

if (should_notify($data, 'site_update_draft_story')) {
  $query .= "(ha.message_id = 'checkdesk_update_draft_story') OR ";
}

$query .= "FALSE) AND ha.timestamp > $timestamp AND ha.uid != $uid";
// Execute query
$count = get_result($query, $mysql);

// Return result
print json_encode(array(
    'pong' => $count,
));
?>
