<?php

function _checkdesk_core_prepare_exported_data($csv_folder, $index, $model, $options) {
  $fun = "_checkdesk_export_build_query_$model";
  $query = $fun($options);
  $data = db_query($query['query'], $query['params']);
  $data = $data->fetchAll();
  if ($model == 'projects') {
    _check_adjust_html_text($data, 'description');
    _check_adjust_image_path($data, 'lead_image');
  }
  elseif ($model == 'statuses') {
    _check_get_hearbeat_value($data, 'status', '!status');
  }
  elseif ($model == 'flags') {
    _check_get_hearbeat_value($data, 'flag', '!flag_type');
  }
  elseif ($model == 'team_users') {
    _check_get_user_role($data);
  }
  $header = array_keys((array)$data[0]);
  $file_name = _get_file_name($csv_folder, $model, $index);
  _checkdesk_core_write_to_csv($file_name, $header, $data);
}

function _check_get_user_role(&$data) {
  $roles = array_flip(user_roles(TRUE));
  $administrator_role_id = $roles['administrator'];
  $journalist_role_id = $roles['journalist'];
  foreach ($data as &$row) {
    $user_roles = explode(',', $row->role);
    if (in_array($administrator_role_id, $user_roles)) {
      $role = 'owner';
    }
    else {
      $max_role = MAX($user_roles);
      $role = ($max_role == $journalist_role_id) ? 'journalist' : 'contributor';
    }
    $row->role = $role;
  }
}

function _check_adjust_html_text(&$data, $key) {
  foreach ($data as &$row) {
    $row->{$key} = strip_tags($row->{$key});
  }
}

function _check_adjust_image_path(&$data, $key) {
  foreach ($data as &$row) {
    $row->{$key} = file_create_url($row->{$key});
  }
}

function _check_get_hearbeat_value(&$data, $type, $key) {
  foreach ($data as &$row) {
    $variables = heartbeat_decode_message_variables($row->{$type});
    $row->{$type} = $variables[$key];
  }
}

function _checkdesk_core_write_to_csv($file_name, $header, $data) {
  $fp = fopen($file_name, 'w');
  fputcsv($fp, $header, ',', '`');
  foreach ($data as $row) {
    $w_row = (array) $row;
    if (isset($w_row['logo'])) {
      $w_row['logo'] = file_create_url($w_row['logo']);
    }
    fputcsv($fp, $w_row, ',', '`');
  }
  fclose($fp);
}

function _get_file_name($csv_folder, $model, $index) {
  $index = sprintf("%02d", $index);
  return $csv_folder . $index . '_' . $model . '.csv';
}

function _checkdesk_export_build_query_users(&$options) {
  $query = array();
  $query['query'] = '
              SELECT u.name, u.mail AS email, u.pass AS password, f.uri AS profile_image,:skip AS skip_confirmation_mail,
                     IFNULL(fb.fbid, t.twitter_uid) AS uuid,
                     CASE WHEN fb.fbid IS NOT NULL then :facebook WHEN t.twitter_uid IS NOT NULL then :twitter ELSE :empty END AS provider,
                     FROM_UNIXTIME(u.created) AS created_at, FROM_UNIXTIME(u.login) AS login
              FROM {users} u
              LEFT JOIN {fboauth_users} fb ON u.uid = fb.uid
              LEFT JOIN {twitter_account} t on u.uid = t.uid
              LEFT JOIN {file_managed} f ON f.fid = u.picture
              WHERE u.uid <> :uid
              ';
  $query['params'] = array(':uid' => 0, ':skip' => true, ':facebook' => 'facebook', ':twitter' => 'twitter', ':empty' => '');
  if (count($options['user_uids'])) {
    $query['query'] .= ' AND u.uid IN (:ids)';
    $query['params'][':ids'] = $options['user_uids'];
  }
  $query['query'] .= ' GROUP BY u.uid';
  return $query;
}

function _checkdesk_export_build_query_team_users($options) {
  $query = array();
  $query['query'] = '
                      SELECT :team_id AS team_id, u.mail AS user_id, group_concat(ur.rid) AS role,
                             IF(u.status=:status, :member, :banned) AS status, FROM_UNIXTIME(u.created) AS created_at,
                             FROM_UNIXTIME(u.created) AS updated_at
                      FROM {users} u
                      INNER JOIN {users_roles} ur ON u.uid = ur.uid
                      WHERE u.uid <> :uid
              ';
  $query['params'] = array(':team_id' => $options['team_id'], ':status' => 1, ':member' => 'member', ':banned' => 'banned',':uid' => 0);

  if (count($options['user_uids'])) {
    $query['query'] .= ' AND u.uid IN (:ids)';
    $query['params'][':ids'] = $options['user_uids'];
  }
  $query['query'] .= ' GROUP BY u.uid';
  return $query;
}

