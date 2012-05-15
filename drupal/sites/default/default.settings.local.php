<?php

/**
 * USAGE:
 * 
 *   Copy this file and name it 'settings.local.php'.
 *   Fill in the appropriate blanks.
 * 
 * NOTES:
 *
 *   This file is included from settings.php.  The intention is to separate
 *   site specific settings from general settings applied to all sites via
 *   the Meedan Drupal Boilerplate.
 */

$databases['default']['default'] = array(
  'driver'   => 'mysql',
  'database' => 'DATABASENAME',
  'username' => 'root',
  'password' => 'root',
  'host'     => 'localhost',
  'prefix'   => '',
);
// The before deployment database, used during complex deployments to ferry
// data from previous schemas / site versions.
$databases['default']['before_deploy'] = array(
  'driver'   => $databases['default']['default']['driver'],
  'database' => $databases['default']['default']['database'] . '_before_deploy',
  'username' => $databases['default']['default']['username'],
  'password' => $databases['default']['default']['password'],
  'host'     => $databases['default']['default']['host'],
  'prefix'   => $databases['default']['default']['prefix'],
);


// Development and debugging.  It is best to remove these lines for
// production deployments.
if (MEEDAN_ENVIRONMENT != 'LIVE') {
  ini_set('error_reporting', E_ALL);
  ini_set('display_errors', 1);
}
