Predis cache backend
====================

This client, for now, is only able to use the Predis PHP library.

The Predis library requires PHP 5.3 minimum. If your hosted environment does
not ships with at least PHP 5.3, please do not use this cache backend.

Please consider using an OPCode cache such as APC. Predis is a good and fully
featured API, the cost is that the code is a lot more than a single file in
opposition to some other backends such as the APC one.

Get Predis
----------

You can download this library at:

  https://github.com/nrk/predis

This file explains how to install the Predis library and the Drupal cache
backend. If you are an advanced Drupal integrator, please consider the fact
that you can easily change all the pathes. Pathes used in this file are
likely to be default for non advanced users.

Download and install library
----------------------------

Once done, you either have to clone it into:

  sites/all/libraries/predis

So that you have the following directory tree:

  sites/all/libraries/lib/Predis # Where the PHP code stands

Or, any other place in order to share it:
For example, into your libraries folder, in order to get:

  some/dir/predis/lib

If you choose this solution, you have to alter a bit your $conf array into
the settings.php file as this:

  define('PREDIS_BASE_PATH', DRUPAL_ROOT . '/some/dir/predis/lib/');

Connect to a remote host and database
-------------------------------------

See README.txt file.

Advanced configuration (PHP expert)
-----------------------------------

Best solution is, whatever is the place where you put the Predis library, that
you set up a fully working autoloader able to use it. The one being used by the
Redis module is a default fallback and will naturally being appened to the SPL
autoloader stack.
