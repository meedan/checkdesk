<?php

/**
 * Predis lock backend implementation.
 *
 * This implementation works with a single key per lock so is viable when
 * doing client side sharding and/or using consistent hashing algorithm.
 */
class Redis_Lock_Backend_Predis extends Redis_Lock_Backend_Default {

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
        $client->unwatch($key);
        unset($this->_locks[$name]);
        return FALSE;
      }

      switch (Redis_Client_Predis::getPredisVersionMajor()) {

        case 0:
          $replies = $client->pipeline(function($pipe) use ($key, $timeout, $id) {
            $pipe->multi();
            $pipe->setex($key, $timeout, $id);
            $pipe->exec();
          });
          break;

        default:
          $replies = $client->transaction(function($pipe) use ($key, $timeout, $id) {
            $pipe->setex($key, $timeout, $id);
          });
          break;
      }

      $execReply = array_pop($replies);

      if (FALSE === $execReply[0]) {
        unset($this->_locks[$name]);
        return FALSE;
      }

      return TRUE;
    }
    else {
      $client->watch($key);
      $owner = $client->get($key);

      if (!empty($owner) && $owner != $id) {
        $client->unwatch();
        unset($this->_locks[$name]);
        return FALSE;
      }

      $replies = $client->pipeline(function($pipe) use ($key, $timeout, $id) {
        $pipe->multi();
        $pipe->setex($key, $timeout, $id);
        $pipe->exec();
      });

      $execReply = array_pop($replies);

      // If another client modified the $key value, transaction will be discarded
      // $result will be set to FALSE. This means atomicity have been broken and
      // the other client took the lock instead of us.
      // EXPIRE and SETEX won't return something here, EXEC return is index 0
      // This was determined debugging, seems to be Predis specific.
      if (FALSE === $execReply[0]) {
        return FALSE;
      }

      // Register the lock and return.
      return ($this->_locks[$name] = TRUE);
    }

    return FALSE;
  }

  public function lockMayBeAvailable($name) {
    $client = Redis_Client::getClient();
    $key    = $this->getKey($name);
    $id     = $this->getLockId();

    $value = $client->get($key);

    return empty($value) || $id == $value;
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
      $client->del(array($key));
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
        $client->del(array($key));
      }
    }
  }
}

