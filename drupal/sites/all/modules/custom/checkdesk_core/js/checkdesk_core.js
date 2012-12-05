(function ($) {

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
