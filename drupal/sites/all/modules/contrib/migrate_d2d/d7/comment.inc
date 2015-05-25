<?php
/**
 * @file
 * Implementation of DrupalCommentMigration for Drupal 7 sources.
 */

/**
 * Handling specific to a Drupal 7 source for comments.
 */
class DrupalComment7Migration extends DrupalCommentMigration {

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'changed',
        'alias' => 'c',
        'type' => 'int',
      );
    }

    // Version-specific field mappings
    $this->addSimpleMappings(array('comment_body', 'created', 'changed',
                               'status', 'language'));
    $this->addFieldMapping('comment_body:format', 'comment_body:format')
         ->callbacks(array($this, 'mapFormat'));
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
             ->select('comment', 'c')
             ->fields('c', array('cid', 'pid', 'nid', 'uid', 'subject',
               'hostname', 'created', 'changed', 'status', 'thread', 'name',
               'mail', 'homepage', 'language'));
    $query->join('node', 'n', 'c.nid = n.nid');
    $query->condition('n.type', $this->sourceType)
          ->orderBy('c.changed');

    return $query;
  }

  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with the CCK fields.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $this->version->getSourceValues($row, $row->cid);
  }
}
