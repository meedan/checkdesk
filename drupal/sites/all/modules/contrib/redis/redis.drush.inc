<?php
/**
 * @file
 * Drush integration.
 */

/**
 * Implements hook_drush_command().
 */
function redis_drush_command() {
  $items = array();

  $items['redis-flush'] = array(
    'description' => 'Flush redis database cache for this site. Caution: can affect other sites using same redis database. Prefer redis-flush-safe.',
    'bootstrap' => DRUPAL_BOOTSTRAP_CONFIGURATION,
  );
  $items['redis-flush-safe'] = array(
    'description' => "Flush redis cache for this site using site prefix. It is advised that you use set the 'redis_eval_enabled' variable to 1 before running this command if your Redis server is >=2.6.",
    'aliases' => array('redis-sflush'),
    'bootstrap' => DRUPAL_BOOTSTRAP_CONFIGURATION,
  );

  return $items;
}

/**
 * Callback for the redis-flush command
 */
function drush_redis_flush() {
  if(!drush_confirm(dt('Do you really want to continue?'))) {
    return drush_user_abort();
  }
  // @todo Not really clean, but this will actually work because the
  // command is the same with both PhpRedis and Predis backends.
  Redis_Client::getClient()->flushdb();
  drush_log('Redis Database was flushed.', 'ok');
}

/**
 * Callback for the redis-flush-safe command
 */
function drush_redis_flush_safe() {
  $GLOBALS['redis_flush_mode'] = Redis_Cache_Base::FLUSH_ALL;
  $redis = new Redis_Cache('*');
  $redis->clear('*', TRUE);
  drush_log('Redis Database was safely flushed.', 'ok');
}
