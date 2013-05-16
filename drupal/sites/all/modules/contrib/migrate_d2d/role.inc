<?php
/**
 * @file
 * Base class for migrating roles into Drupal.
 */

/**
 * Base class for all role migrations - handles commonalities across all
 * supported source Drupal versions.
 */
abstract class DrupalRoleMigration extends DrupalMigration {
  /**
   * Allow the implementor to map roles by name (e.g., map the legacy "Fan Club"
   * role to the destination "fan club member" role).
   *
   * @var array
   */
  protected $roleMappings = array();

  /**
   * @param array $arguments
   * role_mappings - Array keyed by the legacy role name, with the destination
   *  role name as the value.
   */
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    if (!empty($arguments['role_mappings'])) {
      $this->roleMappings = $arguments['role_mappings'];
    }

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields,
      NULL, $this->sourceOptions);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'rid' => array('type' => 'int',
                       'unsigned' => TRUE,
                       'not null' => TRUE,
                       'description' => 'Source role ID',
                      ),
      ),
      MigrateDestinationRole::getKeySchema()
    );

    $this->destination = new MigrateDestinationRole();

    $this->addSimpleMappings(array('name'));
  }

  /**
   * Query for the basic role data.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    // Do not attempt to migrate the anonymous or authenticated roles.
    $query = Database::getConnection('default', $this->sourceConnection)
             ->select('role', 'r')
             ->fields('r')
             ->condition('rid', 2, '>');
    return $query;
  }

  /**
   * Apply any role mappings
   *
   * @param $row
   * @return bool
   */
  public function prepare($role, $row) {
    if (isset($this->roleMappings[$role->name])) {
      $destination_name = $this->roleMappings[$role->name];
      $destination_rid = db_select('role', 'r')
                         ->fields('r', array('rid'))
                         ->condition('name', $destination_name)
                         ->execute()
                         ->fetchField();
      if ($destination_rid) {
        $role->rid = $destination_rid;
        // Make sure we don't change the destination name
        $role->name = $destination_name;
        $this->rollbackAction = MigrateMap::ROLLBACK_PRESERVE;
      }
    }
  }
}
