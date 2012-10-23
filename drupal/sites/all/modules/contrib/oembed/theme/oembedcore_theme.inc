<?php

/**
 * @file
 * Theme related functions for oEmbed Core
 */

/**
 * Template for oEmbed theme.
 */
function template_preprocess_oembed(&$vars, $hook) {
  $embed = $vars['embed'];
  if ($embed) {

    $vars['original_url'] = $embed->original_url;

    $vars['classes_array'][] = 'oembed-'. $embed->type;
    $vars['title_attributes_array']['class'] = 'oembed-title';
    $vars['content_attributes_array']['class'] = 'oembed-content';

    // oEmbed links render using core link theme unless other preprocess
    // functions suggest other hooks.
    if ($embed->type == 'link') {
      $vars['title_attributes_array']['class'] .= ' oembed-link';

      $vars['theme_hook_suggestions'][] = 'link';
      $vars['path'] = $embed->original_url;
      $vars['text'] = $embed->title;
      $vars['options'] = array(
        'absolute' => TRUE,
        'attributes' => $vars['title_attributes_array'],
        'html' => TRUE,
      );
    }
  }
}
