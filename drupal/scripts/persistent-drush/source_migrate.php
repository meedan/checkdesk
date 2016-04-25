<?php

/**
 * @file
 * Handles meedan_source migration.
 * Move script to root directory
 */

/**
 * Root directory of Drupal installation.
 */
define('DRUPAL_ROOT', getcwd());

include_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

// Set this to avoid php warnings.
//$_SERVER['REMOTE_ADDR'] = '';

_checkdesk_sources_migrate_meedan_sources();
