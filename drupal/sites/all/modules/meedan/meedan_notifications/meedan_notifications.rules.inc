<?php

/**
 * Implements hook_rules_action_info().
 */
function meedan_notifications_rules_action_info() {
  return array(
    'notify_subscribers' => array(
      'label' => t('Notify subscribed users'),
      'parameter' => array(
        'object' => array(
          'type' => 'unknown',
          'label' => t('Object'),
        ),
        'event' => array(
          'type' => 'text',
          'label' => t('Event'),
          'options list' => 'meedan_notifications_rules_get_events',
          'restriction' => 'input',
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'restriction' => 'input',
          'description' => t('The notification email subject. In addition to the tokens listed below, you can also use [recipient] which will be filled with the account information of each recipient.'),
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'restriction' => 'input',
          'description' => t('The notification email body. In addition to the tokens listed below, you can also use [recipient] which will be filled with the account information of each recipient.'),
        ),
        'actor' => array(
          'type' => 'user',
          'label' => t('Actor'),
          'description' => t('The actor who executed the notified action.'),
        ),
        't_args' => array(
          'type' => 'text',
          'label' => t('Arguments'),
          'restriction' => 'input',
          'description' => t('A serialized PHP array of named arguments to pass to the t() function, for both subject and message texts. Each argument will itself be first passed through t(). For example: <code>return serialize(array("!type" => $node->type, "!title" => $node->title));</code>.'),
          'default value' => '<?php return serialize(array()); ?>',
          'cleaning callback' => 'meedan_notifications_cleaning_callback',
        ),
      ),
      'group' => 'User',
      'base' => 'meedan_notifications_rules_action',
    ),
  );
}

/**
 * Helper to get event types.
 */
function meedan_notifications_rules_get_events() {
  return meedan_notifications_get_events('label');
}

/**
 * Action function for Rules action `notify_subscribers`.
 */
function meedan_notifications_rules_action($object, $event, $subject, $message, $actor, $t_args) {
  meedan_notifications_action($object, array('event' => $event, 'subject' => $subject, 'message' => $message, 'actor' => $actor->uid, 't_args' => (array)@unserialize($t_args)));
}

/**
 * Callback for `t_args` parameter from Rules action `notify_subscribers`.
 */
function meedan_notifications_cleaning_callback(&$replacements, $data, $options) {
  // Keep tokens to be replaced later
  foreach ($replacements as $token => $value) {
    $replacements[$token] = $token;
  }
}
