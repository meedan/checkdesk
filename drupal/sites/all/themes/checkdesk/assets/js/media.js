/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
	'use strict';

  Drupal.behaviors.mediaBrowser = {
    attach: function(context) {
    	// Add class to html inside the modal iframe
    	$('.page-media').parent('html').addClass('media-browser');
    	// Add classes to buttons in media browser forms
      $('.page-media').find('.fake-ok').addClass('btn btn-primary');
      $('.page-media').find('.button-yes').addClass('btn btn-default');
      // On the media browser / photo library change submit button text to select
      $('.page-media-browser').find('.button-yes').text(Drupal.t('Select'));
      // Change Submit to Add image on format or embedding ... 
      $('.page-media-format-form').find('.fake-ok').text(Drupal.t('Add Image'));
    }
  };

}(jQuery));
