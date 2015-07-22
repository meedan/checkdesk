<?php
/**
 * @file
 * Views filter to display in a 'Content revisions' view only
 * published revisions. Does not work in a standard 'Content' view.
 */

class revisioning_handler_filter_revision_latest extends views_handler_filter_boolean_operator {

  /**
   * Call constructor.
   */
  public function construct() {
    parent::construct();
    $this->value_value = t('Revisions');
  }

  /**
   * Check for access.
   */
  public function access() {
    return user_access('access content');
  }

  /**
   * Is this filter exposible.
   */
  public function can_expose() {
    return TRUE;
  }

  /**
   * Exposed form elements.
   */
  public function expose_form(&$form, &$form_state) {
    $form['expose']['required'] = array(
      '#type' => 'value',
      '#value' => FALSE,
    );
  }

  /**
   * Get the value options.
   */
  public function get_value_options() {
    $this->value_options = array(1 => t('Latest only'));
  }

  /**
   * Override the query, in particular the WHERE clause.
   */
  public function query() {
    $revisions_table = $this->ensure_my_table();
    $node_table = $this->query->ensure_table('node');
    // If we are using a relationship we need to try again because the alias
    // is not going to be node!
    if (!$node_table) {
      $node_table = $this->query->ensure_table('node_' . $revisions_table);
    }
    if (!$node_table) {
      // Final desperate guess ...
      $node_table = 'node';
    }

    // The subquery selects the maximum revision ID (vid) for a given node ID
    // (nid). This is guaranteed to be the latest revision, because vids are
    // assigned chronologically.
    $max_vid_subquery = "SELECT MAX(vid) FROM $revisions_table WHERE $revisions_table.nid = $node_table.nid";

    $where_clause = "$revisions_table.vid = ($max_vid_subquery)";
    $this->query->add_where_expression($this->options['group'], $where_clause);
  }
}
