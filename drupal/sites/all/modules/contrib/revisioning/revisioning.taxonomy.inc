<?php

/**
 * @file
 * Code required only when the Taxonomy module is enabled.
 */

/**
 * Updates the {taxonomy_index} table.
 *
 * Assures that when content with terms is
 * shown in a View, the correct terms (those belonging to the current, rather
 * than latest revision) are displayed, regardless of whether the content is
 * published or not.
 *
 * Revisioning's weight has been set higher than Taxonomy's so this is called
 * after taxonomy_node_insert() or taxonomy_node_update().
 * Called when creating, updating or (un)publishing a node.
 *
 * @param object $node
 *   the node object
 * @param bool $show_unpublished_content_terms
 *   whether to show unpublished content terms
 */
function revisioning_update_taxonomy_index($node, $show_unpublished_content_terms = TRUE) {
  if (module_exists('taxonomy') && variable_get('taxonomy_maintain_index_table', TRUE)) {
    // First, delete all term id's associated with this node.
    db_delete('taxonomy_index')->condition('nid', $node->nid)->execute();
    // Use of taxonomy_delete_node_index($node); requires core 7.12 or later
    // Then add terms if node is published OR terms are requested explicitly.
    if ($node->status || $show_unpublished_content_terms) {
      $vid = empty($node->revision_moderation) || empty($node->current_revision_id) ? $node->vid : $node->current_revision_id;
      // Find all the terms attached to this node revision.
      $tids = revisioning_get_tids($vid);
      if (!empty($tids)) {
        // Core, via taxonomy_node_update(), only does this when node is
        // published, but then we can't see the terms of unpublished content
        // in Views!
        $query = db_insert('taxonomy_index')->fields(
          array('nid', 'tid', 'sticky', 'created')
        );
        foreach ($tids as $tid) {
          $query->values(array(
            'nid' => $node->nid,
            'tid' => $tid,
            // See [#1417658].
            'sticky' => empty($node->sticky) ? 0 : 1,
            'created' => $node->created,
          ));
        }
        $query->execute();
      }
    }
  }
}

/**
 * Return array of all taxonomy term ids belonging to the supplied revision.
 *
 * @param int $vid
 *   the revision id
 */
function revisioning_get_tids($vid) {
  $tids = array();
  $conditions = array('type' => 'taxonomy_term_reference');
  $fields = field_read_fields($conditions);
  foreach ($fields as $field => $data) {
    $sql = "SELECT {$field}_tid AS tid FROM {field_revision_$field} WHERE revision_id = :vid AND entity_type = 'node' AND deleted = 0 ORDER BY tid";
    $result = db_query($sql, array(':vid' => $vid));
    foreach ($result as $term) {
      $tids[$term->tid] = $term->tid;
    }
  }
  return $tids;
}
