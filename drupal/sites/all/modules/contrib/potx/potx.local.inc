<?php

use Symfony\Component\Yaml\Yaml;
use Symfony\Component\Yaml\Exception\ParseException;

/**
 * Initialize potx to run locally, e.g. by drush.
 *
 * @param string $module_path
 *   Path to the module that is being parsed by potx.
 */
function potx_local_init($module_path = NULL) {
  global $_potx_found_modules;
  global $_potx_schema_lookup;
  global $_potx_reverse_lookup_built;

  $_potx_found_modules = array();
  $_potx_schema_lookup = array();
  $_potx_reverse_lookup_built = FALSE;

  global $potx_callbacks;

  $potx_callbacks = array(
      'schema_store_lookup' => '_potx_schema_store_lookup',
      'schema_reverse_lookup' => '_potx_schema_reverse_lookup',
      'load_module_metadata' => '_potx_load_module_metadata',
      'store_module_metadata' => '_potx_store_module_metadata',
      'schema_store' => '_potx_schema_store',
      'schema_load' => '_potx_schema_load',
  );

  if ($module_path !== NULL) {
    _potx_find_all_modules($module_path);
  }
}

/**
 * Find all available modules based on Drupal 8's directory structure.
 *
 * @param string $module_path
 *   Path to the module that is being parsed by potx.
 */
function _potx_find_all_modules($module_path) {
  global $_potx_found_modules;

  $module_path = realpath($module_path);
  if (substr($module_path, -1) != '/') {
    $module_path = $module_path . '/';
  }

  // The list of directories to check in the path, to find out if we are in a Drupal install directory.
  $checks = array('/sites/', '/core/', '/profiles/', '/modules/', '/themes/');

  // The list of paths that could contain "modules/" or "themes/" subdirectories.
  $search_paths = array();

  foreach ($checks as $check) {
    if (preg_match("!$check!", $module_path)) {
      $parts = explode($check, $module_path, 2);

      // The installed Drupal root.
      $root = $parts[0];

      // The Drupal core directory contains a config/schema subdirectory, which
      //  is not part of any module or theme.
      $_potx_found_modules['core']['path'] = $root . '/core';

      $search_paths[] = $root;
      $search_paths[] = $root . '/core';

      $profiles = glob($root . '/profiles/*', GLOB_ONLYDIR);
      $sites = glob($root . '/sites/*', GLOB_ONLYDIR);

      if (is_array($profiles)) {
        $search_paths = array_merge($search_paths, $profiles);
      }
      if (is_array($sites)) {
        $search_paths = array_merge($search_paths, $sites);
      }

      break;
    }
  }

  foreach ($search_paths as $search_path) {
    foreach (array('/modules', '/themes') as $sub) {
      if (is_dir($search_path . $sub)) {
        _potx_find_modules($search_path . $sub);
      }
    }
  }
}

/**
 * Recursively find all modules in a given path, by looking for .info.yml files.
 *
 * @param string $path
 *   The search path
 */
function _potx_find_modules($path) {
  global $_potx_found_modules;

  $subdirs = glob($path . '/*', GLOB_ONLYDIR);

  if (is_array($subdirs)) {
    foreach ($subdirs as $dir) {
      if (!preg_match("!(^|.+/)(CVS|\.svn|\.git|tests|vendor)$!", $dir)) {
        $module_name = basename($dir);
        $info_path = $dir . '/' . $module_name . '.info.yml';

        if (file_exists($info_path)) {
          $_potx_found_modules[$module_name]['path'] = $dir;
        }

        _potx_find_modules($dir);
      }
    }
  }
}

/**
 * Store a config schema file's matching keys (e.g. field.field.*.*.*), and
 *  the module that contains the schema, in a lookup table.
 *
 * @param array $keys
 *   List of config matching keys in a config schema file.
 *
 * @param string $module_name
 *   Name of the module containing the schema.
 */
function _potx_schema_store_lookup($keys, $module_name) {
  global $_potx_schema_lookup;
  $_potx_schema_lookup = array_merge($_potx_schema_lookup, array_fill_keys($keys, $module_name));
}

/**
 * Find the module containing the schema for a specific config file, based on
 *  its matching candidates, using a reverse lookup table.
 *
 * @param array $matching_candidates
 *   The list of matching candidates for a config file, ordered from specific to
 *    generic.
 *
 * @return string|null
 *   The module containing the matching schema, if exists, otherwise NULL.
 *
 * @see _potx_find_matching_schema()
 */
