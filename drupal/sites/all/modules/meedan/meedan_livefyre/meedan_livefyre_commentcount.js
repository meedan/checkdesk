/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
'use strict';

Drupal.behaviors.livefyreCommentCount = {
  attach: function(context, settings) {
    LF.CommentCount({
      replacer: function(element, count) {
        element.innerHTML = Drupal.formatPlural(count, '1 comment', '@count comments');
      }
    });
  }
};

}(jQuery));
