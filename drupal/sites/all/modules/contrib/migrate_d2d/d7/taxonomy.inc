<?php
/**
 * @file
 * Implementation of DrupalTermMigration for Drupal 7 sources.
 */

class DrupalTerm7Migration extends DrupalTermMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addFieldMapping('format', 'format')
         ->callbacks(array($this, 'mapFormat'));
  }

  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('taxonomy_term_data', 'td')
             ->fields('td', array('tid', 'name', 'description', 'weight', 'format'))
             ->orderBy('th.parent')
             ->distinct();
    // Join to the hierarchy so we can sort on parent, but we'll pull the
    // actual parent values in separately in case there are multiples.
    $query->leftJoin('taxonomy_term_hierarchy', 'th', 'td.tid=th.tid');
    $query->innerJoin('taxonomy_vocabulary', 'v', 'td.vid=v.vid');
    $query->condition('v.machine_name', array($this->sourceVocabulary), 'IN');
    return $query;
  }

  /**
   * Review a data row after fetch, returning FALSE to skip it.
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Add the (potentially multiple) parents.
    $result = Database::getConnection('default', $this->sourceConnection)
      ->select('taxonomy_term_hierarchy', 'th')
      ->fields('th', array('parent'))
      ->condition('tid', $row->tid)
      ->execute();
    $row->parent = array();
    foreach ($result as $parent_row) {
      $row->parent[] = $parent_row->parent;
    }

    $this->version->getSourceValues($row, $row->tid);
    return TRUE;
  }
}
