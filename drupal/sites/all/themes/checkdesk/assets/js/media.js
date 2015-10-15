/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
	'use strict';

  // Add classes to buttons in media browser forms
  Drupal.behaviors.mediaBrowser = {
    attach: function(context) {
      $('.page-media').find('.fake-ok, .button-yes').addClass('btn btn-primary');
    }
  };

}(jQuery));
