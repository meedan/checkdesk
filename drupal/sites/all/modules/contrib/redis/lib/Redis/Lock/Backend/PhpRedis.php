<?php

/**
 * Predis lock backend implementation.
 *
 * This implementation works with a single key per lock so is viable when
 * doing client side sharding and/or using consistent hashing algorithm.
 */
class Redis_Lock_Backend_PhpRedis extends Redis_Lock_Backend_Default {

  public function lockAcquire($name, $timeout = 30.0) {
    $client = Redis_Client::getClient();
    $key    = $this->getKey($name);
    $id     = $this->getLockId();

    // Insure that the timeout is at least 1 second, we cannot do otherwise with
    // Redis, this is a minor change to the function signature, but in real life
    // nobody will notice with so short duration.
    $timeout = ceil(max($timeout, 1));

    // If we already have the lock, check for his owner and attempt a new EXPIRE
    // command on it.
    if (isset($this->_locks[$name])) {

      // Create a new transaction, for atomicity.
      $client->watch($key);

      // Global tells us we are the owner, but in real life it could have expired
      // and another process could have taken it, check that.
      if ($client->get($key) != $id) {
        // Explicit UNWATCH we are not going to run the MULTI/EXEC block.
        $client->unwatch();
        unset($this->_locks[$name]);
        return FALSE;
      }

      // See https://github.com/nicolasff/phpredis#watch-unwatch
      // MULTI and other commands can fail, so we can't chain calls.
      if (FALSE !== ($result = $client->multi())) {
        $client->setex($key, $timeout, $id);
        $result = $client->exec();
      }

      // Did it broke?
      if (FALSE === $result) {
        unset($this->_locks[$name]);
        // Explicit transaction release which also frees the WATCH'ed key.
        $client->discard();
        return FALSE;
      }

      return ($this->_locks[$name] = TRUE);
    }
    else {
      $client->watch($key);
      $owner = $client->get($key);

      // If the $key is set they lock is not available
      if (!empty($owner) && $id != $owner) {
        $client->unwatch();
        return FALSE;
      }

      // See https://github.com/nicolasff/phpredis#watch-unwatch
      // MULTI and other commands can fail, so we can't chain calls.
      if (FALSE !== ($result = $client->multi())) {
        $client->setex($key, $timeout, $id);
        $result->exec();
      }

      // If another client modified the $key value, transaction will be discarded
      // $result will be set to FALSE. This means atomicity have been broken and
      // the other client took the lock instead of us.
      if (FALSE === $result) {
        // Explicit transaction release which also frees the WATCH'ed key.
        $client->discard();
        return FALSE;
      }

      // Register the lock.
      return ($this->_locks[$name] = TRUE);
    }

    return FALSE;
  }

  public function lockMayBeAvailable($name) {
    $client = Redis_Client::getClient();
    $key    = $this->getKey($name);
    $id     = $this->getLockId();

    $value = $client->get($key);

    return FALSE === $value || $id == $value;
  }

  public function lockRelease($name) {
    $client = Redis_Client::getClient();
    $key    = $this->getKey($name);
    $id     = $this->getLockId();

    unset($this->_locks[$name]);

    // Ensure the lock deletion is an atomic transaction. If another thread
    // manages to removes all lock, we can not alter it anymore else we will
    // release the lock for the other thread and cause race conditions.
    $client->watch($key);

    if ($client->get($key) == $id) {
      $client->multi();
      $client->delete($key);
      $client->exec();
    }
    else {
      $client->unwatch();
    }
  }

  public function lockReleaseAll($lock_id = NULL) {
    if (!isset($lock_id) && empty($this->_locks)) {
      return;
    }

    $client = Redis_Client::getClient();
    $id     = isset($lock_id) ? $lock_id : $this->getLockId();

    // We can afford to deal with a slow algorithm here, this should not happen
    // on normal run because we should have removed manually all our locks.
    foreach ($this->_locks as $name => $foo) {
      $key   = $this->getKey($name);
      $owner = $client->get($key);

      if (empty($owner) || $owner == $id) {
        $client->delete($key);
      }
    }
  }
}
