<?php

/**
 * @file
 * Defines constants included in both traceview.module and traceview.install.
 */

// These constants are defined here because traceview.module is not included
// during install until after hook_requirements passes and they are used in
// traceview_requirements().

// The latest tested and confirmed working version of the oboe PHP extension.
define('TRACEVIEW_LATEST_CONFIRMED_VERSION', '1.4.5');

// Versions that are known to have problems and are not recommended.
define('TRACEVIEW_BAD_VERSIONS', serialize(array('1.4.2', '1.4.4')));
