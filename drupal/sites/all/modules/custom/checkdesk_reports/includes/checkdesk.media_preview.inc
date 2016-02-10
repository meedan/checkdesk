<?php

/*
 * Menu callback for checkdesk/media-preview.
 */
function _checkdesk_reports_media_preview_callback() {
    $path = (isset($_GET['url']) ? $_GET['url'] : FALSE);
    drupal_json_output(_checkdesk_reports_media_preview($path));
}

/*
 * Function to show media preview.
 */
function _checkdesk_reports_media_preview($path) {
    $response = array('preview' => '');

    if (!$path) {
        return array(
            'error' => array(
                'message' => t('Preview not available.'),
            ),
        );
    }

    $oembed = meedan_oembed_data($path, array(), TRUE);
    if ($oembed) {
        if (isset($oembed->error) && $oembed->error) {
            $response['error'] = array();

            if (isset($oembed->error_message) && $oembed->error_message) {
                $response['error']['message'] = check_plain($oembed->error_message);
            }
            else {
                $response['error']['message'] = check_plain(t('There was a problem parsing this report. You can create the report now (but it will remain unpublished) and try to parse it later, or give up and try to submit it again later.'));
            }
        }
        else {
            if (isset($oembed->html)) {
                $response['preview'] = $oembed->html;
            }
            else if (isset($oembed->thumbnail_url)) {
                $response['preview'] = theme_image(array('path' => $oembed->thumbnail_url, 'alt' => t('Preview'), 'attributes' => array('class' => 'bookmarklet-preview')));
            }
            if (isset($oembed->description)) {
                $response['description'] = $oembed->description;
            }
            if (isset($oembed->title)) {
                $response['title'] = $oembed->title;
            }

            // Add duplicate reports id exists
            $response['duplicates'] = FALSE;
            if (module_exists('checkdesk_reports_duplicates')) {
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
            }
        }
    }
    return $response;
}

/**
 *
 */
function _checkdesk_media_widget_callback($nid) {
    $node = node_load($nid);
    $render = field_view_field('node', $node, 'field_link',
        array(
            'type' => 'meedan_oembed_thumbnail',
            'settings' => array('imagestyle' => 'report_thumbnail'),
        )
    );
    $media_ref = checkdesk_core_droppable_reference($node);
    $response = array(
        'preview' => render($render),
        'media_ref' => $media_ref,
    );
    drupal_json_output($response);
}
