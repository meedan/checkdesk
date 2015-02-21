/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function ($) {
  'use strict';

  // Function to retrieve a media preview from a URL.
  function getMediaPreview() {
    var $input = $('#edit-field-link-und-0-url'),
        $preview = $('#meedan_bookmarklet_preview'),
        $preview_content = $('#meedan_bookmarklet_preview_content'),
        $controls = $('#edit-body, #edit-graphic-content, #edit-submit, #edit-title, #edit-field-tags, #edit-field-stories');

    $input.addClass('meedan-bookmarklet-loading');

    $.ajax({
      url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'checkdesk/media-preview?' + parseInt(Math.random() * 1000000000, 10),
      data: { url : $input.val() },
      dataType: 'json',
      success: function (data) {
        if (data.error) {
          $preview_content.addClass('error').html(data.error.message);
          $controls.hide();
        } else {
          $preview_content.removeClass('error').html(data.preview);
          if (data.title) $('#edit-title').val(data.title);
          $controls.show();
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
      var typingTimer,
          urlPrevious;
      $('#edit-field-link-und-0-url', context).keyup(function(e) {
        clearTimeout(typingTimer);
        var url = $(this).val(),
            done = $('#edit-submit');
        if (/https?:\/\/[^.]+\.[^.]+/.test(url)) {
          done.removeAttr('disabled');
          if (url !== urlPrevious) {
            urlPrevious = url;
            typingTimer = setTimeout(getMediaPreview, 500);
          }
        }
        else {
          done.attr('disabled', 'disabled');
          $('#edit-body, #edit-graphic-content, #edit-submit, #edit-title, #edit-field-tags, #edit-field-stories').hide();
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
