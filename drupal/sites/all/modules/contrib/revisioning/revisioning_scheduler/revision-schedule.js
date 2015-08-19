(function ($) {

  /* This reflect the logic of revisioning_scheduler_node_presave().
   * Scheduling a publication date is only appropriate if:
   * o the node is NOT published
   * o the node is already published, but the new revision to be created goes in
   *   moderation, i.e will not be published yet
   */
  Drupal.behaviors.showPublicationDateTimeField = {
    attach: function (context) {
      var publishedBox = $('.form-item-status input');
      var newRevisionInModerationRadio = $('#edit-revision-operation-2');
      var publicationDate = $('.form-item-publication-date');

      // Page-load: hide the publication date textbox, if necessary
      if ((publishedBox.is(':checked') && !newRevisionInModerationRadio.is(':checked'))) {
        publicationDate.hide();
      }

      // Define handlers for clicks on the Published box and moderation radio buttons.
      publishedBox.click(function() {
        if (!publishedBox.is(':checked') || newRevisionInModerationRadio.is(':checked')) {
          publicationDate.show();
        }
        else {
          publicationDate.hide();
        }
      });
      $('#edit-revision-operation input').click(function() {
        if (!publishedBox.is(':checked') || newRevisionInModerationRadio.is(':checked')) {
          publicationDate.show();
        }
        else {
          publicationDate.hide();
        }
      });
    }
  };

})(jQuery);
