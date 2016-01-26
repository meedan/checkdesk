<?php
/**
 * @file
 * checkdesk_core_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function checkdesk_core_feature_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|media|default';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'media';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '11',
    'children' => array(),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_metadata|node|media|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_metadata|node|media|form';
  $field_group->group_name = 'group_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'media';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Metadata',
    'weight' => '9',
    'children' => array(
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Metadata',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => 'checkdesk-group-metadata',
        'classes' => 'group-metadata field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_metadata|node|media|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Metadata');

  return $field_groups;
}
