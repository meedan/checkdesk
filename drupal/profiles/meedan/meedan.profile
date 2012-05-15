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
      '#markup' => '<div class="messages ok">' . t("This form will automatically submit if no user action is taken in 5 seconds…") . '</div>',
      '#weight' => -1000,
    );
    $form['admin_account']['account']['robot'] = array(
      '#markup' => '<script type="text/javascript">
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
                      });
                    };
                    // Wait a second before running the robot
                    setTimeout(pass_robot, 1000);
                    </script>'
    );

    // $form['server_settings']['site_default_country']['#default_value'] = 'US';
    // $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Los_Angeles';
  }
}
