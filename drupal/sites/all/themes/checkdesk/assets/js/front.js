/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
	'use strict';

	// frontpage swap header logos
  Drupal.behaviors.frontpage = {
    attach: function(context) {
      $(window).bind('scroll', function(){
        var widgets = $('#widgets'), // element containing the partner logo
          headerHeight = $('header ul#user-menu').height(), // height of fixed header
          buffer = 220, // some margins to count for other elements such as slogan and social icons
          widgetsLimit = (widgets.offset().top + widgets.height()) - (headerHeight + buffer),
          headerLimit = headerHeight + buffer,
          st = $(window).scrollTop();
        // fade out the large logo in widgets
        if(st <= 200) {
          $('#widgets').css({ 'opacity' : (1 - st/200), 'visibility': 'inherit' });
        }
        // fade in small logo in header
        if (st <= 300) {
          $('header .header_logo').css({ 'opacity' : (0 + st/300), 'visibility': 'inherit' });
        }
        // if scroll is past widgets set opacity to 1
        if (st > widgetsLimit) {
          $('header .header_logo').css({ 'opacity' : 1, 'visibility': 'inherit' }); 
        }
      });
    }
  };

}(jQuery));
