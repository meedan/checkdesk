<?php
/**
 * @file
 * Implementation of DrupalEntityMigration for Drupal 6 sources.
 */

/**
 * Handling specific to a Drupal 6 node source for entities.
 */
class DrupalEntity6Migration extends DrupalEntityMigration {
  /**
   * Translation from field names assigned when executing the query to our
   * subfield notation.
   *
   * @var array
   *  key: DB-compatible name (e.g., field_buy_link_title).
   *  value: Subfield notation (e.g., field_buy_link:title).
   */
  protected $fixFieldNames = array();

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $query = $this->query();

    $this->sourceOptions['fix_field_names'] = $this->fixFieldNames;

    $this->source = new MigrateDrupal6SourceSQL($query, $this->sourceFields, NULL,
      $this->sourceOptions);

    $this->addUnmigratedSources(array(
      'format',
      'language',
      'teaser',
      'tnid',
      'translate',
    ));
  }

  /**
   * Query for basic node fields from Drupal 6.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('node', 'n')
             ->fields('n', array('nid', 'vid', 'language', 'title',
                 'uid', 'status', 'created', 'changed', 'comment', 'promote',
                 'moderate', 'sticky', 'tnid', 'translate'))
             ->condition('type', $this->sourceType)
             ->orderBy('changed');
    $query->innerJoin('node_revisions', 'nr', 'n.vid=nr.vid');
    $query->fields('nr', array('body', 'teaser', 'format'));
    // Pick up simple CCK fields
    $cck_table = 'content_type_' . $this->sourceType;
    if (Database::getConnection('default', $this->sourceConnection)
          ->schema()->tableExists($cck_table)) {
      $query->leftJoin($cck_table, 'f', 'n.vid=f.vid');
      // The main column for the field should be rendered with
      // the field name, not the column name (e.g., field_foo rather
      // than field_foo_value).
      $field_info = $this->version->getSourceFieldInfo();
      foreach ($field_info as $field_name => $info) {
        if (isset($info['columns']) && !$info['multiple'] && $info['db_storage']) {
          $i = 0;
          foreach ($info['columns'] as $display_name => $column_name) {
            if ($i++ == 0) {
              $query->addField('f', $column_name, $field_name);
            }
            else {
              // The database API won't allow colons in column aliases, so we
              // will accept the default alias, and fix up the field names later.
              // Remember how to translate the field names.
              $clean_name = str_replace(':', '_', $display_name);
              $this->fixFieldNames[$clean_name] = $display_name;
              $query->addField('f', $column_name);
            }
          }
        }
      }
    }
    return $query;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // Convert the default field names to the nice-looking ones.
    foreach ($this->fixFieldNames as $clean => $display) {
      if (isset($row->$clean)) {
        $row->$display = $row->$clean;
        unset($row->$clean);
      }
    }
  }
}
