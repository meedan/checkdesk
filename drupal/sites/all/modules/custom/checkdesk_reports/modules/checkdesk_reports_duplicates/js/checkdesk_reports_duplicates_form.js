/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function ($) {
  'use strict';

    jQuery('#edit-field-stories-und').change(function() {
        var story_id = jQuery(this).val();
        var report_id = 0;
        if (typeof Drupal.settings.checkdesk_reports_duplicates !== 'undefined') {
            report_id = Drupal.settings.checkdesk_reports_duplicates.report_nid;
        }
        jQuery('#checkdesk_report_story_duplicate').hide();
        jQuery('#edit-submit').show();
        var url = jQuery('#edit-field-link-und-0-url').val().trim();
        jQuery.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'checkdesk/duplicate-report-story?' + parseInt(Math.random() * 1000000000, 10),
            data: { url : url, report_id : report_id, story_id : story_id },
            dataType: 'json',
            success: function (data) {
                if (data.duplicate) {
                    jQuery('#checkdesk_report_story_duplicate').show().addClass('error').html(data.msg);
                    jQuery('#edit-submit').hide();
                }
            },
            error: function (xhr, textStatus, error) {

            },
            complete: function (xhr, textStatus) {

            }
        });
    });

  // Function to retrieve a media preview from a URL.
  function getMediaPreview() {
    var $input = $('#edit-field-link-und-0-url'),
        url = $input.val().trim();

    var report_id = 0;
    if (typeof Drupal.settings.checkdesk_reports_duplicates !== 'undefined') {
        report_id = Drupal.settings.checkdesk_reports_duplicates.report_nid;
    }
    var story_id = jQuery('#edit-field-stories-und').val();
    $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'checkdesk/duplicate-report?' + parseInt(Math.random() * 1000000000, 10),
      data: { url : url, report_id : report_id, story_id : story_id },
      dataType: 'json',
      success: function (data) {
          $('#checkdesk_report_duplicate').html('').hide();
          $('#edit-submit').show();
          if (data.duplicates.duplicate) {
            // Fix geolocation Google maps grey area bug.
            try {
                $.each(Drupal.settings.geolocation.defaults, function (i) {
                    google.maps.event.trigger(Drupal.geolocation.maps[i], "resize");
                });
            }
            catch (e) {
                // no maps, nothing to do.
            }
            $('#checkdesk_report_duplicate').show().html(data.duplicates.msg);
            if (data.duplicates.duplicate_story) {
                // Report already exists in same story
                // Hide submit button
                $('#edit-submit').hide();
            }
        }
      },
      complete: function (xhr, textStatus) {
        $input.removeClass('meedan-bookmarklet-loading');
      }
    });
  }

  function checkEnter(e){
    e = e || event;
    var txtArea = /textarea/i.test((e.target || e.srcElement).tagName);
    return txtArea || (e.keyCode || e.which || e.charCode || 0) !== 13;
  }

  Drupal.behaviors.checkdeskBookmarklet = {
    attach: function(context, settings) {

      // http://stackoverflow.com/a/587575/209184
      document.querySelector('form').onkeypress = checkEnter;

      // Inform the parent.
      window.parent.postMessage('loaded', '*');


      // Update preview if URL changes.
      var typingTimer;
      $('#edit-field-link-und-0-url', context).keyup(function(e) {
        clearTimeout(typingTimer);
        var url = $(this).val().trim(),
            done = $('#edit-submit');
        if (/https?:\/\/[^.]+\.[^.]+/.test(url)) {
          done.removeAttr('disabled');
          typingTimer = setTimeout(getMediaPreview, 500);
        }
        else {
          done.attr('disabled', 'disabled');
        }
      });

      $('#edit-field-link-und-0-url', context).keydown(function(e) {
        clearTimeout(typingTimer);
      });

      // Disable submit button if link field is empty
      $('#edit-submit', context).click(function() {
        if (!$('#edit-field-link-und-0-url').val()) {
          return false;
        }
      });
    }
  };

})(jQuery);
