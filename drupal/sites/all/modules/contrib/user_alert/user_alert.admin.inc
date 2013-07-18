<?php
/**
 * @file
 * Allow configuration changes for alerts.
 */

/**
 * Form builder for the user alerts settings form.
 * @ingroup forms
 */
function user_alert_admin_settings() {
	$form = array();

	$form['user_alert_label'] = array(
		'#title' => 'User alert label',
		'#type' => 'textfield',
		'#description' => t('The label next to every user alert message.'),
		'#default_value' =>	variable_get('user_alert_label', 'User Alert'),
	);

  $form['user_alert_cron_delete'] = array(
    '#title' => t('Delete unpublished user alerts automatically?'),
    '#type' => 'checkbox',
    '#description' => t('If checked, any user alerts that are unpublished will be deleted when cron runs.'),
    '#default_value' => variable_get('user_alert_cron_delete', 0),
  );
	
	return system_settings_form($form);	
}