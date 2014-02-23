/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function($) {
  'use strict';

  var timeout = null;

  window.waitForTwitteriFrames = function() {
    if ($('.oembed.twitter').length === $('.oembed.twitter iframe').contents().find('.standalone-tweet').length) {
      clearTimeout(timeout);
      localizeTwitterEmbeds();
    }
    else {
      timeout = setTimeout('waitForTwitteriFrames()', 1000);
    }
  };

  var localizeTwitterEmbeds = function() {
    $('.oembed.twitter:not(.twitter-embed-localized)').each(function() {
      var direction = $(this).find('span[dir]:first').attr('dir'),
          tweet = $(this).find('iframe').contents().find('.standalone-tweet');
      tweet.attr('dir', direction);
      tweet.removeClass('ltr rtl').addClass(direction);
      $(this).addClass('twitter-embed-localized');
    });
  };
  
  Drupal.behaviors.localizeTwitterEmbeds = {

    attach : function (context, settings) {
      timeout = setTimeout('waitForTwitteriFrames()', 1000);
    }

  };

}(jQuery));
