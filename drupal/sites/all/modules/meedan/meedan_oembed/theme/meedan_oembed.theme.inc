<?php

/**
 * Template preprocessor for 'oembed_link' with provider 'meedan_oembed_generic'.
 */
function template_preprocess_oembed__link__meedan_oembed_generic(&$vars) {
  $embed = $vars['embed'];
  $vars['title'] = $embed->title;
  $vars['favicon_link'] = l(theme('image', array('path' => $embed->favicon_link)), $embed->provider_url, array('html' => TRUE));
  $vars['title_link'] = l($embed->title, $embed->url);
  $vars['content'] = isset($embed->description) ? $embed->description : '';
  $vars['thumbnail'] = isset($embed->thumbnail_url) ? l(theme('image', array('path' => $embed->thumbnail_url)), $embed->url, array('html' => TRUE)) : '';
  $vars['domain_link'] = l($embed->provider_name, $embed->provider_url);
}

/**
 * Template preprocessor for 'meedan_oembed_thumbnail_generic' with provider 'meedan_oembed_generic'.
 */
function template_preprocess_meedan_oembed_thumbnail_generic(&$vars) {
	$render = oembedcore_render_cache('oembed_thumbnail', $vars['url'], $vars['attributes']);
  $vars['thumbnail'] = '<img class="inline-img-thumb" src="https://dl.dropboxusercontent.com/u/450152/cover-photo.png" />';
}

/**
 * Custom link theme function.
 */
function theme_meedan_oembed_link($vars) {
  $link = '';
  if ($vars['thumbnail_url']) {
    $link .= theme('image', array('path' => $vars['thumbnail_url']));
  }
  $link .= '<a href="' . check_plain(url($vars['path'], $vars['options'])) . '"' . drupal_attributes($vars['options']['attributes']) . '>' . ($vars['options']['html'] ? $vars['text'] : check_plain($vars['text'])) . '</a>';
  return $link;
}

/**
 * Template preprocessor for 'meedan_oembed_thumbnail_generic' with provider 'meedan_oembed_twitter'.
 */
function template_preprocess_meedan_oembed_thumbnail_googlemaps(&$vars) {
  $render = oembedcore_render_cache('oembed', $vars['url'], $vars['attributes']);
  $vars['thumbnail'] = render($render);
}
