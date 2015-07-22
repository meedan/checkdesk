<?php

/**
 * @file
 * Declare new node and node_revisions fields and filters.
 */

/**
 * Implements hook_views_data_alter().
 *
 * Here we define pseudo-fields for the {node} and {node_revision} tables.
 */
function revisioning_views_data_alter(&$data) {

  $data['node']['last_editor'] = array(
    'title' => t('Last edited by'),
    'help' => t('The name of the user who last edited this content.'),
    'field' => array(
      'handler' => 'revisioning_handler_field_node_last_editor',
      'click sortable' => TRUE,
    ),
  );

  $data['node']['state'] = array(
    'title' => t('State'),
    'help' => t('One of: pending, current, archived.'),
    'field' => array(
      'handler' => 'revisioning_handler_field_node_state',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'revisioning_handler_filter_node_state',
    ),
    // Cannot support sort as 'state' cannot be expressed as ORDER BY clause.
  );

  $data['node']['number_of_revisions'] = array(
    'title' => t('Revisions'),
    'help' => t('Number of revisions.'),
    'field' => array(
      'handler' => 'revisioning_handler_field_node_number_of_revisions',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'revisioning_handler_filter_node_number_of_revisions',
    ),
    // Cannot support sort as 'number of revisions' cannot be expressed as
    // ORDER BY clause.
  );

  $data['node']['revision_moderation'] = array(
    'title' => t('Revision moderation'),
    'help' => t('Whether this content is subject to revision moderation.'),
    'field' => array(
      'handler' => 'revisioning_handler_field_node_revision_moderation',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'revisioning_handler_filter_node_revision_moderation',
    ),
    // Cannot support sort as this flag cannot be expressed as ORDER BY clause.
  );

  $data['node_revision']['title']['help'] = t('The title of the content revision.');

  $data['node_revision']['state'] = array(
    'title' => t('State'),
    'help' => t('One of: pending, current, archived.'),
    'field' => array(
      'handler' => 'revisioning_handler_field_revision_state',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'revisioning_handler_filter_revision_state',
    ),
    // Cannot support sort as 'state' cannot be expressed as ORDER BY clause.
  );
  $data['node_revision']['latest'] = array(
    'title' => t('Latest'),
    'help' => t('Include only the most recent revisions.'),
    'filter' => array(
      'handler' => 'revisioning_handler_filter_revision_latest',
    ),
  );
  $data['node_revision']['latest_published'] = array(
    'title' => t('Published'),
    'help' => t('Include only currently published revisions.'),
    'filter' => array(
      'handler' => 'revisioning_handler_filter_revision_latest_published',
    ),
  );
}
