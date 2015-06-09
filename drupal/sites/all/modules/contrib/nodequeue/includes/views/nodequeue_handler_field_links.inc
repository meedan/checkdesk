<?php

/**
 * @file
 * Views field handler for the nodequeue queue links
 */
class nodequeue_handler_field_links extends views_handler_field_node_link {
  function render($values) {
    if ((user_access('manipulate queues') || user_access('manipulate all queues')) && $node = $this->get_value($values)) {
      return theme('links', array('links' => nodequeue_node_links($node)));
    }
  }
}
