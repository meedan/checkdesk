<?php

class oembed_provider_ui extends ctools_export_ui {

  /**
   * Provide the actual editing form.
   */
  function edit_form(&$form, &$form_state) {
    parent::edit_form($form, $form_state);
    $form['title'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Title'),
      '#description'   => t('A human-readable title for the provider.'),
      '#size'          => 32,
      '#maxlength'     => 255,
      '#required'      => TRUE,
      '#default_value' => $form_state['item']->title,
    );

    $form['endpoint'] = array(
      '#type'          => 'textfield',
      '#title'         => t('Endpoint'),
      '#description'   => t('The endpoint where OEmbed requests are going to be sent.'),
      '#size'          => 32,
      '#maxlength'     => 255,
      '#required'      => TRUE,
      '#default_value' => $form_state['item']->endpoint,
    );

    $form['scheme'] = array(
      '#type'          => 'textarea',
      '#title'         => t('Schemes'),
      '#description'   => t('Newline separated list of schemes like !example', array('!example' => 'http://*.revision3.com/*')),
      '#required'      => TRUE,
      '#default_value' => $form_state['item']->scheme,
    );
  }
}
