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
$port = $p['port'] ? $p['port'] : 3306; 
$mysql = new PDO('mysql:host=' . $p['host'] . ';port=' . $port . ';dbname=' . $p['database'], $p['username'], @$p['password']);
$mysql->exec('SET NAMES utf8mb4 COLLATE utf8mb4_general_ci');

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

