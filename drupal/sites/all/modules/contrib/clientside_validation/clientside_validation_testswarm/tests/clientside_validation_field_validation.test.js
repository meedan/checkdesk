/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true, QUnit:true*/
(function ($, Drupal, window, document, undefined) {
  "use strict";
  /**
   * Field Validation.
   */
  var formid = 'cv-test-field-validation-node-form';
  var validator = {};
  $(document).bind('clientsideValidationInitialized', function (){
    validator = Drupal.myClientsideValidation.validators[formid];
  });
  Drupal.tests.cvfieldvalidation = {
    getInfo: function() {
      return {
        name: Drupal.t('Clientside Validation Field Validation'),
        description: Drupal.t('Test Clientside Validation Field Validation.'),
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
          QUnit.equal($('label[for=edit-field-regex-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Regex"'));

          // Fill in the field with an illegal value (this regex only allows alphanumerics and underscores).
          $('#edit-field-regex-und-0-value').val("abc_123*");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-field-regex-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Regex"'));

          // Fill in the field with valid value.
          $('#edit-field-regex-und-0-value').val("abc_123");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-field-regex-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Regex"'));
        };
      },
      minLength: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Min length" error.
          QUnit.equal($('label[for=edit-field-min-length-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Min length"'));

          // Fill in the "Min length" with a value that is too short.
          $('#edit-field-min-length-und-0-value').val('123');

          // Validate the form.
          validator.form();

          // Check for the "Min length" error.
          QUnit.equal($('label[for=edit-field-min-length-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Min length"'));


          // Fill in the "Min length" with a valid value.
          $('#edit-field-min-length-und-0-value').val('123456');

          // Validate the form.
          validator.form();

          // Check for the "Min length" error.
          QUnit.equal($('label[for=edit-field-min-length-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Min length"'));
        };
      },
      maxLength: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Max length" error.
          QUnit.equal($('label[for=edit-field-max-length-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Max length"'));

          // Fill in the "Max length" with a value that is too long.
          $('#edit-field-max-length-und-0-value').val('1234567890abc');

          // Validate the form.
          validator.form();

          // Check for the "Max length" error.
          QUnit.equal($('label[for=edit-field-max-length-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Max length"'));


          // Fill in the "Max length" with a valid value.
          $('#edit-field-max-length-und-0-value').val('123456');

          // Validate the form.
          validator.form();

          // Check for the "Max length" error.
          QUnit.equal($('label[for=edit-field-max-length-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Max length"'));
        };
      },
      rangeLength: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(4);

          // Validate the empty form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-field-range-length-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Range length"'));

          // Fill in the "Range length" with a value that is too short.
          $('#edit-field-range-length-und-0-value').val('123');

          // Validate the form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-field-range-length-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Range length"'));

          // Fill in the "Range length" with a value that is too long.
          $('#edit-field-range-length-und-0-value').val('1234567890abc');

          // Validate the form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-field-range-length-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Range length"'));

          // Fill in the "Range length" with a valid value.
          $('#edit-field-range-length-und-0-value').val('123456');

          // Validate the form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-field-range-length-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Range length"'));
        };
      },
      minWords: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Min words" error.
          QUnit.equal($('label[for=edit-field-min-words-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Min words"'));

          // Fill in the "Min words" with a value that is too short.
          $('#edit-field-min-words-und-0-value').val('one  two three four');

          // Validate the form.
          validator.form();

          // Check for the "Min words" error.
          QUnit.equal($('label[for=edit-field-min-words-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Min words"'));


          // Fill in the "Min words" with a valid value.
          $('#edit-field-min-words-und-0-value').val('one two three four five');

          // Validate the form.
          validator.form();

          // Check for the "Min length" error.
          QUnit.equal($('label[for=edit-field-min-words-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Min words"'));
        };
      },
      maxWords: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Max words" error.
          QUnit.equal($('label[for=edit-field-max-words-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Max words"'));

          // Fill in the "Max words" with a value that is too long.
          $('#edit-field-max-words-und-0-value').val('one  two three four five six seven eight nine ten eleven');

          // Validate the form.
          validator.form();

          // Check for the "Max words" error.
          QUnit.equal($('label[for=edit-field-max-words-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Max words"'));


          // Fill in the "Max words" with a valid value.
          $('#edit-field-max-words-und-0-value').val('one two three four five');

          // Validate the form.
          validator.form();

          // Check for the "Max length" error.
          QUnit.equal($('label[for=edit-field-max-words-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Max words"'));
        };
      },
      rangeWords: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(4);

          // Validate the empty form.
          validator.form();

          // Check for the "Range words" error.
          QUnit.equal($('label[for=edit-field-range-words-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Range words"'));

          // Fill in the "Range words" with a value that is too short.
          $('#edit-field-range-words-und-0-value').val('one two three four');

          // Validate the form.
          validator.form();

          // Check for the "Range words" error.
          QUnit.equal($('label[for=edit-field-range-words-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Range words"'));

          // Fill in the "Range words" with a value that is too long.
          $('#edit-field-range-words-und-0-value').val('one two three four five six seven eight nine ten eleven');

          // Validate the form.
          validator.form();

          // Check for the "Range words" error.
          QUnit.equal($('label[for=edit-field-range-words-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Range words"'));

          // Fill in the "Range words" with a valid value.
          $('#edit-field-range-words-und-0-value').val('one two three four five six');

          // Validate the form.
          validator.form();

          // Check for the "Range length" error.
          QUnit.equal($('label[for=edit-field-range-words-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Range words"'));
        };
      },
      plainText: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Plain text" error.
          QUnit.equal($('label[for=edit-field-plain-text-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Plain text"'));

          // Fill in the "Plain text" with an invalid value.
          $('#edit-field-plain-text-und-0-value').val('<p>This is a paragraph</p>');

          // Validate the form.
          validator.form();

          // Check for the "Plain text" error.
          QUnit.equal($('label[for=edit-field-plain-text-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Plain text"'));

          // Fill in the "Plain text" with a valid value.
          $('#edit-field-plain-text-und-0-value').val('This is plain text');

          // Validate the form.
          validator.form();

          // Check for the "Plain text" error.
          QUnit.equal($('label[for=edit-field-plain-text-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Plain text"'));
        };
      },
      empty: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the form.
          validator.form();

          // Check for the "Empty" error.
          QUnit.equal($('label[for=edit-field-empty-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Empty"'));

          // Fill in the "Empty" with a value.
          $('#edit-field-empty-und-0-value').val('This is not empty');

          // Validate the form.
          validator.form();

          // Check for the "Empty" error.
          QUnit.equal($('label[for=edit-field-empty-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Empty"'));

          // Fill in the "Empty" with a valid value.
          $('#edit-field-empty-und-0-value').val('');

          // Validate the form.
          validator.form();

          // Check for the "Empty" error.
          QUnit.equal($('label[for=edit-field-empty-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Empty"'));
        };
      },
      blackList: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(4);

          // Validate the empty form.
          validator.form();

          // Check for the "Blacklist" error.
          QUnit.equal($('label[for=edit-field-blacklist-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Blacklist"'));

          // Fill in the "Blacklist" with an invalid value (words black and list are blacklisted).
          $('#edit-field-blacklist-und-0-value').val('color black');

          // Validate the form.
          validator.form();

          // Check for the "Blacklist" error.
          QUnit.equal($('label[for=edit-field-blacklist-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Blacklist"'));

          // Fill in the "Blacklist" with an invalid value (words black and list are blacklisted).
          $('#edit-field-blacklist-und-0-value').val('grocery list');

          // Validate the form.
          validator.form();

          // Check for the "Blacklist" error.
          QUnit.equal($('label[for=edit-field-blacklist-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Blacklist"'));

          // Fill in the "Blacklist" with valid value.
          $('#edit-field-blacklist-und-0-value').val('these are just some words');

          // Validate the form.
          validator.form();

          // Check for the "Blacklist" error.
          QUnit.equal($('label[for=edit-field-blacklist-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Blacklist"'));
        };
      },
      numeric: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the empty form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-field-numeric-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric"'));

          // Fill in the "Numeric" textfield with a letter.
          $('#edit-field-numeric-und-0-value').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-field-numeric-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric"'));

          // Fill in the "Numeric" textfield with a valid number
          $('#edit-field-numeric-und-0-value').val("1.5");

          // Validate the form.
          validator.form();

          // Check for the "Numeric" error.
          QUnit.equal($('label[for=edit-field-numeric-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Numeric"'));
        };
      },
      numericMin: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(4);
          // Validate the empty form.
          validator.form();

          // Check for the "Numeric min" error.
          QUnit.equal($('label[for=edit-field-numeric-min-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric min"'));

          // Fill in the "Numeric min" textfield with a letter.
          $('#edit-field-numeric-min-und-0-value').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Numeric min" error.
          QUnit.equal($('label[for=edit-field-numeric-min-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric min"'));

          // Fill in the "Numeric min" textfield with a number that is too low.
          $('#edit-field-numeric-min-und-0-value').val("1");

          // Validate the form.
          validator.form();

          // Check for the "Numeric min" error.
          QUnit.equal($('label[for=edit-field-numeric-min-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric min"'));

           // Fill in the "Numeric min" textfield with a valid number.
          $('#edit-field-numeric-min-und-0-value').val("6");

          // Validate the form.
          validator.form();

          // Check for the "Numeric min" error.
          QUnit.equal($('label[for=edit-field-numeric-min-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Numeric min"'));
        };
      },
      numericMax: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(4);
          // Validate the empty form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-field-numeric-max-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric max"'));

          // Fill in the "Numeric max" textfield with a letter.
          $('#edit-field-numeric-max-und-0-value').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-field-numeric-max-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric max"'));

          // Fill in the "Numeric max" textfield with a number that is too high.
          $('#edit-field-numeric-max-und-0-value').val("12");

          // Validate the form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-field-numeric-max-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric max"'));

           // Fill in the "Numeric max" textfield with a valid number.
          $('#edit-field-numeric-max-und-0-value').val("6");

          // Validate the form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-field-numeric-max-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Numeric max"'));
        };
      },
      numericRange: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(5);
          // Validate the empty form.
          validator.form();

          // Check for the "Numeric range" error.
          QUnit.equal($('label[for=edit-field-numeric-range-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric range"'));

          // Fill in the "Numeric range" textfield with a letter.
          $('#edit-field-numeric-range-und-0-value').val("a");

          // Validate the form.
          validator.form();

          // Check for the "Numeric max" error.
          QUnit.equal($('label[for=edit-field-numeric-range-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric range"'));

          // Fill in the "Numeric range" textfield with a number that is too high.
          $('#edit-field-numeric-range-und-0-value').val("12");

          // Validate the form.
          validator.form();

          // Check for the "Numeric range" error.
          QUnit.equal($('label[for=edit-field-numeric-range-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric range"'));

          // Fill in the "Numeric range" textfield with a number that is too low.
          $('#edit-field-numeric-range-und-0-value').val("1");

          // Validate the form.
          validator.form();

          // Check for the "Numeric range" error.
          QUnit.equal($('label[for=edit-field-numeric-range-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Numeric range"'));

           // Fill in the "Numeric range" textfield with a valid number.
          $('#edit-field-numeric-range-und-0-value').val("6");

          // Validate the form.
          validator.form();

          // Check for the "Numeric range" error.
          QUnit.equal($('label[for=edit-field-numeric-range-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Numeric range"'));
        };
      },
      specificVal: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Specific val" error.
          QUnit.equal($('label[for=edit-field-specific-val-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Specific val"'));

          // Fill in the "Specific val" textfield with an invalid value.
          $('#edit-field-specific-val-und-0-value').val('some text');

          // Validate the form.
          validator.form();

          // Check for the "Specific val" error.
          QUnit.equal($('label[for=edit-field-specific-val-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Specific val"'));

          // Fill in the "Specific val" textfield with a valid value.
          $('#edit-field-specific-val-und-0-value').val('abc-123');

          // Validate the form.
          validator.form();

          // Check for the "Specific val" error.
          QUnit.equal($('label[for=edit-field-specific-val-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Specific val"'));
        };
      },
      selectMin: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Select min" error.
          QUnit.equal($('label[for=edit-field-select-min-und].error:visible').length, 1, Drupal.t('Error label found for "Select min"'));

          // Select too few elements for "Select min".
          $('#edit-field-select-min-und').val(["one"]);

          // Validate the form.
          validator.form();

          // Check for the "Select min" error.
          QUnit.equal($('label[for=edit-field-select-min-und].error:visible').length, 1, Drupal.t('Error label found for "Select min"'));

          // Select a valid amount of elements for "Select min".
          $('#edit-field-select-min-und').val(["one", "three", "five"]);

          // Validate the form.
          validator.form();

          // Check for the "Select min" error.
          QUnit.equal($('label[for=edit-field-select-min-und].error:visible').length, 0, Drupal.t('Error label not found for "Select min"'));
        };
      },
      selectMax: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the "Select max" error.
          QUnit.equal($('label[for=edit-field-select-max-und].error:visible').length, 1, Drupal.t('Error label found for "Select max"'));

          // Select too many elements for "Select max".
          $('#edit-field-select-max-und').val(["one", "three", "five", "six", "seven", "nine"]);

          // Validate the form.
          validator.form();

          // Check for the "Select max" error.
          QUnit.equal($('label[for=edit-field-select-max-und].error:visible').length, 1, Drupal.t('Error label found for "Select max"'));

          // Select a valid amount of elements for "Select max".
          $('#edit-field-select-max-und').val(["one", "three", "five"]);

          // Validate the form.
          validator.form();

          // Check for the "Select max" error.
          QUnit.equal($('label[for=edit-field-select-max-und].error:visible').length, 0, Drupal.t('Error label not found for "Select max"'));
        };
      },
      selectRange: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(4);

          // Validate the empty form.
          validator.form();

          // Check for the "Select range" error.
          QUnit.equal($('label[for=edit-field-select-range-und].error:visible').length, 1, Drupal.t('Error label found for "Select range"'));

          // Select too few elements for "Select range".
          $('#edit-field-select-range-und').val(["one"]);

          // Validate the form.
          validator.form();

          // Check for the "Select range" error.
          QUnit.equal($('label[for=edit-field-select-range-und].error:visible').length, 1, Drupal.t('Error label found for "Select range"'));

          // Select too many elements for "Select range".
          $('#edit-field-select-range-und').val(["one", "three", "five", "six", "seven", "nine"]);

          // Validate the form.
          validator.form();

          // Check for the "Select range" error.
          QUnit.equal($('label[for=edit-field-select-range-und].error:visible').length, 1, Drupal.t('Error label found for "Select range"'));

          // Select a valid amount of elements for "Select range".
          $('#edit-field-select-range-und').val(["one", "three", "five"]);

          // Validate the form.
          validator.form();

          // Check for the "Select range" error.
          QUnit.equal($('label[for=edit-field-select-range-und].error:visible').length, 0, Drupal.t('Error label not found for "Select range"'));
        };
      },
      email: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-field-cv-email-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Email"'));

          // Fill in the field with an illegal email.
          $('#edit-field-cv-email-und-0-value').val("oops");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-field-cv-email-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "Email"'));

          // Fill in the field with an email.
          $('#edit-field-cv-email-und-0-value').val("test@example.com");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-field-cv-email-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "Email"'));
        };
      },
      url: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-field-url-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "URL"'));

          // Fill in the field with an illegal URL.
          $('#edit-field-url-und-0-value').val("oops");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-field-url-und-0-value].error:visible').length, 1, Drupal.t('Error label found for "URL"'));

          // Fill in the field with an URL.
          $('#edit-field-url-und-0-value').val("http://example.com");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-field-url-und-0-value].error:visible').length, 0, Drupal.t('Error label not found for "URL"'));
        };
      }
    }
  };
})(jQuery, Drupal, this, this.document);
