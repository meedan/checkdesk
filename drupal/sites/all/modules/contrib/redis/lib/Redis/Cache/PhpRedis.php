<?php

/**
 * Predis cache backend.
 */
class Redis_Cache_PhpRedis extends Redis_Cache_Base {

  function get($cid) {
    $client     = Redis_Client::getClient();
    $key        = $this->getKey($cid);

    $cached = $client->hgetall($key);

    if (empty($cached)) {
      return FALSE;
    }

    $cached = (object)$cached;

    if ($cached->serialized) {
      $cached->data = unserialize($cached->data);
    }

    return $cached;
  }

  function getMultiple(&$cids) {
    $client = Redis_Client::getClient();

    $ret = array();
    $keys = array_map(array($this, 'getKey'), $cids);

    $pipe = $client->multi(Redis::PIPELINE);
    foreach ($keys as $key) {
      $pipe->hgetall($key);
    }
    $replies = $pipe->exec();

    foreach ($replies as $reply) {
      if (!empty($reply)) {
        $cached = (object)$reply;

        if ($cached->serialized) {
          $cached->data = unserialize($cached->data);
        }

        $ret[$cached->cid] = $cached;
      }
    }

    foreach ($cids as $index => $cid) {
      if (isset($ret[$cid])) {
        unset($cids[$index]);
      }
    }

    return $ret;
  }

  function set($cid, $data, $expire = CACHE_PERMANENT) {
    $client = Redis_Client::getClient();
    $key    = $this->getKey($cid);

    $hash = array(
      'cid' => $cid,
      'created' => time(),
      'expire' => $expire,
    );

    // Let Redis handle the data types itself.
    if (!is_scalar($data)) {
      $hash['data'] = serialize($data);
      $hash['serialized'] = 1;
    }
    else {
      $hash['data'] = $data;
      $hash['serialized'] = 0;
    }

    $pipe = $client->multi(Redis::PIPELINE);
    $pipe->hmset($key, $hash);

    switch ($expire) {

      // FIXME: Handle CACHE_TEMPORARY correctly.
      case CACHE_TEMPORARY:
      case CACHE_PERMANENT:
        // We dont need the PERSIST command, since it's the default.
        break;

      default:
        $delay = $expire - time();
        $pipe->expire($key, $delay);
    }

    $pipe->exec();
  }

  function clear($cid = NULL, $wildcard = FALSE) {
    $client = Redis_Client::getClient();
    $many   = FALSE;

    // We cannot determine which keys are going to expire, so we need to flush
    // the full bin case we have an explicit NULL provided. This means that
    // stuff like block and cache pages may be expired too often.
    if (NULL === $cid) {
      $key = $this->getKey('*');
      $many = TRUE;
    }
    else if ('*' !== $cid && $wildcard) {
      $key  = $this->getKey($cid . '*');
      $many = TRUE;
    }
    else if ('*' === $cid) {
      $key  = $this->getKey($cid);
      $many = TRUE;
    }
    else {
      $key = $this->getKey($cid);
    }

    if ($many) {
      $keys = $client->keys($key);

      // Attempt to clear an empty array will raise exceptions.
      if (!empty($keys)) {
        $client->del($keys);
      }
    }
    else {
      $client->del(array($key));
    }
  }

  function isEmpty() {
    // FIXME: Todo.
  }
}
