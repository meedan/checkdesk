<?php

/**
 * @file
 * Handler to sort the nodes that are in a nodequeue from the ones that are not.
 */

/**
 * Sort the view by a boolean, is this is a nodequeue node or not.
 */
class nodequeue_handler_sort_in_queue extends views_handler_sort {

  function query() {
    $this->ensure_my_table();
    $this->query->add_orderby(NULL, "($this->table_alias.nid IS NULL)", $this->options['order']);
  }
}
