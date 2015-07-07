<?php

/**
 * Implements hook_token_info().
 */
function meedan_notifications_token_info() {
  $info['types']['recipient'] = array(
    'name' => t('Recipient'),
    'description' => t('The recipient of the email notification.'),
    'type' => 'user',
    'needs-data' => 'recipient',
  );
  return $info;
}

/**
 * Implements hook_tokens().
 */
function meedan_notifications_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  if ($type == 'recipient' && !empty($data['recipient'])) {
    $replacements += token_generate('user', $tokens, array('user' => $data['recipient']), $options);
  }
  return $replacements;
}
