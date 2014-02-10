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
                Drupal.settings.views_autorefresh[settings.view_name].view_args = viewData.view_args;
                // Setup the click response with Drupal.ajax.
                var element_settings = {};
                element_settings.url = ajax_path;
                element_settings.event = 'click';
                element_settings.selector = view;
                element_settings.submit = viewData;
                Drupal.settings.views_autorefresh[settings.view_name].ajax = new Drupal.ajax(view, this, element_settings);

                // Activate refresh timer.
                clearTimeout(Drupal.settings.views_autorefresh[settings.view_name].timer);
                Drupal.views_autorefresh.timer(settings.view_name, anchor, target);
              }); // .each function () {
        }); // $view.filter().each
      });
    }
  }
}

Drupal.views_autorefresh.timer = function(view_name, anchor, target) {
  Drupal.settings.views_autorefresh[view_name].timer = setTimeout(function() {
    clearTimeout(Drupal.settings.views_autorefresh[view_name].timer);

    // Turn off "new" items class.
    $('.views-autorefresh-new', target).removeClass('views-autorefresh-new');

    // Handle ping path.
    var ping_base_path;
    if (Drupal.settings.views_autorefresh[view_name].ping) {
      ping_base_path = Drupal.settings.views_autorefresh[view_name].ping.ping_base_path;
    }
    
    // Handle secondary view for incremental refresh.
    // http://stackoverflow.com/questions/122102/what-is-the-most-efficient-way-to-clone-a-javascript-object
    var viewData = Drupal.settings.views_autorefresh[view_name].ajax.submit;
    var viewArgs = Drupal.settings.views_autorefresh[view_name].view_args;
    if (Drupal.settings.views_autorefresh[view_name].incremental) {
      if (!viewData.original_view_data) viewData.original_view_data = $.extend(true, {}, viewData);
      viewData.view_args = viewArgs + (viewArgs.length ? '/' : '') + Drupal.settings.views_autorefresh[view_name].timestamp;
      viewData.view_base_path = Drupal.settings.views_autorefresh[view_name].incremental.view_base_path;
      viewData.view_display_id = Drupal.settings.views_autorefresh[view_name].incremental.view_display_id;
      viewData.view_name = Drupal.settings.views_autorefresh[view_name].incremental.view_name;
    }
    viewData.autorefreshRequest = 'autorefreshRequest';
    Drupal.settings.views_autorefresh[view_name].ajax.submit = viewData;

    // If there's a ping URL, hit it first.
    if (ping_base_path) {
      $.ajax({
        url: Drupal.settings.basePath + ping_base_path,
        data: {
          timestamp: Drupal.settings.views_autorefresh[view_name].timestamp
        },
        success: function(response) {
          if (response.pong && parseInt(response.pong) > 0) {
            $(target).trigger('autorefresh.ping', parseInt(response.pong));
            $(anchor).trigger('click');
          }
          else {
            Drupal.views_autorefresh.timer(view_name, anchor, target);
          }
        },
        error: function(xhr) {},
        dataType: 'json',
      });
    }
    else {
      $(anchor).trigger('click');
    }
  }, Drupal.settings.views_autorefresh[view_name].interval);
}

Drupal.ajax.prototype.commands.viewsAutoRefreshTriggerUpdate = function (ajax, response, status) {
  $(response.selector).trigger('autorefresh.update', response.timestamp);
}

// http://stackoverflow.com/questions/1394020/jquery-each-backwards
jQuery.fn.reverse = [].reverse;

Drupal.ajax.prototype.commands.viewsAutoRefreshIncremental = function (ajax, response, status) {
  var $view = $(response.selector);
  if (response.data) {
    // jQuery removes script tags, so let's mask them now and later unmask.
    // http://stackoverflow.com/questions/4430707/trying-to-select-script-tags-from-a-jquery-ajax-get-response/4432347#4432347
    response.data = response.data.replace(/<(\/?)script([^>]*)>/gi, '<$1scripttag$2>');

    var sourceSelector = Drupal.settings.views_autorefresh[response.view_name].incremental.sourceSelector || '.view-content';
    var $source = $(response.data).find(sourceSelector).not(sourceSelector + ' ' + sourceSelector).children();
    if ($source.size() > 0) {
      var targetSelector = Drupal.settings.views_autorefresh[response.view_name].incremental.targetSelector || '.view-content';
      var $target = $view.find(targetSelector).not(targetSelector + ' ' + targetSelector);

      // If initial view was empty, remove the empty divs then add the target div.
      if ($target.size() == 0) {
        var emptySelector = Drupal.settings.views_autorefresh[response.view_name].incremental.emptySelector || '.view-empty';
        var afterSelector = Drupal.settings.views_autorefresh[response.view_name].incremental.afterSelector || '.view-header';
        var targetStructure = Drupal.settings.views_autorefresh[response.view_name].incremental.targetStructure || '<div class="view-content"></div>';
        if ($(emptySelector, $view).size() > 0) {
          // replace empty div with content.
          $(emptySelector, $view).replaceWith(targetStructure);
        }
        else if ($(afterSelector, $view).size() > 0) {
          // insert content after given div.
          $view.find(afterSelector).not(targetSelector + ' ' + afterSelector).after(targetStructure);
        }
        else {
          // insert content as first child of view div.
          $view.prepend(targetStructure);
        }
        // Now that it's inserted, find it for manipulation.
        $target = $view.find(targetSelector).not(targetSelector + ' ' + targetSelector);
      }

      // Remove first, last row classes from items.
      var firstClass = Drupal.settings.views_autorefresh[response.view_name].incremental.firstClass || 'views-row-first';
      var lastClass = Drupal.settings.views_autorefresh[response.view_name].incremental.lastClass || 'views-row-last';
      $target.children().removeClass(firstClass);
      $source.removeClass(lastClass);

      // Adjust even-odd classes.
      var oddClass = Drupal.settings.views_autorefresh[response.view_name].incremental.oddClass || 'views-row-odd';
      var evenClass = Drupal.settings.views_autorefresh[response.view_name].incremental.evenClass || 'views-row-even';
      var oddness = $target.children(':first').hasClass(oddClass);
      $source.filter('.' + oddClass + ', .' + evenClass).reverse().each(function() {
        $(this).removeClass(oddClass + ' ' + evenClass).addClass(oddness ? evenClass : oddClass);
        oddness = !oddness;
      });

      // Add the new items to the view.
      // Put scripts back first.
      $source.each(function() {
        $target.prepend($(this)[0].outerHTML.replace(/<(\/?)scripttag([^>]*)>/gi, '<$1script$2>'));
      });

      // Adjust row number classes.
      var rowClassPrefix = Drupal.settings.views_autorefresh[response.view_name].incremental.rowClassPrefix || 'views-row-';
      var rowRegex = new RegExp('views-row-(\\d+)');
      $target.children().each(function(i) {
        $(this).attr('class', $(this).attr('class').replace(rowRegex, rowClassPrefix + (i+1)));
      });

      // Trigger custom event on any plugin that needs to do extra work.
      $view.trigger('autorefresh.incremental', $source.size());
    }

    // Reactivate refresh timer.
    Drupal.views_autorefresh.timer(response.view_name, $('.auto-refresh a', $view), $view);
    
    // Attach behaviors
    Drupal.attachBehaviors($view);
  }
}

// END jQuery
})(jQuery);

