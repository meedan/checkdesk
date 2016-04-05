<?php
/**
 * @file
 * checkdesk_sources_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function checkdesk_sources_feature_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-source-body'.
  $field_instances['node-source-body'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description about this source',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'exclude_cv' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-source-field_image'.
  $field_instances['node-source-field_image'] = array(
    'bundle' => 'source',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'exclude_cv' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'image_field_caption' => 0,
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-source-field_provider'.
  $field_instances['node-source-field_provider'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_provider',
    'label' => 'Provider',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'captions' => 'captions',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'liveblog' => 'liveblog',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'captions' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -50,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'liveblog' => array(
              'weight' => -50,
            ),
            'php_code' => array(
              'weight' => 10,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-source-field_published_at'.
  $field_instances['node-source-field_published_at'] = array(
    'bundle' => 'source',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 9,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_published_at',
    'label' => 'Published at',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-source-field_source_comments'.
  $field_instances['node-source-field_source_comments'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 7,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_source_comments',
    'label' => 'Comments',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-source-field_source_status'.
  $field_instances['node-source-field_source_status'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_source_status',
    'label' => 'Status',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'autocomplete_deluxe',
      'settings' => array(
        'autocomplete_deluxe_path' => 'autocomplete_deluxe/taxonomy',
        'delimiter' => '',
        'limit' => 10,
        'min_length' => 0,
        'not_found_message' => 'The term \'@term\' will be added.',
        'size' => 60,
      ),
      'type' => 'autocomplete_deluxe_taxonomy',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-source-field_source_subscriber'.
  $field_instances['node-source-field_source_subscriber'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 6,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_source_subscriber',
    'label' => 'Subscribers',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-source-field_source_tags'.
  $field_instances['node-source-field_source_tags'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'i18n_taxonomy',
        'settings' => array(),
        'type' => 'i18n_taxonomy_term_reference_link',
        'weight' => 3,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_source_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'autocomplete_deluxe',
      'settings' => array(
        'autocomplete_deluxe_path' => 'autocomplete_deluxe/taxonomy',
        'delimiter' => '',
        'limit' => 10,
        'min_length' => 0,
        'not_found_message' => 'The term \'@term\' will be added.',
        'size' => 60,
      ),
      'type' => 'autocomplete_deluxe_taxonomy',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-source-field_source_url'.
  $field_instances['node-source-field_source_url'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'inline',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_source_url',
    'label' => 'Source URL',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'exclude_cv' => FALSE,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-source-field_source_views'.
  $field_instances['node-source-field_source_views'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 5,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_source_views',
    'label' => 'Views',
    'required' => 0,
    'settings' => array(
      'exclude_cv' => FALSE,
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-source-field_username'.
  $field_instances['node-source-field_username'] = array(
    'bundle' => 'source',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'checkdesk_collaborate' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_export' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'checkdesk_search' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'meedan_oembed' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'exclude_cv' => 0,
    'field_name' => 'field_username',
    'label' => 'Username',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'captions' => 'captions',
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'liveblog' => 'liveblog',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'captions' => array(
              'weight' => 0,
            ),
            'filtered_html' => array(
              'weight' => -50,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'liveblog' => array(
              'weight' => -50,
            ),
            'php_code' => array(
              'weight' => 10,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'exclude_cv' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'maxlength_js' => 0,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Comments');
  t('Description about this source');
  t('Image');
  t('Provider');
  t('Published at');
  t('Source URL');
  t('Status');
  t('Subscribers');
  t('Tags');
  t('Username');
  t('Views');

  return $field_instances;
}
