<?php

require('../../../../../../sites/default/settings.php');

$p = $databases['default']['default'];
$mysql = mysql_pconnect($p['host'], $p['username'], $p['password']);
if (!$mysql) die('Could not connect to database server.');
mysql_set_charset('utf8', $mysql);
if (!mysql_select_db($p['database'], $mysql)) die('Could not select database.');
 
$timestamp = mysql_real_escape_string($_REQUEST['timestamp']);
$type = mysql_real_escape_string($_REQUEST['type']);
$sql = "SELECT COUNT(nid) FROM node WHERE type='" . $type .  "' AND created > " . $timestamp;
if (!empty($_REQUEST['uid'])) {
  $uid = mysql_real_escape_string($_REQUEST['uid']);
  $sql .= " AND uid = " . $uid;
}
$count = mysql_result(mysql_query($sql, $mysql), 0);
 
print json_encode(array(
  'pong' => $count,
));

