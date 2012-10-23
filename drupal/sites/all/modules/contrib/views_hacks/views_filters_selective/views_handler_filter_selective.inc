<?php

class views_handler_filter_selective extends views_handler_filter_in_operator {
  static $results;

  function get_value_options() {
    $this->value_options = array(0 => t('Actual values will be available at run-time'));
    if (empty($this->view->selective_oids) && !empty($this->view->inited)) {
      $handler = _views_filters_selective_get_handler($this->definition['proxy']);
      $oids = $this->get_oids();
      $options = empty($oids) ? array() : call_user_func($handler, $this, $oids);
      sort($options);
      if (!empty($options)) {
        // Encode the values to keep special chars.
        $this->value_options = array_combine(array_map('urlencode', array_values($options)), array_values($options));
      }
    }
  }

  function value_form(&$form, &$form_state) {
    parent::value_form($form, $form_state);
    // Avoid the 'illegal values' Form API error.
    $form['value']['#validated'] = TRUE;
  }

  function query() {
    // Decode the values to restore special chars.
    $this->value = array_map('urldecode', $this->value);
    parent::query();
  }

  function get_oids() {
    $exposed_input = isset($this->view->exposed_input) ? $this->view->exposed_input : array();
    $signature = md5(serialize(array(
      'name' => $this->view->name,
      'args' => $this->view->args,
      'input' => $exposed_input,
    )));
    if (empty(self::$results[$signature])) {
      // Clone the view and get all results.
      $view_copy = views_get_view($this->view->name);
      if (!$view_copy) return NULL;
      $view_copy->selective_oids = TRUE;
      $view_copy->set_exposed_input($exposed_input);
      $view_copy->set_arguments($this->view->args);
      $view_copy->set_items_per_page(0);
      if (isset($_GET['items_per_page'])) {
        $items_per_page = $_GET['items_per_page'];
        unset($_GET['items_per_page']);
      }
      $view_copy->execute($this->view->current_display);
      if (isset($items_per_page)) {
        $_GET['items_per_page'] = $items_per_page;
      }
      $oids = array();
      foreach ($view_copy->result as $row) {
        $oids[] = $row->{$view_copy->base_field};
      }
      if (empty($this->view->base_field)) {
        $this->view->base_field = $view_copy->base_field;
      }
      self::$results[$signature] = $oids;
      $view_copy->destroy();
    }
    return self::$results[$signature];
  }
}

