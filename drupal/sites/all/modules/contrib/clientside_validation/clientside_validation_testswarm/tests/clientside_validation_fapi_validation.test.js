/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true, QUnit:true*/
(function ($, Drupal, window, document, undefined) {
  "use strict";
  /**
   * FAPI Validation.
   */
  var formid = 'clientside-validation-testswarm-fapi-validation';
  var validator = {};
  $(document).bind('clientsideValidationInitialized', function (){
    validator = Drupal.myClientsideValidation.validators[formid];
  });
  Drupal.tests.cvfapivalidation = {
    getInfo: function() {
      return {
        name: Drupal.t('Clientside Validation FAPI Validation'),
        description: Drupal.t('Test Clientside Validation on FAPI elements with FAPI Validation rules.'),
        group: Drupal.t('Clientside Validation')
      };
    },
    tests: {
      numeric: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the empty form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-numeric].error:visible').length, 1, Drupal.t('Error label found for "Numeric"'));

          // Fill in the "Numeric" textfield with a letter.
          $('#edit-numeric').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-numeric].error:visible').length, 1, Drupal.t('Error label found for "Numeric"'));

          // Fill in the "Numeric" textfield with a valid number
          $('#edit-numeric').val("1.5");

          // Validate the form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-numeric].error:visible').length, 0, Drupal.t('Error label not found for "Numeric"'));
        };
      },
      rangeLength: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(4);

          // Validate the empty form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-length-range].error:visible').length, 1, Drupal.t('Error label found for "Range length"'));

          // Fill in the "Range length" with a value that is too short.
          $('#edit-length-range').val('123');

          // Validate the form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-length-range].error:visible').length, 1, Drupal.t('Error label found for "Range length"'));

          // Fill in the "Range length" with a value that is too long.
          $('#edit-length-range').val('1234567890abc');

          // Validate the form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-length-range].error:visible').length, 1, Drupal.t('Error label found for "Range length"'));

          // Fill in the "Range length" with a valid value.
          $('#edit-length-range').val('123456');

          // Validate the form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-length-range].error:visible').length, 0, Drupal.t('Error label not found for "Range length"'));
        };
      },
      limitedChars: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Chars" error.
          QUnit.equal($('label[for=edit-chars].error:visible').length, 1, Drupal.t('Error label found for "Chars"'));

          // Fill in the "Chars" textfield with an invalid character.
          $('#edit-chars').val('ad');

          // Validate the form.
          validator.form();

          // Check for the "Chars" error.
          QUnit.equal($('label[for=edit-chars].error:visible').length, 1, Drupal.t('Error label found for "Chars"'));

          // Fill in the "Chars" textfield with valid characters.
          $('#edit-chars').val('abc');

          // Validate the form.
          validator.form();

          // Check for the "Chars" error.
          QUnit.equal($('label[for=edit-chars].error:visible').length, 0, Drupal.t('Error label not found for "Chars"'));
        };
      },
      email: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-email].error:visible').length, 1, Drupal.t('Error label found for "Email"'));

          // Fill in the field with an illegal email.
          $('#edit-email').val("oops");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-email].error:visible').length, 1, Drupal.t('Error label found for "Email"'));

          // Fill in the field with an email.
          $('#edit-email').val("test@example.com");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-email].error:visible').length, 0, Drupal.t('Error label not found for "Email"'));
        };
      },
      url: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-url].error:visible').length, 1, Drupal.t('Error label found for "URL"'));

          // Fill in the field with an illegal URL.
          $('#edit-url').val("oops");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-url].error:visible').length, 1, Drupal.t('Error label found for "URL"'));

          // Fill in the field with an URL.
          $('#edit-url').val("http://example.com");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-url].error:visible').length, 0, Drupal.t('Error label not found for "URL"'));
        };
      },
      ipv4: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-ipv4].error:visible').length, 1, Drupal.t('Error label found for "IPv4"'));

          // Fill in the field with an illegal ipv4 value.
          $('#edit-ipv4').val("oops");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-ipv4].error:visible').length, 1, Drupal.t('Error label found for "IPv4"'));

          // Fill in the field with a valid ipv4 value.
          $('#edit-ipv4').val("192.168.1.2");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-ipv4].error:visible').length, 0, Drupal.t('Error label not found for "IPv4"'));
        };
      },
      alphaNumeric: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-alpha-numeric].error:visible').length, 1, Drupal.t('Error label found for "Alpha Numeric"'));

          // Fill in the field with an illegal alpha numeric value.
          $('#edit-alpha-numeric').val("_oops_");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-alpha-numeric].error:visible').length, 1, Drupal.t('Error label found for "Alpha Numeric"'));

          // Fill in the field with valid value.
          $('#edit-alpha-numeric').val("abc123");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-alpha-numeric].error:visible').length, 0, Drupal.t('Error label not found for "Alpha Numeric"'));
        };
      },
      alphaDash: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-alpha-dash].error:visible').length, 1, Drupal.t('Error label found for "Alpha Dash"'));

          // Fill in the field with an illegal alpha-dash value.
          $('#edit-alpha-dash').val("*oops*");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-alpha-dash].error:visible').length, 1, Drupal.t('Error label found for "Alpha Dash"'));

          // Fill in the field with valid value.
          $('#edit-alpha-dash').val("a-b-c");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-alpha-dash].error:visible').length, 0, Drupal.t('Error label not found for "Alpha Dash"'));
        };
      },
      digit: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-digit].error:visible').length, 1, Drupal.t('Error label found for "Digit"'));

          // Fill in the field with an illegal value (digit means no dots either).
          $('#edit-digit').val("1.2");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-digit].error:visible').length, 1, Drupal.t('Error label found for "Digit"'));

          // Fill in the field with valid value.
          $('#edit-digit').val("123");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-digit].error:visible').length, 0, Drupal.t('Error label not found for "Digit"'));
        };
      },
      decimalLimited: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-decimal-limited].error:visible').length, 1, Drupal.t('Error label found for "Decimal (limited)"'));

          // Fill in the field with an illegal value (this decimal must have 2 before the dot and 3 after).
          $('#edit-decimal-limited').val("1.2");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-decimal-limited].error:visible').length, 1, Drupal.t('Error label found for "Decimal (limited)"'));

          // Fill in the field with valid value.
          $('#edit-decimal-limited').val("12.345");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-decimal-limited].error:visible').length, 0, Drupal.t('Error label not found for "Decimal (limited)"'));
        };
      },
      regex: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-regex].error:visible').length, 1, Drupal.t('Error label found for "Regex"'));

          // Fill in the field with an illegal value (this regex only allows alphanumerics and underscores).
          $('#edit-regex').val("abc_123*");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-regex].error:visible').length, 1, Drupal.t('Error label found for "Regex"'));

          // Fill in the field with valid value.
          $('#edit-regex').val("abc_123");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-regex].error:visible').length, 0, Drupal.t('Error label not found for "Regex"'));
        };
      }
    }
  };
})(jQuery, Drupal, this, this.document);
