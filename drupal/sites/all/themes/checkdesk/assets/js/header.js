/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';

  // Hide header on scroll
  Drupal.behaviors.header = {
    attach: function(context) {

      var didScroll,
          lastScrollTop = 0,
          delta = 20,
          buffer = 220,
          headerHeight = $('header ul#user-menu').outerHeight();

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
        
        // add helper classes to body
        if (st < lastScrollTop) {
          $('body').removeClass('scroll-down').addClass('scroll-up');
        } else {
          $('body').addClass('scrolling');
          $('body').removeClass('scroll-up').addClass('scroll-down');
        }


        // If current position > last position AND scrolled past navbar...
        if (st > lastScrollTop && st > (headerHeight + (buffer))){
          // Scroll Down
          $('header .metabar').removeClass('header-down').addClass('header-up');
          $('header').removeClass('show-content-shadow');
          // move incoming reports to top
          if ($('#sidebar-first').length) {
            $('#sidebar-first').css('top', '0px');
          }
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
              // move incoming reports back
              if ($('#sidebar-first').length) {
                $('#sidebar-first').css('top', '');
              }
            }
          }

          // If at top of the page hide shadow
          if(st == 0) {
            $('header').removeClass('show-content-shadow');
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
