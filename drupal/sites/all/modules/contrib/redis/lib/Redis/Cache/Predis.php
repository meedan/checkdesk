<?php

/**
 * Predis cache backend.
 */
class Redis_Cache_Predis extends Redis_Cache_Base {

  function get($cid) {

    $client = Redis_Client::getClient();
    $key    = $this->getKey($cid);

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
    $ret    = $keys = array();
    $keys   = array_map(array($this, 'getKey'), $cids);

    $replies = $client->pipeline(function($pipe) use ($keys) {
      foreach ($keys as $key) {
        $pipe->hgetall($key);
      }
    });

    foreach ($replies as $reply) {
      if (!empty($reply)) {

        // HGETALL signature seems to differ depending on Predis versions.
        // This was found just after Predis update. Even though I'm not sure
        // this comes from Predis or just because we're misusing it.
        // FIXME: Needs some investigation.
        if (!isset($reply['cid'])) {
          $cache = new stdClass();
          $size = count($reply);
          for ($i = 0; $i < $size; ++$i) {
            $cache->{$reply[$i]} = $reply[++$i];
          }
        } else {
          $cache = (object)$reply;
        }

        if ($cache->serialized) {
          $cache->data = unserialize($cache->data);
        }

        $ret[$cache->cid] = $cache;
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
    $self   = $this;

    $client->pipeline(function($pipe) use ($cid, $key, $skey, $data, $expire, $self) {

      $hash = array(
        'cid' => $cid,
        'created' => time(),
        'expire' => $expire,
        'volatile' => (int)CACHE_TEMPORARY === $expire,
      );

      if (!is_string($data)) {
        $hash['data'] = serialize($data);
        $hash['serialized'] = 1;
      }
      else {
        $hash['data'] = $data;
        $hash['serialized'] = 0;
      }

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
          if (0 !== ($ttl = $self->getPermTtl())) {
            $pipe->expire($key, $ttl);
          }
          // We dont need the PERSIST command we want the cache item to
          // never expire.
          break;

        default:
          // If caller gives us an expiry timestamp in the past
          // the key will expire now and will never be read.
          $ttl = $expire - time();
          $pipe->expire($key, $ttl);
          if (0 < $ttl) {
            $pipe->sadd($skey, $cid);
          }
          break;
      }
    });
  }

  protected function clearWithEval($cid = NULL, $wildcard = FALSE) {

    $client = Redis_Client::getClient();

    // @todo Should I restore the clear mode?
    if (NULL === $cid && FALSE === $wildcard) {
      // Flush volatile keys.
      // Per Drupal core definition, do not expire volatile keys
      // when a default cache lifetime is set.
      if (Redis_Cache_Base::LIFETIME_INFINITE == variable_get('cache_lifetime', Redis_Cache_Base::LIFETIME_DEFAULT)) {
        $ret = $client->eval(self::EVAL_DELETE_VOLATILE, 0, $this->getKey('*'));
        if (1 != $ret) {
          trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
        }
      }
    }
    else if ('*' !== $cid && $wildcard) {
      // Flush by prefix.
      $ret = $client->eval(self::EVAL_DELETE_PREFIX, 0, $this->getKey($cid . '*'));
      if (1 != $ret) {
        trigger_error(sprintf("EVAL failed: %s", $client->getLastError()), E_USER_ERROR);
      }
    }
    else if ('*' === $cid) {
      // Flush everything.
      $ret = $client->eval(self::EVAL_DELETE_PREFIX, 0, $this->getKey('*'));
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
      $keys = array_merge($keys, $client->keys($this->getKey($cid . '*')));
    }
    else if ('*' === $cid) {
      // Full bin flush.
      $keys = array_merge($keys, $client->keys($this->getKey('*')));
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
        $client->pipeline(function($pipe) use ($keys) {
          do {
            $buffer = array_splice($keys, 0, Redis_Cache_Base::KEY_THRESHOLD);
            $pipe->del($buffer);
          } while (!empty($keys));
        });
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
