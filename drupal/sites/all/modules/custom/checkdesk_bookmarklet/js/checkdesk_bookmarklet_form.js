/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function ($) {
  'use strict';

  // Function to retrieve a media preview from a URL.
  function getMediaPreview() {
    var $input = $('#edit-field-link-und-0-url'),
        $preview = $('#meedan_bookmarklet_preview'),
        $preview_content = $('#meedan_bookmarklet_preview_content'),
        $controls = $('#edit-body, #edit-graphic-content, #edit-submit, .form-item-title, #edit-field-tags, #edit-field-stories, #edit-field-rating'),
        url = $input.val().trim();

    $input.addClass('meedan-bookmarklet-loading');
    var report_id = 0;
    if (typeof Drupal.settings.checkdesk_duplicates !== 'undefined') {
        report_id = Drupal.settings.checkdesk_duplicates.report_nid;
    }
    var story_id = jQuery('#edit-field-stories-und').val();
    $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'checkdesk/media-preview?' + parseInt(Math.random() * 1000000000, 10),
      data: { url : url, report_id : report_id, story_id : story_id },
      dataType: 'json',
      success: function (data) {
        if (data.error) {
          $preview_content.addClass('error').html(data.error.message);
          $controls.hide();
        } else {
          $preview_content.removeClass('error').html(data.preview);
          if (data.title) $('#edit-title').val(data.title);

          $controls.show();
          $('#checkdesk_report_duplicate').hide();
          if (data.duplicates.duplicate) {
              if (data.duplicates.duplicate_story) {
                  //Report already exists in same story
                  $('#checkdesk_report_duplicate').show().addClass('error').html(data.duplicates.msg);
                  // Hide submit button
                  $('#edit-submit').hide();
              }
              else {
                  $('#checkdesk_report_duplicate').show().addClass('status').html(data.duplicates.msg);
              }
          }
        }
      },
      error: function (xhr, textStatus, error) {
        $preview_content.addClass('error').html(Drupal.t('An error occurred while communicating with Checkdesk. Please try again.'));
        $controls.hide();
      },
      complete: function (xhr, textStatus) {
        $input.removeClass('meedan-bookmarklet-loading');
        $preview.show();
        Drupal.attachBehaviors($preview[0]);
      }
    });
  }

  // Watch the height of the iframe, inform the parent every time it changes
  var htmlHeight = 0;
  function checkHTMLHeight() {
    var height = $('body')[0].offsetHeight;
    if (height !== htmlHeight) {
      htmlHeight = height;
      window.parent.postMessage(['setHeight', htmlHeight].join(';'), '*');
    }
    setTimeout(checkHTMLHeight, 30);
  }

  Drupal.behaviors.checkdeskBookmarklet = {
    attach: function(context, settings) {

      // Start the checker.
      checkHTMLHeight();

      // Inform the parent.
      window.parent.postMessage('loaded', '*');

      // Preview media if any.
      if ($('#edit-field-link-und-0-url', context).val()) {
        getMediaPreview();
      }

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
          $('#edit-body, #edit-graphic-content, #edit-submit, .form-item-title, #edit-field-tags, #edit-field-stories, #edit-field-rating').hide();
          $('#meedan_bookmarklet_preview_content').html('');
        }
      });

      $('#edit-field-link-und-0-url', context).keydown(function(e) {
        clearTimeout(typingTimer);
        if (e.keyCode == 13) {
          e.preventDefault();
        }
      });

      // Hide preview if graphic content is checked
      $('#edit-graphic-content-graphic, #edit-graphic-content-graphic-journalist', context).click(function() {
        var mask = $('#meedan_bookmarklet_preview_gc'),
            content = $('#meedan_bookmarklet_preview_content');
        if ($(this).is(':checked')) {
          mask.show();
          content.hide();
        } else {
          mask.hide();
          content.show();
        }
      });
      $('#meedan_bookmarklet_preview_gc a', context).click(function() {
        $('#meedan_bookmarklet_preview_gc').hide();
        $('#meedan_bookmarklet_preview_content').show();
        return false;
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
