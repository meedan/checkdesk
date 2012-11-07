(function ($) {

Drupal.behaviors.comment_goodness = {
  attach: function (context) {
    $('form.comment-form div.field-name-comment-body div.text-format-wrapper iframe:not(.cgprocessed)').live('mouseover', function () {
      var $this = $(this);
      $this.addClass('cgprocessed');
      var ctx = $this.parents('div.text-format-wrapper');
      var textarea = $('textarea', ctx);
      $this.contents().find('html').bind('blur keyup paste', function () {
        var text = $('body', $(this)).text();
        textarea.val(text).keyup();
      });
    });
  }
};

})(jQuery);
