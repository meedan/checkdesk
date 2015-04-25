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
    'customized' => 1,
    'expanded' => 1,
    'external' => 0,
    'has_children' => 1,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => '<sub>',
    'link_title' => '...',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_:<sub>',
    ),
    'router_path' => '<sub>',
    'uuid' => 'b54b8beb-654c-c3b4-1938-db4fae8838fe',
    'weight' => -45,
  );
  // Exported menu link: main-menu_administer-users:admin/people
  $menu_links['main-menu_administer-users:admin/people'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'admin/people',
    'link_title' => 'Administer users',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_administer-users:admin/people',
    ),
    'parent_identifier' => 'main-menu_:<sub>',
    'router_path' => 'admin/people',
    'uuid' => '485c5e2e-cc65-4904-91e1-1ec580b522d5',
    'weight' => -49,
  );
  // Exported menu link: main-menu_create-story:node/add/discussion
  $menu_links['main-menu_create-story:node/add/discussion'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'node/add/discussion',
    'link_title' => 'Create story',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_create-story:node/add/discussion',
    ),
    'router_path' => 'node/add/discussion',
    'uuid' => 'edc54df9-4aa8-bf84-dd89-ca0a351af23b',
    'weight' => -49,
  );
  // Exported menu link: main-menu_draft--stories:checkdesk/draft_stories
  $menu_links['main-menu_draft--stories:checkdesk/draft_stories'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'checkdesk/draft_stories',
    'link_title' => 'Draft  stories',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_draft--stories:checkdesk/draft_stories',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'parent_identifier' => 'main-menu_:<sub>',
    'router_path' => 'checkdesk/draft_stories',
    'uuid' => '2821e682-4a21-4a62-87b5-9c98675c7813',
    'weight' => -47,
  );
  // Exported menu link: main-menu_draft--updates:checkdesk/draft_updates
  $menu_links['main-menu_draft--updates:checkdesk/draft_updates'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'checkdesk/draft_updates',
    'link_title' => 'Draft  updates',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'main-menu_draft--updates:checkdesk/draft_updates',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'parent_identifier' => 'main-menu_:<sub>',
    'router_path' => 'checkdesk/draft_updates',
    'uuid' => '5452488b-84b8-4398-9078-9814050cc153',
    'weight' => -46,
  );
  // Exported menu link: main-menu_edit-fact-checking-statement:admin/config/system/checkdesk
  $menu_links['main-menu_edit-fact-checking-statement:admin/config/system/checkdesk'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'admin/config/system/checkdesk',
    'link_title' => 'Edit fact-checking statement',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_edit-fact-checking-statement:admin/config/system/checkdesk',
    ),
    'parent_identifier' => 'main-menu_:<sub>',
    'router_path' => 'admin/config/system/checkdesk',
    'uuid' => '2643d8bd-eb4d-16f4-1928-3013705c11af',
    'weight' => -48,
  );
  // Exported menu link: main-menu_home:<front>
  $menu_links['main-menu_home:<front>'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 1,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => '<front>',
    'link_title' => 'Home',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_home:<front>',
    ),
    'router_path' => '',
    'uuid' => 'd5f3370f-db5f-d074-d189-cbac6703dd49',
    'weight' => -50,
  );
  // Exported menu link: main-menu_submit-report:node/add/media
  $menu_links['main-menu_submit-report:node/add/media'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'node/add/media',
    'link_title' => 'Submit report',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'main-menu_submit-report:node/add/media',
    ),
    'router_path' => 'node/add/media',
    'uuid' => '0bc3af5d-28a8-c864-bd93-f17d8bea2366',
    'weight' => -48,
  );
  // Exported menu link: main-menu_update-story:node/add/post
  $menu_links['main-menu_update-story:node/add/post'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'node/add/post',
    'link_title' => 'Update story',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'identifier' => 'main-menu_update-story:node/add/post',
    ),
    'router_path' => 'node/add/post',
    'uuid' => 'd1a4a4e9-b0c3-8d94-11a4-34f35bda25c1',
    'weight' => -47,
  );
  // Exported menu link: main-menu_view-incoming-citizen-reports:checkdesk/reports
  $menu_links['main-menu_view-incoming-citizen-reports:checkdesk/reports'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'checkdesk/reports',
    'link_title' => 'View incoming citizen reports',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'main-menu',
    'module' => 'menu',
    'options' => array(
      'identifier' => 'main-menu_view-incoming-citizen-reports:checkdesk/reports',
      'alter' => TRUE,
    ),
    'parent_identifier' => 'main-menu_:<sub>',
    'router_path' => 'checkdesk/reports',
    'uuid' => 'e48d5c0f-0c1a-49ca-8a8d-b785b7bc8514',
    'weight' => -50,
  );
  // Exported menu link: menu-common_information:<nolink>
  $menu_links['menu-common_information:<nolink>'] = array(
    'customized' => 1,
    'expanded' => 1,
    'external' => 0,
    'has_children' => 1,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => '<nolink>',
    'link_title' => 'Information',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_information:<nolink>',
    ),
    'router_path' => '<nolink>',
    'uuid' => '02e041f6-6c32-c594-8d35-79cb52a371d8',
    'weight' => -50,
  );
  // Exported menu link: menu-common_logout:user/logout
  $menu_links['menu-common_logout:user/logout'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'user/logout',
    'link_title' => 'Logout',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_logout:user/logout',
    ),
    'parent_identifier' => 'menu-common_user:<sub>',
    'router_path' => 'user/logout',
    'uuid' => '391be377-17db-a134-4d21-c6742d07ca4e',
    'weight' => -48,
  );
  // Exported menu link: menu-common_my-account:user
  $menu_links['menu-common_my-account:user'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'user',
    'link_title' => 'My account',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_my-account:user',
    ),
    'parent_identifier' => 'menu-common_user:<sub>',
    'router_path' => 'user',
    'uuid' => '42e9e86e-42ae-8d04-0d50-e42bde8cbbda',
    'weight' => -49,
  );
  // Exported menu link: menu-common_notifications:my-notifications
  $menu_links['menu-common_notifications:my-notifications'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'my-notifications',
    'link_title' => 'Notifications',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_notifications:my-notifications',
    ),
    'router_path' => 'my-notifications',
    'uuid' => '5626ddfd-e3f6-7ba4-f9ff-f8c36ff9d636',
    'weight' => -47,
  );
  // Exported menu link: menu-common_search:search
  $menu_links['menu-common_search:search'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'search',
    'link_title' => 'Search',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-common_search:search',
    ),
    'router_path' => 'search',
    'uuid' => '4f72ba17-81dc-46f1-96bf-ab4ae0bed92e',
    'weight' => -48,
  );
  // Exported menu link: menu-common_sign-in:user/login
  $menu_links['menu-common_sign-in:user/login'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'user/login',
    'link_title' => 'Sign in',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_sign-in:user/login',
    ),
    'parent_identifier' => 'menu-common_user:<sub>',
    'router_path' => 'user/login',
    'uuid' => '9a684326-a352-d454-517b-878bb9468e91',
    'weight' => -47,
  );
  // Exported menu link: menu-common_user:<sub>
  $menu_links['menu-common_user:<sub>'] = array(
    'customized' => 1,
    'expanded' => 1,
    'external' => 0,
    'has_children' => 1,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => '<sub>',
    'link_title' => '<user>',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(),
      'alter' => TRUE,
      'identifier' => 'menu-common_user:<sub>',
    ),
    'router_path' => '<sub>',
    'uuid' => '919ac829-ba90-aaa4-1546-5188241b9d5b',
    'weight' => -45,
  );
  // Exported menu link: menu-information_about-checkdesk:content/about-checkdesk
  $menu_links['menu-information_about-checkdesk:content/about-checkdesk'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'en',
    'link_path' => 'content/about-checkdesk',
    'link_title' => 'About Checkdesk',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'en',
    'menu_name' => 'menu-information',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'identifier' => 'menu-information_about-checkdesk:content/about-checkdesk',
    ),
    'router_path' => 'modal/%',
    'uuid' => '567a9623-1ab2-3fd4-ddf8-ccaffafffa37',
    'weight' => -45,
  );
  // Exported menu link: menu-information_bookmarklet:content/install-bookmarklet
  $menu_links['menu-information_bookmarklet:content/install-bookmarklet'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'en',
    'link_path' => 'content/install-bookmarklet',
    'link_title' => 'Bookmarklet',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'en',
    'menu_name' => 'menu-information',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'identifier' => 'menu-information_bookmarklet:content/install-bookmarklet',
    ),
    'router_path' => 'modal/%',
    'uuid' => 'f8c7469e-2592-4b39-84dd-7bc71c6373ba',
    'weight' => -46,
  );
  // Exported menu link: menu-information_fact-checking-statement:content/fact-checking-statement
  $menu_links['menu-information_fact-checking-statement:content/fact-checking-statement'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'en',
    'link_path' => 'content/fact-checking-statement',
    'link_title' => 'Fact-checking statement',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'en',
    'menu_name' => 'menu-information',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'identifier' => 'menu-information_fact-checking-statement:content/fact-checking-statement',
    ),
    'router_path' => 'modal/%',
    'uuid' => 'aaac935a-d8c3-c964-b1a5-11747d737824',
    'weight' => -50,
  );
  // Exported menu link: menu-information_terms-of-use:content/terms-use
  $menu_links['menu-information_terms-of-use:content/terms-use'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'en',
    'link_path' => 'content/terms-use',
    'link_title' => 'Terms of use',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'en',
    'menu_name' => 'menu-information',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
      'identifier' => 'menu-information_terms-of-use:content/terms-use',
    ),
    'router_path' => 'modal/%',
    'uuid' => '6b224c9f-ab09-421d-a672-0305c98e1fa2',
    'weight' => -48,
  );
  // Exported menu link: menu-information_إضافة-المتصفح:content/تنصيب-إضافة-المتصفح
  $menu_links['menu-information_إضافة-المتصفح:content/تنصيب-إضافة-المتصفح'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'ar',
    'link_path' => 'content/تنصيب-إضافة-المتصفح',
    'link_title' => 'إضافة المتصفح',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'ar',
    'menu_name' => 'menu-information',
    'module' => 'menu',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'alter' => TRUE,
      'identifier' => 'menu-information_إضافة-المتصفح:content/تنصيب-إضافة-المتصفح',
    ),
    'router_path' => 'modal/%',
    'uuid' => '70468a91-c4d2-4a27-9a1b-c85b7f133967',
    'weight' => 0,
  );
  // Exported menu link: menu-information_بيان-التحقق-من-صحة-المعلومات:content/بيان-التحقق-من-صحة-المعلومات
  $menu_links['menu-information_بيان-التحقق-من-صحة-المعلومات:content/بيان-التحقق-من-صحة-المعلومات'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'ar',
    'link_path' => 'content/بيان-التحقق-من-صحة-المعلومات',
    'link_title' => 'بيان التحقق من صحة المعلومات',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'ar',
    'menu_name' => 'menu-information',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'identifier' => 'menu-information_بيان-التحقق-من-صحة-المعلومات:content/بيان-التحقق-من-صحة-المعلومات',
    ),
    'router_path' => 'modal/%',
    'uuid' => '3daae1f4-caac-41f1-b00c-7ada7412206e',
    'weight' => -49,
  );
  // Exported menu link: menu-information_شروط-الاستخدام:content/شروط-الاستخدام
  $menu_links['menu-information_شروط-الاستخدام:content/شروط-الاستخدام'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'ar',
    'link_path' => 'content/شروط-الاستخدام',
    'link_title' => 'شروط الاستخدام',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'ar',
    'menu_name' => 'menu-information',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'identifier' => 'menu-information_شروط-الاستخدام:content/شروط-الاستخدام',
    ),
    'router_path' => 'modal/%',
    'uuid' => '9c0aaf8e-aa8f-440b-a85a-9cfee6ca33f7',
    'weight' => -47,
  );
  // Exported menu link: menu-information_عن-checkdesk:content/عن-checkdesk
  $menu_links['menu-information_عن-checkdesk:content/عن-checkdesk'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'ar',
    'link_path' => 'content/عن-checkdesk',
    'link_title' => 'عن Checkdesk',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'ar',
    'menu_name' => 'menu-information',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'checkdesk-use-modal',
        ),
      ),
      'identifier' => 'menu-information_عن-checkdesk:content/عن-checkdesk',
    ),
    'router_path' => 'modal/%',
    'uuid' => '73569ef8-14a7-4aa7-bb03-420d23ec8564',
    'weight' => -44,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('...');
  t('<user>');
  t('About Checkdesk');
  t('Administer users');
  t('Bookmarklet');
  t('Create story');
  t('Draft  stories');
  t('Draft  updates');
  t('Edit fact-checking statement');
  t('Fact-checking statement');
  t('Home');
  t('Information');
  t('Logout');
  t('My account');
  t('Notifications');
  t('Search');
  t('Sign in');
  t('Submit report');
  t('Terms of use');
  t('Update story');
  t('View incoming citizen reports');
  t('إضافة المتصفح');
  t('بيان التحقق من صحة المعلومات');
  t('شروط الاستخدام');
  t('عن Checkdesk');


  return $menu_links;
}
