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

  // Exported menu link: main-menu_:<sub>
  $menu_links['main-menu_:<sub>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<sub>',
    'router_path' => '<sub>',
    'link_title' => '...',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_:<sub>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
    'uuid' => 'b54b8beb-654c-c3b4-1938-db4fae8838fe',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: main-menu_administer-users:admin/people
  $menu_links['main-menu_administer-users:admin/people'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/people',
    'router_path' => 'admin/people',
    'link_title' => 'Administer users',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_administer-users:admin/people',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'uuid' => '82dd0143-063e-49f9-8ccc-5260b8120464',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
    'parent_identifier' => 'main-menu_:<sub>',
  );
  // Exported menu link: main-menu_create-story:node/add/discussion
  $menu_links['main-menu_create-story:node/add/discussion'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/discussion',
    'router_path' => 'node/add/discussion',
    'link_title' => 'Create story',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_create-story:node/add/discussion',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'uuid' => 'edc54df9-4aa8-bf84-dd89-ca0a351af23b',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: main-menu_edit-fact-checking-statement:admin/config/system/checkdesk
  $menu_links['main-menu_edit-fact-checking-statement:admin/config/system/checkdesk'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'admin/config/system/checkdesk',
    'router_path' => 'admin/config/system/checkdesk',
    'link_title' => 'Edit fact-checking statement',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_edit-fact-checking-statement:admin/config/system/checkdesk',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'uuid' => '2643d8bd-eb4d-16f4-1928-3013705c11af',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
    'parent_identifier' => 'main-menu_:<sub>',
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'uuid' => 'd5f3370f-db5f-d074-d189-cbac6703dd49',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: main-menu_submit-report:node/add/media
  $menu_links['main-menu_submit-report:node/add/media'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/media',
    'router_path' => 'node/add/media',
    'link_title' => 'Submit report',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_submit-report:node/add/media',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'uuid' => '0bc3af5d-28a8-c864-bd93-f17d8bea2366',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: main-menu_update-story:node/add/post
  $menu_links['main-menu_update-story:node/add/post'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/add/post',
    'router_path' => 'node/add/post',
    'link_title' => 'Update story',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'identifier' => 'main-menu_update-story:node/add/post',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'uuid' => 'd1a4a4e9-b0c3-8d94-11a4-34f35bda25c1',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: main-menu_view-incoming-citizen-reports:reports
  $menu_links['main-menu_view-incoming-citizen-reports:reports'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'reports',
    'router_path' => 'reports',
    'link_title' => 'View incoming citizen reports',
    'options' => array(
      'identifier' => 'main-menu_view-incoming-citizen-reports:reports',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'uuid' => '06507a52-3ff5-46c6-a503-e7367944f867',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
    'parent_identifier' => 'main-menu_:<sub>',
  );
  // Exported menu link: menu-common_-:content/تنصيب-إضافة-المتصفح
  $menu_links['menu-common_-:content/تنصيب-إضافة-المتصفح'] = array(
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
      'identifier' => 'menu-common_-:content/تنصيب-إضافة-المتصفح',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'uuid' => '302da736-6f32-4024-695a-49ecde0f8091',
    'language' => 'ar',
    'menu_links_customized' => 1,
    'menu_links_language' => 'ar',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-common_bookmarklet:content/install-bookmarklet
  $menu_links['menu-common_bookmarklet:content/install-bookmarklet'] = array(
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
      'identifier' => 'menu-common_bookmarklet:content/install-bookmarklet',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'uuid' => 'd1606646-9485-5154-e504-9eabb5782cc6',
    'language' => 'en',
    'menu_links_customized' => 1,
    'menu_links_language' => 'en',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-common_information:<nolink>
  $menu_links['menu-common_information:<nolink>'] = array(
    'menu_name' => 'menu-common',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Information',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_information:<nolink>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'uuid' => '02e041f6-6c32-c594-8d35-79cb52a371d8',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-common_logout:user/logout
  $menu_links['menu-common_logout:user/logout'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Logout',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_logout:user/logout',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'uuid' => '391be377-17db-a134-4d21-c6742d07ca4e',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
    'parent_identifier' => 'menu-common_user:<sub>',
  );
  // Exported menu link: menu-common_my-account:user
  $menu_links['menu-common_my-account:user'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'My account',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_my-account:user',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'uuid' => '42e9e86e-42ae-8d04-0d50-e42bde8cbbda',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
    'parent_identifier' => 'menu-common_user:<sub>',
  );
  // Exported menu link: menu-common_notifications:my-notifications
  $menu_links['menu-common_notifications:my-notifications'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'my-notifications',
    'router_path' => 'my-notifications',
    'link_title' => 'Notifications',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_notifications:my-notifications',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'uuid' => '5626ddfd-e3f6-7ba4-f9ff-f8c36ff9d636',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-common_sign-in:user/login
  $menu_links['menu-common_sign-in:user/login'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Sign in',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_sign-in:user/login',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'uuid' => '9a684326-a352-d454-517b-878bb9468e91',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
    'parent_identifier' => 'menu-common_user:<sub>',
  );
  // Exported menu link: menu-common_take-tour:checkdesk_take_tour
  $menu_links['menu-common_take-tour:checkdesk_take_tour'] = array(
    'menu_name' => 'menu-common',
    'link_path' => 'checkdesk_take_tour',
    'router_path' => 'checkdesk_take_tour',
    'link_title' => 'Take tour',
    'options' => array(
      'attributes' => array(
        'id' => 'take-tour-link',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-common_take-tour:checkdesk_take_tour',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'uuid' => '15e60957-a3ae-4474-acc9-1c77ab8c6fbf',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-common_user:<sub>
  $menu_links['menu-common_user:<sub>'] = array(
    'menu_name' => 'menu-common',
    'link_path' => '<sub>',
    'router_path' => '<sub>',
    'link_title' => '<user>',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_user:<sub>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
    'uuid' => '919ac829-ba90-aaa4-1546-5188241b9d5b',
    'language' => 'und',
    'menu_links_customized' => 1,
    'menu_links_language' => 'und',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-information_----:content/بيان-التحقق-من-صحة-المعلومات
  $menu_links['menu-information_----:content/بيان-التحقق-من-صحة-المعلومات'] = array(
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
      'identifier' => 'menu-information_----:content/بيان-التحقق-من-صحة-المعلومات',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'uuid' => '3daae1f4-caac-41f1-b00c-7ada7412206e',
    'language' => 'ar',
    'menu_links_customized' => 1,
    'menu_links_language' => 'ar',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-information_-:content/شروط-الاستخدام
  $menu_links['menu-information_-:content/شروط-الاستخدام'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/شروط-الاستخدام',
    'router_path' => '',
    'link_title' => 'شروط الاستخدام',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
      'identifier' => 'menu-information_-:content/شروط-الاستخدام',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'uuid' => '2caff8c7-f404-4de3-8c79-0fdf715f1b00',
    'language' => 'ar',
    'menu_links_customized' => 1,
    'menu_links_language' => 'ar',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-information_-checkdesk:content/عن-checkdesk
  $menu_links['menu-information_-checkdesk:content/عن-checkdesk'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/عن-checkdesk',
    'router_path' => 'node/%',
    'link_title' => 'عن Checkdesk',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'identifier' => 'menu-information_-checkdesk:content/عن-checkdesk',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'uuid' => '73569ef8-14a7-4aa7-bb03-420d23ec8564',
    'language' => 'ar',
    'menu_links_customized' => 1,
    'menu_links_language' => 'ar',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-information_about-checkdesk:content/about-checkdesk
  $menu_links['menu-information_about-checkdesk:content/about-checkdesk'] = array(
    'menu_name' => 'menu-information',
    'link_path' => 'content/about-checkdesk',
    'router_path' => 'node/%',
    'link_title' => 'About Checkdesk',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'identifier' => 'menu-information_about-checkdesk:content/about-checkdesk',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'uuid' => '567a9623-1ab2-3fd4-ddf8-ccaffafffa37',
    'language' => 'en',
    'menu_links_customized' => 1,
    'menu_links_language' => 'en',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-information_bookmarklet:content/install-bookmarklet
  $menu_links['menu-information_bookmarklet:content/install-bookmarklet'] = array(
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
      'identifier' => 'menu-information_bookmarklet:content/install-bookmarklet',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'uuid' => 'd1606646-9485-5154-e504-9eabb5782cc6',
    'language' => 'en',
    'menu_links_customized' => 1,
    'menu_links_language' => 'en',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-information_fact-checking-statement:content/fact-checking-statement
  $menu_links['menu-information_fact-checking-statement:content/fact-checking-statement'] = array(
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
      'identifier' => 'menu-information_fact-checking-statement:content/fact-checking-statement',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'uuid' => 'aaac935a-d8c3-c964-b1a5-11747d737824',
    'language' => 'en',
    'menu_links_customized' => 1,
    'menu_links_language' => 'en',
    'menu_links_customized_2' => 1,
  );
  // Exported menu link: menu-information_terms-of-use:content/terms-use
  $menu_links['menu-information_terms-of-use:content/terms-use'] = array(
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
      'identifier' => 'menu-information_terms-of-use:content/terms-use',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'uuid' => 'a3f2b8b5-2d02-9934-79d7-246ff6231eaf',
    'language' => 'en',
    'menu_links_customized' => 1,
    'menu_links_language' => 'en',
    'menu_links_customized_2' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('...');
  t('<user>');
  t('About Checkdesk');
  t('Administer users');
  t('Bookmarklet');
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
  t('Take tour');
  t('Terms of use');
  t('Update story');
  t('View incoming citizen reports');
  t('إضافة المتصفح');
  t('بيان التحقق من صحة المعلومات');
  t('شروط الاستخدام');
  t('عن Checkdesk');


  return $menu_links;
}
