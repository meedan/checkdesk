jQuery(function ($) {

/**
 * Move the messages-inline div right after the form label.
 */
Drupal.behaviors.checkdeskInlineErrors = {
  attach: function (context) {
    $('.messages-inline:not(.cd-inline-errors-processed)', context)
      .addClass('cd-inline-errors-processed')
      .each(function () {
        var $msg  = $(this),
            // Risky, relying on the .messages-inline DIV always coming
            // immediately after the form element. This seems to be the case.
            $item = $msg.prev();

        $('label', $item).append($msg);
      });
  }
};

}(jQuery));