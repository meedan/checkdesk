<?php

/**
 * Retrive report callback.
 *
 * @param int $id
 *   Report id
 *
 * @return string
 *  HTML for report view
 */
function _reports_resource_retrieve($id) {
    $report = node_load($id);
    if (!is_object($report) || $report->type !== 'media') {
        _checkdesk_api_error(t('Report with the provided id (@id) was not found', array('@id' => $id)), 404);
    }
    return array(
        'type' => 'reports',
        'data' => array(
            'title' => $report->title,
            'url' => url('node/'. $report->nid),
        ),
    );
}

/**
 * Create report callback.
 *
 * @param array $report
 *   An associative array with a "url" and "story_id" keys
 *
 * @return array
 *   An associative array with two keys "id" and "url"
 */
function _reports_resource_create($report) {
    $msg = '';
    if (!isset($report['url'])) {
        $msg = t('Parameters missing (URL)');
    }
    if (isset($report['story_id'])) {
        if (is_numeric($report['story_id'])) {
            $story = node_load($report['story_id']);
            if (!is_object($story) || $story->type !== 'discussion') {
                $msg = t('Story with the provided id (@id) was not found', array('@id' => $report['story_id']));
            }
        }
        else {
            $msg = t('Story id must be a numeric value');
        }
    }
    if (!empty($msg)) {
        _checkdesk_api_error($msg, 400);
    }
    // Create a report
    // TODO use form_submit to validate URL
    $node = new stdclass() ;
    $node->type ='media';
    node_object_prepare($node);
    $node->field_link[LANGUAGE_NONE][0]['url'] = $report['url'];
    if (isset($report['story_id'])) {
        $node->field_stories[LANGUAGE_NONE][0]['target_id '] = $report['story_id'];

    }
    node_save($node);
    return array(
        'type' => 'reports',
        'data' => array(
            'id' => $node->nid,
            'url' => url('node/'. $node->nid),
        ),
    );
}

/**
 * Lists all existing stories.
 *
 * @return array
 *   An array with stories data nid and title.
 */
function _reports_resource_index() {
    $reports = array();
    $result = db_query_range('SELECT fl.entity_id, fl.field_link_url
                        FROM {field_data_field_link} fl
                        INNER JOIN {node} n ON fl.entity_id = n.nid
                        WHERE bundle = :bundle AND n.status = :status
                        ',1, 50, array(':bundle' => 'media', ':status' => 1)
    );
    foreach ($result as $report) {
        $reports[] = array(
            'id' => $report->entity_id,
            'url' => $report->field_link_url,
        );
    }
    return array(
        'type' => 'reports',
        'data' => $reports,
    );
}
