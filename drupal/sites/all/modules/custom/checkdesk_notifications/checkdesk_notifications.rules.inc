<?php
/**
 *  @file
 * Rules integration for checkdesk notifications module
 */

function checkdesk_notifications_rules_condition_info() {
  $defaults = array(
    'group' => t('Revisioning'),
    'parameter' => array(
      'node' => array('type' => 'node', 'label' => t('Content')),
    ),
  );
  $items['checkdesk_notifications_first_publish'] = $defaults + array(
    'label' => t('Content was not published before'),
    'help' => t('Evaluates to TRUE, if the content has never been published before.'),
    'module' => 'checkdesk_notifications',
  );
  return $items;
}

function checkdesk_notifications_first_publish($node, $settings) {
  $query = db_select('node_revision', 'r');
  $query->condition('nid', $node->nid);
  $query->condition('status', 1);
  $query->fields('r', array('nid'));
  $query->range(0, 2);
  $result = $query->execute();
  return $result->rowCount() != 2;
}