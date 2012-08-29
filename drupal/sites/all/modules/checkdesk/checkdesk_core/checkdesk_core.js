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
          $('textarea', event.target).insertAtCaret("\n [nid:" + data.nid + "]\n");
        },
      });
      // Attach the Views results to each correspoknding row in the DOM.
      var i=0;
      $('.view-desk-reports .view-content', context).children().each(function() {
        $(this).data('views', settings.checkdesk.reports[i++]);
      });
    }
  };

})(jQuery);
