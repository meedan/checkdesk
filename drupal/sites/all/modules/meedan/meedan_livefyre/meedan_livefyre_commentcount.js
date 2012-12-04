(function ($) {
// START jQuery

Drupal.behaviors.livefyre = {
  attach: function(context, settings) {
    LF.CommentCount({
      replacer: function(element, count) {
        element.innerHTML = Drupal.t([ '@count comment', '@count comments' ], { '@count': count });
      }
    });
  }
}

// END jQuery
})(jQuery);

