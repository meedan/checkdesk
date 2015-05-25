<?php
/**
 * @file
 * Implementation of DrupalCommentMigration for Drupal 6 sources.
 */

/**
 * Handling specific to a Drupal 6 source for comments.
 */
class DrupalComment6Migration extends DrupalCommentMigration {

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'timestamp',
        'alias' => 'c',
        'type' => 'int',
      );
    }

    // Version-specific field mappings
    $this->addFieldMapping('comment_body', 'comment');
    $this->addFieldMapping('comment_body:format', 'format')
         ->callbacks(array($this, 'mapFormat'));
    $this->addFieldMapping('created', 'timestamp');
    $this->addFieldMapping('changed', 'timestamp');
    $this->addFieldMapping('status', 'status')
         ->callbacks(array($this, 'handleStatus'));

    $this->addUnmigratedDestinations(array('language', 'comment_body:language'));
  }

  /**
   * Implementation of DrupalCommentMigration::query().
   *
   * We join to {node} so that we can use separate comment migration classes
   * for each associated node type.
   *
   * @return SelectQueryInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('comments', 'c')
             ->fields('c', array('cid', 'pid', 'nid', 'uid', 'subject',
               'comment', 'hostname', 'timestamp', 'status', 'thread', 'name',
               'mail', 'homepage', 'format'));
    $query->join('node', 'n', 'c.nid = n.nid');
    $query->condition('n.type', $this->sourceType)
          ->orderBy($this->newOnly ? 'c.cid' : 'c.timestamp');

    return $query;
  }

  /**
   * Default status flag values flipped in D7. Non-standard statuses are kept.
   *
   * @param $value
   *
   * @return int
   */
  protected function handleStatus($value) {
    if ($value == 0) {
      return 1;
    }
    elseif ($value == 1) {
      return 0;
    }
    else {
      return $value;
    }
  }

  /**
   * Implementation of Migration::prepareRow().
   *
   * @param $row
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
  }
}
