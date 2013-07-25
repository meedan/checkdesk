<?php

/**
 * Override or insert variables into the region template.
 */
function checkdesk_embed_preprocess_page(&$variables) {
  // Invoke parent preprocessor
  checkdesk_preprocess_page($variables);

  // Never display user alerts in the embed
  unset($variables['page']['content']['user_alert_user_alert']);

  if ($variables['node']->type == 'media') {
    $variables['factcheck_cta'] = array(
      '#type' => 'link',
      '#title' => '<span class="icon-comments-alt"></span> ' . t('Help verify this report'),
      '#href' => url('node/' . $variables['node']->nid, array('absolute' => TRUE)),
      '#options' => array(
        'attributes' => array('class' => array('factcheck-cta', 'btn', 'btn-large')),
        'html' => TRUE,
      )
    );
  }
}

/**
 * Override or insert variables into the region template.
 */
function checkdesk_embed_preprocess_node(&$variables) {
  // Invoke parent preprocessor
  checkdesk_preprocess_node($variables);

  $node = $variables['node'];

  if ($node->type == 'discussion') {
    $body = $node->body && $node->body[LANGUAGE_NONE] && $node->body[LANGUAGE_NONE][0]
          ? $node->body[LANGUAGE_NONE][0]
          : FALSE;

    if ($body) {
      $variables['content']['body'] = array(
        '#type' => 'markup',
        '#markup' => check_markup($body['value'], $body['format']),
      );
    }
  }
}
