<?php

/**
 * @file
 * Handler for the 'Node: last edited by' field.
 */

class revisioning_handler_field_node_last_editor extends views_handler_field {

  /**
   * Call constructor.
   */
  public function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  /**
   * Check for access.
   */
  public function access() {
    return user_access('access content');
  }

  /**
   * Help build the query.
   */
  public function query() {
    // Not calling parent::query() as it will treat 'last_editor' as a real db
    // field.
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * Render data.
   */
  public function render($values) {
    $nid = $values->{$this->aliases['nid']};
    $uid = revisioning_get_last_editor($nid, FALSE);
    $account = user_load($uid);
    return $account->name;
  }
  /*
   * Consider this performance improvement from [#1852680].
   * Not tested.
   *
    function pre_render($values) {
    // Collect Nodes
    $nids = array();
    foreach ($values as $row) {
      $nids[] = $row->{$this->aliases['nid']};
    }

    // If the view has no results, there is no last editor to determine.
    if (empty($nids)) {
      return;
    }

    // Get newest revisions for nodes.
    $sql = "SELECT MAX(vid) AS vid, nid FROM {node_revision} WHERE nid IN (:nids) GROUP BY nid";
    $result = db_query($sql, array(':nids' => $nids));
    $vids = array();
    while($vid = $result->fetchAssoc()) {
      $vids[] = $vid['vid'];
    }

    if (empty($vids)) {
      return;
    }

    // Get author name oft the revisions.
    $result = db_query("SELECT node_revision.nid, users.name FROM {node_revision} JOIN {users} ON node_revision.uid=users.uid WHERE node_revision.vid IN (:vids)", array(':vids' => $vids));
    while($revision = $result->fetchAssoc()) {
      $this->uids[$revision['nid']] = $revision['name'];
    }
  }

  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    return isset($this->uids[$nid])? $this->uids[$nid] : '';
  }
  */
}
