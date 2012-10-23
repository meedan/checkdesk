<?php

class views_plugin_style_summary_taxonomy extends views_plugin_style_summary {
  function option_definition() {
    $options = parent::option_definition();
    $options['taxonomy'] = array('default' => 0);
    $options['hide_zero'] = array('default' => TRUE);
    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    foreach (taxonomy_get_vocabularies() as $vid => $vocabulary) {
      $options[$vid] = $vocabulary->name;
    }
    $form['taxonomy'] = array(
      '#type' => 'select',
      '#default_value' => $this->options['taxonomy'],
      '#title' => t('Taxonomy'),
      '#options' => $options,
    );

    $form['hide_zero'] = array(
      '#type' => 'checkbox',
      '#default_value' => $this->options['hide_zero'],
      '#title' => t('Hide terms with zero entries'),
    );
  }

  function render() {
    $argument = $this->view->argument[$this->view->build_info['summary_level']];
    $this->terms = array();
    foreach ($this->view->result as $row) {
      $this->terms[$row->{$argument->base_alias}] = $row;
    }

    // Get the taxonomy tree. We're going to heavily modify it...
    $tree = taxonomy_get_tree($this->options['taxonomy']);

    // Reverse sort it: children at the front.
    usort($tree, array($this, 'term_depth_compare'));

    // Add the tid as key.
    $tree = array_combine(array_map(array($this, 'term_tid'), $tree), $tree);

    // Initialize counts as copied from view results.
    array_walk($tree, array($this, 'term_count'), $argument);

    // Accumulate children counts. 
    // This works without recursion because the array is sorted in reverse.
    foreach ($tree as $tid => $term) {
      foreach ($term->parents as $pid) {
        if (!$pid) continue; // parent tid = 0 means no parent
        $tree[$pid]->aggregate_count += $term->aggregate_count;
      }
    }

    // Now we're ready to render it!
    $url_options = array();
    if (!empty($this->view->exposed_raw_input)) {
      $url_options['query'] = $this->view->exposed_raw_input;
    }
    $item_list = array();
    $children = array();
    foreach ($tree as $tid => $term) {
      if (!$term->aggregate_count && $this->options['hide_zero']) continue;
      $args = $this->view->args;
      $args[$argument->position] = $argument->summary_argument($this->terms[$tid]);
      $item = array();
      $item['data']  = l($term->name, $this->view->get_url($args), $url_options);
      if (!empty($this->options['count'])) {
        $item['data'] .= ' (' . (@$argument->definition['accept depth modifier'] ? $term->aggregate_count : $term->count) . ')';
      }
      $item['weight'] = $term->weight;
      if (isset($children[$tid])) {
        usort($children[$tid], array($this, 'item_weight_compare'));
        $item['children'] = $children[$tid];
      }
      foreach ($term->parents as $pid) {
        if (!$pid) {
          $item_list[] = $item;
        }
        else {
          $children[$pid][] = $item;
        }
      }
    }
    usort($item_list, array($this, 'item_weight_compare'));
    return theme('item_list', $item_list);
  }

  static function item_weight_compare($item1, $item2) {
    if ($item1['weight'] == $item2['weight']) return 0;
    return ($item1['weight'] > $item2['weight']) ? 1 : -1;
  }

  static function term_depth_compare($term1, $term2) {
    if ($term1->depth == $term2->depth) return 0;
    return ($term1->depth > $term2->depth) ? -1 : 1; // reverse sort
  }

  static function term_tid($term) {
    return $term->tid;
  }

  function term_count(&$term, $tid, $argument) {
    if (isset($this->terms[$tid])) {
      $term->count = $term->aggregate_count = $this->terms[$tid]->{$argument->count_alias};
    }
    else {
      $term->count = $term->aggregate_count = 0;

      // Create an entry for this term.
      $this->terms[$tid] = (object)array(
        $argument->base_alias => $tid,
        $argument->count_alias => 0,
      );
    }
  }
}

