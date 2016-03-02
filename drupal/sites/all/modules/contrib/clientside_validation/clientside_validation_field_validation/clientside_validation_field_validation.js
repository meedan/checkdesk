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
                      .replace("[length]", $element.val().length)
                      .replace("[field-name]", $element.closest(".form-item").find('label').first().text().replace(' *',''))
                  );
                }
              }
            };
          }
        }
      });
      // Add the ajax field validation handling.
      $(document).bind('clientsideValidationAddCustomRules', function(event){
        // Support for server side field validation.
        jQuery.validator.addMethod("fieldValidationAjax", function(value, element, params) {
          // Don't execute on every keyup!
          if (this.settings['name_event'] == 'onkeyup') {
            // Keep the current state until the next validation is run.
            return !(typeof this.invalid[element.name] != 'undefined');
          }

          // Use the built in remote function for validation - does the whole
          // async handling. Overwrite the data property to send the value and
          // rules. Don't adjust the value variable to keep the "previous"
          // handling working.
          var remote_param = {
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'js/clientside_validation_field_validation/validate',
            type: 'post',
            data: {
              fieldValidationAjax: {
                value: value,
                rules: params,
              },
              js_module: 'clientside_validation_field_validation',
              js_callback: 'validate',
              js_token: Drupal.settings.js && Drupal.settings.js.tokens && Drupal.settings.js.tokens['clientside_validation_field_validation-validate'] || ''
            }
          };
          return $.validator.methods.remote.call( this, value, element, remote_param);
        }, jQuery.format('Please fill in a valid value.'));
      });
    }
  };
})(jQuery);
