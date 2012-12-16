(function ($) {

  Drupal.behaviors.checkdesk_extended = {
    attach: function (context, settings) {

      console.log(Drupal.settings);
      // $('.flag-'+Drupal.settings.checkdesk.flagSettings.flag.name).attr('href', Drupal.settings.checkdesk.flagSettings.url);
      // $('.flag-'+Drupal.settings.checkdesk.flagSettings.flag.name).removeClass(Drupal.settings.checkdesk.flagSettings.action+'-action');
      // $('.flag-'+Drupal.settings.checkdesk.flagSettings.flag.name).addClass(Drupal.settings.checkdesk.flagSettings.newAction+'-action');
      $('.flag-'+Drupal.settings.checkdesk.flagSettings.flag.name).parent().addClass('flag-'+Drupal.settings.checkdesk.flagSettings.flag.name);
      $('a.flag-'+Drupal.settings.checkdesk.flagSettings.flag.name).replaceWith(Drupal.settings.checkdesk.flagSettings.newHTML);
  
    }
  };


 

})(jQuery);
