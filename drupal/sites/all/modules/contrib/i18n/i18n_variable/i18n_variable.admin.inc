<?php
/**
 * @file
 * Administration pages for multilingual variables. Internationalization (i18n) package.
 */

/**
 * Select multilingual variables
 *
 * There are two lists of variables here.
 * - i18n_variable_conf, list with high level variable names, some of which are multiple variables
 * - i18n_variable_list, translated list into actual variable names
 *
 * Aditional variables to be make translatable can be set into $conf['i18n_variables'] as for older versions
 */
function i18n_variable_admin_settings($form, $form_state) {
  $translatable = array();
  $current = variable_get('i18n_variable_conf', array());
  $conf = variable_get('i18n_variables', array());
  foreach (variable_get_info() as $name => $variable) {
    if (!empty($variable['localize']) || in_array($name, $conf)) {
      $translatable[] = $name;
    }
  }
  // The final list will be the sum of both lists. We may have unknown variables we want to preserve.
  $list = array_unique(array_merge($translatable, $current));
  $form['variables'] = array(
    '#type' => 'fieldset',
    '#title' => t('Select variables to be translated'),
    '#theme' => 'variable_table_select',
    '#tree' => TRUE,
  );
  foreach ($list as $name) {
    // Variable names may clash with form element names, so we need to replace '[' and ']'
    $safename = str_replace(array('[', ']'), array('<', '>'), $name);
    $form['variables'][$safename] = array(
      '#type' => 'checkbox',
      '#default_value' => in_array($name, $current),
      '#variable_name' => $name,
    );
  }
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Save configuration'));
  return $form;
}

/**
 * Handle form submission.
 */
function i18n_variable_admin_settings_submit($form, $form_state) {
  // Get main variable names
  $variables = $form_state['values']['variables'];
  $variables = array_keys(array_filter($variables));
  // Translate variable names
  foreach ($variables as $index => $name) {
    $variables[$index] = str_replace(array('<', '>'), array('[', ']'), $name);
  }
  variable_set('i18n_variable_conf', $variables);
  // Spawn multiple variables and translate into actual variables
  $new_list = variable_children($variables);
  variable_set('i18n_variable_list', $new_list);
  // Delete variables from store that are not in the new list.
  $old_list = variable_store_list_all('language', NULL);
  foreach (array_diff($old_list, $new_list) as $name) {
    variable_store_delete_all('language', NULL, $name);
    drupal_set_message(t('Deleted existing values of %name from multilingual variables.', array('%name' => $name)));
  }
}