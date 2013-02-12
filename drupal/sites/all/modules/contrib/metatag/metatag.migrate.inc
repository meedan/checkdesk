<?php

/**
 * @file
 * Metatag support for migrate.
 */

/**
 * Implements hook_migrate_api().
 */
function metatag_migrate_api() {
  return array('api' => 2);
}

/**
 * Metatags destination handler.
 */
class MigrateMetatagHandler extends MigrateDestinationHandler {

  public function __construct() {
    $this->registerTypes(array('node', 'user', 'taxonomy_term'));
  }

  /**
   * Implements MigrateDestinationHandler::fields().
   */
  public function fields() {
    $fields = array();
    $elements = metatag_get_info();

    foreach ($elements['tags'] as $value) {
      $metatag_field = 'metatag_' . $value['name'];
      $fields[$metatag_field] = $value['description'];
    }

    return $fields;
  }

  /**
   * Implements MigrateDestinationHandler::prepare().
   */
  public function prepare($entity, stdClass $row) {
    $elements = metatag_get_info();

    foreach ($elements['tags'] as $value) {
      $metatag_field = 'metatag_' . $value['name'];
      if (isset($entity->$metatag_field)) {
        $entity->metatags[$value['name']]['value'] = $entity->$metatag_field;
        unset($entity->$metatag_field);
      }
    }
  }
}
