<?php
/**
 * @file
 * Contains the composite exposed form plugin.
 */

class views_composite_exposed_form_plugin extends views_plugin_exposed_form {
  var $plugins = array();

  function init(&$view, &$display, $options = array()) {
    parent::init($view, $display, $options);
    // Instantiate each of our contained plugins, just like views_plugin_display does.
    foreach ($this->options['plugins'] as $name) {
      $plugin = views_get_plugin('exposed_form', $name);
      if (empty($plugin)) continue;
      $options = isset($this->options[$name]) ? $this->options[$name] : array();
      $options += array_intersect_key($this->options, parent::option_definition());
      $plugin->init($view, $display, $options);
      $this->plugins[$name] = $plugin;
    }
  }

  function summary_title() {
    $plugins = array_intersect_key(views_fetch_plugin_names('exposed_form'), array_flip($this->options['plugins']));
    if (empty($plugins)) {
      $plugins[] = t('(none)');
    }
    return t('Composite: !plugins', array('!plugins' => implode(', ', $plugins)));
  }

  function option_definition() {
    views_include('admin');
    $options = $parent_options = parent::option_definition();
    $options['plugins'] = array('default' => array());
    foreach (array_keys(views_fetch_plugin_names('exposed_form')) as $name) {
      if ($name == 'composite') continue;
      $plugin = views_get_plugin('exposed_form', $name);
      $options[$name] = $plugin->option_definition();
      $options[$name] = array_diff_key($options[$name], $parent_options);
    }
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $parent_form = $form;
    $options = views_fetch_plugin_names('exposed_form');
    unset($options['composite']);
    $form['plugins'] = array(
      '#type' => 'checkboxes',
      '#title' => t('Plugins'),
      '#options' => $options,
      '#default_value' => $this->options['plugins'],
      '#description' => t('When you choose new plugins, please click "Update" then edit again to select the new plugin settings.'),
    );
    foreach ($this->options['plugins'] as $name) {
      if (empty($name)) {
        continue;
      }
      $form[$name] = array(
        '#type' => 'fieldset',
        '#title' => $options[$name],
        '#tree' => TRUE,
      );
      $this->plugins[$name]->options_form($form[$name], $form_state);
      $form[$name] = array_diff_key($form[$name], $parent_form);
    }
  }
  
  function options_validate(&$form, &$form_state) {
    foreach ($this->plugins as $name => $plugin) {
      $plugin->options_validate($form[$name], $form_state);
    }
  }

  function options_submit(&$form, &$form_state) {
    foreach ($this->plugins as $name => $plugin) {
      $plugin->options_submit($form[$name], $form_state);
    }
  }

  function exposed_form_alter(&$form, &$form_state) {
    foreach ($this->plugins as $name => $plugin) {
      $plugin->exposed_form_alter($form, $form_state);
    }
  }

  function exposed_form_validate(&$form, &$form_state) {
    foreach ($this->plugins as $name => $plugin) {
      $plugin->exposed_form_validate($form, $form_state);
    }
  }

  function exposed_form_submit(&$form, &$form_state, &$exclude) {
    foreach ($this->plugins as $name => $plugin) {
      $plugin->exposed_form_submit($form, $form_state, $exclude);
    }
  }

  function pre_render($values) {
    foreach ($this->plugins as $name => $plugin) {
      $plugin->pre_render($values);
    }
  }

  function post_render(&$output) {
    foreach ($this->plugins as $name => $plugin) {
      $plugin->post_render($output);
    }
  }

  function pre_execute() {
    foreach ($this->plugins as $name => $plugin) {
      $plugin->pre_execute();
    }
  }
}

