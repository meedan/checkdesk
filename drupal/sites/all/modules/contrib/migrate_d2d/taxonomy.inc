<?php
/**
 * @file
 * Base class for migrating taxonomy terms into Drupal.
 */

/**
 * Base class for migrations of Drupal taxonomy terms from another Drupal
 * installation.
 */
abstract class DrupalTermMigration extends DrupalMigration {
  /**
   * The machine name, or vocabulary ID (pre-D7), of the vocabulary we're
   * migrating from.
   *
   * @var mixed
   */
  protected $sourceVocabulary;

  /**
   * The machine name of the Drupal 7 vocabulary we're migrating into.
   *
   * @var string
   */
  protected $destinationVocabulary;


  /**
   * In addition to the arguments supported by DrupalMigration, we add the
   * following required arguments:
   *
   * source_vocabulary - Unique identifier for the source vocabulary (a vid
   *   through Drupal 6, machine name for Drupal 7 and later). This may be a
   *   comma-separated list, to support merging multiple vocabularies into one.
   * destination_vocabulary - Machine name of the destination vocabulary.
   *
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    $this->sourceVocabulary = $arguments['source_vocabulary'];
    $this->destinationVocabulary = $arguments['destination_vocabulary'];
    $this->sourceFields += $this->version->getSourceFields(
      'taxonomy_term', $this->sourceVocabulary);
    if ($this->moduleExists('path')) {
      $this->sourceFields['path'] = array('label' => t('Node: Path alias'));
    }

    // Create our three main objects - source, destination, and map
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->destination = new MigrateDestinationTerm($this->destinationVocabulary);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'tid' => array('type' => 'int',
                       'unsigned' => TRUE,
                       'not null' => TRUE,
                       'description' => 'Source term ID',
                      ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // Mappings are straight-forward
    $this->addSimpleMappings(array('name', 'description', 'weight'));
    $this->addFieldMapping('parent', 'parent')
         ->sourceMigration($this->machineName);

    $this->addUnmigratedDestinations(array('parent_name'));

    if ($this->moduleExists('path')) {
      $this->addFieldMapping('path', 'path')
           ->description('Handled in prepareRow');
    }

    if (module_exists('pathauto')) {
      $this->addFieldMapping('pathauto')
           ->description('By default, disable in favor of migrated paths')
           ->defaultValue(0);
    }
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

    // Add the path to the source row, if relevant
    if ($this->moduleExists('path')) {
      $path = $this->version->getPath('taxonomy/term/' . $row->tid);
      if ($path) {
        $row->path = $path;
      }
    }
    return TRUE;
  }
}
