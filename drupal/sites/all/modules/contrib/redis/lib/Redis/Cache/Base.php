<?php

abstract class Redis_Cache_Base implements DrupalCacheInterface {
  /**
   * @var string
   */
  protected $bin;

  /**
   * @var string
   */
  protected $prefix;

  /**
   * Get prefix for bin using the configuration.
   * 
   * @param string $bin
   * 
   * @return string
   *   Can be an empty string, if no prefix set.
   */
  protected static function getPrefixForBin($bin) {
    if (isset($GLOBALS['drupal_test_info']) && !empty($test_info['test_run_id'])) {
      return $test_info['test_run_id'];
    } else {
      $prefixes = variable_get('cache_prefix', '');

      if (is_string($prefixes)) {
        // Variable can be a string, which then considered as a default behavior.
        return $prefixes;
      }

      if (isset($prefixes[$bin])) {
        if (FALSE !== $prefixes[$bin]) {
          // If entry is set and not FALSE, an explicit prefix is set for the bin.
          return $prefixes[$bin];
        } else {
          // If we have an explicit false, it means no prefix whatever is the
          // default configuration.
          return '';
        }
      } else {
        // Key is not set, we can safely rely on default behavior.
        if (isset($prefixes['default']) && FALSE !== $prefixes['default']) {
          return $prefixes['default'];
        } else {
          // When default is not set or an explicit FALSE, this means no prefix.
          return '';
        }
      }
    }
  }

  function __construct($bin) {
    $this->bin = $bin;

    $prefix = self::getPrefixForBin($this->bin);

    if (empty($prefix) && isset($_SERVER['HTTP_HOST'])) {
      // Provide a fallback for multisite. This is on purpose not inside the
      // getPrefixForBin() function in order to decouple the unified prefix
      // variable logic and custom module related security logic, that is not
      // necessary for all backends.
      $this->prefix = $_SERVER['HTTP_HOST'] . '_';
    } else {
      $this->prefix = $prefix;
    }
  }

  protected function getKey($cid) {
    return $this->prefix . $this->bin . ':' . $cid;
  }
}
