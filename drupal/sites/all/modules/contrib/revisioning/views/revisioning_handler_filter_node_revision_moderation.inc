<?php

/**
 * @file
 * Views filter override to filter on whether node is subject to moderation.
 */

define('REVISIONING_MODERATED', 1);
define('REVISIONING_NOT_MODERATED', 0);

class revisioning_handler_filter_node_revision_moderation extends views_handler_filter_in_operator {

  /**
   * Add a where clause to the query.
   */
  public function query() {
    if (empty($this->value) || (isset($this->value[0]) && isset($this->value[1]))) {
      // Don't filter if none or both options are set.
      return;
    }
    $moderated_content_types = array();
    foreach (revisioning_moderated_content_types() as $moderated_content_type) {
      $moderated_content_types[] = "'$moderated_content_type'";
    }
    $this->ensure_my_table();
    if (empty($moderated_content_types)) {
      if (reset($this->value) == REVISIONING_MODERATED) {
        // None of the content types are moderated, so return nothing.
        $this->query->add_where($this->options['group'], '1 = 0');
      }
    }
    else {
      $moderated = (reset($this->value) == REVISIONING_MODERATED);
      if ($this->operator == 'not in') {
        $moderated = !$moderated;
      }
      $where_operator = $moderated ? 'IN' : 'NOT IN';
      $where_expression = $this->table_alias . '.type ' . $where_operator . ' (' . implode(',', $moderated_content_types) . ')';
      $this->query->add_where_expression($this->options['group'], $where_expression);
    }
  }

  /**
   * Get the value options.
   */
  public function get_value_options() {
    $this->value_title = t('Moderated');
    $this->value_options = array(
      REVISIONING_MODERATED => t('Moderated'),
      REVISIONING_NOT_MODERATED => t('Not moderated'));
  }
}
