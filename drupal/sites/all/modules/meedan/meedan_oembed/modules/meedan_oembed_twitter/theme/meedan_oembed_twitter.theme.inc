<?php

/**
 * Template preprocessor for 'oembed_link' with provider 'meedan_oembed_twitter'.
 */
function template_preprocess_oembed__link__meedan_oembed_twitter(&$vars) {
  $embed = $vars['embed'];
  $vars['favicon_link'] = l(theme('image', array('path' => $embed->favicon_link)), $embed->provider_url, array('html' => TRUE));
  $vars['content'] = $embed->html;
  $vars['domain_link'] = l($embed->provider_name, $embed->provider_url);
}

function theme_meedan_oembed_twitter_tweet($variables) {
  return '<div class="tweet-preview">' . $variables['tweet'] . '</div>';
}

/**
 * Template preprocessor for 'meedan_oembed_thumbnail_generic' with provider 'meedan_oembed_twitter'.
 */
function template_preprocess_meedan_oembed_thumbnail_twitter(&$vars) {
	$render = oembedcore_render_cache('oembed', $vars['url'], $vars['attributes']);
  $vars['thumbnail'] = render($render);
}
