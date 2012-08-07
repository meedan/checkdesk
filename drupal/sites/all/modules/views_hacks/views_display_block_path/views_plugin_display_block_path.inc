<?php

class views_plugin_display_block_path extends views_plugin_display_block {
  function option_definition() {
    $options = parent::option_definition();
    $options['path'] = array('default' => '');
    return $options;
  }

  function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);

    $path = strip_tags($this->get_option('path'));
    if (empty($path)) {
      $path = t('None');
    }
    if (strlen($path) > 16) {
      $path = substr($path, 0, 16) . '...';
    }
    $options['path'] = array(
      'category' => 'block',
      'title' => t('Path'),
      'value' => $path,
    );
  }

  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      case 'path':
        $form['#title'] .= t('URL of this block');
        $form['#help_topic'] = 'path';
        $form['path'] = array(
          '#type' => 'textfield',
          '#description' => t('The URL reported by this block. Leave blank to return the URL of the page in which the block is embedded.'),
          '#default_value' => $this->get_option('path'),
          '#field_prefix' => '<span dir="ltr">' . url(NULL, array('absolute' => TRUE)) . (variable_get('clean_url', 0) ? '' : '?q='),
          '#field_suffix' => '</span>&lrm;',
          '#attributes' => array('dir'=>'ltr'),
        );
        break;
    }
  }

  function options_validate(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_validate($form, $form_state);
    switch ($form_state['section']) {
      case 'path':
        // automatically remove '/' from path.
        $form_state['values']['path'] = trim($form_state['values']['path'], '/');
        break;
    }
  }

  function options_submit(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_submit($form, $form_state);
    switch ($form_state['section']) {
      case 'path':
        $this->set_option('path', $form_state['values']['path']);
        break;
    }
  }

  function uses_exposed() {
    // bypass views_plugin_display_block's logic.
    return views_plugin_display::uses_exposed();
  }

  function has_path() {
    // avoid interfering with the admin forms.
    if (arg(0) == 'admin' && arg(1) == 'build' && arg(2) == 'views') {
      return FALSE;
    }
    // set the path explicitly when Views reads it from the options.
    $this->set_option('path', $this->get_path());
    return TRUE;
  }

  function get_path() {
    return empty($this->options['path']) ? $_GET['q'] : $this->get_option('path');
  }
}

