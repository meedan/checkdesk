<?php

/**
 * Returns the hook_meedan_oembed() handler information for a given domain.
 */
function meedan_oembed_get_handler_for_domain($domain) {
  $handlers = module_invoke_all('meedan_oembed');

  if (array_key_exists($domain, $handlers)) {
    return $handlers[$domain];
  }

  return FALSE;
}

/**
 * Get domain name from url.
 * Get site name.
 * Choose largest token of the host.
 */
function _meedan_oembed_get_domain_name($url) {
  //set domain for google maps including short link
  if (stripos($url, 'maps.google') || stripos($url, 'goo.gl/maps')) {
    return 'googlemaps';
  }
  $parts = explode('.', parse_url($url, PHP_URL_HOST));
  $domain = '';
  foreach ($parts as $part) {
    if (strlen($part) > strlen($domain)) {
      $domain = $part;
    }
  }
  return strtolower($domain);
}

/**
 * Any string beginning with at least one Arabic character is deemed
 * to be Arabic.
 */
function meedan_oembed_needs_rtl($text) {
  return (boolean) preg_match('/^\p{Arabic}/u', $text);
}
