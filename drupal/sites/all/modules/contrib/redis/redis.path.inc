<?php

/**
 * @file
 * Drupal default includes/path.inc file copy which only differs in:
 *  - drupal_lookup_path() which is the only performance critical.
 *  - path_*() functions for synchronization.
 */

/**
 * Get Redis path lookup backend.
 *
 * @return Redis_Path_HashLookupInterface
 */
function redis_path_backend_get() {
  static $hashLookup;

  if (null === $hashLookup) {
    try {
      $className = Redis_Client::getClass(Redis_Client::REDIS_IMPL_PATH);
      $hashLookup = new $className();
    } catch (Exception $e) {
      $hashLookup = new Redis_Path_NullHashLookup();
    }
  }

  return $hashLookup;
}

/**
 * Initialize the $_GET['q'] variable to the proper normal path.
 */
function drupal_path_initialize() {
  // Ensure $_GET['q'] is set before calling drupal_normal_path(), to support
  // path caching with hook_url_inbound_alter().
  if (empty($_GET['q'])) {
    $_GET['q'] = variable_get('site_frontpage', 'node');
  }
  $_GET['q'] = drupal_get_normal_path($_GET['q']);
}

/**
 * Given an alias, return its Drupal system URL if one exists. Given a Drupal
 * system URL return one of its aliases if such a one exists. Otherwise,
 * return FALSE.
 *
 * @param $action
 *   One of the following values:
 *   - wipe: delete the alias cache.
 *   - alias: return an alias for a given Drupal system path (if one exists).
 *   - source: return the Drupal system URL for a path alias (if one exists).
 * @param $path
 *   The path to investigate for corresponding aliases or system URLs.
 * @param $path_language
 *   Optional language code to search the path with. Defaults to the page language.
 *   If there's no path defined for that language it will search paths without
 *   language.
 *
 * @return
 *   Either a Drupal system path, an aliased path, or FALSE if no path was
 *   found.
 */
