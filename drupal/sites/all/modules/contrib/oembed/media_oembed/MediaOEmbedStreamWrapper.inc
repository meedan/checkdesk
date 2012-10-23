<?php

/**
 *  @file
 *  Create a oEmbed Stream Wrapper class for the Media/Resource module.
 */

/**
 *  Create an instance like this:
 *  $oembed = new MediaoEmbedStreamWrapper('oembed://[video-code]');
 */
class MediaOEmbedStreamWrapper extends MediaReadOnlyStreamWrapper {

  function interpolateUrl() {
    return $this->get_parameters();
  }

  /**
   * Fetches oEmbed data for the URL.
   *
   *  @param $url
   *    The URI to parse, such as youtube://v/[video-code]/t/[tags+more-tags].
   *  @return
   *    An associative array of all the parameters in the path,
   *    or FALSE if the $url is ill-formed.
   */
  protected function _parse_url($uri) {
    return rawurldecode(substr($uri, 9));
  }

  function getTarget($f) {
    return FALSE;
  }

  static function getMimeType($uri, $mapping = NULL) {
    $url = rawurldecode(substr($uri, 9));
    $embed = oembedcore_oembed_data($url);
    if ($embed) {
      switch ($embed->type) {
        case 'video':
          return 'video/oembed';
        case 'photo':
          return 'image/oembed';
        default:
          return 'text/oembed';
      }
    }
    return FALSE;
  }
}
