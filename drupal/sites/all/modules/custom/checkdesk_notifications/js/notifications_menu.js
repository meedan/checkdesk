/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function ($) {
'use strict';

var pageTitle = document.title;

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
              document.title = pageTitle;
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
    var soundNewItem = false;
    if (Drupal.settings.alert_new_notifications.play_sound) {
      soundManager.setup({
        url: Drupal.settings.basePath + 'sites/all/libraries/soundmanager2/swf/',
        preferFlash: false,
        onready: function() {
          // @see http://www.freesound.org/people/GabrielAraujo/sounds/242502/
          soundNewItem = soundManager.createSound({
            id: 'newItem',
            url: Drupal.settings.basePath + 'sites/all/modules/custom/checkdesk_notifications/sounds/notification.mp3'
          });
        },
        ontimeout: function() {
          console.log('Error starting SoundManager 2.');
        }
      });
    }

    var block = $('#my-notifications'),
        counter = $('#my-notifications-menu-link').find('.notifications-count');
    if (counter.html() !== '') {
      document.title = pageTitle + ' (' + counter.html() + ')';
    }
    block.unbind('autorefresh_update').bind('autorefresh_update', function(e, nid) {
      Drupal.behaviors.meedan_notifications_load_more.attach();
    });
    block.unbind('autorefresh_ping').bind('autorefresh_ping', function(e, count) {
      var total = (counter.html() === '') ? count : (parseInt(counter.html(), 10) + parseInt(count, 10));
      counter.addClass('badge').html(total);
      document.title = pageTitle + ' (' + total + ')';
      if (soundNewItem) soundNewItem.play();
    });
  }
};

}(jQuery));
