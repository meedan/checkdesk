<?php


/**
 * Lists all existing stories.
 *
 * @return array
 *   An array with stories data nid and title.
 */
function _stories_resource_index() {
    $stories = array();
    $result = db_query_range('SELECT nid, title FROM {node} WHERE type = :type AND status = :status', 1 , 50, array(':type' => 'discussion', ':status' => 1));
    foreach ($result as $story) {
        $stories[] = array(
            'id' => $story->nid,
            'title' => $story->title,
        );
    }
    return array(
        'type' => 'stories',
        'data' => $stories,
    );
}
