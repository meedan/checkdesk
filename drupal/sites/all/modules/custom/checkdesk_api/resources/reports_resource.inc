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
function _report_resource_retrieve($id) {
    $report = node_load($id);
    if (!is_object($report)) {
        return services_error(t('Report with the provided id (@id) was not found', array('@id' => $id)), 400);
    }
    return array(
        'title' => $report->title,
        'url' => url('node/'. $report->nid),
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
function _node_resource_create($report) {
    if (!isset($report['url'])) {
        return services_error(t('Parameters missing (URL)'), 400);
    }
    if (isset($report['story_id'])) {
        $story = NULL;
        if (is_numeric($report['story_id'])) {
            $story = node_load($report['story_id']);
        }
        if (!is_object($story)) {
            return services_error(t('Story with the provided id (@id) was not found', array('@id' => $report['story_id'])), 400);
        }
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
        'id' => $node->nid,
        'url' => url('node/'. $node->nid),
    );
}

/**
 * Lists all existing reports.
 *
 * @return array
 *   An array with stories data nid and url.
 */
function _reports_resource_index() {
    $reports = array();

    $result = db_query_range('SELECT entity_id, field_link_url
                        FROM {field_data_field_link} fl
                        INNER JOIN {node} n ON fl.entity = n.nid
                        WHERE bundle = :bundle AND n.status = :status
                        ', array(':bundle' => 'media', ':status' => 1)
                        , 1, 50);
    foreach ($result as $report) {
        $reports[] = array(
            'id' => $report->nid,
            'url' => $report->url,
        );
    }
    return $reports;
}
