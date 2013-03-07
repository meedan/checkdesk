(function() {

  // Communication between inner window and outer window happens using messages
  var messageCallback = function(e) {
    switch(e.data) {

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

      // Bookmarklet loaded
      case 'loaded':
        // Adjust bookmarklet modal position for internal bookmarklet
        if (jQuery('#menu-submit-report').length > 0) {
          var offset = jQuery('#menu-submit-report').offset();
          jQuery('#meedan_bookmarklet_cont').css('top', (parseInt(offset.top) + 26) + 'px');
        }
        jQuery('#meedan_bookmarklet_cont').show();
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

})();
