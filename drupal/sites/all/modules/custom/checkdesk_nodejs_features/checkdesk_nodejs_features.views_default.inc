<?php
/**
 * @file
 * checkdesk_nodejs_features.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function checkdesk_nodejs_features_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'liveblog';
  $view->description = '';
  $view->tag = 'checkdesk';
  $view->base_table = 'node';
  $view->human_name = 'Liveblog';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'view-liveblog-content';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '2';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Load more stories';
  $handler->display->display_options['pager']['options']['advance']['content_class'] = '> .view-liveblog-content .view-content';
  $handler->display->display_options['pager']['options']['advance']['pager_selector'] = '.view-liveblog-pager .pager-load-more';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['pager']['options']['load_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Autorefresh';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
print theme(\'views_autorefresh\', array(
  \'interval\' => 5000, 
  \'ping\' => array(\'ping_base_path\' => drupal_get_path(\'module\', \'checkdesk_core\') . \'/autorefresh/liveblog.php?type=discussion&field=changed\'),
  \'incremental\' => array(
    \'view_base_path\' => \'liveblog/autorefresh\',
    \'view_display_id\' => \'page_1\',
    \'view_name\' => \'liveblog\',
  ),
));
?>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* Relationship: Content: Lead image (field_lead_image:fid) */
  $handler->display->display_options['relationships']['field_lead_image_fid']['id'] = 'field_lead_image_fid';
  $handler->display->display_options['relationships']['field_lead_image_fid']['table'] = 'field_data_field_lead_image';
  $handler->display->display_options['relationships']['field_lead_image_fid']['field'] = 'field_lead_image_fid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M d Y';
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_type'] = '0';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'M d, Y \\a\\t g:ia';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_lead_image_fid';
  $handler->display->display_options['fields']['uri']['label'] = '';
  $handler->display->display_options['fields']['uri']['element_type'] = '0';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['element_default_classes'] = FALSE;
  /* Field: Image field caption: Lead image (caption) */
  $handler->display->display_options['fields']['caption']['id'] = 'caption';
  $handler->display->display_options['fields']['caption']['table'] = 'field_lead_image_field_image_field_caption';
  $handler->display->display_options['fields']['caption']['field'] = 'caption';
  $handler->display->display_options['fields']['caption']['label'] = '';
  $handler->display->display_options['fields']['caption']['element_type'] = '0';
  $handler->display->display_options['fields']['caption']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['caption']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'discussion' => 'discussion',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  /* Filter criterion: Content: Promoted to front page */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['path'] = 'liveblog';
  $handler->display->display_options['menu']['title'] = 'Liveblog';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'liveblog.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );
  $handler->display->display_options['sitename_title'] = 1;

  /* Display: Autorefresh Page */
  $handler = $view->new_display('page', 'Autorefresh Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Updated date (with operator) */
  $handler->display->display_options['arguments']['changed_operator']['id'] = 'changed_operator';
  $handler->display->display_options['arguments']['changed_operator']['table'] = 'node';
  $handler->display->display_options['arguments']['changed_operator']['field'] = 'changed_operator';
  $handler->display->display_options['arguments']['changed_operator']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['changed_operator']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['changed_operator']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['changed_operator']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['changed_operator']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'liveblog/autorefresh/%';
  $translatables['liveblog'] = array(
    t('Master'),
    t('more'),
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
    t('Load more stories'),
    t('Autorefresh'),
    t('<?php
print theme(\'views_autorefresh\', array(
  \'interval\' => 5000, 
  \'ping\' => array(\'ping_base_path\' => drupal_get_path(\'module\', \'checkdesk_core\') . \'/autorefresh/liveblog.php?type=discussion&field=changed\'),
  \'incremental\' => array(
    \'view_base_path\' => \'liveblog/autorefresh\',
    \'view_display_id\' => \'page_1\',
    \'view_name\' => \'liveblog\',
  ),
));
?>'),
    t('image from field_lead_image'),
    t('Page'),
    t('Feed'),
    t('Autorefresh Page'),
    t('All'),
  );
  $export['liveblog'] = $view;

  return $export;
}
