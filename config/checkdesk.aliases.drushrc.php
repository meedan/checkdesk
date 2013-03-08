<?php
$aliases['dev'] = array(
  'uri' => 'http://dev.checkdesk.org',
  'root' => '/var/www/checkdesk.dev/current/drupal',
  'remote-host' => 'dev.checkdesk.org',
  'ssh-options' => '-p43896',
);
$aliases['qa'] = array(
  'uri' => 'http://qa.checkdesk.org',
  'root' => '/var/www/checkdesk.qa/current/drupal',
  'remote-host' => 'qa.checkdesk.org',
  'ssh-options' => '-p43896',
);
$aliases['prod'] = array(
  'uri' => 'http://meedan.checkdesk.org',
  'root' => '/var/www/checkdesk.prod/current/drupal',
  'remote-host' => 'checkdesk.live',
  'ssh-options' => '-p43896',
);

