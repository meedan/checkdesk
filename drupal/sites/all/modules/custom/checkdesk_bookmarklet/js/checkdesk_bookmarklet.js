/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function() {
  'use strict';

  /**
   * Communication between inner window and outer window happens using messages.
   *
   * Example messages include:
   *   - window.parent.postMessage('close', '*');
   *   - window.parent.postMessage('reset', '*');
   */
  var messageCallback = function(e) {
    var offset,
        data = e.data.split(';'),
        type = data.shift();

    switch (type) {
      // Close iframe
      case 'close':
        jQuery('#meedan_bookmarklet_cont, #meedan_bookmarklet_mask').fadeOut(500);
        jQuery('#menu-submit-report').removeClass('open');
        break;

      // Scale iframe after report was submitted or before link is provided
      case 'submit':
      case 'nolink':
        jQuery('#meedan_bookmarklet_cont').addClass('meedan-bookmarklet-collapsed');
        break;

      // Send another report
      case 'reset':
        jQuery('#meedan_bookmarklet_cont').removeClass('meedan-bookmarklet-collapsed');
        break;

      // Height changed
      case 'setHeight':
        if (data[0]) {
          jQuery('#meedan_bookmarklet_cont iframe').css('height', data[0]);
          jQuery('#meedan_bookmarklet_cont').css('height', parseInt(data[0], 10) + 7); // a little extra stuff to consider scrollbar
        }
        break;

      // Bookmarklet loaded
      case 'loaded':
        // Adjust bookmarklet modal position for internal bookmarklet
        if (jQuery('#meedan_bookmarklet_cont').length > 0) {
          if (jQuery('#menu-submit-report').length > 0) {
            var scrollPosition = jQuery('html').scrollTop() || jQuery('body').scrollTop();
            var topPosition = jQuery('#menu-submit-report').offset().top - scrollPosition;
            jQuery('#meedan_bookmarklet_cont').css('top', topPosition + 'px');
          }
          var modalPosition = jQuery('#meedan_bookmarklet_cont').offset().top + 26;

          // Watch if window height changes
          jQuery(window).resize(function() {
            jQuery("#meedan_bookmarklet_cont").css('max-height', jQuery(window).height() - modalPosition);
          });
          jQuery(window).resize();
        }

        jQuery('#meedan_bookmarklet_cont, #meedan_bookmarklet_mask').show();
        break;

      // Destroy bookmarklet
      case 'destroy':
        jQuery('#meedan_bookmarklet_cont, #meedan_bookmarklet_mask').remove();
        jQuery('#menu-submit-report').removeClass('open');
        break;
    }
  };

  if (!window.addEventListener) {
    window.attachEvent('onmessage', messageCallback);
  }
  else {
    window.addEventListener('message', messageCallback, false);
  }

}());
