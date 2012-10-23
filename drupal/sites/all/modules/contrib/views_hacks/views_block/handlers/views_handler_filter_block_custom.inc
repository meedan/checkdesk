<?php

/**
 * Filter based on block custom visibility.
 */
class views_handler_filter_block_custom extends views_handler_filter_in_operator {
  function get_value_options() {
    $this->value_options = array(
      t('Show always'),
      t('Show by default'),
      t('Hide by default')
    );
  }
}

