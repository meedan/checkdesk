<?php

/**
 * A modal login callback.
 */
function checkdesk_sign_in_up_callback($js = NULL) {
  $output = '';
  $links = array();
  if (twitter_api_keys()) {
    $links['twitter'] = twitter_signin_button();
  }
  // Add FB
  if (variable_get('fboauth_id', '') && !fboauth_fbid_load()) {
    // Set the redirect to the current page (unless we're on the login page).
    $redirect = (arg(0) === 'user' && (arg(1) === 'login' || arg(1) == '')) ? NULL : $_GET['destination'];
    $links['facebook'] = fboauth_action_display('connect', $redirect);
  }

  $links['login'] = l(t('Sign in with your email'), 'user/login', array('attributes' => array('class' => array('email-signin'))));
  $links['register'] = l(t('Create a new account'), 'user/register', array('attributes' => array('class' => array('email-signup'))));
  $output = theme('checkdesk_core_sign_in_up', array('links' => $links));
  // built sign in/ sign up modal content
  if (!$js) {
    return $output;
  }
  ctools_include('modal');
  ctools_include('ajax');
  return ctools_modal_render('', $output) ;
}
