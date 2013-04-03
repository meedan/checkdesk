/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function() {
  'use strict';

  /**
   * Communication between inner window and outer window happens using messages.
   *
   * Example messages include:
   *   - window.parent.postMessage('close', '*');
   *   - window.parent.postMessage('reset', '*');
   *   - window.parent.postMessage({ type: 'resize', width: 123, height: 456 }, '*');
   */
  var messageCallback = function(e) {
    var offset,
        newSize,
        data = (e.data.substr(0, 1) === '{') ? jQuery.parseJSON(e.data) : e.data,
        type = (data && data.type) ? data.type : data;

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

      // Resize the container to match the iframe size
      case 'resize':
        newSize = {};
        if (data.width) {
          newSize.width = data.width;
        }
        if (data.height) {
          newSize.height = data.height;
        }
        jQuery('#meedan_bookmarklet_cont iframe').css(newSize);
        newSize.height += 7; // A little extra to avoid a scrollbar
        jQuery('#meedan_bookmarklet_cont').css(newSize);
        break;

      // Bookmarklet loaded
      case 'loaded':
        // Adjust bookmarklet modal position for internal bookmarklet
        if (jQuery('#menu-submit-report').length > 0) {
          var scrollPosition = jQuery('html').scrollTop() || jQuery('body').scrollTop();
          var topPosition = jQuery('#menu-submit-report').offset().top - scrollPosition + 26;
          jQuery('#meedan_bookmarklet_cont').css('top', topPosition + 'px');

          // Watch if window height changes
          jQuery(window).resize(function() {
            jQuery("#meedan_bookmarklet_cont").css('max-height', jQuery(window).height() - topPosition);
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
