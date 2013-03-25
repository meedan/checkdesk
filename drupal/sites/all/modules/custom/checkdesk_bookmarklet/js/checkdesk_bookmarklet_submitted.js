/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function() {
  'use strict';

  // Tell parent window that report was submitted
  window.parent.postMessage('submit', '*');

}());
