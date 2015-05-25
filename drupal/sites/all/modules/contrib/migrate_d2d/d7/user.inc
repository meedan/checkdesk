<?php
/**
 * @file
 * Implementation of DrupalUserMigration for Drupal 7 sources.
 */

class DrupalUser7Migration extends DrupalUserMigration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->destination = new DrupalDestinationUser();
  }

  /**
   * Implementation of Migration::complete().
   *
   * @param $account
   * @param $row
   */
  public function complete($account, $row) {
    parent::complete($account, $row);

    // The incoming password was encrypted - user_save added an extra round of
    // encryption, we need to replace that with the original encrypted value.
    $account->pass = $row->pass;
    db_update('users')
      ->fields(array('pass' => $account->pass))
      ->condition('uid', $account->uid)
      ->execute();
  }
}
