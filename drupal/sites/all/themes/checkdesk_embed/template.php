<?php

/**
 * Override or insert variables into the region template.
 */
function checkdesk_embed_preprocess_page(&$variables) {
  // Invoke parent preprocessor
  checkdesk_preprocess_page($variables);

  // Never display user alerts in the embed
  unset($variables['page']['content']['user_alert_user_alert']);
}

/**
 * Override or insert variables into the region template.
 */
function checkdesk_embed_preprocess_region(&$variables) {
  // Invoke parent preprocessor
  checkdesk_preprocess_region($variables);

  // TODO: Update the footer region
}
