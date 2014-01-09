<?php

abstract class Redis_AbstractBackend
{
    /**
     * Get global default prefix
     *
     * @param string $suffix
     *
     * @return string
     */
    static public function getDefaultPrefix($suffix = null)
    {
        $ret = null;

        if (isset($GLOBALS['drupal_test_info']) && !empty($test_info['test_run_id'])) {
            $ret = $test_info['test_run_id'];
        } else {
            $prefixes = variable_get('cache_prefix', '');

            if (is_string($prefixes)) {
                // Variable can be a string which then considered as a default
                // behavior.
                $ret = $prefixes;
            } else if (null !== $suffix && isset($prefixes[$suffix])) {
                if (false !== $prefixes[$suffix]) {
                    // If entry is set and not false an explicit prefix is set
                    // for the bin.
                    $ret = $prefixes[$suffix];
                } else {
                    // If we have an explicit false it means no prefix whatever
                    // is the default configuration.
                    $ret = '';
                }
            } else {
                // Key is not set, we can safely rely on default behavior.
                if (isset($prefixes['default']) && false !== $prefixes['default']) {
                    $ret = $prefixes['default'];
                } else {
                    // When default is not set or an explicit false this means
                    // no prefix.
                    $ret = '';
                }
            }
        }

        if (empty($ret) && isset($_SERVER['HTTP_HOST'])) {
            // Provide a fallback for multisite. This is on purpose not inside the
            // getPrefixForBin() function in order to decouple the unified prefix
            // variable logic and custom module related security logic, that is not
            // necessary for all backends.
            $ret = $_SERVER['HTTP_HOST'] . '_';
        }

        return $ret;
    }

    /**
     * @var string
     */
    private $prefix;

    /**
     * Default constructor
     */
    public function __construct($prefix = null)
    {
        if (null === $prefix) {
            $this->prefix = $prefix = self::getDefaultPrefix();
        } else {
            $this->prefix = $prefix;
        }
    }

    /**
     * Set prefix
     *
     * @param string $prefix
     */
    final public function setPrefix($prefix)
    {
        $this->prefix = $prefix;
    }

    /**
     * Get prefix
     *
     * @return string
     */
    final public function getPrefix()
    {
        return $this->prefix;
    }

    /**
     * Get full key name using the set prefix
     *
     * @param string $name
     *
     * @return string
     */
    public function getKey($name = null)
    {
        if (null === $name) {
            return $this->prefix;
        } else {
            return $this->prefix . ':' . $name;
        }
    }
}
