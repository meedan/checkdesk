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
              $textarea  = $('textarea', this),
              instance;

          // Either insert the text into CKEDITOR, if available, else directly
          // into the text editor.
          if (typeof CKEDITOR != 'undefined' && CKEDITOR.instances[$textarea.attr('id')]) {
            instance = CKEDITOR.instances[$textarea.attr('id')];
            var mediaoembed_template = '<md class="tagMediaOembedClass" datasource="'+ data.nid +'">' + data.droppable_ref + '</md>';
            instance.insertHtml(mediaoembed_template);
            // add newline.
            instance.execCommand( 'enter' );
            // remember the inserted report.
            instance.checkdeskReports[data.nid] = data.droppable_ref;
          } else {
            $textarea.insertAtCaret("\n" + data.droppable_ref + "\n");
          }
        }
      });

      // CKEditor configuration, see: http://www.question2answer.org/qa/13255/simple-ckeditor-how-to-modify-it-to-be-simple-solution
      if (typeof CKEDITOR != 'undefined') {
        // Force CKEditor plugins to be reloaded.
        CKEDITOR.timestamp = ( new Date() ).valueOf();

        CKEDITOR.on('dialogDefinition', function(ev) {
          var dialog = ev.data, currentDialog;

          if (dialog.name == 'link') {
            dialog.definition.onShow = function () {
              currentDialog = CKEDITOR.dialog.getCurrent();

              currentDialog.getContentElement('info','anchorOptions').getElement().hide();
              currentDialog.getContentElement('info','emailOptions').getElement().hide();
              currentDialog.getContentElement('info','linkType').getElement().hide();
              currentDialog.getContentElement('info','protocol').disable();
            };
          }
        });
        // Listen to CKEditor content changes and hide/unhide reports accordingly.
        CKEDITOR.on('instanceReady', function(ev) {
          var editor = ev.editor;
          editor.checkdeskReports = {};
          editor.on('change', function(ev) {
            var data = editor.getData();
            $.each(editor.checkdeskReports, function(nid, ref) {
                //check if ref exist return wrong value if contain EN+AR
                // Ticket #3404 - changed to check with last part of ref ":report-id]"
              if (-1 !== data.indexOf(":" + nid + "]")) {
                // report is there: hide in sidebar.
                $('#report-'+nid).parent().hide();
              } else {
                // report is not there: show in sidebar.
                $('#report-'+nid).parent().show();
              }
            })
          })
        });
      }

      // Attach the Views results to each correspoknding row in the DOM.
      $('.view-display-id-incoming_reports .view-content').children().each(function() {
        var i = $(this).find('.report-row-container').attr('id');
        $(this).data('views', settings.checkdesk.reports[i]);
      });
      // Restrict thumbnail width to 220
      $('.view-display-id-incoming_reports .view-content').find('.thumbnail img').width(220);
      // Avoid clicking the videos by applying a mask over it
      $('.view-display-id-incoming_reports .view-content').find('.oembed-video .oembed-content, .content').each(function() {
        var video = $(this).find('iframe, object');
        video.css('position', 'absolute');
        video.find('embed').attr('wmode', 'transparent');
        $(this).css({ position : 'relative', display : 'block', width : video.attr('width') + 'px', height : video.attr('height') + 'px' });
        var src = video.attr('src');
        if (src) {
          var sep = src.indexOf('?') === -1 ? '?' : '&';
          src = src.indexOf('wmode') === -1 ? src + sep + 'wmode=transparent' : src;
          video.attr('src', src);
        }
        video.wrap('<div class="oembed-wrapper" />');
        $(this).find('.oembed-wrapper').after('<div class="oembed-mask" />');
        $(this).find('.oembed-mask, .oembed-wrapper').css({ position : 'absolute', width : video.attr('width') + 'px', height : video.attr('height') + 'px' });
      });

      // Avoid videos over content
      $('.oembed-video iframe').attr('src', function(index, value) {
        var wmode_set = /wmode=transparent/g;

        if (wmode_set.test(value)) {
          return value;
        }
          
        var sep = value.indexOf('?') === -1 ? '?' : '&';

        return value + sep + 'wmode=transparent';
      });
      $('.oembed-video embed').attr('wmode', 'transparent');
      // close modal
      $('#close').click(function() {
        Drupal.CTools.Modal.dismiss();
        return false;
      });
      
      // Close modal by clicking outside it
      $('#modalBackdrop').click(function() {
        Drupal.CTools.Modal.dismiss();
      });

      // Show messages when an item is flagged/unflagged
      $(document).bind('flagGlobalAfterLinkUpdate', function(event, data) {
        Drupal.ajax.checkdesk_core_message_settings.setMessages();
        
        // Keep settings
        if (data.settings) {
          $.extend(true, Drupal.settings, data.settings);
        }
        
        // Run any other ajax command
        if (data.hasOwnProperty('commands')) {
          for (var i = 0; i < data.commands.length; i++) {
            if (data.commands[i]['command'] && Drupal.ajax.prototype.commands[data.commands[i]['command']]) {
              Drupal.ajax.prototype.commands[data.commands[i]['command']](Drupal.ajax.prototype, data.commands[i], data.status);
            }
          }
        }
        $('span.add-to').removeClass('open')
      });
      // Show throbber after change stories on node/add/post form.
      jQuery('#edit-submit-desk-reports').click(function () {
        jQuery('.view-filters .ajax-progress').remove();
        jQuery('.view-filters').append('<div class="ajax-progress"><div class="throbber">&nbsp;</div></div>');
      });
      //Bind auto-refresh update to hide embeded reports
        jQuery('#block-views-desk-reports-block').unbind('autorefresh_update');
        jQuery('#block-views-desk-reports-block').bind('autorefresh_update', function(e, nid) {
            //Add this value to trigger CKEDITOR instanceReady
            var instance = CKEDITOR.instances['edit-body-und-0-value'];
            instance.insertHtml(' ');
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
  
  /**
   * Handle cTools Modal events
   */
  Drupal.behaviors.ctoolsModalEvents = {
    attach: function(context) {  
      // Responds to link click with ctools applied
      $('a.ctools-use-modal').click(function() {
        $('body').addClass('modal-overflow-hidden');                    
      });
      // Responds to cTools modal close
      $(document).bind('CToolsDetachBehaviors', function() {
        $('body').removeClass('modal-overflow-hidden');                    
      });
    }
  }

  /**
   *  Command for `checkdesk_core_ajax_command_attach_behaviors`.
   */
  Drupal.ajax.prototype.commands.attachBehaviors = function(ajax, response, status) {
    Drupal.attachBehaviors(response.selector);
  };

  /**
   * Command to refresh Facebook embeds.
   */
  Drupal.ajax.prototype.commands.refreshFacebook = function(ajax, response, status) {
    if (typeof(FB) != 'undefined') {
      window.fbAsyncInit();
    }
  }

  // Custom client-side validations
  Drupal.behaviors.clientSideValidations = {
    attach: function (context) {
      $(document).bind('clientsideValidationAddCustomRules', function(event) {
        // Check if username or e-mail is taken
        jQuery.validator.addMethod('unique', function (value, element, param) {
          var result = false;
          jQuery.ajax({
            'url': Drupal.settings.basePath + 'checkdesk_validation/unique_field',
            'type': 'POST',
            'data': {
              'value' : value,
              'field' : $(element).attr('name'),
              'table' : param
            },
            'dataType': 'json',
            'async': false,
            'success': function(res) {
              result = res;
            }
          });
          if (result.result == false) {
            jQuery.extend(jQuery.validator.messages, {
              'unique': Drupal.t('unavailable')
            });
          }
          return result.result;
        }, jQuery.format(Drupal.t('unavailable')));

        // Show a success message if no error is found
        $('#user-register-form', context).find('input[type=text], input[type=password]').blur(function() {
          var id = $(this).attr('id'),
              $success = $('#user-register-form label[for=' + id + '].success', context);
          if (!$(this).hasClass('error')) {
            if ($success.length) {
              $success.show();
            }
            else {
              $(this).after($('<label />').attr('for', id).addClass('success').html(Drupal.t('good')));
            }
            $(this).addClass('success');
          }
          else {
            $(this).removeClass('success');
            $success.hide();
          }
        });
        // Special case for password field - message is displayed on confirmation field
        $('#user-register-form #edit-pass-pass1', context).blur(function() {
          var $confirmation = $('#user-register-form #edit-pass-pass2'),
              $success = $('#user-register-form label[for=edit-pass-pass2].success', context);
          if (($(this).val() != $confirmation.val()) && $success.length) {
            $confirmation.removeClass('success');
            $success.hide();
          }
        });
        // Check password as the user types
        $('#user-register-form', context).find('input[type=password]').keyup(function() {
          $(this).trigger('focusout');
          $(this).blur();
          $(this).focus();
        });

      });
    }
  }
}(jQuery));

