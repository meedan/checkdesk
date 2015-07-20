<?php
/**
 * @file
 * Drush implementation for the unused_modules module.
 */

/**
 * Implements hook_drush_command().
 */
function unused_modules_drush_command() {
  $items = array();
  $items['unused-modules'] = array(
    'description' => 'Show unused modules or projects.',
    'aliases' => array('um', 'unused_modules'),
    'arguments' => array(
      'type' => 'Options "projects" and "modules". Show modules or projects (defaults to projects).',
      'show' => 'Options "all" and "disabled". Show only disabled modules (defaults to disabled).',
    ),
    'examples' => array(
      'Show projects that are unused.' => 'drush unused-modules projects disabled',
      'As above, shorthand.' => 'drush um',
      'As above, include projects with enabled modules.' => 'drush unused-modules projects disabled',
      'Show modules that are unused.' => 'drush unused-modules modules disabled',
      'As above, include enabled modules.' => 'drush unused-modules modules disabled',
    ),
  );
  return $items;
}

/**
 * Implements of hook_drush_help().
 */
function unused_modules_drush_help($section) {
  switch ($section) {
    case 'drush:unused-modules':
      return dt("Show modules and projects that are unused.");
  }
}

/**
 * Drush command callback.
 */
function drush_unused_modules($type = "projects", $show = "disabled") {

  // Print projects.
  if ($type == 'projects') {
    if ($show == 'all') {
      drush_unused_modules_show_projects('all');
    }
    elseif ($show == 'disabled') {
      drush_unused_modules_show_projects('disabled');
    }
    else {
      drush_set_error("unknown 'show' argument " . $show . ". See drush unused-modules --help");
    }
  }
  // Print modules.
  elseif ($type == 'modules') {
    if ($show == 'all') {
      drush_print($show);
      drush_unused_modules_show_modules('all');
    }
    elseif ($show == 'disabled') {
      drush_unused_modules_show_modules('disabled');
    }
    else {
      drush_set_error("unknown 'show' argument " . $show . ". See drush unused-modules --help");
    }
  }
  else {
    drush_set_error("unknown 'type' argument " . $type . ". See drush unused-modules --help");
  }
}

/**
 * Drush callback.
 *
 * Prints a table with orphaned projects.
 *
 * @param string $op
 *   Either 'all' or 'disabled'.
 *
 * @return string
 *   themed table.
 */
function drush_unused_modules_show_projects($op = 'all') {
  $modules = _unused_modules_get_modules_by_project();

  $header = array(
    'Project',
    'Project has Enabled Modules',
    'Project Path',
  );

  // With Drush, the first row is the header.
  $rows = array();
  $rows[] = $header;

  foreach ($modules as $module) {
    if ($op == 'all') {
      $rows[$module->project] = array(
        $module->project,
        ($module->project_has_enabled_modules) ? t("Yes") : t("No"),
        $module->project_path,
      );
    }
    elseif ($op == 'disabled') {
      if (!$module->project_has_enabled_modules) {
        $rows[$module->project] = array(
          $module->project,
          ($module->project_has_enabled_modules) ? t("Yes") : t("No"),
          $module->project_path,
        );
      }
    }
  }

  if (!$rows) {
    drush_print("Hurray, no orphaned projects!");
  }

  drush_print_table($rows, TRUE);
}


/**
 * Drush callback.
 *
 * Prints a table with orphaned modules.
 *
 * @param string $op
 *   Either 'all' or 'disabled'.
 *
 * @return string
 *   themed table.
 */
function drush_unused_modules_show_modules($op = 'all') {
  $modules = _unused_modules_get_modules_by_project();

  $header = array(
    'Project',
    'Module',
    'Module enabled',
    'Project has Enabled Modules',
    'Project Path',
  );

  // With Drush, the first row is the header.
  $rows = array();
  $rows[] = $header;

  foreach ($modules as $module) {
    if ($op == 'all') {
      $rows[$module->name] = array(
        $module->project,
        $module->name,
        ($module->module_is_enabled) ? t("Yes") : t("No"),
        ($module->project_has_enabled_modules) ? t("Yes") : t("No"),
        $module->project_path,
      );
    }
    elseif ($op == 'disabled') {
      if (!$module->project_has_enabled_modules) {
        $rows[$module->name] = array(
          $module->project,
          $module->name,
          ($module->module_is_enabled) ? t("Yes") : t("No"),
          ($module->project_has_enabled_modules) ? t("Yes") : t("No"),
          $module->project_path,
        );
      }
    }
  }

  if (!$rows) {
    drush_print("Hurray, no orphaned modules!");
  }

  drush_print_table($rows, TRUE);
}
