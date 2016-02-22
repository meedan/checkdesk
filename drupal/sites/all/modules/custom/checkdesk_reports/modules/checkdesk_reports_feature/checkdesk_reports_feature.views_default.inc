<?php
/**
 * @file
 * checkdesk_reports_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function checkdesk_reports_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'activity_report';
  $view->description = 'Report activity stream';
  $view->tag = 'checkdesk';
  $view->base_table = 'heartbeat_activity';
  $view->human_name = 'Report Activity';
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
    'status_report' => 'status_report',
    'new_comment_report' => 'new_comment_report',
    'new_report' => 'new_report',
    'publish_report' => 'publish_report',
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
  $handler->display->display_options['path'] = 'report_activity/%';
  $translatables['activity_report'] = array(
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
  $export['activity_report'] = $view;

  $view = new view();
  $view->name = 'desk_reports';
  $view->description = '';
  $view->tag = 'checkdesk';
  $view->base_table = 'node';
  $view->human_name = 'Desk Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Desk Reports';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    4 => '4',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Remove all filters';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Date Asc';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Date Desc';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'secondary_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'title' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '<span class="report-stream-filter-label">{key:[current-page:query:title_op]}</span>&nbsp;<span class="report-stream-filter-val">"[current-page:query:title]"</span>',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_rating_tid_i18n' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'source' => array(
      'more_options' => array(
        'is_secondary' => 0,
        'bef_filter_description' => '<span class="report-stream-filter-label">{key:[current-page:query:source_op]}</span>&nbsp;<span class="report-stream-filter-val">"[current-page:query:source]"</span>',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'field_stories_target_id' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
  );
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '5';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['load_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'draggable';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Auto-Refresh';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php
$story = isset($_GET[\'story\']) ? $_GET[\'story\'] : 0;
print theme(\'views_autorefresh\', array(
  \'interval\' => 5000, 
  \'ping\' => array(
          \'ping_base_path\' => drupal_get_path(\'module\', \'checkdesk_core\') . \'/autorefresh/liveblog.php?type=media&field=created&story=\'. $story
    ),
  \'incremental\' => array(
    \'view_base_path\' => \'desk-reports/autorefresh\',
    \'view_display_id\' => \'page_1\',
    \'view_name\' => \'desk_reports\',
  ),
));
$view = views_get_current_view();
?>
<div class="filters-summary">
  <p><?php print format_plural($view->total_rows, \'<span>1</span> result. You can drag and drop it.\', \'<span>@count</span> results. Drag and drop the best ones.\'); ?></p>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<?php
print t(\'No content available\');
?>';
  $handler->display->display_options['empty']['area']['format'] = 'php_code';
  /* Relationship: Media sources: Media sources of the node */
  $handler->display->display_options['relationships']['ms_id']['id'] = 'ms_id';
  $handler->display->display_options['relationships']['ms_id']['table'] = 'node';
  $handler->display->display_options['relationships']['ms_id']['field'] = 'ms_id';
  $handler->display->display_options['relationships']['ms_id']['required'] = TRUE;
  /* Relationship: Media sources: Parent */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'meedan_sources';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  $handler->display->display_options['relationships']['parent']['relationship'] = 'ms_id';
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_link']['alter']['text'] = '<div class="draggable">[field_link]</div>';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'oembed_thumbnail';
  $handler->display->display_options['fields']['field_link']['settings'] = array(
    'imagestyle' => 'medium',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Date';
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
    'media' => 'media',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Autorefresh */
  $handler->display->display_options['header']['autorefresh']['id'] = 'autorefresh';
  $handler->display->display_options['header']['autorefresh']['table'] = 'views';
  $handler->display->display_options['header']['autorefresh']['field'] = 'autorefresh';
  $handler->display->display_options['header']['autorefresh']['interval'] = '5000';
  $handler->display->display_options['header']['autorefresh']['incremental'] = TRUE;
  $handler->display->display_options['header']['autorefresh']['display'] = 'page_1';
  $handler->display->display_options['header']['autorefresh']['ping'] = TRUE;
  $handler->display->display_options['header']['autorefresh']['ping_base_path'] = 'sites/all/modules/custom/checkdesk_core/autorefresh/liveblog.php';
  $handler->display->display_options['header']['autorefresh']['ping_arguments'] = '$story = isset($_GET[\'story\']) ? $_GET[\'story\'] : 0;
return array(\'type\'=>\'media\',\'field\'=>\'created\',\'story\'=>$story);';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Reports stats';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<?php $view = views_get_current_view(); ?>
<div class="filters-summary">
  <p><?php print format_plural($view->total_rows, \'<span>1</span> result. You can drag and drop it.\', \'<span>@count</span> results. Drag and drop the best ones.\'); ?></p>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'meedan_oembed_thumbnail';
  $handler->display->display_options['fields']['field_link']['settings'] = array(
    'imagestyle' => 'report_thumbnail',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'ctools-use-modal';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Field: Fact-checking status */
  $handler->display->display_options['fields']['field_rating']['id'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['fields']['field_rating']['field'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['label'] = '';
  $handler->display->display_options['fields']['field_rating']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Media sources: Source name */
  $handler->display->display_options['fields']['source']['id'] = 'source';
  $handler->display->display_options['fields']['source']['table'] = 'meedan_sources';
  $handler->display->display_options['fields']['source']['field'] = 'source';
  $handler->display->display_options['fields']['source']['relationship'] = 'parent';
  $handler->display->display_options['fields']['source']['label'] = '';
  $handler->display->display_options['fields']['source']['element_type'] = '0';
  $handler->display->display_options['fields']['source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['source']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'g:ia - d M Y';
  /* Field: Media sources: Source URL */
  $handler->display->display_options['fields']['source_url']['id'] = 'source_url';
  $handler->display->display_options['fields']['source_url']['table'] = 'meedan_sources';
  $handler->display->display_options['fields']['source_url']['field'] = 'source_url';
  $handler->display->display_options['fields']['source_url']['relationship'] = 'ms_id';
  $handler->display->display_options['fields']['source_url']['label'] = '';
  $handler->display->display_options['fields']['source_url']['element_type'] = '0';
  $handler->display->display_options['fields']['source_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['source_url']['element_default_classes'] = FALSE;
  /* Field: Media sources: Source URL */
  $handler->display->display_options['fields']['source_url_1']['id'] = 'source_url_1';
  $handler->display->display_options['fields']['source_url_1']['table'] = 'meedan_sources';
  $handler->display->display_options['fields']['source_url_1']['field'] = 'source_url';
  $handler->display->display_options['fields']['source_url_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['source_url_1']['label'] = '';
  $handler->display->display_options['fields']['source_url_1']['element_type'] = '0';
  $handler->display->display_options['fields']['source_url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['source_url_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'media' => 'media',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'By keyword';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Fact-checking status (field_rating) (translated) */
  $handler->display->display_options['filters']['field_rating_tid_i18n']['id'] = 'field_rating_tid_i18n';
  $handler->display->display_options['filters']['field_rating_tid_i18n']['table'] = 'field_data_field_rating';
  $handler->display->display_options['filters']['field_rating_tid_i18n']['field'] = 'field_rating_tid_i18n';
  $handler->display->display_options['filters']['field_rating_tid_i18n']['group'] = 1;
  $handler->display->display_options['filters']['field_rating_tid_i18n']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_rating_tid_i18n']['expose']['operator_id'] = 'field_rating_tid_i18n_op';
  $handler->display->display_options['filters']['field_rating_tid_i18n']['expose']['label'] = 'By status';
  $handler->display->display_options['filters']['field_rating_tid_i18n']['expose']['operator'] = 'field_rating_tid_i18n_op';
  $handler->display->display_options['filters']['field_rating_tid_i18n']['expose']['identifier'] = 'field_rating_tid';
  $handler->display->display_options['filters']['field_rating_tid_i18n']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_rating_tid_i18n']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_rating_tid_i18n']['type'] = 'select';
  $handler->display->display_options['filters']['field_rating_tid_i18n']['vocabulary'] = 'media_rating';
  /* Filter criterion: Media sources: Source name */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'meedan_sources';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['relationship'] = 'ms_id';
  $handler->display->display_options['filters']['source']['operator'] = 'contains';
  $handler->display->display_options['filters']['source']['group'] = 1;
  $handler->display->display_options['filters']['source']['exposed'] = TRUE;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'By source';
  $handler->display->display_options['filters']['source']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Story (field_stories) */
  $handler->display->display_options['filters']['field_stories_target_id']['id'] = 'field_stories_target_id';
  $handler->display->display_options['filters']['field_stories_target_id']['table'] = 'field_data_field_stories';
  $handler->display->display_options['filters']['field_stories_target_id']['field'] = 'field_stories_target_id';
  $handler->display->display_options['filters']['field_stories_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_stories_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['operator_id'] = 'field_stories_target_id_op';
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['label'] = 'By story';
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['operator'] = 'field_stories_target_id_op';
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['identifier'] = 'field_stories_target_id';
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Autorefresh */
  $handler = $view->new_display('page', 'Autorefresh', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Media */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['label'] = '';
  $handler->display->display_options['fields']['field_link']['element_type'] = '0';
  $handler->display->display_options['fields']['field_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_link']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'meedan_oembed_thumbnail';
  $handler->display->display_options['fields']['field_link']['settings'] = array(
    'imagestyle' => 'report_thumbnail',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['link_class'] = 'ctools-use-modal';
  $handler->display->display_options['fields']['nid']['element_type'] = '0';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  /* Field: Field: Fact-checking status */
  $handler->display->display_options['fields']['field_rating']['id'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['table'] = 'field_data_field_rating';
  $handler->display->display_options['fields']['field_rating']['field'] = 'field_rating';
  $handler->display->display_options['fields']['field_rating']['label'] = '';
  $handler->display->display_options['fields']['field_rating']['element_type'] = '0';
  $handler->display->display_options['fields']['field_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_rating']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Media sources: Source name */
  $handler->display->display_options['fields']['source']['id'] = 'source';
  $handler->display->display_options['fields']['source']['table'] = 'meedan_sources';
  $handler->display->display_options['fields']['source']['field'] = 'source';
  $handler->display->display_options['fields']['source']['relationship'] = 'parent';
  $handler->display->display_options['fields']['source']['label'] = '';
  $handler->display->display_options['fields']['source']['element_type'] = '0';
  $handler->display->display_options['fields']['source']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['source']['element_default_classes'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_type'] = '0';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'g:ia - d M Y';
  /* Field: Media sources: Source URL */
  $handler->display->display_options['fields']['source_url']['id'] = 'source_url';
  $handler->display->display_options['fields']['source_url']['table'] = 'meedan_sources';
  $handler->display->display_options['fields']['source_url']['field'] = 'source_url';
  $handler->display->display_options['fields']['source_url']['relationship'] = 'ms_id';
  $handler->display->display_options['fields']['source_url']['label'] = '';
  $handler->display->display_options['fields']['source_url']['element_type'] = '0';
  $handler->display->display_options['fields']['source_url']['element_label_colon'] = FALSE;
  /* Field: Media sources: Source URL */
  $handler->display->display_options['fields']['source_url_1']['id'] = 'source_url_1';
  $handler->display->display_options['fields']['source_url_1']['table'] = 'meedan_sources';
  $handler->display->display_options['fields']['source_url_1']['field'] = 'source_url';
  $handler->display->display_options['fields']['source_url_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['source_url_1']['label'] = '';
  $handler->display->display_options['fields']['source_url_1']['element_type'] = '0';
  $handler->display->display_options['fields']['source_url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Post date (with operator) */
  $handler->display->display_options['arguments']['created_operator']['id'] = 'created_operator';
  $handler->display->display_options['arguments']['created_operator']['table'] = 'node';
  $handler->display->display_options['arguments']['created_operator']['field'] = 'created_operator';
  $handler->display->display_options['arguments']['created_operator']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['created_operator']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['created_operator']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['created_operator']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['created_operator']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'media' => 'media',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'By keyword';
  $handler->display->display_options['filters']['title']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Field: Fact-checking status (field_rating) */
  $handler->display->display_options['filters']['field_rating_tid']['id'] = 'field_rating_tid';
  $handler->display->display_options['filters']['field_rating_tid']['table'] = 'field_data_field_rating';
  $handler->display->display_options['filters']['field_rating_tid']['field'] = 'field_rating_tid';
  $handler->display->display_options['filters']['field_rating_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_rating_tid']['expose']['operator_id'] = 'field_rating_tid_op';
  $handler->display->display_options['filters']['field_rating_tid']['expose']['label'] = 'By status';
  $handler->display->display_options['filters']['field_rating_tid']['expose']['operator'] = 'field_rating_tid_op';
  $handler->display->display_options['filters']['field_rating_tid']['expose']['identifier'] = 'field_rating_tid';
  $handler->display->display_options['filters']['field_rating_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_rating_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_rating_tid']['vocabulary'] = 'media_rating';
  /* Filter criterion: Media sources: Source name */
  $handler->display->display_options['filters']['source']['id'] = 'source';
  $handler->display->display_options['filters']['source']['table'] = 'meedan_sources';
  $handler->display->display_options['filters']['source']['field'] = 'source';
  $handler->display->display_options['filters']['source']['relationship'] = 'ms_id';
  $handler->display->display_options['filters']['source']['operator'] = 'contains';
  $handler->display->display_options['filters']['source']['exposed'] = TRUE;
  $handler->display->display_options['filters']['source']['expose']['operator_id'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['label'] = 'By source';
  $handler->display->display_options['filters']['source']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['source']['expose']['operator'] = 'source_op';
  $handler->display->display_options['filters']['source']['expose']['identifier'] = 'source';
  $handler->display->display_options['filters']['source']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  /* Filter criterion: Content: Story (field_stories) */
  $handler->display->display_options['filters']['field_stories_target_id']['id'] = 'field_stories_target_id';
  $handler->display->display_options['filters']['field_stories_target_id']['table'] = 'field_data_field_stories';
  $handler->display->display_options['filters']['field_stories_target_id']['field'] = 'field_stories_target_id';
  $handler->display->display_options['filters']['field_stories_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['operator_id'] = 'field_stories_target_id_op';
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['label'] = 'By story';
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['operator'] = 'field_stories_target_id_op';
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['identifier'] = 'field_stories_target_id';
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_stories_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  $handler->display->display_options['path'] = 'desk-reports/autorefresh/%';
  $translatables['desk_reports'] = array(
    t('Master'),
    t('Desk Reports'),
    t('more'),
    t('Apply'),
    t('Remove all filters'),
    t('Sort by'),
    t('Date Asc'),
    t('Date Desc'),
    t('Advanced options'),
    t('Sort options'),
    t('Select any filter and click on Apply to see results'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Load more'),
    t('Auto-Refresh'),
    t('<?php
$story = isset($_GET[\'story\']) ? $_GET[\'story\'] : 0;
print theme(\'views_autorefresh\', array(
  \'interval\' => 5000, 
  \'ping\' => array(
          \'ping_base_path\' => drupal_get_path(\'module\', \'checkdesk_core\') . \'/autorefresh/liveblog.php?type=media&field=created&story=\'. $story
    ),
  \'incremental\' => array(
    \'view_base_path\' => \'desk-reports/autorefresh\',
    \'view_display_id\' => \'page_1\',
    \'view_name\' => \'desk_reports\',
  ),
));
$view = views_get_current_view();
?>
<div class="filters-summary">
  <p><?php print format_plural($view->total_rows, \'<span>1</span> result. You can drag and drop it.\', \'<span>@count</span> results. Drag and drop the best ones.\'); ?></p>
</div>'),
    t('<?php
print t(\'No content available\');
?>'),
    t('Media sources'),
    t('Parent'),
    t('<div class="draggable">[field_link]</div>'),
    t('Date'),
    t('Block'),
    t('<span class="report-stream-filter-label">{key:[current-page:query:title_op]}</span>&nbsp;<span class="report-stream-filter-val">"[current-page:query:title]"</span>'),
    t('<span class="report-stream-filter-label">{key:[current-page:query:source_op]}</span>&nbsp;<span class="report-stream-filter-val">"[current-page:query:source]"</span>'),
    t('Reports stats'),
    t('<?php $view = views_get_current_view(); ?>
<div class="filters-summary">
  <p><?php print format_plural($view->total_rows, \'<span>1</span> result. You can drag and drop it.\', \'<span>@count</span> results. Drag and drop the best ones.\'); ?></p>
</div>'),
    t('By keyword'),
    t('By status'),
    t('By source'),
    t('By story'),
    t('Autorefresh'),
    t('All'),
  );
  $export['desk_reports'] = $view;

  return $export;
}