function drupal_lookup_path($action, $path = '', $path_language = NULL) {
  global $language_url;

  static $cache, $denyAdmin;

  if (null === $cache) {
    $cache = array('whitelist' => variable_get('path_alias_whitelist'));
    if (null === $cache['whitelist']) {
      $cache['whitelist'] = drupal_path_alias_whitelist_rebuild();
    }
    $denyAdmin = (bool)variable_get('path_alias_admin_blacklist', true);
  }

  // If no language is explicitly specified we default to the current URL
  // language. If we used a language different from the one conveyed by the
  // requested URL, we might end up being unable to check if there is a path
  // alias matching the URL path.
  if (!$path_language = $path_language ? $path_language : $language_url->language) {
    $path_language = LANGUAGE_NONE;
  }

  if (!empty($path) && isset($cache[$path_language][$action][$path])) {
    return $cache[$path_language][$action][$path];
  }

  $ret = null;
  $hashLookup = redis_path_backend_get();

  switch ($action) {

    case 'wipe':
      $cache = array();
      $cache['whitelist'] = drupal_path_alias_whitelist_rebuild();
      break;

    case 'alias':
      if (empty($path)) {
        return false;
      }
      // Check the path whitelist, if the top_level part before the first /
      // is not in the list, then there is no need to do anything further,
      // it is not in the database.
      if (!isset($cache['whitelist'][strtok($path, '/')])) {
        return false;
      }
      // Deny admin paths.
      if ($denyAdmin && path_is_admin($path)) {
        return false;
      }

      $ret = $hashLookup->lookupAlias($path, $path_language);
      if (null === $ret) {
        // Original Drupal algorithm.
        // This will also update the $path_language variable so Redis will store
        // the right language (keeps track of LANGUAGE_NONE or specific language
        // so that default fallback behavior is the same that core).
        if ($path_language == LANGUAGE_NONE) {
          list ($ret, $path_language) = db_query("SELECT alias, language FROM {url_alias} WHERE source = :source AND language = :language ORDER BY pid DESC LIMIT 1", array(
            ':source' => $path,
            ':language' => $path_language,
          ))->fetch(PDO::FETCH_NUM);
        } else if ($path_language > LANGUAGE_NONE) {
          list ($ret, $path_language) = db_query("SELECT alias, language FROM {url_alias} WHERE source = :source AND language IN (:language) ORDER BY language DESC, pid DESC LIMIT 1", array(
            ':source' => $path,
            ':language' => array($path_language, LANGUAGE_NONE),
          ))->fetch(PDO::FETCH_NUM);
        } else {
          list ($ret, $path_language) = db_query("SELECT alias, language FROM {url_alias} WHERE source = :source AND language IN (:language) ORDER BY language ASC, pid DESC LIMIT 1", array(
            ':source' => $path,
            ':language' => array($path_language, LANGUAGE_NONE),
          ))->fetch(PDO::FETCH_NUM);
        }
        // Getting here with a value means we need to cache it
        if (empty($ret)) {
          $ret = false;
        }
        $hashLookup->saveAlias($path, $ret, $path_language);
      }
      $cache[$path_language]['alias'][$path] = $ret;
      $cache[$path_language]['source'][$ret] = $path;
      break;

    case 'source':
      if (empty($path)) {
        return false;
      }
      // Even thought given entry is an alias, if it conflicts with an
      // existing admin path just deny any lookup.
      if ($denyAdmin && path_is_admin($path)) {
        return false;
      }

      $ret = $hashLookup->lookupSource($path, $path_language);
      if (null === $ret) {
        // Original Drupal algorithm.
        // This will also update the $path_language variable so Redis will store
        // the right language (keeps track of LANGUAGE_NONE or specific language
        // so that default fallback behavior is the same that core).
        if ($path_language == LANGUAGE_NONE) {
          list ($ret, $path_language) = db_query("SELECT source, language FROM {url_alias} WHERE alias = :alias AND language = :language ORDER BY pid DESC LIMIT 1", array(
            ':alias' => $path,
            ':language' => LANGUAGE_NONE,
          ))->fetch(PDO::FETCH_NUM);
        } else if ($path_language > LANGUAGE_NONE) {
          list ($ret, $path_language) = db_query("SELECT source, language FROM {url_alias} WHERE alias = :alias AND language IN (:language) ORDER BY language DESC, pid DESC LIMIT 1", array(
            ':alias' => $path,
            ':language' => array($path_language, LANGUAGE_NONE),
          ))->fetch(PDO::FETCH_NUM);
        } else {
          list ($ret, $path_language) = db_query("SELECT source, language FROM {url_alias} WHERE alias = :alias AND language IN (:language) ORDER BY language ASC, pid DESC LIMIT 1", array(
            ':alias' => $path,
            ':language' => array($path_language, LANGUAGE_NONE),
          ))->fetch(PDO::FETCH_NUM);
        }
        // Getting here with a value means we need to cache it
        if (empty($ret)) {
          $ret = false;
        }
        $hashLookup->saveAlias($ret, $path, $path_language);
      }
      $cache[$path_language]['alias'][$ret] = $path;
      $cache[$path_language]['source'][$path] = $ret;
      break;
  }

  return $ret;
}

/**
 * Cache system paths for a page.
 *
 * Cache an array of the system paths available on each page. We assume
 * that aliases will be needed for the majority of these paths during
 * subsequent requests, and load them in a single query during
 * drupal_lookup_path().
 */
function drupal_cache_system_paths() {
  // Check if the system paths for this page were loaded from cache in this
  // request to avoid writing to cache on every request.
  $cache = &drupal_static('drupal_lookup_path', array());
  if (empty($cache['system_paths']) && !empty($cache['map'])) {
    // Generate a cache ID (cid) specifically for this page.
    $cid = current_path();
    // The static $map array used by drupal_lookup_path() includes all
    // system paths for the page request.
    if ($paths = current($cache['map'])) {
      $data = array_keys($paths);
      $expire = REQUEST_TIME + (60 * 60 * 24);
      cache_set($cid, $data, 'cache_path', $expire);
    }
  }
}

