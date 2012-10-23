<?php

/**
 * Filter based on regular expression.
 */
class views_handler_filter_regex extends views_handler_filter {
  var $no_single = TRUE;

  function operator_options() {
    return array(
      'REGEXP' => t('Matches regex'),
      'NOT REGEXP' => t('Does not match regex'),
    );
  }

  function admin_summary() {
    if (!empty($this->options['exposed'])) {
      return t('exposed');
    }
    return parent::admin_summary();
  }

  function value_form(&$form, &$form_state) {
    $form['value'] = array(
      '#type' => 'textfield',
      '#title' => t('Value'),
      '#size' => 30,
      '#default_value' => $this->value,
    );
  }
}

