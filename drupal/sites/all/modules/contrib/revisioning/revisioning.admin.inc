<?php

/**
 * @file
 * Admin configuration settings for Revisioning.
 */

/**
 * Menu callback for admin configuration settings.
 */
function revisioning_admin_configure() {

  $form['revisioning_view_and_edit_links'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configure which revision is loaded when clicking on a view or edit link'),
    '#description' => t('This section allows you to configure which revision is loaded when clicking on links for viewing or editing moderated content, that is content for which the check-box <strong>New revision in draft, pending moderation</strong> is ticked on the %link page. If not ticked for this content type, current and latest revisions will be one and the same, so that the options behave identically.',
      array('%link' => 'admin/structure/types/manage/<content-type>')),
  );
  $form['revisioning_view_and_edit_links']['revisioning_view_callback'] = array(
    '#type' => 'radios',
    '#title' => t('Links to view content default to'),
    '#options' => array(
      REVISIONING_LOAD_CURRENT => t('displaying the current revision'),
      REVISIONING_LOAD_LATEST  => t('displaying the latest revision (reverts to current revision, if the user is not permitted to view revisions of the content type in question)')),
    '#default_value' => variable_get('revisioning_view_callback', REVISIONING_LOAD_CURRENT),
    '#description' => t('The first option represents default core behaviour.'),
  );
  $form['revisioning_view_and_edit_links']['revisioning_edit_callback'] = array(
    '#type' => 'radios',
    '#title' => t('Links to edit content default to'),
    '#options' => array(
      REVISIONING_LOAD_CURRENT => t('editing the current revision'),
      REVISIONING_LOAD_LATEST  => t('editing the latest revision (reverts to current revision, if the user is not permitted to view revisions of the content type in question)')),
    '#default_value' => variable_get('revisioning_edit_callback', REVISIONING_LOAD_CURRENT),
    '#description' => t('The first option represents default core behaviour.'),
  );

  $form['revisioning_publication_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Publication options'),
  );
  $form['revisioning_publication_config']['revisioning_require_update_to_publish'] = array(
    '#type' => 'checkbox',
    '#title' => t('Require update permission in order to publish or unpublish content.'),
    '#default_value' => variable_get('revisioning_require_update_to_publish', TRUE),
    '#description' => t('If you have enabled one or modules dealing with content access, then you would normally tick this box.'),
  );
  $form['revisioning_publication_config']['revisioning_publication_shortcuts'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show publication shortcut controls for all users permitted to publish nodes.'),
    '#default_value' => variable_get('revisioning_publication_shortcuts', FALSE),
    '#description' => t('Radio buttons are added immediately under the "Revisioning" pane in the content edit form for any user permitted to publish. If not selected, then only users with "administer nodes" will see these controls.'),
  );
  $form['revisioning_publication_config']['revisioning_no_moderation_by_default'] = array(
    '#type' => 'checkbox',
    '#title' => t('Publish content by default.'),
    '#default_value' => variable_get('revisioning_no_moderation_by_default', FALSE),
    '#description' => t('When publication shortcut controls are shown, publish content by default. If not, the default will be to moderate.'),
  );

  if (module_exists('taxonomy')) {
    $form['revisioning_display_options'] = array(
      '#type' => 'fieldset',
      '#title' => t('Display options'),
    );
    $form['revisioning_display_options']['revisioning_show_taxonomy_terms'] = array(
      '#type' => 'checkbox',
      '#title' => t('Where applicable add <strong>Tags</strong> and <strong>Terms</strong> columns to the content revisions summary (Revisions tab).'),
      '#default_value' => variable_get('revisioning_show_taxonomy_terms', TRUE),
      '#description' => t('These columns will only appear if some tags or terms have been assigned to the content shown.'),
    );
    $form['revisioning_display_options']['revisioning_in_views_show_unpublished_content_terms'] = array(
      '#type' => 'checkbox',
      '#title' => t('In feeds and Views, e.g. <em>/content-summary</em>, show <strong>Tags</strong> and <strong>Terms</strong> associated with unpublished content, subject to permissions'),
      '#default_value' => variable_get('revisioning_in_views_show_unpublished_content_terms', TRUE),
      '#description' => t('Core behaviour is to suppress the display of tags and terms on all unpublished content even if the user has the permission.'),
    );
  }

  $access_modules = module_implements('node_access');
  $grants_modules = module_implements('node_grants');
  $modules = array_merge($access_modules, $grants_modules);

  $form['revisioning_additional_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Additional info'),
    '#description' => t('The following content access modules are enabled and may affect whether users can view, edit, delete or publish content:<br/>%modules.',
      array('%modules' => empty($modules) ? t('none') : implode(', ', $modules))),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  $form['#submit'][] = 'revisioning_admin_configure_form_submit';

  $form['#theme'] = 'system_settings_form';

  return $form;
}


/**
 * Execute the revisioning_admin_configure_form.
 */
function revisioning_admin_configure_form_submit($form, &$form_state) {
  // Exclude unnecessary form elements.
  form_state_values_clean($form_state);

  foreach ($form_state['values'] as $key => $new_value) {
    $old_value = variable_get($key);
    if ($old_value != $new_value) {
      variable_set($key, $new_value);
      if ($key == 'revisioning_in_views_show_unpublished_content_terms') {
        foreach (node_load_multiple(FALSE) as $node) {
          revisioning_update_taxonomy_index($node, $new_value);
        }
      }
    }
  }

  drupal_set_message(t('The revisioning configuration options have been saved.'));
}
