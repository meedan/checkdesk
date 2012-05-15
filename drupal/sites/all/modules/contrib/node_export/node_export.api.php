<?php

/**
 * @file
 * Documents Node export's hooks for api reference.
 */

/**
 * Override export access on a node.
 *
 * Let other modules alter this - for example to only allow some users to
 * export specific nodes or types.
 *
 * @param &$access
 *   Boolean access value for current user.
 * @param $node
 *   The node to determine access for.
 */
function hook_node_export_access_export_alter(&$access, $node) {
  // no example code
}

/**
 * Override import access on a node.
 *
 * Let other modules alter this - for example to only allow some users to
 * import specific nodes or types.
 *
 * @param &$access
 *   Boolean access value for current user.
 * @param $node
 *   The node to determine access for.
 */
function hook_node_export_access_import_alter(&$access, $node) {
  // no example code
}

/**
 * Override one line of the export code output.
 *
 * @param &$out
 *   The line of output.
 * @param $tab
 *   The $tab variable from node_export_node_encode().
 * @param $key
 *   The $key variable from node_export_node_encode().
 * @param $value
 *   The $value variable from node_export_node_encode().
 * @param $iteration
 *   The $iteration variable from node_export_node_encode().
 */
function hook_node_export_node_encode_line_alter(&$out, $tab, $key, $value, $iteration) {
  // Start with something like this, and work on it:
  $out = $tab . "  '" . $key . "' => " . node_export_node_encode($value, $iteration) . ",\n";
}

/**
 * Manipulate a node on export.
 *
 * @param &$node
 *   The node to alter.
 * @param $original_node
 *   The unaltered node.
 */
function hook_node_export_node_alter(&$node, $original_node) {
  // no example code
}

/**
 * Manipulate a node on import.
 *
 * @param &$node
 *   The node to alter.
 * @param $original_node
 *   The unaltered node.
 * @param $save
 *   Whether the node will be saved by node_export_import().
 */
function hook_node_export_node_import_alter(&$node, $original_node, $save) {
  // no example code
}

/**
 * Manipulate node array before export.
 *
 * The purpose of this is to allow a module to check nodes in the array for
 * two or more nodes that must retain a relationship, and to add/remove other
 * data to the array to assist with maintaining dependencies, relationships,
 * references, and additional data required by the nodes.
 *
 * @param &$nodes
 *   The array of nodes to alter.
 * @param $format
 *   The format of node code being used.
 */
function hook_node_export_alter(&$nodes, $format) {
  // no example code
}

/**
 * Manipulate node array before import.
 *
 * The purpose of this is to allow a module to check nodes in the array for
 * two or more nodes that must retain a relationship, and to add/remove other
 * data to the array to assist with maintaining dependencies, relationships,
 * references, and additional data required by the nodes.
 *
 * @param &$nodes
 *   The array of nodes to alter.
 * @param $format
 *   The format of node code being used.
 * @param $save
 *   Whether the nodes will be saved by node_export_import().
 */
function hook_node_export_import_alter(&$nodes, $format, $save) {
  // no example code
}

/**
 * Manipulate node array after import.
 *
 * The purpose of this is to allow a module to check nodes in the array for
 * two or more nodes that must retain a relationship, and to add/remove other
 * data to the array to assist with maintaining dependencies, relationships,
 * references, and additional data required by the nodes.
 *
 * @param &$nodes
 *   The array of nodes to alter - IMPORTANT: keyed by node id.
 * @param $format
 *   The format of node code being used.
 * @param $save
 *   Whether the nodes were saved by node_export_import().
 */
function hook_node_export_after_import_alter(&$nodes, $format, $save) {
  // no example code
}

/**
 * Manipulate the code string before import.
 *
 * @param &$code_string
 *   The export code.
 */
function hook_node_export_decode_alter(&$code_string) {
  // no example code
}

/**
 * Manipulate the code string upon export.
 *
 * @param &$code_string
 *   The Node export code.  Leave as FALSE for no change.
 * @param $nodes
 *   The node.
 * @param $format
 *   A string indicating what the export format is, and whether to do anything.
 */
function hook_node_export_encode_alter(&$code_string, $nodes, $format) {
  // no example code
}

/**
 * Register a format handler, for exporting code using other methods.
 *
 * @return
 *   An array keyed by format names containing an array with keys #title and
 *   #module, where the value for #title is the display name of the format, and
 *   the value for #module is the module that implements it.
 */
function hook_node_export_format_handlers() {
  return array(
    // Note: format_short_name must NOT contain the string 'node_export'.
    'format_short_name' => array(
      '#title' => t('Format Title'),
      '#module' => 'format_module_name',
    ),
  );
}

/**
 * Create the output code for nodes.
 *
 * Called from the module with the currently used export format.
 *
 * @param $nodes
 *   An array of nodes to export.
 * @param $format
 *   The format to use for export.  Check this if module does multiple formats.
 * @return
 *   The code string.
 */
function hook_node_export($nodes, $format) {
  // no example code
}

/**
 * Handle importing of a node.
 *
 * Called on all format handler modules until one returns something useful.
 *
 * @param $code_string
 * @return
 *   The array of nodes, or nothing if code_string not handled by this
 *   function.
 *   If there is a problem with the supplied code return an array like so:
 *   array(
 *     'success' => FALSE,
 *     'output' => array("error msg 1", "error msg 2", etc...),
 *   )
 *   Note: Do not use the t() function on error msgs, and don't mix the error
 *   message with dynamic variables/content, at least not in the first message
 *   so it can be translated properly and used as the main message.  See the
 *   XML implementation for malformed XML imports for an example that combines
 *   information for the user followed by generated errors from PHP.
 */
function hook_node_export_import($code_string) {
  // no example code
}