function _potx_schema_reverse_lookup($matching_candidates) {
  global $_potx_schema_lookup;
  global $_potx_reverse_lookup_built;

  if (!$_potx_reverse_lookup_built) {
    _potx_build_reverse_lookup();
  }

  foreach ($matching_candidates as $candidate) {
    if (isset($_potx_schema_lookup[$candidate])) {
      return $_potx_schema_lookup[$candidate];
    }
  }

  return NULL;
}

/**
 * Build the reverse lookup table from config schemas' matching keys, and their
 *  containing modules, for all modules found locally.
 *
 * This is only used on a local potx. Building the reverse lookup table is
 * expensive, so it is delayed as much as possible, i.e. until an optional
 * config is parsed, and the reverse lookup is called.
 *
 * @see _potx_find_all_modules()
 * @see _potx_schema_reverse_lookup()
 */
function _potx_build_reverse_lookup() {
  global $_potx_reverse_lookup_built;
  global $_potx_found_modules;
  global $potx_callbacks;

  foreach ($_potx_found_modules as $module_name => $module_data) {
    $module_files = _potx_explore_dir($module_data['path'] . '/', '*', POTX_API_8);

    foreach ($module_files as $file_name) {

      if (preg_match('~config/schema/[^/]+\.yml$~', $file_name)) {

        $code = file_get_contents($file_name);

        try {
          $yaml = Yaml::parse($code);
          $keys = array_keys($yaml);

          $potx_callbacks['schema_store_lookup']($keys, $module_name);
        } catch (ParseException $e) {
          watchdog('potx', "YAML parseing error on file @path: @error", array(
              '@path' => $file_path,
              '@error' => $e->getMessage(),
          ));
        }
      }
    }
  }

  $_potx_reverse_lookup_built = TRUE;
}

/**
 * Load a module's metadata, including its dependencies and list of config
 *  schema files.
 *
 * @param string $module_name
 *   The module's name.
 *
 * @return bool
 *   TRUE if the module was found, FALSE otherwise.
 */
function _potx_load_module_metadata($module_name) {
  global $_potx_found_modules;
  global $_potx_module_metadata;

  if (!isset($_potx_found_modules[$module_name])) {
    return FALSE;
  }

  $module_path = $_potx_found_modules[$module_name]['path'];

  if ($module_name === 'core') {
    $_potx_module_metadata['core']['dependencies'] = array();
  }
  else {
    $info_path = $module_path . '/' . $module_name . '.info.yml';

    $code = file_get_contents($info_path);

    try {
      $info_yaml = Yaml::parse($code);
      $_potx_module_metadata[$module_name]['dependencies'] = isset($info_yaml['dependencies']) ? $info_yaml['dependencies'] : array();
    } catch (ParseException $e) {
      watchdog('potx', "YAML parseing error on file @path: @error", array(
          '@path' => $file_path,
          '@error' => $e->getMessage(),
      ));

      return FALSE;
    }
  }

  $module_files = _potx_explore_dir($module_path . '/config/schema/', '*', POTX_API_8);

  foreach ($module_files as $file_path) {
    if (preg_match('~config/schema/[^/]+\.yml$~', $file_path)) {
      $_potx_module_metadata[$module_name]['config']['schema'][] = array(NULL, $file_path);
    }
  }

  return TRUE;
}

/**
 * Store the metadata for a module, including its dependencies.
 *
 * Not used locally by potx.
 *
 * @param string $module_name
 *   The module's name
 * @param array $metadata
 *   The module's metadata
 */
function _potx_store_module_metadata($module_name, $metadata) {
  // Intentionally Left Empty.
}

/**
 * Store a module's processed schema, in a cache (for local potx), or database
 *  (for l10n_server).
 *
 * The processed schema is found in the "$_potx_module_schema" global.
 *
 * @param string $module_name
 *   The module name.
 */
function _potx_schema_store($module_name) {
  global $_potx_module_schema;
  global $_potx_schema_cache;

  $_potx_schema_cache[$module_name] = $_potx_module_schema;
}

/**
 * Load a module's processed schema, from cache (for local potx), or database
 *  (for l10n_server).
 *
 * @param string $module_name
 *   The module's name.
 */
function _potx_schema_load($module_name) {
  global $_potx_schema_cache;
  if (isset($_potx_schema_cache[$module_name])) {
    return $_potx_schema_cache[$module_name];
  }

  return NULL;
}
