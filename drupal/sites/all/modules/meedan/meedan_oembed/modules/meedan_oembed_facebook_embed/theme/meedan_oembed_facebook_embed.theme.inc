<?php

/**
 * Template preprocessor for 'meedan_oembed_thumbnail_generic' with provider 'meedan_oembed_facebook'.
 */
function template_preprocess_meedan_oembed_thumbnail_facebook(&$vars) {
  $vars['thumbnail'] = render(oembedcore_render_cache('oembed', $vars['url'], $vars['attributes']));
}
