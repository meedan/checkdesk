(function($) {
  Drupal.behaviors.chosen = {
    attach: function(context) {
      $(Drupal.settings.chosen.selector, context).each(function() {
        if ($(this).find('option').size() >= Drupal.settings.chosen.minimum) {
          $(this).chosen();
        }
      }); 
    }
  }
})(jQuery);