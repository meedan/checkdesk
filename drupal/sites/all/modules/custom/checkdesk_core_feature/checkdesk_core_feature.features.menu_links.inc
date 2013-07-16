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
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'uuid' => 'd5f3370f-db5f-d074-d189-cbac6703dd49',
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: main-menu:<sub>
  $menu_links['main-menu:<sub>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<sub>',
    'router_path' => '<sub>',
    'link_title' => '...',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'uuid' => 'b54b8beb-654c-c3b4-1938-db4fae8838fe',
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: main-menu:admin/config/system/checkdesk
  $menu_links['main-menu:admin/config/system/checkdesk'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/config/system/checkdesk',
    'router_path' => 'admin/config/system/checkdesk',
    'link_title' => 'Edit fact-checking statement',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'uuid' => '2643d8bd-eb4d-16f4-1928-3013705c11af',
    'language' => 'und',
    'customized' => 1,
    'parent_path' => '<sub>',
  );
  // Exported menu link: main-menu:admin/people
  $menu_links['main-menu:admin/people'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Administer users',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid' => '90476ce1-c57a-48e8-b95a-abc56aae9886',
    'language' => 'und',
    'customized' => 1,
    'parent_path' => '<sub>',
  );
  // Exported menu link: main-menu:node/add/discussion
  $menu_links['main-menu:node/add/discussion'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/discussion',
    'router_path' => 'node/add/discussion',
    'link_title' => 'Create story',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'uuid' => 'edc54df9-4aa8-bf84-dd89-ca0a351af23b',
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: main-menu:node/add/media
  $menu_links['main-menu:node/add/media'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/media',
    'router_path' => 'node/add/media',
    'link_title' => 'Submit report',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid' => '0bc3af5d-28a8-c864-bd93-f17d8bea2366',
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: main-menu:node/add/post
  $menu_links['main-menu:node/add/post'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/post',
    'router_path' => 'node/add/post',
    'link_title' => 'Compose update',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'uuid' => 'd1a4a4e9-b0c3-8d94-11a4-34f35bda25c1',
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: main-menu:reports
  $menu_links['main-menu:reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'reports',
    'router_path' => 'reports',
    'link_title' => 'View incoming citizen reports',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'uuid' => '50e68ce2-956c-6f64-1914-5e6a93778baf',
    'language' => 'und',
    'customized' => 1,
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-common:<nolink>
  $menu_links['menu-common:<nolink>'] = array(
    'menu_name' => 'menu-common',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Information',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'uuid' => '02e041f6-6c32-c594-8d35-79cb52a371d8',
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-common:<sub>
  $menu_links['menu-common:<sub>'] = array(
    'menu_name' => 'menu-common',
    'link_path' => '<sub>',
    'router_path' => '<sub>',
    'link_title' => '<user>',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'uuid' => '919ac829-ba90-aaa4-1546-5188241b9d5b',
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-common:content/install-bookmarklet
  $menu_links['menu-common:content/install-bookmarklet'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'content/install-bookmarklet',
    'router_path' => 'modal/%',
    'link_title' => 'Bookmarklet',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'uuid' => 'd1606646-9485-5154-e504-9eabb5782cc6',
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-common:content/تنصيب-إضافة-المتصفح
  $menu_links['menu-common:content/تنصيب-إضافة-المتصفح'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'content/تنصيب-إضافة-المتصفح',
    'router_path' => 'modal/%',
    'link_title' => 'إضافة المتصفح',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid' => '302da736-6f32-4024-695a-49ecde0f8091',
    'language' => 'ar',
    'customized' => 1,
  );
  // Exported menu link: menu-common:my-notifications
  $menu_links['menu-common:my-notifications'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'my-notifications',
    'router_path' => 'my-notifications',
    'link_title' => 'Notifications',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid' => '5626ddfd-e3f6-7ba4-f9ff-f8c36ff9d636',
    'language' => 'und',
    'customized' => 1,
  );
  // Exported menu link: menu-common:user
  $menu_links['menu-common:user'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My account',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'uuid' => '42e9e86e-42ae-8d04-0d50-e42bde8cbbda',
    'language' => 'und',
    'customized' => 1,
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-common:user/login
  $menu_links['menu-common:user/login'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Sign in',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'uuid' => '9a684326-a352-d454-517b-878bb9468e91',
    'language' => 'und',
    'customized' => 1,
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-common:user/logout
  $menu_links['menu-common:user/logout'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'uuid' => '391be377-17db-a134-4d21-c6742d07ca4e',
    'language' => 'und',
    'customized' => 1,
    'parent_path' => '<sub>',
  );
  // Exported menu link: menu-information:content/fact-checking-statement
  $menu_links['menu-information:content/fact-checking-statement'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/fact-checking-statement',
    'router_path' => 'modal/%',
    'link_title' => 'Fact-checking statement',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'uuid' => 'aaac935a-d8c3-c964-b1a5-11747d737824',
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-information:content/install-bookmarklet
  $menu_links['menu-information:content/install-bookmarklet'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/install-bookmarklet',
    'router_path' => 'modal/%',
    'link_title' => 'Bookmarklet',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid' => 'd1606646-9485-5154-e504-9eabb5782cc6',
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-information:content/terms-use
  $menu_links['menu-information:content/terms-use'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/terms-use',
    'router_path' => 'modal/%',
    'link_title' => 'Terms of use',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'uuid' => 'a3f2b8b5-2d02-9934-79d7-246ff6231eaf',
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: menu-information:content/بيان-التحقق-من-صحة-المعلومات
  $menu_links['menu-information:content/بيان-التحقق-من-صحة-المعلومات'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/بيان-التحقق-من-صحة-المعلومات',
    'router_path' => 'modal/%',
    'link_title' => 'بيان التحقق من صحة المعلومات',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'uuid' => '3daae1f4-caac-41f1-b00c-7ada7412206e',
    'language' => 'ar',
    'customized' => 1,
  );
  // Exported menu link: menu-information:content/تنصيب-إضافة-المتصفح
  $menu_links['menu-information:content/تنصيب-إضافة-المتصفح'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/تنصيب-إضافة-المتصفح',
    'router_path' => 'modal/%',
    'link_title' => 'إضافة المتصفح',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'uuid' => '70468a91-c4d2-4a27-9a1b-c85b7f133967',
    'language' => 'ar',
    'customized' => 1,
  );
  // Exported menu link: menu-information:content/شروط-الاستخدام
  $menu_links['menu-information:content/شروط-الاستخدام'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/شروط-الاستخدام',
    'router_path' => 'modal/%',
    'link_title' => 'شروط الاستخدام',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'uuid' => '2caff8c7-f404-4de3-8c79-0fdf715f1b00',
    'language' => 'ar',
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('...');
  t('<user>');
  t('Administer users');
  t('Bookmarklet');
  t('Compose update');
  t('Create story');
  t('Edit fact-checking statement');
  t('Fact-checking statement');
  t('Home');
  t('Information');
  t('Logout');
  t('My account');
  t('Notifications');
  t('Sign in');
  t('Submit report');
  t('Terms of use');
  t('View incoming citizen reports');
  t('إضافة المتصفح');
  t('بيان التحقق من صحة المعلومات');
  t('شروط الاستخدام');


  return $menu_links;
}
