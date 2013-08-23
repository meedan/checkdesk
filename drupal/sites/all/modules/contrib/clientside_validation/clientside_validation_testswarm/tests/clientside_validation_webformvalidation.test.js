/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true, QUnit:true*/
(function ($, Drupal, window, document, undefined) {
  "use strict";
  /**
   * Field Validation.
   */
  var validator = {};
  $(document).bind('clientsideValidationInitialized', function(){
    var formid = Drupal.settings.clientsideValidationTestswarm.formID;
    validator = Drupal.myClientsideValidation.validators[formid];
  });
  Drupal.tests.cvwebformvalidation = {
    getInfo: function() {
      return {
        name: Drupal.t('Clientside Validation Webform Validation'),
        description: Drupal.t('Test Clientside Validation Webform Validation.'),
        group: Drupal.t('Clientside Validation')
      };
    },
    tests: {
      regex: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-regex].error:visible').length, 1, Drupal.t('Error label found for "Regex"'));

          // Fill in the field with an illegal value (this regex only allows alphanumerics and underscores).
          $('#edit-submitted-regex').val("abc_123*");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-regex].error:visible').length, 1, Drupal.t('Error label found for "Regex"'));

          // Fill in the field with valid value.
          $('#edit-submitted-regex').val("abc_123");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-regex].error:visible').length, 0, Drupal.t('Error label not found for "Regex"'));
        };
      },
      minLength: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Min length" error.
          QUnit.equal($('label[for=edit-submitted-min-length].error:visible').length, 1, Drupal.t('Error label found for "Min length"'));

          // Fill in the "Min length" with a value that is too short.
          $('#edit-submitted-min-length').val('123');

          // Validate the form.
          validator.form();

          // Check for the "Min length" error.
          QUnit.equal($('label[for=edit-submitted-min-length].error:visible').length, 1, Drupal.t('Error label found for "Min length"'));


          // Fill in the "Min length" with a valid value.
          $('#edit-submitted-min-length').val('123456');

          // Validate the form.
          validator.form();

          // Check for the "Min length" error.
          QUnit.equal($('label[for=edit-submitted-min-length].error:visible').length, 0, Drupal.t('Error label not found for "Min length"'));
        };
      },
      maxLength: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Max length" error.
          QUnit.equal($('label[for=edit-submitted-max-length].error:visible').length, 1, Drupal.t('Error label found for "Max length"'));

          // Fill in the "Max length" with a value that is too long.
          $('#edit-submitted-max-length').val('1234567890abc');

          // Validate the form.
          validator.form();

          // Check for the "Max length" error.
          QUnit.equal($('label[for=edit-submitted-max-length].error:visible').length, 1, Drupal.t('Error label found for "Max length"'));


          // Fill in the "Max length" with a valid value.
          $('#edit-submitted-max-length').val('123456');

          // Validate the form.
          validator.form();

          // Check for the "Max length" error.
          QUnit.equal($('label[for=edit-submitted-max-length].error:visible').length, 0, Drupal.t('Error label not found for "Max length"'));
        };
      },
      minWords: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Min words" error.
          QUnit.equal($('label[for=edit-submitted-min-words].error:visible').length, 1, Drupal.t('Error label found for "Min words"'));

          // Fill in the "Min words" with a value that is too short.
          $('#edit-submitted-min-words').val('one  two three four');

          // Validate the form.
          validator.form();

          // Check for the "Min words" error.
          QUnit.equal($('label[for=edit-submitted-min-words].error:visible').length, 1, Drupal.t('Error label found for "Min words"'));


          // Fill in the "Min words" with a valid value.
          $('#edit-submitted-min-words').val('one two three four five');

          // Validate the form.
          validator.form();

          // Check for the "Min length" error.
          QUnit.equal($('label[for=edit-submitted-min-words].error:visible').length, 0, Drupal.t('Error label not found for "Min words"'));
        };
      },
      maxWords: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Max words" error.
          QUnit.equal($('label[for=edit-submitted-max-words].error:visible').length, 1, Drupal.t('Error label found for "Max words"'));

          // Fill in the "Max words" with a value that is too long.
          $('#edit-submitted-max-words').val('one  two three four five six seven eight nine ten eleven');

          // Validate the form.
          validator.form();

          // Check for the "Max words" error.
          QUnit.equal($('label[for=edit-submitted-max-words].error:visible').length, 1, Drupal.t('Error label found for "Max words"'));


          // Fill in the "Max words" with a valid value.
          $('#edit-submitted-max-words').val('one two three four five');

          // Validate the form.
          validator.form();

          // Check for the "Max length" error.
          QUnit.equal($('label[for=edit-submitted-max-words].error:visible').length, 0, Drupal.t('Error label not found for "Max words"'));
        };
      },
      numeric: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the empty form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-submitted-numeric].error:visible').length, 1, Drupal.t('Error label found for "Numeric"'));

          // Fill in the "Numeric" textfield with a letter.
          $('#edit-submitted-numeric').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-submitted-numeric].error:visible').length, 1, Drupal.t('Error label found for "Numeric"'));

          // Fill in the "Numeric" textfield with a valid number
          $('#edit-submitted-numeric').val("1.5");

          // Validate the form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-submitted-numeric].error:visible').length, 0, Drupal.t('Error label not found for "Numeric"'));
        };
      },
      numericMin: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(4);
          // Validate the empty form.
          validator.form();

          // Check for the "Numeric min" error.
          QUnit.equal($('label[for=edit-submitted-numeric-min].error:visible').length, 1, Drupal.t('Error label found for "Numeric min"'));

          // Fill in the "Numeric min" textfield with a letter.
          $('#edit-submitted-numeric-min').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Numeric min" error.
          QUnit.equal($('label[for=edit-submitted-numeric-min].error:visible').length, 1, Drupal.t('Error label found for "Numeric min"'));

          // Fill in the "Numeric min" textfield with a number that is too low.
          $('#edit-submitted-numeric-min').val("1");

          // Validate the form.
          validator.form();

          // Check for the "Numeric min" error.
          QUnit.equal($('label[for=edit-submitted-numeric-min].error:visible').length, 1, Drupal.t('Error label found for "Numeric min"'));

           // Fill in the "Numeric min" textfield with a valid number.
          $('#edit-submitted-numeric-min').val("6");

          // Validate the form.
          validator.form();

          // Check for the "Numeric min" error.
          QUnit.equal($('label[for=edit-submitted-numeric-min].error:visible').length, 0, Drupal.t('Error label not found for "Numeric min"'));
        };
      },
      numericMax: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(4);
          // Validate the empty form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-submitted-numeric-max].error:visible').length, 1, Drupal.t('Error label found for "Numeric max"'));

          // Fill in the "Numeric max" textfield with a letter.
          $('#edit-submitted-numeric-max').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-submitted-numeric-max].error:visible').length, 1, Drupal.t('Error label found for "Numeric max"'));

          // Fill in the "Numeric max" textfield with a number that is too high.
          $('#edit-submitted-numeric-max').val("12");

          // Validate the form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-submitted-numeric-max].error:visible').length, 1, Drupal.t('Error label found for "Numeric max"'));

           // Fill in the "Numeric max" textfield with a valid number.
          $('#edit-submitted-numeric-max').val("6");

          // Validate the form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-submitted-numeric-max].error:visible').length, 0, Drupal.t('Error label not found for "Numeric max"'));
        };
      },
      requireOneOf: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(24);
          // Validate the empty form.
          validator.form();

          // Check for the "Requireone 1", "Requireone 2" and "Requireone 3" errors.
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-1].error:visible').length, 1, Drupal.t('Error label found for "Requireone 1"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-2].error:visible').length, 1, Drupal.t('Error label found for "Requireone 2"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-3].error:visible').length, 1, Drupal.t('Error label found for "Requireone 3"'));

          // Fill in a value in "Requireone 1".
          $('#edit-submitted-requireone-fieldset-requireone-1').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Requireone 1", "Requireone 2" and "Requireone 3" errors.
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-1].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 1"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-2].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 2"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-3].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 3"'));

          // Clear the value of "Requireone 1".
          $('#edit-submitted-requireone-fieldset-requireone-1').val("");

          // Validate the form.
          validator.form();

          // Check for the "Requireone 1", "Requireone 2" and "Requireone 3" errors.
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-1].error:visible').length, 1, Drupal.t('Error label found for "Requireone 1"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-2].error:visible').length, 1, Drupal.t('Error label found for "Requireone 2"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-3].error:visible').length, 1, Drupal.t('Error label found for "Requireone 3"'));

          // Fill in a value in "Requireone 2".
          $('#edit-submitted-requireone-fieldset-requireone-2').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Requireone 1", "Requireone 2" and "Requireone 3" errors.
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-1].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 1"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-2].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 2"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-3].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 3"'));

          // Clear the value of "Requireone 2".
          $('#edit-submitted-requireone-fieldset-requireone-2').val("");

          // Validate the form.
          validator.form();

          // Check for the "Requireone 1", "Requireone 2" and "Requireone 3" errors.
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-1].error:visible').length, 1, Drupal.t('Error label found for "Requireone 1"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-2].error:visible').length, 1, Drupal.t('Error label found for "Requireone 2"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-3].error:visible').length, 1, Drupal.t('Error label found for "Requireone 3"'));

          // Fill in a value in "Requireone 3".
          $('#edit-submitted-requireone-fieldset-requireone-3').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Requireone 1", "Requireone 2" and "Requireone 3" errors.
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-1].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 1"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-2].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 2"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-3].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 3"'));

          // Clear the value of "Requireone 3".
          $('#edit-submitted-requireone-fieldset-requireone-3').val("");

          // Validate the form.
          validator.form();

          // Check for the "Requireone 1", "Requireone 2" and "Requireone 3" errors.
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-1].error:visible').length, 1, Drupal.t('Error label found for "Requireone 1"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-2].error:visible').length, 1, Drupal.t('Error label found for "Requireone 2"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-3].error:visible').length, 1, Drupal.t('Error label found for "Requireone 3"'));

          // Fill in a value in "Requireone 1", "Requireone 2" and "Requireone 3".
          $('#edit-submitted-requireone-fieldset-requireone-1').val("a");
          $('#edit-submitted-requireone-fieldset-requireone-2').val("a");
          $('#edit-submitted-requireone-fieldset-requireone-3').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Requireone 1", "Requireone 2" and "Requireone 3" errors.
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-1].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 1"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-2].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 2"'));
          QUnit.equal($('label[for=edit-submitted-requireone-fieldset-requireone-3].error:visible').length, 0, Drupal.t('Error label not found for "Requireone 3"'));
        };
      },
      requireOneOfTwo: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(12);
          // Validate the empty form.
          validator.form();

          // Check for the "RequireoneOfTwo 1" and "RequireoneOfTwo 2" errors.
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1].error:visible').length, 1, Drupal.t('Error label found for "RequireoneOfTwo 1"'));
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2].error:visible').length, 1, Drupal.t('Error label found for "RequireoneOfTwo 2"'));

          // Fill in a value in "RequireoneOfTwo 1".
          $('#edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1').val("a");

          // Validate the form.
          validator.form();

          // Check for the "RequireoneOfTwo 1" and "RequireoneOfTwo 2" errors.
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1].error:visible').length, 0, Drupal.t('Error label not found for "RequireoneOfTwo 1"'));
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2].error:visible').length, 0, Drupal.t('Error label not found for "RequireoneOfTwo 2"'));

          // Clear the value of "RequireoneOfTwo 1".
          $('#edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1').val("");

          // Validate the form.
          validator.form();

          // Check for the "RequireoneOfTwo 1" and "RequireoneOfTwo 2" errors.
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1].error:visible').length, 1, Drupal.t('Error label found for "RequireoneOfTwo 1"'));
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2].error:visible').length, 1, Drupal.t('Error label found for "RequireoneOfTwo 2"'));

          // Fill in a value in "RequireoneOfTwo 2".
          $('#edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2').val("a");

          // Validate the form.
          validator.form();

          // Check for the "RequireoneOfTwo 1" and "RequireoneOfTwo 2" errors.
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1].error:visible').length, 0, Drupal.t('Error label not found for "RequireoneOfTwo 1"'));
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2].error:visible').length, 0, Drupal.t('Error label not found for "RequireoneOfTwo 2"'));

          // Clear the value of "RequireoneOfTwo 2".
          $('#edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2').val("");

          // Validate the form.
          validator.form();

          // Check for the "RequireoneOfTwo 1" and "RequireoneOfTwo 2" errors.
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1].error:visible').length, 1, Drupal.t('Error label found for "RequireoneOfTwo 1"'));
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2].error:visible').length, 1, Drupal.t('Error label found for "RequireoneOfTwo 2"'));

          // Fill in a value in "RequireoneOfTwo 1" and "RequireoneOfTwo 2".
          $('#edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1').val("a");
          $('#edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2').val("a");

          // Validate the form.
          validator.form();

          // Check for the "RequireoneOfTwo 1" and "RequireoneOfTwo 2" errors.
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-1].error:visible').length, 0, Drupal.t('Error label not found for "RequireoneOfTwo 1"'));
          QUnit.equal($('label[for=edit-submitted-requireoneoftwo-fieldset-requireoneoftwo-2].error:visible').length, 0, Drupal.t('Error label not found for "RequireoneOfTwo 2"'));
        };
      },
      plainText: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Plain text" error.
          QUnit.equal($('label[for=edit-submitted-plain-text].error:visible').length, 1, Drupal.t('Error label found for "Plain text"'));

          // Fill in the "Plain text" with an invalid value.
          $('#edit-submitted-plain-text').val('<p>This is a paragraph</p>');

          // Validate the form.
          validator.form();

          // Check for the "Plain text" error.
          QUnit.equal($('label[for=edit-submitted-plain-text].error:visible').length, 1, Drupal.t('Error label found for "Plain text"'));

          // Fill in the "Plain text" with a valid value.
          $('#edit-submitted-plain-text').val('This is plain text');

          // Validate the form.
          validator.form();

          // Check for the "Plain text" error.
          QUnit.equal($('label[for=edit-submitted-plain-text].error:visible').length, 0, Drupal.t('Error label not found for "Plain text"'));
        };
      },
      blackList: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(4);

          // Validate the empty form.
          validator.form();

          // Check for the "Blacklist" error.
          QUnit.equal($('label[for=edit-submitted-blacklist].error:visible').length, 1, Drupal.t('Error label found for "Blacklist"'));

          // Fill in the "Blacklist" with an invalid value (words black and list are blacklisted).
          $('#edit-submitted-blacklist').val('color black');

          // Validate the form.
          validator.form();

          // Check for the "Blacklist" error.
          QUnit.equal($('label[for=edit-submitted-blacklist].error:visible').length, 1, Drupal.t('Error label found for "Blacklist"'));

          // Fill in the "Blacklist" with an invalid value (words black and list are blacklisted).
          $('#edit-submitted-blacklist').val('grocery list');

          // Validate the form.
          validator.form();

          // Check for the "Blacklist" error.
          QUnit.equal($('label[for=edit-submitted-blacklist].error:visible').length, 1, Drupal.t('Error label found for "Blacklist"'));

          // Fill in the "Blacklist" with valid value.
          $('#edit-submitted-blacklist').val('these are just some words');

          // Validate the form.
          validator.form();

          // Check for the "Blacklist" error.
          QUnit.equal($('label[for=edit-submitted-blacklist].error:visible').length, 0, Drupal.t('Error label not found for "Blacklist"'));
        };
      },
      equal:  function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(10);

          // Validate the empty form.
          validator.form();

          // Check for the "Equal to" and "Must equal" errors.
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-equal-to].error:visible').length, 1, Drupal.t('Error label found for "Equal to"'));
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-must-equal].error:visible').length, 1, Drupal.t('Error label found for "Must equal"'));

          // Fill in different values for both fields.
          $('#edit-submitted-equal-fieldset-equal-to').val('zbc');
          $('#edit-submitted-equal-fieldset-must-equal').val('abc');

          // Validate the form.
          validator.form();

          // Check for the "Equal to" and "Must equal" errors.
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-equal-to].error:visible').length, 0, Drupal.t('Error label not found for "Equal to"'));
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-must-equal].error:visible').length, 1, Drupal.t('Error label found for "Must equal"'));

          //Change the first value to equal the second.
          $('#edit-submitted-equal-fieldset-equal-to').val('abc');

          // Validate the form.
          validator.form();

          // Check for the "Equal to" and "Must equal" errors.
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-equal-to].error:visible').length, 0, Drupal.t('Error label not found for "Equal to"'));
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-must-equal].error:visible').length, 0, Drupal.t('Error label not found for "Must equal"'));
          
          //Change the second value.
          $('#edit-submitted-equal-fieldset-must-equal').val('1abc');

          // Validate the form.
          validator.form();

          // Check for the "Equal to" and "Must equal" errors.
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-equal-to].error:visible').length, 0, Drupal.t('Error label not found for "Equal to"'));
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-must-equal].error:visible').length, 1, Drupal.t('Error label found for "Must equal"'));

          // Change both values tot the same value.
          $('#edit-submitted-equal-fieldset-equal-to').val('equal value');
          $('#edit-submitted-equal-fieldset-must-equal').val('equal value');

          // Validate the form.
          validator.form();

          // Check for the "Equal to" and "Must equal" errors.
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-equal-to].error:visible').length, 0, Drupal.t('Error label not found for "Equal to"'));
          QUnit.equal($('label[for=edit-submitted-equal-fieldset-must-equal].error:visible').length, 0, Drupal.t('Error label not found for "Must equal"'));
        };
      },
      unique:  function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(18);
          // Validate the empty form.
          validator.form();

          // Check for the "Unique 1", "Unique 2" and "Unique 3" errors.
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-1].error:visible').length, 1, Drupal.t('Error label found for "Unique 1"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-2].error:visible').length, 1, Drupal.t('Error label found for "Unique 2"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-3].error:visible').length, 1, Drupal.t('Error label found for "Unique 3"'));

          // Fill the same value in "Unique 1", "Unique 2" and "Unique 3".
          $('#edit-submitted-unique-fieldset-unique-1').val("a");
          $('#edit-submitted-unique-fieldset-unique-2').val("a");
          $('#edit-submitted-unique-fieldset-unique-3').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Unique 1", "Unique 2" and "Unique 3" errors.
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-1].error:visible').length, 1, Drupal.t('Error label found for "Unique 1"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-2].error:visible').length, 1, Drupal.t('Error label found for "Unique 2"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-3].error:visible').length, 0, Drupal.t('Error label not found for "Unique 3"'));

          // Fill the same value in "Unique 1" and "Unique 2".
          $('#edit-submitted-unique-fieldset-unique-1').val("a");
          $('#edit-submitted-unique-fieldset-unique-2').val("a");
          $('#edit-submitted-unique-fieldset-unique-3').val("b");

          // Validate the form.
          validator.form();

          // Check for the "Unique 1", "Unique 2" and "Unique 3" errors.
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-1].error:visible').length, 1, Drupal.t('Error label found for "Unique 1"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-2].error:visible').length, 0, Drupal.t('Error label not found for "Unique 2"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-3].error:visible').length, 0, Drupal.t('Error label not found for "Unique 3"'));

          // Fill the same value in "Unique 2" and "Unique 3".
          $('#edit-submitted-unique-fieldset-unique-1').val("b");
          $('#edit-submitted-unique-fieldset-unique-2').val("a");
          $('#edit-submitted-unique-fieldset-unique-3').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Unique 1", "Unique 2" and "Unique 3" errors.
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-1].error:visible').length, 0, Drupal.t('Error label not found for "Unique 1"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-2].error:visible').length, 1, Drupal.t('Error label found for "Unique 2"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-3].error:visible').length, 0, Drupal.t('Error label not found for "Unique 3"'));

          // Fill the same value in "Unique 1", "Unique 2" and "Unique 3".
          $('#edit-submitted-unique-fieldset-unique-1').val("a");
          $('#edit-submitted-unique-fieldset-unique-2').val("b");
          $('#edit-submitted-unique-fieldset-unique-3').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Unique 1", "Unique 2" and "Unique 3" errors.
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-1].error:visible').length, 1, Drupal.t('Error label found for "Unique 1"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-2].error:visible').length, 0, Drupal.t('Error label found for "Unique 2"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-3].error:visible').length, 0, Drupal.t('Error label not found for "Unique 3"'));

          // Fill different values in "Unique 1", "Unique 2" and "Unique 3".
          $('#edit-submitted-unique-fieldset-unique-1').val("a");
          $('#edit-submitted-unique-fieldset-unique-2').val("b");
          $('#edit-submitted-unique-fieldset-unique-3').val("c");

          // Validate the form.
          validator.form();

          // Check for the "Unique 1", "Unique 2" and "Unique 3" errors.
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-1].error:visible').length, 0, Drupal.t('Error label found for "Unique 1"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-2].error:visible').length, 0, Drupal.t('Error label found for "Unique 2"'));
          QUnit.equal($('label[for=edit-submitted-unique-fieldset-unique-3].error:visible').length, 0, Drupal.t('Error label not found for "Unique 3"'));
        };
      },
      specificVal: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Specific val" error.
          QUnit.equal($('label[for=edit-submitted-specific-val].error:visible').length, 1, Drupal.t('Error label found for "Specific val"'));

          // Fill in the "Specific val" textfield with an invalid value.
          $('#edit-submitted-specific-val').val('some text');

          // Validate the form.
          validator.form();

          // Check for the "Specific val" error.
          QUnit.equal($('label[for=edit-submitted-specific-val].error:visible').length, 1, Drupal.t('Error label found for "Specific val"'));

          // Fill in the "Specific val" textfield with a valid value.
          $('#edit-submitted-specific-val').val('abc-123');

          // Validate the form.
          validator.form();

          // Check for the "Specific val" error.
          QUnit.equal($('label[for=edit-submitted-specific-val].error:visible').length, 0, Drupal.t('Error label not found for "Specific val"'));
        };
      },
      selectMin: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Select min" error.
          QUnit.equal($('label[for=edit-submitted-select-min].error:visible').length, 1, Drupal.t('Error label found for "Select min"'));

          // Select too few elements for "Select min".
          $('#edit-submitted-select-min').val(["one"]);

          // Validate the form.
          validator.form();

          // Check for the "Select min" error.
          QUnit.equal($('label[for=edit-submitted-select-min].error:visible').length, 1, Drupal.t('Error label found for "Select min"'));

          // Select a valid amount of elements for "Select min".
          $('#edit-submitted-select-min').val(["one", "three", "five"]);

          // Validate the form.
          validator.form();

          // Check for the "Select min" error.
          QUnit.equal($('label[for=edit-submitted-select-min].error:visible').length, 0, Drupal.t('Error label not found for "Select min"'));
        };
      },
      selectMax: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Select max" error.
          QUnit.equal($('label[for=edit-submitted-select-max].error:visible').length, 1, Drupal.t('Error label found for "Select max"'));

          // Select too many elements for "Select max".
          $('#edit-submitted-select-max').val(["one", "three", "five", "six", "seven", "nine"]);

          // Validate the form.
          validator.form();

          // Check for the "Select max" error.
          QUnit.equal($('label[for=edit-submitted-select-max].error:visible').length, 1, Drupal.t('Error label found for "Select max"'));

          // Select a valid amount of elements for "Select max".
          $('#edit-submitted-select-max').val(["one", "three", "five"]);

          // Validate the form.
          validator.form();

          // Check for the "Select max" error.
          QUnit.equal($('label[for=edit-submitted-select-max].error:visible').length, 0, Drupal.t('Error label not found for "Select max"'));
        };
      },
      selectExact: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(4);

          // Validate the empty form.
          validator.form();

          // Check for the "Select exact" error.
          QUnit.equal($('label[for=edit-submitted-select-exact].error:visible').length, 1, Drupal.t('Error label found for "Select exact"'));

          // Select too few elements for "Select exact".
          $('#edit-submitted-select-exact').val(["one"]);

          // Validate the form.
          validator.form();

          // Check for the "Select exact" error.
          QUnit.equal($('label[for=edit-submitted-select-exact].error:visible').length, 1, Drupal.t('Error label found for "Select exact"'));

          // Select too many elements for "Select exact".
          $('#edit-submitted-select-exact').val(["one", "three", "five", "six", "seven", "nine"]);

          // Validate the form.
          validator.form();

          // Check for the "Select exact" error.
          QUnit.equal($('label[for=edit-submitted-select-exact].error:visible').length, 1, Drupal.t('Error label found for "Select exact"'));

          // Select a valid amount of elements for "Select exact".
          $('#edit-submitted-select-exact').val(["one", "three", "five"]);

          // Validate the form.
          validator.form();

          // Check for the "Select exact" error.
          QUnit.equal($('label[for=edit-submitted-select-exact].error:visible').length, 0, Drupal.t('Error label not found for "Select exact"'));
        };
      },
      empty: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the form.
          validator.form();

          // Check for the "Empty" error.
          QUnit.equal($('label[for=edit-submitted-empty].error:visible').length, 0, Drupal.t('Error label not found for "Empty"'));

          // Fill in the "Empty" with a value.
          $('#edit-submitted-empty').val('This is not empty');

          // Validate the form.
          validator.form();

          // Check for the "Empty" error.
          QUnit.equal($('label[for=edit-submitted-empty].error:visible').length, 1, Drupal.t('Error label found for "Empty"'));

          // Fill in the "Empty" with a valid value.
          $('#edit-submitted-empty').val('');

          // Validate the form.
          validator.form();

          // Check for the "Empty" error.
          QUnit.equal($('label[for=edit-submitted-empty].error:visible').length, 0, Drupal.t('Error label not found for "Empty"'));
        };
      }
    }
  };
})(jQuery, Drupal, this, this.document);
