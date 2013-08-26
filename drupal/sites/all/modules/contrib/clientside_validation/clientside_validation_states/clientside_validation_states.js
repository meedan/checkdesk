/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * File:        clientside_validation_states.js
 * Version:     7.x-1.x
 * Description: Add clientside validation rules
 * Author:      Attiks
 * Language:    Javascript
 * Project:     clientside_validation_states
 * @module clientside_validation
 */

(/** @lends Drupal */function ($) {
  "use strict";
  /**
   * Drupal.behaviors.clientsideValidationStates.
   *
   * Attach clientside validation to the page for states.
   */
  Drupal.behaviors.clientsideValidationStates = {
    attach: function () {
      function statesrequired (el) {
        var required = $(el).closest('.form-item, .form-wrapper').find('.form-required').length;
        return required !== 0;
      }
      $(document).bind('state:required', function(e) {
        if (e.trigger) {
          $(e.target).valid();
        }
      });
      $(document).bind('clientsideValidationInitialized', function(){
        for (var formid in Drupal.myClientsideValidation.forms) {
          if (Drupal.myClientsideValidation.forms.hasOwnProperty(formid)) {
            for (var element in Drupal.myClientsideValidation.forms[formid].rules) {
              if (Drupal.myClientsideValidation.forms[formid].rules.hasOwnProperty(element)) {
                for (var rulename in Drupal.myClientsideValidation.forms[formid].rules[element]) {
                  if (Drupal.myClientsideValidation.forms[formid].rules[element].hasOwnProperty(rulename) && rulename === 'statesrequired') {
                    var selector = ':input[name="' + element + '"]';
                    $(selector).rules("remove", "statesrequired");
                    $(selector).rules("add", {
                      required: statesrequired
                    });
                  }
                }
              }
            }
          }
        }
      });
    }
  };
})(jQuery);
