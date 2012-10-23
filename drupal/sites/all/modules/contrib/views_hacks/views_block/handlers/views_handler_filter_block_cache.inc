<?php

/**
 * Filter based on block cache settings.
 */
class views_handler_filter_block_cache extends views_handler_filter {
  var $no_single = TRUE;

  function admin_summary() {
    if (!empty($this->options['exposed'])) {
      return t('exposed');
    }
    return parent::admin_summary();
  }

  function value_form(&$form, &$form_state) {
    $options = array(
      BLOCK_NO_CACHE => 'BLOCK_NO_CACHE',
      BLOCK_CACHE_PER_ROLE => 'BLOCK_CACHE_PER_ROLE',
      BLOCK_CACHE_PER_USER => 'BLOCK_CACHE_PER_USER',
      BLOCK_CACHE_PER_PAGE => 'BLOCK_CACHE_PER_PAGE',
      BLOCK_CACHE_GLOBAL => 'BLOCK_CACHE_GLOBAL',
    );
    $form['value'] = array(
      '#type' => 'checkboxes',
      '#options' => $options,
    );
  }

  function query() {
    $this->ensure_my_table();
    if (in_array(BLOCK_NO_CACHE, $this->value)) {
      $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field = %d", BLOCK_NO_CACHE);
    }
    else {
      $val = 0;
      if (!empty($this->value)) foreach ($this->value as $bit) {
        $val |= $bit;
      }
      $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field & %d = %d", $val, $val);
      $this->query->add_where($this->options['group'], "$this->table_alias.$this->real_field != %d", BLOCK_NO_CACHE);
    }
  }
}

