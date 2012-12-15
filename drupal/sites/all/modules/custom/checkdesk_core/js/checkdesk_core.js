(function ($) {

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
  message_settings.url = '/checkdesk/drupal/core/messages/ajax/';
  message_settings.event = 'onload';
  message_settings.keypress = false;
  message_settings.prevent = false;
  Drupal.ajax['checkdesk_core_message_settings'] = new Drupal.ajax(null, $(document.body), message_settings);

  Drupal.behaviors.checkdesk = {
    attach: function (context, settings) {

      $('.draggable', context).draggable({
        revert: 'invalid',
        zIndex: 3000,
      });
      $('.droppable', context).droppable({
        hoverClass: 'drop-hover',
        accept: '.draggable',  
        drop: function(event, ui) {
          $(ui.draggable).hide();
          // Retrieve the Views information from the DOM.
          var data = $(ui.draggable).data('views');
          // Insert the report URL into the textarea of the post body.
          $('textarea', this).insertAtCaret("\n" + data.droppable_ref + "\n");
        },
      });
      // Attach the Views results to each correspoknding row in the DOM.
      var i=0;
      $('.view-desk-reports .view-content', context).children().each(function() {
        $(this).data('views', settings.checkdesk.reports[i++]);
      });
      // Restrict thumbnail width to 220
      jQuery('.view-desk-reports .view-content').find('.thumbnail img').width(220);


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
        console.log(data);
        Drupal.ajax['checkdesk_core_message_settings'].setMessages();
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

  }

})(jQuery);
