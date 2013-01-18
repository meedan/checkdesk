<?php

/**
 * Cache backend for Redis module.
 */
class Redis_Cache implements DrupalCacheInterface {
  /**
   * @var DrupalCacheInterface
   */
  protected $backend;

  function __construct($bin) {
    $className = Redis_Client::getClass(Redis_Client::REDIS_IMPL_CACHE);
    $this->backend = new $className($bin);
  }

  function get($cid) {
    return $this->backend->get($cid);
  }

  function getMultiple(&$cids) {
    return $this->backend->getMultiple($cids);
  }

  function set($cid, $data, $expire = CACHE_PERMANENT) {
    $this->backend->set($cid, $data, $expire);
  }

  function clear($cid = NULL, $wildcard = FALSE) {
    // This function also accepts arrays, thus handle everything like an array.
    $cids = is_array($cid) ? $cid : array($cid);
    foreach ($cids as $cid) {
      $this->backend->clear($cid, $wildcard);
    }
  }

  function isEmpty() {
    return $this->backend->isEmpty();
  }
}
