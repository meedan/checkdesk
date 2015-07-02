/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
	'use strict';

	// frontpage swap header logos and hide header on page scroll
  Drupal.behaviors.responsiveNav = {
    attach: function(context) {
      var nav = responsiveNav(".nav-collapse", { // Selector
        animate: false, // Boolean: Use CSS3 transitions, true or false
        transition: 284, // Integer: Speed of the transition, in milliseconds
        customToggle: ".nav-toggle", // Selector: Specify the ID of a custom toggle
        closeOnNavClick: false, // Boolean: Close the navigation when one of the links are clicked
        openPos: "fixed", // String: Position of the opened nav, relative or static
        navClass: "nav-collapse", // String: Default CSS class. If changed, you need to edit the CSS too!
        navActiveClass: "js-nav-active", // String: Class that is added to  element when nav is active
        jsClass: "js", // String: 'JS enabled' class which is added to  element
        open: function(){
          // Make metabar position relative so it pushes down
          // when the navigation expands
          $('.metabar').css('position', 'relative');
          $('#main').css('top', '0px');
        },
        close: function(){
          // move metabar back to top
          $('.metabar').css('top', '');
        },
      });

      // Run code on entry and exit from media queries
      // see: https://github.com/sparkbox/mediaCheck
      // see: _variables for standar breakpoint variables if needed
      
      mediaCheck({
        media: '(max-width: 500px)',
        entry: function() {
          // On mobile: Make sign in / sign up button small and trim copy
          $('.btn-sign-in-up').text('Sign in').addClass('btn-sm');
          $('.header_logo img').css('max-width', '176px');
          // make avatar small
          $('#my-account-link .avatar-menu').removeClass('thumb-40').addClass('thumb-38');
        },
        exit: function() {
          // Restore sign in / sign up button size and copy
          $('.btn-sign-in-up').text('Sign in / Sign Up').removeClass('btn-sm');
          $('.header_logo img').css('max-width', '100%');
          // make avatar big again
          $('#my-account-link .avatar-menu').removeClass('thumb-38').addClass('thumb-40');
        }
      });

    }
  };

}(jQuery));
