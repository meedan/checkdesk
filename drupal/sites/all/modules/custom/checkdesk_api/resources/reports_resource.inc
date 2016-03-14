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
       return _checkdesk_api_error(t('Report with the provided id (@id) was not found', array('@id' => $id)), 404);
    }
    return array(
        'type' => 'report',
        'data' => _reports_format_report($report),
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
        return _checkdesk_api_error($msg, 400);
    }
    // Create a report
    global $user;
    $node = new StdClass;
    $node->type = 'media';
    node_object_prepare($node);
    $node->status = 1;
    $node->language = LANGUAGE_NONE;
    $node->uid = $user->uid;
    $node->field_link[LANGUAGE_NONE][0]['url'] = $report['url'];
    if (isset($report['story_id'])) {
        $node->field_stories[LANGUAGE_NONE][0]['target_id '] = $report['story_id'];
    }

    if ($node = node_submit($node)) {
        node_save($node);
        return array(
            'type' => 'reports',
            'data' => $node,
        );
    }
    //TODO: add a clear error msg
    return _checkdesk_api_error(t('Failed to create a new report'), 400);
}

/**
 * Lists all existing stories.
 *
 * @return array
 *   An array with stories data nid and title.
 */
function _reports_resource_index() {
    $reports = array();
    $result = db_query_range('
                        SELECT n.nid
                        FROM {node} n
                        WHERE n.type = :type AND n.status = :status
                        ',1, 50, array(':type' => 'media', ':status' => 1)
    )->fetchCol();
    foreach (node_load_multiple($result) as $report) {
        $reports[] = _reports_format_report($report);
    }
    return array(
        'type' => 'reports',
        'data' => $reports,
    );
}

function _reports_format_report($report) {
    return array(
        'nid' => $report->nid,
        'title' => $report->title,
        'url' => url('node/'. $report->nid, array('absolute' => TRUE)),
        'original_url' => $report->field_link[LANGUAGE_NONE][0]['url'],
        'uid' => $report->uid,
    );
}