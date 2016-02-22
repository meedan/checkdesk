<?php


/**
 * Lists all existing stories.
 *
 * @return array
 *   An array with stories data nid and title.
 */
function _stories_resource_index() {
    $stories = array();

    $result = db_query('SELECT nid, title FROM {node} WHERE type = :type', array(':type' => 'discussion'));
    foreach ($result as $story) {
        $stories[] = array(
            'gid' => $story->nid,
            'name' => $story->title,
        );
    }
    return $stories;
}