function _checkdesk_report_view_redirect() {
  var title = jQuery('form#post-node-form input#edit-title').val();
  var placeholder = jQuery('form#post-node-form #edit-body #edit-body-und-0-value').attr('placeholder');
  var desc  = jQuery('form#post-node-form #edit-body iframe').contents().find('body').html();
  var modal = false;
  if (title) {
    modal = true;
  }
  if (desc && placeholder != desc) {
    modal = true;
  }
  if(modal) {
    return 'You have unsaved changes that will be lost if you decide to continue.';
  }
}


function _checkdesk_filter_reports(story_nid) {
    jQuery('#block-views-desk-reports-block').bind('ajaxComplete', function( event, xhr, settings ) {
        if (typeof settings.extraData != 'undefined' && settings.extraData.view_name == 'desk_reports') {
            //Add this value to trigger CKEDITOR instanceReady
            var instance = CKEDITOR.instances['edit-body-und-0-value'];
            instance.insertHtml(' ');
            //resize reports sidebar
            jQuery(window).trigger('resize');
        }
    });
    jQuery('select#edit-field-stories-target-id').val(story_nid);
    jQuery('#edit-submit-desk-reports').trigger('click');
}

jQuery(function() {
    jQuery('.flag-follow-story a.unflag-action').bind( "mouseenter", function() {
            jQuery(this).text(Drupal.t('Unfollow story'));
        })
        .bind( "mouseleave", function() {
            jQuery(this).text(Drupal.t('Following story'));
        });
});
