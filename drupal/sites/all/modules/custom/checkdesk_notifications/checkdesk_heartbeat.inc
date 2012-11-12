<?php

/**
 * @file
 * Notifications list for a user 
 */

heartbeat_include('HeartbeatAccess');

/**
 * Class PublicHeartbeat
 * Concrete class to prepare messages for all
 * users in the site of whom the heartbeat is
 * set to public
 *
 */
class NotificationsList extends HeartbeatAccess {

  /**
   * Skip active user.
   * We never want to skip the active user. not for
   * logged-in user and not for displayed user (profile).
   * This is ofcourse because private stream is intended to
   * show own activity.
   */
  public function skipActiveUser() {
    return FALSE;
  }

  /**
   * prepareStream
   *
   * @param $text
   * @return HeartbeatParser object
   */
  protected function prepareStream() {
    global $user, $language;
    $this->stream->offset_sql = $this->_offset_sql;

    // Prevent already assigned language to be overriden
    if (empty($this->stream->language)) {
      $this->stream->language = $language->language;
    }

    db_query('SELECT  * from {heartbeat_activity}');

    // Calls with an offset uaid will fetch newer messages
    if ($this->stream->latest_uaid > 0) {
      $this->stream->sql_start .= "AND (ua.uaid > %d ) ";
    }
    else {
      $this->stream->sql_start .= "AND (ua.timestamp < %d ";

      // Add sql to delete too old messages if set
      if ($this->stream->oldest_date) {
        $this->stream->sql_start .= "AND ua.timestamp > %d ";
      }
      $this->stream->sql_start .= ")";
    }

    $this->checkDeniedMessages();

    $heartbeat = $this->createHeartbeatParser();

    return $heartbeat;
  }

  /**
   * Implementation of dressUpMessages().
   *
   * @param object HeartbeatParser $heartbeat
   *   The heartbeat parser object
   * @return object HeartbeatParser $heartbeat
   */
  public function dressUpMessages(HeartbeatParser $heartbeat) {
    $heartbeat->raw_messages = $this->resultSql();
    return $heartbeat;
  }

  /**
   * Function to add a part of a sql to a query built by views.
   * @param object $view
   *   The view handler object by reference to add our part to the query
   */
  public function addViewQuery(&$view) {
    // We don't use it as view
  }
}
