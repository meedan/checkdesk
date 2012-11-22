<?php

/**
 * @file
 * Menu callbacks for the Flag module.
 */

/**
 * Menu callback for (un)flagging a node.
 *
 * Used both for the regular callback as well as the JS version.
 *
 * @param $action
 *   Either 'flag' or 'unflag'.
 */
function flag_page($action, $flag, $entity_id) {
  global $user;

  // Shorten up the variables that affect the behavior of this page.
  $js = isset($_REQUEST['js']);
  $token = $_REQUEST['token'];

  // Specifically $_GET to avoid getting the $_COOKIE variable by the same key.
  $has_js = isset($_GET['has_js']);

  // Check the flag token, then perform the flagging.
  if (!flag_check_token($token, $entity_id)) {
    $error = t('Bad token. You seem to have followed an invalid link.');
  }
  elseif ($user->uid == 0 && !$has_js) {
    $error = t('You must have JavaScript and cookies enabled in your browser to flag content.');
  }
  else {
    $result = $flag->flag($action, $entity_id);
    if (!$result) {
      $error = t('You are not allowed to flag, or unflag, this content.');
    }
  }

  // If an error was received, set a message and exit.
  if (isset($error)) {
    if ($js) {
      drupal_add_http_header('Content-Type', 'text/javascript; charset=utf-8');
      print drupal_json_encode(array(
        'status' => FALSE,
        'errorMessage' => $error,
      ));
      drupal_exit();
    }
    else {
      drupal_set_message($error);
      drupal_access_denied();
      return;
    }
  }

  // If successful, return data according to the request type.
  if ($js) {
    drupal_add_http_header('Content-Type', 'text/javascript; charset=utf-8');
    $flag->link_type = 'toggle';
    print drupal_json_encode(flag_build_javascript_info($flag, $entity_id));
    drupal_exit();
  }
  else {
    drupal_set_message($flag->get_label($action . '_message', $entity_id));
    drupal_goto();
  }
}

/**
 * Form for confirming the (un)flagging of an entity.
 *
 * @param $action
 *   Either 'flag' or 'unflag'.
 * @param $flag
 *   A loaded flag object.
 * @param $entity_id
 *   The id of the entity to operate on. The type is implicit in the flag.
 *
 * @see flag_confirm_submit()
 */
function flag_confirm($form, &$form_state, $action, $flag, $entity_id) {
  $form['action'] = array(
    '#type' => 'value',
    '#value' => $action,
  );
  $form['flag_name'] = array(
    '#type' => 'value',
    '#value' => $flag->name,
  );
  $form['entity_id'] = array(
    '#type' => 'value',
    '#value' => $entity_id,
  );

  $question = $flag->get_label($action . '_confirmation', $entity_id);
  $path = isset($_GET['destination']) ? $_GET['destination'] : '<front>';
  $yes = $flag->get_label($action . '_short', $entity_id);

  if ($action == 'flag') {
    // If the action 'flag', we're potentially about to create a new
    // flagging entity. We need an empty new entity to pass to FieldAPI.
    $flagging = $flag->new_flagging($entity_id);
    field_attach_form('flagging', $flagging, $form, $form_state);
    $form['#flagging'] = $flagging;
  }

  return confirm_form($form, $question, $path, '', $yes);
}

/**
 * Submit handler for the flag confirm form.
 *
 * Note that validating whether the user may perform the action is done here,
 * rather than in a form validation handler.
 *
 * @see flag_confirm()
 */
function flag_confirm_submit(&$form, &$form_state) {
  $action = $form_state['values']['action'];
  $flag_name = $form_state['values']['flag_name'];
  $entity_id = $form_state['values']['entity_id'];

  $flag = flag_get_flag($flag_name);

  if ($action == 'flag') {
    // If the action 'flag', further build up the new entity from form values.
    $flagging = $form['#flagging'];
    entity_form_submit_build_entity('flagging', $flagging, $form, $form_state);

    $result = $flag->flag($action, $entity_id, NULL, FALSE, $flagging);
  }
  else {
    $result = $flag->flag($action, $entity_id, NULL, FALSE);
  }

  if (!$result) {
    drupal_set_message(t('You are not allowed to flag, or unflag, this content.'));
  }
  else {
    drupal_set_message($flag->get_label($action . '_message', $entity_id));
  }
}

/**
 * Builds the JavaScript structure describing the flagging operation.
 */
function flag_build_javascript_info($flag, $entity_id) {
  $info = array(
    'status' => TRUE,
    'newLink' => $flag->theme($flag->is_flagged($entity_id) ? 'unflag' : 'flag', $entity_id, TRUE),
    // Further information for the benefit of custom JavaScript event handlers:
    'contentId' => $entity_id,
    'entityType' => $flag->entity_type,
    'flagName' => $flag->name,
    'flagStatus' => $flag->is_flagged($entity_id) ? 'flagged' : 'unflagged',
  );
  drupal_alter('flag_javascript_info', $info);
  return $info;
}
