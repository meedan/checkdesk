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
        
        // If current position > last position AND scrolled past navbar...
        if (st > lastScrollTop && st > (headerHeight + (buffer*2))){
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

          // If at top of the page hide shadow
          if(st == 0) {
            $('header').removeClass('show-content-shadow');
          }
        }
        
        lastScrollTop = st;
      }

    }
  };

}(jQuery));