function _checkdesk_export_build_query_projects($options) {
  $query = array();
  $query['query'] = '
                    SELECT n.nid AS id, n.title, :team_id AS team_id, u.mail AS user_id, fb.body_value AS description, f.uri AS lead_image,
                            FROM_UNIXTIME(n.created) AS created_at, FROM_UNIXTIME(n.changed) AS updated_at
                    FROM {node} n
                    INNER JOIN {users} u ON u.uid = n.uid
                    LEFT JOIN {field_revision_body} fb ON n.vid = fb.revision_id
                    LEFT JOIN {field_data_field_lead_image} fi ON n.nid = fi.entity_id
                    LEFT JOIN {file_managed} f ON f.fid = fi.field_lead_image_fid
                    WHERE n.type = :type
              ';
  $query['params'] = array(':team_id' => $options['team_id'], ':type' => 'discussion');
  if (count($options['story_ids'])) {
    $query['query'] .= ' AND n.nid IN (:ids)';
    $query['params'][':ids'] = $options['story_ids'];
  }
  return $query;
}

function _checkdesk_export_build_query_project_medias($options) {
  $query = array();
  $query['query'] = '
              SELECT n.nid AS id, fp.field_stories_target_id AS project_id, fl.field_link_url AS url, u.mail AS user_id,
                     FROM_UNIXTIME(n.created) AS created_at, FROM_UNIXTIME(n.changed) AS updated_at
              FROM {node} n
              INNER JOIN {users} u ON u.uid = n.uid
              INNER JOIN {field_data_field_link} fl ON n.nid = fl.entity_id
              INNER JOIN {field_data_field_stories} fp ON n.nid = fp.entity_id
              WHERE n.type = :type
              ';
  $query['params'] = array(':type' => 'media');
  if (count($options['story_ids'])) {
    $query['query'] .= ' AND fp.field_stories_target_id IN (:ids)';
    $query['params'][':ids'] = $options['story_ids'];
  }
  return $query;
}

function _checkdesk_export_build_query_tags($options) {
  $query = array();
  $query['query'] = '
              SELECT u.mail as annotator_id, :annotator as annotator_type, n.nid as annotated_id, :annotated as annotated_type,
                     td.name as tag, FROM_UNIXTIME(n.created) as created_at, FROM_UNIXTIME(n.changed) as updated_at
              FROM {node} n
              INNER JOIN {users} u ON u.uid = n.uid
              INNER JOIN {field_data_field_tags} ft ON ft.revision_id = n.vid
              INNER JOIN {taxonomy_term_data} td ON td.tid = ft.field_tags_tid
              WHERE n.type = :type
              ';
  $query['params'] = array(':annotator' => 'User', ':annotated' => 'ProjectMedia', ':type' => 'media');
  if (count($options['media_ids'])) {
    $query['query'] .= ' AND n.nid IN (:ids)';
    $query['params'][':ids'] = $options['media_ids'];
  }
  return $query;
}

function _checkdesk_export_build_query_comments($options) {
  $query = array();
  $query['query'] = 'SELECT u.mail as annotator_id, :annotator as annotator_type, n.nid as annotated_id, :annotated as annotated_type,
                      cb.comment_body_value AS text, FROM_UNIXTIME(n.created) as created_at, FROM_UNIXTIME(n.changed) as updated_at
                      FROM {node} n
                      INNER JOIN {users} u on n.uid = u.uid
                      INNER JOIN {comment} c ON n.nid = c.nid
                      INNER JOIN {field_data_comment_body} cb ON c.cid = cb.entity_id
                      WHERE n.type = :type
                      ';
  $query['params'] = array(':annotator' => 'User', ':annotated' => 'ProjectMedia', ':type' => 'media');
  if (count($options['media_ids'])) {
    $query['query'] .= ' AND n.nid IN (:ids)';
    $query['params'][':ids'] = $options['media_ids'];
  }
  return $query;
}

function _checkdesk_export_build_query_statuses($options) {
  $query = array();
  $query['query'] = '
            SELECT u.mail as annotator_id, :annotator as annotator_type, ha.nid as annotated_id, :annotated as annotated_type,
                   ha.variables AS status, FROM_UNIXTIME(ha.timestamp) as created_at, FROM_UNIXTIME(ha.timestamp) as updated_at
            FROM {heartbeat_activity} ha
            INNER JOIN {users} u ON u.uid = ha.uid
            WHERE ha.message_id = :message_id
            ';
  $query['params'] = array(':annotator' => 'User', ':annotated' => 'ProjectMedia', ':message_id' => 'status_report');
  if (count($options['story_ids'])) {
    $query['query'] .= ' AND ha.nid_target IN (:ids)';
    $query['params'][':ids'] = $options['story_ids'];
  }
  return $query;
}

function _checkdesk_export_build_query_flags($options) {
  $query = array();
  $query['query'] = '
            SELECT u.mail as annotator_id, :annotator as annotator_type, ha.nid as annotated_id, :annotated as annotated_type,
                   ha.variables AS flag, FROM_UNIXTIME(ha.timestamp) as created_at, FROM_UNIXTIME(ha.timestamp) as updated_at
            FROM {heartbeat_activity} ha
            INNER JOIN {users} u ON u.uid = ha.uid
            WHERE ha.message_id = :message_id
            ';
  $query['params'] = array(':annotator' => 'User', ':annotated' => 'ProjectMedia', ':message_id' => 'checkdesk_flag_report');
  if (count($options['story_ids'])) {
    $query['query'] .= ' AND ha.nid_target IN (:ids)';
    $query['params'][':ids'] = $options['story_ids'];
  }
  return $query;
}
