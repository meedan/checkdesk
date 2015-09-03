<?php
/**
 * This file is part of FaviconDownloader.
 *
 * PHPUnit bootstrap
 */

error_reporting(E_ALL);

// Check curl available
if (!function_exists('curl_init')) {
    trigger_error("curl extension is not available", E_USER_ERROR);
}

// Fiddler proxy testing
if (!isset($_ENV['fiddler-proxy'])) {
    trigger_error("Missing proxy settings", E_USER_ERROR);
}
$echoServiceUrl = 'http://'.$_ENV['fiddler-proxy'];
$ch = curl_init($echoServiceUrl);
curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
$content = curl_exec($ch);
curl_close($ch);
if (!preg_match('#(Fiddler Echo Service|^\s*\[Fiddler\])#i', $content)) {
    trigger_error("Fiddler is not running at ".$echoServiceUrl, E_USER_ERROR);
}

require __DIR__.'/../src/FaviconDownloader.php';
