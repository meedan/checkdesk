<?php

/**
 * Base class for area handlers.
 *
 * @ingroup views_area_handlers
 */
class views_autorefresh_handler_area_autorefresh extends views_handler_area {

  /**
   * Overrides views_handler_area::init().
   *
   * Reset override done in views_handler_area::init(). This area must be
   * rendered even if view has no results.
   */
  function init(&$view, &$options) {
    parent::init($view, $options);
  }

  function option_definition() {
    $options = array();
    $options['interval'] = array('default' => '');
    $options['incremental'] = array('default' => FALSE, 'bool' => TRUE);
    $options['display'] = array('default' => '');
    $options['sourceSelector'] = array('default' => '.view-content');
    $options['targetSelector'] = array('default' => '.view-content');
    $options['emptySelector'] = array('default' => '.view-empty');
    $options['afterSelector'] = array('default' => '.view-header');
    $options['targetStructure'] = array('default' => '<div class="view-content"></div>');
    $options['firstClass'] = array('default' => 'views-row-first');
    $options['lastClass'] = array('default' => 'views-row-last');
    $options['oddClass'] = array('default' => 'views-row-odd');
    $options['evenClass'] = array('default' => 'views-row-even');
    $options['rowClassPrefix'] = array('default' => 'views-row-');
    $options['ping'] = array('default' => FALSE, 'bool' => TRUE);
    $options['ping_base_path'] = array('default' => '');
    return $options;
  }

