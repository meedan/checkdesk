<?php

/**
 * Retrive source callback.
 *
 * @param int $id
 *   source id
 *
 * @return string
 *  HTML for source view
 */
function _sources_resource_retrieve($id) {
    $source = node_load($id);
    if (!is_object($source) || $source->type !== 'source') {
       return _checkdesk_api_error(t('source with the provided id (@id) was not found', array('@id' => $id)), 404);
    }
    return array(
        'type' => 'sources',
        'data' => _sources_format_source($source),
    );
}

/**
 * Create source callback.
 *
 * @param array $source
 *   An associative array with a "url" and "story_id" keys
 *
 * @return array
 *   An associative array with two keys "id" and "url"
 */
function _sources_resource_create($source) {
    $msg = '';
    if (!isset($source['url'])) {
        $msg = t('Parameters missing (URL)');
    }

    if (!empty($msg)) {
        return _checkdesk_api_error($msg, 400);
    }
    // Create a source
    global $user;
    $node = new StdClass;
    $node->type = 'source';
    node_object_prepare($node);
    $node->status = 1;
    $node->language = LANGUAGE_NONE;
    $node->uid = $user->uid;
    $node->field_source_url[LANGUAGE_NONE][0]['url'] = $source['url'];

    if ($node = node_submit($node)) {node_save($node);
        return array(
            'type' => 'sources',
            'data' => _sources_format_source($node),
        );
    }
    //TODO: add a clear error msg
    return _checkdesk_api_error(t('Failed to create a new source'), 400);
}

/**
 * Lists all existing stories.
 *
 * @return array
 *   An array with stories data nid and title.
 */
function _sources_resource_index() {
    $sources = array();
    $result = db_query_range('
                        SELECT n.nid
                        FROM {node} n
                        WHERE n.type = :type AND n.status = :status
                        ',1, 50, array(':type' => 'source', ':status' => 1)
    )->fetchCol();
    foreach (node_load_multiple($result) as $source) {
        $sources[] = _sources_format_source($source);
    }
    return array(
        'type' => 'sources',
        'data' => $sources,
    );
}

function _sources_format_source($source) {
    return array(
        'nid' => $source->nid,
        'title' => $source->title,
        'provider' => $source->field_provider[LANGUAGE_NONE][0]['value'],
        'url' => url('node/'. $source->nid, array('absolute' => TRUE)),
        'original_url' => $source->field_source_url[LANGUAGE_NONE][0]['url'],
        'uid' => $source->uid,
    );
}
