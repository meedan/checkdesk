(function() {

  // Tell parent window that report was submitted
  window.parent.postMessage('submit', '*');
 
})();
