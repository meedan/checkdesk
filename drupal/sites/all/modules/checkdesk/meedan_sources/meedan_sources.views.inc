<?php

/**
 * Implements hook_views_data().
 */
function meedan_sources_views_data() {
  // meedan_sources table.
  $data['meedan_sources']['table']['group']  = t('Media sources');
  $data['meedan_sources']['table']['base'] = array(
    'field' => 'ms_id',
    'title' => t('Media sources'),
    'help' => t('Media source information.'),
  );

  $data['meedan_sources']['table']['join'] = array(
    'meedan_sources_media' => array(
      'field' => 'ms_id',
      'left_field' => 'ms_id',
    ),
  );

  $data['meedan_sources']['ms_id'] = array(
    'title' => t('Source ID'),
    'help' => t('The media source ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'source',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['meedan_sources']['source'] = array(
    'title' => t('Source name'),
    'help' => t('The media source name.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['meedan_sources']['source_url'] = array(
    'title' => t('Source URL'),
    'help' => t('The media source URL'),
    'field' => array(
      'handler' => 'views_handler_field',
    ),
  );

  $data['meedan_sources']['parent'] = array(
    'title' => t('Parent'),
    'help' => t('The media source parent ID.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'source',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'meedan_sources',
      'field' => 'parent',
      'label' => t('Parent'),
    ),
  );

  // meedan_sources_media table.
  $data['meedan_sources_media']['table']['group']  = t('Media sources');
  $data['meedan_sources_media']['table']['join'] = array(
    'meedan_sources' => array(
      'left_field' => 'ms_id',
      'field' => 'ms_id',
    ),
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['meedan_sources_media']['nid'] = array(
    'title' => t('Content with media sources'),
    'help' => t('Relate all content associated with a media source. This can produce duplicate entries if a source is used in multiple nodes.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'node',
      'base field' => 'nid',
      'label' => t('Node'),
      'skip base' => 'node',
    ),
  ); 

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function meedan_sources_views_data_alter(&$data) {
  $data['node']['ms_id'] = array(
    'title' => t('Media sources of the node'),
    'help' => t('Relate all media sources on the node. This can produce duplicate entries if a node includes multiple media sources.'),
    'relationship' => array(
      'group' => t('Media sources'),
      'label' => t('Media sources'),
      'base' => 'meedan_sources_media',
      'base field' => 'nid',
      'relationship field' => 'nid',
      'handler' => 'views_handler_relationship',
    ),
  );
}

