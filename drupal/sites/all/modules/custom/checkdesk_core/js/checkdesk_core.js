/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';

  Drupal.ajax.prototype.setMessages = function() {
    var ajax = this;
 
    // Do not perform another ajax command if one is already in progress.
    if (ajax.ajaxing) {
      return false;
    }
 
    try {
      $.ajax(ajax.options);
    }
    catch (err) {
      alert('An error occurred while attempting to process ' + ajax.options.url);
      return false;
    }
 
    return false;
  };
 
  // Ajax action settings for messages
  var message_settings = {};
  message_settings.url = '/core/messages/ajax/';
  message_settings.event = 'onload';
  message_settings.keypress = false;
  message_settings.prevent = false;
  Drupal.ajax.checkdesk_core_message_settings = new Drupal.ajax(null, $(document.body), message_settings);

  Drupal.behaviors.checkdesk = {
    attach: function (context, settings) {
      // Drag and drop support for reports
      $('.draggable', context).draggable({
        revert: 'invalid',
        zIndex: 3000,
        scroll: false,
        helper: 'clone',
        iframeFix: true
      });

      $('.droppable', context).droppable({
        hoverClass: 'drop-hover',
        accept: '.draggable',
        tolerance: 'touch',
        drop: function(event, ui) {
          $(ui.draggable).hide();

          // Retrieve the Views information from the DOM.
          var data       = $(ui.draggable).data('views'),
              $ckeditor  = $('.cke', this),
              $textarea  = $('textarea', this),
              instance;

          // Either insert the text into CKEDITOR, if available, else directly
          // into the text editor.
          if (CKEDITOR && $ckeditor && CKEDITOR.instances[$textarea.attr('id')]) {
            instance = CKEDITOR.instances[$textarea.attr('id')];

            // Slight abuse of the CKEDITOR input filtering to close the previous
            // <p> for line break. A new opening <p> is automatically created
            // by CKEDITOR. Annoyingly, putting this all into one insertHtml()
            // call does not seem to work.
            instance.insertHtml('</p>');
            instance.insertHtml(data.droppable_ref);
            instance.insertHtml('</p>');
          } else {
            $textarea.insertAtCaret("\n" + data.droppable_ref + "\n");
          }
        }
      });

      // Attach the Views results to each correspoknding row in the DOM.
      $('.view-desk-reports .view-content #incoming-reports').children().each(function() {
        var i = $(this).find('.report-row-container').attr('id');
        $(this).data('views', settings.checkdesk.reports[i]);
      });
      // Restrict thumbnail width to 220
      $('.view-desk-reports .view-content').find('.thumbnail img').width(220);
      // Avoid clicking the videos by applying a mask over it
      $('.view-desk-reports .view-content').find('.oembed-video .oembed-content, .content').each(function() {
        var video = $(this).find('iframe, object');
        video.css('position', 'absolute');
        video.find('embed').attr('wmode', 'transparent');
        $(this).css({ position : 'relative', display : 'block', width : video.attr('width') + 'px', height : video.attr('height') + 'px' });
        if (video.attr('src')) {
          video.attr('src', video.attr('src') + '&wmode=transparent');
        }
        video.wrap('<div class="oembed-wrapper" />');
        $(this).find('.oembed-wrapper').after('<div class="oembed-mask" />');
        $(this).find('.oembed-mask, .oembed-wrapper').css({ position : 'absolute', width : video.attr('width') + 'px', height : video.attr('height') + 'px' });
      });
      // Toggle filters when button is clicked (reports filters on "create update" sidebar)
      $('.view-desk-reports .views-exposed-widget label').each(function() {
        $(this).unbind('click').click(function() {
          $(this).siblings('.views-widget, .views-operator').slideToggle();
        });
      });
      // Avoid videos over content
      $('.oembed-video iframe').attr('src', function(index, value) {
        var wmode_set = /wmode=transparent/g;

        if (wmode_set.test(value)) {
          return value;
        }

        return value + '&wmode=transparent';
      });
      $('.oembed-video embed').attr('wmode', 'transparent');
      // close modal
      $('#close').click(function() {
        Drupal.CTools.Modal.dismiss();
        return false;
      });

      // $(".flag-link-confirm", context).once('checkdesk-modal', function () {
      //   this.href = this.href.replace(/flag\/confirm\/flag\/graphic/,'node/flag/nojs/confirm/flag/graphic');
      // }).addClass('ctools-use-modal ctools-modal-checkdesk-style');

      // Trigger 
      // $('.some-class').click(function() {
      //   Drupal.ajax['checkdesk_core_message_settings'].setMessages();
      // });

      // Show messages when an item is flagged/unflagged
      $(document).bind('flagGlobalAfterLinkUpdate', function(event, data) {
        Drupal.ajax.checkdesk_core_message_settings.setMessages();
      });

    }
  };


  /**
   * Provide the HTML to create the modal dialog.
  */
  Drupal.theme.prototype.CheckDeskModal = function () {
    var html = '';

    html += '<div id="ctools-modal">';
    html += '<div class="ctools-modal-content">';
    html += '<div class="modal">';
    html += '  <div class="modal-header">';
    html += '   <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>';
    html += '   <h4><span id="modal-title" class="modal-title"></span></h4>';
    html += '  </div>';
    html += ' <div class="modal-body">';
    html += '   <div id="modal-content" class="modal-content"></div>';
    html += ' </div>';
    html += '</div>';
    html += '</div>';
    html += '</div>';

    return html;
  };

}(jQuery));
