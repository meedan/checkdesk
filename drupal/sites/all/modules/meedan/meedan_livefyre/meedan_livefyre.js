(function ($) {
// START jQuery

Drupal.livefyre = {
  streams: [],  // Current streams
  widgets: [],  // Elements where LiveFyre content is loaded in
  widget: null, // Reference to the object created by LiveFyre
  callback: function(widget) {
    Drupal.livefyre.widget = widget;
    widget.on('initialRenderComplete', function(data) {
      $('.livefyre-loading').remove();
    });
    widget.on('commentCountUpdated', function(data) {
      $('.livefyre-comments:visible').prev('.livefyre-header').find('.livefyre-commentcount').html(Drupal.formatPlural(data, '1 comment', '@count comments'));
    });
  }
}

Drupal.behaviors.livefyre = {
  attach: function(context, settings) {
    try {

      // Prepare streams
      var streams = [];
      var index = 0;
      $.each(settings.livefyre, function(nid, setting) {
        // Keep the same ids as the first page load
        if (window.FyreLoader) {
          setting.streamConfig.el = Drupal.livefyre.widgets[index];
          $('.livefyre-comments:eq(' + index + ')').attr('id', setting.streamConfig.el);
          index++;
        }
        streams.push(setting.streamConfig);
      });
      delete Drupal.settings.livefyre;
      Drupal.livefyre.streams = streams;

      // First time, when the page loads
      if (!window.FyreLoader) {
        $.each(streams, function(index, stream) {
          Drupal.livefyre.widgets.push(stream.el);
        });
        fyre.conv.load(
          {},
          streams,
          Drupal.livefyre.callback 
        );
      }

      // Show or hide comments
      $('.livefyre-header', context).unbind('click').click(function() {
        var comments = $('.livefyre-comments', $(this).parent());
        if (comments.is(':visible')) {
          comments.hide();
        }
        else {
          $('.livefyre-comments').hide();
          if (!comments.find('.fyre-widget').length) {
            $(this).append('<span class="livefyre-loading"><em> (' + Drupal.t('loading...') + ')</em></span>');
            Drupal.livefyre.widget.changeCollection(Drupal.livefyre.streams[$('.livefyre-comments').index(comments)]);
          }
          comments.show();
        }
      });

    // Catch exceptions
    } catch(error) {
      console.log('Error while attaching Livefyre: ' + error.toString());
    }
  }
}

// END jQuery
})(jQuery);
