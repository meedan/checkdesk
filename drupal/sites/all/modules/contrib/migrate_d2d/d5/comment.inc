<?php
/**
 * @file
 * Implementation of DrupalCommentMigration for Drupal 5 sources.
 */

/**
 * Handling specific to a Drupal 5 source for comments.
 */
class DrupalComment5Migration extends DrupalCommentMigration {

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->highwaterField = array(
      'name' => 'timestamp',
      'alias' => 'c',
      'type' => 'int',
    );

    // Version-specific field mappings
    $this->addFieldMapping('comment_body', 'comment');
    $this->addFieldMapping('comment_body:format', 'format')
         ->callbacks(array($this, 'mapFormat'));

    $this->addFieldMapping('created', 'timestamp');
    $this->addFieldMapping('changed', 'timestamp');
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
          ->orderBy('timestamp');

    return $query;
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
