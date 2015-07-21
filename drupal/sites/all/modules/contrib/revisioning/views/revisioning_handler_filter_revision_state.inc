<?php
/**
 * @file
 * revisioning_handler_filter_revision_state.inc
 * 
 * Views filter override to filter on revision state, i.e. pending, archived or
 * current.
 */

class revisioning_handler_filter_revision_state extends views_handler_filter_in_operator {

  /**
   * Override the query, in particular the WHERE clause.
   */
  public function query() {
    if (empty($this->value)) {
      return;
    }
    $revisions_table = $this->ensure_my_table();
    $node_table = $this->query->ensure_table('node', $this->relationship);
    if (!$node_table) {
      $node_table = $this->query->ensure_table('node');
      // If we are using a relationship we need to try again because the alias
      // is not going to be node!
      if (!$node_table) {
        $node_table = $this->query->ensure_table('node_' . $revisions_table);
      }
      if (!$node_table) {
        // Final desperate guess ...
        $node_table = 'node';
      }
    }

    $subclauses = array();
    foreach ($this->value as $state_code) {
      switch ($state_code) {

        case REVISION_ARCHIVED:
          $subclauses[] = "($revisions_table.vid<$node_table.vid)";
          break;

        case REVISION_CURRENT:
          $subclauses[] = "($revisions_table.vid=$node_table.vid AND $node_table.status=1)";
          break;

        case REVISION_PENDING:
          $subclauses[] = "($revisions_table.vid>$node_table.vid OR ($node_table.status=0 AND (SELECT COUNT(vid) FROM {" . $revisions_table . "} WHERE nid=$node_table.nid)=1))";
          // Only add this join if there is not already a 'Revision NID of the
          // content revision' contextual filter relationship.
          if (empty($this->query->relationships[$this->relationship])) {
            // Make sure UNIQUE is set!
            $this->query->table_queue[$revisions_table]['join'] = new views_join();
            $this->query->table_queue[$revisions_table]['join']->construct($node_table, $revisions_table, 'nid', 'nid');
          }
          break;
      }
    }
    if (!empty($subclauses)) {
      $where_expression = implode(' OR ', $subclauses);
      if ($this->operator == 'not in') {
        $where_expression = '!' . $where_expression;
      }
      $this->query->add_where_expression($this->options['group'], $where_expression);
    }
  }

  /**
   * Get value options.
   */
  public function get_value_options() {
    $this->value_title = t('Revision state');
    $this->value_options = revisioning_revision_states();
  }
}
