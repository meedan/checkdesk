<?php
/**
 * @file
 * Base class for migrating nodes into Drupal custom entities.
 */

/**
 * Base class for all non-standard entity migrations - handles commonalities
 * across all supported source Drupal versions.
 *
 * In addition to the arguments supported by DrupalMigration, the following
 * must be passed in the $arguments array:
 *
 * source_type - Drupal 6 content type machine name.
 * destination_entity_type - Drupal 7 entity type machine name.
 * destination_bundle - Drupal 7 bundle machine name.
 *
 * The following optional argument may be passed:
 *
 * default_language - Default language for the node and node body. Defaults
 *   to LANGUAGE_NONE.
 */
abstract class DrupalEntityMigration extends DrupalMigration {
  /**
   * The source node type.
   *
   * @var string
   */
  protected $sourceType;

  /**
   * The destination entity type.
   *
   * @var string
   */
  protected $entityType;

  /**
   * The destination bundle.
   *
   * @var string
   */
  protected $bundle;

  /**
   * Default language to apply to the entity.
   *
   * @var string
   */
  protected $defaultLanguage = LANGUAGE_NONE;

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $this->entityType = $arguments['destination_entity_type'];
    $this->bundle = $arguments['destination_bundle'];
    if (!empty($arguments['default_language'])) {
      $this->defaultLanguage = $arguments['default_language'];
    }
    parent::__construct($arguments);
    $this->sourceFields += $this->version->getSourceFields('node', $this->sourceType);

    $this->destination = new MigrateDestinationEntityAPI($this->entityType,
      $this->bundle, array('language' => $this->defaultLanguage));

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array('type' => 'int',
                       'unsigned' => TRUE,
                       'not null' => TRUE,
                       'description' => 'Source node ID',
                       'alias' => 'n',
                      ),
      ),
      MigrateDestinationEntityAPI::getKeySchema($this->entityType)
    );

    if (!$this->newOnly) {
      $this->highwaterField = array(
        'name' => 'changed',
        'alias' => 'n',
        'type' => 'int',
      );
    }

    // Ignore by default
    $this->addUnmigratedSources(array(
      'body',
      'changed',
      'comment',
      'created',
      'moderate',
      'promote',
      'status',
      'sticky',
      'uid',
      'vid',
    ));
  }

  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with the CCK fields.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $this->version->getSourceValues($row, $row->nid);
  }
}
