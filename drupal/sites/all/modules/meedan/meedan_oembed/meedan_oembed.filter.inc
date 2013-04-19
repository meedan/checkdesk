<?php

/**
 * Implements hook_filter_info().
 */
function meedan_oembed_filter_info() {
  $filters['filter_meedan_oembed'] = array(
    'title' => t('Meedan oEmbed filter'),
    'description' => t('Every instance of [media-title:$nid] will be replaced with the corresponding Meedan oEmbed node view.'),
    'prepare callback' => '_meedan_oembed_filter_prepare',
    'process callback' => '_meedan_oembed_filter_process',
    'tips callback' => '_meedan_oembed_filter_tips',
    'cache' => FALSE,
  );
  return $filters;
}

/**
 * Meedan oEmbed filter prepare callback.
 */
function _meedan_oembed_filter_prepare($text, $filter) {
  return $text;
}

/**
 * Time filter process callback.
 *
 * Now, in the "process" step, we'll search for our escaped time tags and
 * do the real filtering: replace nid with meedan oembed node view.
 */
function _meedan_oembed_filter_process($text, $filter) {
  $matches = array();
  preg_match_all('/\[\S+:(\d+)\]/u', $text, $matches);
  if (count($matches[1])) {
    $output = array();
    foreach ($matches[1] as $key => $nid) {
      if (is_numeric($nid)) {
        $node = node_load($nid);
        if (is_object($node)) {
          // Render node using custom Meedan oEmbed view.
          $element = node_view($node, 'meedan_oembed');
          $element['comments'] = comment_node_page_additions($node);
          $node_view = drupal_render($element);
          // Replace [media-title:$nid] with node view.
          $text = str_replace($matches[0][$key], $node_view, $text);
        }
        else {
          $missing = theme('meedan_oembed_missing', array('media' => $matches[0][$key]));
          $text = str_replace($matches[0][$key], $missing, $text);
        }
      }
    }
  }
  return $text;
}

/**
 * Filter tips callback for meedan oembed filter.
 *
 */
function _meedan_oembed_filter_tips($filter, $format, $long = FALSE) {
  return t('<em>[media-title:$nid]</em> is replaced with the Meedan oEmbed node view for <em>$nid</em>.');
}
