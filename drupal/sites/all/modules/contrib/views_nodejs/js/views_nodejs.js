(function ($) {

/**
 * Drupal.Nodejs.callback on views update.
 */
Drupal.Nodejs.callbacks.viewsNodejs = {
  callback: function (message) {
    if (Drupal.settings && Drupal.settings.viewsNodejs && Drupal.settings.viewsNodejs.views) {
      $.each(Drupal.settings.viewsNodejs.views, function(i, view) {
        var settings = view.settings;

        // Search in settings view which need update.
        if (settings.view_name == message.view_id && settings.view_display_id == message.display_id) {
          var selector = '.view-dom-id-' + settings.view_dom_id,
              href = view.href,
              viewData = {};

          // Construct an object using the settings defaults and then overriding
          // with data specific to the link.
          $.extend(
            viewData,
            settings,
            Drupal.Views.parseQueryString(href),
            // Extract argument data from the URL.
            Drupal.Views.parseViewArgs(href, settings.view_base_path)
          );

          // For anchor tags, these will go to the target of the anchor rather
          // than the usual location.
          $.extend(viewData, Drupal.Views.parseViewArgs(href, settings.view_base_path));

          // Ajax settings for uping view.
          var ajax_settings = {
            url: Drupal.settings.viewsNodejs.ajax_path,
            submit: viewData,
            selector: selector
          };

          var ajax = new Drupal.ajax(false, false, ajax_settings);
          ajax.eventResponse(ajax, {});
        }
      });
    }
  }
};

}(jQuery));
