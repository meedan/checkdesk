(function ($) {
// START jQuery

Drupal.behaviors.meedan_facebook_comments = {

  updateCommentsCount: function(url, value) {
    $('.fb-commentscount[data-url="' + url + '"]').html(Drupal.formatPlural(value, '1 comment', '@count comments')).addClass('fb-commentscount-processed');
  },

  attach: function(context, settings) {

    window.fbAsyncInit = function() {

      // Init the FB JS SDK
      FB.init({
        appId      : Drupal.settings.meedan_facebook.appId, // App ID from the App Dashboard
        channelUrl : Drupal.settings.meedan_facebook.channelUrl, // Channel File for x-domain communication
        status     : true, // check the login status upon init?
        cookie     : true, // set sessions cookies to allow your server to access the session?
        xfbml      : true  // parse XFBML tags on this page?
      });

      // Additional initialization code such as adding Event Listeners goes here

      // Comments count
      var paths = [];
      $('.fb-commentscount').each(function() {
        if (!$(this).hasClass('fb-commentscount-processed')) {
          var path = $(this).attr('data-url');
          paths.push(path);
        }
      });
      if (paths.length) {
        FB.api('/', { ids : paths.join() }, function(response) {
          if (response.error) {
            console.log('Error while fetching number of Facebook comments: ' + response.error.message);
          } else {
            for (var path in response) {
              // Why "shares" and not "comments"?
              var value = response[path].shares;
              if (value) {
                Drupal.behaviors.meedan_facebook_comments.updateCommentsCount(path, value);
              }
            }
          }
        });
      }

      // Refresh comments count when comment is added or removed
      FB.Event.subscribe('comment.create',
        function(response) {
          var counter = $('.fb-commentscount[data-url="' + response.href + '"]');
          var value = (isNaN(parseInt(counter.html())) ? 0 : parseInt(counter.html()));
          Drupal.behaviors.meedan_facebook_comments.updateCommentsCount(response.href, value + 1);
        }
      );
      FB.Event.subscribe('comment.remove',
        function(response) {
          var counter = $('.fb-commentscount[data-url="' + response.href + '"]');
          var value = (isNaN(parseInt(counter.html())) ? 0 : parseInt(counter.html()));
          Drupal.behaviors.meedan_facebook_comments.updateCommentsCount(response.href, value - 1);
        }
      );
    };

    // Load the SDK's source Asynchronously
    // Note that the debug version is being actively developed and might 
    // contain some type checks that are overly strict. 
    // Please report such bugs using the bugs tool.
    (function(d, debug) {
      var js, id = 'facebook-jssdk', ref = d.getElementsByTagName('script')[0];
      if (d.getElementById(id)) {
        FB.XFBML.parse();
        return;
      } else {
        js = d.createElement('script'); js.id = id; js.async = true;
        js.src = "//connect.facebook.net/" + Drupal.settings.meedan_facebook.language + "/all" + (debug ? "/debug" : "") + ".js";
        ref.parentNode.insertBefore(js, ref);
      }
    }(document, /*debug*/ false));

    // Show or hide comments
    $('.fb-comments-header').die('click').live('click', function() {
      var header = $(this);
      var comments = $('.fb-comments, .fb_iframe_widget', header.parent());
      comments.toggleClass('fb-comments-visible');
      if (comments.hasClass('fb-comments-visible')) {
        $('html, body').animate({ scrollTop : header.offset().top }, 1000);
      }
    });
  }
}

// END jQuery
})(jQuery);
