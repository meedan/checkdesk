<?php

/**
 * Implements hook_form_system_theme_settings_alter().
 *
 */
function checkdesk_form_system_theme_settings_alter(&$form, &$form_state) {

  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => t('Logos and Badges'),
  );

  // logo on frontpage
  $path = theme_get_setting('frontpage_logo_path');
  $form['header']['frontpage_logo_path'] = array(
    '#type' => 'value',
    '#value' => $path,
  );
  $form['header']['frontpage_logo_upload'] = array(
    '#type' => 'file',
    '#title' => t('Partner logo (square version):'),
    '#description' => t('The partner logo will appear on the frontpage. The logo should be 400px tall and 400px wide and work on a white background.'),
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
    '#title' => t('Partner Logo (wide version):'),
    '#description' => t('This version will appear on the top of stories. The logo should be 72px tall and up to 400px wide and work on a white background.'),
  );
  if (file_uri_scheme($path) === 'public') {
    $path = file_uri_target($path);
  }
  $form['header']['header_logo_preview'] = array(
    '#markup' => (empty($path) ? '' : '<img src="' . image_style_url('header_logo', $path) . '" />'),
  );

  // badge logo mostly for mobile
  $path = theme_get_setting('badge_logo_path');
  $form['header']['badge_logo_path'] = array(
    '#type' => 'value',
    '#value' => $path,
  );
  $form['header']['badge_logo_upload'] = array(
    '#type' => 'file',
    '#title' => t('Partner logo (badge version):'),
    '#description' => t('This version will appear on smaller screens and as your avatar. The logo should be a 400px tall and 400px wide.'),
  );
  if (file_uri_scheme($path) === 'public') {
    $path = file_uri_target($path);
  }
  $form['header']['badge_logo_preview'] = array(
    '#markup' => (empty($path) ? '' : '<img src="' . image_style_url('activity_avatar', $path) . '" />'),
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

  if ($file = file_save_upload('badge_logo_upload', array('file_validate_is_image' => array()), $filepath, FILE_EXISTS_REPLACE)) {
    // Make the file permanent
    $file->status = 1;
    file_save($file);
    $_POST['badge_logo_path'] = $form_state['values']['badge_logo_path'] = $file->destination;
  }
}

?>
