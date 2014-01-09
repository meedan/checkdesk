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

Install
=======

Choose the Redis client library to use
--------------------------------------

Add into your settings.php file:

  $conf['redis_client_interface']      = 'PhpRedis';

You can replace 'PhpRedis' with 'Predis', depending on the library you chose. 

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
