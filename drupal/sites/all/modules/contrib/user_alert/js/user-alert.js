(function ($) {
  Drupal.behaviors.user_alert_get_message = {
    attach: function(context) {
      $('body').delegate('div.user-alert-close a', 'click', function() {
        id = $(this).attr('rel');
        $.ajax({
          type: 'GET',
          data: 'message=' + id,
          url: Drupal.settings.basePath + Drupal.settings.user_alert.url_prefix + 'js/user-alert/close-message',
          success: function(response) {
            $('#user-alert-' + id).fadeOut('slow');
          }
        });
      });
  	}
  };
}(jQuery));
