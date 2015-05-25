<?php
/**
 * @file
 * Implementation of DrupalCustomBlockMigration for Drupal 5 sources.
 */

/*
 * Class for custom block migrations: from {boxes} into {block_custom}.
 * Dependent on this patch for Migrate:
 * https://drupal.org/node/2224297
 */
class DrupalCustomBlock5Migration extends DrupalCustomBlockMigration {
  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }

  /**
   * Query for the basic custom block data.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('boxes', 'b')
             ->fields('b');
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
