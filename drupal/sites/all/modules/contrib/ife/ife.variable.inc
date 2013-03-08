<?php

/**
 * Implements hook_variable_info().
 */
function ife_variable_info($options) {
  $variables = array();

  $variables['ife_general_message'] = array(
    'title' => t('Inline form errors alternate error message', array(), $options),
    'description' => t('A general error message to display at the top of the page (default Drupal messages display).', array(), $options),
    'type' => 'string',
    'default' => t('Please correct all highlighted errors and try again.', array(), $options),
    'localize' => TRUE,
  );

  return $variables;
}