/**
 * Given an internal Drupal path, return the alias set by the administrator.
 *
 * If no path is provided, the function will return the alias of the current
 * page.
 *
 * @param $path
 *   An internal Drupal path.
 * @param $path_language
 *   An optional language code to look up the path in.
 *
 * @return
 *   An aliased path if one was found, or the original path if no alias was
 *   found.
 */
function drupal_get_path_alias($path = NULL, $path_language = NULL) {
  // If no path is specified, use the current page's path.
  if ($path == NULL) {
    $path = $_GET['q'];
  }
  $result = $path;
  if ($alias = drupal_lookup_path('alias', $path, $path_language)) {
    $result = $alias;
  }
  return $result;
}

/**
 * Given a path alias, return the internal path it represents.
 *
 * @param $path
 *   A Drupal path alias.
 * @param $path_language
 *   An optional language code to look up the path in.
 *
 * @return
 *   The internal path represented by the alias, or the original alias if no
 *   internal path was found.
 */
function drupal_get_normal_path($path, $path_language = NULL) {
  $original_path = $path;

  // Lookup the path alias first.
  if ($source = drupal_lookup_path('source', $path, $path_language)) {
    $path = $source;
  }

  // Allow other modules to alter the inbound URL. We cannot use drupal_alter()
  // here because we need to run hook_url_inbound_alter() in the reverse order
  // of hook_url_outbound_alter().
  foreach (array_reverse(module_implements('url_inbound_alter')) as $module) {
    $function = $module . '_url_inbound_alter';
    $function($path, $original_path, $path_language);
  }

  return $path;
}

/**
 * Check if the current page is the front page.
 *
 * @return
 *   Boolean value: TRUE if the current page is the front page; FALSE if otherwise.
 */
function drupal_is_front_page() {
  // Use the advanced drupal_static() pattern, since this is called very often.
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['is_front_page'] = &drupal_static(__FUNCTION__);
  }
  $is_front_page = &$drupal_static_fast['is_front_page'];

  if (!isset($is_front_page)) {
    // As drupal_path_initialize updates $_GET['q'] with the 'site_frontpage' path,
    // we can check it against the 'site_frontpage' variable.
    $is_front_page = ($_GET['q'] == variable_get('site_frontpage', 'node'));
  }

  return $is_front_page;
}

/**
 * Check if a path matches any pattern in a set of patterns.
 *
 * @param $path
 *   The path to match.
 * @param $patterns
 *   String containing a set of patterns separated by \n, \r or \r\n.
 *
 * @return
 *   Boolean value: TRUE if the path matches a pattern, FALSE otherwise.
 */
function drupal_match_path($path, $patterns) {
  $regexps = &drupal_static(__FUNCTION__);

  if (!isset($regexps[$patterns])) {
    // Convert path settings to a regular expression.
    // Therefore replace newlines with a logical or, /* with asterisks and the <front> with the frontpage.
    $to_replace = array(
      '/(\r\n?|\n)/', // newlines
      '/\\\\\*/',     // asterisks
      '/(^|\|)\\\\<front\\\\>($|\|)/' // <front>
    );
    $replacements = array(
      '|',
      '.*',
      '\1' . preg_quote(variable_get('site_frontpage', 'node'), '/') . '\2'
    );
    $patterns_quoted = preg_quote($patterns, '/');
    $regexps[$patterns] = '/^(' . preg_replace($to_replace, $replacements, $patterns_quoted) . ')$/';
  }
  return (bool)preg_match($regexps[$patterns], $path);
}

