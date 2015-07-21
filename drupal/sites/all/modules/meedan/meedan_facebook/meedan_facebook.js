/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
'use strict';

Drupal.behaviors.meedanFacebookComments = {

  comments: {},

  updateCommentsCount: function(path) {
    var value = Drupal.behaviors.meedanFacebookComments.comments[path] || 0;
    $('.fb-commentscount[data-url="' + path + '"]').html(Drupal.formatPlural(value, '1 comment', '@count comments')).addClass('fb-commentscount-processed');
  },

  attach: function(context, settings) {
    window.fbAsyncInit = function() {
      // Init the FB JS SDK
      FB.init({
        appId      : Drupal.settings.meedanFacebookComments.appId, // App ID from the App Dashboard
        xfbml      : true,  // parse XFBML tags on this page?
        version    : 'v2.3'
      });

      // Comments count
      FB.Event.subscribe('xfbml.render',
        function(response) {
          var paths = [], path;
          $('.fb-commentscount').each(function() {
            if (!$(this).hasClass('fb-commentscount-processed')) {
              path = $(this).attr('data-url');
              Drupal.behaviors.meedanFacebookComments.comments[path] = 0;
              paths.push(path);
            }
          });
          if (paths.length) {
            FB.api('/', { ids : paths.join() }, function(response) {
              if (response.error) {
                console.log('Error while fetching number of Facebook comments: ' + response.error.message);
              } else {
                for (var path in response) {
                  if (response.hasOwnProperty(path)) {
                    if (typeof(response[path].comments) !== 'undefined') {
                      Drupal.behaviors.meedanFacebookComments.comments[path] = response[path].comments;
                      Drupal.behaviors.meedanFacebookComments.updateCommentsCount(path);
                    }
                  }
                }
              }
            });
          }
        }
      );

      // Refresh comments count when comment is added or removed
      FB.Event.subscribe('comment.create',
        function(response) {
          Drupal.behaviors.meedanFacebookComments.comments[response.href]++;
          Drupal.behaviors.meedanFacebookComments.updateCommentsCount(response.href);
        }
      );
      FB.Event.subscribe('comment.remove',
        function(response) {
          Drupal.behaviors.meedanFacebookComments.comments[response.href]--;
          Drupal.behaviors.meedanFacebookComments.updateCommentsCount(response.href);
        }
      );
    };

    // Load the SDK's source Asynchronously
    // Note that the debug version is being actively developed and might
    // contain some type checks that are overly strict.
    // Please report such bugs using the bugs tool.

    (function(d, s, id){
         var js, fjs = d.getElementsByTagName(s)[0];
         if (d.getElementById(id)) {return;}
         js = d.createElement(s); js.id = id;
         js.src = "//connect.facebook.net/" + Drupal.settings.meedanFacebookComments.language + "/sdk.js";
         fjs.parentNode.insertBefore(js, fjs);
       }(document, 'script', 'facebook-jssdk'));

    // (function(d, debug) {
    //   var js, id = 'facebook-jssdk', ref = d.getElementsByTagName('script')[0];
    //   if (d.getElementById(id)) {
    //     FB.XFBML.parse();
    //   } else {
    //     js = d.createElement('script'); js.id = id; js.async = true;
    //     js.src = "//connect.facebook.net/" + Drupal.settings.meedanFacebookComments.language + "/all" + (debug ? "/debug" : "") + ".js";
    //     ref.parentNode.insertBefore(js, ref);
    //   }
    // }(document, /*debug*/ false));
  }
};

}(jQuery));
