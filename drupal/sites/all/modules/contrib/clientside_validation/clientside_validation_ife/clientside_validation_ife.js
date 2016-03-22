/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * File:        clientside_validation_ife.js
 * Version:     7.x-1.x
 * Description: Add clientside validation rules
 * Author:      Attiks
 * Language:    Javascript
 * Project:     clientside_validation ife
 * @module clientside_validation
 */

(/** @lends Drupal */function ($) {
  "use strict";
  /**
   * Drupal.behaviors.clientsideValidationHtml5.
   *
   * Attach clientside validation to the page for HTML5.
   */
  Drupal.behaviors.clientsideValidationIfe = {
    attach: function () {
      $(document).bind('clientsideValidationInitialized', function (){
        /**
         * IFE specific rules.
         * @name _bindIfeRules
         * @memberof Drupal.clientsideValidation
         * @method
         * @private
         */
        jQuery.each(Drupal.myClientsideValidation.validators, function (formid) {
          if (
            !Drupal.settings.clientsideValidation.forms.hasOwnProperty(formid) ||
              !Drupal.settings.clientsideValidation.forms[formid].hasOwnProperty('serverSideErrors')
            ) {
            return;
          }
          var errors = Drupal.settings.clientsideValidation.forms[formid].serverSideErrors;

          for(var error in errors) {
            if(!errors[error]) { delete errors[error]; }
          }

          if ($.isEmptyObject(errors)) {
            return;
          }

          Drupal.myClientsideValidation.validators[formid].showErrors(errors);
        });
      });
    }
  };
})(jQuery);
