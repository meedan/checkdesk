<?php
$aliases['prod'] = array(
  'site-list' => array(
    '@prod.7iber',
    '@prod.alayyam',
    '@prod.almasryalyoum',
    '@prod.annahar',
    '@prod.maan',
    '@prod.meedan',
    '@prod.weladelbalad',
    '@prod.thetribune',
    '@prod.madamasr',
    '@prod.smex',
    '@prod.bellingcat',
    '@prod.globalvoices',
  ),
);
// temporarily remove gv
//    '@prod.globalvoices'
$aliases['qa'] = array(
  'site-list' => array('@qa.meedan'),
);

// prod aliases
$aliases['prod-alias'] = array (
  'remote-host' => 'www2.checkdesk.org',
  'root' => '/var/www/checkdesk.prod/current/drupal',
  'ssh-options' => '-p 43896',
  'path-aliases' =>
  array (
    '%drush' => '/usr/share/php/drush',
  ),
);
$aliases['prod.7iber'] = array (
  'parent' => '@prod-alias',
  'uri' => '7iber.checkdesk.org',
);
$aliases['prod.alayyam'] = array (
  'parent' => '@prod-alias',
  'uri' => 'alayyam.checkdesk.org',
);
$aliases['prod.almasryalyoum'] = array (
  'parent' => '@prod-alias',
  'uri' => 'almasryalyoum.checkdesk.org',
);
$aliases['prod.annahar'] = array (
  'parent' => '@prod-alias',
  'uri' => 'annahar.checkdesk.org',
);
$aliases['prod.maan'] = array (
  'parent' => '@prod-alias',
  'uri' => 'maan.checkdesk.org',
);
$aliases['prod.meedan'] = array (
  'parent' => '@prod-alias',
  'uri' => 'meedan.checkdesk.org',
);
$aliases['prod.weladelbalad'] = array (
  'parent' => '@prod-alias',
  'uri' => 'weladelbalad.checkdesk.org',
);
$aliases['prod.thetribune'] = array (
  'parent' => '@prod-alias',
  'uri' => 'thetribune.checkdesk.org',
);
$aliases['prod.madamasr'] = array (
  'parent' => '@prod-alias',
  'uri' => 'mersal.madamasr.com',
);
$aliases['prod.smex'] = array (
  'parent' => '@prod-alias',
  'uri' => 'smex.checkdesk.org',
);
$aliases['prod.bellingcat'] = array (
  'parent' => '@prod-alias',
  'uri' => 'bellingcat.checkdesk.org',
);
$aliases['prod.globalvoices'] = array (
  'parent' => '@prod-alias',
  'uri' => 'globalvoices.checkdesk.org',
);

// qa aliases
$aliases['qa-alias'] = array (
  'remote-host' => 'qa.checkdesk.org',
  'ssh-options' => '-p 43896',
  'path-aliases' =>
  array (
    '%drush' => '/usr/share/php/drush',
  ),
);

$aliases['qa.meedan'] = array (
  'parent' => '@qa-alias',
  'uri' => 'qa.checkdesk.org',
  'root' => '/var/www/checkdesk.qa/current/drupal',
);

// dev template
$aliases['local-alias'] = array(
  'target-command-specific' => array(
    'sql-sync' => array(
      'sanitize' => TRUE,
      'confirm-sanitizations' => TRUE,
      'no-ordered-dump' => TRUE,
      'no-cache' => TRUE,
      'create-db' => TRUE,
      'enable' => array(
        'checkdesk_devel_feature',
      ),
    ),
  ),
);
$aliases['local'] = array(
  'parent' => '@local-alias',
  'uri' => 'checkdesk.local',
  'root' => '/var/www/checkdesk/drupal',
);

include "checkdesk.aliases.local.php"

?>
