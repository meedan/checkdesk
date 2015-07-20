/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
	'use strict';

	// frontpage swap header logos and hide header on page scroll
  Drupal.behaviors.frontpage = {
    attach: function(context) {
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
        if(Math.abs(lastScrollTop - st) <= delta && st >= delta) 
          return;


        // Don't swap logos if responsive nav is active
        if (!$('html').hasClass('js-nav-active')) {
          // fade the large logo in widgets
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

          // add helper classes to body
          if (st < lastScrollTop) {
            $('body').removeClass('scroll-down').addClass('scroll-up');
          } else {
            $('body').addClass('scrolling');
            $('body').removeClass('scroll-up').addClass('scroll-down');
          }

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
          // Don't scroll up the header if responsive nav is active
          if (!$('html').hasClass('js-nav-active')) {
            // Scroll Up
            // If did not scroll past the document (possible on mac)...
            if(st + $(window).height() < $(document).height()) {
              // reset metabar position             
              $('.metabar').css('position', '');
              $('#toolbar').removeClass('header-up').addClass('header-down');
              $('header .metabar').removeClass('header-up').addClass('header-down');
              $('header').addClass('show-content-shadow');
            }
          }

          // If at top hide the small logo
          if(st == 0) {
            $('header .header_logo').css({ 'opacity' : 0, 'visibility': 'hidden' }); 
            $('header').removeClass('show-content-shadow');
            $('body').removeClass('scrolling');
            // Don't reset top for #main if responsive nav is active
            if (!$('html').hasClass('js-nav-active')) {
              $('#main').css('top', '');
            }
          }

        }
        
        lastScrollTop = st;
      }

    }
  };

}(jQuery));