/**
 * Return the current URL path of the page being viewed.
 *
 * Examples:
 * - http://example.com/node/306 returns "node/306".
 * - http://example.com/drupalfolder/node/306 returns "node/306" while
 *   base_path() returns "/drupalfolder/".
 * - http://example.com/path/alias (which is a path alias for node/306) returns
 *   "node/306" as opposed to the path alias.
 *
 * This function is not available in hook_boot() so use $_GET['q'] instead.
 * However, be careful when doing that because in the case of Example #3
 * $_GET['q'] will contain "path/alias". If "node/306" is needed, calling
 * drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL) makes this function available.
 *
 * @return
 *   The current Drupal URL path.
 *
 * @see request_path()
 */
function current_path() {
  return $_GET['q'];
}

/**
 * Rebuild the path alias white list.
 *
 * @param $source
 *   An optional system path for which an alias is being inserted.
 *
 * @return
 *   An array containing a white list of path aliases.
 */
function drupal_path_alias_whitelist_rebuild($source = NULL) {
  // When paths are inserted, only rebuild the whitelist if the system path
  // has a top level component which is not already in the whitelist.
  if (!empty($source)) {
    $whitelist = variable_get('path_alias_whitelist', NULL);
    if (isset($whitelist[strtok($source, '/')])) {
      return $whitelist;
    }
  }
  // For each alias in the database, get the top level component of the system
  // path it corresponds to. This is the portion of the path before the first
  // '/', if present, otherwise the whole path itself.
  $whitelist = array();
  $result = db_query("SELECT DISTINCT SUBSTRING_INDEX(source, '/', 1) AS path FROM {url_alias}");
  foreach ($result as $row) {
    $whitelist[$row->path] = TRUE;
  }
  variable_set('path_alias_whitelist', $whitelist);
  return $whitelist;
}

/**
 * Fetches a specific URL alias from the database.
 *
 * @param $conditions
 *   A string representing the source, a number representing the pid, or an
 *   array of query conditions.
 *
 * @return
 *   FALSE if no alias was found or an associative array containing the
 *   following keys:
 *   - source: The internal system path.
 *   - alias: The URL alias.
 *   - pid: Unique path alias identifier.
 *   - language: The language of the alias.
 */
function path_load($conditions) {
  if (is_numeric($conditions)) {
    $conditions = array('pid' => $conditions);
  }
  elseif (is_string($conditions)) {
    $conditions = array('source' => $conditions);
  }
  elseif (!is_array($conditions)) {
    return FALSE;
  }
  $select = db_select('url_alias');
  foreach ($conditions as $field => $value) {
    $select->condition($field, $value);
  }
  return $select
    ->fields('url_alias')
    ->execute()
    ->fetchAssoc();
}

/**
 * Save a path alias to the database.
 *
 * @param $path
 *   An associative array containing the following keys:
 *   - source: The internal system path.
 *   - alias: The URL alias.
 *   - pid: (optional) Unique path alias identifier.
 *   - language: (optional) The language of the alias.
 */
function path_save(&$path) {
  $path += array('language' => LANGUAGE_NONE);

  // Load the stored alias, if any.
  if (!empty($path['pid']) && !isset($path['original'])) {
    $path['original'] = path_load($path['pid']);
  }

  if (empty($path['pid'])) {
    drupal_write_record('url_alias', $path);
    module_invoke_all('path_insert', $path);
  }
  else {
    drupal_write_record('url_alias', $path, array('pid'));
    module_invoke_all('path_update', $path);
  }
  if (!empty($path['original'])) {
    redis_path_backend_get()->deleteAlias($path['original']['source'], $path['original']['alias'], $path['original']['language']);
  }
  redis_path_backend_get()->saveAlias($path['source'], $path['alias'], $path['language']);

  // Clear internal properties.
  unset($path['original']);

  // Clear the static alias cache.
  drupal_clear_path_cache($path['source']);
}

/**
 * Delete a URL alias.
 *
 * @param $criteria
 *   A number representing the pid or an array of criteria.
 */
function path_delete($criteria) {
  if (!is_array($criteria)) {
    $criteria = array('pid' => $criteria);
  }
  $path = path_load($criteria);
  $query = db_delete('url_alias');
  foreach ($criteria as $field => $value) {
    $query->condition($field, $value);
  }
  $query->execute();
  module_invoke_all('path_delete', $path);
  redis_path_backend_get()->deleteAlias($path['source'], $path['alias'], $path['language']);
  drupal_clear_path_cache($path['source']);
}

