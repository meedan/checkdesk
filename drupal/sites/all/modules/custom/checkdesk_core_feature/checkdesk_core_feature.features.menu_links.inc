<?php
/**
 * @file
 * checkdesk_core_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function checkdesk_core_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
  );
  // Exported menu link: main-menu:<sub>
  $menu_links['main-menu:<sub>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<sub>',
    'router_path' => '<sub>',
    'link_title' => '...',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-45',
  );
  // Exported menu link: main-menu:admin/config/system/checkdesk
  $menu_links['main-menu:admin/config/system/checkdesk'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/config/system/checkdesk',
    'router_path' => 'admin/config/system/checkdesk',
    'link_title' => 'Edit fact-checking statement',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => '<sub>',
  );
  // Exported menu link: main-menu:admin/people
  $menu_links['main-menu:admin/people'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Administer users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'parent_path' => '<sub>',
  );
  // Exported menu link: main-menu:node/add/discussion
  $menu_links['main-menu:node/add/discussion'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/discussion',
    'router_path' => 'node/add/discussion',
    'link_title' => 'Create story',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: main-menu:node/add/media
  $menu_links['main-menu:node/add/media'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/media',
    'router_path' => 'node/add/media',
    'link_title' => 'Submit report',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: main-menu:node/add/post
  $menu_links['main-menu:node/add/post'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/post',
    'router_path' => 'node/add/post',
    'link_title' => 'Compose update',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: main-menu:reports
  $menu_links['main-menu:reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'reports',
    'router_path' => 'reports',
    'link_title' => 'View incoming citizen reports',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-information:<sub>
  $menu_links['menu-information:<sub>'] = array(
    'menu_name' => 'menu-information',
    'link_path' => '<sub>',
    'router_path' => '<sub>',
    'link_title' => 'Info',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '0',
  );
  // Exported menu link: menu-information:modal/nojs/content/install-bookmarklet
  $menu_links['menu-information:modal/nojs/content/install-bookmarklet'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'modal/nojs/content/install-bookmarklet',
    'router_path' => 'modal/%',
    'link_title' => 'Install bookmarklet',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-utility-menu:user
  $menu_links['menu-utility-menu:user'] = array(
    'menu_name' => 'menu-utility-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Sign in',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('...');
  t('Administer users');
  t('Compose update');
  t('Create story');
  t('Edit fact-checking statement');
  t('Home');
  t('Info');
  t('Install bookmarklet');
  t('Sign in');
  t('Submit report');
  t('View incoming citizen reports');


  return $menu_links;
}
