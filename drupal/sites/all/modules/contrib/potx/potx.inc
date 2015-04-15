<?php

/**
 * @file
 *   Extraction API used by the web and command line interface.
 *
 *   This include file implements the default string and file version
 *   storage as well as formatting of POT files for web download or
 *   file system level creation. The strings, versions and file contents
 *   are handled with global variables to reduce the possible memory overhead
 *   and API clutter of passing them around. Custom string and version saving
 *   functions can be implemented to use the functionality provided here as an
 *   API for Drupal code to translatable string conversion.
 *
 *   The potx-cli.php script can be used with this include file as
 *   a command line interface to string extraction. The potx.module
 *   can be used as a web interface for manual extraction.
 *
 *   For a module using potx as an extraction API, but providing more
 *   sophisticated functionality on top of it, look into the
 *   'Localization server' module: http://drupal.org/project/l10n_server
 */

/**
 * Use Twig and the Symfony YAML parser, found in the vendor directory.
 */
set_include_path(get_include_path() . PATH_SEPARATOR . __DIR__ . '/vendor');
spl_autoload_register(function($c){
  @include preg_replace('#\\\|_(?!.*\\\)#','/',$c).'.php';
});

use Symfony\Component\Yaml\Yaml;

/**
 * The current Drupal major API verion.
 *
 * This should be the only difference between different branches of potx.inc
 */
define('POTX_API_CURRENT', 7);

/**
 * Silence status reports.
 */
define('POTX_STATUS_SILENT', 0);

/**
 * Drupal message based status reports.
 */
define('POTX_STATUS_MESSAGE', 1);

/**
 * Command line status reporting.
 *
 * Status goes to standard output, errors to standard error.
 */
define('POTX_STATUS_CLI', 2);

/**
 * Structured array status logging.
 *
 * Useful for coder review status reporting.
 */
define('POTX_STATUS_STRUCTURED', 3);

/**
 * Core parsing mode:
 *  - .info files folded into general.pot
 *  - separate files generated for modules
 */
define('POTX_BUILD_CORE', 0);

/**
 * Multiple files mode:
 *  - .info files folded into their module pot files
 *  - separate files generated for modules
 */
define('POTX_BUILD_MULTIPLE', 1);

/**
 * Single file mode:
 *  - all files folded into one pot file
 */
define('POTX_BUILD_SINGLE', 2);

/**
 * Save string to both installer and runtime collection.
 */
define('POTX_STRING_BOTH', 0);

/**
 * Save string to installer collection only.
 */
define('POTX_STRING_INSTALLER', 1);

/**
 * Save string to runtime collection only.
 */
define('POTX_STRING_RUNTIME', 2);

/**
 * Parse source files in Drupal 5.x format.
 */
define('POTX_API_5', 5);

/**
 * Parse source files in Drupal 6.x format.
 *
 * Changes since 5.x documented at http://drupal.org/node/114774
 */
define('POTX_API_6', 6);

/**
 * Parse source files in Drupal 7.x format.
 *
 * Changes since 6.x documented at http://drupal.org/node/224333
 */
define('POTX_API_7', 7);

/**
 * Parse source files in Drupal 8.x format.
 *
 * Changes since 7.x documented at
 * http://drupal.org/list-changes/drupal?to_branch=8.x
 */
define('POTX_API_8', 8);

/**
 * When no context is used. Makes it easy to look these up.
 */
define('POTX_CONTEXT_NONE', NULL);

/**
 * When there was a context identification error.
 */
define('POTX_CONTEXT_ERROR', FALSE);

/**
 * Regular expression pattern used to localize JavaScript strings.
 */
define('POTX_JS_STRING', '(?:(?:\'(?:\\\\\'|[^\'])*\'|"(?:\\\\"|[^"])*")(?:\s*\+\s*)?)+');

/**
 * Regular expression pattern used to match simple JS object literal.
 *
 * This pattern matches a basic JS object, but will fail on an object with
 * nested objects. Used in JS file parsing for string arg processing.
 */
define('POTX_JS_OBJECT', '\{.*?\}');


/**
 * Regular expression to match an object containing a key 'context'.
 *
 * Pattern to match a JS object containing a 'context key' with a string value,
 * which is captured. Will fail if there are nested objects.
 */
