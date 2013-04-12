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
      })
    }
  };

}(jQuery));
