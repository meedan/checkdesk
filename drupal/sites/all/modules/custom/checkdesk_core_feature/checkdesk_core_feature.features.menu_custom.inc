<?php
/**
 * @file
 * checkdesk_core_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function checkdesk_core_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-common.
  $menus['menu-common'] = array(
    'menu_name' => 'menu-common',
    'title' => 'Common',
    'description' => 'Links that are common to all users and appear usually at the right.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer',
    'description' => 'Links for footer',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-information.
  $menus['menu-information'] = array(
    'menu_name' => 'menu-information',
    'title' => 'Information',
    'description' => 'Menu with links for static information pages.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Common');
  t('Footer');
  t('Information');
  t('Links for footer');
  t('Links that are common to all users and appear usually at the right.');
  t('Main menu');
  t('Menu with links for static information pages.');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
