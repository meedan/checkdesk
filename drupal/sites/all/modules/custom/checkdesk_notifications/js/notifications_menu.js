/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function ($) {
'use strict';

Drupal.behaviors.meedan_notifications_menu_visibility = {
  attach: function (context, settings) {
    var block = $('#my-notifications', context),
        title = $('#my-notifications-menu-link', context);
    block.find('.content, h2').hide();
    title.unbind('click');
    title.click(function() {
      var that = $(this);
      if (that.find('.notifications-count').html() !== '') {
        $.ajax({
          type: 'GET',
          url: Drupal.settings.basePath + 'user/update-last-time',
          success: function(data) {
            if (data.timestamp) {
              // Don't hide the notification count
              that.find('.notifications-count').removeClass('badge').html('');
            }
          }
        });
      }
    });
  }
};

Drupal.behaviors.meedan_notifications_load_more = {
  attach: function (context, settings) {
    var block = $('#my-notifications', context),
        container =  block.find('.view-content');
    container.unbind('scroll');
    container.scroll(function() {
      if ($(this)[0].scrollHeight - $(this).scrollTop() === $(this).outerHeight()) {
        block.find('.pager a').click();
      }
    });
  }
};

Drupal.behaviors.alert_new_notifications = {
  attach: function (context, settings) {
    var block, counter;
    block = $('#my-notifications');
    block.unbind('autorefresh_update');
    block.bind('autorefresh_update', function(e, nid) {
      Drupal.behaviors.meedan_notifications_load_more.attach();
    });
    block.unbind('autorefresh_ping');
    block.bind('autorefresh_ping', function(e, count) {
      counter = $('#my-notifications-menu-link').find('.notifications-count');
      if (counter.html() === '') {
        counter.replaceWith('<span class="badge notifications-count">' + count + '</span>');
      }
      else {
        counter.replaceWith('<span class="badge notifications-count">' + (parseInt(counter.html(), 10) + parseInt(count, 10)) + '</span>');
      }
    });
  }
};

Drupal.behaviors.meedan_notifications_adjust_heights = {
  attach: function (context, settings) {
    // we need that each row has an integer height, otherwise loading more may not work
    var li = $('#my-notifications').parents('li'),
        hidden = !li.hasClass('open');
    if (hidden) {
      li.addClass('open');
    }
    $('#my-notifications .views-row').each(function() {
      var height = $(this).height();
      if (height > 0) {
        $(this).css('height', height);
      }
    });
    if (hidden) {
      li.removeClass('open');
    }
  }
};

}(jQuery));
