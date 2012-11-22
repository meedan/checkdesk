<?php

/**
 * @file
 *   Contains the flag_entity class.
 */

/**
 * Base entity flag handler.
 */
class flag_entity extends flag_flag {
  /**
   * Adds additional options that are common for all entity types.
   */
  function options() {
    $options = parent::options();
    $options += array(
      // Output the flag in the entity links.
      // @see hook_entity_view().
      'show_on_entity' => TRUE,
      // Add a checkbox for the flag in the entity form.
      // @see hook_field_attach_form().
      'show_on_form' => FALSE,
      'access_author' => '',
      'show_contextual_link' => FALSE,
    );
    return $options;
  }

  /**
   * Options form extras for the generic entity flag.
   */
  function options_form(&$form) {
    $bundles = array();
    $entity_info = entity_get_info($this->entity_type);
    foreach ($entity_info['bundles'] as $bundle_key => $bundle) {
      $bundles[$bundle_key] = check_plain($bundle['label']);
    }
    $form['access']['types'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Bundles'),
      '#options' => $bundles,
      '#description' => t('Select the bundles that this flag may be used on. Leave blank to allow on all bundles for the entity type.'),
      '#default_value' => $this->types,
    );
    // Handlers may want to unset this option if they provide their own more
    // specific ways to show links.
    $form['display']['show_on_entity'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display link on entity'),
      '#default_value' => isset($this->show_on_entity) ? $this->show_on_entity : TRUE,
    );
    $form['display']['show_on_form'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display checkbox on entity edit form'),
      '#default_value' => $this->show_on_form,
    );
    $form['display']['show_contextual_link'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display in contextual links'),
      '#default_value' => $this->show_contextual_link,
      '#description' => t('Note that not all entity types support contextual links.'),
      '#access' => module_exists('contextual'),
    );
  }

  /**
   * Loads the entity object.
   */
  function _load_entity($entity_id) {
    if (is_numeric($entity_id)) {
      $entity = entity_load($this->entity_type, array($entity_id));
      return reset($entity);
    }
    return NULL;
  }

  /**
   * Checks whether the flag applies for the current entity bundle.
   */
  function applies_to_entity($entity) {
    $entity_info = entity_get_info($this->entity_type);
    // The following conditions are applied:
    // - if the types array is empty, the flag applies to all bundles and thus
    //   to this entity.
    // - if the entity has no bundles, the flag applies to the entity.
    // - if the entity's bundle is in the list of types.
    if (empty($this->types) || empty($entity_info['entity keys']['bundle']) || in_array($entity->{$entity_info['entity keys']['bundle']}, $this->types)) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Provides permissions for this flag.
   *
   * @return
   *  An array of permissions for hook_permission().
   */
  function get_permissions() {
    // For entity flags, use the human label of the entity.
    $entity_info = entity_get_info($this->entity_type);
    $entity_label = $entity_info['label'];
    return array(
      "flag $this->name" => array(
        'title' => t('Flag %entity entities as %flag_title', array(
          '%flag_title' => $this->title,
          '%entity' => $entity_label,
        )),
      ),
      "unflag $this->name" => array(
        'title' => t('Unflag %entity entities as %flag_title', array(
          '%flag_title' => $this->title,
          '%entity' => $entity_label,
        )),
      ),
    );
  }

  /**
   * Returns the entity id, if it already exists.
   */
  function get_entity_id($entity) {
    $entity_info = entity_get_info($this->entity_type);
    if ($entity && isset($entity->{$entity_info['entity keys']['id']})) {
      return $entity->{$entity_info['entity keys']['id']};
    }
  }

  /**
   * Returns TRUE if the link should be displayed.
   */
  function uses_hook_link($teaser) {
    if ($this->show_on_entity) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Returns token types for the current entity type.
   */
  function get_labels_token_types() {
    // The token type name might be different to the entity type name. If so,
    // an own flag entity handler can be used for overriding this.
    return array_merge(array($this->entity_type), parent::get_labels_token_types());
  }

  /**
   * Replaces tokens.
   */
  function replace_tokens($label, $contexts, $options, $entity_id) {
    if ($entity_id && ($entity = $this->fetch_entity($entity_id))) {
      $contexts[$this->entity_type] = $entity;
    }
    return parent::replace_tokens($label, $contexts, $options, $entity_id);
  }

  /**
   * Returns a 'flag action' object.
   */
  function get_flag_action($entity_id) {
    $flag_action = parent::get_flag_action($entity_id);
    $entity = $this->fetch_entity($entity_id);
    $flag_action->content_title = entity_label($this->entity_type, $entity);
    $flag_action->content_url = _flag_url($this->entity_type . '/' . $this->get_entity_id($entity));
    return $flag_action;
  }

  /**
   * Returns objects the action may possible need.
   */
  function get_relevant_action_objects($entity_id) {
    return array(
      $this->entity_type => $this->fetch_entity($entity_id),
    );
  }

  /**
   * Returns information for the Views integration.
   */
  function get_views_info() {
    $entity_info = entity_get_info($this->entity_type);
    return array(
      'views table' => $entity_info['base table'],
      'join field' => $entity_info['entity keys']['id'],
      'title field' => isset($entity_info['entity keys']['label']) ? $entity_info['entity keys']['label'] : '',
      'title' => t('@entity_label flag', array('@entity_label' => $entity_info['label'])),
      'help' => t('Limit results to only those entity flagged by a certain flag; Or display information about the flag set on a entity.'),
      'counter title' => t('@entity_label flag counter', array('@entity_label' => $entity_info['label'])),
      'counter help' => t('Include this to gain access to the flag counter field.'),
    );
  }
}
