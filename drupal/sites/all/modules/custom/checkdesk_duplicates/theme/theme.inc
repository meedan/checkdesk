<?php

/**
 * Template preprocessor for `duplicates_reports`.
 */
function checkdesk_duplicates_preprocess_checkdesk_duplicates_reports(&$variables) {
  $checkdesk_avatar = base_path() . drupal_get_path('theme', 'checkdesk') . '/assets/imgs/icons/checkdesk_avatar.png';
  $avatar = theme('html_tag', array(
    'element' => array(
      '#tag' => 'div',
      '#attributes' => array(
        'class' => array('avatar', 'thumb-60'),
        'title' => t('Checkdesk'),
        'style' => 'background-image: url("' . $checkdesk_avatar . '")'
      ),
      '#value' => '',
    ),
  ));
  $variables['avatar'] = $avatar;
}