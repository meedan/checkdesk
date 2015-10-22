<?php

/**
  * include this file at the bottom of your settings.php
  * either by  
  * require_once(DRUPAL_ROOT."path/to/this/file/utf8mb4_converter/supporting/settings.php.inc");
  * or by copy/paste-ing this in the bottom of the settings.php file
  * either way this needs to happen LAST in the file right before
  * the main page processing takes place
  *
  **/

foreach ($databases as $_key => $_settings) {
  if (trim($_key) != "" && !empty($_settings)) {
    $databases[$_key]['default']['charset'] = 'utf8mb4';
    $databases[$_key]['default']['collation'] = 'utf8mb4_general_ci';
  }
}