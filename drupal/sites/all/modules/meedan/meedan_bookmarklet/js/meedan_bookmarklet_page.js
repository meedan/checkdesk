/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

// This file is loaded on any page loaded inside the bookmarklet
jQuery(function($) {
  'use strict';
  
  // Watch the height of the iframe, inform the parent every time it changes
  var htmlHeight = 0;

  function checkHTMLHeight() {
    if ($('html').height() != htmlHeight) {
      htmlHeight = $('html').height();

      window.parent.postMessage('{"type":"resize","height":' + htmlHeight + '}', '*');
    }

    setTimeout(checkHTMLHeight, 250);
  }

  // Start the checker
  checkHTMLHeight();

  window.parent.postMessage('loaded', '*');
});
