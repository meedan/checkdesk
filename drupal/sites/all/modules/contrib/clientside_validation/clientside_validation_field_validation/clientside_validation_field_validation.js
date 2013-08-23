/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * File:        clientside_validation_field_valdiation.js
 * Version:     7.x-1.x
 * Description: Replace field validation's error message placeholders with their values.
 * Author:      Attiks
 * Language:    Javascript
 * Project:     clientside_validation_field_valdiation
 * @module clientside_validation
 */

(/** @lends Drupal */function ($) {
  "use strict";
  /**
   * Drupal.behaviors.clientsideValidationFieldValidation.
   *
   * Attach behavior for replacing field validation's error message placeholders
   * with their values.
   */
  Drupal.behaviors.clientsideValidationFieldValidation = {
    attach: function () {
      $(document).bind('clientsideValidationInitialized', function(){
        for (var formid in Drupal.myClientsideValidation.validators) {
          if (Drupal.myClientsideValidation.validators.hasOwnProperty(formid)) {
            Drupal.myClientsideValidation.validators[formid].settings.showErrors = function (errorMap, errorList) {
              this.defaultShowErrors();
              for (var index in errorList) {
                var $element = $(errorList[index].element);
                var label = this.errorsFor(errorList[index].element);
                if ( label.length ) {
                  label.html(
                    label.html()
                      .replace("[value]", $element.val())
                      .replace("[field-name]", $element.closest(".form-item").find('label').text())
                  );
                }
              }
            }
          }
        }
      });
    }
  };
})(jQuery);
