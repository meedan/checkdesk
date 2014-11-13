/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

(function($) {
  'use strict';

  var undoRemoveStep = function($wrapper) {
    $wrapper.find('.form-text, .form-textarea').each(function() {
      $(this).val($(this).attr('data-old-value'));
    });
    $wrapper.find('.fieldset-wrapper:first').show();
    var $a = $wrapper.find('.demo-tour-remove-step');
    $a.html(Drupal.t('Remove step'));
    $a.unbind('click');
    $a.click(function() {
      removeStep($wrapper);
      return false;
    });
  };

  var removeStep = function($wrapper) {
    if (confirm(Drupal.t('Are you sure?'))) {
      $wrapper.find('.fieldset-wrapper:first').hide();
      $wrapper.find('.form-text, .form-textarea').each(function() {
        $(this).attr('data-old-value', $(this).val());
        $(this).val('');
      });
      var $a = $wrapper.find('.demo-tour-remove-step');
      $a.html(Drupal.t('Undo remove step'));
      $a.unbind('click');
      $a.click(function() {
        undoRemoveStep($wrapper);
        return false;
      });
    }
    return false;
  };

  var addRemovalLinks = function(context) {
    $('.edit-steps fieldset', context).each(function() {
      var $wrapper = $(this);
      if ($wrapper.find('.demo-tour-remove-step').length == 0) {
        var $link = $('<a href="#" class="demo-tour-remove-step"></a>');
        $link.html(Drupal.t('Remove this step'));
        $link.click(function() {
          removeStep($wrapper);
          return false;
        });
        $wrapper.append($link);
      }
    });
  };

  $(window).load(function() {
    addRemovalLinks(document);
  });

  Drupal.behaviors.tourForm = {
    attach: function(context, settings) {
      addRemovalLinks(context);
    }
  };

}(jQuery));
