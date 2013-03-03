jQuery(function ($) {
  "use strict";

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
    if (matchExpr) {
      $all = $all.filter(matchExpr);
    }

    return $all;
  };

  /**
   * Move the messages-inline div right after the form label.
   */
  Drupal.behaviors.checkdeskInlineErrors = {

    attach: function (context) {
  //     var $firstError;

  //     $('.messages-inline:not(.cd-inline-errors-processed)', context)
  //       .addClass('cd-inline-errors-processed')
  //       .each(function () {
  //         var $msg  = $(this),
  //             // Risky, relying on the .messages-inline DIV always coming
  //             // immediately after the form element. This seems to be the case.
  //             $label = $msg.prevALL('label:first');

  //         if (!$firstError) {
  //           $firstError = $msg;
  //         }

  //         $label.after($msg);
  //       });

  //     // Scroll the browser to the fist displayed error
  //     if ($firstError) {
  //       setTimeout(function () {
  //         $('html, body').animate({
  //           scrollTop: $firstError.offset().top - $firstError.outerHeight()
  //         }, 'slow');
  //       }, 2000);
  //     }
      // ife user register form 
      // setting placeholder text for password fields
      // as it wasn't possible to do with hook_form_alter
      $('.ife #edit-pass-pass1').attr('placeholder', 'Password');
      $('.ife #edit-pass-pass2').attr('placeholder', 'Confirm Password');
    }

  };

}(jQuery));