<?php

/**
 * Template preprocessor for 'oembed_link' with provider 'meedan_oembed_facebook'.
 */
function template_preprocess_oembed__link__meedan_oembed_facebook(&$vars) {
  $embed = $vars['embed'];
  if (isset($embed->author_img)) {
    $vars['author_img'] = l(theme('image', array('path' => $embed->author_img)), $embed->author_url, array('html' => TRUE));
  }
  else {
    $vars['author_img'] = '';
  }
  if (isset($embed->author_name)) {
    $vars['author_name'] = l($embed->author_name, $embed->author_url);
  }
  else {
    $vars['author_name'] = '';
  }
  $vars['content'] = $embed->description;
  $vars['fb_picture']  = isset($embed->picture) ? theme('image', array('path' => $embed->picture)) : (isset($embed->thumbnail_url) ? theme('image', array('path' => $embed->thumbnail_url)) : '');
  $vars['fb_link_title'] = isset($embed->link_name) ? $embed->link_name : '';
  $vars['fb_link_desc'] = isset($embed->link_description) ? $embed->link_description : '';
  $vars['domain_link'] = l($embed->provider_name, $embed->provider_url);
  $vars['favicon_link'] = l(theme('image', array('path' => $embed->favicon_link)), $embed->provider_url, array('html' => TRUE));
}

/**
 * Default theme implementation for embedded Facebook status message.
 */
function theme_meedan_oembed_facebook_status($variables) {
  $text   = $variables['status'];
  $author = $variables['author'];

  $dir = meedan_oembed_needs_rtl($text) ? 'rtl' : 'ltr';

  $output  = '<div class="fb-status-preview clearfix ' . $dir . '"">';
  $output .=   check_plain($text);

  if ($author) {
    $output .= '<div class="author">&ndash; ' . l($author['name'], $author['url'], array('attributes' => array('target' => '_blank'))) . '</div>';
  }

  $output .= '</div>';

  return $output;
}
