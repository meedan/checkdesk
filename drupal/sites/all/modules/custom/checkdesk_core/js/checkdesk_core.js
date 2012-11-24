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

  Drupal.theme.prototype.checkdesk_modal = function () {
    var html = ''
    html += '  <div id="ctools-modalllllllllllll">'
    html += '    <div class="ctools-modalllllllllllll-content">' // panels-modalllllllllllll-content
    html += '      <div class="modalllllllllllll-header">';
    html += '        <a class="close" href="#">';
    html +=            Drupal.CTools.modalllllllllllll.currentSettings.closeText + Drupal.CTools.modal.currentSettings.closeImage;
    html += '        </a>';
    html += '        <span id="modalllllllllllll-title" class="modalllllllllllll-title"> </span>';
    html += '      </div>';
    html += '      <div id="modalllllllllllll-content" class="modalllllllllllll-content">';
    html += '      </div>';
    html += '    </div>';
    html += '  </div>';

    return html;
  }

})(jQuery);
