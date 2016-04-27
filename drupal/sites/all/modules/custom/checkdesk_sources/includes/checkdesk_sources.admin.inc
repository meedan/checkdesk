<?php

function _checkdesk_sources_admin_settings() {
  $form['checkdesk_sources_pender_key'] = array(
	'#type' => 'textfield',
	'#title' => t('Pender API key'),
	'#description' => t('This key is shared with Pender service in order to communicate securely.'),
	'#default_value' => variable_get('checkdesk_sources_pender_key'),
  );
  $form['checkdesk_sources_pender_host'] = array(
	'#type' => 'textfield',
	'#title' => t('Pender host'),
	'#description' => t('Host where Pender is running.'),
	'#default_value' => variable_get('checkdesk_sources_pender_host'),
  );
  $form['pender_cache'] = array(
	'#type' => 'fieldset',
	'#title' => 'Pender cache settings',
  );
  $period = drupal_map_assoc(array(3600, 10800, 21600, 32400, 43200, 86400, 172800, 259200, 604800, 1209600, 2419200, 4838400, 9676800), 'format_interval');
  $period[CACHE_PERMANENT] = t('Indefinite');
  $form['pender_cache']['pender_cache_lifetime'] = array(
	'#type' => 'select',
	'#title' => t('Minimum Pender cache lifetime'),
	'#options' => $period,
	'#default_value' => variable_get('pender_cache_lifetime', CACHE_PERMANENT),
  );
  $form['pender_cache']['pender_cache_flush'] = array(
	'#type' => 'checkbox',
	'#title' => t('Clear Pender cache when all Drupal caches are cleared'),
	'#default_value' => variable_get('pender_cache_flush', FALSE),
  );
  return system_settings_form($form);
}