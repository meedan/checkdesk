(function ($) {
// START jQuery

Drupal.behaviors.livefyreCommentCount = {
  attach: function(context, settings) {
    LF.CommentCount({
      replacer: function(element, count) {
        element.innerHTML = Drupal.formatPlural(count, '1 comment', '@count comments');
      }
    });
  }
}

// END jQuery
})(jQuery);

