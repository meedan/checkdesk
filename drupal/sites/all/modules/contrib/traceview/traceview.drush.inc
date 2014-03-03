<?php

/**
 * @file
 * Implements drush hooks for the traceview module.
 */

/**
 * Implements hook_drush_exit().
 *
 * Record traceview traffic partitioning and controller within drush.
 */
function traceview_drush_exit() {
  // Partition drush commands.
  if (variable_get('traceview_partition_drush_traffic', FALSE)) {
    traceview_set_partition('Drush');
  }

  // Track drush comamnds.
  if (variable_get('traceview_track_drush_commands', FALSE)) {
    $command = drush_get_command();
    $drush_controller = array(
      'Controller' => $command['command'],
      'Action' => (!empty($command['arguments'][0]) ? traceview_get_action($command['arguments'][0]) : NULL),
    );
    traceview_set_controller($controller, TRUE, FALSE);
  }
}
