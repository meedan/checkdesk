<?php

/**
 * Form callback for normal fapi elements.
 */
function clientside_validation_testswarm_fapi($form, $form_state) {
  $form = array();
  $form['info'] = array(
    '#markup' => '<p><strong>' . t('Clientside Validation Testswarm - Form API') . '</strong></p>',
  );

  $form['yourname'] = array(
    '#type' => 'textfield',
    '#title' => t('Your name'),
    '#default_value' => '',
    '#required' => TRUE,
    '#maxlength' => 20,
    '#description' => t('Required textfield, max length 20 characters.'),
  );

  $form['copy'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select at least one'),
    '#required' => TRUE,
    '#options' => array(
      'status' => t('Published'),
      'moderate' => t('In moderation queue'),
      'promote' => t('Promoted to front page'),
      'sticky' => t('Sticky at top of lists'),
      'revision' => t('Create new revision'),
    ),
    '#description' => t('Required checkboxes'),
  );

  $form['yourdob'] = array(
    '#type' => 'date',
    '#title' => t('DOB'),
    '#required' => TRUE,
    '#description' => t('Required date field'),
  );

  $form['pass'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#maxlength' => 20,
    '#size' => 25,
    '#required' => TRUE,
    '#description' => t('Required password field, max length 20 characters.'),
  );

  $form['posting_settings'] = array(
    '#type' => 'radios',
    '#title' => t('Preview comment'),
    '#options' => array(t('Optional'), t('Required')),
    '#required' => TRUE,
    '#description' => t('Required radios'),
  );

  $form['feed'] = array(
    '#type' => 'select',
    '#title' => t('Display of XML feed items'),
    '#required' => TRUE,
    '#options' => array(
      '' => t('--select--'),
      'title' => t('Titles only'),
      'teaser' => t('Titles plus teaser'),
      'fulltext' => t('Full text'),
    ),
    '#description' => t('Required selectbox'),
  );

  $form['feed2'] = array(
    '#type' => 'select',
    '#title' => t('Multiple items'),
    '#multiple' => 3,
    '#required' => TRUE,
    '#options' => array(
      '' => t('--select--'),
      'title' => t('Titles only'),
      'teaser' => t('Titles plus teaser'),
      'fulltext' => t('Full text'),
    ),
    '#description' => t('Required multiple selectbox.'),
  );

  $form['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#required' => TRUE,
    '#maxlength' => 50,
    '#description' => t('Required textarea, max length 50 characters.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#weight' => 100
  );

  return $form;
}

/**
 * Form callback for HTML5 elements
 */
function clientside_validation_testswarm_html5($form, &$form_state) {
  $form['info'] = array(
    '#markup' => '<p><strong>' . t('Clientside Validation Testswarm - HTML5') . '</strong></p><p>' . t('For this test, the "Replace HTML5 validation with Clientside Validation" option must be set to "Yes"') . '</p>',
  );

  $form['mynumber'] = array(
    '#type' => 'numberfield',
    '#title' => t('HTML 5 number element'),
    '#description' => t('HTML 5 number element. Enter a number between 1.1 and 5.1 with steps of 1 (so: [1.1, 2.1, 3.1, 4.1, 5.1])'),
    '#min' => 1,
    '#max' => 5,
    '#step' => 0.5,
    '#required' => TRUE,
  );

  $form['myurl'] = array(
    '#type' => 'urlfield',
    '#title' => t('HTML 5 url element'),
    '#description' => t('HTML 5 url element. Enter a valid absolute url.'),
    '#required' => TRUE,
  );

  $form['myemail'] = array(
    '#type' => 'emailfield',
    '#title' => t('HTML 5 email element'),
    '#description' => t('HTML 5 email element. Enter a valid email.'),
    '#required' => TRUE,
  );

  $form['myrange'] = array(
    '#type' => 'rangefield',
    '#title' => t('HTML 5 range element'),
    '#description' => t('HTML 5 range element. Enter a number between 2 and 5 with steps of 0.5 (so:[2, 2.5, 3, 3.5, 4, 4.5, 5].'),
    '#min' => 2,
    '#max' => 5,
    '#step' => 0.5,
    '#required' => TRUE,
  );

  $form['mynumbermin'] = array(
    '#type' => 'numberfield',
    '#title' => t('Number min only'),
    '#description' => t('Number element. Minimum only'),
    '#min' => 2,
    '#step' => 'any',
    '#required' => TRUE,
  );

  $form['mynumbermax'] = array(
    '#type' => 'numberfield',
    '#title' => t('Number max only'),
    '#description' => t('Number element. Maximum only'),
    '#max' => 255,
    '#step' => 'any',
    '#required' => TRUE,
  );

  $form['mynumberminmax'] = array(
    '#type' => 'numberfield',
    '#title' => t('Number min and max'),
    '#description' => t('Number element. Minimum and maximum set'),
    '#min' => 2,
    '#max' => 255,
    '#step' => 'any',
    '#required' => TRUE,
  );

  $form['mynumberint'] = array(
    '#type' => 'numberfield',
    '#title' => t('Number integer'),
    '#description' => t('Number element. Integer only'),
    '#min' => 2,
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#weight' => 100
  );
  return $form;
}

/**
 * Form callback for fapi elements with fapi_validation rules.
 */
function clientside_validation_testswarm_fapi_validation($form, &$form_state) {
  $form['info'] = array(
    '#markup' => '<p><strong>' . t('Clientside Validation Testswarm - FAPI Validation') . '</strong></p>',
  );

  $form['numeric'] = array(
    '#type' => 'textfield',
    '#title' => t('Numeric'),
    '#description' => t('Numeric values only'),
    '#required' => TRUE,
    '#rules' => array(
      'numeric',
    ),
  );
  
  $form['length_range'] = array(
    '#type' => 'textfield',
    '#title' => t('Range length'),
    '#description' => t('Enter text - 10 characters maximum, 5 minimum'),
    '#required' => TRUE,
    '#rules' => array(
      'length[5, 10]',
    ),
  );

  $form['chars'] = array(
    '#type' => 'textfield',
    '#title' => t('Chars'),
    '#description' => t('Enter text - only use charachters a, b and c'),
    '#required' => TRUE,
    '#rules' => array(
      'chars[a, b, c]',
    ),
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#description' => t('Enter a valid email address'),
    '#required' => TRUE,
    '#rules' => array(
      'email',
    ),
  );

  $form['url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#description' => t('Enter a valid url'),
    '#required' => TRUE,
    '#rules' => array(
      'url',
    ),
  );

  $form['ipv4'] = array(
    '#type' => 'textfield',
    '#title' => t('IPv4'),
    '#description' => t('Enter a valid IPv4 IP'),
    '#required' => TRUE,
    '#rules' => array(
      'ipv4',
    ),
  );

  $form['alpha_numeric'] = array(
    '#type' => 'textfield',
    '#title' => t('Alpha Numeric'),
    '#description' => t('Enter text - alphanumeric characters only'),
    '#required' => TRUE,
    '#rules' => array(
      'alpha_numeric',
    ),
  );

  $form['alpha_dash'] = array(
    '#type' => 'textfield',
    '#title' => t('Alpha dash'),
    '#description' => t('Enter text - alpha characters and dash (-) only'),
    '#required' => TRUE,
    '#rules' => array(
      'alpha_dash',
    ),
  );

  $form['digit'] = array(
    '#type' => 'textfield',
    '#title' => t('Digit'),
    '#description' => t('Enter text - digits only (no dots or dashes)'),
    '#required' => TRUE,
    '#rules' => array(
      'digit',
    ),
  );

  $form['decimal_limited'] = array(
    '#type' => 'textfield',
    '#title' => t('Decimal (limited)'),
    '#description' => t('Enter text - valid decimal value, 2 digits, 3 decimals'),
    '#required' => TRUE,
    '#rules' => array(
      'decimal[2, 3]',
    ),
  );

  $form['regex'] = array(
    '#type' => 'textfield',
    '#title' => t('Regex'),
    '#description' => t('Enter text - machine_name (alphanumeric and underscores)'),
    '#required' => TRUE,
    '#rules' => array(
      'regexp[/^[a-z0-9_]+$/]',
    ),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
    '#weight' => 100
  );

  return $form;

}