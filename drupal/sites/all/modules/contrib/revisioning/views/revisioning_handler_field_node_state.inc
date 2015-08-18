<?php

/**
 * @file
 * Handler for the 'Node: state' field.
 */

class revisioning_handler_field_node_state extends views_handler_field {

  /**
   * Call constructor.
   */
  public function construct() {
    parent::construct();
    // Request node fields required to calculate the 'state' when rendering.
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['vid'] = 'vid';
    $this->additional_fields['published'] = array('field' => 'status');
  }

  /**
   * Check for access.
   */
  public function access() {
    return user_access('access content');
  }

  /**
   * Help build the query.
   */
  public function query() {
    // Not calling parent::query() as it will treat 'state' as a real db field.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Implement the rendering of the state value.
   *
   * Note that $values contains:
   *   o nid
   *   o node_vid (current revision id)
   *   o node_status (published flag)
   */
  public function render($values) {
    $published = $values->{$this->aliases['published']};
    $nid = $values->{$this->aliases['nid']};
    $current_vid = $values->{$this->aliases['vid']};
    $is_initial_unpublished_draft = !$published && (revisioning_get_number_of_revisions($nid) == 1);
    $latest_vid = revisioning_get_latest_revision_id($nid);
    $is_pending = ($latest_vid > $current_vid) || $is_initial_unpublished_draft;
    $description = $is_pending
      ? (!$published && !$is_initial_unpublished_draft ? t('Archived with revision pending') : t('Revision pending'))
      : ($published && ($latest_vid == $current_vid) ? t('Current, published') : t('Archived'));
    return $description;
  }
}
