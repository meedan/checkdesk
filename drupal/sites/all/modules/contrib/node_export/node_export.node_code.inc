<?php

/**
 * @file
 * The Node export node code file.
 *
 * Handles the default code format.
 */


/**
 * Implements hook_node_export_format_handlers().
 *
 * @see hook_node_export_format_handlers()
 */
function node_export_node_export_format_handlers() {
  return array(
    'node_code' => array(
      '#title' => t('Node code'),
      '#module' => 'node_export',
      '#description' => t(
        'PHP parsable export code, which is a custom version of <a href="!php">var_export</a>.',
        array(
          '!php' => 'http://www.php.net/manual/en/function.var-export.php', 
        )
      ),
    ),
  );
}

/**
 * Implements hook_node_export().
 *
 * @see hook_node_export()
 */
function node_export_node_export($nodes, $format) {
  $node_codes = array();
  foreach ($nodes as $node) {
    $node_codes[] = node_export_node_code_encode($node);
  }
  return "array(\n  " . implode(",\n    ", $node_codes) . ",\n)";
}

/**
 * Implements hook_node_export_import().
 *
 * @see hook_node_export_import()
 */
function node_export_node_export_import($code_string) {
  // Check for "array(" at the start.
  if (substr(ltrim($code_string), 0, 6) == "array(") {
    // Default node decoding.
    $array = eval('return ' . $code_string . ';');
    // Ensure array has a value before doing anything else.
    if ($array) {
      // Handle importing of objects.
      $return = node_export_node_code_decode_objects($array);
      // If there is just one object in $return, make it an array.
      if (is_object($return)) {
        $return = array($return);
      }
      // Ensure we have an array before returning.
      if (is_array($return)) {
        return $return;
      }
    }
  }
}

/**
 * Build node code string recursively.
 */
function node_export_node_code_encode($var, $iteration = 0) {
  // Default node encoding.
  $tab = '';
  for ($i = 0; $i <= $iteration; $i++) {
    $tab = $tab . "  ";
  }
  $iteration++;
  if (is_object($var)) {
    $var = (array)$var;
    $var['#_export_node_encode_object'] = '1';
  }
  if (is_array($var)) {
    $empty = empty($var);
    $code = "array(" . ($empty ? '' : "\n");
    foreach ($var as $key => $value) {
      $out = $tab . "  '" . $key . "' => " . node_export_node_code_encode($value, $iteration) . ",\n";
      drupal_alter('node_export_node_code_encode_line', $out, $tab, $key, $value, $iteration);
      $code .= $out;
    }
    $code .= ($empty ? '' : $tab) . ")";
    return $code;
  }
  else {
    if (is_string($var)) {
      // Escape single quotes so we don't accidentally exit the string.
      return "'" . strtr($var, array("'" => "\\'")) . "'";
    }
    elseif (is_numeric($var)) {
      return $var;
    }
    elseif (is_bool($var)) {
      return ($var ? 'TRUE' : 'FALSE');
    }
    else {
      return 'NULL';
    }
  }
}

/**
 * Recursively convert arrays back to objects.
 */
function node_export_node_code_decode_objects($array) {
  foreach ($array as $k => $v) {
    if (is_array($v)) {
      $array[$k] = node_export_node_code_decode_objects($v);
    }
  }
  if (isset($array['#_export_node_encode_object'])) {
    unset($array['#_export_node_encode_object']);
    $array = (object)$array;
  }
  return $array;
}