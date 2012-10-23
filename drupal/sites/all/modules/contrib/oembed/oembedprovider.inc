<?php

/**
 * @file
 * Functions for the oEmbed provider
 */

/**
 * Callback handler for oembed requests.
 *
 * @param string $format
 *  Optional. The response format to use.
 *  Defaults to $_GET['format'] or 'json', in that order.
 */
function _oembedprovider_handle_request($format = '') {
  if (empty($format)) {
    $format = empty($_GET['format']) ? 'json' : $_GET['format'];
  }

  // Get the supported formats, and abort if a unsupported format it requested
  $formats = oembedprovider_formats();
  if (!isset($formats[$format])) {
    header('HTTP/1.0 501 Not implemented. Unsupported response format "' . check_plain($format) . '"');
    die;
  }
  $f = $formats[$format];
  header('Content-type: ' . $f['mime']);

  // Check that we got a url
  if (empty($_GET['url'])) {
    header('HTTP/1.0 406 Not acceptable. The url parameter is required.');
    print call_user_func($f['callback'], _oembedprovider_result('link', array(
      'title' => t('The url parameter is required'),
      'error' => 1,
    )));
    die;
  }

  $url = $_GET['url'];

  $matches = array();
  $provider = oembedcore_get_provider($url, $matches);

  if ($provider) {
    $forward = array('maxwidth', 'maxheight');
    $attributes = array();
    foreach ($forward as $key) {
      if (isset($_GET[$key])) {
        $attributes[$key] = $_GET[$key];
      }
    }

    $data = oembedcore_oembed_fetch($provider, $url, $matches, $attributes);
    if ($data) {
      print call_user_func($f['callback'], $data);
    }
    else {
      header('HTTP/1.0 404 Not found.');
      print call_user_func($f['callback'], _oembedprovider_result('link', array(
        'title' => t('Could not fetch an embed for this url'),
        'error' => 1,
      )));
    }
    die;
  }
  else {
    header('HTTP/1.0 404 Not found.');
    print call_user_func($f['callback'], _oembedprovider_result('rich', array(
      'title' => t('Could not find a provider that supports this url'),
      'error' => 1,
    )));
    die;
  }
}

/**
 * Merges a result with some standard values.
 *
 * @param string $type
 * @param array $result
 */
function _oembedprovider_result($type, $props) {
  return array_merge(array(
    'type' => $type,
    'version' => '1.0',
    'provider_name' => variable_get('site_name', ''),
    'width' => 0,
    'height' => 0,
  ), $props);
}


/**
 * The default provider to handle nodes
 *
 * @param string $url
 * @param array $matches
 */
function _oembedprovider_node_provider($provider, $url, $matches) {
  $block_endless_recursion = &drupal_static(__FUNCTION__, array());

  $result = FALSE;

  $nid = $matches[1];
  if (!isset($block_endless_recursion[$nid])) {
    $block_endless_recursion[$nid] = TRUE;

    $node = node_load($nid);
    if ($node && node_access('view', $node, drupal_anonymous_user())) {
      $author = user_load($node->uid);
      //TODO: The title and author data is currently returned as part of the rich-text html as well - this makes some clients show duplicate title and/or author information
      // TODO Please change this theme call to use an associative array for the $variables parameter.
      $result = _oembedprovider_result('rich', array(
        'html' => theme('oembed_node', array('node' => $node)),
        'title' => $node->title,
        'author_name' => $author->name,
        'author_url' => url('user/' . $author->uid, array('absolute' => TRUE)),
      ));
    }

    unset($block_endless_recursion[$nid]);
  }

  return $result;
}

/**
 * JSONP formatter
 */
function _oembedprovider_formats_jsonp($data) {
  $callback = !empty($_GET['callback']) ? $_GET['callback'] : 'jsonp';
  return sprintf('%s(%s)', $callback, _oembedprovider_formats_json($data));
}

/**
 * JSON formatter
 */
function _oembedprovider_formats_json($data) {
  return json_encode($data);
}

/**
 * XML formatter
 */
function _oembedprovider_formats_xml($data) {
  $doc = new DomDocument('1.0', 'utf-8');
  $oembed = $doc->createElement('oembed');
  $doc->appendChild($oembed);
  foreach ($data as $key => $value) {
    $e = $doc->createElement($key);
    $e->appendChild($doc->createTextNode($value));
    $oembed->appendChild($e);
  }
  return $doc->saveXml();
}
