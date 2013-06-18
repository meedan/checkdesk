/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
'use strict';

Drupal.livefyreCommentCount = {
  loaded: false,

   callback: function(context, settings) {
     LF.CommentCount({
       replacer: function(element, count) {
         element.innerHTML = Drupal.formatPlural(count, '1 comment', '@count comments');
       }
     });
   }
};

Drupal.behaviors.livefyreCommentCount = {
  attach: function(context, settings) {
    if (!Drupal.livefyreCommentCount.loaded) {
      $.getScript(Drupal.settings.livefyreScript.commentCount, function() {
        Drupal.livefyreCommentCount.loaded = true;
        Drupal.livefyreCommentCount.callback(context, settings);
      });
    }
    else {
      Drupal.livefyreCommentCount.callback(context, settings);
    }
  }
};

}(jQuery));
