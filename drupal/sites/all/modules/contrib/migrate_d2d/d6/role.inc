<?php
/**
 * @file
 * Implementation of DrupalRoleMigration for Drupal 6 sources.
 */

/**
 * Handling specific to a Drupal 6 source for roles.
 */
class DrupalRole6Migration extends DrupalRoleMigration {
  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addUnmigratedDestinations(array('weight'));
  }
}
