<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t("Entity is flagged"),
  'description' => t('Control access by whether or not an entity is flagged.'),
  'callback' => 'flag_flag_is_flagged_access_check',
  'default' => array('flag_name' => ''),
  'settings form' => 'flag_flag_is_flagged_access_settings',
  'summary' => 'flag_flag_is_flagged_access_summary',
  'get child' => 'flag_flag_is_flagged_access_get_child',
  'get children' => 'flag_flag_is_flagged_access_get_children',
);

/*
 * Implements plugin get_child callback.
 */
function flag_flag_is_flagged_access_get_child($plugin, $parent, $child) {
  $plugins = flag_flag_is_flagged_access_get_children($plugin, $parent);
  return $plugins[$parent . ':' . $child];
}

/*
 * Implements plugin get_children callback.
 */
function flag_flag_is_flagged_access_get_children($plugin, $parent) {
  $plugins = array();
  $entities = entity_get_info();

  foreach ($entities as $entity_type => $info) {
    if (entity_type_supports($entity_type, 'view')) {
      $plugin['title'] =  t('@entity_type is flagged', array('@entity_type' => $info['label']));
      $plugin['keyword'] = $entity_type;
      $plugin['name'] = $parent . ':' . $entity_type;
      $plugin['required context'] = new ctools_context_required(t('Entity'), $entity_type);
      $plugins[$parent . ':' . $entity_type] = $plugin;
    }
  }

  return $plugins;
}

/**
 * Settings form.
 */
function flag_flag_is_flagged_access_settings(&$form, &$form_state, $conf) {
  $options = array();

  $plugin = $form_state['plugin'];
  $entity_type = explode(':', $plugin['name']);
  $entity_type = $entity_type[1];

  foreach (flag_get_flags($entity_type) as $flag) {
    $options[$flag->name] = check_plain($flag->title);
  }

  $form['settings']['flag_name'] = array(
    '#title' => t('Flag name'),
    '#type' => 'radios',
    '#options' => $options,
    '#description' => t('Include only flagged content.'),
    '#default_value' => $conf['flag_name'],
  );
  return $form;
}

/**
 * Check for access.
 */
function flag_flag_is_flagged_access_check($conf, $context) {
  $flag = flag_get_flag($conf['flag_name']);
  if (!$flag || empty($context->data)) {
    return FALSE;
  }

  // Get the ID of the entity.
  list($id) = entity_extract_ids($flag->entity_type, $context->data);

  return $flag->is_flagged($id);
}

/**
 * Provide a summary description based upon the specified context
 */
function flag_flag_is_flagged_access_summary($conf, $context) {
  $flag = flag_get_flag($conf['flag_name']);

  if ($flag) {
    return t('@identifier is flagged with "@flag"', array('@flag' => check_plain($flag->title), '@identifier' => $context->identifier));
  }
  else {
    return t('Missing/ deleted flag "@flag"', array('@flag' => $conf['flag_name']));
  }
}
