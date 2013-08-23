/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * File:        clientside_validation_html5.js
 * Version:     7.x-1.x
 * Description: Add clientside validation rules
 * Author:      Attiks
 * Language:    Javascript
 * Project:     clientside_validation html5
 * @module clientside_validation
 */

(/** @lends Drupal */function ($) {
  "use strict";
  /**
   * Drupal.behaviors.clientsideValidationHtml5.
   *
   * Attach clientside validation to the page for HTML5.
   */
  Drupal.behaviors.clientsideValidationHtml5 = {
    attach: function () {
      $(document).bind('clientsideValidationAddCustomRules', function(){
        /**
         * HTML5 specific rules.
         * @name _bindHTML5Rules
         * @memberof Drupal.clientsideValidation
         * @method
         * @private
         */
        function _getMultiplier(a, b, c) {
          var inta = Number(parseInt(a, 10));
          var mula = a.length - inta.toString().length - 1;

          var intb = parseInt(b, 10);
          var mulb = b.toString().length - intb.toString().length - 1;

          var intc = parseInt(c, 10);
          var mulc = c.toString().length - intc.toString().length - 1;

          var multiplier = Math.pow(10, Math.max(mulc, Math.max(mula, mulb)));
          return (multiplier > 1) ? multiplier : 1;
        }

        jQuery.validator.addMethod("Html5Min", function(value, element, param) {
          //param[0] = min, param[1] = step;
          var min = param[0];
          var step = param[1];
          var multiplier = _getMultiplier(value, min, step);

          value = parseInt(parseFloat(value) * multiplier, 10);
          min = parseInt(parseFloat(min) * multiplier, 10);

          var mismatch = 0;
          if (param[1] !== 'any') {
            step = parseInt(parseFloat(param[1]) * multiplier, 10);
            mismatch = (value - min) % step;
          }
          return this.optional(element) || (mismatch === 0 && value >= min);
        }, jQuery.format('Value must be greater than {0} with steps of {1}.'));

        jQuery.validator.addMethod("Html5Max", function(value, element, param) {
          //param[0] = max, param[1] = step;
          var max = param[0];
          var step = param[1];
          var multiplier = _getMultiplier(value, max, step);

          value = parseInt(parseFloat(value) * multiplier, 10);
          max = parseInt(parseFloat(max) * multiplier, 10);

          var mismatch = 0;
          if (param[1] !== 'any') {
            step = parseInt(parseFloat(param[1]) * multiplier, 10);
            mismatch = (max - value) % step;
          }
          return this.optional(element) || (mismatch === 0 && value <= max);
        }, jQuery.format('Value must be smaller than {0} and must be dividable by {1}.'));

        jQuery.validator.addMethod("Html5Range", function(value, element, param) {
          //param[0] = min, param[1] = max, param[2] = step;
          var min = param[0];
          var max = param[1];
          var step = param[2];
          var multiplier = _getMultiplier(value, min, step);

          value = parseInt(parseFloat(value) * multiplier, 10);
          min = parseInt(parseFloat(min) * multiplier, 10);
          max = parseInt(parseFloat(max) * multiplier, 10);

          var mismatch = 0;
          if (param[2] !== 'any') {
            step = parseInt(parseFloat(param[2]) * multiplier, 10);
            mismatch = (value - min) % step;
          }
          return this.optional(element) || (mismatch === 0 && value >= min && value <= max);
        }, jQuery.format('Value must be greater than {0} with steps of {2} and smaller than {1}.'));

        jQuery.validator.addMethod("Html5Color", function(value) {
          return (/^#([a-f]|[A-F]|[0-9]){6}$/).test(value);
        }, jQuery.format('Value must be a valid color code'));
      });
    }
  };
})(jQuery);
