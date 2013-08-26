/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true, QUnit:true*/
(function ($, Drupal, window, document, undefined) {
  "use strict";
  /**
   * Form API Elements.
   */
  var formid = 'clientside-validation-testswarm-fapi';
  var validator = {};
  $(document).bind('clientsideValidationInitialized', function (){
    validator = Drupal.myClientsideValidation.validators[formid];
  });
  Drupal.tests.cvfapi = {
    getInfo: function() {
      return {
        name: Drupal.t('Clientside Validation Fapi'),
        description: Drupal.t('Test Clientside Validation on normal FAPI elements.'),
        group: Drupal.t('Clientside Validation')
      };
    },
    tests: {
      requiredTextfield: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);
          // Sometimes browsers autofill names, make sure it's empty.
          $('#edit-yourname').val('');

          // Validate the empty form.
          validator.form();

          // Check for the "Your name" error.
          QUnit.equal($('label[for=edit-yourname].error:visible').length, 1, Drupal.t('Error label found for "Your name"'));

          // Change the maxlength attribute so we can fill in an illegal value in the browsers that would prevent this.
          $('#edit-yourname').attr('maxlength', '25');

          // Fill in an illegal value.
          $('#edit-yourname').val("thisisaverylongnameforsomeone");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-yourname].error:visible').length, 1, Drupal.t('Error label found for "Your name"'));

          // Fill in the "Your name textfield" with a legal value.
          $('#edit-yourname').val("yourname");

          // Validate the form.
          validator.form();

          // Check for the "Your name" error.
          QUnit.equal($('label[for=edit-yourname].error:visible').length, 0, Drupal.t('Error label not found for "Your name"'));
        };
      },
      requiredCheckboxes: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(2);

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=copy_group].error:visible').length, 1, Drupal.t('Error label found for "Checkboxes" (Select at least one)'));

          // Check one checkbox, random.
          var checkboxes = ['#edit-copy-status', '#edit-copy-moderate', '#edit-copy-promote', '#edit-copy-sticky', '#edit-copy-revision'];
          var $checkbox = $(checkboxes[Math.floor(Math.random()*checkboxes.length)]);
          $checkbox.attr('checked', 'checked');

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=' + $checkbox.attr('id') + '].error:visible').length, 0, Drupal.t('Error label found for "Checkboxes" (Select at least one)'));
        };
      },
      requiredPassword: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(3);

          // Sometimes browsers autofill passwords, make sure it's empty.
          $('#edit-pass').val('');

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-pass].error:visible').length, 1, Drupal.t('Error label found for "Password"'));

          // Change the maxlength attribute so we can fill in an illegal value in the browsers would prevent this.
          $('#edit-pass').attr('maxlength', '25');

          // Fill in an illegal value.
          $('#edit-pass').val("thisisaverylongpassword");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-pass].error:visible').length, 1, Drupal.t('Error label found for "Password"'));

          // Fill in an legal value.
          $('#edit-pass').val("notsolongpassword");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-pass].error:visible').length, 0, Drupal.t('Error label not found for "Password"'));
        };
      },
      requiredRadios: function ($, Drupal, window, document, undefined) {
        return function() {
          QUnit.expect(2);

          // Deselect default value.
          $('#edit-posting-settings-0').removeAttr('checked');

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=posting_settings].error:visible').length, 1, Drupal.t('Error label found for "Preview comment"'));

          // Select an option
          $('#edit-posting-settings-0').attr('checked', 'checked');

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=posting_settings].error:visible').length, 0, Drupal.t('Error label not found for "Preview comment"'));
        };
      },
      requiredSingleSelect: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(2);

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-feed].error:visible').length, 1, Drupal.t('Error label found for "Display of XML feed items"'));

          // Select an option.
          $('#edit-feed').val('title');

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-feed].error:visible').length, 0, Drupal.t('Error label not found for "Display of XML feed items"'));
        };
      },
      requiredMultipleSelect: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(2);

          // Deselect the default value.
          $('#edit-feed2 option:first').removeAttr('selected');

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-feed2].error:visible').length, 1, Drupal.t('Error label found for "Multiple items"'));

          // Select multiple options.
          $('#edit-feed2 option:even').attr('selected', 'selected');

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-feed2].error:visible').length, 0, Drupal.t('Error label not found for "Multiple items"'));
        };
      },
      requiredTextArea: function ($, Drupal, window, document, undefined) {
        return function () {
          QUnit.expect(3);

          // Validate the empty form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-body].error:visible').length, 1, Drupal.t('Error label found for "Body"'));

          // Change the maxlength attribute so we can fill in an illegal value in the browsers would prevent this.
          $('#edit-body').attr('maxlength', '60');

          // Fill in an illegal value.
          $('#edit-body').val("I am typing quite a long text here to exceed 50 characters");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-body].error:visible').length, 1, Drupal.t('Error label found for "Body"'));

          // Fill in an legal value.
          $('#edit-body').val("This is a shorter text");

          // Validate the form.
          validator.form();

          // Check for the error.
          QUnit.equal($('label[for=edit-body].error:visible').length, 0, Drupal.t('Error label not found for "Body"'));
        };
      }

    }
  };
})(jQuery, Drupal, this, this.document);
