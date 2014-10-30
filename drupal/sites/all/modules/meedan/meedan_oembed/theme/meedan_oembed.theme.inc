<?php

/**
 * Template preprocessor for 'oembed_link' with provider 'meedan_oembed_generic'.
 */
function template_preprocess_oembed__link__meedan_oembed_generic(&$vars) {
  $embed = $vars['embed'];
  $vars['title'] = $embed->title;
  $vars['favicon_link'] = l(theme('image', array('path' => $embed->favicon_link)), $embed->provider_url, array('html' => TRUE, 'attributes' => array('class' => array('favicon'))));
  $vars['title_link'] = l($embed->title, $embed->url);
  $vars['content'] = isset($embed->description) ? $embed->description : '';
  $vars['thumbnail'] = isset($embed->thumbnail_url) ? l(theme('image', array('path' => $embed->thumbnail_url)), $embed->url, array('html' => TRUE)) : '';
  $vars['domain_link'] = l($embed->provider_name, $embed->provider_url);
}

/**
 * Template preprocessor for 'meedan_oembed_thumbnail_generic' with provider 'meedan_oembed_generic'.
 */
function template_preprocess_meedan_full_mode(&$vars) {
	$embed = $vars['entity']->embed;
  $node = $vars['entity'];
  $vars['embed'] = $embed;
  $vars['node'] = $node;

  // set provider class name
  $provider = strtolower($embed->provider_name);
  $vars['provider_class_name'] = str_replace('.', '_', $provider) . '-wrapper';
  // Set author name or provider name
  if(isset($embed->author_url) && isset($embed->author_name)) {
      $vars['author_name'] = $embed->author_url ? l($embed->author_name, $embed->author_url) : $embed->author_name;
  } else {
    $vars['provider_name'] = $embed->original_url ? l($embed->provider_name, $embed->original_url) : $embed->provider_name;
  }
  // Media description
    if(isset($node->body['und'][0]['value'])) {
      $vars['media_description'] = $node->body['und'][0]['value'];
    }
  // Set favicon 
  if (isset($embed->favicon_link)) {
    $vars['favicon_link'] = l(
      theme('image', array( 'path' => $embed->favicon_link)),
      $embed->original_url, array('html' => TRUE, 'attributes' => array('class' => array('favicon')))
    );
  }

  // timestamp
  // TODO: make this source media timestamp
  $vars['media_creation_info'] = t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a>', array(
      '@url' => $embed->original_url,
      '!timestamp' => format_date($node->created, 'custom', 'Y-m-d\TH:i:sP'),
      '!datetime' => format_date($node->created, 'custom', t('M d, Y \a\t g:ia e')),
      '!daydatetime' => format_date($node->created, 'custom', t('D, F j\t\h \a\t g:i A')),
      '!interval' => format_interval(time() - $node->created, 1),
    ));

  // Inline thumbnail
  if(isset($embed->thumbnail_url)) {
    $vars['inline_thumbnail'] = l(theme_image(array('path' => $embed->thumbnail_url, 'attributes' => array('class' => array('inline-img-thumb')))), 'node/' . $node->nid , array('html' => TRUE));
  }

  // Load report status
  if(isset($node->field_rating)) {
    if($node->field_rating['und'][0]['tid'] != 4) {
      $vars['report_status'] = _checkdesk_report_status($node);
    }
  }
}

/**
 * Template preprocessor for 'meedan_oembed_thumbnail_generic' with provider 'meedan_oembed_generic'.
 */
