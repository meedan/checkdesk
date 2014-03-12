<?php

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function meedan_form_install_configure_form_alter(&$form, $form_state) {
  $server_name = $_SERVER['SERVER_NAME'];

  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $server_name;

  // Automatically fill basic account information when running in a development
  // environment.
  if (MEEDAN_ENVIRONMENT == 'DEV') {
    $form['site_information']['site_mail']['#default_value'] = 'admin@' . $server_name;
    $form['admin_account']['account']['name']['#default_value'] = 'admin';
    $form['admin_account']['account']['mail']['#default_value'] = 'admin@' . $server_name;

    // Robot automatically submits the confirm form if no user input is given
    // and 5 seconds passes.
    $form['robot_info'] = array(
      '#markup' => '<div class="messages ok" id="robot-warning">' . t("This form will automatically submit if no user action is taken in 5 seconds…") . '</div>',
      '#weight' => -1000,
    );
    $form['admin_account']['account']['robot'] = array(
      '#markup' => '<script type="text/javascript">
                    (function ($) {

                    // Things that should stop the autosubmit if they
                    // gain focus
                    var focus_context = "#install-configure-form input, #install-configure-form select, #install-configure-form textarea";

                    var autosubmit_form = function () {
                      jQuery(focus_context).unbind("focus");
                      jQuery("#install-configure-form").submit();
                    };

                    var pass_robot = function () {
                      jQuery("#edit-account-pass-pass1").val("admin").focus();
                      jQuery("#edit-account-pass-pass2").val("admin").focus();

                      // Submit the form if nothing changes after 5 seconds
                      var timer = setTimeout(autosubmit_form, 5000);

                      // If anything gains focus clear the timer
                      jQuery(focus_context).focus(function () {
                        clearTimeout(timer);
                        jQuery(focus_context).unbind("focus");
                        $("#robot-warning")
                          .slideUp(function() { $(this).remove(); });
                      });
                    };
                    // Wait a second before running the robot
                    setTimeout(pass_robot, 1000);

                    })(jQuery);
                    </script>'
    );

    // $form['server_settings']['site_default_country']['#default_value'] = 'US';
    // $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Los_Angeles';
  }
}

/**
 * Implements hook_install_tasks().
 */
function meedan_install_tasks($install_state) {
  $tasks['cd_import_translations'] = array(
    'display_name' => st('Import translations'),
    'type' => 'batch',
  );
  $tasks['cd_configration_form'] = array(
    'display_name' => st('Checkdesk Configration'),
    'display' => TRUE,
    'type' => 'form',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    //'function' => 'cd_configration_form',
  );
  return $tasks;
}

function cd_configration_form($form, &$form_state, &$install_state) {
  $form['twitter_oauth'] = array(
    '#type' => 'fieldset',
    '#title' => st('Twitter Configration'),
    '#collapsible' => FALSE,
  );
  $form['twitter_oauth']['twitter_consumer_key'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth Consumer key'),
    '#default_value' => variable_get('twitter_consumer_key', NULL),
  );  
  $form['twitter_oauth']['twitter_consumer_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('OAuth Consumer secret'),
    '#default_value' => variable_get('twitter_consumer_secret', NULL),
  ); 
  $form['facebook'] = array(
    '#type' => 'fieldset',
    '#title' => st('Facebook Configration'),
    '#collapsible' => FALSE,
  );
  $form['facebook']['fboauth_id'] = array(
    '#type' => 'textfield',
    '#title' => t('App ID'),
    '#size' => 20, 
    '#maxlengh' => 50, 
    '#description' => t('To use Facebook connect, a Facebook Application must be created. Set up your app in <a href="http://www.facebook.com/developers/apps.php">my apps</a> on Facebook.') . ' ' . t('Enter your App ID here.'),
    '#default_value' => variable_get('fboauth_id', ''),
  );  
  $form['facebook']['fboauth_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('App Secret'),
    '#size' => 40, 
    '#maxlengh' => 50, 
    '#description' => t('To use Facebook connect, a Facebook Application must be created. Set up your app in <a href="http://www.facebook.com/developers/apps.php">my apps</a> on Facebook.') . ' ' . t('Enter your App Secret here.'),
    '#default_value' => variable_get('fboauth_secret', ''),
  ); 
  $form['cd_multilingual'] = array(
    '#type' => 'fieldset',
    '#title' => st('Multilingual feature'),
    '#collapsible' => FALSE,
  );
  $form['cd_multilingual']['enable_multilingual'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      1 => st('Enable multilingual feature'),
    ),
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    '#weight' => 15,
  );
  return $form;
}

function cd_configration_form_submit($form, &$form_state) {
  variable_set('twitter_consumer_key', $form_state['values']['twitter_consumer_key']);
  variable_set('twitter_consumer_secret', $form_state['values']['twitter_consumer_secret']);
  variable_set('fboauth_id', $form_state['values']['fboauth_id']);
  variable_set('fboauth_secret', $form_state['values']['fboauth_secret']);
  module_enable(array('checkdesk_core_feature'));
  if ($form_state['values']['enable_multilingual'][1]) {
    module_enable(array('checkdesk_multilingual_feature'));
  }
  //revert some feature components
  features_revert(array('checkdesk_core_feature' => array('user_permission')));
  features_revert(array('checkdesk_featured_stories_feature' => array('user_permission')));
}

function cd_import_translations() {
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  module_load_include('check.inc', 'l10n_update');
  module_load_include('batch.inc', 'l10n_update');
  $translations = array('ar');
  // Prepare batch process to enable languages and download translations.
  $operations = array();
  foreach ($translations as $translation) {
    locale_add_language(strtolower($translation));

    // Build batch with l10n_update module.
    $history = l10n_update_get_history();
    $available = l10n_update_available_releases();
    $updates = l10n_update_build_updates($history, $available);

    $operations = array_merge($operations, _l10n_update_prepare_updates($updates, NULL, array()));
  }

  $batch = l10n_update_batch_multiple($operations, LOCALE_IMPORT_KEEP);
  return $batch;
}


