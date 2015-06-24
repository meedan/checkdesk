jQuery(function() {

    Drupal.behaviors.checkdesk_sign_in_up = {
        attach: function (context, settings) {
            jQuery('a.twitter-action-signin, a.facebook-action-connect').click(function() {
                var throbber = Drupal.settings["modal-popup-medium"].throbber;
                jQuery('#modal-content div.modal-dialog-actions').html(throbber);
                return true;
            });
        }
    }

});