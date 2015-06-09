<?php

/**
 * @file nodequeue.views.inc
 * Provides support for the Views module.
 *
 * This implementation is almost entirely based around a relationship
 * which is stapled to the 'node' table via hook_views_data_alter.
 *
 * The relationship allows you to define 0 or more queues that join the
 * queue tables, limiting the join to just the queues selected. Once
 * the queues are joined in, the queue fields will show up, and they
 * have the usual array of arguments, sorts, fields and filters; since
 * the real legwork is done by the relationship, most of these are
 * really quite simple.
 */

/**
 * Implements hook_views_data().
 */
function nodequeue_views_data() {
  $data = array();

  // ----------------------------------------------------------------
  // nodequeue_nodes table
  $data['nodequeue_nodes']['table']['group'] = t('Nodequeue');

  // The nodequeue_nodes table is how nodequeue connects to the
  // rest of the world, but we will only join it in via relationship.

  // position
  $data['nodequeue_nodes']['position'] = array(
    'title' => t('Position'),
    'help' => t('The position of the node within a queue.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Nodequeue position and other.
  $data['nodequeue_nodes']['position_and_other'] = array(
    'title' => t('Position in nodequeue and other parameter'),
    'help' => t("Allows combining the nodequeue position with another (random)
      parameter (created date for example). This handler is useful only if the
      nodequeue relationship is NOT required."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'nodequeue_handler_sort_by_position_and_other',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // timestamp
  $data['nodequeue_nodes']['timestamp'] = array(
    'title' => t('Added date'),
    'help' => t('The date the node was added to a queue.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['nodequeue_nodes']['qid'] = array(
    'title' => t('Queue ID'),
    'help' => t('The ID of the queue the node belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'name table' => 'nodequeue_queue',
      'empty field name' => t('No queue'),
    ),
  );

  $data['nodequeue_nodes']['sqid'] = array(
    'title' => t('Subqueue ID'),
    'help' => t('The ID of the subqueue the node belongs to.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'name field' => 'title',
      'name table' => 'nodequeue_subqueue',
      'empty field name' => t('No queue'),
    ),
  );

  // specialized is null/is not null filter
  $data['nodequeue_nodes']['in_queue'] = array(
    'title' => t('In queue'),
    'help' => t('Filter to ensure a node IS or IS NOT in the related queue'),
    'sort' => array(
      'help' => t('Sort by whether this is a nodequeue node or not'),
      'handler' => 'nodequeue_handler_sort_in_queue',
    ),
    'filter' => array(
      'handler' => 'nodequeue_handler_filter_in_queue',
      'label' => t('In queue'),
    ),
  );

  $data['nodequeue_queue']['name'] = array(
    'title' => t('Queue machine name'),
    'help' => t('The machine name of the queue.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // ----------------------------------------------------------------
  // nodequeue_queue table
  $data['nodequeue_queue']['table']['group'] = t('Nodequeue');

  // For use with the relationship.
  $data['nodequeue_queue']['table']['join'] = array(
    'nodequeue_nodes' => array(
      'left_field' => 'qid',
      'field' => 'qid',
    ),
  );

  $data['nodequeue_queue']['title'] = array(
    'title' => t('Queue title'),
    'help' => t('The title of the nodequeue.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  // ----------------------------------------------------------------
  // nodequeue_subqueue table
  $data['nodequeue_subqueue']['table']['group'] = t('Nodequeue');

  // For use with the relationship.
  $data['nodequeue_subqueue']['table']['join'] = array(
    'nodequeue_nodes' => array(
      'left_field' => 'sqid',
      'field' => 'sqid',
    ),
  );

  $data['nodequeue_subqueue']['title'] = array(
    'title' => t('Subqueue title'),
    'help' => t('The title of the subqueue.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['nodequeue_subqueue']['reference'] = array(
    'title' => t('Subqueue reference'),
    'help' => t('The reference that defines a subqueue; what this actually is depends upon the type of subqueue, but is a taxonomy tid for smartqueue taxonomy, or a uid for authorview.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
     ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function nodequeue_views_data_alter(&$data) {
  // queue relationship
  $data['node']['nodequeue_rel'] = array(
    'group' => t('Nodequeue'),
    'title' => t('Queue'),
    'help' => t('Create a relationship to a nodequeue.'),
    'real field' => 'nid',
    'relationship' => array(
      'handler' => 'nodequeue_handler_relationship_nodequeue',
      'base' => 'nodequeue_nodes',
      'field' => 'nid',
      'label' => t('queue'),
    ),
  );

  // links
  $data['node']['nodequeue_links'] = array(
    'group' => t('Nodequeue'),
    'title' => t('Add/remove links'),
    'help' => t('Display add/remove links for all eligible nodequeues. Note that this performs a node_load so could add many extra queries to a view.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'nodequeue_handler_field_links',
    ),
  );

  $data['node']['nodequeue_queue_tab'] = array(
    'group' => t('Nodequeue'),
    'title' => t('Link to tab'),
    'help' => t('Display add/remove links for all eligible nodequeues. Note that this performs a node_load so could add many extra queries to a view.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'nodequeue_handler_field_queue_tab',
    ),
  );

  // all queues
  $data['node']['nodequeue_all_queues'] = array(
    'group' => t('Nodequeue'),
    'title' => t('All queues'),
    'help' => t('Display all queues a node is a member of.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'nodequeue_handler_field_all_queues',
    ),
  );

  // all subqueues
  $data['node']['nodequeue_all_subqueues'] = array(
    'group' => t('Nodequeue'),
    'title' => t('All subqueues'),
    'help' => t('Display all subqueues a node is a member of.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'nodequeue_handler_field_all_subqueues',
    ),
  );
}



/**
 * Implements hook_contextual_links_view_alter().
 */
function nodequeue_contextual_links_view_alter(&$element, $items) {

  // Bail if the user doesn't have access to edit nodequeues.
  if (!user_access('manipulate queues')) {
    return;
  }

  if (empty($element['#element']['#contextual_links']['views_ui'])) {
    return;
  }

  if (!variable_get('nodequeue_show_contextual_links', TRUE)) {
    return;
  }

  // If this is a block placed by Context then the View info is stored in
  // a slightly different place
  $views_info = empty($element['#element']['#views_contextual_links_info'])
    ? $element['#element']['content']['#views_contextual_links_info']
    : $element['#element']['#views_contextual_links_info'];

  $display_id = $views_info['views_ui']['view_display_id'];
  $view_name = $views_info['views_ui']['view_name'];
  $view = views_get_view($view_name, TRUE);

  // If the view is empty, e.g. it wasn't saved yet and has no display
  // objects, this won't work.
  if (empty($view)) {
    return;
  }
  $view->build($display_id);

  $nodequeue_rels = array(
    'nodequeue_handler_relationship_nodequeue'
  );
  $subqueue_arg_titles = array(
    'Subqueue reference',
    'Subqueue reference (optional)',
  );

  // Cycle through all the relationships to find ones provided by nodequeue.
  // We'll use this as a trigger to attach the links.
  foreach ($view->relationship as $rel) {
    if (!in_array(get_class($rel), $nodequeue_rels, TRUE)) {
      continue;
    }

    foreach ($rel->options['names'] as $queue_name) {
      if (gettype($queue_name) != 'string') {
        continue;
      }
      $qid_map = nodequeue_get_qid_map();
      $qid = $qid_map[$queue_name];
      $queue = nodequeue_load($qid);
      $element['#links'][$queue_name] = array(
        'title' => t('Edit queue'),
        'href' => 'admin/structure/nodequeue/' . $qid . '/view',
        'query' => array('destination' => current_path()),
      );

      // Cycle through all arguments to find ones that limit us by subqueue.
      // If we find some, add further links to subqueues.
      foreach ($view->argument as $arg) {
        $is_subqueue_arg = $arg->options['relationship'] == $rel->options['id']
          && in_array($arg->definition['title'], $subqueue_arg_titles, TRUE);

        if (!$is_subqueue_arg) {
          continue;
        }

        // Provide contextual links for each of the subqueues.
        $subqueues = nodequeue_load_subqueues_by_reference(array($qid => $arg->value));
        foreach ($subqueues as $sqid => $subqueue) {
          $element['#links'][$queue_name . '_' . $sqid] = array(
            'title' => t('Edit Subqueue'),
            'href' => 'admin/structure/nodequeue/' . $qid . '/view/' . $sqid,
            'query' => array('destination' => current_path()),
          );
        }
      }
    }
  }
}
