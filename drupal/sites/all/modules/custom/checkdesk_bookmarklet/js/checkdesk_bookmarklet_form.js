/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

// Stuff here happens after bookmarklet form is rendered
jQuery(function($) {
  'use strict';

  // Function to retrive a media preview from a URL
  function getMediaPreview() {
    var $input = $('#edit-field-link-und-0-url'),
        $preview = $('#meedan_bookmarklet_preview_content'),
        $controls = $('#edit-body, #edit-graphic-content, #edit-submit');

    $input.addClass('meedan-bookmarklet-loading');

    $.ajax({
      url: Drupal.settings.basePath + 'checkdesk/media-preview?' + parseInt(Math.random() * 1000000000, 10),
      data: { url : $input.val() },
      dataType: 'json',
      success: function (data) {
        if (data.error) {
          $preview.addClass('error').html(data.error.message);
          $controls.hide();
        } else {
          $preview.removeClass('error').html(data.preview);
          $controls.show();
        }
      },
      error: function (xhr, textStatus, error) {
        $preview.addClass('error').html(Drupal.t('An error occurred while communicating with Checkdesk. Please try again.'));
        $controls.hide();
      },
      complete: function (xhr, textStatus) {
        $input.removeClass('meedan-bookmarklet-loading');
        $('#meedan_bookmarklet_preview').show();
      }
    });
  }

  // Update preview if URL changes
  $('#edit-field-link-und-0-url').keyup(function() {
    var url = $(this).val();
    var done = $('#edit-submit');
    if (/https?:\/\/[^.]+\.[^.]+/.test(url)) {
      done.removeAttr('disabled');
      clearTimeout($.data(this, 'timer'));
      var wait = setTimeout(getMediaPreview, 1500);
      $(this).data('timer', wait);
    } else {
      done.attr('disabled', 'disabled');
    }
  });

  // Hide preview if graphic content is checked
  $('#edit-graphic-content-graphic, #edit-graphic-content-graphic-journalist').click(function() {
    var mask = $('#meedan_bookmarklet_preview_gc');
    var content = $('#meedan_bookmarklet_preview_content');
    if ($(this).is(':checked')) {
      mask.show();
      content.hide();
    } else {
      mask.hide();
      content.show();
    }
  });
  $('#meedan_bookmarklet_preview_gc a').click(function() {
    $('#meedan_bookmarklet_preview_gc').hide();
    $('#meedan_bookmarklet_preview_content').show();
    return false;
  });

  // Disable submit button if link field is empty
  $('#edit-submit').click(function() {
    if ($('#edit-field-link-und-0-url').val() == '') {
      return false;
    }
  });

  // Watch the height of the iframe, inform the parent every time it changes
  var htmlHeight = 0;

  function checkHTMLHeight() {
    if ($('html').height() != htmlHeight) {
      htmlHeight = $('html').height();

      window.parent.postMessage({ type: 'resize', height: htmlHeight + 32 }, '*');
    }

    setTimeout(checkHTMLHeight, 250);
  }

  // Start the checker
  checkHTMLHeight();

  window.parent.postMessage('loaded', '*');
});
