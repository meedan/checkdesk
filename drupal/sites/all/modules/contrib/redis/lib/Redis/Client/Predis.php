<?php

/**
 * Predis client specific implementation.
 */
class Redis_Client_Predis implements Redis_Client_Interface {

  /**
   * Circular depedency breaker.
   */
  static protected $autoloaderRegistered = false;

  /**
   * Predis version major.
   */
  static protected $predisVersionMajor = 1;

  /**
   * Get predis version major.
   *
   * @return int
   */
  static public function getPredisVersionMajor()
  {
      return self::$predisVersionMajor;
  }

  /**
   * Define Predis base path if not already set, and if we need to set the
   * autoloader by ourself. This will ensure no crash. Best way would have
   * been that Drupal ships a PSR-0 autoloader, in which we could manually
   * add our library path.
   * 
   * We cannot do that in the file header, PHP class_exists() function wont
   * see classes being loaded during the autoloading because this file is
   * loaded by another autoloader: attempting the class_exists() during a
   * pending autoloading would cause PHP to crash and ignore the rest of the
   * file silentely (WTF!?). By delaying this at the getClient() call we
   * ensure we are not in the class loading process anymore.
   */
  public static function setPredisAutoload() {

    if (self::$autoloaderRegistered) {
      return;
    } else {
      self::$autoloaderRegistered = true;
    }

    // If you attempt to set Drupal's bin cache_bootstrap using Redis, you
    // will experience an infinite loop (breaking by itself the second time
    // it passes by): the following call will wake up autoloaders (and we
    // want that to work since user may have set its own autoloader) but
    // will wake up Drupal's one too, and because Drupal core caches its
    // file map, this will trigger this method to be called a second time
    // and boom! Adios bye bye. That's why this will be called early in the
    // 'redis.autoload.inc' file instead.
    if (!class_exists('Predis\Client')) {

      if (!defined('PREDIS_BASE_PATH')) {
        $search = DRUPAL_ROOT . '/sites/all/libraries/predis';
      } else {
        $search = PREDIS_BASE_PATH;
      }

      if (is_dir($search . '/src')) { // Predis v1.x
        self::$predisVersionMajor = 1;
        define('PREDIS_BASE_PATH', $search);
      } else if (is_dir($search . '/lib')) { // Predis v0.x
        self::$predisVersionMajor = 0;
        define('PREDIS_BASE_PATH', $search);
      } else {
        throw new Exception("PREDIS_BASE_PATH constant must be set, Predis library must live in sites/all/libraries/predis.");
      }

      // Register a simple autoloader for Predis library. Since the Predis
      // library is PHP 5.3 only, we can afford doing closures safely.
      switch (self::$predisVersionMajor) {

        case 0:
          spl_autoload_register(function($classname) { // PSR-0 autoloader.
            if (0 === strpos($classname, 'Predis\\')) {
              $filename = PREDIS_BASE_PATH . '/lib/' . str_replace('\\', '/', $classname) . '.php';
              return (bool)require_once $filename;
            }
            return false;
          });
          break;

        case 1:
          // Register a simple autoloader for Predis library. Since the Predis
          // library is PHP 5.3 only, we can afford doing closures safely.
          spl_autoload_register(function($classname) { // PSR-4 autoloader
            if (0 === strpos($classname, 'Predis\\')) {
              $filename = PREDIS_BASE_PATH . '/src/' . str_replace('\\', '/', substr($classname, 7)) . '.php';
              return (bool)require_once $filename;
            }
            return false;
          });
          break;
      }
    }
  }

  public function getClient($host = NULL, $port = NULL, $base = NULL, $password = NULL, $socket = NULL) {
    $connectionInfo = array(
      'password' => $password,
      'host'     => $host,
      'port'     => $port,
      'database' => $base
    );

    if (!empty($socket)) {
      $connectionInfo['scheme'] = 'unix';
      $connectionInfo['path'] = $socket;
    }

    foreach ($connectionInfo as $key => $value) {
      if (!isset($value)) {
        unset($connectionInfo[$key]);
      }
    }

    // I'm not sure why but the error handler is driven crazy if timezone
    // is not set at this point.
    // Hopefully Drupal will restore the right one this once the current
    // account has logged in.
    date_default_timezone_set(@date_default_timezone_get());

    $client = new \Predis\Client($connectionInfo);

    return $client;
  }

  public function getName() {
    return 'Predis';
  }
}
