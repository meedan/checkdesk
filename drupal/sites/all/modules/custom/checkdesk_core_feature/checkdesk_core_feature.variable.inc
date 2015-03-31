<?php
/**
 * @file
 * checkdesk_core_feature.variable.inc
 */

/**
 * Implements hook_variable_realm_default_variables().
 */
function checkdesk_core_feature_variable_realm_default_variables() {
$realm_variables = array();
  $realm_variables['language']['ar'] = array(
  'r4032login_access_denied_message' => 'الوصول ممنوع. سجل دخولك لتصل للصفحة.',
);

return $realm_variables;
}
