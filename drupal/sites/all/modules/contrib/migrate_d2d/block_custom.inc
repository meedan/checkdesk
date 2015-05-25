<?php
/**
 * @file
 * Base class for migrating custom blocks into Drupal.
 */

/*
 * Base class for all custom block migrations - handles commonalities across
 * all supported source Drupal versions.
 */
abstract class DrupalCustomBlockMigration extends DrupalMigration {
  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Create our three main objects - source, destination, and map
    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->destination = new MigrateDestinationCustomBlock();

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'bid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => "The block's {block}.bid.",
        ),
      ),
      MigrateDestinationCustomBlock::getKeySchema()
    );

    // The mappings are straightforward
    $this->addSimpleMappings(array('body', 'info'));
    $this->addFieldMapping('format', 'format')->callbacks(array($this, 'mapFormat'));
  }
}
