<?php
/**
 * @file
 * Contains hook implementations for Views.
 */

/**
 * Implementation of hook_views_plugins()
 */
function views_composite_exposed_form_views_plugins() {
  return array(
    'exposed_form' => array(
      'composite' => array(
        'title' => t('Composite'),
        'help' => t('Allows multiple exposed form plugins to be activated simultaneously.'),
        'handler' => 'views_composite_exposed_form_plugin',
        'uses row plugin' => FALSE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'parent' => 'basic',
      ),
    ),
  );
}

