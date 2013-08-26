<?php
/**
 * @file
 * Admin settings for Clientside Validation
 */

function clientside_validation_general_settings_form($form_id, $form_state) {
  drupal_set_title(t('Edit general settings'));

  //jquery.validate.js settings
  $form['clientside_validation_min'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Use minified version of jquery.validate.js'),
    '#description' => t('You can use the minified version of the library.'),
  );

  $form['clientside_validation_min']['clientside_validation_use_minified'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#default_value' => variable_get('clientside_validation_use_minified', 0),
    '#title' => t('Use minified version?'),
  );

  //jquery.form.js settings
  $form['clientside_validation_jquery_form'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Override the version of jquery.form.js'),
    '#description' => t('This is needed for IE < 9 support for #ajax forms.'),
  );

  $form['clientside_validation_jquery_form']['clientside_validation_override_jquery_form'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#default_value' => variable_get('clientside_validation_override_jquery_form', 0),
    '#title' => t('Use jquery.form.js version 3.09 (16-APR-2012)?'),
  );

  //Page settings
  $form['clientside_validation_pages'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Paths'),
    '#description' => t('Include or exclude paths for Clientside Validation.'),
  );

  $form['clientside_validation_pages']['clientside_validation_filter_paths'] = array(
    '#type' => 'radios',
    '#options' => array(
      CLIENTSIDE_VALIDATION_EXCLUDE_PATHS => t('Add Clientside Validation on all paths except those specified below'),
      CLIENTSIDE_VALIDATION_INCLUDE_PATHS => t('Only add Clientside Validation on the paths specified below'),
    ),
    '#default_value' => variable_get('clientside_validation_filter_paths', CLIENTSIDE_VALIDATION_EXCLUDE_PATHS),
    '#title' => t('Include or exclude paths'),
  );

  $form['clientside_validation_pages']['clientside_validation_path_list'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('clientside_validation_path_list', 'admin/structure/views/view/*'),
    '#title' => t("Enter paths"),
    '#description' => t("Enter one page per line as Drupal paths.
      The '*' character is a wildcard. Example paths are %blog for the blog page and
      %blog-wildcard for every personal blog. %front is the front page.",
      array('%blog' => 'blog', '%blog-wildcard' => 'blog/*', '%front' => '<front>')),
  );

  //Form settings
  $form['clientside_validation_validate_forms'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Forms to validate'),
  );

  $form['clientside_validation_validate_forms']['clientside_validation_validate_all'] = array(
    '#type' => 'radios',
    '#default_value' => variable_get('clientside_validation_validate_all', CLIENTSIDE_VALIDATION_VALIDATE_ALL),
    '#title' => t('Select the forms to validate'),
    '#options' => array(
      CLIENTSIDE_VALIDATION_VALIDATE_ALL => t('Validate all forms'),
      CLIENTSIDE_VALIDATION_VALIDATE_SPECIFIC => t('Only validate forms listed below'),
      CLIENTSIDE_VALIDATION_VALIDATE_ALL_EXCEPT => t('Validate all forms except those listed below')
    )
  );

  $form['clientside_validation_validate_forms']['clientside_validation_validate_specific'] = array(
    '#type' => 'textarea',
    '#default_value' => variable_get('clientside_validation_validate_specific', ''),
    '#title' => t("Enter form IDs below"),
    '#description' => t('You can specify form IDs (one per line, use _) of forms that should or should not be validated.'),
    '#states' => array(
      'invisible' => array(
       'input[name="clientside_validation_validate_all"]' => array('value' => (string)CLIENTSIDE_VALIDATION_VALIDATE_ALL),
      ),
    ),
  );

  if (module_exists('xregexp_api')) {
    $lib = libraries_detect('xregexp');
    if ($lib && $lib['installed']) {
      //XRegExp settings
      $form['clientside_validation_xregxp'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#title' => t('XRegExp for Pattern matching'),
        '#description' => t("Javascript doesn't support regular expressions for
          pattern matching the way PHP does. With the XRegExp library most PHP
          expressions(pregex) become also available in Javascript. So you might
          want to use that instead of AJAX calls."),
      );

      $form['clientside_validation_xregxp']['clientside_validation_usexregxp'] = array(
        '#prefix' => '<br />',
        '#title' => t('Use XRegExp'),
        '#description' => t('Check to use XRegExp for PCRE.'),
        '#type' => 'checkbox',
        '#default_value' => variable_get('clientside_validation_usexregxp', 0),
      );
      $options = array('' => t('default'));
      foreach ($lib['variants'] as $name => $variant) {
        if (!isset($variant['error']) || !$variant['error']) {
          $options[$name] = $name;
        }
      }
      $form['clientside_validation_xregxp']['clientside_validation_xregxp_variant'] = array(
        '#title' => t('XRegExp variant'),
        '#description' => t('Choose which variant of the library you want to use.'),
        '#type' => 'select',
        '#options' => $options,
        '#default_value' => variable_get('clientside_validation_xregxp_variant', ''),
      );
      if (version_compare($lib['version'], '2', '>=')) {
        $form['clientside_validation_xregxp']['clientside_validation_xregxp_variant']['#description'] .= '<br />' .
        t('!warning: You are using version 2.x or higher of the XRegExp library.
          For best compatibility (including some !fapi rules) you should enable
          the backcompat.js plugin on the !settingspage',
          array(
            '!warning' => '<strong>Warning</strong>',
            '!fapi' => l(t('FAPI Validation'), 'http://drupal.org/project/fapi_validation'),
            '!settingspage' => l(t('XRegExp API Settings page'), 'admin/config/system/xregexp'),
          )
        );
      }
    }
  }

  $form = system_settings_form($form);
  return $form;
}

function clientside_validation_settings_form($form, $form_state, $cvs_formid = NULL, $cvs_type = 'default') {
  $settings = clientside_validation_settings_load($cvs_type, $cvs_formid, TRUE);
  $form['new'] = array(
    '#type' => 'value',
    '#value' => FALSE,
  );
  if ($cvs_type == 'default') {
    drupal_set_title(clientside_validation_settings_title($cvs_type, $cvs_formid, TRUE), PASS_THROUGH);
  }
  else {
    if (!$settings || $settings['settings'] === FALSE || empty($settings['form_id'])) {
      $settings = clientside_validation_settings_load_defaults();
      drupal_set_title(clientside_validation_settings_title($cvs_type, $cvs_formid, FALSE), PASS_THROUGH);
      $form['new'] = array(
        '#type' => 'value',
        '#value' => TRUE,
      );
    }
    else {
      drupal_set_title(clientside_validation_settings_title($cvs_type, $cvs_formid, TRUE), PASS_THROUGH);
    }
  }

  // Make sure settings aren't nested.
  if (isset($settings['settings']) && is_array($settings['settings'])) {
    $settings = $settings['settings'];
  }

  $form['#tree'] = TRUE;
  $form['cvs_formid'] = array(
    '#type' => 'value',
    '#value' => $cvs_formid,
  );
  $form['cvs_type'] = array(
    '#type' => 'value',
    '#value' => $cvs_type,
  );

  //Validate options
  $form['validate_options'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Validate options'),
    '#weight' => 10,
  );

  if (module_exists('clientside_validation_html5')) {
    $form['validate_options']['disable_html5'] = array(
      '#type' => 'radios',
      '#options' => array(
        '1' => t('Yes'),
        '0' => t('No'),
      ),
      '#title' => t('Replace HTML5 validation with Clientside Validation'),
      '#default_value' => $settings['validate_options']['disable_html5'],
      '#description' => t('Replace HTML5 validation with Clientside Validation on forms that have Clientside Validation enabled'),
    );
  }
  else {
    $form['validate_options']['disable_html5'] = array(
      '#type' => 'value',
      '#value' => $settings['validate_options']['disable_html5'],
    );
  }

  if (module_exists('clientside_validation_form')) {
    $form['validate_options']['captcha'] = array(
      '#type' => 'radios',
      '#options' => array(
        '1' => t('Yes'),
        '0' => t('No'),
      ),
      '#title' => t('Validate CAPTCHA'),
      '#default_value' => $settings['validate_options']['captcha'],
      '#description' => t('Enable or disable Clientside Validation for CAPTCHA elements'),
    );
  }
  else {
    $form['validate_options']['captcha'] = array(
      '#type' => 'value',
      '#value' => $settings['validate_options']['captcha'],
    );
  }

  $form['validate_options']['validate_onsubmit'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#title' => t('Validate fields on submit'),
    '#description' => t('"No" disables onsubmit validation, allowing the user to submit whatever he wants, while still validating on keyup/blur/click events (if not specified otherwise).'),
    '#default_value' => $settings['validate_options']['validate_onsubmit'],
  );

  $form['validate_options']['validate_onblur'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#title' => t('Validate fields on blur'),
    '#description' => t('Validate elements (except checkboxes/radio buttons) on blur. <strong>If nothing is entered, all rules are skipped, except when the field was already marked as invalid.</strong>'),
    '#default_value' => $settings['validate_options']['validate_onblur'],
  );

  $form['validate_options']['validate_onblur_always'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#title' => t('Always validate fields on blur'),
    '#description' => t('Validate elements (except checkboxes/radio buttons) on blur, <strong>even nothing is entered before or if the fields hasn\'t been marked as invalid before.</strong>'),
    '#default_value' => $settings['validate_options']['validate_onblur_always'],
    '#states' => array(
      'visible' => array(
        ':input[name="validate_options[validate_onblur]"]' => array('value' => 1),
      ),
    ),
  );

  $form['validate_options']['validate_onkeyup'] = array(
    '#type' => 'radios',
    '#options' => array(
      '1' => t('Yes'),
      '0' => t('No'),
    ),
    '#title' => t('Validate fields on key up'),
    '#description' => t('Validate elements on keyup. <strong>As long as the field is not marked as invalid, nothing happens</strong>. Otherwise, all rules are checked on each key up event.'),
    '#default_value' => $settings['validate_options']['validate_onkeyup'],
  );

  $form['validate_options']['show_messages'] = array(
    '#type' => 'radios',
    '#options' => array(
      '0' => t('Show all error messages'),
      '1' => t('Show only first error message'),
      '2' => t('Show only last error message'),
    ),
    '#title' => t('Show these error messages on validation'),
    '#default_value' => $settings['validate_options']['show_messages'],
    '#description' => t('Warning: Showing only the first or last message only works if the error messages are displayed on top of the form. When they are displayed inline this setting will not be applied.'),
    '#states' => array(
      'visible' => array(
        ':input[name="error_placement[error_placement_default]"]' => array('value' => CLIENTSIDE_VALIDATION_TOP_OF_FORM),
      ),
    ),
  );

  //Error message settings
  $form['error'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Error message settings'),
    '#weight' => 20,
  );

  $form['error']['prefix'] = array(
    '#title' => t('Field name prefix'),
    '#description' => t('The prefix of the field name in the error messages.'),
    '#type' => 'textfield',
    '#default_value' => $settings['error']['prefix'],
  );

  $form['error']['suffix'] = array(
    '#title' => t('Field name suffix'),
    '#description' => t('The suffix of the field name in the error messages.'),
    '#type' => 'textfield',
    '#default_value' => $settings['error']['suffix'],
  );

  $form['error']['example_image'] = array(
    '#type' => 'item',
    '#title' => t('Example'),
    '#markup' => '<img id="example_image" src="' . base_path() . drupal_get_path('module', 'clientside_validation') . '/errormsg.png" alt="' . t('Error message example') . '" />',
    '#description' => t('Filling in double quotes in both the above fields will give this result.'),
  );

  $form['error']['scrollto_errormessage'] = array(
    '#title' => t('Scroll to error message'),
    '#description' => t('If checked, the page will automatically scroll to the error messages when validation fails.'),
    '#type' => 'checkbox',
    '#default_value' => $settings['error']['scrollto_errormessage'],
  );

  $form['error']['scroll_speed'] = array(
    '#title' => t('Scroll speed'),
    '#description' => t('The scroll speed in milliseconds'),
    '#type' => 'textfield',
    '#default_value' => $settings['error']['scroll_speed'],
    '#states' => array(
      'visible' => array(
        ':input[name="error[scrollto_errormessage]"]' => array('checked' => TRUE),
      ),
    ),
  );

  $form['error']['error_element'] = array(
    '#title' => t('Error Element'),
    '#description' => t('The HTML element to wrap the errors in. Defaults to label.'),
    '#type' => 'select',
    '#options' => drupal_map_assoc(array('label', 'span', 'div')),
    '#default_value' => $settings['error']['error_element'],
  );

  if (module_exists('fapi_validation') && module_exists('fapi')) {
    $form['error']['scroll_speed'] += array('#rules' => array('numeric'));
  }

  //Error Placement
  $form['error_placement'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#title' => t('Error message placement'),
    '#weight' => 30,
  );

  $form['error_placement']['error_placement_default'] = array(
    '#type' => 'select',
    '#title' => t('Default location'),
    '#description' => t('Default location to show the error messages.
      If you choose "jQuery selector", provide a valid jQuery selector in the appropriate textfield.
      If you choose "Custom function", provide the name of the custom javascript function.
      The function needs to be declared on the Drupal.clientsideValidation object prototype. You can find
      further details in the clientside_validation.api.js file.
      This function will be given to !errorPlacement.',
      array(
        '!errorPlacement' =>
        l(t('the errorPlacement option of jQuery.validate()'), 'http://docs.jquery.com/Plugins/Validation/validate#options')
      )
    ),
    '#options' => array(
      CLIENTSIDE_VALIDATION_JQUERY_SELECTOR => t('jQuery selector'),
      CLIENTSIDE_VALIDATION_TOP_OF_FORM => t('Top of form'),
      CLIENTSIDE_VALIDATION_BEFORE_LABEL => t('Before label'),
      CLIENTSIDE_VALIDATION_AFTER_LABEL => t('After label'),
      CLIENTSIDE_VALIDATION_BEFORE_INPUT => t('Before input'),
      CLIENTSIDE_VALIDATION_AFTER_INPUT => t('After input'),
      CLIENTSIDE_VALIDATION_TOP_OF_FIRST_FORM => t('Top of first form'),
      CLIENTSIDE_VALIDATION_CUSTOM_ERROR_FUNCTION => t('Custom function'),
    ),
    '#default_value' => $settings['error_placement']['error_placement_default'],
  );

  $form['error_placement']['jquery_selector'] = array(
    '#type' => 'textfield',
    '#title' => t('jQuery selector'),
    '#description' => t('Enter a jQuery selector here if you selected "jQuery selector" in the previous step.
                      The error messages will be shown in this div if it exists.
                      If it doesn\'t, error messages will be shown above the first form on the page.'),
    '#default_value' => $settings['error_placement']['jquery_selector'],
    '#states' => array(
      'visible' => array(
        ':input[name="error_placement[error_placement_default]"]' => array('value' => CLIENTSIDE_VALIDATION_JQUERY_SELECTOR),
      ),
    ),
  );

  $form['error_placement']['custom_error_function'] = array(
    '#type' => 'textfield',
    '#title' => t('Custom function name'),
    '#description' => t('If you selected "Custom function" in the previous step, provide the name of the custom javascript function.
      This function will be given to !errorPlacement',
      array(
        '!errorPlacement' =>
        l(t('the errorPlacement option of jQuery.validate()'), 'http://docs.jquery.com/Plugins/Validation/validate#options')
      )),
    '#default_value' => $settings['error_placement']['custom_error_function'],
    '#states' => array(
      'visible' => array(
        ':input[name="error_placement[error_placement_default]"]' => array('value' => CLIENTSIDE_VALIDATION_CUSTOM_ERROR_FUNCTION),
      ),
    ),
  );

  //Hidden fields and tabs
  $form['include_hidden'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hidden fields and tabs'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => 40,
  );

  $form['include_hidden']['include_hidden_fields'] = array(
    '#type' => 'checkbox',
    '#default_value' => $settings['include_hidden']['include_hidden_fields'],
    '#title' => t('Validate hidden fields'),
    '#description' => t('Validate hidden fields as well.'),
    '#weight' => 2,
  );

  $form['include_hidden']['validate_tabs'] = array(
    '#type' => 'checkbox',
    '#default_value' => $settings['include_hidden']['validate_tabs'],
    '#title' => t('Validate all tabs'),
    '#description' => t('If you check this, all tabs will be validated (both vertical and horizontal) on submit
                      (including the hidden ones). Warning: if there are other hidden
                      fields (e.g. conditional fields), those will be validated too.'),
    '#weight' => 3,
  );
  if ($cvs_type == 'default') {
    $form['include_hidden']['include_hidden'] = array(
      '#type' => 'textarea',
      '#default_value' => $settings['include_hidden']['include_hidden'],
      '#title' => t("Don't ignore hidden fields on the following forms"),
      '#description' => t('You can specify form IDs (one per line) of forms that should have hidden elements validated.'),
      '#weight' => 1,
    );
  }
  else {
    $fieldsets = array(
      'validate_options' => 'Validate options',
      'error' => 'Error message settings',
      'error_placement' => 'Error message placement',
      'include_hidden' => 'Hidden fields and vertical tabs',
    );
    foreach ($fieldsets as $key => $fieldset) {
      $statefield = ':input[name="' . $key . '_override_default"]';
      $form[$key]['#states'] = array(
        'visible' => array(
          $statefield => array('checked' => TRUE),
        ),
      );

      $form[$key . '_override_default'] = array(
        '#type' => 'checkbox',
        '#title' => t('Override default options for %fieldset', array('%fieldset' => $fieldset)),
        '#description' => t('Check this to override the default validate options'),
        '#default_value' => isset($settings[$key . '_override_default']) && $settings[$key . '_override_default'] ,
        '#weight' => $form[$key]['#weight'] - 1,
      );
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#weight' => 50,
  );

  return $form;
}

function clientside_validation_settings_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $cvs_type = $values['cvs_type'];
  $cvs_formid = $values['cvs_formid'];
  $new = $values['new'];

  unset($values['submit']);
  unset($values['form_build_id']);
  unset($values['form_token']);
  unset($values['form_id']);
  unset($values['op']);
  unset($values['cvs_type']);
  unset($values['cvs_formid']);
  unset($values['new']);

  if ($cvs_type == 'default') {
    variable_set('clientside_validation_default_settings', $values);
  }
  else {
    // Remove not overloaded settings
    foreach (array('validate_options', 'error', 'error_placement', 'include_hidden') as $set) {
      if (isset($values[$set . '_override_default']) && $values[$set . '_override_default'] === 0) {
        unset($values[$set]);
      }
    }
    if (!$new) {
      clientside_validation_settings_update($cvs_type, $cvs_formid, $values);
    }
    else {
      clientside_validation_settings_add($cvs_type, $cvs_formid, $values, TRUE);
    }
  }
}

function _cv_setting_status($status) {
  if ($status) {
    return t('Enabled');
  }
  return t('Disabled');
}

function clientside_validation_settings_overview($form, $form_state, $cvs_type) {
  $form = array();
  $settings = clientside_validation_settings_load($cvs_type, NULL, TRUE);
  $definedforms = array();
  $empty_text = "";
  switch ($cvs_type) {
    case 'content-types':
      $destination = array('destination' => 'admin/config/validation/clientside_validation/content-types');
      $settinguri = 'admin/config/validation/clientside_validation/content-types/';
      $headerlabel = t('Content type');
      $empty_text = t('No content types available');

      $content_types = node_type_get_types();
      foreach ($content_types as $content_type) {
        $definedforms[] = array(
          'id' => $content_type->type,
          'label' => t($content_type->name),
        );
      }
      break;

    case 'webforms':
      $destination = array('destination' => 'admin/config/validation/clientside_validation/webforms');
      $settinguri = 'admin/config/validation/clientside_validation/webforms/';
      $headerlabel = t('Webforms');
      $empty_text = t('No webforms available');

      $webform_types = webform_variable_get('webform_node_types');
      $nodes = array();
      if ($webform_types) {
        $nodes = db_select('node', 'n')
          ->fields('n')
          ->condition('n.type', $webform_types, 'IN')
          ->execute()
          ->fetchAllAssoc('nid');

        foreach ($nodes as $node) {
          $definedforms[] = array(
            'id' => $node->nid,
            'label' => l($node->title, 'node/' . $node->nid),
          );
        }
      }
      break;

    case 'custom-forms':
      $destination = array('destination' => 'admin/config/validation/clientside_validation/custom-forms');
      $settinguri = 'admin/config/validation/clientside_validation/custom-forms/';
      $headerlabel = t('Form Id');
      $empty_text = t('No custom forms added yet');

      foreach ($settings as $customform) {
        $definedforms[] = array(
          'id' => $customform->form_id,
          'label' => $customform->form_id,
        );
      }
      $form['cvs_type'] = array(
        '#type' => 'value',
        '#value' => $cvs_type,
      );
      $form['add_formid'] = array(
        '#type' => 'fieldset',
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
        '#title' => t('Add a new custom form'),
        '#description' => t('Enter the formid of the form you want to override.'),
      );
      $form['add_formid']['cvs_formid'] = array(
        '#title' => t('Form Id'),
        '#type' => 'textfield',
      );
      $form['add_formid']['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Add Form Id'),
        '#weight' => 50,
      );
      break;
  }

  $rows = array();
  if ($definedforms) {
    foreach ($definedforms as $definedform) {
      $row = array();
      $row[] = $definedform['label'];
      if (isset($settings[$definedform['id']]) && $settings[$definedform['id']]->status) {
        $cvs_formid = check_plain($definedform['id']);
        $row[] = _cv_setting_status(TRUE);
        $actions = array(
          'edit' => array(
            'title' => t('edit'),
            'href' => $settinguri . $cvs_formid . '/edit',
            'query' => $destination,
          ),
          'disable' => array(
            'title' => t('disable'),
            'href' => $settinguri . $cvs_formid . '/disable',
            'query' => $destination,
          ),
          'delete' => array(
            'title' => t('delete'),
            'href' => $settinguri . $cvs_formid . '/delete',
            'query' => $destination,
          ),
        );
      }
      else {
        $row[] = _cv_setting_status(FALSE);
        if (isset($settings[$definedform['id']])) {
          $cvs_formid = check_plain($definedform['id']);
          $actions = array(
            'edit' => array(
              'title' => t('edit'),
              'href' => $settinguri . $cvs_formid . '/edit',
              'query' => $destination,
            ),
            'enable' => array(
              'title' => t('enable'),
              'href' => $settinguri . $cvs_formid . '/enable',
              'query' => $destination,
            ),
            'delete' => array(
              'title' => t('delete'),
              'href' => $settinguri . $cvs_formid . '/delete',
              'query' => $destination,
            ),
          );
        }
        else {
          $actions = array(
            'edit' => array(
              'title' => t('create'),
              'href' => $settinguri . check_plain($definedform['id']) . '/edit',
              'query' => $destination,
            ),
          );
        }
      }
      $row[] = array(
        'data' => array(
          '#theme' => 'links__node_operations',
          '#links' => $actions,
          '#attributes' => array('class' => array('links', 'inline')),
        ),
      );
      $rows[] = $row;
    }
  }

  $header = array(
    $headerlabel,
    t('Status'),
    t('Actions'),
  );
  $form[str_replace('-', '', $cvs_type)] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
    '#empty' => $empty_text,
  );

  return $form;
}

