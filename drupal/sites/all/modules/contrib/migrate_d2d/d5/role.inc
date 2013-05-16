<?php
/**
 * @file
 * Implementation of DrupalRoleMigration for Drupal 5 sources.
 */

/**
 * Handling specific to a Drupal 5 source for roles.
 */
class DrupalRole5Migration extends DrupalRoleMigration {
  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addUnmigratedDestinations(array('weight'));
  }
}
