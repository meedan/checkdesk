<?php

function render_report_sql($type, $year = '') {
  $values = array();
  $year_filter = '';
  if ($year) {
    $year_filter = " AND FROM_UNIXTIME(created,'%Y') = $year ";
  }
  switch ($type) {
  case 'user_registered':
    $query = db_select('users', 'u');
    $query->addExpression('FROM_UNIXTIME(created, \'%M %Y\')', 'date');
    $query->addExpression('COUNT(uid)', 'count');
    $query->condition('u.uid', 1, '<>');
    $query->condition('u.status', 0, '<>');
    if ($year) {
      $query->where('FROM_UNIXTIME(u.created, \'%Y\') = :year', array(':year' => $year));
    }
    $query->groupBy('FROM_UNIXTIME(created, \'%M %Y\')');
    $query->orderBy('FROM_UNIXTIME(created, \'%Y-%m\')', 'ASC');
    $query->orderBy('count', 'DESC');
    $title = t('Registered users'); 
    break;
  case 'translation_count':
    $sql = "SELECT FROM_UNIXTIME(created,'%M %Y') AS date,
      SUM(LENGTH(field_translation_value) - LENGTH(REPLACE(field_translation_value, ' ', ''))+1) as count
      FROM `content_type_report` ctr 
      INNER JOIN node n ON n.nid = ctr.nid
      WHERE field_translation_value IS NOT NULL $year_filter 
      GROUP BY FROM_UNIXTIME(created,'%m %Y')
      ORDER BY FROM_UNIXTIME( created, '%Y-%m' ) ASC , count DESC";
    $title = t('Translated reports words');
    break;
  case 'translation_reports':
    $sql = "SELECT FROM_UNIXTIME( created, '%M %Y' ) AS date, COUNT( * ) AS count
      FROM `content_type_report` ctr
      INNER JOIN node n ON n.nid = ctr.nid
      WHERE field_translation_value IS NOT NULL $year_filter
      GROUP BY FROM_UNIXTIME( created, '%m %Y' )
      ORDER BY FROM_UNIXTIME( created, '%Y-%m' ) ASC , count DESC";
    $title = t('Translated reports');
    break;
  case 'reports_count' :
    $query = db_select('node', 'n');
    $query->addExpression('FROM_UNIXTIME(created, \'%M %Y\')', 'date');
    $query->addExpression('COUNT(uid)', 'count');
    $query->condition('n.type', 'media');
    $query->condition('n.status', 1);
    if ($year) {
      $query->where('FROM_UNIXTIME(n.created, \'%Y\') = :year', array(':year' => $year));
    }
    $query->groupBy('FROM_UNIXTIME(created, \'%M %Y\')');
    $query->orderBy('FROM_UNIXTIME(created, \'%Y-%m\')', 'ASC');
    $query->orderBy('count', 'DESC');
    $title = t('Citizen reports');
    break;
  case 'different_sources' :
    $query = db_select('meedan_sources', 'ms');
    $query->addExpression('CONCAT_WS( \'\n\', CONCAT_WS( \' \', ms.source, CONCAT( \'[\', ms_parent.source, \']\' ) ) , FROM_UNIXTIME( created, \'%M %Y\'))', 'info');
    $query->addExpression('FROM_UNIXTIME(created, \'%M %Y\')', 'date');
    $query->addExpression('COUNT(ms.source)', 'count');
    $query->leftJoin('meedan_sources', 'ms_parent', 'ms.parent = ms_parent.ms_id');
    $query->innerJoin('meedan_sources_media', 'msm', 'msm.ms_id = ms.ms_id');
    $query->innerJoin('node', 'n', 'n.nid = msm.nid');
    if ($year) {
      $query->where('FROM_UNIXTIME(n.created, \'%Y\') = :year', array(':year' => $year));
    }
    $query->groupBy('FROM_UNIXTIME(n.created, \'%m %Y\')');
    $query->groupBy('ms.source');
    $query->orderBy('FROM_UNIXTIME(n.created, \'%Y-%m\')', 'ASC');
    $query->orderBy('n.created', 'DESC');
    $title = t('Different sources');
    break;
  case 'most_active_users' :
    $query = db_select('node', 'n');
    $query->addExpression('CONCAT_WS(\'\n\', name, FROM_UNIXTIME( n.created, \'%M %Y\' ))', 'info');
    $query->addExpression('FROM_UNIXTIME(n.created, \'%M %Y\')', 'date');
    $query->addExpression('COUNT(*)', 'count');
    $query->innerJoin('users', 'u', 'u.uid = n.uid');
    $query->groupBy('FROM_UNIXTIME(n.created, \'%M %Y\')');
    $query->groupBy('n.uid');
    $query->orderBy('FROM_UNIXTIME(n.created, \'%Y-%m\')', 'ASC');
    $query->orderBy('count', 'DESC');
    $title = t('Most active users as measured by number of reports submitted');
    break;
  case 'detailed_citizen_reports' :
    $sql = "SELECT FROM_UNIXTIME(created,'%M %Y') AS date, COUNT(*) AS count
      FROM content_type_report ctr
      INNER JOIN node n ON ctr.nid = n.nid
      WHERE ((field_location_value IS NOT NULL) OR (field_time_value IS NOT NULL) OR (field_source_value IS NOT NULL) OR (field_parties_value IS NOT NULL) OR (field_corroboration_value IS NOT NULL) OR (field_transcription_value IS NOT NULL) OR (field_translation_value IS NOT NULL)) $year_filter
      GROUP BY FROM_UNIXTIME( n.created, '%M %Y' )
      ORDER BY FROM_UNIXTIME( created, '%Y-%m' ) ASC , count DESC";
    $title = t('Detailed citizen Reports');
    break;
  case 'active_users':
    $query = db_select('node', 'n');
    $query->addExpression('FROM_UNIXTIME(created, \'%M %Y\')', 'date');
    $query->addExpression('COUNT(*)', 'count');
    $query->condition('n.uid', 0, '<>');
    if ($year) {
      $query->where('FROM_UNIXTIME(n.created, \'%Y\') = :year', array(':year' => $year));
    }
    $query->groupBy('FROM_UNIXTIME(n.created, \'%M %Y\')');
    $query->orderBy('n.created');
    $title = t('Numbers of users submitting reports');
    break;
  }
  $results = $query->execute()->fetchAll();
  $values = array('results' => $results, 'title' => $title);
  return $values;
}

