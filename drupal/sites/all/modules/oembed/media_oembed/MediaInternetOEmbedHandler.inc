<?php

class MediaInternetOEmbedHandler extends MediaInternetBaseHandler {

  /**
   * Claim this URL.
   */
  public function claim($embedCode) {
    $matches = array();
    if (oembedcore_get_provider($embedCode, $matches)) {
      return TRUE;
    }
  }

  /**
   * Returns a file object which can be used for validation
   *
   * @return StdClass
   */
  public function getFileObject() {
    $uri = 'oembed://'. drupal_encode_path($this->embedCode);
    return file_uri_to_object($uri, TRUE);
  }

  /**
   * Before the file has been saved, implementors may do additional operations.
   */
  public function preSave(&$file_obj) {
    $url = rawurldecode(substr($file_obj->uri, 9));
    $embed = oembedcore_oembed_data($url);
    if (!empty($embed->title)) {
      $file_obj->filename = truncate_utf8($embed->title, 255);
    }
    // If a user enters a duplicate embed code, the object will be saved again.
    // Set the timestamp to the current time, so that the media item shows up
    // at the top of the media library, where they would expect to see it.
    $file_obj->timestamp = REQUEST_TIME;
  }

  /**
   * Returns an array representation of the oEmbed data, or NULL on failure.
   *
   * An example project that calls this method is Media Browser Plus
   * (http://drupal.org/project/media_browser_plus). Other projects may do so
   * in the future.
   */
  public function getOEmbed() {
    $embed = oembedcore_oembed_data($this->embedCode);
    return $embed ? (array) $embed : NULL;
  }
}
