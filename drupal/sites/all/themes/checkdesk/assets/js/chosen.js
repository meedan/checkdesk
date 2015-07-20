/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
	'use strict';

  // format select element
  Drupal.behaviors.customSelect = {
    attach: function(context) {
      // apply js plugin
      $('#edit-field-stories-und').chosen();
      $('#edit-field-desk-und').chosen();
    }
  };

}(jQuery));
