<?php


/**
 * 
 */
function _checkdesk_reports_export() {
  // Load reports
  $all_stories = TRUE;
  $file_name = date('Ymd', time()). '-reports';
  $query = db_select('node', 'n');
  $query->addExpression('FROM_UNIXTIME(created)', 'created');
  $query->addField('fl', 'field_link_url');
  $query->addField('ms', 'source');
  $query->fields('n', array('nid', 'title'));
  $query->join('field_data_field_link', 'fl', 'n.nid = fl.entity_id');
  $query->join('meedan_sources_media', 'msm', 'n.nid = msm.nid');
  $query->join('meedan_sources', 'ms', 'ms.ms_id = msm.ms_id');
  $query->condition('n.type', 'media');
  $query->groupBy('n.nid');
  if (arg(1) !== null && is_numeric(arg(1))) {
    // Load reports for specific story
    $all_stories = FALSE;
    $file_name .= '-' . arg(1);
    $query->join('field_data_field_stories', 'fs', 'n.nid = fs.entity_id AND field_stories_target_id = :story', array(':story' => arg(1)));
  }
  $file_name .= '.csv';
  $reports = $query->execute()->fetchAllAssoc('nid');
  // Get max footnotes count to set header
  $query = db_select('node', 'n');
  $query->join('comment', 'c', 'n.nid = c.nid AND n.type = :type', array(':type' => 'media'));
  $query->addExpression('COUNT(n.nid)', 'count');
  if (!$all_stories) {
    $query->condition('n.nid', array_keys($reports), 'IN');
  }
  $query->groupBy('n.nid');
  $query->orderBy('count', 'DESC');
  $query->range(0, 1);
  $max_footnotes = $query->execute()->fetchField();

  // output the column headings
  // Basic fields
  $header = array(t('URL'), T('Source'), t('Title'), t('Post date'));
  // Append manually entered fields by user
  $metadata_group_info = field_group_info_groups('node', 'media');
  $manually_fields = array();
  foreach ($metadata_group_info['form']['group_metadata']->children as $field) {
    $info = field_info_instance('node', $field, 'media');
    $manually_fields[] = $field;
    $header[] = $info['label'];
  }

  // Append footnotes header (column for each footnote)
  for ($i = 1; $i <= $max_footnotes; $i++) {
    $header[] = t('Footnote #@count', array('@count' => $i));
  }

  $rows = array();
  foreach($reports as $nid => $value) {
    $row = (array) $value;
    // Load manually fields
    $metadata = _checkdesk_fetch_report_metadata($manually_fields, $row['nid']);
    foreach ($manually_fields as $k) {
      $row[] = array_key_exists($k, $metadata) ? $metadata[$k] : '';
    }
    unset($row['nid']);
    // load footnotes for report
    $footnotes = db_query('SELECT cid, subject FROM {comment} WHERE nid = :nid', array(':nid' => $nid))->fetchCol(1);
    foreach($footnotes as $footnote) {
      $row[] = $footnote;
    }
    $rows[] = $row;
  }

  // Export CSV file
  // output headers so that the file is downloaded rather than displayed
  header('Content-Type: text/csv; charset=utf-8');
  header('Content-Disposition: attachment; filename='. $file_name);
  // create a file pointer connected to the output stream
  $output = fopen('php://output', 'w');
  //print_r($header);
  fputcsv($output, $header);
  foreach ($rows as $row) {
    fputcsv($output, $row);
  }
  drupal_exit();
}

/**
 *
 */
function _checkdesk_fetch_report_metadata($manually_fields, $nid) {
  $metadata = array();
  $node = node_load($nid);
  foreach ($manually_fields as $field_name) {
    $field_items = field_get_items('node', $node, $field_name);
    $field = field_view_value('node', $node, $field_name, $field_items[0], 'checkdesk_export');
    $value = render($field);
    if (!empty($value)) {
      $metadata[$field_name] = strip_tags($value);
    }
  }
  return $metadata;
}
