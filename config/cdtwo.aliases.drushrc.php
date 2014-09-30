<?php

$aliases['dev'] = array(
  'site-list' => array('@dev.meedan'),
);

// dev aliases
$aliases['dev-alias'] = array (
//   'remote-host' => 'cd-two.dev.meedan.net',
//   'ssh-options' => '-p 8922',
  'path-aliases' => array (
    '%drush' => '/usr/share/php/drush',
  ),
);
$aliases['dev.meedan'] = array (
  'parent' => '@dev-alias',
  'uri' => 'cd-two.dev.meedan.net',
  'root' => '/var/www/cd-two/current/drupal',
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

include "cdtwo.aliases.local.php"

?>
