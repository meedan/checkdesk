/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
jQuery(function () {
  'use strict';

  var tp = Drupal.settings.basePathDemoTourPath;
  jQuery('body')
    // $, jQuery is replaced with the 1.8.2 version. Old is moved to _$, _jQuery
    .append('<script src="' + tp + '/js/jquery-1.8.2.min.js"><\/script>')
    // Twitter bootstrap now makes use of jQuery and $ which are the 1.8.2 version.
    .append('<script src="' + tp + '/js/bootstrap-tooltip.js"><\/script>')
    .append('<script src="' + tp + '/js/bootstrap-popover.js"><\/script>')
    .append('<script src="' + tp + '/js/bootstrap-tour.min.js"><\/script>')
    // Create a jQuery_182 variable which can be used later in the execution
    .append('<script>var jQuery182 = jQuery.noConflict(true);</script>');
    // Now $ and jQuery refer to jQuery-1.4.4 again, @see $.noConflict()

});
