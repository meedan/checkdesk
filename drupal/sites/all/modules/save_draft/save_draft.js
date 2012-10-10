(function ($) {

/**
 * Remove publication status from the "Content promotion options" vertical tab.
 */
Drupal.behaviors.saveDraftFieldsetSummaries = {
  attach: function (context) {
    $('fieldset.node-promotion-options', context).drupalSetSummary(function (context) {
      var vals = [];

      $('input:checked', context).parent().each(function () {
        vals.push(Drupal.checkPlain($.trim($(this).text())));
      });
      if (vals.length) {
        return vals.join(', ');
      }
      else {
        return Drupal.t('Not promoted');
      }
    });
  }
};

})(jQuery);
