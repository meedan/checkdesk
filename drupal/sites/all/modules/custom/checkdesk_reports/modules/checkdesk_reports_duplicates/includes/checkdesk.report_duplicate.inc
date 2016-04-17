<?php

/*
 * Menu callback for checkdesk/report-duplicate.
 */
function _checkdesk_detect_report_duplicate_callback() {
    $path = (isset($_GET['url']) ? $_GET['url'] : FALSE);
    // Add duplicate reports id exists
    $response = array('duplicates' => FALSE);
    if (!$path) {
        return $response;
    }
    // hide duplicate reports messages in node edit form
    if ($_GET['report_id']) {
        $report = node_load($_GET['report_id']);
        if ($report->field_link[LANGUAGE_NONE][0]['url'] != $path) {
            $duplicates = _checkdesk_detect_report_duplicate($path, $_GET['report_id'], $_GET['story_id']);
            $response['duplicates'] = $duplicates;
        }
    }
    else {
        $duplicates = _checkdesk_detect_report_duplicate($path, $_GET['report_id'], $_GET['story_id']);
        $response['duplicates'] = $duplicates;
    }
    drupal_json_output($response);
}

/**
 * @param string $url
 *  report url
 * @param $report_id
 * @param $story_id
 * @return array|bool
 * FALSE if no duplicate or
 * Associative array with report_nid => story_nid
 */

function _checkdesk_detect_report_duplicate($url, $report_id, $story_id) {
    $output = array();
    $output['duplicate'] = $output['duplicate_story'] = FALSE;
    $reports = _checkdesk_duplicate_reports($url);
    // Unset current report (edit form)
    unset($reports[$report_id]);
    if (count($reports)) {
        $duplicate_reports = array();
        $output['duplicate'] = TRUE;
        $story_id = is_numeric($story_id) ? $story_id : 0;
        $query = db_select('node', 'n');
        $query->fields('n', array('nid', 'title', 'uid', 'created'));
        $query->addField('u', 'name');
        $query->addField('n2', 'nid', 'story_id');
        $query->addField('n2', 'title', 'story_title');
        $query->innerJoin('users', 'u', 'n.uid = u.uid');
        $query->leftJoin('field_data_field_stories', 'fs', 'n.nid = fs.entity_id');
        $query->leftJoin('node', 'n2', 'fs.field_stories_target_id = n2.nid');
        $query->condition('n.nid', array_keys($reports), 'IN');
        $query->addTag('checkdesk_duplicate');
        $result = $query->execute()->fetchAllAssoc('nid');
        $duplicate_report_nid = 0;
        foreach ($result as $k => $v) {
            if ($v->story_id == $story_id) {
                $output['duplicate_story'] = TRUE;
                $duplicate_report_nid = $v->nid;
            }
            $story = '';
            $author =  l($v->name, 'user/'. $v->uid, array(
              'attributes' => array('target'=>'_blank', 'class' => array('actor'))
            ));
            if ($v->story_id) {
                $story = l($v->story_title, 'node/'. $v->story_id, array(
                  'attributes' => array('target'=>'_blank', 'class' => array('duplicate-report-story'))
                ));
            }
            $created_at = t('<time datetime="!isodatetime" class="timestamp timeago">!interval ago</time>', array(
              '!interval' => format_interval((time() - $v->created), 1),
              '!isodatetime' => format_date($v->created, 'custom', 'c'),
            ));

            $duplicate_reports[$v->nid] = array(
              'author' => $author,
              'story' => $story,
              'created_at' => $created_at,
            );
        }
        $output['msg'] = theme('checkdesk_reports_duplicates', array(
          'reports' => $duplicate_reports, 'duplicate_report_nid' => $duplicate_report_nid));
    }
    return $output;
}


/*
 * Menu callback for checkdesk/duplicate-report-story.
 */
function _checkdesk_duplicate_report_story() {
    $output['duplicate'] = FALSE;
    $url = isset($_GET['url']) ? $_GET['url'] : FALSE;
    $report_id = $_GET['report_id'];
    $story_id = is_numeric($_GET['story_id']) ? $_GET['story_id'] : 0;
    if ($url) {
        $output = _checkdesk_duplicate_report_story_exists($url, $report_id, $story_id);
    }
    drupal_json_output($output);
}