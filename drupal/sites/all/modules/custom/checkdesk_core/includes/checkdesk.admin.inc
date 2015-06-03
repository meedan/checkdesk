<?php

/**
 * Form function for `_checkdesk_core_settings`.
 */
function _checkdesk_core_settings($form, $form_state) {
  $form['checkdesk_site_owner'] = array(
    '#title' => t('Site owner'),
    '#type' => 'textfield',
    '#default_value' => variable_get('checkdesk_site_owner', ''),
  );
  $form['checkdesk_site_owner_url'] = array(
    '#title' => t('Site owner URL'),
    '#type' => 'textfield',
    '#default_value' => variable_get('checkdesk_site_owner_url', ''),
  );
  $form['checkdesk_factchecking_statement'] = array(
    '#title' => t('A "verified" status means'),
    '#type' => 'textarea',
    '#default_value' => variable_get('checkdesk_factchecking_statement', ''),
  );

  return system_settings_form($form);
}
