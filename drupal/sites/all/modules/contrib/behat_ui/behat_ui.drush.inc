<?php

/**
 * Implementation of hook_drush_command().
 */
function behat_ui_drush_command() {
  $items = array();

  // The 'behat-ui' command
  $items['behat-ui'] = array(
    'description' => "Runs your Behat testing suite.",
    'arguments' => array(),
    'options' => array(),
    'examples' => array(
      'drush bui' => 'Runs the testing suite.',
    ),
    'aliases' => array('bui'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );
  
  return $items;
}

/**
 * Implementation of hook_drush_help().
 */
function behat_ui_drush_help($section) {
  switch ($section) {
    case 'drush:behat-ui':
      return dt("This command will run the Behat testing suite.");
  }
}

/**
 * Drush command callback.
 */
function drush_behat_ui() {
  global $base_root;

  $username = variable_get('behat_ui_http_user', '');
  $password = variable_get('behat_ui_http_password', '');

  $url = $base_root;
  if (!empty($username) && !empty($password) && !variable_get('behat_ui_http_auth_headless_only', 0)) {
    $url = preg_replace('/^(https?:\/\/)/', "$1$username:$password@", $url);
    $url = preg_replace('/([^\/])$/', "$1/", $url);
  }

  $behat_bin = variable_get('behat_ui_behat_bin_path');
  $behat_config_path = variable_get('behat_ui_behat_config_path');

  $tmp = file_directory_temp();
  $cmd = "MINK_EXTENSION_PARAMS='base_url=$url' php $behat_bin";
  $outfile = $tmp . '/behat-ui-' . time() . '.log';
  exec(sprintf("cd $behat_config_path; %s > %s 2>&1", $cmd, $outfile));
  drush_print(file_get_contents($outfile));
}
