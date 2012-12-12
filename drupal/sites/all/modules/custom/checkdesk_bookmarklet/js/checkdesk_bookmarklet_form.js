// Stuff here happens after bookmarklet form is rendered

jQuery(function($) {

  // Function to retrive a media preview from a URL
  function getMediaPreview() {
    var input = $('#edit-field-link-und-0-url');
    input.addClass('meedan-bookmarklet-loading');
    $.get(Drupal.settings.basePath + 'checkdesk/media-preview?' + parseInt(Math.random() * 1000000000), { url : input.val() }, function(data) {
      $('#meedan_bookmarklet_preview_content').html(data);
      input.removeClass('meedan-bookmarklet-loading');
      if (data) {
        $('#meedan_bookmarklet_preview, #edit-body, #edit-graphic-content, #edit-submit').show();
        // Link was provided, so restore window to its original size
        window.parent.postMessage('reset', '*');
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

  window.parent.postMessage('loaded', '*');
});
