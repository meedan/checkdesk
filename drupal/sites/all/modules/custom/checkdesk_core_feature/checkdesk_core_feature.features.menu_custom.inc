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
  );
  // Exported menu: menu-information.
  $menus['menu-information'] = array(
    'menu_name' => 'menu-information',
    'title' => 'Information',
    'description' => 'Menu with links for static information pages.',
  );
  // Exported menu: menu-utility-menu.
  $menus['menu-utility-menu'] = array(
    'menu_name' => 'menu-utility-menu',
    'title' => 'Utility menu',
    'description' => 'Utility menu contains link to sign in',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Information');
  t('Main menu');
  t('Menu with links for static information pages.');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');
  t('Utility menu');
  t('Utility menu contains link to sign in');


  return $menus;
}
