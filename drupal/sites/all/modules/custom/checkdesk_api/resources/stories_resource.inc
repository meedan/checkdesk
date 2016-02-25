<?php


/**
 * Lists all existing stories.
 *
 * @return array
 *   An array with stories data nid and title.
 */
function _stories_resource_index() {
    $stories = array();
    $result = db_query('SELECT nid, title FROM {node} WHERE type = :type AND status = :status', array(':type' => 'discussion', ':status' => 1));
    foreach ($result as $story) {
        $stories[] = array(
            'id' => $story->nid,
            'title' => $story->title,
        );
    }
    return $stories;
}