<?php

// LOGGING
$handle = fopen('../../data/of/request.log', 'a');
$log = $_SERVER['QUERY_STRING']."\t"
	.($_SERVER['HTTP_REFERER']?$_SERVER['HTTP_REFERER']:'no-referer')."\t"
	.$_SERVER['REMOTE_ADDR']."\t"
	.$_SERVER['REQUEST_METHOD']."\t"
	.$_SERVER['HTTP_USER_AGENT']."\t"
	.@date(DATE_RFC822,$_SERVER['REQUEST_TIME'])."\n";
fwrite($handle, $log);
fclose($handle);

// GETTING WEBSITE'S URL
$url = explode('&',$_SERVER['QUERY_STRING']);
$url = $url[0];
   
// GETICON
require_once('class.geticon.php');
new geticon($url, '../../', 'data/of/');
?>
