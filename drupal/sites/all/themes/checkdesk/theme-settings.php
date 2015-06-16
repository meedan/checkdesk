<?php

/**
 * Implements hook_form_system_theme_settings_alter().
 *
 */
function checkdesk_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header'),
  );

  // logo on frontpage
  $path = theme_get_setting('frontpage_logo_path');
  $form['header']['frontpage_logo_path'] = array(
    '#type' => 'value',
    '#value' => $path,
  );
  $form['header']['frontpage_logo_upload'] = array(
    '#type' => 'file',
    '#title' => t('Choose a logo that will appear on the frontpage:'),
  );
  if (file_uri_scheme($path) === 'public') {
    $path = file_uri_target($path);
  }
  $form['header']['frontpage_logo_preview'] = array(
    '#markup' => (empty($path) ? '' : '<img src="' . image_style_url('partner_logo', $path) . '" />'),
  );


  // header logo on top of stories
  $path = theme_get_setting('header_logo_path');
  $form['header']['header_logo_path'] = array(
    '#type' => 'value',
    '#value' => $path,
  );
  $form['header']['header_logo_upload'] = array(
    '#type' => 'file',
    '#title' => t('Choose a logo that will appear on the top of stories:'),
  );
  if (file_uri_scheme($path) === 'public') {
    $path = file_uri_target($path);
  }
  $form['header']['header_logo_preview'] = array(
    '#markup' => (empty($path) ? '' : '<img src="' . image_style_url('header_logo', $path) . '" />'),
  );

  // footer logo
  $form['footer'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer'),
  );
  $path = theme_get_setting('footer_image_path');
  $form['footer']['footer_image_path'] = array(
    '#type' => 'value',
    '#value' => $path,
  );
  $form['footer']['footer_image_upload'] = array(
    '#type' => 'file',
    '#title' => t('Choose a logo that will appear in the footer:'),
  );
  if (file_uri_scheme($path) === 'public') {
    $path = file_uri_target($path);
  }
  $form['footer']['footer_image_preview'] = array(
    '#markup' => (empty($path) ? '' : '<img src="' . image_style_url('footer_partner_logo', $path) . '" />'),
  );

  $form['#submit'][] = 'checkdesk_settings_submit';
}

/**
 * Submit function for `checkdesk_form_system_theme_settings_alter`.
 *
 */
function checkdesk_settings_submit($form, &$form_state) {
  $filepath = 'public://checkdesk_theme/';
  file_prepare_directory($filepath, FILE_CREATE_DIRECTORY);

  if ($file = file_save_upload('frontpage_logo_upload', array('file_validate_is_image' => array()), $filepath, FILE_EXISTS_REPLACE)) {
    // Make the file permanent
    $file->status = 1;
    file_save($file);
    $_POST['frontpage_logo_path'] = $form_state['values']['frontpage_logo_path'] = $file->destination;
  }

  if ($file = file_save_upload('header_logo_upload', array('file_validate_is_image' => array()), $filepath, FILE_EXISTS_REPLACE)) {
    // Make the file permanent
    $file->status = 1;
    file_save($file);
    $_POST['header_logo_path'] = $form_state['values']['header_logo_path'] = $file->destination;
  }

  if ($file = file_save_upload('footer_image_upload', array('file_validate_is_image' => array()), $filepath, FILE_EXISTS_REPLACE)) {
    // Make the file permanent
    $file->status = 1;
    file_save($file);
    $_POST['footer_image_path'] = $form_state['values']['footer_image_path'] = $file->destination;
  }
}

?>
