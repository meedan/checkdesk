<?php

/**
 * @file
 * Admin settings pages
 *
 * @author Stijn De Meyere
 */

/**
 * IFE settings form
 */
function ife_settings_form($form, $form_state) {
  $form = array();

  //general options
  $form['general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General options'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
  );

  $form['general_settings']['ife_show_form_ids'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show form_ids on form'),
    '#description' => t('This option will print the form_id on the form for users with the administer inline form errors permissions'),
    '#default_value' => variable_get('ife_show_form_ids', 0),
  );

  $form['general_settings']['ife_display'] = array(
    '#type' => 'select',
    '#title' => t('Default display settings'),
    '#description' => t('What do you want to do with the original messages block at the top of the page?'),
    '#options' => array(
      t('Leave the messages in place (default Drupal behaviour)'),
      t('Show an alternate error message (a general error message of your choice)'),
      t('Remove all messages (Show nothing)'),
    ),
    '#default_value' => variable_get('ife_display', 1),
  );
  $form['general_settings']['ife_general_message'] = array(
    '#type' => 'textarea',
    '#title' => t('General error message'),
    '#description' => t('A general error message to display at the top of the page (default Drupal messages display). For use with the option "Show an alternate error message".'),
    '#default_value' => variable_get('ife_general_message', 'Please correct all highlighted errors and try again.'),
    '#required' => TRUE,
  );


  //the form id's
  $form['form_ids'] = array(
    '#type' => 'fieldset',
    '#title' => t('Form conversion'),
    '#collapsed' => FALSE,
    '#collapsible' => FALSE,
    '#tree' => TRUE,
    '#theme' => 'ife_settings_form_ids',
  );

  $form_ids = ife_load_form_ids();
  foreach ($form_ids as $form_id) {
    $form['form_ids'][$form_id->form_id] = array();
    $form['form_ids'][$form_id->form_id]['form_id'] = array('#markup' => $form_id->form_id);
    $form['form_ids'][$form_id->form_id]['field_types'] = array('#markup' => t('All fields will be converted'));
    $form['form_ids'][$form_id->form_id]['status'] = array(
      '#type' => 'checkbox',
      '#title' => t('Enabled'),
      '#default_value' => $form_id->status,
    );
    $form['form_ids'][$form_id->form_id]['display'] = array(
      '#type' => 'select',
      '#options' => array(
        '-1' => t('<default>'), t('Leave the messages in place'), t('Show an alternate error message'), t('Remove all messages'),
      ),
      '#default_value' => $form_id->display,
    );
  }

  $form['form_ids']['new_form_id']['form_id'] = array(
    '#type' => 'textfield',
    '#size' => 20,
  );
  $form['form_ids']['new_form_id']['status'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enabled'),
    '#default_value' => 1,
  );
  $form['form_ids']['new_form_id']['field_types'] = array('#value' => t('All fields will be converted'));
  $form['form_ids']['new_form_id']['display'] = array(
    '#type' => 'select',
    '#options' => array(
      '-1' => t('<default>'), t('Leave the messages in place'), t('Show an alternate error messages'), t('Remove all message'),
    ),
    '#default_value' => -1,
  );

  //submit button
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * IFE settings form validations
 */
function ife_settings_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $new_form_id = trim($values['form_ids']['new_form_id']['form_id']);

  //check if form_id already exists
  if ($new_form_id && ife_form_id_load($new_form_id)) {
    form_set_error('form_ids][new_form_id][form_id', t('The form %form_id has already been added.', array('%form_id' => $new_form_id)));
  }

  //check if the form_id is valid
  if (!preg_match('/^[a-z0-9_*]*$/', $new_form_id)) {
    form_set_error('form_ids][new_form_id][form_id', t('The form_id %form_id is invalid.', array('%form_id' => $new_form_id)));
  }
}

/**
 * IFE settings form submit
 */
function ife_settings_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  //set general options
  variable_set('ife_show_form_ids', $values['ife_show_form_ids']);
  variable_set('ife_display', $values['ife_display']);
  variable_set('ife_general_message', $values['ife_general_message']);

  //write form_ids to the database
  $form_ids = $values['form_ids'];
  array_pop($form_ids);

  foreach ($form_ids as $form_id => $options) {
    $object = $options;
    $object['form_id'] = $form_id;

    drupal_write_record('ife', $object, array('form_id'));
  }

  //create new form_id
  if ($values['form_ids']['new_form_id']['form_id']) {
    $values['form_ids']['new_form_id']['form_id'] = trim($values['form_ids']['new_form_id']['form_id']);
    drupal_write_record('ife', $values['form_ids']['new_form_id']);
    drupal_set_message(t('The form %form_id has been added.', array('%form_id' => $values['form_ids']['new_form_id']['form_id'])));
  }

  drupal_set_message(t('The settings have been saved'));
  cache_clear_all('ife_form_ids', 'cache');
}

/**
 * Confirm delete form for IFE form_ids
 */
function ife_form_id_delete_form($form, $form_state, $form_id) {
  $form = array();
  $form['fid'] = array(
    '#value' => $form_id->form_id,
    '#type' => 'hidden',
  );

  return confirm_form(
    $form,
    t('Are your sure you want to delete the form %form_id', array('%form_id' => $form_id->form_id)),
    'admin/config/user-interface/ife',
    t('This action cannot be undone.'),
    t('Delete'));
}

/**
 * Submit for confirm delete form for IFE form_ids
 */
function ife_form_id_delete_form_submit($form, &$form_state) {
  $form_id = $form_state['values']['fid'];
  // TODO Please review the conversion of this statement to the D7 database API syntax.
  /* db_query("DELETE FROM {ife} WHERE form_id = '%s'", $form_id) */
  db_delete('ife')
  ->condition('form_id', $form_id)
  ->execute();
  drupal_set_message(t('The form %form_id has been deleted.', array('%form_id' => $form_id)));

  cache_clear_all('ife_form_ids', 'cache');
  drupal_goto('admin/config/user-interface/ife');
}
