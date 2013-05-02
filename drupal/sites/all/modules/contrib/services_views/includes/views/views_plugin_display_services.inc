<?php
/**
 * @file
 * Contains the page display plugin.
 */

/**
 * The plugin that handles a Services callback.
 *
 * @ingroup views_display_plugins
 */
class views_plugin_display_services extends views_plugin_display {

  function option_definition() {
    $options = parent::option_definition();

    $options['path'] = array('default' => '');

    return $options;
  }

  /**
   * Execute implementation.
   */
  function execute() {

    // Prior to this being called, the $view should already be set to this
    // display, and arguments should be set on the view.
    $this->view->build();

    // Execute a view.
    $this->view->execute();

    // Map fields.
    $result = array();
    foreach ($this->view->result as $item) {
      $new_item = new stdClass();
      foreach ($this->view->field as $field) {
        if (isset($item->{$field->field_alias})) {
          // Make sure new keys are alphanumerical, underscore and dash.
          if (!empty($field->options['label']) && preg_match('/^[0-9a-z_-]*$/', $field->options['label'])) {
            $new_item->{$field->options['label']} = $item->{$field->field_alias};
          }
          else {
            $new_item->{$field->field_alias} = $item->{$field->field_alias};
          }
        }
      }
      if (!empty($new_item)) {
        $result[] = $new_item;
      }
    }

    return $result;
  }

  function render() {
    return $this->execute();
  }

  function preview() {
    return '<pre>' . var_export($this->execute(), TRUE) . '</pre>';
  }

  /**
   * Provide the summary for page options in the views UI.
   *
   * This output is returned as an array.
   */
  function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);

    $categories['page'] = array(
      'title' => t('Services settings'),
      'column' => 'second',
      'build' => array(
        '#weight' => -10,
      ),
    );

    $path = strip_tags('/' . $this->get_option('path'));
    if (empty($path)) {
      $path = t('None');
    }

    $options['path'] = array(
      'category' => 'page',
      'title' => t('Path'),
      'value' => views_ui_truncate($path, 24),
    );
  }

  /**
   * Provide the default form for setting options.
   */
  function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      case 'path':
        $form['#title'] .= t('Path of the Services resource');
        $form['#help_topic'] = 'path';
        $form['path'] = array(
          '#type' => 'textfield',
          '#description' => t('This is path element that comes after endpoint path.'),
          '#default_value' => $this->get_option('path'),
        );
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
}
