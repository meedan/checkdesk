<?php
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT"); // Date in the past (HTTP 1.0)

$server_name = $_SERVER['HTTP_HOST'];

if (file_exists("../../../../../{$server_name}/settings.php")) {
  require("../../../../../{$server_name}/settings.php");
} else {
  require("../../../../../default/settings.php");
}
// Connect to the database
global $databases;
$p = $databases['default']['default'];
$mysql = new PDO('mysql:host=' . $p['host'] . ';dbname=' . $p['database'], $p['username'], @$p['password']);
$mysql->exec('SET NAMES utf8mb4');

$timestamp = intval($_REQUEST['timestamp']);
$type = preg_replace('/[^a-zA-Z0-9_]/', '', $_REQUEST['type']);
$field = preg_replace('/[^a-zA-Z0-9_]/', '', $_REQUEST['field']);
$join = '';
if ($type == 'media' && $_REQUEST['story']) {
  $story = intval($_REQUEST['story']);
  $join = "INNER JOIN field_data_field_stories fs ON node.nid = fs.entity_id AND fs.field_stories_target_id = $story";
}
$sql = "SELECT COUNT(nid) FROM node $join WHERE type='" . $type . "' AND " . $field . " > " . $timestamp;
if (!empty($_REQUEST['uid'])) {
  $uid = intval($_REQUEST['uid']);
  $sql .= " AND uid = " . $uid;
}

$query = $mysql->prepare($sql);
$query->execute();
$count = $query->fetchColumn();
 
print json_encode(array(
  'pong' => $count,
));

