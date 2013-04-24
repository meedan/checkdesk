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

  /**
   * Listen in on the communication between the report IFRAME in the navigation
   * and this parent window.
   *
   * Close the report dropdown when requested.
   */
  var messageCallback = function(e) {
    var type = e.data;

    console.log(type, 'caught');

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
