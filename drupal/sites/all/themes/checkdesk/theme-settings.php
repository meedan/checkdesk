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

  $path = theme_get_setting('header_image_path');

  $form['header']['header_image_path'] = array(
    '#type' => 'value',
    '#value' => $path,
  );

  if (file_uri_scheme($path) == 'public') {
    $path = file_uri_target($path);
  }

  $form['header']['header_image_upload'] = array(
    '#type' => 'file',
    '#title' => t('Choose a background image that will appear above your stories:'),
  );

  $form['header']['header_image_preview'] = array(
    '#markup' => (empty($path) ? '' : '<img src="' . image_style_url('thumbnail', $path) . '" />'),
  );

  $form['header']['header_image_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable custom header image'),
    '#default_value' => theme_get_setting('header_image_enabled'),
  );

  $color = theme_get_setting('header_background_color');
  $attributes = array('onblur' => 'this.style.backgroundColor=this.value');
  if (!empty($color)) $attributes['style'] = 'background-color: ' . $color;
  $form['header']['header_background_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Choose a color for the background of the header:'),
    '#default_value' => $color,
    '#attributes' => $attributes,
  );

  $form['header']['header_image_position'] = array(
    '#type' => 'radios',
    '#title' => t('Choose a position for the image:'),
    '#default_value' => theme_get_setting('header_image_position'),
    '#options' => array('center' => t('Center'), 'right' => t('Right'), 'left' => t('Left')),
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

  if ($file = file_save_upload('header_image_upload', array('file_validate_is_image' => array()), $filepath, FILE_EXISTS_REPLACE)) {
    // Make the file permanent
    $file->status = 1;
    file_save($file);
    $_POST['header_image_path'] = $form_state['values']['header_image_path'] = $file->destination;
  }
}

?>
