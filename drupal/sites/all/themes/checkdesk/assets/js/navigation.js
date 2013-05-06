/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';

  // Handles active state of the nav, so many elements in the nav are not full
  // page reloads and will not get correct active state.
  Drupal.behaviors.checkdeskNavigationActive = {
    attach: function (context) {
      $('#navbar ul.nav > li > a', context).click(function () {
        // Remove active state from everything else
        $('#navbar ul.nav > li').add('a').removeClass('active');

        // Add active state to this link
        $(this).parents('li:first').addClass('active');
        $(this).addClass('active');
      });
    }
  };

  Drupal.behaviors.reportIframeResize = {
    desiredHeight: 0,

    setOptimalHeight: function($wrapper) {
      if (!$wrapper || $wrapper.length <= 0) {
        return;
      }

      var allowableHeight = $(window).height() - $wrapper.offset().top + $(window).scrollTop() - 26,
          desiredHeight   = Drupal.behaviors.reportIframeResize.desiredHeight;

      if (desiredHeight && allowableHeight < desiredHeight) {
        $wrapper.css({ height: allowableHeight, overflowY: 'scroll' });
      } else {
        $wrapper.css({ height: 'auto', overflowY: 'hidden' });
      }
    },

    // NOTE: The context argument is ignored here because there should be only
    //       navbar rendered on the page!
    attach: function (context) {
      var $wrapper = $('#nav-media-form');

      // Resize the window should shrink the iframe as necessary
      $(window).resize(function() {
        Drupal.behaviors.reportIframeResize.setOptimalHeight($wrapper);
      });

      // The iframe should never grow beyond the window height. It might need
      // scrollbars added too.
      $('iframe', $wrapper).bind('postSetHeight', function (e) {
        Drupal.behaviors.reportIframeResize.desiredHeight = parseInt(e.originalEvent.data[0], 10);

        Drupal.behaviors.reportIframeResize.setOptimalHeight($wrapper);
      });
    }
  };


  /**
   * Listen in on the communication between the report IFRAME in the navigation
   * and this parent window.
   *
   * Close the report dropdown when requested.
   */
  function messageCallback(e) {
    var data = e.data.split(';'),
        type = data.shift();

    switch (type) {
      case 'close':
      case 'destroy':
        // Triggering a click on some other element will fire the event handlers
        // to close the dropdown.
        jQuery('body').click();
        break;
    }
  };

  if (!window.addEventListener) {
    window.attachEvent('onmessage', messageCallback);
  }
  else {
    window.addEventListener('message', messageCallback, false);
  }

}(jQuery));
