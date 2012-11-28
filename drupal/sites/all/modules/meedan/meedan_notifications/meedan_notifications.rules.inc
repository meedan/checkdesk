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
          'type' => 'text',
          'label' => t('Actor UID'),
          'restriction' => 'input',
          'description' => t('The identifier of the actor (the one which executed the notified action).'),
        ),
      ),
      'group' => 'System',
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
function meedan_notifications_rules_action($object, $event, $subject, $message, $actor) {
  meedan_notifications_action($object, array('event' => $event, 'subject' => $subject, 'message' => $message, 'actor' => $actor));
}

