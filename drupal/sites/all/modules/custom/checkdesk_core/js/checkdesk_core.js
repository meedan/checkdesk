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

  Drupal.behaviors.checkdeskModal = {
  attach: function (context){

    // Make modal window height scaled automatically.
    $('.ctools-modal-content, #modal-content', context).height('auto');

    // Position code lifted from http://www.quirksmode.org/viewport/compatibility.html
    if (self.pageYOffset) { // all except Explorer
      var wt = self.pageYOffset;
    }
    else if (document.documentElement && document.documentElement.scrollTop) { // Explorer 6 Strict
      var wt = document.documentElement.scrollTop;
    }
    else if (document.body) { // all other Explorers
      var wt = document.body.scrollTop;
    }

    // Fix CTools bug: calculate correct 'top' value.
    var mdcTop = wt + ( $(window).height() / 2 ) - ($('#modalContent', context).outerHeight() / 2);
    $('#modalContent', context).css({top: mdcTop + 'px'});
  }
}

  Drupal.theme.prototype.checkdesk_modal_style = {
    attach: function (context){ 
    var html = '';
    html += '<div id="ctools-modal-checkdesk" class="popups-box">';
    html += '  <div class="ctools-modal-content ctools-modal-happy-modal-content">';
    html += '    <span class="popups-close"><a class="close" href="#"></a></span>';
    html += '    <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
    html += '  </div>';
    html += '</div>';
    return html;
  }
}

})(jQuery);
