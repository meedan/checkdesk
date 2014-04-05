Redis cache backends
====================

This package provides two different Redis cache backends. If you want to use
Redis as cache backend, you have to choose one of the two, but you cannot use
both at the same time. Well, it will be technically possible, but it would be
quite a dumb thing to do.

Predis
------

This implementation uses the Predis PHP library. It is compatible PHP 5.3
only, and need Redis >= 2.1.0 for using the WATCH command.

PhpRedis
--------

This implementation uses the PhpRedis PHP extention. In order to use it, you
will need to compile the extension yourself.

Redis version
-------------

Be careful with lock.inc replacement, actual implementation uses the Redis
WATCH command, it is actually there only since version 2.1.0. If you use
the it, it will just pass silently and work gracefully, but lock exclusive
mutex is exposed to race conditions.

Use Redis 2.1.0 or later if you can! I warned you.

Notes
-----

Both backends provide the exact same functionnalities. The major difference is
because PhpRedis uses a PHP extension, and not PHP code, it more performant.

Difference is not that visible, it's really a few millisec on my testing box.

Note that most of the settings are shared. See next sections.

Important notice
----------------

This module only supports Redis >= 2.4 due to the missing WATCH command in
Redis <= 2.2. Using it with older versions is untested, might work but might
also cause you serious trouble. Any bug report raised using such version will
be ignored.

Install
=======

Choose the Redis client library to use
--------------------------------------

Add into your settings.php file:

  $conf['redis_client_interface']      = 'PhpRedis';

You can replace 'PhpRedis' with 'Predis', depending on the library you chose. 

Note that this is optionnal but recommended. If you don't set this variable the
module will proceed to class lookups and attempt to choose the best client
available, having always a preference for the Predis one.

Tell Drupal to use the cache backend
------------------------------------

Usual cache backend configuration, as follows, to add into your settings.php
file like any other backend:

  $conf['cache_backends'][]            = 'sites/all/modules/redis/redis.autoload.inc';
  $conf['cache_class_cache']           = 'Redis_Cache';
  $conf['cache_class_cache_menu']      = 'Redis_Cache';
  $conf['cache_class_cache_bootstrap'] = 'Redis_Cache';
  // ... Any other bins.

Tell Drupal to use the lock backend
-----------------------------------

Usual lock backend override, update you settings.php file as this:

  $conf['lock_inc'] = 'sites/all/modules/redis/redis.lock.inc';

Drupal 6 and lock backend
-------------------------

Considering this is a Drupal 7 module only downloading it in Drupal 6 will make
the module UI telling you this module is unsupported yet you can use the lock
backend on Drupal 6.

Read your Drupal 6 core documentation and use the redis.lock.inc file as
lock_inc replacement the same way its being done for Drupal 7 and it should
work. Note that this is untested by the module maintainer (feedback will be
greatly appreciated).

Common settings
===============

Connect to a remote host
------------------------

If your Redis instance is remote, you can use this syntax:

  $conf['redis_client_host'] = '1.2.3.4';
  $conf['redis_client_port'] = 1234;

Port is optional, default is 6379 (default Redis port).

Using a specific database
-------------------------

Per default, Redis ships the database "0". All default connections will be use
this one if nothing is specified.

Depending on you OS or OS distribution, you might have numerous database. To
use one in particular, just add to your settings.php file:

  $conf['redis_client_base'] = 12;

Connection to a password protected instance
-------------------------------------------

If you are using a password protected instance, specify the password this way:

  $conf['redis_client_password'] = "mypassword";

Depending on the backend, using a wrong auth will behave differently:

 - Predis will throw an exception and make Drupal fail during early boostrap.

 - PhpRedis will make Redis calls silent and creates some PHP warnings, thus
   Drupal will behave as if it was running with a null cache backend (no cache
   at all).

Prefixing site cache entries (avoiding sites name collision)
------------------------------------------------------------

If you need to differenciate multiple sites using the same Redis instance and
database, you will need to specify a prefix for your site cache entries.

Cache prefix configuration attemps to use a unified variable accross contrib
backends that support this feature. This variable name is 'cache_prefix'.

This variable is polymorphic, the simplest version is to provide a raw string
that will be the default prefix for all cache bins:

  $conf['cache_prefix'] = 'mysite_';

Alternatively, to provide the same functionnality, you can provide the variable
as an array:

  $conf['cache_prefix']['default'] = 'mysite_';

This allows you to provide different prefix depending on the bin name. Common
usage is that each key inside the 'cache_prefix' array is a bin name, the value
the associated prefix. If the value is explicitely FALSE, then no prefix is
used for this bin.

The 'default' meta bin name is provided to define the default prefix for non
specified bins. It behaves like the other names, which means that an explicit
FALSE will order the backend not to provide any prefix for any non specified
bin.

Here is a complex sample:

  // Default behavior for all bins, prefix is 'mysite_'.
  $conf['cache_prefix']['default'] = 'mysite_';

  // Set no prefix explicitely for 'cache' and 'cache_bootstrap' bins.
  $conf['cache_prefix']['cache'] = FALSE;
  $conf['cache_prefix']['cache_bootstrap'] = FALSE;

  // Set another prefix for 'cache_menu' bin.
  $conf['cache_prefix']['cache_menu'] = 'menumysite_';

