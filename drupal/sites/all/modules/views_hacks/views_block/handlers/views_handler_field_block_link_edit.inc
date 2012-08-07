<?php

class views_handler_field_block_link_edit extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['module'] = 'module';
    $this->additional_fields['delta'] = 'delta';
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
  
  function render($values) {
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return l($text, 'admin/build/block/configure/'. $values->{$this->aliases['module']} .'/'. $values->{$this->aliases['delta']});
  }
}

