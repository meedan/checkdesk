<?php

/**
 * Implementation of hook_views_data().
 */
function views_perm_views_data() {
  $data['permission']['table']['join'] = array(
    'users' => array(
      'left_table' => 'users_roles',
      'left_field' => 'rid',
      'field' => 'rid',
    ),
    'users_roles' => array(
      'left_field' => 'rid',
      'field' => 'rid',
    ),
    'roles' => array(
      'left_field' => 'rid',
      'field' => 'rid'
    ),
  );

  return $data;
}

/**
 * Implementation of hook_views_data_alter().
 */
function views_perm_views_data_alter(&$data) {
  $data['users_roles']['pid'] = array(
    'title' => t('Permissions'),
    'help' => t('Permissions granted to a user.'),
    'field' => array(
      'handler' => 'views_handler_field_user_permissions',
      'table' => 'permission',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_permissions',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_permissions',
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function views_perm_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'views_perm'),
    ),
    'handlers' => array(
      'views_handler_field_user_permissions' => array(
        'parent' => 'views_handler_field',
      ),
      'views_handler_filter_user_permissions' => array(
        'parent' => 'views_handler_filter',
      ),
      'views_handler_argument_user_permissions' => array(
        'parent' => 'views_handler_argument',
      ),
    ),
  );
}

