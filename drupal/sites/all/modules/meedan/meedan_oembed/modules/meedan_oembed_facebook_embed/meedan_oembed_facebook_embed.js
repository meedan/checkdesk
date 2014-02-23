/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function($) {
  'use strict';

  var timeout = null;

  window.waitForFacebookiFrames = function() {
    if ($('.fb-post').length === $('.fb-post iframe').length) {
      clearTimeout(timeout);
      localizeFacebookEmbeds();
    }
    else {
      timeout = setTimeout('waitForFacebookiFrames()', 1000);
    }
  };

  var localizeFacebookEmbeds = function() {
    $('.oembed.facebook:not(.fb-embed-localized)').each(function() {
      var newlocale = $(this).find('#fb-root').data('locale'),
          iframe = $(this).find('iframe');
      if (iframe.length > 0) {
        var currentlocale = iframe.attr('src').match(/locale=([^&]+)/)[1];
        if (currentlocale !== newlocale) {
          var src = iframe.attr('src').replace(/locale=([^&]+)/, 'locale=' + newlocale);
          iframe.attr('src', src);
        }
      }
      $(this).addClass('fb-embed-localized');
    });
  };
  
  Drupal.behaviors.localizeFacebookEmbeds = {

    attach : function (context, settings) {
      timeout = setTimeout('waitForFacebookiFrames()', 1000);
    }

  };

}(jQuery));
