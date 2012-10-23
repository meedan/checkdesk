(function ($) {

/**
 * Module initialization.
 */
Drupal.behaviors.meedanSensitiveContent = {
  attach: function(context) {
    // FIXME This section is not working. Events are not caught. 
    //       One of the problems is that the sensitive wrapper is added by the backend
    //       only if the content is already marked as sensitive.
    // Listen to Flag update events to show/hide the content.
    $('.flag-'+Drupal.settings.meedanSensitiveContent.flag+' a.flag-link-toggle', context)
    .bind('flagGlobalAfterLinkUpdate', function() {
      var $wrapper = $(this).parents('.flag-wrapper');
      var flagged = $(this).hasClass('flagged');
      $.each($wrapper.attr('class').split(/\s+/), function(n,i) {
        // http://james.padolsey.com/javascript/match-trick/
        var nid = ( i.match(new RegExp('flag-'+Drupal.settings.meedanSensitiveContent.flag+'-(\\d+)')) || [,0] )[1];
        if (nid > 0) { // found a match
          meedanSensitiveContent.Update(nid, !flagged);
        }
      });
    });
  }
}

meedanSensitiveContent = {
  /**
   * Show sensitive item. 
   */
  Update: function(nid, show) {
    $('div.sensitive-notification-'+nid)[show ? 'hide' : 'show']();
    $('div.sensitive-item-'+nid)[show ? 'show' : 'hide']();
  }
}

})(jQuery);