function template_preprocess_meedan_inline_full_mode(&$vars) {

  $embed = $vars['entity']->embed;
  $node = $vars['entity'];
  $vars['embed'] = $embed;
  $vars['node'] = $node;

  // set provider class name
  $provider = strtolower($embed->provider_name);
  $vars['provider_class_name'] = str_replace('.', '_', $provider) . '-wrapper';
  // Set author name or provider name
  if(isset($embed->author_url) && isset($embed->author_name)) {
      $vars['author_name'] = $embed->author_url ? l($embed->author_name, $embed->author_url) : $embed->author_name;
  } else {
    $vars['provider_name'] = $embed->original_url ? l($embed->provider_name, $embed->original_url) : $embed->provider_name;
  }
  // Set favicon 
  if (isset($embed->favicon_link)) {
    $vars['favicon_link'] = l(
      theme('image', array( 'path' => $embed->favicon_link)),
      $embed->original_url, array('html' => TRUE, 'attributes' => array('class' => array('favicon')))
    );
  }

  // timestamp
  // TODO: make this source media timestamp
  $vars['media_creation_info'] = t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a>', array(
      '@url' => $embed->original_url,
      '!timestamp' => format_date($node->created, 'custom', 'Y-m-d\TH:i:sP'),
      '!datetime' => format_date($node->created, 'custom', t('M d, Y \a\t g:ia e')),
      '!daydatetime' => format_date($node->created, 'custom', t('D, F j\t\h \a\t g:i A')),
      '!interval' => format_interval(time() - $node->created, 1),
    ));

  // Inline thumbnail
  if(isset($embed->thumbnail_url)) {
    $vars['inline_thumbnail'] = l(theme_image(array('path' => $embed->thumbnail_url, 'attributes' => array('class' => array('inline-img-thumb')))), 'node/' . $node->nid , array('html' => TRUE));
  }

  // Load report status
  if(isset($node->field_rating)) {
    if($node->field_rating['und'][0]['tid'] == 2) {
      $vars['report_status'] = _checkdesk_report_status($node);
    }
  }

}

/**
 * Template preprocessor for 'meedan_oembed_thumbnail_generic' with provider 'meedan_oembed_generic'.
 */
function template_preprocess_meedan_inline_thumbnail(&$vars) {

 $embed = $vars['entity']->embed;
  $node = $vars['entity'];
  $vars['embed'] = $embed;
  $vars['node'] = $node;

  // set provider class name
  $provider = strtolower($embed->provider_name);
  $vars['provider_class_name'] = str_replace('.', '_', $provider) . '-wrapper';
  // Set author name or provider name
  if(isset($embed->author_url) && isset($embed->author_name)) {
      $vars['author_name'] = $embed->author_url ? l($embed->author_name, $embed->author_url) : $embed->author_name;
  } else {
    $vars['provider_name'] = $embed->original_url ? l($embed->provider_name, $embed->original_url) : $embed->provider_name;
  }
  // Set favicon 
  if (isset($embed->favicon_link)) {
    $vars['favicon_link'] = l(
      theme('image', array( 'path' => $embed->favicon_link)),
      $embed->original_url, array('html' => TRUE, 'attributes' => array('class' => array('favicon')))
    );
  }

  // timestamp
  // TODO: make this source media timestamp
  $vars['media_creation_info'] = t('<a href="@url"><time class="date-time" datetime="!timestamp">!daydatetime</time></a>', array(
      '@url' => $embed->original_url,
      '!timestamp' => format_date($node->created, 'custom', 'Y-m-d\TH:i:sP'),
      '!datetime' => format_date($node->created, 'custom', t('M d, Y \a\t g:ia e')),
      '!daydatetime' => format_date($node->created, 'custom', t('D, F j\t\h \a\t g:i A')),
      '!interval' => format_interval(time() - $node->created, 1),
    ));

  // Inline thumbnail
  if(isset($embed->thumbnail_url)) {
    $vars['inline_thumbnail'] = l(theme_image(array('path' => $embed->thumbnail_url, 'attributes' => array('class' => array('inline-img-thumb')))), 'node/' . $node->nid , array('html' => TRUE));
  }

  // Load report status
  if(isset($node->field_rating)) {
    if($node->field_rating['und'][0]['tid'] == 2) {
      $vars['report_status'] = _checkdesk_report_status($node);
    }
  }
 

}

/**
 * Template preprocessor for 'meedan_oembed_thumbnail_generic' with provider 'meedan_oembed_generic'.
 */
function template_preprocess_meedan_oembed_thumbnail_generic(&$vars) {
  $render = oembedcore_render_cache('oembed_thumbnail', $vars['url'], $vars['attributes']);
  $vars['thumbnail'] = render($render);
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
