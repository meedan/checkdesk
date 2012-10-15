<?php

/**
 * @file
 * Definition of views_handler_filter_string.
 */

/**
 * Basic textfield filter to handle string filtering commands
 * including equality, like, not like, etc.
 *
 * @ingroup views_filter_handlers
 */
class meedan_source_filter_handler extends views_handler_filter_string {
  // exposed filter options
  var $always_multiple = TRUE;

  function option_definition() {
    $options = parent::option_definition();

    $options['expose']['contains']['required'] = array('default' => FALSE, 'bool' => TRUE);

    return $options;
  }


  function op_not($field) {
    $field_parent = $this->table_alias. ".ms_id";
    $ms_ids = $this->_get_source_ms_id(db_like($this->value));
    $this->query->add_where(
      $this->options['group'], 
      db_and()
      ->condition($field, '%' . db_like($this->value) . '%', 'NOT LIKE')
      ->condition($field_parent, $ms_ids, 'NOT IN')
    );
  }

  function op_word($field) {
    $where = $this->operator == 'word' ? db_or() : db_and();

    // Don't filter on empty strings.
    if (empty($this->value)) {
      return;
    }

    preg_match_all('/ (-?)("[^"]+"|[^" ]+)/i', ' ' . $this->value, $matches, PREG_SET_ORDER);
    foreach ($matches as $match) {
      $phrase = false;
      // Strip off phrase quotes
      if ($match[2]{0} == '"') {
        $match[2] = substr($match[2], 1, -1);
        $phrase = true;
      }
      $words = trim($match[2], ',?!();:-');
      $words = $phrase ? array($words) : preg_split('/ /', $words, -1, PREG_SPLIT_NO_EMPTY);
      foreach ($words as $word) {
        $placeholder = $this->placeholder();
        $where->condition($field, '%' . db_like(trim($word, " ,!?")) . '%', 'LIKE');
      }
    }

    if (!$where) {
      return;
    }

    $field_parent = $this->table_alias. ".ms_id";
    $ms_ids = $this->_get_source_ms_id(db_like(trim($word, " ,!?")));
    $where->condition($field_parent, $ms_ids, 'IN');
    // previously this was a call_user_func_array but that's unnecessary
    // as views will unpack an array that is a single arg.
    $this->query->add_where($this->options['group'], $where);
  }

  function _get_source_ms_id($source) {
    $query = db_select('meedan_sources', 'ms');
    $query->innerJoin('meedan_sources', 'ms_tmp', 'ms.ms_id = ms_tmp.parent');
    $query->condition('ms.source', '%'. $source .'%', 'LIKE');
    $query->fields('ms_tmp', array('ms_id'));
    $ms_ids = $query->execute()->fetchCol();
    return $ms_ids;
  }

}
