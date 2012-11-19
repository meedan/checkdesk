<?php
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT"); // Date in the past (HTTP 1.0)
require('../../../../default/settings.php');

// Connect to the database
global $databases;
$p = $databases['default']['default'];
$mysql = mysql_pconnect($p['host'], $p['username'], @$p['password']);
if (!$mysql) die('Could not connect to database server.');
mysql_set_charset('utf8', $mysql);
if (!mysql_select_db($p['database'], $mysql)) die('Could not select database.');

// Handle parameters - call intval to avoid injection of non-sense stuff
$timestamp = intval(mysql_real_escape_string($_REQUEST['timestamp']));
$uid = intval($_REQUEST['user']);

// Get user notification preferences
$data = unserialize(mysql_result(mysql_query("SELECT data FROM users WHERE uid = $uid", $mysql), 0));
function should_notify($data, $option) {
  return (isset($data['meedan_notifications']) ? $data['meedan_notifications'][$option] : TRUE);
}

// Is this user a journalist?
$is_journalist = mysql_result(mysql_query("SELECT COUNT(*) FROM users_roles WHERE uid = $uid AND rid = 4", $mysql), 0);

$query = "SELECT COUNT(DISTINCT(ha.uaid)) FROM heartbeat_activity ha LEFT JOIN node n ON n.nid = ha.nid LEFT JOIN comment c ON c.cid = ha.nid LEFT JOIN comment c2 ON c2.nid = n.nid WHERE (";
if ($is_journalist) {
  if (should_notify($data, 'site_report_flagged')) $query .= "(ha.message_id = 'checkdesk_flag_report') OR ";
  if (should_notify($data, 'site_report_suggested')) $query .= "(ha.message_id = 'checkdesk_report_suggested_to_story') OR ";
  if (should_notify($data, 'site_comment_on_report')) $query .= "(ha.message_id = 'checkdesk_comment_on_report') OR ";
  if (should_notify($data, 'site_comment_on_update')) $query .= "(ha.message_id = 'checkdesk_comment_on_update' AND n.uid = $uid) OR ";
  if (should_notify($data, 'site_fact_checking_on')) $query .= "(ha.message_id = 'checkdesk_fact_checking_on' AND n.uid = $uid) OR ";
  if (should_notify($data, 'site_fact_checking_set')) $query .= "(ha.message_id = 'checkdesk_fact_checking_set' AND n.uid = $uid) OR ";
  if (should_notify($data, 'site_fact_status_changed_for_commenter')) $query .= "(ha.message_id = 'checkdesk_fact_status_changed_for_commenter' AND c2.uid = $uid) OR ";
  if (should_notify($data, 'site_reply_to_comment')) $query .= "(ha.message_id = 'checkdesk_reply_to_comment' AND c.uid = $uid) OR ";
} else {
  if (should_notify($data, 'site_reply_to_comment')) $query .= "(ha.message_id = 'checkdesk_reply_to_comment' AND c.uid = $uid) OR ";
  if (should_notify($data, 'site_comment_on_report')) $query .= "(ha.message_id = 'checkdesk_comment_on_report' AND c2.uid = $uid) OR ";
  if (should_notify($data, 'site_fact_checking_on')) $query .= "(ha.message_id = 'checkdesk_fact_checking_on' AND n.uid = $uid) OR ";
  if (should_notify($data, 'site_fact_checking_set')) $query .= "(ha.message_id = 'checkdesk_fact_checking_set' AND n.uid = $uid) OR ";
  if (should_notify($data, 'site_fact_status_changed_for_commenter')) $query .= "(ha.message_id = 'checkdesk_fact_status_changed_for_commenter' AND c2.uid = $uid) OR ";
  if (should_notify($data, 'site_update_on_story_i_commented_on_update')) $query .= "(ha.message_id = 'checkdesk_new_update_on_story_i_commented_on_update' AND ha.nid_target IN (SELECT field_desk_target_id FROM field_data_field_desk f INNER JOIN comment c ON c.nid = f.entity_id WHERE entity_type = 'node' AND bundle = 'post' AND c.uid = $uid)) OR ";
  if (should_notify($data, 'site_report_published_in_update')) $query .= "(ha.message_id = 'checkdesk_report_published_in_update' AND ha.uid_target = $uid) OR ";
}
$query .= "FALSE) AND ha.timestamp > $timestamp AND ha.uid != $uid";

// Execute query
$count = mysql_result(mysql_query($query, $mysql), 0);

// Return result
print json_encode(array(
  'pong' => $count,
));
?>
