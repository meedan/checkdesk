<?php

/**
 * @file
 * Views filter override to filter on the number of revisions a node has.
 */

class revisioning_handler_filter_node_number_of_revisions extends views_handler_filter_numeric {

  /**
   * Override the query, in particular the WHERE clause.
   */
  public function query() {
    if (empty($this->value)) {
      return;
    }

    $info = $this->operators();
    $operator_symbol = drupal_strtoupper($info[$this->operator]['short']);
    if (!empty($operator_symbol)) {
      $node_table = $this->ensure_my_table();
      $revisions_table = $this->query->ensure_table('node_revision');
      $pseudo_field = "(SELECT COUNT(vid) FROM {$revisions_table} WHERE nid=$node_table.nid)";
      // Can't use add_where() as it sanitises (destroys) the $where_expression
      // Have to use add_where_expression() and copy what add_where() does.
      if ($operator_symbol == 'BETWEEN' || $operator_symbol == 'NOT BETWEEN') {
        $where_expression = "$pseudo_field $operator_symbol '" . $this->value['min'] . "' AND '" . $this->value['max'] . "'";
      }
      else {
        $where_expression = "$pseudo_field $operator_symbol " . $this->value['value'];
      }
      $this->query->add_where_expression($this->options['group'], $where_expression);
    }
  }
}
