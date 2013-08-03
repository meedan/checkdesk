/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

/**
 * Child component for Meedan seamless IFRAME support.
 */
jQuery(function ($) {
  'use strict';

  // Watch the height of the iframe, inform the parent every time it changes
  var htmlHeight = 0,
      id = window.location.hash;

  function checkHTMLHeight() {
    var ds = Drupal && Drupal.settings ? Drupal.settings : false,
        height;

    if (ds && ds.meedanIframes) {
      height = $(ds.meedanIframes.contentSelector).outerHeight(true);
    } else {
      height = $('body')[0].offsetHeight;
    }

    if (height !== htmlHeight) {
      htmlHeight = height;

      window.parent.postMessage([id, 'setHeight', htmlHeight].join(';'), '*');
    }

    setTimeout(checkHTMLHeight, 30);
  }

  // Start the checker
  checkHTMLHeight();

  window.parent.postMessage([id, 'loaded'].join(';'), '*');
});
