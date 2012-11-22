<?php

/**
 * @file
 * Hooks provided by the Flag module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Define one or more flag types.
 *
 * This hook may be placed in a $module.flag.inc file.
 *
 * @return
 *  An array whose keys are flag type names and whose values are properties of
 *  the flag type.
 *  When a flag type is for an entity, the flag type name must match the entity
 *  type.
 *  Properties for flag types are as follows:
 *  - 'title': The main label of the flag type.
 *  - 'description': A longer description shown in the UI when creating a new
 *    flag.
 *  - 'handler': The name of the class implementing this flag type.
 *
 * @see flag_fetch_definition()
 */
function hook_flag_type_info() {
  return array(
    'node' => array(
      'title' => t('Nodes'),
      'description' => t("Nodes are a Drupal site's primary content."),
      'handler' => 'flag_node',
    ),
  );
}

/**
 * Alter flag type definitions provided by other modules.
 *
 * This hook may be placed in a $module.flag.inc file.
 *
 * @param $definitions
 *  An array of flag definitions returned by hook_flag_type_info().
 */
function hook_flag_type_info_alter(&$definitions) {

}

/**
 * Define default flags.
 */
function hook_flag_default_flags() {

}

/**
 * Allow modules to alter a flag when it is initially loaded.
 *
 * @see flag_get_flags().
 */
function hook_flag_alter(&$flag) {

}

/**
 * Alter a flag's default options.
 *
 * Modules that wish to extend flags and provide additional options must declare
 * them here so that their additions to the flag admin form are saved into the
 * flag object.
 *
 * @param $options
 *  The array of default options for the flag type, with the options for the
 *  flag's link type merged in.
 * @param $flag
 *  The flag object.
 *
 * @see flag_flag::options()
 */
function hook_flag_options_alter(&$options, $flag) {

}

/**
 * Act on an object being flagged.
 *
 * @param $flag
 *  The flag object.
 * @param $entity_id
 *  The id of the entity the flag is on.
 * @param $account
 *  The user account performing the action.
 * @param $flagging_id
 *  The flagging entity.
 */
function hook_flag_flag($flag, $entity_id, $account, $flagging) {

}

/**
 * Act on an object being unflagged.
 *
 * This is invoked after the flag count has been decreased, but before the
 * flagging entity has been deleted.
 *
 * @param $flag
 *  The flag object.
 * @param $entity_id
 *  The id of the entity the flag is on.
 * @param $account
 *  The user account performing the action.
 * @param $flagging
 *  The flagging entity.
 */
function hook_flag_unflag($flag, $entity_id, $account, $flagging) {

}

/**
 * Allow modules to allow or deny access to flagging.
 *
 * @param $flag
 *  The flag object.
 * @param $entity_id
 *  The id of the entity in question.
 * @param $action
 *  The action to test. Either 'flag' or 'unflag'.
 * @param $account
 *  The user on whose behalf to test the flagging action.
 *
 * @return
 *   Boolean TRUE if the user is allowed to flag/unflag the given entity.
 *   FALSE otherwise.
 *
 * @see flag_flag:access()
 */
function hook_flag_access($flag, $entity_id, $action, $account) {

}

/**
 * Allow modules to allow or deny access to flagging.
 *
 * @param $flag
 *  The flag object.
 * @param $entity_ids
 *  An array of object ids to check access.
 * @param $account
 *  The user on whose behalf to test the flagging action.
 *
 * @return
 *   An array whose keys are the object IDs and values are booleans indicating
 *   access.
 *
 * @see hook_flag_access()
 * @see flag_flag:access_multiple()
 */
function hook_flag_access_multiple($flag, $entity_ids, $account) {

}

/**
 * Define one or more flag link types.
 *
 * Link types defined here must be returned by this module's hook_flag_link().
 *
 * This hook may be placed in a $module.flag.inc file.
 *
 * @return
 *  An array of one or more types, keyed by the machine name of the type, and
 *  where each value is a link type definition as an array with the following
 *  properties:
 *  - 'title': The human-readable name of the type.
 *  - 'description': The description of the link type.
 *  - 'options': An array of extra options for the link type.
 *  - 'uses standard js': Boolean, indicates whether the link requires Flag
 *    module's own JS file for links.
 *  - 'uses standard css': Boolean, indicates whether the link requires Flag
 *    module's own CSS file for links.
 *  - 'provides form': (optional) Boolean indicating that this link type shows
 *    the user a flagging entity form. This property is used in the UI, eg to
 *    warn the admin user of link types that are not compatible with other
 *    flag options. Defaults to FALSE.
 *
 * @see flag_get_link_types()
 * @see hook_flag_link_type_info_alter()
 */
function hook_flag_link_type_info() {

}

/**
 * Alter other modules' definitions of flag link types.
 *
 * This hook may be placed in a $module.flag.inc file.
 *
 * @param $link_types
 *  An array of the link types defined by all modules.
 *
 * @see flag_get_link_types()
 * @see hook_flag_link_type_info()
 */
function hook_flag_link_type_info_alter(&$link_types) {

}

/**
 * Return the link for the link types this module defines.
 *
 * The type of link to be produced is given by $flag->link_type.
 *
 * When Flag uses a link type provided by this module, it will call this
 * implementation of hook_flag_link(). This should return a single link's
 * attributes, using the same structure as hook_link(). Note that "title" is
 * provided by the Flag configuration if not specified here.
 *
 * @param $flag
 *   The full flag object for the flag link being generated.
 * @param $action
 *   The action this link should perform. Either 'flag' or 'unflag'.
 * @param $entity_id
 *   The ID of the node, comment, user, or other object being flagged. The type
 *   of the object can be deduced from the flag type.
 *
 * @return
 *   An array defining properties of the link.
 *
 * @see hook_flag_link_type_info()
 * @see template_preprocess_flag()
 */
function hook_flag_link() {

}

/**
 * Act on flag deletion.
 *
 * This is invoked after all the flag database tables have had their relevant
 * entries deleted.
 *
 * @param $flag
 *  The flag object that has been deleted.
 */
function hook_flag_delete($flag) {

}

/**
 * Act when a flag is reset.
 *
 * @param $flag
 *  The flag object.
 * @param $entity_id
 *  The entity ID on which all flaggings are to be removed. May be NULL, in
 *  which case all of this flag's entities are to be unflagged.
 * @param $rows
 *  Database rows from the {flagging} table.
 *
 * @see flag_reset_flag()
 */
function hook_flag_reset($flag, $entity_id, $rows) {

}

/**
 * Alter the javascript structure that describes the flag operation.
 *
 * @param $flag
 *   The full flag object.
 * @param $entity_id
 *   The ID of the node, comment, user or other object being flagged.
 *
 * @see flag_build_javascript_info()
 */
function hook_flag_javascript_info_alter() {

}
