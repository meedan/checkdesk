/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true, QUnit:true*/
(function($, Drupal, window, document, undefined) {
  "use strict";
  /**
   * Webform.
   */
  var validator = {};
  $(document).bind('clientsideValidationInitialized', function(){
    var formid = Drupal.settings.clientsideValidationTestswarm.formID;
    validator = Drupal.myClientsideValidation.validators[formid];
  });
  Drupal.tests.cvwebform = {
    getInfo: function() {
      return {
        name: Drupal.t('Clientside Validation Webform'),
        description: Drupal.t('Test Clientside Validation on Webform elements.'),
        group: Drupal.t('Clientside Validation')
      };
    },
    tests: {
      webformDate: function($, Drupal, window, document, undefined) {
        return function() {
          //Note: Javascript months start at 0.
          QUnit.expect(6);
          var date = new Date();
          // Validate the empty form.
          validator.form();

          // Check for the "Date" error.
          QUnit.equal($('label[for=webform-component-date_group].error:visible').length, 1, Drupal.t('Error label found for "Date"'));

          // The date range is set from -2 years to +2 years. In the next steps we will be filling in the date
          // beginning with year, then month, then day, validating the form in each step to make sure the required error
          // still shows. This way we will set the date to 'yesterday, two years ago'.
          // This logic will only be a problem if the test runs on Jan 1st.

          // Set the date to yesterday.
          date.setDate(date.getDate()-1);

          // If the date equals Feb 29th, set the date to Feb 28th.
          if (date.getMonth() === 2 && date.getDate() === 29) {
            date.setDate(date.getDate()-1);
          }

          // Fill in the year for "Date".

          $('#edit-submitted-date-year').val(date.getFullYear()-2);

          // Validate the form.
          validator.form();

          // Check for the "Date" error.
          QUnit.equal($('label[for=webform-component-date_group].error:visible').length, 1, Drupal.t('Error label found for "Date"'));

          // Fill in the month for "Date".
          $('#edit-submitted-date-month').val(date.getMonth()+1);

          // Validate the form.
          validator.form();

          // Check for the "Date" error.
          QUnit.equal($('label[for=webform-component-date_group].error:visible').length, 1, Drupal.t('Error label found for "Date"'));

          // Fill in the day for "Date".

          $('#edit-submitted-date-day').val(date.getDate());

          // Validate the form.
          validator.form();
          // Check for the "Date" error.
          QUnit.equal($('label[for=webform-component-date_group].error:visible').length, 1, Drupal.t('Error label found for "Date"'));

          // Now we check the other end of the scale, we set the date to 'tomorrow, in two years'.
          date = new Date();
          //set the date to tomorrow.
          date.setDate(date.getDate()+1);

          // If the date equals Feb 29th, set the date to Mar 1st.
          if (date.getMonth() === 2 && date.getDate() === 29) {
            date.setDate(date.getDate()+1);
          }

          // Fill in the date.
          $('#edit-submitted-date-year').val(date.getFullYear()+2);
          $('#edit-submitted-date-month').val(date.getMonth()+1);
          $('#edit-submitted-date-day').val(date.getDate());

          // Validate the form.
          validator.form();
          // Check for the "Date" error.
          QUnit.equal($('label[for=webform-component-date_group].error:visible').length, 1, Drupal.t('Error label found for "Date"'));

          // Set the date to today.
          date = new Date();
          $('#edit-submitted-date-year').val(date.getFullYear());
          $('#edit-submitted-date-month').val(date.getMonth()+1);
          $('#edit-submitted-date-day').val(date.getDate());

          // Validate the form.
          validator.form();
          // Check for the "Date" error.
          QUnit.equal($('label[for=webform-component-date_group].error:visible').length, 0, Drupal.t('Error label not found for "Date"'));
        };
      },
      webformEmail: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Validate the form.
          validator.form();

          // Check for the email error.
          QUnit.equal($('label[for=edit-submitted-email].error:visible').length, 1, Drupal.t('Error label found for "Email"'));

          // Fill in an illegal value.
          $('#edit-submitted-email').val('oops');

          // Validate the form.
          validator.form();

          // Check for the email error.
          QUnit.equal($('label[for=edit-submitted-email].error:visible').length, 1, Drupal.t('Error label found for "Email"'));

          // Fill in a legal value.
          $('#edit-submitted-email').val('test@test.com');

          // Validate the form.
          validator.form();

          // Check for the email error.
          QUnit.equal($('label[for=edit-submitted-email].error:visible').length, 0, Drupal.t('Error label not found for "Email"'));
        };
      },
      webformNumber: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(6);

          // Replace the number element with a textfield so we can actually fill in illegal values.
          if ($.browser.msie === true) {
            var myrange = document.getElementById('edit-submitted-number');
            var el = document.createElement("input");
            el.setAttribute("type", "text");
            myrange.mergeAttributes(el, true);
          }
          else {
            var $oldrange = $('#edit-submitted-number');
            var $myrange = $oldrange.clone();
            $myrange.attr('type', 'text');
            $myrange.insertBefore($oldrange);
            $oldrange.remove();
          }

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-number].error:visible').length, 1, Drupal.t('Error label found for "Number"'));

          // Fill in an illegal value.
          $('#edit-submitted-number').val("a");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-number].error:visible').length, 1, Drupal.t('Error label found for "Number"'));

          // Fill in the textfield with a number > max.
          $('#edit-submitted-number').val("6");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-number].error:visible').length, 1, Drupal.t('Error label found for "Number"'));

          // Fill in the textfield with a number < min.
          $('#edit-submitted-number').val("1");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-number].error:visible').length, 1, Drupal.t('Error label found for "Number"'));

          // Fill in the textfield with a number not respecting the 'step' attribute.
          $('#edit-submitted-number').val("3.3");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-number].error:visible').length, 1, Drupal.t('Error label found for "Number"'));

          // Fill in the textfield with a legal number.
          $('#edit-submitted-number').val("2.5");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-number].error:visible').length, 0, Drupal.t('Error label not found for "Number"'));
        };
      },
      webformSingleSelect: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(2);

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-single-select].error:visible').length, 1, Drupal.t('Error label found for "Single select"'));

          // Fill in a value.
          $('#edit-submitted-single-select option:first').removeAttr('selected');
          $('#edit-submitted-single-select option:last').attr('selected', 'selected');

          // Validate the form.
          validator.form();

          // Check for the email error.
          QUnit.equal($('label[for=edit-submitted--single-select].error:visible').length, 0, Drupal.t('Error label not found for "Single select"'));
        };
      },
      webformMultipleSelect: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(2);

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-multiple-select].error:visible').length, 1, Drupal.t('Error label found for "Multiple select"'));

          // Select multiple options.
          $('#edit-submitted-multiple-select option:even').attr('selected', 'selected');

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-multiple-select].error:visible').length, 0, Drupal.t('Error label not found for "Multiple select"'));
        };
      },
      webformRadios: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(2);

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for="submitted[radio_buttons]"].error:visible').length, 1, Drupal.t('Error label found for "Radio Buttons"'));

          // Select an option.
          $('#edit-submitted-radio-buttons-1').attr('checked', 'checked');

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for="submitted[radio_buttons]"].error:visible').length, 0, Drupal.t('Error label not found for "Radio Buttons"'));
        };
      },
      webformCheckboxes: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(2);

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for="submitted[checkboxes]_group"].error:visible').length, 1, Drupal.t('Error label found for "Checkboxes"'));

          // Select an option.
          $('#edit-submitted-checkboxes input[type="checkbox"]:even').attr('checked', 'checked');

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for="submitted[checkboxes]_group"].error:visible').length, 0, Drupal.t('Error label not found for "Checkboxes"'));
        };
      },
      webformTextarea: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(2);

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-textarea].error:visible').length, 1, Drupal.t('Error label found for "Textarea"'));

          // Fill in a value.
          $('#edit-submitted-textarea').val("I've entered a value in the textarea!");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-textarea].error:visible').length, 0, Drupal.t('Error label not found for "Textarea"'));
        };
      },
      webformTextfield: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(2);

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-textfield].error:visible').length, 1, Drupal.t('Error label found for "Textfield"'));

          // Fill in a value.
          $('#edit-submitted-textfield').val("I've entered a value in the textfield!");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-textfield].error:visible').length, 0, Drupal.t('Error label not found for "Textfield"'));
        };
      },
      webformTime: function($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(8);
          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-time-hour].error:visible').length, 1, Drupal.t('Error label found for "Time (Hour)"'));
          QUnit.equal($('label[for=edit-submitted-time-minute].error:visible').length, 1, Drupal.t('Error label found for "Time (Minute)"'));

          // Select hour.
          var date = new Date();
          var hours = (date.getHours() > 12) ? (date.getHours() - 12) : date.getHours();
          var minutes = date.getMinutes();
          $('#edit-submitted-time-hour').val(hours);

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-submitted-time-hour].error:visible').length, 0, Drupal.t('Error label not found for "Time (Hour)"'));
          QUnit.equal($('label[for=edit-submitted-time-minute].error:visible').length, 1, Drupal.t('Error label found for "Time (Minute)"'));

          // Deselect hour and select minutes.
          $('#edit-submitted-time-hour').val("");
          $('#edit-submitted-time-minute').val(minutes);

          // Validate the form.
          validator.form();

          // Check for the "Date" error.
          QUnit.equal($('label[for=edit-submitted-time-hour].error:visible').length, 1, Drupal.t('Error label found for "Time (Hour)"'));
          QUnit.equal($('label[for=edit-submitted-time-minute].error:visible').length, 0, Drupal.t('Error label not found for "Time (Minute)"'));

          // Select hour and minutes.
          $('#edit-submitted-time-hour').val(hours);
          $('#edit-submitted-time-minute').val(minutes);

          // Validate the form.
          validator.form();

          // Check for the "Date" error.
          QUnit.equal($('label[for=edit-submitted-time-hour].error:visible').length, 0, Drupal.t('Error label not found for "Time (Hour)"'));
          QUnit.equal($('label[for=edit-submitted-time-minute].error:visible').length, 0, Drupal.t('Error label not found for "Time (Minute)"'));
        };
      }
    }
  };
})(jQuery, Drupal, this, this.document);
