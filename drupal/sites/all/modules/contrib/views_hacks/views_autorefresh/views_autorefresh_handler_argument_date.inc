<?php

class views_autorefresh_handler_argument_date extends views_handler_argument {
  /**
   * Construct the instance
   */
  function construct() {
    parent::construct();
    $this->format = 'r';
    $this->operator = '>';
  }

  /**
   * Provide a link to the next level of the view
   */
  function summary_name($data) {
    $created = $data->{$this->name_alias};
    return format_date(strtotime($created), 'custom', $this->format, 0);
  }

  /**
   * Provide a link to the next level of the view
   */
  function title() {
    return format_date(strtotime($this->argument), 'custom', $this->format, 0);
  }

  /**
   * Build the query based upon the formula
   */
  function query() {
    $this->ensure_my_table();
    $this->query->add_where_expression(0, "{$this->table_alias}.{$this->real_field} {$this->operator} :date", array(':date' => $this->argument));
  }
}

