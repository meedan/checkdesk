<?php

/**
 * Implements hook_drush_command().
 */
function utf8mb4_converter_drush_command() {
  $items['utf8mb4-convert'] = array(
    'description' => dt('Convert tables to utf8mb4.'),
  );
  return $items;
}

function drush_utf8mb4_converter_utf8mb4_convert() {
  foreach (db_query("show tables")->fetchCol() as $table) {
    $table_ok = TRUE;
    try {
      utf8mb4_converter_fix_table($table);
    } catch(Exception $e) {
      $table_ok = FALSE;
      drush_log($table . ': ' . $e->getMessage(), 'warning');
      watchdog_exception('utf8mb4_converter', $e);
    }
    $schema = utf8mb4_converter_get_column_iterator($table);
    foreach ($schema as $column_name => $column_def){
      try {
        $results[] = utf8mb4_converter_fix_column($column_def, $table);
      } catch(Exception $e) {
        $table_ok = FALSE;
        drush_log($table . ': ' . $e->getMessage(), 'warning');
        watchdog_exception('utf8mb4_converter', $e);
      }
    }
    if ($table_ok) {
      drush_log($table, 'ok');
    }
  }
}
