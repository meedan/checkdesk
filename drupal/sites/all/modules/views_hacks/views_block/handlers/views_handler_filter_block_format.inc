<?php

/**
 * Filter based on block body format.
 */
class views_handler_filter_block_format extends views_handler_filter_in_operator {
  function get_value_options() {
    foreach (filter_formats() as $fid => $format) {
      $this->value_options[$fid] = $format->name;
    }
  }
}

