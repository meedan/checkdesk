<?php

/**
 * @file
 * Field handler for all subqueues
 *
 * @ingroup views_field_handlers
 */
class nodequeue_handler_field_all_subqueues extends nodequeue_handler_field_all_queues {
  function pre_render(&$values) {
    if (user_access('manipulate queues') || user_access('manipulate all queues')) {
      $nids = array();
      foreach ($values as $result) {
        $nids[] = $result->{$this->field_alias};
      }

      if ($nids) {
        $query = db_select('nodequeue_nodes', 'nn');
        $query->innerJoin('nodequeue_queue', 'nq', 'nn.qid = nq.qid');
        $query->innerJoin('nodequeue_subqueue', 'ns', 'nn.sqid = ns.sqid');
        $query->fields('nn', array('nid', 'sqid', 'qid'));
        $query->fields('nq', array('subqueue_title'));
        $query->fields('ns', array('title'));
        $query->orderby('ns.title');
        $query->orderby('nq.subqueue_title');
        $query->condition('nn.nid', $nids);
        $qids = array_filter($this->options['qids']);
        if (!empty($this->options['limit']) && !empty($qids)) {
          $query->condition('nn.qid', $qids);
        }
        $result = $query->execute();

        foreach ($result as $queue) {
          $title = empty($queue->subqueue_title) ? $queue->title : str_replace('%subqueue', $queue->title, $queue->subqueue_title);
          $this->items[$queue->nid][$queue->sqid]['title'] = check_plain($title);

          if (!empty($this->options['link_to_queue'])) {
            $this->items[$queue->nid][$queue->sqid]['make_link'] = TRUE;
            $this->items[$queue->nid][$queue->sqid]['path'] = 'admin/structure/nodequeue/' . $queue->qid . '/view/' . $queue->sqid;
          }
        }
      }
    }
  }
}
