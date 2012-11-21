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
    if (count($ms_ids)) {
    $this->query->add_where(
      $this->options['group'], 
      db_and()
      ->condition($field, '%' . db_like($this->value) . '%', 'NOT LIKE')
      ->condition($field_parent, $ms_ids, 'NOT IN')
    );
    }
    else {
      parent::op_not($field);
    }
  }

  function op_contains($field) {
    $field_parent = $this->table_alias. ".ms_id";
    $ms_ids = $this->_get_source_ms_id(db_like($this->value));
    if (count($ms_ids)) {
      $this->query->add_where(
        $this->options['group'], 
        db_or()
        ->condition($field, '%' . db_like($this->value) . '%', 'LIKE')
        ->condition($field_parent, $ms_ids, 'IN')
      );
    }
    else {
      parent::op_contains($field);
    }

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
