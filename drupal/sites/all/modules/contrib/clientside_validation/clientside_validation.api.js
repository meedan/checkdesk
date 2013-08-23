/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * @file
 * Javascript api documentation for Clientside Validation.
 */
/**
 * It speaks for itself that Clientside Validation cannot provide javascript
 * validation codes for custom validation rules defined in php. So if you want
 * to support Clientside Validation you will have to code the javascript
 * equivalent of your custom php validation rule and make it available for
 * Clientside validation. Below is an example of how you would do this.
 *
 * The second block of code is an example of how to define a custom errorplacement function.
 * You can set this option in admin/config/validation/clientside_validation
 */
//jQuery wrapper
(function ($) {
  "use strict";
  //Define a Drupal behaviour with a custom name
  Drupal.behaviors.myModuleBehavior = {
    attach: function (context) {
      //Add an eventlistener to the document reacting on the
      //'clientsideValidationAddCustomRules' event.
      $(document).bind('clientsideValidationAddCustomRules', function(event){
        //Add your custom method with the 'addMethod' function of jQuery.validator
        //http://docs.jquery.com/Plugins/Validation/Validator/addMethod#namemethodmessage
        jQuery.validator.addMethod("myCustomMethod", function(value, element, param) {
          //let an element match an exact value defined by the user
          return value === param;
          //Enter a default error message, numbers between {} will be replaced
          //with the matching value of that key in the param array, enter {0} if
          //param is a value and not an array.
        }, jQuery.format('Value must be equal to {0}'));
      });

      // According to this example you would fill in 'mycustomerrorplacement' for the custom
      // error placement function at admin/config/validation/clientside_validation
      // The declaration of this function needs to be within the attach of a Drupal behavior.
      Drupal.clientsideValidation.prototype.mycustomerrorplacement = function (error, element) {
        // error placement code here.
      };
    }
  };
})(jQuery);
