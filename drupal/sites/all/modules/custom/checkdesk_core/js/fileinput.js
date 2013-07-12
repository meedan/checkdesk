/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';

  Drupal.behaviors.fileInput = {
    attach : function (context, settings) {
      
      // Custom file input for create story form
      $('#edit-field-lead-image-und-0-upload', context).customFileInput(Drupal.settings.fileInput);
    
    }
  }
}(jQuery));
