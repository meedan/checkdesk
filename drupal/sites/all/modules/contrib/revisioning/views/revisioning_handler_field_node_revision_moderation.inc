<?php

/**
 * @file
 * Handler for the 'Node: revision moderation' field.
 */

class revisioning_handler_field_node_revision_moderation extends views_handler_field {

  /**
   * Call constructor.
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['type'] = 'type';
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
    // Not calling parent::query() as it will treat 'number of revisions' as
    // a real db field.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render the data.
   */
  public function render($values) {
    $content_type = $values->{$this->aliases['type']};
    $moderated = revisioning_content_is_moderated($content_type);
    // Not returning 'No' to allow special tricks with empty field.
    return $moderated ? t('Yes') : '';
  }
}
