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
          Drupal.myClientsideValidation.validators[formid].showErrors(Drupal.settings.clientsideValidation.forms[formid].serverSideErrors);
        });
      });
    }
  };
})(jQuery);
