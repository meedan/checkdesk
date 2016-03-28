<?php

/**
 * Template preprocessor for `checkdesk_sources_source_activity`.
 */
function checkdesk_sources_preprocess_checkdesk_sources_source_activity(&$variables) {
  global $language;
  $node = $variables['node'];
  $variables['nid'] = $node->nid;
  $variables['collapsed'] = 'open';
  $source_activity = checkdesk_source_load_activity($variables['nid']);
  $variables['comments_count'] = t('@count comments', array('@count' => $source_activity['total_rows']));
  $variables['source_activity'] = $source_activity['view_output'];
}