define('POTX_JS_OBJECT_CONTEXT', '
  \{              # match object literal start
  .*?             # match anything, non-greedy
  (?:             # match a form of "context"
    \'context\'
    |
    "context"
    |
    context
  )
  \s*:\s*         # match key-value separator ":"
  (' . POTX_JS_STRING . ')  # match context string
  .*?             # match anything, non-greedy
  \}              # match end of object literal
');

/**
 * Process a file and put extracted information to the given parameters.
 *
 * @param $file_path
 *   Comlete path to file to process.
 * @param $strip_prefix
 *   An integer denoting the number of chars to strip from filepath for output.
 * @param $save_callback
 *   Callback function to use to save the collected strings.
 * @param $version_callback
 *   Callback function to use to save collected version numbers.
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_process_file($file_path, $strip_prefix = 0, $save_callback = '_potx_save_string', $version_callback = '_potx_save_version', $api_version = POTX_API_CURRENT) {
  global $_potx_tokens, $_potx_lookup;

  // Figure out the basename and extension to select extraction method.
  $basename = basename($file_path);
  $name_parts = pathinfo($basename);

  // Always grab the CVS version number from the code
  $code = file_get_contents($file_path);
  $file_name = $strip_prefix > 0 ? substr($file_path, $strip_prefix) : $file_path;
  _potx_find_version_number($code, $file_name, $version_callback);

  // The .info files are not PHP code, no need to tokenize.
  if ($name_parts['extension'] == 'info' && $api_version < POTX_API_8) {
    _potx_find_info_file_strings($file_path, $file_name, $save_callback, $api_version);
    return;
  }
  elseif ($name_parts['extension'] == 'yml' && $api_version > POTX_API_7) {
    _potx_parse_yaml_file($code, $file_name, $file_path, $save_callback);
  }
  elseif ($name_parts['extension'] == 'js' && $api_version > POTX_API_5) {
    // @todo: D7 context support.
    _potx_parse_js_file($code, $file_name, $save_callback);
  }
  elseif ($name_parts['extension'] == 'twig' && $api_version > POTX_API_7) {
    _potx_parse_twig_file($code, $file_name, $save_callback);
  }

  $constraint_extract = FALSE;
  if (substr($name_parts['filename'], -10) == 'Constraint' && $api_version > POTX_API_7) {
    $constraint_extract = TRUE;
  }

  // Extract raw PHP language tokens.
  $raw_tokens = token_get_all($code);
  unset($code);

  // Remove whitespace and possible HTML (the later in templates for example),
  // count line numbers so we can include them in the output.
  $_potx_tokens = array();
  $_potx_lookup = array();
  $token_number = 0;
  $line_number = 1;
  foreach ($raw_tokens as $token) {
    if ((!is_array($token)) || (($token[0] != T_WHITESPACE) && ($token[0] != T_INLINE_HTML))) {
      if (is_array($token)) {
        $token[] = $line_number;

         $constraint_match = $constraint_extract && $token[0] == T_VARIABLE && strlen($token[1]) >= 7 && substr_compare($token[1], 'message', -7, 7, true) === 0;

         // Fill array for finding token offsets quickly.
         if (in_array($token[0], array(T_STRING, T_DOC_COMMENT)) || ($token[0] == T_VARIABLE && $token[1] == '$t') || $constraint_match
             || ($token[0] == T_CONSTANT_ENCAPSED_STRING && ($token[1] == "'#template'" || $token[1] == '"#template"'))) {

           // Give doc comments a specific key because their content varies.
           $key = ($token[0] == T_DOC_COMMENT) ? 'T_DOC_COMMENT' : ($constraint_match ? 'T_POTX_CONSTRAINT' : $token[1]);
           // Normalise "#template" token to support both single-quoted and double-quoted #template keys.
           if ($key == '"#template"') {
             $key = "'#template'";
           }

           if (!isset($_potx_lookup[$key])) {
             $_potx_lookup[$key] = array();
           }
           $_potx_lookup[$key][] = $token_number;
         }
      }
      $_potx_tokens[] = $token;
      $token_number++;
    }
    // Collect line numbers.
    if (is_array($token)) {
      $line_number += count(explode("\n", $token[1])) - 1;
    }
    else {
      $line_number += count(explode("\n", $token)) - 1;
    }
  }
  unset($raw_tokens);

  // Regular t() calls with different usages.
  if ($api_version > POTX_API_6) {
    // Drupal 7 onwards supports context on t().
    _potx_find_t_calls_with_context($file_name, $save_callback);
    if ($api_version < POTX_API_8) {
      // st() and $t() are supported up to Drupal 7.
      _potx_find_t_calls_with_context($file_name, $save_callback, '$t', POTX_STRING_BOTH);
      _potx_find_t_calls_with_context($file_name, $save_callback, 'st', POTX_STRING_INSTALLER);
    }
    else {
      // TranslationWrapper added in Drupal 8.
      _potx_find_t_calls_with_context($file_name, $save_callback, 'TranslationWrapper');
    }
  }
  else {
    // Context-less API up to Drupal 6.
    _potx_find_t_calls($file_name, $save_callback);
    _potx_find_t_calls($file_name, $save_callback, '$t', POTX_STRING_BOTH);
    _potx_find_t_calls($file_name, $save_callback, 'st', POTX_STRING_INSTALLER);
  }
  if ($api_version < POTX_API_8) {
    // This does not support context even in Drupal 7.
    _potx_find_t_calls($file_name, $save_callback, '_locale_import_message', POTX_STRING_BOTH);
  }

  if ($api_version > POTX_API_5) {
    // Watchdog calls have both of their arguments translated from Drupal 6.x.
    if ($api_version < POTX_API_8) {
      _potx_find_watchdog_calls($file_name, $save_callback);
    }

    if ($api_version > POTX_API_7) {
      // Logging calls may use a colorful set of methods now.
      _potx_find_t_calls($file_name, $save_callback, 'debug');
      _potx_find_t_calls($file_name, $save_callback, 'info');
      _potx_find_t_calls($file_name, $save_callback, 'notice');
      _potx_find_t_calls($file_name, $save_callback, 'warning');
      _potx_find_t_calls($file_name, $save_callback, 'error');
      _potx_find_t_calls($file_name, $save_callback, 'critical');
      _potx_find_t_calls($file_name, $save_callback, 'alert');
      _potx_find_t_calls($file_name, $save_callback, 'emergency');
      _potx_find_log_calls($file_name, $save_callback);
    }
  }
  else {
    // Watchdog calls only have their first argument translated in Drupal 5.x
    // and before.
    _potx_find_t_calls($file_name, $save_callback, 'watchdog');
  }

  // Plurals need unique parsing.
  _potx_find_format_plural_calls($file_name, $save_callback, 'format_plural', $api_version);

  // Support for formatPlural() calls in Drupal 8+.
  if ($api_version > POTX_API_7) {
    _potx_find_format_plural_calls($file_name, $save_callback, 'formatPlural', $api_version);
  }

  if ($name_parts['extension'] == 'module') {
    if ($api_version < POTX_API_7) {
      _potx_find_perm_hook($file_name, $name_parts['filename'], $save_callback);
    }
    if ($api_version > POTX_API_5) {
      // @todo: if tabs are not defined on the menu hook anymore, exclude this for 8.
      _potx_find_menu_hooks($file_name, $name_parts['filename'], $save_callback);
    }
  }

  // Support @Translation annotation (in doc comments) on Drupal 8+.
  if ($api_version > POTX_API_7) {
    _potx_find_translation_annotations($file_name, $save_callback);
  }

  if ($constraint_extract) {
    _potx_find_constraint_messages($file_name, $save_callback);
  }

  if ($api_version > POTX_API_7) {
    _potx_process_inline_templates($file_name, $save_callback);
  }

  // Special handling of some Drupal core files.
  if ($api_version < POTX_API_8 && (($basename == 'locale.inc' && $api_version < POTX_API_7) || $basename == 'iso.inc')) {
    _potx_find_language_names($file_name, $save_callback, $api_version);
  }
  elseif ($api_version > POTX_API_7 && $basename == 'LanguageManager.php') {
    _potx_find_language_names($file_name, $save_callback, $api_version);
  }
  elseif ($basename == 'locale.module') {
    // Applies to all Drupal versions, yay!
    _potx_add_date_strings($file_name, $save_callback, $api_version);
  }
  elseif ($basename == 'common.inc') {
    // Applies to all Drupal versions, yay!
    _potx_add_format_interval_strings($file_name, $save_callback, $api_version);
  }
  elseif ($basename == 'system.module') {
    // Applies to all Drupal versions, yay!
    _potx_add_default_region_names($file_name, $save_callback, $api_version);
  }
  elseif ($basename == 'user.module' && $api_version < POTX_API_8) {
    // Save default user role names (up to Drupal 7).
    $save_callback('anonymous user', POTX_CONTEXT_NONE, $file_name);
    $save_callback('authenticated user', POTX_CONTEXT_NONE, $file_name);
    if ($api_version > POTX_API_6) {
      // Administator role is included by default from Drupal 7.
      $save_callback('administrator', POTX_CONTEXT_NONE, $file_name);
    }
  }
}

/**
 * Executes tasks that need to happen after all the files have been processed.
 *
 * @param string $save_callback
 * @param int $api_version
 */
function potx_finish_processing($save_callback = '_potx_save_string', $api_version = POTX_API_CURRENT) {
  if ($api_version > POTX_API_7) {
    // Parsing shipped configuration has to happen after processing all schemas.
    _potx_parse_shipped_configuration($save_callback, $api_version);
  }
}

/**
 * Creates complete file strings with _potx_store()
 *
 * @param $string_mode
 *   Strings to generate files for: POTX_STRING_RUNTIME or POTX_STRING_INSTALLER.
 * @param $build_mode
 *   Storage mode used: single, multiple or core
 * @param $force_name
 *   Forces a given file name to get used, if single mode is on, without extension
 * @param $save_callback
 *   Callback used to save strings previously.
 * @param $version_callback
 *   Callback used to save versions previously.
 * @param $header_callback
 *   Callback to invoke to get the POT header.
 * @param $template_export_langcode
 *   Language code if the template should have language dependent content
 *   (like plural formulas and language name) included.
 * @param $translation_export_langcode
 *   Language code if translations should also be exported.
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_build_files($string_mode = POTX_STRING_RUNTIME, $build_mode = POTX_BUILD_SINGLE, $force_name = 'general',  $save_callback = '_potx_save_string', $version_callback = '_potx_save_version', $header_callback = '_potx_get_header', $template_export_langcode = NULL, $translation_export_langcode = NULL, $api_version = POTX_API_CURRENT) {
  global $_potx_store;

  // Get strings and versions by reference.
  $strings  = $save_callback(NULL, NULL, NULL, 0, $string_mode);
  $versions = $version_callback();

  // We might not have any string recorded in this string mode.
  if (!is_array($strings)) {
    return;
  }

  foreach ($strings as $string => $string_info) {
    foreach ($string_info as $context => $file_info) {
      // Build a compact list of files this string occured in.
      $occured = $file_list = array();
      // Look for strings appearing in multiple directories (ie.
      // different subprojects). So we can include them in general.pot.
      $names = array_keys($file_info);
      $last_location = dirname(array_shift($names));
      $multiple_locations = FALSE;
      foreach ($file_info as $file => $lines) {
        $occured[] = "$file:". join(';', $lines);
        if (isset($versions[$file])) {
          $file_list[] = $versions[$file];
        }
        if (dirname($file) != $last_location) {
          $multiple_locations = TRUE;
        }
        $last_location = dirname($file);
      }

      // Mark duplicate strings (both translated in the app and in the installer).
      $comment = join(" ", $occured);
      if (strpos($comment, '(dup)') !== FALSE) {
        $comment = '(duplicate) '. str_replace('(dup)', '', $comment);
      }
      $output = "#: $comment\n";

      if ($build_mode == POTX_BUILD_SINGLE) {
        // File name forcing in single mode.
        $file_name = $force_name;
      }
      elseif (strpos($comment, '.info')) {
        // Store .info file strings either in general.pot or the module pot file,
        // depending on the mode used.
        $file_name = ($build_mode == POTX_BUILD_CORE ? 'general' : str_replace('.info', '.module', $file_name));
      }
      elseif ($multiple_locations) {
        // Else if occured more than once, store in general.pot.
        $file_name = 'general';
      }
      else {
        // Fold multiple files in the same folder into one.
        if (empty($last_location) || $last_location == '.') {
          $file_name = 'root';
        }
        else {
          $file_name = str_replace('/', '-', $last_location);
        }
      }


      if (strpos($string, "\0") !== FALSE) {
        // Plural strings have a null byte delimited format.
        list($singular, $plural) = explode("\0", $string);
        if (!empty($context)) {
          $output .= "msgctxt \"$context\"\n";
        }
        $output .= "msgid \"$singular\"\n";
        $output .= "msgid_plural \"$plural\"\n";
        if (isset($translation_export_langcode)) {
          $output .= _potx_translation_export($translation_export_langcode, $singular, $plural, $api_version);
        }
        else {
          $output .= "msgstr[0] \"\"\n";
          $output .= "msgstr[1] \"\"\n";
        }
      }
      else {
        // Simple strings.
        if (!empty($context)) {
          $output .= "msgctxt \"$context\"\n";
        }
        $output .= "msgid \"$string\"\n";
        if (isset($translation_export_langcode)) {
          $output .= _potx_translation_export($translation_export_langcode, $string, NULL, $api_version);
        }
        else {
          $output .= "msgstr \"\"\n";
        }
      }
      $output .= "\n";

      // Store the generated output in the given file storage.
      if (!isset($_potx_store[$file_name])) {
        $_potx_store[$file_name] = array(
          'header'  => $header_callback($file_name, $template_export_langcode, $api_version),
          'sources' => $file_list,
          'strings' => $output,
          'count'   => 1,
        );
      }
      else {
        // Maintain a list of unique file names.
        $_potx_store[$file_name]['sources']  = array_unique(array_merge($_potx_store[$file_name]['sources'], $file_list));
        $_potx_store[$file_name]['strings'] .= $output;
        $_potx_store[$file_name]['count']   += 1;
      }
    }
  }
}

/**
 * Export translations with a specific language.
 *
 * @param $translation_export_langcode
 *   Language code if translations should also be exported.
 * @param $string
 *   String or singular version if $plural was provided.
 * @param $plural
 *   Plural version of singular string.
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_translation_export($translation_export_langcode, $string, $plural = NULL, $api_version = POTX_API_CURRENT) {
  include_once 'includes/locale.inc';

  // Stip out slash escapes.
  $string = stripcslashes($string);

  // Column and table name changed between versions.
  $language_column = $api_version > POTX_API_5 ? 'language' : 'locale';
  $language_table  = $api_version > POTX_API_5 ? 'languages' : 'locales_meta';

  if (!isset($plural)) {
    // Single string to look translation up for.
    if ($translation = db_query("SELECT t.translation FROM {locales_source} s LEFT JOIN {locales_target} t ON t.lid = s.lid WHERE s.source = :source AND t.{$language_column} = :langcode", array(':source' => $string, ':langcode' => $translation_export_langcode))->fetchField()) {
      return 'msgstr '. _locale_export_string($translation);
    }
    return "msgstr \"\"\n";
  }

  else {
    // String with plural variants. Fill up source string array first.
    $plural = stripcslashes($plural);
    $strings = array();
    $number_of_plurals = db_query('SELECT plurals FROM {'. $language_table ."} WHERE {$language_column} = :langcode", array(':langcode' => $translation_export_langcode))->fetchField();
    $plural_index = 0;
    while ($plural_index < $number_of_plurals) {
      if ($plural_index == 0) {
        // Add the singular version.
        $strings[] = $string;
      }
      elseif ($plural_index == 1) {
        // Only add plural version if required.
        $strings[] = $plural;
      }
      else {
        // More plural versions only if required, with the lookup source
        // string modified as imported into the database.
        $strings[] = str_replace('@count', '@count['. $plural_index .']', $plural);
      }
      $plural_index++;
    }

    $output = '';
    if (count($strings)) {
      // Source string array was done, so export translations.
      foreach ($strings as $index => $string) {
        if ($translation = db_query("SELECT t.translation FROM {locales_source} s LEFT JOIN {locales_target} t ON t.lid = s.lid WHERE s.source = :source AND t.{$language_column} = :langcode", array(':source' => $string, ':langcode' => $translation_export_langcode))->fetchField()) {
          $output .= 'msgstr['. $index .'] '. _locale_export_string(_locale_export_remove_plural($translation));
        }
        else {
          $output .= "msgstr[". $index ."] \"\"\n";
        }
      }
    }
    else {
      // No plural information was recorded, so export empty placeholders.
      $output .= "msgstr[0] \"\"\n";
      $output .= "msgstr[1] \"\"\n";
    }
    return $output;
  }
}

/**
 * Returns a header generated for a given file
 *
 * @param $file
 *   Name of POT file to generate header for
 * @param $template_export_langcode
 *   Language code if the template should have language dependent content
 *   (like plural formulas and language name) included.
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_get_header($file, $template_export_langcode = NULL, $api_version = POTX_API_CURRENT) {
  // We only have language to use if we should export with that langcode.
  $language = NULL;
  if (isset($template_export_langcode)) {
    $language = db_query($api_version > POTX_API_5 ? "SELECT language, name, plurals, formula FROM {languages} WHERE language = :langcode" : "SELECT locale, name, plurals, formula FROM {locales_meta} WHERE locale = :langcode", array(':langcode' => $template_export_langcode))->fetchObject();
  }

  $output  = '# $'.'Id'.'$'."\n";
  $output .= "#\n";
  $output .= '# '. (isset($language) ? $language->name : 'LANGUAGE') .' translation of Drupal ('. $file .")\n";
  $output .= "# Copyright YEAR NAME <EMAIL@ADDRESS>\n";
  $output .= "# --VERSIONS--\n";
  $output .= "#\n";
  $output .= "#, fuzzy\n";
  $output .= "msgid \"\"\n";
  $output .= "msgstr \"\"\n";
  $output .= "\"Project-Id-Version: PROJECT VERSION\\n\"\n";
  $output .= '"POT-Creation-Date: '. date("Y-m-d H:iO") ."\\n\"\n";
  $output .= '"PO-Revision-Date: '. (isset($language) ? date("Y-m-d H:iO") : 'YYYY-mm-DD HH:MM+ZZZZ') ."\\n\"\n";
  $output .= "\"Last-Translator: NAME <EMAIL@ADDRESS>\\n\"\n";
  $output .= "\"Language-Team: ". (isset($language) ? $language->name : 'LANGUAGE') ." <EMAIL@ADDRESS>\\n\"\n";
  $output .= "\"MIME-Version: 1.0\\n\"\n";
  $output .= "\"Content-Type: text/plain; charset=utf-8\\n\"\n";
  $output .= "\"Content-Transfer-Encoding: 8bit\\n\"\n";
  if (isset($language->formula) && isset($language->plurals)) {
    $output .= "\"Plural-Forms: nplurals=". $language->plurals ."; plural=". strtr($language->formula, array('$' => '')) .";\\n\"\n\n";
  }
  else {
    $output .= "\"Plural-Forms: nplurals=INTEGER; plural=EXPRESSION;\\n\"\n\n";
  }
  return $output;
}

/**
 * Write out generated files to the current folder.
 *
 * @param $http_filename
 *   File name for content-disposition header in case of usage
 *   over HTTP. If not given, files are written to the local filesystem.
 * @param $content_disposition
 *   See RFC2183. 'inline' or 'attachment', with a default of
 *   'inline'. Only used if $http_filename is set.
 * @todo
 *   Look into whether multiple files can be output via HTTP.
 */
function _potx_write_files($http_filename = NULL, $content_disposition = 'inline') {
  global $_potx_store;

  // Generate file lists and output files.
  if (is_array($_potx_store)) {
    foreach ($_potx_store as $file => $contents) {
      // Build replacement for file listing.
      if (count($contents['sources']) > 1) {
        $filelist = "Generated from files:\n#  " . join("\n#  ", $contents['sources']);
      }
      elseif (count($contents['sources']) == 1) {
        $filelist = "Generated from file: " . join('', $contents['sources']);
      }
      else {
        $filelist = 'No version information was available in the source files.';
      }
      $output = str_replace('--VERSIONS--', $filelist, $contents['header'] . $contents['strings']);

      if ($http_filename) {
        // HTTP output.
        header('Content-Type: text/plain; charset=utf-8');
        header('Content-Transfer-Encoding: 8bit');
        header("Content-Disposition: $content_disposition; filename=$http_filename");
        print $output;
        return;
      }
      else {
        // Local file output, flatten directory structure.
        $file = str_replace('.', '-', preg_replace('![/]?([a-zA-Z_0-9]*/)*!', '', $file)) .'.pot';
        $fp = fopen($file, 'w');
        fwrite($fp, $output);
        fclose($fp);
      }
    }
  }
}

/**
 * Escape quotes in a strings depending on the surrounding
 * quote type used.
 *
 * @param $str
 *   The strings to escape
 */
function _potx_format_quoted_string($str) {
  $quo = substr($str, 0, 1);
  $str = substr($str, 1, -1);
  if ($quo == '"') {
    $str = stripcslashes($str);
  }
  else {
    $str = strtr($str, array("\\'" => "'", "\\\\" => "\\"));
  }
  return addcslashes($str, "\0..\37\\\"");
}

/**
 * Output a marker error with an extract of where the error was found.
 *
 * @param $file
 *   Name of file
 * @param $line
 *   Line number of error
 * @param $marker
 *   Function name with which the error was identified
 * @param $ti
 *   Index on the token array
 * @param $error
 *   Helpful error message for users.
 * @param $docs_url
 *   Documentation reference.
 */
function _potx_marker_error($file, $line, $marker, $ti, $error, $docs_url = NULL) {
  global $_potx_tokens;

  $tokens = '';
  $ti += 2;
  $tc = count($_potx_tokens);
  $par = 1;
  while ((($tc - $ti) > 0) && $par) {
    if (is_array($_potx_tokens[$ti])) {
      $tokens .= $_potx_tokens[$ti][1];
    }
    else {
      $tokens .= $_potx_tokens[$ti];
      if ($_potx_tokens[$ti] == "(") {
        $par++;
      }
      else if ($_potx_tokens[$ti] == ")") {
        $par--;
      }
    }
    $ti++;
  }
  potx_status('error', $error, $file, $line, $marker .'('. $tokens, $docs_url);
}

/**
 * Status notification function.
 *
 * @param $op
 *   Operation to perform or type of message text.
 *     - set:    sets the reporting mode to $value
 *               use one of the POTX_STATUS_* constants as $value
 *     - get:    returns the list of error messages recorded
 *               if $value is true, it also clears the internal message cache
 *     - error:  sends an error message in $value with optional $file and $line
 *     - status: sends a status message in $value
 * @param $value
 *   Value depending on $op.
 * @param $file
 *   Name of file the error message is related to.
 * @param $line
 *   Number of line the error message is related to.
 * @param $excerpt
 *   Excerpt of the code in question, if available.
 * @param $docs_url
 *   URL to the guidelines to follow to fix the problem.
 */
function potx_status($op, $value = NULL, $file = NULL, $line = NULL, $excerpt = NULL, $docs_url = NULL) {
  static $mode = POTX_STATUS_CLI;
  static $messages = array();

  switch ($op) {
    case 'set':
      // Setting the reporting mode.
      $mode = $value;
      return;

    case 'get':
      // Getting the errors. Optionally deleting the messages.
      $errors = $messages;
      if (!empty($value)) {
        $messages = array();
      }
      return $errors;

    case 'error':
    case 'status':

      // Location information is required in 3 of the four possible reporting
      // modes as part of the error message. The structured mode needs the
      // file, line and excerpt info separately, not in the text.
      $location_info = '';
      if (($mode != POTX_STATUS_STRUCTURED) && isset($file)) {
        if (isset($line)) {
          if (isset($excerpt)) {
            $location_info = t('At %excerpt in %file on line %line.', array('%excerpt' => $excerpt, '%file' => $file, '%line' => $line));
          }
          else {
            $location_info = t('In %file on line %line.', array('%file' => $file, '%line' => $line));
          }
        }
        else {
          if (isset($excerpt)) {
            $location_info = t('At %excerpt in %file.', array('%excerpt' => $excerpt, '%file' => $file));
          }
          else {
            $location_info = t('In %file.', array('%file' => $file));
          }
        }
      }

      // Documentation helpers are provided as readable text in most modes.
      $read_more = '';
      if (($mode != POTX_STATUS_STRUCTURED) && isset($docs_url)) {
        $read_more = ($mode == POTX_STATUS_CLI) ? t('Read more at @url', array('@url' => $docs_url)) : t('Read more at <a href="@url">@url</a>', array('@url' => $docs_url));
      }

      // Error message or progress text to display.
      switch ($mode) {
        case POTX_STATUS_MESSAGE:
          drupal_set_message(join(' ', array($value, $location_info, $read_more)), $op);
          break;
        case POTX_STATUS_CLI:
          fwrite($op == 'error' ? STDERR : STDOUT, join("\n", array($value, $location_info, $read_more)) ."\n\n");
          break;
        case POTX_STATUS_SILENT:
          if ($op == 'error') {
            $messages[] = join(' ', array($value, $location_info, $read_more));
          }
          break;
        case POTX_STATUS_STRUCTURED:
          if ($op == 'error') {
            $messages[] = array($value, $file, $line, $excerpt, $docs_url);
          }
          break;
      }
      return;
  }
}

/**
 * Detect all occurances of t()-like calls.
 *
 * These sequences are searched for:
 *   T_STRING("$function_name") + "(" + T_CONSTANT_ENCAPSED_STRING + ")"
 *   T_STRING("$function_name") + "(" + T_CONSTANT_ENCAPSED_STRING + ","
 *
 * @param $file
 *   Name of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 * @param function_name
 *   The name of the function to look for (could be 't', '$t', 'st'
 *   or any other t-like function).
 * @param $string_mode
 *   String mode to use: POTX_STRING_INSTALLER, POTX_STRING_RUNTIME or
 *   POTX_STRING_BOTH.
 */
function _potx_find_t_calls($file, $save_callback, $function_name = 't', $string_mode = POTX_STRING_RUNTIME) {
  global $_potx_tokens, $_potx_lookup;

  // Lookup tokens by function name.
  if (isset($_potx_lookup[$function_name])) {
    foreach ($_potx_lookup[$function_name] as $ti) {
      list($prev, $ctok, $par, $mid, $rig) = array($_potx_tokens[$ti - 1], $_potx_tokens[$ti], $_potx_tokens[$ti+1], $_potx_tokens[$ti+2], $_potx_tokens[$ti+3]);
      list($type, $string, $line) = $ctok;

      if (is_array($prev) && $prev[0] == T_FUNCTION) {
        continue;
      }

      if ($function_name == 'debug' && is_array($prev) && $prev[0] != T_OBJECT_OPERATOR) {
        continue;
      }

      if ($par == "(") {
        if (in_array($rig, array(")", ","))
          && (is_array($mid) && ($mid[0] == T_CONSTANT_ENCAPSED_STRING))) {
            // This function is only used for context-less call types.
            $save_callback(_potx_format_quoted_string($mid[1]), POTX_CONTEXT_NONE, $file, $line, $string_mode);
        }
        else {
          // $function_name() found, but inside is something which is not a string literal.
          _potx_marker_error($file, $line, $function_name, $ti, t('The first parameter to @function() should be a literal string. There should be no variables, concatenation, constants or other non-literal strings there.', array('@function' => $function_name)), 'http://drupal.org/node/322732');
        }
      }
    }
  }
}

/**
 * Detect all occurances of t()-like calls from Drupal 7 (with context).
 *
 * These sequences are searched for:
 *   T_STRING("$function_name") + "(" + T_CONSTANT_ENCAPSED_STRING + ")"
 *   T_STRING("$function_name") + "(" + T_CONSTANT_ENCAPSED_STRING + ","
 *   and then an optional value for the replacements and an optional array
 *   for the options with an optional context key.
 *
 * @param $file
 *   Name of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 * @param function_name
 *   The name of the function to look for (could be 't', '$t', 'st'
 *   or any other t-like function). Drupal 7 only supports context on t(), st()
 *   and $t().
 * @param $string_mode
 *   String mode to use: POTX_STRING_INSTALLER, POTX_STRING_RUNTIME or
 *   POTX_STRING_BOTH.
 */
function _potx_find_t_calls_with_context($file, $save_callback, $function_name = 't', $string_mode = POTX_STRING_RUNTIME) {
  global $_potx_tokens, $_potx_lookup;

  // Lookup tokens by function name.
  if (isset($_potx_lookup[$function_name])) {
    foreach ($_potx_lookup[$function_name] as $ti) {
      list($prev, $ctok, $par, $mid, $rig) = array($_potx_tokens[$ti - 1], $_potx_tokens[$ti], $_potx_tokens[$ti+1], $_potx_tokens[$ti+2], $_potx_tokens[$ti+3]);
      list($type, $string, $line) = $ctok;

      if (is_array($prev) && $prev[0] == T_FUNCTION) {
        continue;
      }

      if ($par == "(") {
        if (in_array($rig, array(")", ","))
          && (is_array($mid) && ($mid[0] == T_CONSTANT_ENCAPSED_STRING))) {
          // By default, there is no context.
          $context = POTX_CONTEXT_NONE;
          if ($rig == ',') {
            // If there was a comma after the string, we need to look forward
            // to try and find the context.
            $context = _potx_find_context($ti, $ti + 4, $file, $function_name);
          }
          if ($context !== POTX_CONTEXT_ERROR) {
            // Only save if there was no error in context parsing.
            $save_callback(_potx_format_quoted_string($mid[1]), $context, $file, $line, $string_mode);
          }
        }
        else {
          // $function_name() found, but inside is something which is not a string literal.
          _potx_marker_error($file, $line, $function_name, $ti, t('The first parameter to @function() should be a literal string. There should be no variables, concatenation, constants or other non-literal strings there.', array('@function' => $function_name)), 'http://drupal.org/node/322732');
        }
      }
    }
  }
}

/**
 * Detect all occurances of watchdog() calls. Only in Drupal 6 and Drupal 7.
 *
 * These sequences are searched for:
 *   watchdog + "(" + T_CONSTANT_ENCAPSED_STRING + "," +
 *   T_CONSTANT_ENCAPSED_STRING + something
 *
 * @param $file
 *   Name of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 */
function _potx_find_watchdog_calls($file, $save_callback) {
  global $_potx_tokens, $_potx_lookup;

  // Lookup tokens by function name.
  if (isset($_potx_lookup['watchdog'])) {
    foreach ($_potx_lookup['watchdog'] as $ti) {
      list($prev, $ctok, $par, $mtype, $comma, $message, $rig) = array($_potx_tokens[$ti - 1], $_potx_tokens[$ti], $_potx_tokens[$ti+1], $_potx_tokens[$ti+2], $_potx_tokens[$ti+3], $_potx_tokens[$ti+4], $_potx_tokens[$ti+5]);
      list($type, $string, $line) = $ctok;

      if (is_array($prev) && $prev[0] == T_FUNCTION) {
        continue;
      }

      if ($par == '(') {
        // Both type and message should be a string literal.
        if (in_array($rig, array(')', ',')) && $comma == ','
          && (is_array($mtype) && ($mtype[0] == T_CONSTANT_ENCAPSED_STRING))
          && (is_array($message) && ($message[0] == T_CONSTANT_ENCAPSED_STRING))) {
            // Context is not supported on watchdog().
            $save_callback(_potx_format_quoted_string($mtype[1]), POTX_CONTEXT_NONE, $file, $line);
            $save_callback(_potx_format_quoted_string($message[1]), POTX_CONTEXT_NONE, $file, $line);
        }
        else {
          // watchdog() found, but inside is something which is not a string literal.
          _potx_marker_error($file, $line, 'watchdog', $ti, t('The first two watchdog() parameters should be literal strings. There should be no variables, concatenation, constants or even a t() call there.'), 'http://drupal.org/node/323101');
        }
      }
    }
  }
}

/**
 * Detect all occurances of log() calls.
 *
 * These sequences are searched for:
 *   log + "(" + ..anything (might be more tokens).. +
 *   "," + T_CONSTANT_ENCAPSED_STRING + whatever.
 *
 * @param $file
 *   Name of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 */
function _potx_find_log_calls($file, $save_callback) {
  global $_potx_tokens, $_potx_lookup;

  if (isset($_potx_lookup['log'])) {
    foreach ($_potx_lookup['log'] as $ti) {
      list($prev, $ctok, $par1) = array($_potx_tokens[$ti - 1], $_potx_tokens[$ti], $_potx_tokens[$ti+1]);
      list($type, $string, $line) = $ctok;

      if (is_array($prev) && $prev[0] == T_FUNCTION) {
        continue;
      }

      if ($par1 == "(") {
        // Eat up everything that is used as the first parameter
        $tn = $ti + 2;
        $depth = 0;
        while (!($_potx_tokens[$tn] == "," && $depth == 0)) {
          if ($_potx_tokens[$tn] == "(") {
            $depth++;
          }
          elseif ($_potx_tokens[$tn] == ")") {
            $depth--;
          }
          $tn++;
          if ($depth < 0) {
            // There is no second argument. This log() call was a false
            // positive, continue with the next one.
            continue 2;
          }
        }
        // Get further parameters
        list($comma, $message, $par2) = array($_potx_tokens[$tn], $_potx_tokens[$tn+1], $_potx_tokens[$tn+2]);
        if (($comma == ',') && in_array($par2, array(')', ',')) &&
          (is_array($message) && ($message[0] == T_CONSTANT_ENCAPSED_STRING))) {
          // Context is not supported on watchdog().
          $save_callback(_potx_format_quoted_string($message[1]), POTX_CONTEXT_NONE, $file, $line);
        }
        else {
          // log() found, but the parameters are not correct.
          _potx_marker_error($file, $line, 'log', $ti, t('In log(), the log level should be followed by a literal string. There should be no variables, concatenation, constants or even a t() call there.'), 'http://drupal.org/node/323101');
        }
      }
    }
  }
}

/**
 * Detect all occurances of format_plural calls.
 *
 * These sequences are searched for:
 *   T_STRING("$function_name") + "(" + ..anything (might be more tokens).. +
 *   "," + T_CONSTANT_ENCAPSED_STRING +
 *   "," + T_CONSTANT_ENCAPSED_STRING + parenthesis (or comma allowed from
 *   Drupal 6)
 *
 * @param $file
 *   Name of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 * @param $function_name
 *   The name of the function to look for (could be 'format_plural' or
 *   'formatPlural').
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_find_format_plural_calls($file, $save_callback, $function_name = 'format_plural', $api_version = POTX_API_CURRENT) {
  global $_potx_tokens, $_potx_lookup;

  if (isset($_potx_lookup[$function_name])) {
    foreach ($_potx_lookup[$function_name] as $ti) {
      list($prev, $ctok, $par1) = array($_potx_tokens[$ti - 1], $_potx_tokens[$ti], $_potx_tokens[$ti+1]);
      list($type, $string, $line) = $ctok;

      if (is_array($prev) && $prev[0] == T_FUNCTION) {
        continue;
      }

      if ($par1 == "(") {
        // Eat up everything that is used as the first parameter
        $tn = $ti + 2;
        $depth = 0;
        while (!($_potx_tokens[$tn] == "," && $depth == 0)) {
          if ($_potx_tokens[$tn] == "(") {
            $depth++;
          }
          elseif ($_potx_tokens[$tn] == ")") {
            $depth--;
          }
          $tn++;
          if ($depth < 0) {
            // There is no second argument. This $function_name() call was a
            // false positive, continue with the next one.
            continue 2;
          }
        }
        // Get further parameters
        list($comma1, $singular, $comma2, $plural, $par2) = array($_potx_tokens[$tn], $_potx_tokens[$tn+1], $_potx_tokens[$tn+2], $_potx_tokens[$tn+3], $_potx_tokens[$tn+4]);
        if (($comma2 == ',') && ($par2 == ')' || ($par2 == ',' && $api_version > POTX_API_5)) &&
          (is_array($singular) && ($singular[0] == T_CONSTANT_ENCAPSED_STRING)) &&
          (is_array($plural) && ($plural[0] == T_CONSTANT_ENCAPSED_STRING))) {
          // By default, there is no context.
          $context = POTX_CONTEXT_NONE;
          if ($par2 == ',' && $api_version > POTX_API_6) {
            // If there was a comma after the plural, we need to look forward
            // to try and find the context.
            $context = _potx_find_context($ti, $tn + 5, $file, $function_name);
          }
          if ($context !== POTX_CONTEXT_ERROR) {
            // Only save if there was no error in context parsing.
            $save_callback(
              _potx_format_quoted_string($singular[1]) ."\0". _potx_format_quoted_string($plural[1]),
              $context,
              $file,
              $line
            );
          }
        }
        else {
          // $function_name() found, but the parameters are not correct.
          _potx_marker_error($file, $line, $function_name, $ti, t('In @function(), the singular and plural strings should be literal strings. There should be no variables, concatenation, constants or even a t() call there.', array('@function' => $function_name)), 'http://drupal.org/node/323072');
        }
      }
    }
  }
}

/**
 * Detect permission names from the hook_perm() implementations.
 * Note that this will get confused with a similar pattern in a comment,
 * and with dynamic permissions, which need to be accounted for.
 *
 * @param $file
 *   Full path name of file parsed.
 * @param $filebase
 *   Filenaname of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 */
function _potx_find_perm_hook($file, $filebase, $save_callback) {
  global $_potx_tokens, $_potx_lookup;

  if (isset($_potx_lookup[$filebase .'_perm'])) {
    // Special case for node module, because it uses dynamic permissions.
    // Include the static permissions by hand. That's about all we can do here.
    if ($filebase == 'node') {
      $line = $_potx_tokens[$_potx_lookup['node_perm'][0]][2];
      // List from node.module 1.763 (checked in on 2006/12/29 at 21:25:36 by drumm)
      $nodeperms = array('administer content types', 'administer nodes', 'access content', 'view revisions', 'revert revisions');
      foreach ($nodeperms as $item) {
        // hook_perm() is only ever found on a Drupal system which does not
        // support context.
        $save_callback($item, POTX_CONTEXT_NONE, $file, $line);
      }
    }
    else {
      $count = 0;
      foreach ($_potx_lookup[$filebase .'_perm'] as $ti) {
        $tn = $ti;
        while (is_array($_potx_tokens[$tn]) || $_potx_tokens[$tn] != '}') {
          if (is_array($_potx_tokens[$tn]) && $_potx_tokens[$tn][0] == T_CONSTANT_ENCAPSED_STRING) {
            // hook_perm() is only ever found on a Drupal system which does not
            // support context.
            $save_callback(_potx_format_quoted_string($_potx_tokens[$tn][1]), POTX_CONTEXT_NONE, $file, $_potx_tokens[$tn][2]);
            $count++;
          }
          $tn++;
        }
      }
      if (!$count) {
        potx_status('error', t('%hook should have an array of literal string permission names.', array('%hook' => $filebase .'_perm()')), $file, NULL, NULL, 'http://drupal.org/node/323101');
      }
    }
  }
}

/**
 * Helper function to look up the token closing the current function.
 *
 * @param $here
 *   The token at the function name
 */
function _potx_find_end_of_function($here) {
  global $_potx_tokens;

  // Seek to open brace.
  while (is_array($_potx_tokens[$here]) || $_potx_tokens[$here] != '{') {
    $here++;
  }
  $nesting = 1;
  while ($nesting > 0) {
    $here++;
    if (!is_array($_potx_tokens[$here])) {
      if ($_potx_tokens[$here] == '}') {
        $nesting--;
      }
      if ($_potx_tokens[$here] == '{') {
        $nesting++;
      }
    }
  }
  return $here;
}

/**
 * Helper to move past t() and format_plural() arguments in search of context.
 *
 * @param $here
 *   The token before the start of the arguments
 */
function _potx_skip_args($here) {
  global $_potx_tokens;

  $nesting = 0;
  // Go through to either the end of the function call or to a comma
  // after the current position on the same nesting level.
  while (!(($_potx_tokens[$here] == ',' && $nesting == 0) ||
           ($_potx_tokens[$here] == ')' && $nesting == -1))) {
    $here++;
    if (!is_array($_potx_tokens[$here])) {
      if ($_potx_tokens[$here] == ')') {
        $nesting--;
      }
      if ($_potx_tokens[$here] == '(') {
        $nesting++;
      }
    }
  }
  // If we run out of nesting, it means we reached the end of the function call,
  // so we skipped the arguments but did not find meat for looking at the
  // specified context.
  return ($nesting == 0 ? $here : FALSE);
}

/**
 * Helper to find the value for 'context' on t() and format_plural().
 *
 * @param $tf
 *   Start position of the original function.
 * @param $ti
 *   Start position where we should search from.
 * @param $file
 *   Full path name of file parsed.
 * @param function_name
 *   The name of the function to look for. Either 'format_plural' or 't'
 *   given that Drupal 7 only supports context on these.
 */
function _potx_find_context($tf, $ti, $file, $function_name) {
  global $_potx_tokens;

  // Start from after the comma and skip the possible arguments for the function
  // so we can look for the context.
  if (($ti = _potx_skip_args($ti)) && ($_potx_tokens[$ti] == ',')) {
    // Now we actually might have some definition for a context. The $options
    // argument is coming up, which might have a key for context.
    list($com, $arr, $par) = array($_potx_tokens[$ti], $_potx_tokens[$ti+1], $_potx_tokens[$ti+2]);
    if ($com == ',' && $arr[1] == 'array' && $par == '(') {
      $nesting = 0;
      $ti += 3;
      // Go through to either the end of the array or to the key definition of
      // context on the same nesting level.
      while (!((is_array($_potx_tokens[$ti]) && (in_array($_potx_tokens[$ti][1], array('"context"', "'context'"))) && ($_potx_tokens[$ti][0] == T_CONSTANT_ENCAPSED_STRING) && ($nesting == 0)) ||
               ($_potx_tokens[$ti] == ')' && $nesting == -1))) {
        $ti++;
        if (!is_array($_potx_tokens[$ti])) {
          if ($_potx_tokens[$ti] == ')') {
            $nesting--;
          }
          if ($_potx_tokens[$ti] == '(') {
            $nesting++;
          }
        }
      }
      if ($nesting == 0) {
        // Found the 'context' key on the top level of the $options array.
        list($arw, $str) = array($_potx_tokens[$ti+1], $_potx_tokens[$ti+2]);
        if (is_array($arw) && $arw[1] == '=>' && is_array($str) && $str[0] == T_CONSTANT_ENCAPSED_STRING) {
          return _potx_format_quoted_string($str[1]);
        }
        else {
          list($type, $string, $line) = $_potx_tokens[$ti];
          // @todo: fix error reference.
          _potx_marker_error($file, $line, $function_name, $tf, t('The context element in the options array argument to @function() should be a literal string. There should be no variables, concatenation, constants or other non-literal strings there.', array('@function' => $function_name)), 'http://drupal.org/node/322732');
          // Return with error.
          return POTX_CONTEXT_ERROR;
        }
      }
      else {
        // Did not found 'context' key in $options array.
        return POTX_CONTEXT_NONE;
      }
    }
  }

  // After skipping args, we did not find a comma to look for $options.
  return POTX_CONTEXT_NONE;
}

/**
 * List of menu item titles. Only from Drupal 6.
 *
 * @param $file
 *   Full path name of file parsed.
 * @param $filebase
 *   Filenaname of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 */
function _potx_find_menu_hooks($file, $filebase, $save_callback) {
  global $_potx_tokens, $_potx_lookup;

  $hooks = array('_menu', '_menu_alter');
  $keys = array("'title'", '"title"', "'description'", '"description"');

  foreach ($hooks as $hook) {
    if (isset($_potx_lookup[$filebase . $hook]) && is_array($_potx_lookup[$filebase . $hook])) {
      // We have this menu hook in this file.
      foreach ($_potx_lookup[$filebase . $hook] as $ti) {
        $end = _potx_find_end_of_function($ti);
        $tn = $ti;
        while ($tn < $end) {

          // Support for array syntax more commonly used in menu hooks:
          // $items = array('node/add' => array('title' => 'Add content'));
          if ($_potx_tokens[$tn][0] == T_CONSTANT_ENCAPSED_STRING && in_array($_potx_tokens[$tn][1], $keys) && $_potx_tokens[$tn+1][0] == T_DOUBLE_ARROW) {
            if ($_potx_tokens[$tn+2][0] == T_CONSTANT_ENCAPSED_STRING) {
              // We cannot export menu item context.
              $save_callback(
                _potx_format_quoted_string($_potx_tokens[$tn+2][1]),
                POTX_CONTEXT_NONE,
                $file,
                $_potx_tokens[$tn+2][2]
              );
              $tn+=2; // Jump forward by 2.
            }
            else {
              potx_status('error', t('Invalid menu %element definition found in %hook. Title and description keys of the menu array should be literal strings.', array('%element' => $_potx_tokens[$tn][1], '%hook' => $filebase . $hook .'()')), $file, $_potx_tokens[$tn][2], NULL, 'http://drupal.org/node/323101');
            }
          }

          // Support for array syntax more commonly used in menu alters:
          // $items['node/add']['title'] = 'Add content here';
          if (is_string($_potx_tokens[$tn]) && $_potx_tokens[$tn] == '[' && $_potx_tokens[$tn+1][0] == T_CONSTANT_ENCAPSED_STRING && in_array($_potx_tokens[$tn+1][1], $keys) && is_string($_potx_tokens[$tn+2]) && $_potx_tokens[$tn+2] == ']') {
            if (is_string($_potx_tokens[$tn+3]) && $_potx_tokens[$tn+3] == '=' && $_potx_tokens[$tn+4][0] == T_CONSTANT_ENCAPSED_STRING) {
              // We cannot export menu item context.
              $save_callback(
                _potx_format_quoted_string($_potx_tokens[$tn+4][1]),
                POTX_CONTEXT_NONE,
                $file,
                $_potx_tokens[$tn+4][2]
              );
              $tn+=4; // Jump forward by 4.
            }
            else {
              potx_status('error', t('Invalid menu %element definition found in %hook. Title and description keys of the menu array should be literal strings.', array('%element' => $_potx_tokens[$tn+1][1], '%hook' => $filebase . $hook .'()')), $file, $_potx_tokens[$tn+1][2], NULL, 'http://drupal.org/node/323101');
            }
          }
          $tn++;
        }
      }
    }
  }
}

/**
 * Get languages names from Drupal's locale.inc.
 *
 * @param $file
 *   Full path name of file parsed
 * @param $save_callback
 *   Callback function used to save strings.
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_find_language_names($file, $save_callback, $api_version = POTX_API_CURRENT) {
  global $_potx_tokens, $_potx_lookup;

  if ($api_version > POTX_API_7) {
    $key = 'getStandardLanguageList';
  }
  elseif ($api_version > POTX_API_5) {
    $key = '_locale_get_predefined_list';
  }
  else {
    $key = '_locale_get_iso639_list';
  }

  foreach ($_potx_lookup[$key] as $ti) {
    // Search for the definition of _locale_get_predefined_list(), not where it is called.
    if ($_potx_tokens[$ti-1][0] == T_FUNCTION) {
      break;
    }
  }

  $end = _potx_find_end_of_function($ti);
  $ti += 7; // function name, (, ), {, return, array, (
  while ($ti < $end) {
    while ($_potx_tokens[$ti][0] != T_ARRAY) {
      if (!is_array($_potx_tokens[$ti]) && $_potx_tokens[$ti] == ';') {
        // We passed the end of the list, break out to function level
        // to prevent an infinite loop.
        break 2;
      }
      $ti++;
    }
    $ti += 2; // array, (
    // Language names are context-less.
    $save_callback(_potx_format_quoted_string($_potx_tokens[$ti][1]), POTX_CONTEXT_NONE, $file, $_potx_tokens[$ti][2]);
  }
}

/**
 * Get the exact CVS version number from the file, so we can
 * push that into the generated output.
 *
 * @param $code
 *   Complete source code of the file parsed.
 * @param $file
 *   Name of the file parsed.
 * @param $version_callback
 *   Callback used to save the version information.
 */
function _potx_find_version_number($code, $file, $version_callback) {
  // Prevent CVS from replacing this pattern with actual info.
  if (preg_match('!\\$I'.'d: ([^\\$]+) Exp \\$!', $code, $version_info)) {
    $version_callback($version_info[1], $file);
  }
  else {
    // Unknown version information.
    $version_callback($file .': n/a', $file);
  }
}

/**
 * Add date strings, which cannot be extracted otherwise.
 * This is called for locale.module.
 *
 * @param $file
 *   Name of the file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_add_date_strings($file, $save_callback, $api_version = POTX_API_CURRENT) {
  for ($i = 1; $i <= 12; $i++) {
    $stamp = mktime(0, 0, 0, $i, 1, 1971);
    if ($api_version > POTX_API_6) {
      // From Drupal 7, long month names are saved with this context.
      $save_callback(date("F", $stamp), 'Long month name', $file);
    }
    elseif ($api_version > POTX_API_5) {
      // Drupal 6 uses a little hack. No context.
      $save_callback('!long-month-name '. date("F", $stamp), POTX_CONTEXT_NONE, $file);
    }
    else {
      // Older versions just accept the confusion, no context.
      $save_callback(date("F", $stamp), POTX_CONTEXT_NONE, $file);
    }
    // Short month names lack a context anyway.
    $save_callback(date("M", $stamp), POTX_CONTEXT_NONE, $file);
  }
  for ($i = 0; $i <= 7; $i++) {
    $stamp = $i * 86400;
    $save_callback(date("D", $stamp), POTX_CONTEXT_NONE, $file);
    $save_callback(date("l", $stamp), POTX_CONTEXT_NONE, $file);
  }
  $save_callback('am', POTX_CONTEXT_NONE, $file);
  $save_callback('pm', POTX_CONTEXT_NONE, $file);
  $save_callback('AM', POTX_CONTEXT_NONE, $file);
  $save_callback('PM', POTX_CONTEXT_NONE, $file);
}

/**
 * Add format_interval special strings, which cannot be
 * extracted otherwise. This is called for common.inc
 *
 * @param $file
 *   Name of the file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_add_format_interval_strings($file, $save_callback, $api_version = POTX_API_CURRENT) {
  $components = array(
    '1 year' => '@count years',
    '1 week' => '@count weeks',
    '1 day'  => '@count days',
    '1 hour' => '@count hours',
    '1 min'  => '@count min',
    '1 sec'  => '@count sec'
  );
  if ($api_version > POTX_API_6) {
    // Month support added in Drupal 7.
    $components['1 month'] = '@count months';
  }

  foreach ($components as $singular => $plural) {
    // Intervals support no context.
    $save_callback($singular ."\0". $plural, POTX_CONTEXT_NONE, $file);
  }
}

/**
 * Add default theme region names, which cannot be extracted otherwise.
 * These default names are defined in system.module
 *
 * @param $file
 *   Name of the file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_add_default_region_names($file, $save_callback, $api_version = POTX_API_CURRENT) {
  $regions = array(
    'left' => 'Left sidebar',
    'right' => 'Right sidebar',
    'content' => 'Content',
    'header' => 'Header',
    'footer' => 'Footer',
  );
  if ($api_version > POTX_API_6) {
    $regions['highlight'] = 'Highlighted';
    $regions['help'] = 'Help';
    $regions['page_top'] = 'Page top';
    $regions['page_top'] = 'Page bottom';
  }
  foreach ($regions as $region) {
    // Regions come with the default context.
    $save_callback($region, POTX_CONTEXT_NONE, $file);
  }
}

/**
 * Parse an .info file and add relevant strings to the list.
 *
 * @param $file_path
 *   Complete file path to load contents with.
 * @param $file_name
 *   Stripped file name to use in outpout.
 * @param $strings
 *   Current strings array
 * @param $api_version
 *   Drupal API version to work with.
 */
function _potx_find_info_file_strings($file_path, $file_name, $save_callback, $api_version = POTX_API_CURRENT) {
  $info = array();

  if (file_exists($file_path)) {
    $info = $api_version > POTX_API_5 ? drupal_parse_info_file($file_path) : parse_ini_file($file_path);
  }

  // We need the name, description and package values. Others,
  // like core and PHP compatibility, timestamps or versions
  // are not to be translated.
  foreach (array('name', 'description', 'package') as $key) {
    if (isset($info[$key])) {
      // No context support for .info file strings.
      $save_callback(addcslashes($info[$key], "\0..\37\\\""), POTX_CONTEXT_NONE, $file_name);
    }
  }

  // Add regions names from themes.
  if (isset($info['regions']) && is_array($info['regions'])) {
    foreach ($info['regions'] as $region => $region_name) {
      // No context support for .info file strings.
      $save_callback(addcslashes($region_name, "\0..\37\\\""), POTX_CONTEXT_NONE, $file_name);
    }
  }
}

/**
 * Parse a JavaScript file for translatables. Only from Drupal 6.
 *
 * Extracts strings wrapped in Drupal.t() and Drupal.formatPlural()
 * calls and inserts them into potx storage.
 *
 * Regex code lifted from _locale_parse_js_file().
 */
function _potx_parse_js_file($code, $file, $save_callback) {
  // Match all calls to Drupal.t() in an array.
  // Note: \s also matches newlines with the 's' modifier.
  preg_match_all('~
    [^\w]Drupal\s*\.\s*t\s*                     # match "Drupal.t" with whitespace
    \(\s*                                       # match "(" argument list start
    (' . POTX_JS_STRING . ')\s*                 # capture string argument
    (?:,\s*' . POTX_JS_OBJECT . '\s*            # optionally capture str args
      (?:,\s*' . POTX_JS_OBJECT_CONTEXT . '\s*) # optionally capture context
    ?)?                                         # close optional args
    \)                                          # match ")" to finish
    ~sx', $code, $t_matches, PREG_SET_ORDER);

  // Add strings from Drupal.t().
  if (isset($t_matches) && count($t_matches)) {
    foreach ($t_matches as $match) {
      // Remove match from code to help us identify faulty Drupal.t() calls.
      $code = str_replace($match[0], '', $code);

      // Get context
      if (!empty($match[2])) {
        // Remove wrapping quotes
        $context = preg_replace('~^[\'"]|[\'"]$~', '', $match[2]);
        $context = _potx_parse_js_string($match[2]);
      }
      else {
        // Set context to null
        $context = POTX_CONTEXT_NONE;
      }

      $save_callback(_potx_parse_js_string($match[1]), $context, $file, 0);
    }
  }

  // Match all Drupal.formatPlural() calls in another array.
  preg_match_all('~
    [^\w]Drupal\s*\.\s*formatPlural\s*  # match "Drupal.formatPlural" with whitespace
    \(                                  # match "(" argument list start
    \s*.+?\s*,\s*                       # match count argument
    (' . POTX_JS_STRING . ')\s*,\s*     # match singular string argument
    (                                   # capture plural string argument
      (?:                               # non-capturing group to repeat string pieces
        (?:
          \'                            # match start of single-quoted string
          (?:\\\\\'|[^\'])*             # match any character except unescaped single-quote
          @count                        # match "@count"
          (?:\\\\\'|[^\'])*             # match any character except unescaped single-quote
          \'                            # match end of single-quoted string
          |
          "                             # match start of double-quoted string
          (?:\\\\"|[^"])*               # match any character except unescaped double-quote
          @count                        # match "@count"
          (?:\\\\"|[^"])*               # match any character except unescaped double-quote
          "                             # match end of double-quoted string
        )
        (?:\s*\+\s*)?                   # match "+" with possible whitespace, for str concat
      )+                                # match multiple because we supports concatenating strs
    )\s*                                # end capturing of plural string argument
    (?:,\s*' . POTX_JS_OBJECT . '\s*              # optionally capture string args
      (?:,\s*' . POTX_JS_OBJECT_CONTEXT . '\s*)?  # optionally capture context
    )?
    \)                                            # match ")" to finish
    ~sx', $code, $plural_matches, PREG_SET_ORDER);

  if (isset($plural_matches) && count($plural_matches)) {
    foreach ($plural_matches as $index => $match) {
      // Remove match from code to help us identify faulty
      // Drupal.formatPlural() calls later.
      $code = str_replace($match[0], '', $code);

      // Get context
      if (!empty($match[3])) {
        // Remove wrapping quotes
        $context = preg_replace('~^[\'"]|[\'"]$~', '', $match[3]);
        $context = _potx_parse_js_string($match[3]);
      }
      else {
        // Set context to null
        $context = POTX_CONTEXT_NONE;
      }

      $save_callback(
        _potx_parse_js_string($match[1]) ."\0". _potx_parse_js_string($match[2]),
        $context,
        $file,
        0
      );
    }
  }

  // Any remaining Drupal.t() or Drupal.formatPlural() calls are evil. This
  // regex is not terribly accurate (ie. code wrapped inside will confuse
  // the match), but we only need some unique part to identify the faulty calls.
  preg_match_all('~[^\w]Drupal\s*\.\s*(t|formatPlural)\s*\([^)]+\)~s', $code, $faulty_matches, PREG_SET_ORDER);
  if (isset($faulty_matches) && count($faulty_matches)) {
    foreach ($faulty_matches as $index => $match) {
      $message = ($match[1] == 't') ? t('Drupal.t() calls should have a single literal string as their first parameter.') : t('The singular and plural string parameters on Drupal.formatPlural() calls should be literal strings, plural containing a @count placeholder.');
      potx_status('error', $message, $file, NULL, $match[0], 'http://drupal.org/node/323109');
    }
  }
}

/**
 * Clean up string found in JavaScript source code. Only from Drupal 6.
 */
function _potx_parse_js_string($string) {
  return _potx_format_quoted_string(implode('', preg_split('~(?<!\\\\)[\'"]\s*\+\s*[\'"]~s', $string)));
}

/**
 * Parse a Twig template for translatables. Drupal 8+.
 */
function _potx_parse_twig_file($code, $file, $save_callback) {
  $twig_lexer = new Twig_Lexer();
  $stream = $twig_lexer->tokenize($code, $file);

  while (!$stream->isEOF()) {
    $token = $stream->next();
    // Capture strings translated with the t or trans filter.
    if ($token->test(Twig_Token::VAR_START_TYPE)) {
      $token = $stream->next();
      if ($token->test(Twig_Token::NAME_TYPE)) {
        continue;
      }
      $string = $token->getValue();
      $line = $token->getLine();
      $has_t = false;
      $chained = false;
      $is_concat = false;

      if ($stream->test(Twig_Token::PUNCTUATION_TYPE, '.')) {
        $is_concat = true;
      }

      while (!$stream->isEOF() && ($token = $stream->next()) && (!$token->test(Twig_Token::VAR_END_TYPE))) {
        if ($token->test(Twig_Token::PUNCTUATION_TYPE, '|')) {
          if ($stream->test(array('t', 'trans'))) {
            $has_t = true;
          }
          else {
            $chained = true;
          }
        }
      }

      if ($has_t) {
        if (!$chained && !$is_concat) {
          $save_callback(_potx_format_quoted_string('"' . trim($string) . '"'), POTX_CONTEXT_NONE, $file, $line);
        }
        else {
          $message = t('Uses of the t filter in Twig templates should start with a single literal string, and should not be chained.');
          // TODO: Fill in specific URL for Twig documentation once it exists.
          potx_status('error', $message, $file, NULL, NULL, 'https://drupal.org/developing/api/localization');
        }
      }
    }
    elseif ($token->test(Twig_Token::BLOCK_START_TYPE)) {
      $token = $stream->next();
      if ($token->test('trans')) {
        _potx_process_twig_trans_tag($stream, $file, $save_callback);
      }
    }
  }
}

/**
 * Parses a single {% trans %} tag, and extracts the translatable string.
 *
 * a {% trans %} tag can have the following formats:
 *   1. {% trans 'string' %}
 *   2. {% trans %} string {% endtrans %}
 *   3. {% trans %} singular string {% plural %} plural string {% endtrans %}
 *
 * @param Twig_TokenStream $stream
 */
function _potx_process_twig_trans_tag($stream, $file, $save_callback) {
  $is_plural = FALSE;
  $context = POTX_CONTEXT_NONE;

  // If the current token in the stream is a string, this trans tag
  // has a simple string argument to be translated.
  $token = $stream->next();
  if ($token->test(Twig_Token::STRING_TYPE)) {
    $text = $token->getValue();
    // Check for context.
    $token = $stream->next();
    if ($token->test(Twig_Token::NAME_TYPE, 'with')) {
      $context = _potx_find_twig_trans_context($stream);
    }
    $save_callback(_potx_format_quoted_string('"' . trim($text) . '"'), $context, $file, $token->getLine());
    return;
  }

  // Otherwise, we are in a trans/endtrans structure.

  $text = array();
  $line = $token->getLine();
  // Process the stream until we reach the endtrans tag.
  while (!$stream->isEOF() && (!$token->test('endtrans'))) {
    // If it's text, add it to the translation.
    if ($token->test(Twig_Token::TEXT_TYPE)) {
      $text[] = $token->getValue();
    }
    elseif ($token->test(Twig_Token::NAME_TYPE, 'with')) {
      $context = _potx_find_twig_trans_context($stream);
    }
    elseif ($token->test('plural')) {
      $singular = implode('', $text);
      $is_plural = true;
      $text = array();
      // Skip past the 'count' token.
      $stream->next();
    }
    elseif ($token->test(Twig_Token::VAR_START_TYPE)) {
      $name = array();
      while ($stream->look(1)->test(Twig_Token::PUNCTUATION_TYPE, '.')) {
        $token = $stream->next();
        $name[] = $token->getValue();
        $stream->next();
      }
      $token = $stream->next();
      $name[] = $token->getValue();

      $name = implode('.', $name);
      // Figure out if it's escaped, passthrough, or placeholder.
      $token = $stream->next();
      // If the next thing we see is }}, this is escaped.
      if ($token->test(Twig_Token::VAR_END_TYPE)) {
        $text[] = "@$name";
      }
      // If the next thing we see is |, this is either passthrough or placeholder.
      elseif ($token->test(Twig_Token::PUNCTUATION_TYPE, '|')) {
        $token = $stream->next();
        if ($token->getValue() == 'passthrough') {
          $text[] = "!$name";
        }
        elseif ($token->getValue() == 'placeholder') {
          $text[] = "%$name";
        }
      }
    }
    $token = $stream->next();
  }

  if ($is_plural) {
    $plural = implode('', $text);
    $save_callback(_potx_format_quoted_string('"' . trim($singular) . '"') . "\0" . _potx_format_quoted_string('"' . trim($plural) . '"'), $context, $file, $line);
  }
  else {
    $save_callback(_potx_format_quoted_string('"' . trim(implode('', $text)) . '"'), $context, $file, $line);
  }
}

/**
 * Look for a 'context' parameter in {% trans %} tags, that appear after the
 *   'with' keyword.
 */
function _potx_find_twig_trans_context($stream) {
  $token = $stream->next();
  if ($token->test(Twig_Token::PUNCTUATION_TYPE, '{')) {
    while (!$stream->isEOF() && ($token = $stream->next()) && !$token->test(Twig_Token::PUNCTUATION_TYPE, '}')) {
      if ($token->test(Twig_Token::STRING_TYPE, 'context')) {
        // Skip the ':' character.
        $stream->next();

        $token = $stream->next();
        if ($token->test(Twig_Token::STRING_TYPE)) {
          return $token->getValue();
        }
      }
    }
  }

  return POTX_CONTEXT_NONE;
}

/**
 * Detect all occurances of @Translation annotations in doc comments.
 *
 * @param $file
 *   Name of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 */
function _potx_find_translation_annotations($file, $save_callback) {
  global $_potx_tokens, $_potx_lookup;

  if (isset($_potx_lookup['T_DOC_COMMENT'])) {
    foreach ($_potx_lookup['T_DOC_COMMENT'] as $ti) {
      list($type, $string, $line) = $_potx_tokens[$ti];
      // Match for a possible empty string too, so we can signal that kind of
      // error in our standard way (from the save callback), instead of signaling
      // a generic error from here around syntax.
      preg_match_all('!=\s*@Translation\(\s*"([^"]*)"(\s*,\s*context\s*=\s*("[^"]+"))?\s*\)!', $string, $found);
      if (isset($found) && is_array($found) && count($found[1])) {

        foreach ($found[1] as $index => $match) {
          $context = empty($found[3][$index]) ? POTX_CONTEXT_NONE : trim($found[3][$index], '"');

          $save_callback(
            $match,
            $context,
            $file,
            $line
          );
          // Remove this annotation from the comment. This way if we have any
          // left after this foreach, we have bugos ones left and can use that
          // to signal an error.
          $string = str_replace($found[0][$index], '', $string);
        }
      }
      if (preg_match('!=\s*@Translation!', $string) === 1) {
        // @Translation annotations still exist, so we have ones that did not
        // match the expected pattern.
        _potx_marker_error($file, $line, "@Translation", $ti, t('In @Translation, only one, non-empty static string is allowed in double quotes.'), 'https://drupal.org/node/1882526');
      }
    }
  }
}

/**
 * Initialize the list of translation patterns for YAML files.
 *
 * The patterns are loaded from a file named "yaml_translation_patterns.yml" in
 * potx's root. Contrib projects can also include their own
 * "yaml_translation_patterns.yml" file in their root folder to specify
 * translatable strings in their own custom yaml files.
 *
 * @param string $path
 *   The path to look for a custom "yaml_translation_patterns.yml" file.
 */
function _potx_init_yaml_translation_patterns($path = '') {
  global $yaml_translation_patterns;

  if (!is_array($yaml_translation_patterns)) {
    $yaml_translation_patterns = array();
  }

  $default_patterns = drupal_get_path('module', 'potx') . '/yaml_translation_patterns.yml';
  _potx_load_yaml_translation_patterns($default_patterns);

  $custom_patterns = $path . '/yaml_translation_patterns.yml';
  if (!empty($path) && file_exists($custom_patterns)) {
    _potx_load_yaml_translation_patterns($custom_patterns);
  }
}

/**
 * Load the list of YAML translation patterns from a file.
 *
 * The file is expected to be in the following format:
 * @code
 *   # A list of file matching patterns (as expected by fnmatch()).
 *   *.test_format.yml:
 *     # A sequence of translatable keys in the matched YAML files.
 *     - test_label
 *     - test_label_2:
 *         # An optional key, used as context for the translatable string.
 *         context: label_2_context
 *     # To mark all top-level keys as translatable, use the '%top-level-key' string.
 *     - %top-level-key
 * @endcode
 *
 * @param string $path
 *   The path for the YAML translation patterns file.
 */
function _potx_load_yaml_translation_patterns($path) {
  global $yaml_translation_patterns;

  $content = Yaml::parse(file_get_contents($path));

  foreach ($content as $pattern => $list) {
    foreach ($list as $value) {
      if (is_array($value)) {
        foreach ($value as $key => $context) {
          $yaml_translation_patterns[$pattern]['keys'][] = $key;
          $yaml_translation_patterns[$pattern]['contexts'][$key] = $context['context'];
        }
      }
      else {
        $yaml_translation_patterns[$pattern]['keys'][] = $value;
      }
    }
  }
}

/**
 * Parse a YAML file for translatables. Drupal 8+.
 */
function _potx_parse_yaml_file($code, $file_name, $file_path, $save_callback) {
  global $yaml_translation_patterns;
  global $_potx_config_set;

  if (!isset($yaml_translation_patterns)) {
    _potx_init_yaml_translation_patterns();
  }

  foreach ($yaml_translation_patterns as $pattern => $trans_list) {
    if (fnmatch($pattern, $file_name) || fnmatch('*/' . $pattern, $file_name)) {
      $yaml = Yaml::parse($code);
      _potx_find_yaml_translatables($yaml, $trans_list, $file_name, $save_callback);
    }
  }

  if (preg_match('~config/schema/[^/]+\.yml$~', $file_name)) {
    $schema = Yaml::parse($code);
    foreach ($schema as $key => $element) {
      _potx_process_config_schema($key, $element);
    }
  }
  elseif (preg_match('~config/(install|optional)/[^/]+\.yml$~', $file_name)) {
    $_potx_config_set[] = $file_path;
  }
}

/**
 * Recursively look for translatable strings in a YAML file.
 *
 * @param array $yaml
 *   The parsed YAML data.
 * @param array $trans_list
 *   The list of translatable keys to look for, and (optionally) their contexts.
 */
function _potx_find_yaml_translatables($yaml, $trans_list, $file_name, $save_callback) {
  $extract_values = FALSE;
  if (in_array('%top-level-key', $trans_list['keys'], TRUE)) {
    $extract_values = TRUE;
    $trans_list['keys'] = array_diff($trans_list['keys'], array('%top-level-key'));
  }

  foreach ($yaml as $key => $value) {

    if (in_array($key, $trans_list['keys'], TRUE)) {
      if (isset($trans_list['contexts'][$key])) {
        $context_key = $trans_list['contexts'][$key];
        if (isset($yaml[$context_key])) {
          $context = $yaml[$context_key];
        }
        else {
          $context = POTX_CONTEXT_NONE;
        }
      }
      else {
        $context = POTX_CONTEXT_NONE;
      }

      if (is_array($value)) {
        foreach ($value as $item) {
          $save_callback(addcslashes($item, "\0..\37\\\""), $context, $file_name);
        }
      }
      else {
        $save_callback(addcslashes($value, "\0..\37\\\""), $context, $file_name);
      }
    }
    elseif (is_array($value)) {
      _potx_find_yaml_translatables($value, $trans_list, $file_name, $save_callback);
    }
    elseif ($extract_values) {
      $save_callback(addcslashes($value, "\0..\37\\\""), POTX_CONTEXT_NONE, $file_name);
    }
  }
}

/**
 * Recursively process config schema into a flat structure.
 *
 * This structure is used to extract translatable strings from shipped
 * configuration, and identifies every element by joining all of its parent keys
 * (including itself) separated by the '+' symbol. It stores the schema elements
 * in four sublists:
 *  'translatables': the list of elements that are translatable.
 *  'types': the list of elements that rely on other schema elements for their
 *    definition. generally, those with types other than "mapping".
 *  'mappings': the list of elements that have a defined "mapping" property.
 *  'contexts': the list of elements that have a defined context string, using
 *    the "translation context" property.
 *
 * Note that 'types' and 'mappings' lists are not exclusive, i.e. an element can
 * both have a 'type' definition and a separate 'mapping'.
 *
 * Here is an example config schema:
 * @code
 *   test_schema:
 *     type: mapping
 *     mapping:
 *       name:
 *         type: label
 *       content:
 *         type: text
 *         translation context: Test schema content
 *       test_filter:
 *         type: filter
 * @endcode
 *
 * And the resulting processed schema:
 * @code
 * Array
 * (
 *   [translatables] => Array
 *     (
 *       [0] => test_schema+name
 *       [1] => test_schema+content
 *     )
 *
 *   [types] => Array
 *     (
 *       [test_schema+test_filter] => filter
 *     )
 *
 *   [mappings] => Array
 *     (
 *       [0] => test_schema
 *     )
 *
 *   [contexts] => Array
 *     (
 *       [test_schema+content] => Test schema content
 *     )
 *
 * )
 * @endcode
 *
 * @param string $schema_prefix
 *   All parent keys (including the element's key) joined by '+' symbol, e.g.
 *   image.style.*+effects+sequence
 * @param array $schema_data
 *   The schema subtree belonging to the current element.
 */
function _potx_process_config_schema($schema_prefix, $schema_data) {
  global $_potx_processed_schema;

  if (!isset($_potx_processed_schema)) {
    // The initial values for 'translatables' allows a limited support for
    // extracting translatable strings from contrib projects, until
    // https://www.drupal.org/node/1933988 gets in.
    $_potx_processed_schema = array(
      'translatables' => array('label', 'text', 'date_format'),
      'types' => array(),
      'mappings' => array(),
      'contexts' => array('date_format' => 'PHP date format'),
    );
  }

  // Elements can opt out of translation with a 'translatable: false' key.
  if (isset($schema_data['translatable']) && $schema_data['translatable'] === FALSE) {
    return;
  }

  // Do not process elements without a type, since the locale module strictly
  // requires translatable elements to be of base type 'string', and also we
  // can't traverse an element without knowing its type.
  if (!isset($schema_data['type'])) {
    return;
  }

  $type = $schema_data['type'];

  if (isset($schema_data['mapping'])) {

    foreach ($schema_data['mapping'] as $key => $element_data) {
      $element_key = $schema_prefix . '+' . $key;
      _potx_process_config_schema($element_key, $element_data);
    }

    if ($type != 'mapping') {
      $_potx_processed_schema['types'][$schema_prefix] = $type;
    }

    $_potx_processed_schema['mappings'][] = $schema_prefix;
  }
  else {
    if ($type == 'sequence') {
      _potx_process_config_schema($schema_prefix . '+sequence', $schema_data['sequence'][0]);
      $_potx_processed_schema['types'][$schema_prefix] = 'sequence';
    }
    // If the element's type is in the "translatables" list, or it has a
    // 'translatable: true' key, then it is translatable.
    elseif (in_array($type, $_potx_processed_schema['translatables'])
            || (isset($schema_data['translatable'])
                && $schema_data['translatable'] === TRUE)) {
      $_potx_processed_schema['translatables'][] = $schema_prefix;

      // Elements can define a context string, or inherit the context from their
      // defined type.
      if (isset($schema_data['translation context'])) {
        $_potx_processed_schema['contexts'][$schema_prefix] = $schema_data['translation context'];
      }
      elseif (isset($_potx_processed_schema['contexts'][$type])) {
        $_potx_processed_schema['contexts'][$schema_prefix] = $_potx_processed_schema['contexts'][$type];
      }
    }
    else {
      $_potx_processed_schema['types'][$schema_prefix] = $type;
    }
  }
}

/**
 * Checks whether an element exists in the processed schema.
 *
 * @param string $type
 * @return boolean
 */
function _potx_element_has_schema($type) {
  global $_potx_processed_schema;

  // If an element doesn't exist in any of the extracted lists, it hasn't been
  // defined in schema. This is checked during processing shipped config.
  return in_array($type, $_potx_processed_schema['translatables'])
         || in_array($type, $_potx_processed_schema['mappings'])
         || isset($_potx_processed_schema['types'][$type]);
}

/**
 * Find the schema element matching with a specific type.
 *
 * Based on Drupal\Core\Config\TypedConfigManager::getFallbackName($name)
 *
 * @param string $name
 *   Configuration name or key.
 *
 * @return null|string
 *   The resolved schema name for the given configuration name or key. Returns
 *   null if there is no schema name to fallback to. For example,
 *   breakpoint.breakpoint.module.toolbar.narrow will check for definitions in
 *   the following order:
 *     breakpoint.breakpoint.module.toolbar.*
 *     breakpoint.breakpoint.module.*.*
 *     breakpoint.breakpoint.module.*
 *     breakpoint.breakpoint.*.*.*
 *     breakpoint.breakpoint.*
 *     breakpoint.*.*.*.*
 *     breakpoint.*
 *   Colons are also used, for example,
 *   block.settings.system_menu_block:footer will check for definitions in the
 *   following order:
 *     block.settings.system_menu_block:*
 *     block.settings.*:*
 *     block.settings.*
 *     block.*.*:*
 *     block.*
 */
function _potx_find_matching_schema($name) {
  global $_potx_processed_schema;

  if (_potx_element_has_schema($name)) {
    return $name;
  }

  // Check for definition of $name with filesystem marker.
  $replaced = preg_replace('/([^.:]+)([.:*]*)$/', '*\2', $name);
  if ($replaced != $name ) {
    if (_potx_element_has_schema($replaced)) {
      return $replaced;
    }
    else {
      // No definition for this level. Collapse multiple wildcards to a single
      // wildcard to see if there is a greedy match. For example,
      // breakpoint.breakpoint.*.* becomes
      // breakpoint.breakpoint.*
      $one_star = preg_replace('/\.([:.*]*)$/', '.*', $replaced);
      if ($one_star != $replaced && _potx_element_has_schema($one_star)) {
        return $one_star;
      }
      // Check for next level. For example, if breakpoint.breakpoint.* has
      // been checked and no match found then check breakpoint.*.*
      return _potx_find_matching_schema($replaced);
    }
  }
}

/**
 * Replaces variables in configuration name.
 *
 * The configuration name may contain one or more variables to be replaced,
 * enclosed in square brackets like '[name]' and will follow the replacement
 * rules defined by the _potx_replace_variable() function.
 *
 * Based on Drupal\Core\Config\TypedConfigManager::replaceName($name, $data)
 *
 * @param string $name
 *   Configuration name with variables in square brackets.
 * @param mixed $data
 *   Configuration data for the element.
 * @return string
 *   Configuration name with variables replaced.
 */
function _potx_config_replace_name($name, $config_data) {
  if (preg_match_all("/\[(.*)\]/U", $name, $matches)) {
    // Build our list of '[value]' => replacement.
    $replace = array();
    foreach (array_combine($matches[0], $matches[1]) as $key => $value) {
      $replace[$key] = _potx_replace_variable($value, $config_data);
    }

    return strtr($name, $replace);
  }
  else {
    return $name;
  }
}

/**
 * Replaces variable values in included names with configuration data.
 *
 * Variable values are nested configuration keys that will be replaced by
 * their value or some of these special strings:
 * - '%key', will be replaced by the element's key.
 * - '%parent', to reference the parent element.
 *
 * There may be nested configuration keys separated by dots or more complex
 * patterns like '%parent.name' which references the 'name' value of the
 * parent element.
 *
 * Example patterns:
 * - 'name.subkey', indicates a nested value of the current element.
 * - '%parent.name', will be replaced by the 'name' value of the parent.
 * - '%parent.%key', will be replaced by the parent element's key.
 *
 * Based on
 *  Drupal\Core\Config\TypedConfigManager::replaceVariable($value, $data).
 *
 * @param string $value
 *   Variable value to be replaced.
 * @param mixed $data
 *   Configuration data for the element.
 *
 * @return string
 *   The replaced value if a replacement found or the original value if not.
 */
function _potx_replace_variable($value, $data) {
  $parts = explode('.', $value);
  // Process each value part, one at a time.
  while ($name = array_shift($parts)) {
    if (!is_array($data) || !isset($data[$name])) {
      // Key not found, return original value
      return $value;
    }
    elseif (!$parts) {
      // If no more parts left, this is the final property.
      return (string)$data[$name];
    }
    else {
      $data = $data[$name];
    }
  }
}

/**
 * Parse shipped configuration for translatables. Drupal 8+
 *
 * @param string $save_callback
 * @param string $api_version
 */
function _potx_parse_shipped_configuration($save_callback = '_potx_save_string', $api_version = POTX_API_CURRENT) {
  global $_potx_config_set;
  foreach ($_potx_config_set as $config_path) {
    // Find the schema that matches the config file.
    $path_info = pathinfo($config_path);
    $config_name = $path_info['filename'];
    $schema = _potx_find_matching_schema($config_name);

    if ($schema == '') {
      // No schema was found matching this config.
      continue;
    }

    $config_code = file_get_contents($config_path);
    $parsed_config = Yaml::parse($config_code);
    unset($config_code);

    _potx_find_shipped_config_translatables($parsed_config, $schema, NULL, NULL, $config_path, $save_callback);
  }
}

/**
 * Recursively check elements in shipped configuration with the processed schema.
 *
 * To support complex cases of variable replacement, '%key' and '%parent'
 * indexes are defined for every element when available. 'key' and 'parent'
 * values are also passed through the function parameters, because $config might
 * be a scalar value, which would not accept an index. Parsing an element's
 * properties inherited from its 'type' are processed separately from the
 * properties defined through its 'mapping'.
 *
 * @param mixed $config
 *   The config element being processed.
 * @param string $schema_prefix
 *   All parent keys (including the element's key) joined by '+' symbol.
 * @param string $config_key
 *   The config element's key.
 * @param array $config_parent
 *   The config element's parent.
 */
function _potx_find_shipped_config_translatables($config, $schema_prefix, $config_key, $config_parent, $config_path, $save_callback) {
  global $_potx_processed_schema;

  if (in_array($schema_prefix, $_potx_processed_schema['translatables'])) {
    if (isset($_potx_processed_schema['contexts'][$schema_prefix])) {
      $context = $_potx_processed_schema['contexts'][$schema_prefix];
    }
    else {
      $context = POTX_CONTEXT_NONE;
    }

    $save_callback(addcslashes($config, "\0..\37\\\""), $context, $config_path);
  }
  else {
    // Resolve the config element's type in schema to a real type, replacing all
    // placeholders, and find the shipped config translatables based on that
    // type.
    if (isset($_potx_processed_schema['types'][$schema_prefix])) {
      $schema_type = $_potx_processed_schema['types'][$schema_prefix];

      if ($schema_type == 'sequence') {
        foreach ($config as $sequence_key => $sequence_item) {
          // '%key' and '%parent' keys are added to $config by potx. skip them.
          if ($sequence_key === '%parent' || $sequence_key === '%key') continue;

          if (is_array($sequence_item)) {
            $sequence_item['%key'] = $sequence_key;
            $sequence_type = _potx_config_replace_name($schema_prefix, $sequence_item);
          }
          else {
            $sequence_type = _potx_config_replace_name($schema_prefix, array('%key' => $sequence_key));
          }

          _potx_find_shipped_config_translatables($sequence_item, $sequence_type . '+sequence', $sequence_key, NULL, $config_path, $save_callback);
        }
      }
      else {
        if (is_array($config)) {
          $schema_type = _potx_config_replace_name($schema_type, $config);
        }
        else {
          $schema_type = _potx_config_replace_name($schema_type, array('%key' => $config_key, '%parent' => $config_parent));
        }

        $matching_schema = _potx_find_matching_schema($schema_type);
        _potx_find_shipped_config_translatables($config, $matching_schema, $config_key, $config_parent, $config_path, $save_callback);
      }
    }

    // Check the keys belonging to config element's schema's "mapping" key.
    if (in_array($schema_prefix, $_potx_processed_schema['mappings'])) {
      foreach ($config as $key => $element) {
        // '%key' and '%parent' keys are added to $config by potx. skip them.
        if ($key === '%parent' || $key === '%key' || empty($element)) {
          continue;
        }

        if (!_potx_element_has_schema($schema_prefix . '+' . $key)) {
          continue;
        }

        if (is_array($element)) {
          $element['%parent'] = $config;
          $element['%key'] = $key;
        }

        _potx_find_shipped_config_translatables($element, $schema_prefix . '+' . $key, $key, $config, $config_path, $save_callback);
      }
    }
  }
}

/**
 * Detect validation constraint messages. Drupal 8+
 *
 * This sequences is searched for:
 *   T_POTX_CONSTRAINT = T_CONSTANT_ENCAPSED_STRING
 *
 * note: T_POTX_CONSTRAINT is marked for T_VARIABLE tokens inside .php files
 *   with the "Constraint" suffix, where the token is "$message", or ends
 *   with "Message"
 *
 * @param $file_name
 *   Name of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 */
function _potx_find_constraint_messages($file_name, $save_callback) {
  global $_potx_tokens, $_potx_lookup;

  if (!isset($_potx_lookup['T_POTX_CONSTRAINT'])) {
    return;
  }

  foreach ($_potx_lookup['T_POTX_CONSTRAINT'] as $key => $ti) {

    if ($_potx_tokens[$ti + 1] == '=' && $_potx_tokens[$ti + 2][0] == T_CONSTANT_ENCAPSED_STRING) {
      $str = $_potx_tokens[$ti + 2][1];

      // Find plural versions if available.
      if (strpos($str, '|') !== FALSE) {
        $quo = substr($str, 0, 1);
        $break = strpos($str, '|');
        $singular = substr($str, 0, $break) . $quo;
        $plural = $quo . substr($str, $break + 1);
        $save_callback(
            _potx_format_quoted_string($singular) ."\0". _potx_format_quoted_string($plural),
            POTX_CONTEXT_NONE,
            $file_name,
            $_potx_tokens[$ti][2]
        );
      }
      else {
        $save_callback(_potx_format_quoted_string($str), POTX_CONTEXT_NONE, $file_name, $_potx_tokens[$ti][2]);
      }
    }
  }
}

/**
 * Process Twig inline templates inside PHP files. Drupal 8+
 *
 * The patterns searched for inline templates include:
 *   1. '#template' => T_CONSTANT_ENCAPSED_STRING
 *   2. ['#template'] = T_CONSTANT_ENCAPSED_STRING
 *
 * @param $file_name
 *   Name of file parsed.
 * @param $save_callback
 *   Callback function used to save strings.
 */
function _potx_process_inline_templates($file_name, $save_callback) {
  global $_potx_tokens, $_potx_lookup;

  if (!isset($_potx_lookup["'#template'"])) {
    return;
  }

  foreach ($_potx_lookup["'#template'"] as $key => $ti) {
    // check for pattern: '#template' => T_CONSTANT_ENCAPSED_STRING
    if ($_potx_tokens[$ti + 1][0] == T_DOUBLE_ARROW && $_potx_tokens[$ti + 2][0] == T_CONSTANT_ENCAPSED_STRING) {
      $str = $_potx_tokens[$ti + 2][1];
      _potx_parse_twig_file($str, $file_name . '::inline-template', $save_callback);
    }
    // check for pattern: ['#template'] = T_CONSTANT_ENCAPSED_STRING
    elseif ($_potx_tokens[$ti - 1] == '[' && $_potx_tokens[$ti + 1] == ']'
            && $_potx_tokens[$ti + 2] == '=' && $_potx_tokens[$ti + 3][0] == T_CONSTANT_ENCAPSED_STRING) {
      $str = $_potx_tokens[$ti + 3][1];
      _potx_parse_twig_file($str, $file_name . '::inline-template', $save_callback);
    }
  }
}

/**
 * Collect a list of file names relevant for extraction,
 * starting from the given path.
 *
 * @param $path
 *   Where to start searching for files recursively.
 *   Provide non-empty path values with a trailing slash.
 * @param $basename
 *   Allows the restriction of search to a specific basename
 *   (ie. to collect files for a specific module).
 * @param $api_version
 *   Drupal API version to work with.
 * @param $skip_self
 *   Skip potx related files. To be used when command line type of extraction
 *   is used and the potx files at in the webroot, and their strings should not
 *   end up in the generated template. Set to TRUE if skiping is needed.
 */
function _potx_explore_dir($path = '', $basename = '*', $api_version = POTX_API_CURRENT, $skip_self = FALSE) {
  // It would be so nice to just use GLOB_BRACE, but it is not available on all
  // operarting systems, so we are working around the missing functionality.
  $extensions = array('php', 'inc', 'module', 'engine', 'theme', 'install', 'info', 'profile');
  if ($api_version > POTX_API_5) {
    $extensions[] = 'js';
  }
  if ($api_version > POTX_API_7) {
    $extensions[] = 'twig';
    $extensions[] = 'yml';
    _potx_init_yaml_translation_patterns($path);
  }
  $files = array();
  foreach ($extensions as $extension) {
    $files_here = glob($path . $basename .'.'. $extension);
    if (is_array($files_here)) {
      $files = array_merge($files, $files_here);
    }
    if ($basename != '*') {
      // Basename was specific, so look for things like basename.admin.inc as well.
      // If the basnename was *, the above glob() already covered this case.
      $files_here = glob($path . $basename .'.*.'. $extension);
      if (is_array($files_here)) {
        $files = array_merge($files, $files_here);
      }
    }
  }

  // Grab subdirectories.
  $dirs = glob($path .'*', GLOB_ONLYDIR);
  if (is_array($dirs)) {
    foreach ($dirs as $dir) {
      if (!preg_match("!(^|.+/)(CVS|\.svn|\.git|tests|vendor)$!", $dir)) {
        $files = array_merge($files, _potx_explore_dir("$dir/", $basename, $api_version, $skip_self));
      }
    }
  }

  // Skip API and test files. Also skip our own files, if that was requested.
  $skip_pattern = ($skip_self ? '!(potx-cli\.php|potx\.inc|\.api\.php|\.test)$!' : '!(\.api\.php|\.test)$!');
  foreach ($files as $id => $file_name) {
    if (preg_match($skip_pattern, $file_name)) {
      unset($files[$id]);
    }
  }
  return $files;
}

/**
 * Default $version_callback used by the potx system. Saves values
 * to a global array to reduce memory consumption problems when
 * passing around big chunks of values.
 *
 * @param $value
 *   The ersion number value of $file. If NULL, the collected
 *   values are returned.
 * @param $file
 *   Name of file where the version information was found.
 */
function _potx_save_version($value = NULL, $file = NULL) {
  global $_potx_versions;

  if (isset($value)) {
    $_potx_versions[$file] = $value;
  }
  else {
    return $_potx_versions;
  }
}

/**
 * Default $save_callback used by the potx system. Saves values
 * to global arrays to reduce memory consumption problems when
 * passing around big chunks of values.
 *
 * @param $value
 *   The string value. If NULL, the array of collected values
 *   are returned for the given $string_mode.
 * @param $context
 *   From Drupal 7, separate contexts are supported. POTX_CONTEXT_NONE is
 *   the default, if the code does not specify a context otherwise.
 * @param $file
 *   Name of file where the string was found.
 * @param $line
 *   Line number where the string was found.
 * @param $string_mode
 *   String mode: POTX_STRING_INSTALLER, POTX_STRING_RUNTIME
 *   or POTX_STRING_BOTH.
 */
function _potx_save_string($value = NULL, $context = NULL, $file = NULL, $line = 0, $string_mode = POTX_STRING_RUNTIME) {
  global $_potx_strings, $_potx_install;

  if (isset($value)) {

    // Value set but empty. Mark error on empty translatable string. Only trim
    // for empty string checking, since we should store leading/trailing
    // whitespace as it appears in the string otherwise.
    $check_empty = trim($value);
    if (empty($check_empty)) {
      potx_status('error', t('Empty string attempted to be localized. Please do not leave test code for localization in your source.'), $file, $line);
      return;
    }

    switch ($string_mode) {
      case POTX_STRING_BOTH:
        // Mark installer strings as duplicates of runtime strings if
        // the string was both recorded in the runtime and in the installer.
        $_potx_install[$value][$context][$file][] = $line .' (dup)';
        // Break intentionally missing.
      case POTX_STRING_RUNTIME:
        // Mark runtime strings as duplicates of installer strings if
        // the string was both recorded in the runtime and in the installer.
        $_potx_strings[$value][$context][$file][] = $line . ($string_mode == POTX_STRING_BOTH ? ' (dup)' : '');
        break;
      case POTX_STRING_INSTALLER:
        $_potx_install[$value][$context][$file][] = $line;
        break;
    }
  }
  else {
    return ($string_mode == POTX_STRING_RUNTIME ? $_potx_strings : $_potx_install);
  }
}

if (!function_exists('t')) {
  // If invoked outside of Drupal, t() will not exist, but
  // used to format the error message, so we provide a replacement.
  function t($string, $args = array()) {
    return strtr($string, $args);
  }
}

if (!function_exists('drupal_parse_info_file')) {
  // If invoked outside of Drupal, drupal_parse_info_file() will not be available,
  // but we need this function to properly parse Drupal 6/7 .info files.
  // Directly copied from common.inc,v 1.756.2.76 2010/02/01 16:01:41 goba Exp.
  function drupal_parse_info_file($filename) {
    $info = array();
    $constants = get_defined_constants();

    if (!file_exists($filename)) {
      return $info;
    }

    $data = file_get_contents($filename);
    if (preg_match_all('
      @^\s*                           # Start at the beginning of a line, ignoring leading whitespace
      ((?:
        [^=;\[\]]|                    # Key names cannot contain equal signs, semi-colons or square brackets,
        \[[^\[\]]*\]                  # unless they are balanced and not nested
      )+?)
      \s*=\s*                         # Key/value pairs are separated by equal signs (ignoring white-space)
      (?:
        ("(?:[^"]|(?<=\\\\)")*")|     # Double-quoted string, which may contain slash-escaped quotes/slashes
        (\'(?:[^\']|(?<=\\\\)\')*\')| # Single-quoted string, which may contain slash-escaped quotes/slashes
        ([^\r\n]*?)                   # Non-quoted string
      )\s*$                           # Stop at the next end of a line, ignoring trailing whitespace
      @msx', $data, $matches, PREG_SET_ORDER)) {
      foreach ($matches as $match) {
        // Fetch the key and value string
        $i = 0;
        foreach (array('key', 'value1', 'value2', 'value3') as $var) {
          $$var = isset($match[++$i]) ? $match[$i] : '';
        }
        $value = stripslashes(substr($value1, 1, -1)) . stripslashes(substr($value2, 1, -1)) . $value3;

        // Parse array syntax
        $keys = preg_split('/\]?\[/', rtrim($key, ']'));
        $last = array_pop($keys);
        $parent = &$info;

        // Create nested arrays
        foreach ($keys as $key) {
          if ($key == '') {
            $key = count($parent);
          }
          if (!isset($parent[$key]) || !is_array($parent[$key])) {
            $parent[$key] = array();
          }
          $parent = &$parent[$key];
        }

        // Handle PHP constants.
        if (isset($constants[$value])) {
          $value = $constants[$value];
        }

        // Insert actual value
        if ($last == '') {
          $last = count($parent);
        }
        $parent[$last] = $value;
      }
    }

    return $info;
  }
}
