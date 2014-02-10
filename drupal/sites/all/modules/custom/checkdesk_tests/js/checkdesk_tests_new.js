/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

// Keep cursor in position after updating textarea
// Reference: http://stackoverflow.com/questions/13949059/persisting-the-changes-of-range-objects-after-selection-in-html/13950376#13950376
var saveSelection, restoreSelection;

if (window.getSelection && document.createRange) {
  saveSelection = function(containerEl) {
    var range = window.getSelection().getRangeAt(0);
    var preSelectionRange = range.cloneRange();
    preSelectionRange.selectNodeContents(containerEl);
    preSelectionRange.setEnd(range.startContainer, range.startOffset);
    var start = preSelectionRange.toString().length;

    return {
      start: start,
      end: start + range.toString().length
    };
  };

  restoreSelection = function(containerEl, savedSel) {
    var charIndex = 0, range = document.createRange();
    range.setStart(containerEl, 0);
    range.collapse(true);
    var nodeStack = [containerEl], node, foundStart = false, stop = false;

    while (!stop && (node = nodeStack.pop())) {
      if (node.nodeType == 3) {
        var nextCharIndex = charIndex + node.length;
        if (!foundStart && savedSel.start >= charIndex && savedSel.start <= nextCharIndex) {
          range.setStart(node, savedSel.start - charIndex);
          foundStart = true;
        }
        if (foundStart && savedSel.end >= charIndex && savedSel.end <= nextCharIndex) {
          range.setEnd(node, savedSel.end - charIndex);
          stop = true;
        }
        charIndex = nextCharIndex;
      } else {
        var i = node.childNodes.length;
        while (i--) {
          nodeStack.push(node.childNodes[i]);
        }
      }
    }

    var sel = window.getSelection();
    sel.removeAllRanges();
    sel.addRange(range);
  }
}
else if (document.selection) {
  saveSelection = function(containerEl) {
    var selectedTextRange = document.selection.createRange();
    var preSelectionTextRange = document.body.createTextRange();
    preSelectionTextRange.moveToElementText(containerEl);
    preSelectionTextRange.setEndPoint("EndToStart", selectedTextRange);
    var start = preSelectionTextRange.text.length;
 
    return {
      start: start,
      end: start + selectedTextRange.text.length
    }
  };

  restoreSelection = function(containerEl, savedSel) {
    var textRange = document.body.createTextRange();
    textRange.moveToElementText(containerEl);
    textRange.collapse(true);
    textRange.moveEnd("character", savedSel.end);
    textRange.moveStart("character", savedSel.start);
    textRange.select();
  };
}

(function($) {
  'use strict';

  // Display available steps on a modal window
  $(window).load(function() {
    $('#checkdesk-tests-steps-link').click(function() {
      $('#checkdesk-tests-steps').modal();
      return false;
    });
  });

  // Replace step fields by rich text fields

  var syntaxHighlight = function(text) {
    return text.replace(/((\([^\)]*\))|("[a-zA-Z0-9 ]*"))/g, '<span class="step-param">$1</span>')
               .replace(/([\|:])\|/g, '$1<br />|')
               .replace(/\|(.*)\|/, '<pre class="step-param">|$1|</pre>')
               .replace(/\|/g, '<span class="step-no-param">|</span>');
  };

  Drupal.behaviors.enrichStepFields = {
    attach: function(context, settings) {

      $('#checkdesk-tests-new-steps .form-text:not(.form-rich-processed)', context).each(function() {
        
        var id       = $(this).attr('id') + '-rich',
            $rich    = $('<div id="' + id + '" contenteditable="true" class="form-rich step-no-param" />'),
            $plain   = $(this),
            $wrapper = $('<div id="' + id + '-wrapper" class="field-rich-wrapper" />');
        
        $plain.after($rich);
        $plain.addClass('form-rich-processed');
        $rich.html(syntaxHighlight($plain.val()));
        $([$plain[0], $rich[0]]).wrapAll($wrapper);
        $rich.parents('.field-rich-wrapper').height($rich.height() - 2);
        
        $rich.keyup(function() {
          var text = $(this).text();
          var savedSel = saveSelection(this);
          $(this).parents('.field-rich-wrapper').height($(this).height() - 2);
          $plain.val(text);
          $(this).html(syntaxHighlight(text));
          $(this).focus();
          restoreSelection(this, savedSel);
          $plain.keyup(); // In order to trigger auto-complete
        });
      });

      // Make autocomplete work
      var $autocomplete = $('#checkdesk-tests-new-steps #autocomplete', context);

      $autocomplete.find('li').live('click', function() {

        var text   = $(this).text(),
            $plain = $(this).parents('.field-rich-wrapper').find('.form-text'),
            $rich  = $(this).parents('.field-rich-wrapper').find('.form-rich');

        if (/:$/.test(text)) {
          text += "| attribute | attribute || value     | value     |";
        }

        $plain.val(text);
        $rich.html(syntaxHighlight(text));
        $(this).parents('.field-rich-wrapper').height($rich.height() - 2);
        $(this).parents('#autocomplete').remove();
      });
    }
  };

}(jQuery));
