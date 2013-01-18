<?php

/**
 * Lock backend singleton handling.
 */
class Redis_Lock {
  /**
   * @var Redis_Lock_Backend_Interface
   */
  private static $instance;

  /**
   * Get actual lock backend.
   * 
   * @return Redis_Lock_Backend_Interface
   */
  public static function getBackend() {
    if (!isset(self::$instance)) {
      $className = Redis_Client::getClass(Redis_Client::REDIS_IMPL_LOCK);
      self::$instance = new $className();
    }
    return self::$instance;
  }
}
