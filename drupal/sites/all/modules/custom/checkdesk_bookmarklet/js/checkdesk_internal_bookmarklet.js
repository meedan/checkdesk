/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
jQuery(function($) {
  'use strict';
  // Stuff here affects only internal bookmarklet

  // Tell parent window that link was not provided
  window.parent.postMessage('nolink', '*');

});
