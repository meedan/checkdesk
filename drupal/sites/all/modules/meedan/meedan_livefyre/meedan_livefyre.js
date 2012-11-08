(function ($) {
// START jQuery

Drupal.livefyre = {
  callback: function(widget) {
  }
}

Drupal.behaviors.livefyre = {
  attach: function(context, settings) {
    var streams = [];
    $.each(settings.livefyre, function(nid, setting) {
      streams.push(setting.streamConfig);
    });
    fyre.conv.load(
      {},
      streams,
      Drupal.livefyre.callback 
    )
  }
}

// END jQuery
})(jQuery);

