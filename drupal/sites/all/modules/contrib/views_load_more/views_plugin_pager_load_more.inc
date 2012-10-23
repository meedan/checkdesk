<?php

/**
 * The plugin to handle Load More pager.
 *
 * @ingroup views_pager_plugins
 */
class views_plugin_pager_load_more extends views_plugin_pager_full {
  function summary_title() {
    if (!empty($this->options['offset'])) {
      return format_plural($this->options['items_per_page'], 'Load more pager, @count item, skip @skip', 'Load more pager, @count items, skip @skip', array('@count' => $this->options['items_per_page'], '@skip' => $this->options['offset']));
    }
      return format_plural($this->options['items_per_page'], 'Load more pager, @count item', 'Load more pager, @count items', array('@count' => $this->options['items_per_page']));
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['waypoint'] = array(
      'contains' => array(
        'infinite' => array('default' => FALSE),
      )
    );
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    if (module_exists('waypoints')) {
      $form['waypoint'] = array(
        '#type' => 'fieldset',
        '#collapsible' => FALSE,
        '#collapsed' => FALSE,
        '#tree' => TRUE,
        '#title' =>  t('Waypoint Support'),
        '#input' => TRUE,
        '#description' => t('Waypoints is a small jQuery plugin that makes it easy to execute a function whenever you scroll to an element.'),
      );
      $form['waypoint']['infinite'] = array(
        '#type' => 'checkbox',
        '#title' => t('Infinite scrolling'),
        '#description' => t('Load more content when the user reaches the bottom of the page.'),
        '#default_value' => $this->options['waypoint']['infinite'],
      );
    }
  }

  function render($input) {
    if (module_exists('waypoints') && $this->options['waypoint']['infinite'] == 1) {
      $viewsLoadMore = array();
      $viewsLoadMore[] = array(
        'view_name' => $this->view->name,
        'view_display_id' => $this->view->current_display,
        'waypoints' => 'infinite',
      );
      drupal_add_library('waypoints', 'waypoints');
      drupal_add_js(array('viewsLoadMore' => $viewsLoadMore),'setting');
    }

    $pager_theme = views_theme_functions('views_load_more_pager', $this->view, $this->display);
    return theme($pager_theme, array(
      'parameters' => $input, 'element' => $this->options['id']));
  }
}

