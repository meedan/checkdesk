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
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'language' => 'und',
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
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-45',
    'language' => 'und',
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
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'language' => 'und',
    'parent_path' => '<sub>',
  );
  // Exported menu link: main-menu:administer-users
  $menu_links['main-menu:administer-users'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'administer-users',
    'router_path' => 'administer-users',
    'link_title' => 'Administer users',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'language' => 'und',
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
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'language' => 'und',
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
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'language' => 'und',
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
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'language' => 'und',
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
    'weight' => '50',
    'language' => 'und',
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-common:<nolink>
  $menu_links['menu-common:<nolink>'] = array(
    'menu_name' => 'menu-common',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Information',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-50',
    'language' => 'und',
  );
  // Exported menu link: menu-common:<sub>
  $menu_links['menu-common:<sub>'] = array(
    'menu_name' => 'menu-common',
    'link_path' => '<sub>',
    'router_path' => '<sub>',
    'link_title' => 'User',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '-48',
    'language' => 'und',
  );
  // Exported menu link: menu-common:modal/ajax/content/about
  $menu_links['menu-common:modal/ajax/content/about'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'modal/ajax/content/about',
    'router_path' => 'modal/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'title' => 'About this site',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'language' => 'en',
    'parent_path' => '<nolink>',
  );
  // Exported menu link: menu-common:modal/ajax/content/fact-checking-statement
  $menu_links['menu-common:modal/ajax/content/fact-checking-statement'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'modal/ajax/content/fact-checking-statement',
    'router_path' => 'modal/%',
    'link_title' => 'Fact-checking statement',
    'options' => array(
      'attributes' => array(
        'title' => 'Fact-checking statement',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
    'language' => 'en',
    'parent_path' => '<nolink>',
  );
  // Exported menu link: menu-common:modal/ajax/content/install-bookmarklet
  $menu_links['menu-common:modal/ajax/content/install-bookmarklet'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'modal/ajax/content/install-bookmarklet',
    'router_path' => 'modal/%',
    'link_title' => 'Install bookmarklet',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'language' => 'en',
    'parent_path' => '<nolink>',
  );
  // Exported menu link: menu-common:modal/ajax/content/terms-use
  $menu_links['menu-common:modal/ajax/content/terms-use'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'modal/ajax/content/terms-use',
    'router_path' => 'modal/%',
    'link_title' => 'Terms of Use',
    'options' => array(
      'attributes' => array(
        'title' => 'Terms of Use',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
    'language' => 'en',
    'parent_path' => '<nolink>',
  );
  // Exported menu link: menu-common:modal/ajax/content/تنصيب-إضافة-المتصفح
  $menu_links['menu-common:modal/ajax/content/تنصيب-إضافة-المتصفح'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'modal/ajax/content/تنصيب-إضافة-المتصفح',
    'router_path' => 'modal/%',
    'link_title' => 'تنصيب إضافة المتصفح',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'language' => 'ar',
    'parent_path' => '<nolink>',
  );
  // Exported menu link: menu-common:my-notifications
  $menu_links['menu-common:my-notifications'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'my-notifications',
    'router_path' => 'my-notifications',
    'link_title' => 'Notifications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'language' => 'und',
  );
  // Exported menu link: menu-common:user
  $menu_links['menu-common:user'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My account',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-50',
    'language' => 'und',
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-common:user/login
  $menu_links['menu-common:user/login'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Sign in',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'language' => 'und',
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-common:user/logout
  $menu_links['menu-common:user/logout'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
    'language' => 'und',
    'parent_path' => '<sub>',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('...');
  t('About');
  t('Administer users');
  t('Compose update');
  t('Create story');
  t('Edit fact-checking statement');
  t('Fact-checking statement');
  t('Home');
  t('Information');
  t('Install bookmarklet');
  t('Logout');
  t('My account');
  t('Notifications');
  t('Sign in');
  t('Submit report');
  t('Terms of Use');
  t('User');
  t('View incoming citizen reports');
  t('تنصيب إضافة المتصفح');


  return $menu_links;
}
