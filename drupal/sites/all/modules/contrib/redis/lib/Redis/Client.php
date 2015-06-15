<?php

// It may happen we get here with no autoloader set during the Drupal core
// early bootstrap phase, at cache backend init time.
if (!interface_exists('Redis_Client_Interface')) {
  require_once dirname(__FILE__) . '/Client/Interface.php';
}

/**
 * Common code and client singleton, for all Redis clients.
 */
class Redis_Client {
  /**
   * Redis default host.
   */
  const REDIS_DEFAULT_HOST = "127.0.0.1";

  /**
   * Redis default port.
   */
  const REDIS_DEFAULT_PORT = 6379;

  /**
   * Redis default socket (not use).
   */
  const REDIS_DEFAULT_SOCKET = NULL;

  /**
   * Redis default database: will select none (Database 0).
   */
  const REDIS_DEFAULT_BASE = NULL;

  /**
   * Redis default password: will not authenticate.
   */
  const REDIS_DEFAULT_PASSWORD = NULL;

  /**
   * Cache implementation namespace.
   */
  const REDIS_IMPL_CACHE = 'Redis_Cache_';

  /**
   * Lock implementation namespace.
   */
  const REDIS_IMPL_LOCK = 'Redis_Lock_Backend_';

  /**
   * Cache implementation namespace.
   */
  const REDIS_IMPL_QUEUE = 'Redis_Queue_';

  /**
   * Session implementation namespace.
   */
  const REDIS_IMPL_SESSION = 'Redis_Session_Backend_';

  /**
   * Session implementation namespace.
   */
  const REDIS_IMPL_PATH = 'Redis_Path_';

  /**
   * Session implementation namespace.
   */
  const REDIS_IMPL_CLIENT = 'Redis_Client_';

  /**
   * @var Redis_Client_Interface
   */
  protected static $_clientInterface;

  /**
   * @var mixed
   */
  protected static $_client;

  /**
   * @var string
   */
  protected static $globalPrefix;

  /**
   * Has this instance a client set.
   *
   * @return boolean
   */
  public static function hasClient() {
    return isset(self::$_client);
  }

  /**
   * Set client proxy.
   */
  public static function setClient(Redis_Client_Interface $interface) {
    if (isset(self::$_client)) {
      throw new Exception("Once Redis client is connected, you cannot change client proxy instance.");
    }

    self::$_clientInterface = $interface;
  }

  /**
   * Lazy instanciate client proxy depending on the actual configuration.
   * 
   * If you are using a lock, session or cache backend using one of the Redis
   * client implementation, this will be overrided at early bootstrap phase
   * and configuration will be ignored.
   * 
   * @return Redis_Client_Interface
   */
  public static function getClientInterface() {
    global $conf;

    if (!isset(self::$_clientInterface)) {
      if (!empty($conf['redis_client_interface'])) {
        $className = self::getClass(self::REDIS_IMPL_CLIENT, $conf['redis_client_interface']);
        self::$_clientInterface = new $className();
      }
      else if (class_exists('Predis\Client')) {
        // Transparent and abitrary preference for Predis library.
        $className = self::getClass(self::REDIS_IMPL_CLIENT, 'Predis');
        self::$_clientInterface = new $className();
      }
      else if (class_exists('Redis')) {
        // Fallback on PhpRedis if available.
        $className = self::getClass(self::REDIS_IMPL_CLIENT, 'PhpRedis');
        self::$_clientInterface = new $className();
      }
      else {
        if (!isset(self::$_clientInterface)) {
          throw new Exception("No client interface set.");
        }
      }
    }

    return self::$_clientInterface;
  }

  /**
   * Get underlaying library name.
   * 
   * @return string
   */
  public static function getClientName() {
    return self::getClientInterface()->getName();
  }

  /**
   * Get client singleton.
   */
  public static function getClient() {
    if (!isset(self::$_client)) {
      global $conf;

      // Always prefer socket connection.
      self::$_client = self::getClientInterface()->getClient(
        isset($conf['redis_client_host']) ? $conf['redis_client_host'] : self::REDIS_DEFAULT_HOST,
        isset($conf['redis_client_port']) ? $conf['redis_client_port'] : self::REDIS_DEFAULT_PORT,
        isset($conf['redis_client_base']) ? $conf['redis_client_base'] : self::REDIS_DEFAULT_BASE,
        isset($conf['redis_client_password']) ? $conf['redis_client_password'] : self::REDIS_DEFAULT_PASSWORD,
        isset($conf['redis_client_socket']) ? $conf['redis_client_socket'] : self::REDIS_DEFAULT_SOCKET
      );
    }

    return self::$_client;
  }

  /**
   * Get specific class implementing the current client usage for the specific
   * asked core subsystem.
   * 
   * @param string $system
   *   One of the Redis_Client::IMPL_* constant.
   * @param string $clientName
   *   Client name, if fixed.
   * 
   * @return string
   *   Class name, if found.
   * 
   * @throws Exception
   *   If not found.
   */
  public static function getClass($system, $clientName = NULL) {
    $className = $system . (isset($clientName) ? $clientName : self::getClientName());

    if (!class_exists($className)) {
      throw new Exception($className . " does not exists");
    }

    return $className;
  }

  /**
   * For unit testing only reset internals.
   */
  static public function reset() {
    self::$globalPrefix = null;
    self::$_clientInterface = null;
    self::$_client = null;
  }
}

