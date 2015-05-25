<?php
/**
 * @file
 * Implementation of DrupalRoleMigration for Drupal 7 sources.
 */

/**
 * Handling specific to a Drupal 7 source for roles.
 */
class DrupalRole7Migration extends DrupalRoleMigration {
  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->addSimpleMappings(array('weight'));
  }
}
