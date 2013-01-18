<?php

/**
 * Lock backend interface.
 */
interface Redis_Lock_Backend_Interface {
  /**
   * Acquire lock.
   * 
   * @param string $name
   *   Lock name.
   * @param float $timeout = 30.0
   *   (optional) Lock lifetime in seconds.
   * 
   * @return bool
   */
  public function lockAcquire($name, $timeout = 30.0);

  /**
   * Check if lock is available for acquire.
   * 
   * @param string $name
   *   Lock to acquire.
   * 
   * @return bool
   */
  public function lockMayBeAvailable($name);

  /**
   * Wait a short amount of time before a second lock acquire attempt.
   * 
   * @param string $name
   *   Lock name currently being locked.
   * @param int $delay = 30
   *   Miliseconds to wait for.
   */
  public function lockWait($name, $delay = 30);

  /**
   * Release given lock.
   * 
   * @param string $name
   */
  public function lockRelease($name);

  /**
   * Release all locks for the given lock token identifier.
   * 
   * @param string $lockId = NULL
   *   (optional) If none given, remove all lock from the current page.
   */
  public function lockReleaseAll($lock_id = NULL);

  /**
   * Get the unique page token for locks. Locks will be wipeout at each end of
   * page request on a token basis.
   * 
   * @return string
   */
  public function getLockId();
}
