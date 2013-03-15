/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function ($) {
'use strict';

var meedanSensitiveContent = {
      /**
       * Show sensitive item. 
       */
      Update: function(nid, show) {
        $('div.sensitive-notification-'+nid)[show ? 'hide' : 'show']();
        $('div.sensitive-item-'+nid)[show ? 'show' : 'hide']();
      }
    };

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
      var $wrapper = $(this).parents('.flag-wrapper'),
          flagged = $(this).hasClass('flagged'),
          nid;
      $.each($wrapper.attr('class').split(/\s+/), function(n,i) {
        // http://james.padolsey.com/javascript/match-trick/
        nid = ( i.match(new RegExp('flag-'+Drupal.settings.meedanSensitiveContent.flag+'-(\\d+)')) || [undefined,0] )[1];
        if (nid > 0) { // found a match
          meedanSensitiveContent.Update(nid, !flagged);
        }
      });
    });
  }
};

}(jQuery));
