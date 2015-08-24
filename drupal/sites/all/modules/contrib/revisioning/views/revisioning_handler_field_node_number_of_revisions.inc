<?php

/**
 * @file
 * Handler for the 'Node: number of revisions' field.
 */

class revisioning_handler_field_node_number_of_revisions extends views_handler_field {

  /**
   * Call constructor.
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  /**
   * Check access.
   */
  public function access() {
    return user_access('access content');
  }

  /**
   * Help build the query.
   */
  public function query() {
    // Not calling parent::query() as it will treat 'number of revisions' as
    // a real db field.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render data.
   */
  public function render($values) {
    $nid = $values->{$this->aliases['nid']};
    return revisioning_get_number_of_revisions($nid);
  }
}
