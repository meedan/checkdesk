/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

/**
 * Child component for Meedan seamless IFRAME support.
 */
jQuery(function ($) {
  'use strict';

  // Watch the height of the iframe, inform the parent every time it changes
  var htmlHeight = 0;

  function checkHTMLHeight() {
    var height = $('html')[0].offsetHeight;
    if (height != htmlHeight) {
      htmlHeight = height;

      window.parent.postMessage(['setHeight', htmlHeight].join(';'), '*');
    }

    setTimeout(checkHTMLHeight, 30);
  }

  // Start the checker
  checkHTMLHeight();

  window.parent.postMessage('loaded', '*');
});
