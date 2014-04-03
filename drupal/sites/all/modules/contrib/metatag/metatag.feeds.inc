<?php
/**
 * @file
 * Feeds mapping implementation for the Metatag module.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 */
function metatag_feeds_processor_targets_alter(&$targets, $entity_type, $bundle) {
  if (metatag_entity_supports_metatags($entity_type)) {
    $info = metatag_get_info();
    foreach ($info['tags'] as $name => $tag) {
      $targets['meta_' . $name] = array(
        'name' => 'Meta tag: ' . check_plain($tag['label']),
        'callback' => 'metatag_feeds_set_target',
        'description' => $tag['description'],
      );
    }
  }
}

/**
 * Callback function to set value of a metatag tag.
 */
function metatag_feeds_set_target($source, $entity, $target, $value) {
  // Don't do anything if we weren't given any data.
  if (empty($value)) {
    return;
  }

  // Strip the prefix that was added above.
  $name = str_replace('meta_', '', $target);

  // Load full metatag object if exists and has not been already loaded.
  if (!isset($entity->metatags) && !empty($entity->feeds_item->entity_id) && is_numeric($entity->feeds_item->entity_id)) {
    $entity_type = $entity->feeds_item->entity_type;
    $entity_id = $entity->feeds_item->entity_id;
    $entities = entity_load($entity_type, array($entity_id));
    if (!empty($entities)) {
      $stored_entity = reset($entities);
      $metatags = metatag_metatags_load($entity_type, $entity_id);
      if (!empty($stored_entity) && !empty($metatags)) {
        $stored_entity_language = metatag_entity_get_language($entity_type, $stored_entity);
        $entity->metatags = isset($metatags[$stored_entity_language]) ? $metatags[$stored_entity_language] : array();
      }
    }
  }

  // Assign the value.
  $entity->metatags[$name]['value'] = $value;
}