function clientside_validation_settings_overview_submit($form, &$form_state) {
  $values = $form_state['values'];

  $cvs_type = $values['cvs_type'];
  $cvs_formid = $values['cvs_formid'];
  clientside_validation_settings_add($cvs_type, $cvs_formid);
}

function clientside_validation_settings_confirmation_form($form, &$form_state, $cvs_formid, $cvs_type, $action) {
  $form['#cvs_action'] = $action;
  $form['#cvs_type'] = $cvs_type;
  $form['#cvs_formid'] = $cvs_formid;

  switch ($action) {
    case 'delete':
      $question = 'Are you sure you want to delete these settings';
      $info = 'This action cannot be undone.';
      break;
    case 'enable':
      $question = 'Are you sure you want to enable these settings';
      $info = 'You can always disable it later.';
      break;
    case 'disable':
      $question = 'Are you sure you want to disable these settings';
      $info = 'You can always enable it later.';
      break;
  }

  return confirm_form(
    $form,
    t($question),
    'admin/config/validation/clientside_validation', // destination is used
    t($info),
    t(drupal_ucfirst($action)),
    t('Cancel')
  );
}

function clientside_validation_settings_confirmation_form_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $action = $form['#cvs_action'];
    $cvs_type = $form['#cvs_type'];
    $cvs_formid = $form['#cvs_formid'];

    switch ($action) {
      case 'delete':
        clientside_validation_settings_delete($cvs_type, $cvs_formid);
        break;
      case 'enable':
        clientside_validation_settings_enable($cvs_type, $cvs_formid);
        break;
      case 'disable':
        clientside_validation_settings_disable($cvs_type, $cvs_formid);
        break;
    }
    $form_state['redirect'] = 'admin/config/validation/clientside_validation/' . $cvs_type;
  }
}
