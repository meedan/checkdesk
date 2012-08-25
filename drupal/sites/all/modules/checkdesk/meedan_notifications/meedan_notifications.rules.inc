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
          'type' => 'entity',
          'label' => t('Object'),
        ),
        'event' => array(
          'type' => 'text',
          'label' => t('Event'),
          'options list' => 'meedan_notifications_get_events',
          'restriction' => 'input',
        ),
        'subject' => array(
          'type' => 'text',
          'label' => t('Subject'),
          'restriction' => 'input',
        ),
        'message' => array(
          'type' => 'text',
          'label' => t('Message'),
          'restriction' => 'input',
        ),
      ),
      'group' => 'Notifications',
      'base' => 'meedan_notifications_rules_action',
    ),
  );
}

/**
 * Action function for Rules action `notify_subscribers`.
 */
function meedan_notifications_rules_action($object, $event, $subject, $message) {
  meedan_notifications_action($object, array('event' => $event, 'subject' => $subject, 'message' => $message));
}

