(function ($) {

Drupal.behaviors.meedan_sensitive_contentFieldsetSummaries = {
  attach: function (context) {
    $('fieldset#edit-meedan-sensitive-content', context).drupalSetSummary(function (context) {
      // Retrieve the value of the selected radio button
      var sensitive = jQuery('#edit-meedan-sensitive').is(':checked');
      if (sensitive) {
        return Drupal.t('Enabled');
      }
      else {
        return Drupal.t('Disabled');
      }
    });
  }
};

})(jQuery);
