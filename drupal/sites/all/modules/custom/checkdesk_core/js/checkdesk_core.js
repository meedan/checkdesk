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
          var data = $(ui.draggable).parent().parent().parent().data('views');
          // Insert the report URL into the textarea of the post body.
          $('textarea', this).insertAtCaret("\n" + data.droppable_ref + "\n");
        },
      });
      // Attach the Views results to each correspoknding row in the DOM.
      var i=0;
      $('.view-desk-reports .view-content', context).children().each(function() {
        $(this).data('views', settings.checkdesk.reports[i++]);
      });
    }
  };

  Drupal.theme.prototype.CtoolsFaceStyle = function () {
    
    var html = '';
    html += '<div id="ctools-modal-checkdesk" class="popups-box">';
    html += '  <div class="ctools-modal-content ctools-modal-happy-modal-content">';
    html += '    <span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeImage + '</a></span>';
    html += '    <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
    html += '  </div>';
    html += '</div>';
    return html;
  }

})(jQuery);
