<?php
/**
 * @file
 * Meta Tags implementation of Entity Translation hooks.
 */

/**
 * Implements hook_entity_translation_insert().
 */
function metatag_entity_translation_insert($entity_type, $entity, $translation, $values = array()) {
  // The update hook can handle both cases so just call that one.
  metatag_entity_translation_update($entity_type, $entity, $translation, $values);
}

/**
 * Implements hook_entity_translation_update().
 */
function metatag_entity_translation_update($entity_type, $entity, $translation, $values = array()) {
  // Get the ID of the entity.
  list($entity_id) = entity_extract_ids($entity_type, $entity);

  // Grab the meta tag data only; we don't need anything else.
  $values = isset($values['metatags']) ? $values['metatags'] : array();

  // Set the default values to be that of the entity's original language (whose
  // tags are shown if the current language has none set) so that we can
  // extract these from the form elements if they haven't been changed.
  $entity_language = function_exists('entity_language') ?
    entity_language($entity_type, $entity) : $entity->language;
  if ($entity_language && isset($entity->metatags[$entity_language])) {
    $defaults = $entity->metatags[$entity_language];
  }
  else {
    $defaults = array();
  }

  // Remove all of the defaults.
  metatag_filter_values_from_defaults($values, $defaults);

  // Save the new data.
  metatag_metatags_save($entity_type, $entity_id, $values, $translation['language']);
}

/**
 * Implements hook_entity_translation_delete().
 */
function metatag_entity_translation_delete($entity_type, $entity, $langcode) {
  // Get the entity's ID.
  list($entity_id) = entity_extract_ids($entity_type, $entity);

  // Delete the translation.
  metatag_metatags_delete($entity_type, $entity_id, $langcode);
}
