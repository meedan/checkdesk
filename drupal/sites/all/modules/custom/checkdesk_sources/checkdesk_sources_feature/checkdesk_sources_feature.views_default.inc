<?php
/**
 * @file
 * checkdesk_sources_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function checkdesk_sources_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'source_activity';
  $view->description = 'Report activity stream';
  $view->tag = 'checkdesk';
  $view->base_table = 'heartbeat_activity';
  $view->human_name = 'Source Activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Fact-checking activity';
  $handler->display->display_options['css_class'] = 'view-activity-report-content';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '1';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'View all @total footnotes';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '> .view-activity-report-content .view-content';
  $handler->display->display_options['pager']['options']['advance']['pager_selector'] = '.activity-report-pager .pager-load-more';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['pager']['options']['load_all'] = 1;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'heartbeat_activity';
  $handler->display->display_options['row_options']['links'] = 0;
  $handler->display->display_options['row_options']['comments'] = 1;
  /* Field: Heartbeat activity: Creation date */
  $handler->display->display_options['fields']['created_at']['id'] = 'created_at';
  $handler->display->display_options['fields']['created_at']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['created_at']['field'] = 'created_at';
  $handler->display->display_options['fields']['created_at']['label'] = '';
  $handler->display->display_options['fields']['created_at']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created_at']['date_format'] = 'time ago';
  /* Field: Heartbeat activity: Activity message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['label'] = '';
  $handler->display->display_options['fields']['message']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message']['element_default_classes'] = FALSE;
  /* Field: Heartbeat activity: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Heartbeat activity: Node target ID */
  $handler->display->display_options['fields']['nid_target']['id'] = 'nid_target';
  $handler->display->display_options['fields']['nid_target']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['nid_target']['field'] = 'nid_target';
  /* Field: Heartbeat activity: User ID */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: Heartbeat activity: User target ID */
  $handler->display->display_options['fields']['uid_target']['id'] = 'uid_target';
  $handler->display->display_options['fields']['uid_target']['table'] = 'heartbeat_activity';
  $handler->display->display_options['fields']['uid_target']['field'] = 'uid_target';
  /* Sort criterion: Heartbeat activity: Creation date */
  $handler->display->display_options['sorts']['created_at']['id'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['table'] = 'heartbeat_activity';
  $handler->display->display_options['sorts']['created_at']['field'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['order'] = 'DESC';
  /* Contextual filter: Heartbeat activity: Node ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'heartbeat_activity';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Heartbeat activity: Heartbeat template */
  $handler->display->display_options['filters']['message_id']['id'] = 'message_id';
  $handler->display->display_options['filters']['message_id']['table'] = 'heartbeat_activity';
  $handler->display->display_options['filters']['message_id']['field'] = 'message_id';
  $handler->display->display_options['filters']['message_id']['value'] = array(
    'new_comment_source' => 'new_comment_source',
    'checkdesk_new_source' => 'checkdesk_new_source',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'View all';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['path'] = 'source_activity/%';
  $translatables['source_activity'] = array(
    t('Master'),
    t('Fact-checking activity'),
    t('View all'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('View all @total footnotes'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Node target ID'),
    t('User ID'),
    t('User target ID'),
    t('All'),
    t('Block'),
    t('more'),
    t('Page'),
  );
  $export['source_activity'] = $view;

  return $export;
}
