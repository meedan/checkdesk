// Stuff here affects only internal bookmarklet

jQuery(function($) {

  // Tell parent window that link was not provided
  window.parent.postMessage('nolink', '*');

});
