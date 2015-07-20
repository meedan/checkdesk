<?php

/**
 * Because those objects will be spawned during boostrap all its configuration
 * must be set in the settings.php file.
 *
 * For a detailed history of flush modes see:
 *   https://drupal.org/node/1980250
 *
 * You will find the driver specific implementation in the Redis_Cache_*
 * classes as they may differ in how the API handles transaction, pipelining
 * and return values.
 */
abstract class Redis_Cache_Base extends Redis_AbstractBackend implements
    DrupalCacheInterface
{
  /**
   * Temporary cache items lifetime is infinite.
   */
  const LIFETIME_INFINITE = 0;

  /**
   * Default temporary cache items lifetime.
   */
  const LIFETIME_DEFAULT = 0;

  /**
   * Default lifetime for permanent items.
   * Approximatively 1 year.
   */
  const LIFETIME_PERM_DEFAULT = 31536000;

  /**
   * Flush nothing on generic clear().
   *
   * Because Redis handles keys TTL by itself we don't need to pragmatically
   * flush items by ourselves in most case: only 2 exceptions are the "page"
   * and "block" bins which are never expired manually outside of cron.
   */
  const FLUSH_NOTHING = 0;

  /**
   * Flush only temporary on generic clear().
   *
   * This dictate the cache backend to behave as the DatabaseCache default
   * implementation. This behavior is not documented anywere but hardcoded
   * there.
   */
  const FLUSH_TEMPORARY = 1;

  /**
   * Flush all on generic clear().
   *
   * This is a failsafe performance unwise behavior that probably no
   * one should ever use: it will force all items even those which are
   * still valid or permanent to be flushed. It exists only in order
   * to mimic the behavior of the pre 1.0 release of this module.
   */
  const FLUSH_ALL = 2;

  /**
   * Computed keys are let's say arround 60 characters length due to
   * key prefixing, which makes 1,000 keys DEL command to be something
   * arround 50,000 bytes length: this is huge and may not pass into
   * Redis, let's split this off.
   * Some recommend to never get higher than 1,500 bytes within the same
   * command which makes us forced to split this at a very low threshold:
   * 20 seems a safe value here (1,280 average length).
   */
  const KEY_THRESHOLD = 20;

  /**
   * Temporary items SET name.
   */
  const TEMP_SET = 'temporary_items';

  /**
   * Delete by prefix lua script
   */
  const EVAL_DELETE_PREFIX = <<<EOT
local keys = redis.call("KEYS", ARGV[1])
for i, k in ipairs(keys) do
    redis.call("DEL", k)
end
return 1
EOT;

  /**
   * Delete volatile by prefix lua script
   */
  const EVAL_DELETE_VOLATILE = <<<EOT
local keys = redis.call('KEYS', ARGV[1])
for i, k in ipairs(keys) do
    local key_type = redis.call("TYPE", k)
    if "hash" == key_type and "1" == redis.call("HGET", k, "volatile") then
        redis.call("DEL", k)
    end
end
return 1
EOT;

  /**
   * @var string
   */
  protected $bin;

  /**
   * @var int
   */
  protected $clearMode = self::FLUSH_TEMPORARY;

  /**
   * Can this instance use EVAL.
   *
   * @var boolean
   */
  protected $useEval = false;

  /**
   * Tell if the backend can use EVAL commands.
   */
  public function canUseEval() {
    return $this->useEval;
  }

  /**
   * Default TTL for CACHE_PERMANENT items.
   *
   * See "Default lifetime for permanent items" section of README.txt
   * file for a comprehensive explaination of why this exists.
   *
   * @var int
   */
  protected $permTtl = self::LIFETIME_PERM_DEFAULT;

  /**
   * Get clear mode.
   *
   * @return int
   *   One of the Redis_Cache_Base::FLUSH_* constant.
   */
  public function getClearMode() {
    return $this->clearMode;
  }

  /**
   * Get TTL for CACHE_PERMANENT items.
   *
   * @return int
   *   Lifetime in seconds.
   */
  public function getPermTtl() {
    return $this->permTtl;
  }

  public function __construct($bin) {

    parent::__construct($bin);

    $this->bin = $bin;

    // Check if the server can use EVAL
    if (variable_get('redis_eval_enabled', false)) {
      $this->useEval = true;
    }

    if (null !== ($mode = variable_get('redis_flush_mode_' . $this->bin, null))) {
      // A bin specific flush mode has been set.
      $this->clearMode = (int)$mode;
    } else if (null !== ($mode = variable_get('redis_flush_mode', null))) {
      // A site wide generic flush mode has been set.
      $this->clearMode = (int)$mode;
    } else {
      // No flush mode is set by configuration: provide sensible defaults.
      // See FLUSH_* constants for comprehensible explaination of why this
      // exists.
      switch ($this->bin) {

        case 'cache_page':
        case 'cache_block':
          $this->clearMode = self::FLUSH_TEMPORARY;
          break;

        default:
          $this->clearMode = self::FLUSH_NOTHING;
          break;
      }
    }

    $ttl = null;
    if (null === ($ttl = variable_get('redis_perm_ttl_' . $this->bin, null))) {
      if (null === ($ttl = variable_get('redis_perm_ttl', null))) {
        $ttl = self::LIFETIME_PERM_DEFAULT;
      }
    }
    if ($ttl === (int)$ttl) {
      $this->permTtl = $ttl;
    } else {
      if ($iv = DateInterval::createFromDateString($ttl)) {
        // http://stackoverflow.com/questions/14277611/convert-dateinterval-object-to-seconds-in-php
        $this->permTtl = ($iv->y * 31536000 + $iv->m * 2592000 + $iv->days * 86400 + $iv->h * 3600 + $iv->i * 60 + $iv->s);
      } else {
        // Sorry but we have to log this somehow.
        trigger_error(sprintf("Parsed TTL '%s' has an invalid value: switching to default", $ttl));
        $this->permTtl = self::LIFETIME_PERM_DEFAULT;
      }
    }
  }

  public function getKey($cid = null) {
    if (null === $cid) {
      return parent::getKey($this->bin);
    } else {
      return parent::getKey($this->bin . ':' . $cid);
    }
  }
}
