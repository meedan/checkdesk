<?php

/**
 * Title callback for `_checkdesk_core_report_suggest`.
 */
function _checkdesk_reports_suggest_title($report) {
  return user_access('add report to story') ?
    t('Add Report "!title" to Story', array(
        '!title' => views_trim_text(array('max_length' => 30, 'ellipsis' => TRUE), $report->title))
    ) :
    t('Suggest Report "!title" to Story', array(
        '!title' => views_trim_text(array('max_length' => 30, 'ellipsis' => TRUE), $report->title))
    );
}

/**
 * Form function for `_checkdesk_reports_suggest_report`.
 * Allow user to choose from all stories not already associated with this report.
 */
function _checkdesk_reports_suggest_report($form, $form_state, $report = NULL) {
  if (empty($report)) {
    $report = $form_state['report'];
  }
  $query = db_select('node', 'n');
  $query->addField('n', 'nid');
  $query->addExpression("CONCAT(substring(title, 1, 48), '...')", 'ttle');
  $query->condition('type', 'discussion');
  $query->orderBy('created', 'DESC');
  $query->range(0, 10);
  $stories = $query->execute()->fetchAllKeyed();
  $form['story'] = array(
    '#type' => 'select',
    '#options' => $stories,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $form['#report'] = $report;
  return $form;
}

/**
 * Submit function for `_checkdesk_reports_suggest_report`.
 */
function _checkdesk_reports_suggest_report_submit($form, &$form_state) {
  // Add the story to the report.
  $report = $form['#report'];
  if (module_exists('checkdesk_reports_duplicates')) {
    // Clone existing report ticket #3660
    $report = _checkdesk_duplicate_share_report($report, $form_state['values']['story']);
  }
  else {
    $report->field_stories[LANGUAGE_NONE][]['target_id'] = $form_state['values']['story'];
    node_save($report);
  }
  $story = node_load($form_state['values']['story']);
  $form_state['values']['story_title'] = $story->title;
  $form_state['values']['report_id'] = $report->nid;
  // Redirect to story.
  if (user_access('add report to story')) {
    $form_state['redirect'] = array('node/add/post', array('query' => array('report' => $report->nid, 'story' => $form_state['values']['story'])));
  }
}



/**
 * Modal function for `_checkdesk_reports_suggest_report`.
 */
function _checkdesk_reports_suggest_report_modal($report, $js) {
  if (!$js) {
    drupal_goto('node/' . $report->nid . '/checkdesk/suggest');
    return;
  }
  ctools_include('modal');
  ctools_include('ajax');

  $form_state = array(
    'ajax' => TRUE,
    'title' => _checkdesk_reports_suggest_title($report),
    'report' => $report,
  );

  $commands = ctools_modal_form_wrapper('_checkdesk_reports_suggest_report', $form_state);

  if (!empty($form_state['executed'])) {
    // Add the responder javascript, required by ctools
    ctools_add_js('ajax-responder');

    // Array with ajax response.
    $commands = array();
    // Create ajax command array, set the message and dismiss the modal window.
    $message = t('<b>' . views_trim_text(array('max_length' => 30, 'ellipsis' => TRUE), $report->title) . '</b> added to <b>' . $form_state['values']['story_title'] . '</b>');
    drupal_set_message(t($message));
    // $commands[] = ajax_command_prepend('#messages-container', theme('status_messages'));
    $commands[] = ctools_modal_command_dismiss();

    // Redirect to story.
    if (user_access('add report to story')) {
      $commands[] = ctools_ajax_command_redirect('node/add/post', 0, array('query' => array('report' => $form_state['values']['report_id'], 'story' => $form_state['values']['story'])));
    }
  }

  print ajax_render($commands);
  exit;
}
