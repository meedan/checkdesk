<?php

$plugin = array(
  'schema' => 'oembedcore_provider',
  'access' => 'administer oembed',
  'menu' => array(
    'menu prefix' => 'admin/config/media/oembed',
    'menu item' => 'provider',
    'menu title' => 'Providers',
    'menu description' => 'Add, edit and remove oembed providers from the system.',
  ),
  'handler' => array(
    'class' => 'oembed_provider_ui',
    'parent' => 'ctools_export_ui',
  ),
  'title singular' => t('provider'),
  'title singular proper' => t('Provider'),
  'title plural' => t('providers'),
  'title plural proper' => t('Providers'),
);