Note that if you don't specify the default behavior, the Redis module will
attempt to use the HTTP_HOST variable in order to provide a multisite safe
default behavior. Notice that this is not failsafe, in such environment you
are strongly advised to set at least an explicit default prefix.

Note that this last notice is Redis only specific, because per default Redis
server will not namespace data, thus sharing an instance for multiple sites
will create conflicts. This is not true for every contributed backends.

Flush mode
----------

Redis allows to set a time-to-live at the key level, which frees us from
handling the garbage collection at clear() calls; Unfortunately Drupal never
explicitely clears single cached pages or blocks. If you didn't configure the
"cache_lifetime" core variable, its value is "0" which means that temporary
items never expire: in this specific case, we need to adopt a different
behavior than leting Redis handling the TTL by itself; This is why we have
three different implementations of the flush algorithm you can use:

 * 0: Never flush temporary: leave Redis handling the TTL; This mode is
   not compatible for the "page" and "block" bins but is the default for
   all others.

 * 1: Keep a copy of temporary items identifiers in a SET and flush them
   accordingly to spec (DatabaseCache default backend mimic behavior):
   this is the default for "page" and "block" bin if you don't change the
   configuration.

 * 2: Flush everything including permanent or valid items on clear() calls:
   this behavior mimics the pre-1.0 releases of this module. Use it only
   if you experience backward compatibility problems on a production
   environement - at the cost of potential performance issues; All other
   users should ignore this parameter.

You can configure a default flush mode which will override the sensible
provided defaults by setting the 'redis_flush_mode' variable.

  // For example this is the safer mode.
  $conf['redis_flush_mode'] = 1;

But you may also want to change the behavior for only a few bins.

  // This will put mode 0 on "bootstrap" bin.
  $conf['redis_flush_mode_cache_bootstrap'] = 0;

  // And mode 2 to "page" bin.
  $conf['redis_flush_mode_cache_page'] = 2;

Note that you must prefix your bins with "cache" as the Drupal 7 bin naming
convention requires it.

Keep in mind that defaults will provide the best balance between performance
and safety for most sites; Non advanced users should ever change them.

Default lifetime for permanent items
------------------------------------

Redis when reaching its maximum memory limit will stop writing data in its
storage engine: this is a feature that avoid the Redis server crashing when
there is no memory left on the machine.

As a workaround, Redis can be configured as a LRU cache for both volatile or
permanent items, which means it can behave like Memcache; Problem is that if
you use Redis as a permanent storage for other business matters than this
module you cannot possibly configure it to drop permanent items or you'll
loose data.

This workaround allows you to explicity set a very long or configured default
lifetime for CACHE_PERMANENT items (that would normally be permanent) which
will mark them as being volatile in Redis storage engine: this then allows you
to configure a LRU behavior for volatile keys without engaging the permenent
business stuff in a dangerous LRU mechanism; Cache items even if permament will
be dropped when unused using this.

Per default the TTL for permanent items will set to safe-enough value which is
one year; No matter how Redis will be configured default configuration or lazy
admin will inherit from a safe module behavior with zero-conf.

For advanturous people, you can manage the TTL on a per bin basis and change
the default one:

    // Make CACHE_PERMANENT items being permanent once again
    // 0 is a special value usable for all bins to explicitely tell the
    // cache items will not be volatile in Redis.
    $conf['redis_perm_ttl'] = 0;

    // Make them being volatile with a default lifetime of 1 year.
    $conf['redis_perm_ttl'] = "1 year";

    // You can override on a per-bin basis;
    // For example make cached field values live only 3 monthes:
    $conf['redis_perm_ttl_cache_field'] = "3 months";

    // But you can also put a timestamp in there; In this case the
    // value must be a STRICTLY TYPED integer:
    $conf['redis_perm_ttl_cache_field'] = 2592000; // 30 days.

Time interval string will be parsed using DateInterval::createFromDateString
please refer to its documentation:

    http://www.php.net/manual/en/dateinterval.createfromdatestring.php

Last but not least please be aware that this setting affects the
CACHE_PERMANENT ONLY; All other use cases (CACHE_TEMPORARY or user set TTL
on single cache entries) will continue to behave as documented in Drupal core
cache backend documentation.

Lock backends
-------------

Both implementations provides a Redis lock backend. Redis lock backend proved to
be faster than the default SQL based one when using both servers on the same box.

Both backends, thanks to the Redis WATCH, MULTI and EXEC commands provides a
real race condition free mutexes if you use Redis >= 2.1.0.

Testing
=======

Due to Drupal unit testing API being incredibly stupid, the unit tests can only
work with PHP >=5.3 while the module will work gracefully with PHP 5.2 (at least
using the PhpRedis client).

I did not find any hint about making tests being configurable, so per default
the tested Redis server must always be on localhost with default configuration.
