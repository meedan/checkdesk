<?php
header("Cache-Control: no-cache, must-revalidate"); // HTTP/1.1
header("Expires: Sat, 26 Jul 1997 05:00:00 GMT"); // Date in the past (HTTP 1.0)
$server_name = $_SERVER['HTTP_HOST'];
require("../../../../../../sites/{$server_name}/settings.php");

// Connect to the database
global $databases;
$p = $databases['default']['default'];
$mysql = new PDO('mysql:host=' . $p['host'] . ';dbname=' . $p['database'], $p['username'], @$p['password']);
$mysql->exec('SET NAMES utf8');

$timestamp = intval($_REQUEST['timestamp']);
$type = preg_replace('/[^a-zA-Z0-9_]/', '', $_REQUEST['type']);
$field = preg_replace('/[^a-zA-Z0-9_]/', '', $_REQUEST['field']);

$sql = "SELECT COUNT(nid) FROM node WHERE type='" . $type . "' AND " . $field . " > " . $timestamp;
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

