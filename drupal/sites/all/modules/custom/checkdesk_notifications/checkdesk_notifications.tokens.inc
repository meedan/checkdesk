<?php

/**
 * Implements hook_token_info().
 */
function checkdesk_notifications_token_info() {
  $info['tokens']['user']['notifications-url'] = array(
    'name' => t('Notifications URL'),
    'description' => t('URL to the notifications page of a user'),
  );
  return $info;
}

/**
 * Implements hook_tokens().
 */
function checkdesk_notifications_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'user' && !empty($data['user']) && isset($tokens['notifications-url'])) {
    $user = $data['user'];
    $original = $tokens['notifications-url'];
    $replacements[$original] = url('user/' . $user->uid . '/edit/notifications', array('absolute' => TRUE, 'alias' => TRUE, 'language' => $options['language']));
  }
  return $replacements;
}
