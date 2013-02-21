(function ($) {
// START jQuery

Drupal.livefyre = {
  el: 'livefyre-current', // Reference to the container in which LiveFyre comments are loaded
  widget: null, // Reference to the object created by LiveFyre
  callback: function(widget) {
    if (!Drupal.livefyre.widget) Drupal.livefyre.widget = widget;
    widget.on('initialRenderComplete', function(data) {
      $('.livefyre-loading').remove();
      if ($('.livefyre-comments:visible').length) $('html, body').animate({ scrollTop : $('.livefyre-comments:visible').prev('.livefyre-header').offset().top }, 1000);
    });
    widget.on('commentCountUpdated', function(data) {
      $('.livefyre-comments:visible').prev('.livefyre-header').find('.livefyre-commentcount').html(Drupal.formatPlural(data, '1 comment', '@count comments'));
    });
  }
}

Drupal.behaviors.livefyre = {
  attach: function(context, settings) {
    try {

      // Show or hide comments
      $('.livefyre-header').die('click').live('click', function() {
        var comments = $('.livefyre-comments', $(this).parent());
        if (comments.is(':visible')) {
          comments.hide();
        }
        else {
          $('.livefyre-comments').hide();
          $(this).append('<span class="livefyre-loading"><em> (' + Drupal.t('loading...') + ')</em></span>');
          var key = 'livefyre-' + comments.attr('data-nid');
          var stream = Drupal.settings.livefyre[key].streamConfig;
          stream.el = Drupal.livefyre.el;
          $('#' + stream.el).attr('id', 'livefyre-' + $('#' + stream.el).attr('data-nid'));
          comments.attr('id', stream.el);

          if (window.FyreLoader) {
            Drupal.livefyre.widget.changeCollection(stream);
          }
          
          else {
            fyre.conv.load(
              {},
              [stream],
              Drupal.livefyre.callback 
            );
          }

          comments.show();
        }
      });

    // Catch exceptions
    } catch(error) {
      console.log('Error while attaching Livefyre');
      if (error) console.log(error.toString());
    }
  }
}

// Overwrite method from Livefyre
var i = window.setInterval(function() { waitForGoogEditor(); }, 1000);
var waitForGoogEditor = function() {
  if (window.goog.editor) {
    window.clearInterval(i);

    // This method was causing an unrecoverable error on Firefox and Opera, so it is overwritten here
    window.goog.editor.Field.prototype.makeUneditable = function(a) {
      if (this.isUneditable()) throw Error("makeUneditable: Field is already uneditable");
      this.clearDelayedChange();
      if (this.selectionChangeTimer_) this.selectionChangeTimer_.fireIfActive(); // Just added a condition on this line
      this.execCommand(goog.editor.Command.CLEAR_LOREM);
      var b = null;
      !a && this.getElement() && (b = ''); // Changed b value here
      this.clearFieldLoadListener_();
      a = this.getOriginalElement();
      goog.editor.Field.getActiveFieldId() == a.id && goog.editor.Field.setActiveFieldId(null);
      this.clearListeners_();
      goog.isString(b) && (a.innerHTML = b, this.resetOriginalElemProperties());
      this.restoreDom();
      this.tearDownFieldObject_();
      goog.userAgent.WEBKIT && a.blur();
      this.execCommand(goog.editor.Command.UPDATE_LOREM);
      this.dispatchEvent(goog.editor.Field.EventType.UNLOAD)
    };

  }
};

// END jQuery
})(jQuery);
