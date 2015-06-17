<?php

/**
 * @file
 * Redis module administration pages.
 */

/**
 * Main settings and review administration screen.
 */
function redis_settings_form($form, &$form_state) {

  $form['connection'] = array(
    '#type' => 'fieldset',
    '#title' => t("Connection information"),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['connection']['scheme'] = array(
    '#type' => 'textfield',
    '#title' => t("Scheme"),
    '#default_value' => 'tcp',
    '#disabled' => TRUE,
    '#description' => t("Connection scheme.") . " " . t("Only <em>tcp</em> is currently supported. This is ignored when using a UNIX socket."),
  );
  $form['connection']['redis_client_host'] = array(
    '#type' => 'textfield',
    '#title' => t("Host"),
    '#default_value' => variable_get('redis_client_host', NULL),
    '#description' => t("Redis server host. Default is <em>@default</em>.", array('@default' => Redis_Client::REDIS_DEFAULT_HOST)),
  );
  $form['connection']['redis_client_port'] = array(
    '#type' => 'textfield',
    '#title' => t("Port"),
    '#default_value' => variable_get('redis_client_port', NULL),
    '#description' => t("Redis server port. Default is <em>@default</em>.", array('@default' => Redis_Client::REDIS_DEFAULT_PORT)),
  );
  $form['connection']['redis_client_socket'] = array(
    '#type' => 'textfield',
    '#title' => t("UNIX socket"),
    '#default_value' => variable_get('redis_client_socket', NULL),
    '#description' => t("Redis UNIX socket for connection. If set remote server host and port will be ignored."),
  );
  $form['connection']['redis_client_base'] = array(
    '#type' => 'textfield',
    '#title' => t("Database"),
    '#default_value' => variable_get('redis_client_base', NULL),
    '#description' => t("Redis server database. Default is none, Redis server will autoselect the database 0."),
  );
  $form['connection']['redis_client_interface'] = array(
    '#type' => 'radios',
    '#title' => t("Client"),
    '#options' => array(
      NULL => t("None or automatic"),
      'PhpRedis' => t("PhpRedis PHP extension"),
      'Predis' => t("Predis PHP library"),
    ),
    '#default_value' => variable_get('redis_client_interface', NULL),
    '#description' => t("Redis low level backend."),
  );

  $form = system_settings_form($form);

  // Enforce empty values drop from the $form_state in order to avoid empty
  // values saving. Empty values would cause the isset() checks in client
  // options to see false positives and fail upon connection.
  array_unshift($form['#submit'], 'redis_settings_form_submit_clean_values');

  return $form;
}

/**
 * Deep clean of $form_state values.
 */
function redis_settings_form_submit_clean_values($form, &$form_state) {

  $string_values = array('redis_client_host', 'redis_client_interface');

  foreach ($string_values as $name) {
    // Empty check is sufficient to verify that the field is indeed empty.
    if (empty($form_state['values'][$name])) {
      // Using unset() will keep the key in the array, with an associated NULL
      // value. While this wouldn't really matter, it's safer to remove it so
      // that system_settings_form_submit() won't find it and attempt to save
      // it.
      $form_state['values'] = array_diff_key($form_state['values'], array($name => NULL));
      variable_del($name);
    }
  }

  $numeric_values = array('redis_client_base', 'redis_client_port');

  foreach ($numeric_values as $name) {
    // Numeric values can be both of NULL or 0 (NULL meaning the value is not
    // not set and the client will use the default, while 0 has a business
    // meaning and should be kept as is).
    if ('0' !== $form_state['values'][$name] && empty($form_state['values'][$name])) {
      $form_state['values'] = array_diff_key($form_state['values'], array($name => NULL));
      variable_del($name);
    } else {
      $form_state['values'][$name] = (int)$form_state['values'][$name];
    }
  }
}
