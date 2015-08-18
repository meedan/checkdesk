<?php

/**
 * @file
 * Canned view to display a summary of all content scheduled for publiction.
 */

/**
 * Implements hook_views_default_views().
 */
function revisioning_scheduler_views_default_views() {

  $view = new view();
  $view->name = 'scheduled_publications';
  $view->description = 'A summary table of content revisions currently scheduled for publication.';
  $view->tag = 'default';
  $view->base_table = 'revisioning_scheduler';
  $view->human_name = 'Scheduled publications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Scheduled publications';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'publish revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['group_rendered'] = 0;
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'revision_vid' => 'revision_vid',
    'last_editor' => 'last_editor',
    'revision_date' => 'revision_date',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = 'revision_date';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'revision_vid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '',
      'empty_column' => 0,
    ),
    'last_editor' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'revision_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Scheduled content: Scheduled by */
  $handler->display->display_options['relationships']['revision_uid']['id'] = 'revision_uid';
  $handler->display->display_options['relationships']['revision_uid']['table'] = 'revisioning_scheduler';
  $handler->display->display_options['relationships']['revision_uid']['field'] = 'revision_uid';
  $handler->display->display_options['relationships']['revision_uid']['required'] = 1;
  /* Relationship: Scheduled content: Vid */
  $handler->display->display_options['relationships']['revision_vid']['id'] = 'revision_vid';
  $handler->display->display_options['relationships']['revision_vid']['table'] = 'revisioning_scheduler';
  $handler->display->display_options['relationships']['revision_vid']['field'] = 'revision_vid';
  $handler->display->display_options['relationships']['revision_vid']['required'] = 1;
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'revision_vid';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = 1;
  /* Field: Scheduled content: Vid */
  $handler->display->display_options['fields']['revision_vid']['id'] = 'revision_vid';
  $handler->display->display_options['fields']['revision_vid']['table'] = 'revisioning_scheduler';
  $handler->display->display_options['fields']['revision_vid']['field'] = 'revision_vid';
  $handler->display->display_options['fields']['revision_vid']['label'] = 'Rev. ID';
  $handler->display->display_options['fields']['revision_vid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['revision_vid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['revision_vid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['revision_vid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['revision_vid']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['revision_vid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['revision_vid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['revision_vid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['revision_vid']['hide_alter_empty'] = 1;
  /* Field: Content: Last edited by */
  $handler->display->display_options['fields']['last_editor']['id'] = 'last_editor';
  $handler->display->display_options['fields']['last_editor']['table'] = 'node';
  $handler->display->display_options['fields']['last_editor']['field'] = 'last_editor';
  $handler->display->display_options['fields']['last_editor']['relationship'] = 'revision_vid';
  $handler->display->display_options['fields']['last_editor']['label'] = 'Edited by';
  $handler->display->display_options['fields']['last_editor']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['path'] = '<a href=[edited_by]"';
  $handler->display->display_options['fields']['last_editor']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['external'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['last_editor']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['last_editor']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['last_editor']['alter']['html'] = 0;
  $handler->display->display_options['fields']['last_editor']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['last_editor']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['last_editor']['hide_empty'] = 0;
  $handler->display->display_options['fields']['last_editor']['empty_zero'] = 0;
  $handler->display->display_options['fields']['last_editor']['hide_alter_empty'] = 1;
  /* Field: Scheduled content: Scheduled publication date */
  $handler->display->display_options['fields']['revision_date']['id'] = 'revision_date';
  $handler->display->display_options['fields']['revision_date']['table'] = 'revisioning_scheduler';
  $handler->display->display_options['fields']['revision_date']['field'] = 'revision_date';
  $handler->display->display_options['fields']['revision_date']['label'] = 'Scheduled for publication';
  $handler->display->display_options['fields']['revision_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['revision_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['revision_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['revision_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['revision_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['revision_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['revision_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['revision_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['revision_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['revision_date']['date_format'] = 'long';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'revision_uid';
  $handler->display->display_options['fields']['name']['label'] = 'Scheduled by';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'scheduled-publications';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Scheduled publications';

  $views[$view->name] = $view;
  return $views;
}
