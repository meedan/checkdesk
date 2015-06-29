/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
	'use strict';

	// frontpage swap header logos
  Drupal.behaviors.frontpage = {
    attach: function(context) {
      // $(window).bind('scroll', function(){
        // var widgets = $('#widgets'), // element containing the partner logo
        //   headerHeight = $('header ul#user-menu').height(), // height of fixed header
        //   buffer = 220, // some margins to count for other elements such as slogan and social icons
        //   widgetsLimit = (widgets.offset().top + widgets.height()) - (headerHeight + buffer),
        //   headerLimit = headerHeight + buffer,
        //   st = $(window).scrollTop();

        // // fade out the large logo in widgets
        // if(st <= widgetsLimit) {
        //   $('#widgets').css({ 'opacity' : (1 - st/headerLimit), 'visibility': 'inherit' });
        //   $('header').removeClass('show-content-shadow');
        // }
        // // fade in small logo in header
        // if (st <= headerLimit) {
        //   $('header .header_logo').css({ 'opacity' : (0 + st/headerLimit), 'visibility': 'inherit' });
        // }
        // // if scroll is past widgets set opacity to 1
        // if (st > widgetsLimit) {
        //   $('header .header_logo').css({ 'opacity' : 1, 'visibility': 'inherit' }); 
        //   $('header').addClass('show-content-shadow');
        // }
        // // if at top hide the small logo
        // if (st == 0) {
        //   $('header .header_logo').css({ 'opacity' : 0, 'visibility': 'hidden' }); 
        //   $('header').removeClass('show-content-shadow');
        // }
      // });

      var didScroll,
          lastScrollTop = 0,
          delta = 20, 
          buffer = 220,
          widgets = $('#widgets'),
          headerHeight = $('header ul#user-menu').outerHeight(),
          widgetsHeight = $('#widgets').outerHeight(),
          headerLimit = headerHeight + buffer,
          widgetsLimit =  (widgets.offset().top + widgets.height()) - (headerHeight + buffer);

      // on scroll, let the interval function know the user has scrolled
      $(window).scroll(function(event){
        didScroll = true;
      });

      // run hasScrolled() and reset didScroll status
      setInterval(function() {
        if (didScroll) {
          hasScrolled();
          didScroll = false;
        }
      }, 250);

      function hasScrolled() {
        var st = $(window).scrollTop();

        // Make sure they scroll more than delta
        if(Math.abs(lastScrollTop - st) <= delta) 
          return;

        if(st <= widgetsLimit) {
          $('#widgets').css({ 'opacity' : (1 - st/widgetsLimit), 'visibility': 'inherit' });
          $('header').removeClass('show-content-shadow');
        }

        // fade in small logo in header
        if (st <= headerLimit) {
          $('header .header_logo').css({ 'opacity' : (0 + st/headerLimit), 'visibility': 'inherit' });
        }

        // if scroll is past widgets set opacity to 1
        if (st > widgetsLimit) {
          $('header .header_logo').css({ 'opacity' : 1, 'visibility': 'inherit' }); 
          $('header').addClass('show-content-shadow');
        }
        
        // If current position > last position AND scrolled past widget + some buffer space...
        if (st > lastScrollTop && st > (widgetsHeight + (buffer*2))){
          
          // Scroll Down
          $('header .metabar').removeClass('header-down').addClass('header-up');
          $('header').removeClass('show-content-shadow');
          // Also hide drupal toolbar
          setTimeout(function() {
            $('#toolbar').removeClass('header-down').addClass('header-up');
          }, 200);

        } else {
          
          // Scroll Up
          // If did not scroll past the document (possible on mac)...
          if(st + $(window).height() < $(document).height()) {
            $('#toolbar').removeClass('header-up').addClass('header-down');
            $('header .metabar').removeClass('header-up').addClass('header-down');
            $('header').addClass('show-content-shadow');
          }

          // If at top hide the small logo
          if(st == 0) {
            $('header .header_logo').css({ 'opacity' : 0, 'visibility': 'hidden' }); 
            $('header').removeClass('show-content-shadow');
          }

        }
        
        lastScrollTop = st;
      }

    }
  };

}(jQuery));
