/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function ($) {
'use strict';

var pageTitle = document.title;

Drupal.behaviors.meedan_notifications_menu_visibility = {
  attach: function (context, settings) {
    var block = $('#my-notifications', context),
        title = $('#my-notifications-menu-link', context);
    block.find('.content, h2').hide();
    title.unbind('click').click(function() {
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
    container.unbind('scroll').scroll(function() {
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

    var updatePageTitle = function(count) {
      if (!count) {
        document.title = pageTitle;
        return;
      }

      // In the case of RTL text, brackets appear misaligned. We need to test the last character of the title
      // and add a special Unicode RTL marker if it is Arabic or Hebrew.
      // @see http://stackoverflow.com/questions/8698441/changing-the-direction-of-html-title-tag-to-right-to-left
      // @see http://stackoverflow.com/questions/12006095/javascript-how-to-check-if-character-is-rtl
      var rtl = new RegExp(
        '[' +
        '\u0600-\u06FF' + // Arabic - Range
        '\u0750-\u077F' + // Arabic Supplement - Range
        '\uFB50-\uFDFF' + // Arabic Presentation Forms-A - Range
        '\uFE70-\uFEFF' + // Arabic Presentation Forms-B - Range
        '\u0590-\u07FF' + // Hebrew
        ']'
      );
      var rtlChar = '';
      if (pageTitle.slice(-1).match(rtl)) {
        rtlChar = '\u202B';
      }
      document.title = rtlChar + pageTitle + ' (' + count + ')';
    };

    var block = $('#my-notifications'),
        counter = $('#my-notifications-menu-link').find('.notifications-count');
    if (counter.html() !== '') {
      updatePageTitle(counter.html());
    }
    block.unbind('autorefresh_update').bind('autorefresh_update', function(e, nid) {
      Drupal.behaviors.meedan_notifications_load_more.attach();
    });
    block.unbind('autorefresh_ping').bind('autorefresh_ping', function(e, count) {
      var total = (counter.html() === '') ? count : (parseInt(counter.html(), 10) + parseInt(count, 10));
      counter.addClass('badge').html(total);
      updatePageTitle(total);
      if (soundNewItem) soundNewItem.play();
    });
  }
};

}(jQuery));
