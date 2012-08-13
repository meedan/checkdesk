(function ($) {
// START jQuery

Drupal.views_autorefresh = Drupal.views_autorefresh || {};

Drupal.behaviors.views_autorefresh = {
  attach: function(context, settings) {
    if (Drupal.settings && Drupal.settings.views && Drupal.settings.views.ajaxViews) {
      var ajax_path = Drupal.settings.views.ajax_path;
      // If there are multiple views this might've ended up showing up multiple times.
      if (ajax_path.constructor.toString().indexOf("Array") != -1) {
        ajax_path = ajax_path[0];
      }
      $.each(Drupal.settings.views.ajaxViews, function(i, settings) {
        var view = '.view-dom-id-' + settings.view_dom_id;
        if (!$(view).size()) {
          // Backward compatibility: if 'views-view.tpl.php' is old and doesn't
          // contain the 'view-dom-id-#' class, we fall back to the old way of
          // locating the view:
          view = '.view-id-' + settings.view_name + '.view-display-id-' + settings.view_display_id;
        }
        $(view).filter(':not(.views-autorefresh-processed)')
          // Don't attach to nested views. Doing so would attach multiple behaviors
          // to a given element.
          .filter(function() {
            // If there is at least one parent with a view class, this view
            // is nested (e.g., an attachment). Bail.
            return !$(this).parents('.view').size();
          })
          .each(function() {
            // Set a reference that will work in subsequent calls.
            var target = this;
            $('select,input,textarea', target)
            .click(function () {
              if (Drupal.settings.views_autorefresh[settings.view_name].timer) {
                clearTimeout(Drupal.settings.views_autorefresh[settings.view_name].timer);
              }
            })
            .change(function () {
              if (Drupal.settings.views_autorefresh[settings.view_name].timer) {
                clearTimeout(Drupal.settings.views_autorefresh[settings.view_name].timer);
              }
            });
            $(this)
              .addClass('views-autorefresh-processed')
              // Process pager, tablesort, and attachment summary links.
              .find('.auto-refresh a')
              .each(function () {
                var viewData = { 'js': 1 };
                var anchor = this;
                // Construct an object using the settings defaults and then overriding
                // with data specific to the link.
                $.extend(
                  viewData,
                  Drupal.Views.parseQueryString($(this).attr('href')),
                  // Extract argument data from the URL.
                  Drupal.Views.parseViewArgs($(this).attr('href'), settings.view_base_path),
                  // Settings must be used last to avoid sending url aliases to the server.
                  settings
                );

                $.extend(viewData, Drupal.Views.parseViewArgs($(this).attr('href'), settings.view_base_path));
                $(this).addClass('views-throbbing');
                var base = view;
                var element_settings = {};
                element_settings.url = ajax_path;
                element_settings.event = 'click';
                element_settings.selector = base;
                element_settings.submit = viewData;
                var ajax = new Drupal.ajax(base, this, element_settings);

                // Activate refresh timer.
                Drupal.views_autorefresh.timer(settings.view_name, anchor);
              }); // .each function () {
        }); // $view.filter().each
      });
    }
  }
}

Drupal.views_autorefresh.timer = function(view_name, anchor) {
  Drupal.settings.views_autorefresh[view_name].timer = setTimeout(function() {
    clearTimeout(Drupal.settings.views_autorefresh[view_name].timer);
    $(anchor).click();
  }, Drupal.settings.views_autorefresh[view_name].interval);
}

// END jQuery
})(jQuery);
