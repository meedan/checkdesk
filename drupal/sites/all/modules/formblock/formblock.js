(function ($) {

Drupal.behaviors.formBlockSummaries = {
  attach: function (context) {
    // Provide the summary for the node type form.
    $('fieldset.formblock-node-type-settings-form', context).drupalSetSummary(function(context) {
      var vals = [];
      $('input:checked', context).next('label').each(function() {
        vals.push(Drupal.checkPlain($(this).text()));
      });
      return vals.join(', ');
    });
  }
};

})(jQuery);
