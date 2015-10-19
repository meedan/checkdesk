/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
'use strict';

Drupal.behaviors.meedanFacebook = {

  comments: {},

  updateCommentsCount: function(path) {
    var value = Drupal.behaviors.meedanFacebook.comments[path] || 0;
    $('.fb-comments-count[data-href="' + path + '"]').html(value).parents('.story-commentcount.cd-item-count').toggle(value > 0);
  },

  attach: function(context, settings) {
    window.fbAsyncInit = function() {
      // Init the FB JS SDK
      FB.init({
        appId      : Drupal.settings.meedanFacebook.appId, // App ID from the App Dashboard
        xfbml      : true,  // parse XFBML tags on this page?
        version    : 'v2.3'
      });

      // Comments count.
      FB.Event.subscribe('xfbml.render', function(response) {
        $('.fb-comments-count').each(function() {
          var href = $(this).attr('data-href');
          Drupal.behaviors.meedanFacebook.comments[href] = parseInt($(this).text());
          $(this).parents('.story-commentcount.cd-item-count').toggle(Drupal.behaviors.meedanFacebook.comments[href] > 0);
        });
      });

      // Refresh comments count when comment is added or removed.
      FB.Event.subscribe('comment.create', function(response) {
        Drupal.behaviors.meedanFacebook.comments[response.href]++;
        Drupal.behaviors.meedanFacebook.updateCommentsCount(response.href);
      });
      FB.Event.subscribe('comment.remove', function(response) {
        Drupal.behaviors.meedanFacebook.comments[response.href]--;
        Drupal.behaviors.meedanFacebook.updateCommentsCount(response.href);
      });
    };

    (function(d, s, id, l) {
      var js, fjs = d.getElementsByTagName(s)[0];
      if (d.getElementById(id)) {return;}
      js = d.createElement(s); js.id = id;
      js.src = "//connect.facebook.net/" + l + "/sdk.js";
      fjs.parentNode.insertBefore(js, fjs);
    }(document, 'script', 'facebook-jssdk', Drupal.settings.meedanFacebook.language));
  }
};

}(jQuery));
