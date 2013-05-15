<?php

class CraneUserMigration extends DrupalUser6Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->removeFieldMapping('mail');
    $this->addFieldMapping('mail', 'mail');
  }

  public function prepareRow($row) {
    $uid = db_query("SELECT uid FROM {users} WHERE mail = :mail", array(':mail' => $row->mail))->fetchField();
    // Skip this row if e-mail is already registered
    if ($uid) {
      return FALSE;
    }
    // Assign journalist role
    $query = "SELECT rid FROM {role} WHERE name = 'journalist'";
    $new_rid = db_query($query)->fetchField();
    $old_rid = Database::getConnection('default', $this->sourceConnection)->query($query)->fetchField();
    $result = Database::getConnection('default', $this->sourceConnection)
              ->select('users_roles', 'ur')
              ->fields('ur', array('rid'))
              ->condition('uid', $row->uid)
              ->execute();
    foreach ($result as $role_row) {
      if ($role_row->rid == $old_rid) {
        $row->roles[] = $new_rid;
      }
    }
    return TRUE;
  }
}
