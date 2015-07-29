/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';

  Drupal.behaviors.checkdesk_sign_in_up = {
    attach: function (context, settings) {
      $('a.twitter-action-signin, a.facebook-action-connect').click(function() {
        var throbber = Drupal.settings["modal-popup-medium"].throbber;
        $('#modal-content div.modal-dialog-actions').html(throbber);
        return true;
      });
    }
  }

}(jQuery));
