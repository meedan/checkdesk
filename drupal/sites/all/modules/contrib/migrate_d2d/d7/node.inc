<?php
/**
 * @file
 * Implementation of DrupalNodeMigration for Drupal 7 sources.
 */

/**
 * Handling specific to a Drupal 7 source for nodes.
 */
class DrupalNode7Migration extends DrupalNodeMigration {
  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);

    $this->addFieldMapping('language', 'language')
         ->defaultValue($this->defaultLanguage);

    $this->addFieldMapping('body:summary', 'body:summary');
    $this->addFieldMapping('body:format', 'body:format')
         ->callbacks(array($this, 'mapFormat'));

    /** @todo Prevent stub creation when tnid == 0
    $this->addFieldMapping('tnid', 'tnid', FALSE)
         ->sourceMigration($arguments['machine_name']);
     */
    $this->addFieldMapping('tnid', NULL);
    $this->addFieldMapping(NULL, 'tnid');

    $this->addFieldMapping('translate', 'translate');

  }

  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('node', 'n')
             ->fields('n', array('nid', 'vid', 'language', 'title', 'uid',
               'status', 'created', 'changed', 'comment', 'promote', 'sticky',
               'tnid', 'translate'))
             ->condition('type', $this->sourceType)
             ->orderBy('changed');
    return $query;
  }
}
