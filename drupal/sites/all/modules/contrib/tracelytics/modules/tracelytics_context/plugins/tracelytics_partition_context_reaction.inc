<?php

/**
 * @file
 * tracelytics_partition context reaction plugin.
 */

/**
 * Expose tracelytics partition as a context reactions.
 */
class tracelytics_partition extends context_reaction {

  /**
   * Configure the tracelytics partition for this reaction.
   */
  function options_form($context) {

    $form = array(
      '#tree' => TRUE,
      '#title' => t('Tracelytics Partition'),
      'partition' => array(
        '#title' => t('Tracelytics Partition'),
        '#description' => t('Enter a tracelytics partition to use when this context is active.'),
        '#type' => 'textfield',
        '#default_value' => NULL,
      ),
    );
    return $form;
  }

  /**
   * Set the tracelytics partition
   */
  function execute(&$vars) {
    $contexts = context_active_contexts();

    foreach ($contexts as $k => $v) {
      if (!empty($v->reactions[$this->plugin]['partition'])) {
        tracelytics_set_partition($v->reactions[$this->plugin]['partition']);
      }
    }
  }

}