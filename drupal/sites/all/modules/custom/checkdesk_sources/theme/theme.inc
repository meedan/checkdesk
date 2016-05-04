<?php

/**
 * Template preprocessor for `checkdesk_sources_source_activity`.
 */
function checkdesk_sources_preprocess_checkdesk_sources_source_activity(&$variables) {
  global $language;
  $node = $variables['node'];
  $variables['nid'] = $node->nid;
  $variables['collapsed'] = ($variables['view_mode'] == 'full') ? 'open' : '';
  $variables['show_activity'] = ($variables['view_mode'] == 'checkdesk_search') ? FALSE : TRUE;
  $source_activity = checkdesk_source_load_activity($variables['nid']);
  $variables['source_activity'] = $source_activity['view_output'];
  $total_rows = $source_activity['total_rows'];
  if ($variables['show_activity'] || empty($total_rows)) {
    $variables['source_activity_count'] = theme(
      'checkdesk_sources_activity_count', array('count' => $total_rows, 'nid' => $variables['nid'])
    );
  }
  else {
    $variables['source_activity_count'] = theme(
      'checkdesk_sources_activity_count', array('count' => $total_rows, 'nid' => $variables['nid'], 'link_count' => TRUE)
    );
  }
}
