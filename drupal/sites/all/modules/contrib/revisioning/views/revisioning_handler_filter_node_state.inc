<?php

/**
 * @file
 * Views filter override to filter on node state, i.e. pending, archived or
 * current.
 */

class revisioning_handler_filter_node_state extends views_handler_filter_in_operator {

  /**
   * Override the query, in particular the WHERE clause.
   */
  public function query() {
    if (empty($this->value)) {
      return;
    }
    $node_table = $this->ensure_my_table();
    $revisions_table = '{' . $this->query->ensure_table('node_revision') . '}';
    $subclauses = array();
    foreach ($this->value as $state_code) {
      switch ($state_code) {

        case REVISION_ARCHIVED:
          // A node is considered archived when it's unpublished and has 2 or
          // more revisions. An unpublished node with 1 revision is considered
          // pending.
          $subclauses[] = "($node_table.status=0 AND (SELECT COUNT(vid) FROM $revisions_table WHERE nid=$node_table.nid)>1)";
          break;

        case REVISION_CURRENT:
          // A node is considered up-to-date when it's published and its
          // current revision is the latest revision (highest vid).
          $subclauses[] = "($node_table.status=1 AND $node_table.vid=(SELECT MAX(vid) FROM $revisions_table WHERE nid=$node_table.nid))";
          break;

        case REVISION_PENDING:
          // A node is pending when it's published with a current revision
          // that's not the latest or when the node has a single, yet to be
          // published revision.
          $subclauses[] = "(($node_table.status=1 AND $node_table.vid<(SELECT MAX(vid) FROM $revisions_table WHERE nid=$node_table.nid)) OR ($node_table.status=0 AND (SELECT COUNT(vid) FROM $revisions_table WHERE nid=$node_table.nid)=1))";
          break;
      }
    }
    if (!empty($subclauses)) {
      $where_expression = implode(' OR ', $subclauses);
      if ($this->operator == 'not in') {
        $where_expression = "not ($where_expression)";
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
