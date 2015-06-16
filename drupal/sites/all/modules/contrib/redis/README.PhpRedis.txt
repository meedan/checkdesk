PhpRedis cache backend
======================

This client, for now, is only able to use the PhpRedis extension.

Get PhpRedis
------------

You can download this library at:

  https://github.com/nicolasff/phpredis

This is PHP extension, too recent for being packaged in most distribution, you
will probably need to compile it yourself.

Default behavior is to connect via tcp://localhost:6379 but you might want to
connect differently.

Connect via UNIX socket
-----------------------

Just add this line to your settings.php file:

  $conf['redis_cache_socket'] = '/tmp/redis.sock';

Don't forget to change the path depending on your operating system and Redis
server configuration.

Connect to a remote host and database
-------------------------------------

See README.txt file.

For this particular implementation, host settings are overridden by the
UNIX socket parameter.
