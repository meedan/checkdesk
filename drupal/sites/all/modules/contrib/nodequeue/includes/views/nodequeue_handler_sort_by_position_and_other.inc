<?php

/**
 * @file
 * Views handler for sorting nodes by position in nodequeue and some other
 * parameter.
 */

/**
 * Allows combining the nodequeue position with another (random) parameter
 * (created date for example). This handler is useful only if the nodequeue
 * relationship is NOT required.
 */
class nodequeue_handler_sort_by_position_and_other extends views_handler_sort {

  function query() {
    $table = $this->ensure_my_table();

    $field = 'position';
    $as = $table . '_' . $field;

    if ($field) {
      $this->query->add_field($table, $field, $as);
    }

    // If we sort ASC items with NULL should be last, so set 99999999,
    // if DESC set 0.
    $order = strtoupper($this->options['order']);
    $stub = ($order == 'DESC') ? '0' : '999999999';

    // Use COALESCE instead of IFNULL, and avoid using the field alias to support MS SQL Server.
    $this->query->orderby[] = array('field' => "COALESCE($table.$field, $stub) ", 'direction' => $order);
  }
}
