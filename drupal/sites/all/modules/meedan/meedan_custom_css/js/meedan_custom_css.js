/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */

jQuery(function($) {
  'use strict';

  // Unobstrusive syntax highlighting
  var $textarea = $('#meedan-custom-css-textarea');

  var createEditor= function() {
    var editor = CodeMirror.fromTextArea($textarea[0], { lineNumbers : true });
    editor.on('change', function(obj) { autoPreview(); });
    return editor;
  };

  var editor = createEditor();

  $textarea.before('<input type="checkbox" id="meedan-custom-css-toggle-editor" /> <label for="meedan-custom-css-toggle-editor">' + Drupal.t('Use plain text editor') + '</label>');

  $('#meedan-custom-css-toggle-editor').click(function() {
    if ($(this).is(':checked')) {
      editor.toTextArea();
    }
    else {
      editor = createEditor(); 
    }
  });
 
  // Preview
  var $preview = $('#meedan-custom-css-preview');
  $textarea.before('<input type="checkbox" id="meedan-custom-css-toggle-preview" checked="checked" /> <label for="meedan-custom-css-toggle-preview">' + Drupal.t('Enable auto preview.') + '</label> <span>' + Drupal.t('Preview path:') + '</span> <input type="text" id="meedan-custom-css-preview-path" size="60" value="' + Drupal.settings.meedanCustomCSS.previewPath + '" />');

  $('#meedan-custom-css-toggle-preview').click(function() {
    if ($(this).is(':checked')) {
      $preview.show();
      autoPreview();
    }
    else {
      $preview.hide();
    }
  });

  $textarea.keyup(function() { autoPreview(); });

  $preview.load(function() { autoPreview(); });

  $('#meedan-custom-css-preview-path').blur(function() {
    var oldpath = Drupal.settings.meedanCustomCSS.previewPath,
        newpath = $(this).val();
    Drupal.settings.meedanCustomCSS.previewPath = newpath;
    $preview.attr('src', $preview.attr('src').replace(oldpath, newpath));
  });

  var autoPreview = function() {
    if ($('#meedan-custom-css-toggle-preview').is(':checked')) {
      var value = ($('#meedan-custom-css-toggle-editor').is(':checked') ? $textarea.val() : editor.getValue()); 
      var id = 'meedan-custom-css-preview-style';
      var $css = $preview.contents().find('#' + id);
      if ($css.length) {
        $css.html(value);
      }
      else {
        $preview.contents().find('head').append($('<style type="text/css" id="' + id + '">' + value + '</style>'));
      }
    }
  };

});
