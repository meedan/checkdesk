/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
jQuery(function () {
  'use strict';

  var tp = Drupal.settings.basePathCheckdeskTheme;
  jQuery('body')
    // $, jQuery is replaced with the 1.8.2 version. Old is moved to _$, _jQuery
    .append('<script src="' + tp + '/assets/js/libs/jquery-1.8.2.min.js"><\/script>')
    // Twitter bootstrap now makes use of jQuery and $ which are the 1.8.2 version.
    .append('<script src="' + tp + '/assets/js/libs/bootstrap-alert.js"><\/script>')
    .append('<script src="' + tp + '/assets/js/libs/bootstrap-tab.js"><\/script>')
    .append('<script src="' + tp + '/assets/js/libs/bootstrap-dropdown.js"><\/script>')
    .append('<script src="' + tp + '/assets/js/libs/bootstrap-modal.js"><\/script>')
    // Create a jQuery_182 variable which can be used later in the execution
    // load tour script.
    .append('<script src="' + tp + '/assets/js/libs/bootstrap-tooltip.js"><\/script>')
    .append('<script src="' + tp + '/assets/js/libs/bootstrap-popover.js"><\/script>')
    .append('<script src="' + tp + '/assets/js/libs/bootstrap-tour.min.js"><\/script>')

    .append('<script>var jQuery_182 = jQuery.noConflict(true);</script>');
    // Now $ and jQuery refer to jQuery-1.4.4 again, @see $.noConflict()

});