  function options_form(&$form, &$form_state) {
    $form['interval'] = array(
      '#type' => 'textfield',
      '#title' => t('Interval to check for new items'),
      '#default_value' => $this->options['interval'],
      '#field_suffix' => 'milliseconds',
      '#required' => TRUE,
    );
    $form['incremental'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use a secondary view display to incrementally insert new items only'),
      '#default_value' => $this->options['incremental'],
    );
    $options = array();
    foreach ($this->view->display as $display) {
      if ($display->display_plugin == 'page') {
        # TODO: check secondary display arguments.
        $options[$display->id] = $display->display_title;
      }
    }
    $form['display'] = array(
      '#type' => 'select',
      '#title' => t('Secondary display'),
      '#default_value' => $this->options['display'],
      '#description' => t('Only displays of type page are eligible. Additionally the display must have a timestamp argument of the <em>(with operator)</em> variant. For example <em>Node: Post date (with operator)</em>.'),
      '#options' => $options,
      '#dependency' => array(
        'edit-options-incremental' => array(1),
      ),
    );
    $form['incremental_advanced'] = array(
      '#type' => 'fieldset',
      '#title' => t('Advanced'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#tree' => FALSE,
      '#dependency' => array(
        'edit-options-incremental' => array(1),
      ),
      '#description' => t('Advanced settings for incremental display. Unless your view is using an overridden template, the defaults below should be fine.'),
    );
    $form['incremental_advanced']['sourceSelector'] = array(
      '#type' => 'textfield',
      '#title' => t('Source selector'),
      '#default_value' => $this->options['sourceSelector'],
      '#description' => t('A jQuery selector expression representing the main view container of your secondary display.'),
    );
    $form['incremental_advanced']['targetSelector'] = array(
      '#type' => 'textfield',
      '#title' => t('Target selector'),
      '#default_value' => $this->options['targetSelector'],
      '#description' => t('A jQuery selector expression representing the main view container of your primary display.'),
    );
    $form['incremental_advanced']['emptySelector'] = array(
      '#type' => 'textfield',
      '#title' => t('Empty selector'),
      '#default_value' => $this->options['emptySelector'],
      '#description' => t('A jQuery selector expression representing the main view container in case of empty results.'),
    );
    $form['incremental_advanced']['afterSelector'] = array(
      '#type' => 'textfield',
      '#title' => t('Header selector'),
      '#default_value' => $this->options['afterSelector'],
      '#description' => t('A jQuery selector expression representing the view header, in case the header is displayed with empty results.'),
    );
    $form['incremental_advanced']['targetStructure'] = array(
      '#type' => 'textfield',
      '#title' => t('Target structure'),
      '#default_value' => $this->options['targetStructure'],
      '#description' => t('An HTML fragment describing the view skeleton in case of empty results.'),
    );
    $form['incremental_advanced']['firstClass'] = array(
      '#type' => 'textfield',
      '#title' => t('First row class'),
      '#default_value' => $this->options['firstClass'],
      '#description' => t('A class to be added to the first result row.'),
    );
    $form['incremental_advanced']['lastClass'] = array(
      '#type' => 'textfield',
      '#title' => t('Last row class'),
      '#default_value' => $this->options['lastClass'],
      '#description' => t('A class to be added to the last result row.'),
    );
    $form['incremental_advanced']['oddClass'] = array(
      '#type' => 'textfield',
      '#title' => t('Odd rows class'),
      '#default_value' => $this->options['oddClass'],
      '#description' => t('A class to be added to each odd result row.'),
    );
    $form['incremental_advanced']['evenClass'] = array(
      '#type' => 'textfield',
      '#title' => t('Even rows class'),
      '#default_value' => $this->options['evenClass'],
      '#description' => t('A class to be added to each even result row.'),
    );
    $form['incremental_advanced']['rowClassPrefix'] = array(
      '#type' => 'textfield',
      '#title' => t('Row class prefix'),
      '#default_value' => $this->options['rowClassPrefix'],
      '#description' => t('The prefix of a class to be added to each result row. The row number will be appended to this prefix.'),
    );
    $form['ping'] = array(
      '#type' => 'checkbox',
      '#title' => t('Use a ping url'),
      '#default_value' => $this->options['ping'],
      '#description' => t('Use a custom script for faster check of new items. See <code>ping.php.example</code> in <code>views_autorefresh</code> folder for reference.'),
    );
    global $base_url;
    # TODO: offer to choose path to a module to better work out of the box with drupal_get_path() ?
    $form['ping_base_path'] = array(
      '#type' => 'textfield',
      '#title' => t('Path to the ping script'),
      '#default_value' => $this->options['ping_base_path'],
      '#description' => t('This url is relative to the Drupal root.'),
      '#dependency' => array(
        'edit-options-ping' => array(1),
      ),
    );
  }

  function options_validate(&$form, &$form_state) {
    if (!is_numeric($form_state['values']['options']['interval'])) {
      form_set_error('interval', t('Invalid interval.'));
    }
    # TODO: check the ping script actualy returns the json we are expecting?
    if ($form_state['values']['options']['ping']) {
      $ping_base_path = $form_state['values']['options']['ping_base_path'];
      if (!file_exists(DRUPAL_ROOT . '/' . $ping_base_path)) {
        form_set_error('ping_base_path', t('Ping script not found.'));
      }
    }
  }

  function options_submit(&$form, &$form_state) {
    $this->view->display_handler->set_option('use_ajax', TRUE);
  }

  function render($empty = FALSE) {
    $args = array();
    $args['view'] = $this->view;
    $args['interval'] = $this->options['interval'];
    if  ($this->options['ping']) {
      $args['ping'] = array(
        'ping_base_path' => $this->options['ping_base_path'],
      );
    }
    if  ($this->options['incremental']) {
      $display = $this->view->display[$this->options['display']];

      $args['incremental'] = array(
        'view_base_path' => $display->display_options['path'],
        'view_display_id' => $display->id,
        'view_name' => $this->view->name,
        'sourceSelector' => $this->options['sourceSelector'],
        'targetSelector' => $this->options['targetSelector'],
        'emptySelector' => $this->options['emptySelector'],
        'afterSelector' => $this->options['afterSelector'],
        'targetStructure' => $this->options['targetStructure'],
        'firstClass' => $this->options['firstClass'],
        'lastClass' => $this->options['lastClass'],
        'oddClass' => $this->options['oddClass'],
        'evenClass' => $this->options['evenClass'],
        'rowClassPrefix' => $this->options['rowClassPrefix'],
      );
    }

    return theme('views_autorefresh', $args);
  }
}

