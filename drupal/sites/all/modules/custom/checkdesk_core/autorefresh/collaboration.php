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

$sql = "SELECT COUNT(*) FROM heartbeat_activity WHERE timestamp > " . $timestamp;

if (!empty($_REQUEST['story_nid'])) {
  $nid = intval($_REQUEST['story_nid']);
  $sql .= " AND nid_target = " . $nid;
}

$query = $mysql->prepare($sql);
$query->execute();
$count = $query->fetchColumn();
 
print json_encode(array(
  'pong' => $count,
));