/**
 * Determines whether a path is in the administrative section of the site.
 *
 * By default, paths are considered to be non-administrative. If a path does
 * not match any of the patterns in path_get_admin_paths(), or if it matches
 * both administrative and non-administrative patterns, it is considered
 * non-administrative.
 *
 * @param $path
 *   A Drupal path.
 *
 * @return
 *   TRUE if the path is administrative, FALSE otherwise.
 *
 * @see path_get_admin_paths()
 * @see hook_admin_paths()
 * @see hook_admin_paths_alter()
 */
function path_is_admin($path) {
  $path_map = &drupal_static(__FUNCTION__);
  if (!isset($path_map['admin'][$path])) {
    $patterns = path_get_admin_paths();
    $path_map['admin'][$path] = drupal_match_path($path, $patterns['admin']);
    $path_map['non_admin'][$path] = drupal_match_path($path, $patterns['non_admin']);
  }
  return $path_map['admin'][$path] && !$path_map['non_admin'][$path];
}

/**
 * Gets a list of administrative and non-administrative paths.
 *
 * @return array
 *   An associative array containing the following keys:
 *   'admin': An array of administrative paths and regular expressions
 *            in a format suitable for drupal_match_path().
 *   'non_admin': An array of non-administrative paths and regular expressions.
 *
 * @see hook_admin_paths()
 * @see hook_admin_paths_alter()
 */
function path_get_admin_paths() {
  $patterns = &drupal_static(__FUNCTION__);
  if (!isset($patterns)) {
    $paths = module_invoke_all('admin_paths');
    drupal_alter('admin_paths', $paths);
    // Combine all admin paths into one array, and likewise for non-admin paths,
    // for easier handling.
    $patterns = array();
    $patterns['admin'] = array();
    $patterns['non_admin'] = array();
    foreach ($paths as $path => $enabled) {
      if ($enabled) {
        $patterns['admin'][] = $path;
      }
      else {
        $patterns['non_admin'][] = $path;
      }
    }
    $patterns['admin'] = implode("\n", $patterns['admin']);
    $patterns['non_admin'] = implode("\n", $patterns['non_admin']);
  }
  return $patterns;
}

/**
 * Checks a path exists and the current user has access to it.
 *
 * @param $path
 *   The path to check.
 * @param $dynamic_allowed
 *   Whether paths with menu wildcards (like user/%) should be allowed.
 *
 * @return
 *   TRUE if it is a valid path AND the current user has access permission,
 *   FALSE otherwise.
 */
function drupal_valid_path($path, $dynamic_allowed = FALSE) {
  global $menu_admin;
  // We indicate that a menu administrator is running the menu access check.
  $menu_admin = TRUE;
  if ($path == '<front>' || url_is_external($path)) {
    $item = array('access' => TRUE);
  }
  elseif ($dynamic_allowed && preg_match('/\/\%/', $path)) {
    // Path is dynamic (ie 'user/%'), so check directly against menu_router table.
    if ($item = db_query("SELECT * FROM {menu_router} where path = :path", array(':path' => $path))->fetchAssoc()) {
      $item['link_path']  = $form_item['link_path'];
      $item['link_title'] = $form_item['link_title'];
      $item['external']   = FALSE;
      $item['options'] = '';
      _menu_link_translate($item);
    }
  }
  else {
    $item = menu_get_item($path);
  }
  $menu_admin = FALSE;
  return $item && $item['access'];
}

/**
 * Clear the path cache.
 *
 * @param $source
 *   An optional system path for which an alias is being changed.
 */
function drupal_clear_path_cache($source = NULL) {
  // Clear the drupal_lookup_path() static cache.
  drupal_static_reset('drupal_lookup_path');
  drupal_path_alias_whitelist_rebuild($source);
}
