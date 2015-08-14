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
    'weight' => -45,
  );
  // Exported menu link: menu-common_manage-users:checkdesk/people
  $menu_links['menu-common_manage-users:checkdesk/people'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'checkdesk/people',
    'link_title' => 'Manage users',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-common_manage-users:checkdesk/people',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'parent_identifier' => 'menu-common_user:<sub>',
    'router_path' => 'checkdesk/people',
    'uuid' => '485c5e2e-cc65-4904-91e1-1ec580b522d5',
    'weight' => -46,
  );
  // Exported menu link: menu-common_my-drafts:checkdesk/my_drafts
  $menu_links['menu-common_my-drafts:checkdesk/my_drafts'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'checkdesk/my_drafts',
    'link_title' => 'My drafts',
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
      'identifier' => 'menu-common_my-drafts:checkdesk/my_drafts',
    ),
    'parent_identifier' => 'menu-common_user:<sub>',
    'router_path' => 'checkdesk/my_drafts',
    'uuid' => '1bca7663-deb6-4a6f-8172-955649ecb507',
    'weight' => -48,
  );
  // Exported menu link: menu-common_my-stories:checkdesk/my_stories
  $menu_links['menu-common_my-stories:checkdesk/my_stories'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'checkdesk/my_stories',
    'link_title' => 'My stories',
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
      'identifier' => 'menu-common_my-stories:checkdesk/my_stories',
    ),
    'parent_identifier' => 'menu-common_user:<sub>',
    'router_path' => 'checkdesk/my_stories',
    'uuid' => 'ae44ca85-2011-439a-a2ee-98bfa24187df',
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
  // Exported menu link: menu-common_settings:checkdesk/settings
  $menu_links['menu-common_settings:checkdesk/settings'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'checkdesk/settings',
    'link_title' => 'Settings',
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
      'identifier' => 'menu-common_settings:checkdesk/settings',
    ),
    'parent_identifier' => 'menu-common_user:<sub>',
    'router_path' => 'checkdesk/settings',
    'uuid' => '99759df7-5990-47f8-9a09-273b3cc268dd',
    'weight' => -47,
  );
  // Exported menu link: menu-common_sign-in--sign-up:checkdesk/nojs/sign_in_up
  $menu_links['menu-common_sign-in--sign-up:checkdesk/nojs/sign_in_up'] = array(
    'customized' => 1,
    'expanded' => 0,
    'external' => 0,
    'has_children' => 0,
    'hidden' => 0,
    'language' => 'und',
    'link_path' => 'checkdesk/nojs/sign_in_up',
    'link_title' => 'Sign in / Sign up',
    'menu_links_customized' => 1,
    'menu_links_customized_2' => 1,
    'menu_links_language' => 'und',
    'menu_name' => 'menu-common',
    'module' => 'menu',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'menu-common_sign-in--sign-up:checkdesk/nojs/sign_in_up',
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
    ),
    'parent_identifier' => 'menu-common_user:<sub>',
    'router_path' => 'checkdesk/%/sign_in_up',
    'uuid' => '9a684326-a352-d454-517b-878bb9468e91',
    'weight' => -50,
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
  t('<user>');
  t('About Checkdesk');
  t('Bookmarklet');
  t('Fact-checking statement');
  t('Logout');
  t('Manage users');
  t('My drafts');
  t('My stories');
  t('Notifications');
  t('Settings');
  t('Sign in / Sign up');
  t('Terms of use');
  t('إضافة المتصفح');
  t('بيان التحقق من صحة المعلومات');
  t('شروط الاستخدام');
  t('عن Checkdesk');

  return $menu_links;
}
