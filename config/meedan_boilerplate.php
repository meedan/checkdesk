<?php

/**
 * CONSTANTS
 */

// The constant MEEDAN_ENVIRONMENT will fairly reliably determine if a site is
// running on production or not.  When uncertain it always assumes it is running
// in production, for safety.
// 
// DO NOT use this constant for important or dangerous tasks!
$is_dev  = preg_match('@(local(host)?$|(^|\.)dev\.)@', $_SERVER['HTTP_HOST']);
$is_test = preg_match('@(^|\.)(test|testing|qa)\.@', $_SERVER['HTTP_HOST']);

define('MEEDAN_ENVIRONMENT', ($is_dev ? 'DEV' : ($is_test ? 'TEST' : 'LIVE')));
