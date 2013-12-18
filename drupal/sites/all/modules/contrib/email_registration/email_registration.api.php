<?php

/**
 * @file
 * Documentation for email_registration API.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Implement this hook to generate a username for email_registration module.
 *
 * Other modules may implement hook_email_registration_name($edit, $account)
 * to generate a username (return a string to be used as the username, NULL
 * to have email_registration generate it).
 *
 * @param $edit
 *   The array of form values submitted by the user.
 * @param $account
 *   The user object on which the operation is being performed.
 *
 * @return
 *   A string defining a generated username.
 */
function hook_email_registration_name($edit, $account) {
  return 'u' . $account->uid;
}

/**
 * @} End of "addtogroup hooks".
 */
