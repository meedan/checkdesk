<?php

/**
 * Predis cache backend.
 */
class Redis_Cache_PhpRedis extends Redis_Cache_Base {

  function get($cid) {

    $client = Redis_Client::getClient();
    $key    = $this->getKey($cid);

    $cached = $client->hgetall($key);

    // Recent versions of PhpRedis will return the Redis instance
    // instead of an empty array when the HGETALL target key does
    // not exists. I see what you did there.
    if (empty($cached) || !is_array($cached)) {
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
    $skey   = $this->getKey(Redis_Cache_Base::TEMP_SET);
    $key    = $this->getKey($cid);

    $hash = array(
      'cid' => $cid,
      'created' => time(),
      'expire' => $expire,
      'volatile' => (int)(CACHE_TEMPORARY === $expire),
    );

    // Let Redis handle the data types itself.
    if (!is_string($data)) {
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

      case CACHE_TEMPORARY:
        $lifetime = variable_get('cache_lifetime', Redis_Cache_Base::LIFETIME_DEFAULT);
        if (0 < $lifetime) {
          $pipe->expire($key, $lifetime);
        }
        $pipe->sadd($skey, $cid);
        break;

      case CACHE_PERMANENT:
        if (0 !== ($ttl = $this->getPermTtl())) {
          $pipe->expire($key, $ttl);
        }
        // We dont need the PERSIST command, since it's the default.
        break;

      default:
        // If caller gives us an expiry timestamp in the past
        // the key will expire now and will never be read.
        $ttl = $expire - time();
        if ($ttl < 0) {
          // Behavior between Predis and PhpRedis seems to change here: when
          // setting a negative expire time, PhpRedis seems to ignore the
          // command and leave the key permanent.
          $pipe->expire($key, 0);
        } else {
          $pipe->expire($key, $ttl);
          $pipe->sadd($skey, $cid);
        }
        break;
    }

    $pipe->exec();
  }

  protected function clearWithEval($cid = NULL, $wildcard = FALSE) {

    $client = Redis_Client::getClient();

    // @todo Should I restore the clear mode?
    if (NULL === $cid && FALSE === $wildcard) {
      // Flush volatile keys.
      // Per Drupal core definition, do not expire volatile keys
      // when a default cache lifetime is set.
      if (Redis_Cache_Base::LIFETIME_INFINITE == variable_get('cache_lifetime', Redis_Cache_Base::LIFETIME_DEFAULT)) {
        $ret = $client->eval(self::EVAL_DELETE_VOLATILE, array($this->getKey('*')));
        if (1 != $ret) {
          trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
        }
      }
    }
    else if ('*' !== $cid && $wildcard) {
      // Flush by prefix.
      $ret = $client->eval(self::EVAL_DELETE_PREFIX, array($this->getKey($cid . '*')));
      if (1 != $ret) {
        trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
      }
    }
    else if ('*' === $cid) {
      // Flush everything.
      $ret = $client->eval(self::EVAL_DELETE_PREFIX, array($this->getKey('*')));
      if (1 != $ret) {
        trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
      }
    }
    else if (!$wildcard) {
      $client->del($this->getKey($cid));
    }
  }

  protected function clearWithoutEval($cid = NULL, $wildcard = FALSE) {

    $keys   = array();
    $skey   = $this->getKey(Redis_Cache_Base::TEMP_SET);
    $client = Redis_Client::getClient();

    if (NULL === $cid) {
      switch ($this->getClearMode()) {

        // One and only case of early return.
        case Redis_Cache_Base::FLUSH_NOTHING:
          return;

        // Default behavior.
        case Redis_Cache_Base::FLUSH_TEMPORARY:
          if (Redis_Cache_Base::LIFETIME_INFINITE == variable_get('cache_lifetime', Redis_Cache_Base::LIFETIME_DEFAULT)) {
            $keys[] = $skey;
            foreach ($client->smembers($skey) as $tcid) {
              $keys[] = $this->getKey($tcid);
            }
          }
          break;

        // Fallback on most secure mode: flush full bin.
        default:
        case Redis_Cache_Base::FLUSH_ALL:
          $keys[] = $skey;
          $cid = '*';
          $wildcard = true;
          break;
      }
    }

    if ('*' !== $cid && $wildcard) {
      // Prefix flush.
      $remoteKeys = $client->keys($this->getKey($cid . '*'));
      // PhpRedis seems to suffer of some bugs.
      if (!empty($remoteKeys) && is_array($remoteKeys)) {
        $keys = array_merge($keys, $remoteKeys);
      }
    }
    else if ('*' === $cid) {
      // Full bin flush.
      $remoteKeys = $client->keys($this->getKey('*'));
      // PhpRedis seems to suffer of some bugs.
      if (!empty($remoteKeys) && is_array($remoteKeys)) {
        $keys = array_merge($keys, $remoteKeys);
      }
    }
    else if (empty($keys) && !empty($cid)) {
      // Single key drop.
      $keys[] = $key = $this->getKey($cid);
      $client->srem($skey, $key);
    }

    if (!empty($keys)) {
      if (count($keys) < Redis_Cache_Base::KEY_THRESHOLD) {
        $client->del($keys);
      } else {
        $pipe = $client->multi(Redis::PIPELINE);
        do {
          $buffer = array_splice($keys, 0, Redis_Cache_Base::KEY_THRESHOLD);
          $pipe->del($buffer);
        } while (!empty($keys));
        $pipe->exec();
      }
    }
  }

  function clear($cid = NULL, $wildcard = FALSE) {
    if ($this->canUseEval()) {
      $this->clearWithEval($cid, $wildcard);
    } else {
      $this->clearWithoutEval($cid, $wildcard);
    }
  }

  function isEmpty() {
    // FIXME: Todo.
  }
}
