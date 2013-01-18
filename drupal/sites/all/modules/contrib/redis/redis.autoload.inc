<?php

/**
 * @file
 * Redis module autoloader.
 */

// Use the Autoload Early module if present.
if (class_exists('AutoloadEarly')) {
  AutoloadEarly::getInstance()->registerNamespace('Redis', dirname(__FILE__) . '/lib');
}
// Else, we have to register our own autoloader.
else {

  /**
   * Autoloader micro optimization, work with constant as much as we can.
   */
  define('REDIS_ROOT', dirname(__FILE__) . '/lib');

  /**
   * Redis module specific autoloader, compatible with spl_register_autoload().
   */
  function redis_autoload($class_name) {
    $parts = explode('_', $class_name);

    if ('Redis' === $parts[0]) {
      $filename = REDIS_ROOT . '/' . implode('/', $parts) . '.php';

      if (file_exists($filename)) {
        require_once $filename;
        return TRUE;
      }
    }

    return FALSE;
  }

  // Register our custom autoloader.
  spl_autoload_register('redis_autoload');
}

// See comment in called method. This is very important.
if (isset($GLOBALS['conf']['redis_client_interface']) && 'Predis' === $GLOBALS['conf']['redis_client_interface']) {
  Redis_Client_Predis::setPredisAutoload();
}
