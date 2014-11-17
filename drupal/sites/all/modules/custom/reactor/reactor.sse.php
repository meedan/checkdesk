<?php

/**
 * @file Server-Side Events notifications.
 */
/*
chdir('../../../..');
include('./includes/bootstrap.inc');
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
*/
header("Content-Type: text/event-stream\n\n");
$counter = rand(1, 10);
while (1) {
  // Every second, sent a "ping" event.
  echo "event: ping\n";
  $curDate = date(DATE_ISO8601);
  echo 'data: {"time": "' . $curDate . '"}';
  echo "\n\n";

  // Send a simple message at random intervals.
  $counter--;
  if (!$counter) {
    echo 'data: This is a message at time ' . $curDate . "\n\n";
    $counter = rand(1, 10);
  }

  ob_flush();
  flush();
  sleep(1);
}
