<?php

/**
 * @file
 * traceview_partition context reaction plugin.
 */

/**
 * Expose traceview partition as a context reactions.
 */
class traceview_partition extends context_reaction {

  /**
   * Configure the traceview partition for this reaction.
   */
  function options_form($context) {

    $form = array(
      '#tree' => TRUE,
      '#title' => t('TraceView Partition'),
      'partition' => array(
        '#title' => t('TraceView Partition'),
        '#description' => t('Enter a TraceView partition to use when this context is active.'),
        '#type' => 'textfield',
        '#default_value' => NULL,
      ),
    );
    return $form;
  }

  /**
   * Set the traceview partition
   */
  function execute(&$vars) {
    $contexts = context_active_contexts();

    foreach ($contexts as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['partition'])) {
        traceview_set_partition($v->reactions[$this->plugin]['partition']);
      }
    }
  }

}