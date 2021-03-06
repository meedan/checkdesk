<?php
/**
 * @file
 * checkdesk_sources_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function checkdesk_sources_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_source_metadata|node|source|form';
  $field_group->group_name = 'group_source_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'source';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '11',
    'children' => array(
      0 => 'field_source_comments',
      1 => 'field_source_likes',
      2 => 'field_source_subscriber',
      3 => 'field_source_views',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-source-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_source_metadata|node|source|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Metadata');

  return $field_groups;
}
