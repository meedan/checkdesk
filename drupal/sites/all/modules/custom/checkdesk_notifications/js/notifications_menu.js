(function ($) {

Drupal.behaviors.meedan_notifications_menu_visibility = {
  attach: function (context, settings) {
    var block = $('#my-notifications', context);
    var title = $('#my-notifications-menu-link', context);
    block.find('.content, h2').hide();
    title.unbind('click');
    title.click(function() {
      var that = $(this);
      if (that.find('.notifications-count').html() != '') {
        $.ajax({
          type: 'GET',
          url: Drupal.settings.basePath + 'user/update-last-time',
          success: function(data) {
            if (data.timestamp) that.find('.notifications-count').html('');
          }
        });
      }
    });
  }
};

Drupal.behaviors.meedan_notifications_load_more = {
  attach: function (context, settings) {
    var block = $('#my-notifications', context);
    var container =  block.find('.view-content');
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
    var block = $('#my-notifications');
    block.unbind('autorefresh.update');
    block.bind('autorefresh.update', function(e, nid) {
      Drupal.behaviors.meedan_notifications_load_more.attach();
    });
    block.unbind('autorefresh.ping');
    block.bind('autorefresh.ping', function(e, count) {
      var counter = $('#my-notifications-menu-link').find('.notifications-count');
      if (counter.html() == '') {
        counter.html('<span>' + count + '</span>');
      }
      else {
        counter.html('<span>' + (parseInt(counter.find('span').html()) + parseInt(count)) + '</span>');
      }
    });
  }
};

})(jQuery);
