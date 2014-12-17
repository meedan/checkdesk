<?php
/**
 * Controller class for menu links.
 *
 * This extends the DrupalDefaultEntityController class, adding required
 * special handling for menu link objects.
 */
class EntityMenuLinkController extends EntityAPIController {

  protected function buildQuery($ids, $conditions = array(), $revision_id = FALSE) {
    $query = parent::buildQuery($ids, $conditions, $revision_id);
    // Specify additional fields from the menu tables.
    $query->leftJoin('menu_router', 'm', 'base.router_path = m.path');
    $query->fields('m', array_diff(drupal_schema_fields_sql('menu_router'), array('weight')));
    return $query;
  }

  protected function attachLoad(&$menu_links, $revision_id = FALSE) {
    foreach ($menu_links as $mlid => &$item) {
      $item = (array) $item;
      $item['options'] = unserialize($item['options']);

      if ($item['external']) {
        $item['access'] = TRUE;
        $map = array();
        $item['href'] = $item['link_path'];
        $item['title'] = $item['link_title'];
        $item['localized_options'] = $item['options'];
      }
      else {
        $map = explode('/', $item['link_path']);
        if (!empty($item['to_arg_functions'])) {
          _menu_link_map_translate($map, $item['to_arg_functions']);
        }
        $item['href'] = implode('/', $map);

        // Note - skip callbacks without real values for their arguments.
        if (strpos($item['href'], '%') !== FALSE) {
          $item['access'] = FALSE;
        }

        // menu_tree_check_access() may set this ahead of time for links to nodes.
        if (!isset($item['access'])) {
          if (!empty($item['load_functions']) && !_menu_load_objects($item, $map)) {
            // An error occurred loading an object.
            $item['access'] = FALSE;
            $item = (object) $item;
            continue;
          }
          _menu_check_access($item, $map);
        }
        // For performance, don't localize a link the user can't access.
        if ($item['access']) {
          _menu_item_localize($item, $map, TRUE);
        }
      }

      // Allow other customizations - e.g. adding a page-specific query string to the
      // options array. For performance reasons we only invoke this hook if the link
      // has the 'alter' flag set in the options array.
      if (!empty($item['options']['alter'])) {
        drupal_alter('translated_menu_link', $item, $map);
      }
      $item = (object) $item;
    }
    parent::attachLoad($menu_links, $revision_id);
  }

  /**
   * Overrides delete from EntityAPIController
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    foreach ($ids as $mlid) {
      menu_link_delete($mlid);
    }
  }

  /**
   * Overrides save from EntityAPIController
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $menu_link = (array) $entity;
    $mlid = menu_link_save($menu_link);
    if (FALSE === $mlid) {
      $transaction->rollback();
      throw new Exception('Could not save menu_link');
    }
    $entity->mlid = $mlid;
  }

}
