<?php
/**
 * @file
 * View elements for Revisioning Scheduler.
 *
 * In particular vid, uid and scheduled publication date.
 * Also defines joins/relationships to node_revision and users tables.
 */

/**
 * Implements hook_views_data().
 */
function revisioning_scheduler_views_data() {

  $data['revisioning_scheduler']['table']['group'] = t('Scheduled content');

  // Advertise revisioning_scheduler table as a possible base table.
  $data['revisioning_scheduler']['table']['base'] = array(
    'field' => 'revision_vid',
    'title' => t('Content revisions scheduled'),
    'help' => t('A list of all revisions currently scheduled for publication.'),
    'defaults' => array(
      'field' => 'revision_date',
    ),
  );

  // For other base tables (node_revision, users), explain how we join.
  $data['revisioning_scheduler']['table']['join'] = array(
    // Directly links to node_revision table. See also relationship details at
    // $data['revisioning_scheduler']['revision_vid'].
    'node_revision' => array(
      'left_field' => 'vid',
      'field' => 'revision_vid',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'revision_nid',
    ),
    // Directly links to the users table. See also relationship details at
    // $data['revisioning_scheduler']['revision_uid'].
    'users' => array(
      'left_field' => 'uid',
      'field' => 'revision_uid',
    ),
  );

  $data['revisioning_scheduler']['revision_nid'] = array(
    'title' => t('Nid'),
    'help' => t('Node ID.'),
    'field' => array(
      'views_handler_field',
      'click sortable' => FALSE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_integer',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'node',
      'field' => 'revision_nid',
      'handler' => 'views_handler_relationship',
      'label' => t('Content revision (NID)'),
    ),
  );

  $data['revisioning_scheduler']['revision_date'] = array(
    'title' => t('Scheduled publication date'),
    'help' => t('Date & time on this content revision will be published.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );

  $data['revisioning_scheduler']['revision_vid'] = array(
    'title' => t('Vid'),
    'help' => t('Revision ID.'),
    'field' => array(
      'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_integer',
    ),
    'relationship' => array(
      'base' => 'node_revision',
      'field' => 'revision_vid',
      'handler' => 'views_handler_relationship',
      'label' => t('Content revision (VID)'),
    ),
  );

  $data['revisioning_scheduler']['revision_uid'] = array(
    'title' => t('Scheduled by'),
    'help' => t('User ID.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_integer',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'revision_uid',
      'handler' => 'views_handler_relationship',
      'label' => t('User'),
    ),
  );

  return $data;
}
