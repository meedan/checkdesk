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
  $fb_block = module_invoke('fboauth', 'block_view', 'login');
  if (isset($fb_block['content'])) {
    $links['facebook'] = $fb_block['content'];
  }
  $links['login'] = l(t('Sign in with your email address'), 'user/login');
  $links['register'] = l(t('Create a new account'), 'user/register');
  $output = theme('checkdesk_core_sign_in_up', array('links' => $links));
  // built sign in/ sign up modal content
  if (!$js) {
    return $output;
  }
  ctools_include('modal');
  ctools_include('ajax');
  return ctools_modal_render('', $output) ;
}
