<?php

/**
 * A modal login callback.
 */
function checkdesk_sign_in_up_callback($js = NULL) {
  global $user;
  if ($user->uid) {
    drupal_goto('<front>');
  }
  $output = '';
  $links = array();
  drupal_add_js(drupal_get_path('module', 'checkdesk_core') . '/js/checkdesk_sign_in_up.js');
  if (twitter_api_keys()) {
    if (isset($_GET['destination'])) {
        $_SESSION['twitter_redirect'] = $_GET['destination'];
    }
    $links['twitter'] = twitter_signin_button();
  }
  // Add FB
  if (variable_get('fboauth_id', '') && !fboauth_fbid_load()) {
    // Set the redirect to the current page (unless we're on the login page).
    $redirect = (arg(0) === 'user' && (arg(1) === 'login' || arg(1) == '')) ? NULL : $_GET['destination'];
    $links['facebook'] = fboauth_action_display('connect', $redirect);
  }
  $options = array();
  $options['attributes'] = array('class' => array('btn', 'btn-default', 'email-signin'));
  if (isset($_GET['destination'])) {
    $options['query'] = array('destination' => $_GET['destination']);
  }
  $links['login'] = l(t('Sign in with your email'), 'user/login', $options);

  $options['attributes']['class'] = array('btn', 'btn-default', 'email-signup');
  $links['register'] = l(t('Create a new account'), 'user/register', $options);

  $output = theme('checkdesk_core_sign_in_up', array('links' => $links));
  // built sign in/ sign up modal content
  if (!$js) {
    return $output;
  }
  ctools_include('modal');
  ctools_include('ajax');
  return ctools_modal_render('', $output) ;
}
