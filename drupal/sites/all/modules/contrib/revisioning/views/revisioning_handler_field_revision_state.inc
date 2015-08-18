<?php

/**
 * @file
 * Handler for the 'Node revision: state' field.
 */

class revisioning_handler_field_revision_state extends views_handler_field {

  protected $_node_based = FALSE;

  /**
   * Constructor.
   */
  public function construct() {
    parent::construct();
    // Collect additional data required prior to rendering.
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['vid'] = 'vid';
  }

  /**
   * Check for access.
   */
  public function access() {
    return user_access('view revisions');
  }

  /**
   * Modify the query before it's executed.
   */
  public function pre_query() {
    $this->_node_based = $this->view->base_table == 'node' || (!empty($this->options['relationship']) && $this->options['relationship'] !== 'none');

    if ($this->_node_based) {
      $this->additional_fields['published'] = array('table' => 'node', 'field' => 'status');
      $this->additional_fields['current_vid'] = array('table' => 'node', 'field' => 'vid');
    }
  }

  /**
   * Help build the query.
   */
  public function query() {
    // Not calling parent::query() as it will treat 'state' as a real db field.
    $this->ensure_my_table();
    $this->add_additional_fields();

    if (empty($this->_node_based)) {
      $join = new views_join();
      $join->construct('node', $this->table_alias, 'nid', 'nid');
      $table_alias = $this->query->ensure_table('node', $this->table_alias, $join);
      $this->aliases['published'] = $this->query->add_field($table_alias, 'status');
      $this->aliases['current_vid'] = $this->query->add_field($table_alias, 'vid');
    }
  }

  /**
   * Render the data.
   *
   * Note that $values contains:
   *   o node_revisions_nid (parent node id)
   *   o node_revisions_vid (revision id)
   *   o node_status (published flag)
   *   o node_vid (current revision id)
   */
  public function render($values) {
    $nid = $values->{$this->aliases['nid']};
    $vid = $values->{$this->aliases['vid']};
    $published = $values->{$this->aliases['published']};
    $current_vid = $values->{$this->aliases['current_vid']};
    $is_initial_unpublished_draft = !$published && (revisioning_get_number_of_revisions($nid) == 1);
    $is_pending = ($vid > $current_vid) || $is_initial_unpublished_draft;
    $state_code = $is_pending ? REVISION_PENDING : ($vid == $current_vid ? REVISION_CURRENT : REVISION_ARCHIVED);
    $description = revisioning_revision_states($state_code);
    return $description;
  }
}
