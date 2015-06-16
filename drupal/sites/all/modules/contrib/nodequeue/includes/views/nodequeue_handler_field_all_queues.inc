<?php

/**
 * @file
 * Field handler for all queues.
 *
 * @ingroup views_field_handlers
 */
class nodequeue_handler_field_all_queues extends views_handler_field_prerender_list {
  /**
   * Provide meaningful defaults.
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['link_to_queue'] = array('default' => TRUE);
    $options['limit'] = array('default' => FALSE);
    $options['qids'] = array('default' => array());

    return $options;
  }

  /**
   * Provide "link to term" option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['link_to_queue'] = array(
      '#title' => t('Link this field to queue arrange page'),
      '#type' => 'checkbox',
      '#default_value' => !empty($this->options['link_to_queue']),
    );

    $form['limit'] = array(
      '#type' => 'checkbox',
      '#title' => t('Limit to queues'),
      '#default_value' => $this->options['limit'],
    );

    $options = array();
    $queues = nodequeue_load_queues(nodequeue_get_all_qids());
    foreach ($queues as $queue) {
      $options[$queue->qid] = $queue->title;
    }

    $form['qids'] = array(
      '#prefix' => '<div><div id="edit-options-qids">',
      '#suffix' => '</div></div>',
      '#type' => 'checkboxes',
      '#title' => t('Queues'),
      '#options' => $options,
      '#default_value' => $this->options['qids'],
      '#dependency' => array('edit-options-limit' => array(TRUE)),
    );
  }

  function pre_render(&$values) {
    $nids = array();
    foreach ($values as $result) {
      $nids[] = $result->{$this->field_alias};
    }

    if ($nids) {
      $query = db_select('nodequeue_nodes', 'nn');
      $query->innerJoin('nodequeue_queue', 'nq', 'nn.qid = nq.qid');
      $query->fields('nn', array('nid', 'qid'));
      $query->fields('nq', array('title'));
      $query->orderby('nq.title');
      $query->condition('nn.nid', $nids);
      $qids = array_filter($this->options['qids']);
      if (!empty($this->options['limit']) && !empty($qids)) {
        $query->condition('nn.qid', $qids);
      }
      $result = $query->execute();

      foreach ($result as $queue) {
        $this->items[$queue->nid][$queue->qid]['title'] = check_plain($queue->title);

        if (!empty($this->options['link_to_queue'])) {
          $this->items[$queue->nid][$queue->qid]['make_link'] = TRUE;
          $this->items[$queue->nid][$queue->qid]['path'] = 'admin/structure/nodequeue/' . $queue->qid;
        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['title'];
  }
}
