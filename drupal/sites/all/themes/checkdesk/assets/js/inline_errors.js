jQuery(function ($) {

// See: http://www.texotela.co.uk/code/jquery/reverse/
$.fn.reverse = function() {
  return this.pushStack(this.get().reverse(), arguments);
};

// Searches all previous elements in the DOM until a match is found
$.fn.prevALL = function(matchExpr) {
  // get all the elements in the body, including the body.
  var $all = $('body').find('*').andSelf();

  // slice the $all object according to which way we're looking
  $all = $all.slice(0, $all.index(this)).reverse();

  // filter the matches if specified
  if (matchExpr) $all = $all.filter(matchExpr);

  return $all;
};

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
            $label = $msg.prevALL('label:first');

        $label.after($msg);
      });
  }

};

}(jQuery));