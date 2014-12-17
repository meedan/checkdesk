<?php

/**
 * @file
 * Contains callbacks for service resource manipulation.
 */

/**
 * Implements hook_services_resources().
 */
function entity_menu_links_services_resources() {
  $resources = array(
    '#api_version' => 3002,
    'menu_link' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => t('This method returns a menu_link.'),
          'file' => array('type' => 'inc', 'module' => 'entity_menu_links', 'name' => 'entity_menu_links.services'),
          'callback' => 'entity_menu_links_services_retrieve',
          'access arguments' => array('administer menu'),
          'args' => array(
            array(
              'name' => 'mlid',
              'type' => 'int',
              'description' => t('The id of the menu_link to get.'),
              'source' => array('path' => '0'),
              'optional' => FALSE,
            ),
          ),
        ),
        'create' => array(
          'help' => t('This method creates a menu_link.'),
          'file' => array('type' => 'inc', 'module' => 'entity_menu_links', 'name' => 'entity_menu_links.services'),
          'callback' => 'entity_menu_links_services_create',
          'access arguments' => array('administer menu'),
          'args' => array(
            array(
              'name' => 'data',
              'type' => 'struct',
              'description' => t('An object representing the menu_link.'),
              'source' => 'data',
              'optional' => FALSE,
            ),
          ),
        ),
        'update' => array(
          'help' => t('This method updates a menu_link.'),
          'file' => array('type' => 'inc', 'module' => 'entity_menu_links', 'name' => 'entity_menu_links.services'),
          'callback' => 'entity_menu_links_services_update',
          'access arguments' => array('administer menu'),
          'args' => array(
            array(
              'name' => 'mlid',
              'type' => 'int',
              'description' => t('The id of the menu_link to update.'),
              'source' => array('path' => '0'),
              'optional' => FALSE,
            ),
            array(
              'name' => 'data',
              'type' => 'struct',
              'description' => t('An object representing the menu_link.'),
              'source' => 'data',
              'optional' => FALSE,
            ),
          ),
        ),
        'delete' => array(
          'help' => t('This method deletes a menu_link.'),
          'file' => array('type' => 'inc', 'module' => 'entity_menu_links', 'name' => 'entity_menu_links.services'),
          'callback' => 'entity_menu_links_services_delete',
          'access arguments' => array('administer menu'),
          'args' => array(
            array(
              'name' => 'mlid',
              'type' => 'int',
              'description' => t('The id of the menu_link to delete.'),
              'source' => array('path' => '0'),
              'optional' => FALSE,
            ),
          ),
        ),
        'index' => array(
          'help' => t('This method returns a listing of menu_links.'),
          'file' => array('type' => 'inc', 'module' => 'entity_menu_links', 'name' => 'entity_menu_links.services'),
          'callback' => 'entity_menu_links_services_index',
          'access arguments' => array('administer menu'),
          'args' => array(
            array(
              'name' => 'page',
              'optional' => TRUE,
              'type' => 'int',
              'description' => t('The zero-based index of the page to get, defaults to 0.'),
              'default value' => 0,
              'source' => array('param' => 'page'),
            ),
            array(
              'name' => 'fields',
              'optional' => TRUE,
              'type' => 'string',
              'description' => t('The fields to return.'),
              'default value' => '*',
              'source' => array('param' => 'fields'),
            ),
            array(
              'name' => 'parameters',
              'optional' => TRUE,
              'type' => 'array',
              'description' => t('Fields an values to filter the list by.'),
              'default value' => array(),
              'source' => array('param' => 'parameters'),
            ),
            array(
              'name' => 'pagesize',
              'optional' => TRUE,
              'type' => 'int',
              'description' => t('Number of records to get per page.'),
              'default value' => 20,
              'source' => array('param' => 'pagesize'),
            ),
          ),
        ),
      ),
    ),
  );
  return $resources;
}

/**
 * Returns a specified menu_link.
 *
 * @param $mlid
 *   Unique identifier for the specified menu_link.
 * @return
 *   The menu_link object.
 */
function entity_menu_links_services_retrieve($mlid) {
  $menu_link = entity_load($mlid);

  if (!$menu_link) {
    return services_error(t('Menu link @mlid not found.', array('@mlid' => $mlid)), 404);
  }

  return $menu_link;
}

/**
 * Adds a new menu_link and returns the mlid.
 *
 * @param $menu_link
 *   An object as would be returned from entity_load().
 * @return
 *   Unique identifier for the menu_link (mlid) or errors if there was a problem.
 */
function entity_menu_links_services_create($menu_link) {
  $controller = entity_get_controller('menu_link');
  $menu_link = $controller->create($menu_link);
  if (!empty($menu_link->mlid)) {
    unset($menu_link->mlid);
  }

  try {
    $controller->save($menu_link);
  }
  catch (Exception $e) {
    return services_error(t('Failed to create menu_link.'), 500);
  }

  return array(
    'mlid' => $menu_link->mlid,
    'uri' => services_resource_uri(array('menu_link', $menu_link->mlid)),
  );
}

/**
 * Updates a menu_link and returns the mlid.
 *
 * @param $mlid
 *   Unique identifier for this menu_link.
 * @param $menu_link
 *   An object as would be returned from entity_load().
 * @return
 *   Unique identifier for the menu_link (mlid) or FALSE if there was a problem.
 */
function entity_menu_links_services_update($mlid, $menu_link) {
  $controller = entity_get_controller('menu_link');
  $menu_link = $controller->create($menu_link);
  $menu_link->mlid = $mlid;
  try {
    $controller->save($menu_link);
  }
  catch (Exception $e) {
    return services_error(t('Failed to update menu_link @mlid.', array('@mlid' => $mlid)), 500);
  }

  return $mlid;
}

/**
 * Delete a menu_link.
 *
 * @param $mlid
 *   Unique identifier of the menu_link to delete.
 * @return
 *   True.
 */
function entity_menu_links_services_delete($mlid) {
  $controller = entity_get_controller('menu_link');
  $menu_link = entity_load('menu_link', array($jid));

  if (empty($menu_link)) {
    return services_error(t('Menu link @mlid not found.', array('@mlid' => $mlid)), 404);
  }

  $controller->delete($mlid);
  return TRUE;
}

/**
 * Return an array of optionally paged mlids based on a set of criteria.
 *
 * An example request might look like:
 *
 * http://domain/endpoint/menu_link?fields=mlid,label&parameters[type]=mytype
 *
 * This would return an array of objects with only mlid and label defined, where
 * type = 'mytype'.
 *
 * @param $page
 *   Page number of results to return (in pages of 20).
 * @param $fields
 *   The fields you want returned.
 * @param $parameters
 *   An array containing fields and values used to build a sql WHERE clause
 *   indicating items to retrieve.
 * @param $page_size
 *   Integer number of items to be returned.
 * @return
 *   An array of menu_link objects.
 **/
function entity_menu_links_services_index($page, $fields, $parameters, $page_size) {
  $info = entity_get_info('menu_link');
  $menu_select = db_select($info['base table'], 't')->condition('module', 'menu')->orderBy('mlid', 'DESC');

  services_resource_build_index_query($menu_select, $page, $fields, $parameters, $page_size, 'menu_link');

  $results = services_resource_execute_index_query($menu_select);

  return services_resource_build_index_list($results, 'menu_link', 'mlid');
}
