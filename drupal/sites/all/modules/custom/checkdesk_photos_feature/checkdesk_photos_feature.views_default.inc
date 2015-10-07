<?php
/**
 * @file
 * checkdesk_photos_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function checkdesk_photos_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'checkdesk_media_browser';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'file_managed';
  $view->human_name = 'Checkdesk Media Browser';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'media_browser';
  /* Field: File: Name */
  $handler->display->display_options['fields']['filename']['id'] = 'filename';
  $handler->display->display_options['fields']['filename']['table'] = 'file_managed';
  $handler->display->display_options['fields']['filename']['field'] = 'filename';
  $handler->display->display_options['fields']['filename']['label'] = '';
  $handler->display->display_options['fields']['filename']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['filename']['alter']['ellipsis'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  /* Sort criterion: File: Upload date */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'file_managed';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['sorts']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['timestamp']['expose']['label'] = 'Upload date';
  /* Filter criterion: File: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'file_managed';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'image' => 'image',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: File: Path */
  $handler->display->display_options['filters']['uri']['id'] = 'uri';
  $handler->display->display_options['filters']['uri']['table'] = 'file_managed';
  $handler->display->display_options['filters']['uri']['field'] = 'uri';
  $handler->display->display_options['filters']['uri']['operator'] = 'starts';
  $handler->display->display_options['filters']['uri']['value'] = 'public://story-inline-images/';
  $handler->display->display_options['filters']['uri']['group'] = 1;
  /* Filter criterion: File: Name */
  $handler->display->display_options['filters']['filename']['id'] = 'filename';
  $handler->display->display_options['filters']['filename']['table'] = 'file_managed';
  $handler->display->display_options['filters']['filename']['field'] = 'filename';
  $handler->display->display_options['filters']['filename']['operator'] = 'contains';
  $handler->display->display_options['filters']['filename']['group'] = 1;
  $handler->display->display_options['filters']['filename']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filename']['expose']['operator_id'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['label'] = 'File name';
  $handler->display->display_options['filters']['filename']['expose']['operator'] = 'filename_op';
  $handler->display->display_options['filters']['filename']['expose']['identifier'] = 'filename';
  $handler->display->display_options['filters']['filename']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: File: Caption (field_media_caption) */
  $handler->display->display_options['filters']['field_media_caption_value']['id'] = 'field_media_caption_value';
  $handler->display->display_options['filters']['field_media_caption_value']['table'] = 'field_data_field_media_caption';
  $handler->display->display_options['filters']['field_media_caption_value']['field'] = 'field_media_caption_value';
  $handler->display->display_options['filters']['field_media_caption_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_media_caption_value']['group'] = 1;
  $handler->display->display_options['filters']['field_media_caption_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_media_caption_value']['expose']['operator_id'] = 'field_media_caption_value_op';
  $handler->display->display_options['filters']['field_media_caption_value']['expose']['label'] = 'Caption contains';
  $handler->display->display_options['filters']['field_media_caption_value']['expose']['operator'] = 'field_media_caption_value_op';
  $handler->display->display_options['filters']['field_media_caption_value']['expose']['identifier'] = 'field_media_caption_value';
  $handler->display->display_options['filters']['field_media_caption_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );

  /* Display: Photo Library */
  $handler = $view->new_display('media_browser', 'Photo Library', 'photo_browser');
  $translatables['checkdesk_media_browser'] = array(
    t('Master'),
    t('Photo Library'),
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
    t('Path'),
    t('Upload date'),
    t('File name'),
    t('Caption contains'),
  );
  $export['checkdesk_media_browser'] = $view;

  return $export;
}
