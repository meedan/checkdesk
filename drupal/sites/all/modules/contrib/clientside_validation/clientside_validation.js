/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true, XRegExp:true*/
/**
 * File:        clientside_validation.js
 * Version:     7.x-1.x
 * Description: Add clientside validation rules
 * Author:      Attiks
 * Language:    Javascript
 * Project:     clientside_validation
 * @module clientside_validation
 */


(/** @lends Drupal */function ($) {
  /**
   * Drupal.behaviors.clientsideValidation.
   *
   * Attach clientside validation to the page or rebind the rules in case of AJAX calls.
   * @extends Drupal.behaviors
   * @fires clientsideValidationInitialized
   */
  "use strict";
  Drupal.behaviors.clientsideValidation = {
    attach: function (context) {
      if (!Drupal.myClientsideValidation) {
        if (Drupal.settings.clientsideValidation) {
          Drupal.myClientsideValidation = new Drupal.clientsideValidation();
        }
      }
      else {
        if (typeof(Drupal.settings.clientsideValidation.forms) === 'undefined') {
          return;
        }
        var update = false;
        jQuery.each(Drupal.settings.clientsideValidation.forms, function (f) {
          if ($(context).find('#' + f).length || $(context).is('#' + f)) {
            update = true;
          }
        });
        //update settings
        if (update) {
          Drupal.myClientsideValidation.data = Drupal.settings.clientsideValidation;
          Drupal.myClientsideValidation.forms = Drupal.myClientsideValidation.data.forms;
          Drupal.myClientsideValidation.groups = Drupal.myClientsideValidation.data.groups;
          Drupal.myClientsideValidation.bindForms();
        }
      }

      /**
       * Let other modules know we are ready.
       * @event clientsideValidationInitialized
       * @name clientsideValidationInitialized
       * @memberof Drupal.clientsideValidation
       */
      jQuery.event.trigger('clientsideValidationInitialized');
    }
  };

  /**
   * Drupal.clientsideValidation.
   * This module adds clientside validation for all forms and webforms using jquery.validate
   * Don't forget to read the README
   *
   * @class Drupal.clientsideValidation
   * @see https://github.com/jzaefferer/jquery-validation
   * @fires clientsideValidationAddCustomRules
   */
  Drupal.clientsideValidation = function() {
    var self = this;
    if (typeof window.time !== 'undefined') {
      // activate by setting clientside_validation_add_js_timing
      self.time = window.time;
    }
    else {
      self.time = {
        start: function() {},
        stop: function() {},
        report: function() {}
      };
    }
    self.time.start('1. clientsideValidation');

    /**
     * prefix to use
     * @memberof Drupal.clientsideValidation
     * @type string
     * @readonly
     * @private
     */
    this.prefix = 'clientsidevalidation-';

    /**
     * local copy of settings
     * @memberof Drupal.clientsideValidation
     * @type array
     * @readonly
     * @private
     */
    this.data = $.extend(true, {}, Drupal.settings.clientsideValidation);

    /**
     * local reference of all defined forms
     * @memberof Drupal.clientsideValidation
     * @type array
     * @readonly
     */
    this.forms = this.data.forms;

    /**
     * list of all defined validators
     * @memberof Drupal.clientsideValidation
     * @type array
     * @readonly
     */
    this.validators = {};

    /**
     * groups used for radios/checkboxes
     * @memberof Drupal.clientsideValidation
     * @type array
     * @readonly
     * @private
     */
    this.groups = this.data.groups;

    // disable class and attribute rules defined by jquery.validate
    $.validator.classRules = function() {
      return {};
    };
    $.validator.attributeRules = function() {
      return {};
    };

    /**
     * add extra rules not defined in jquery.validate
     * @see jquery.validate
     */
    this.addExtraRules();

    /**
     * bind all rules to all forms
     * @see Drupal.clientsideValidation.prototype.bindForms
     */
    this.bindForms();
    self.time.stop('1. clientsideValidation');
    self.time.report();
  };

  /**
   * findVerticalTab helper.
   * @memberof Drupal.clientsideValidation
   * @private
   */
  Drupal.clientsideValidation.prototype.findVerticalTab = function(element) {
    element = $(element);

    // Check for the vertical tabs fieldset and the verticalTab data
    var fieldset = element.parents('fieldset.vertical-tabs-pane');
    if ((fieldset.size() > 0) && (typeof(fieldset.data('verticalTab')) !== 'undefined')) {
      var tab = $(fieldset.data('verticalTab').item[0]).find('a');
      if (tab.size()) {
        return tab;
      }
    }

    // Return null by default
    return null;
  };

  /**
   * findHorizontalTab helper.
   * @memberof Drupal.clientsideValidation
   * @private
   */
  Drupal.clientsideValidation.prototype.findHorizontalTab = function(element) {
    element = $(element);

    // Check for the vertical tabs fieldset and the verticalTab data
    var fieldset = element.parents('fieldset.horizontal-tabs-pane');
    if ((fieldset.size() > 0) && (typeof(fieldset.data('horizontalTab')) !== 'undefined')) {
      var tab = $(fieldset.data('horizontalTab').item[0]).find('a');
      if (tab.size()) {
        return tab;
      }
    }

    // Return null by default
    return null;
  };

  /**
   * Bind all forms.
   * @memberof Drupal.clientsideValidation
   * @public
   */
  Drupal.clientsideValidation.prototype.bindForms = function(){
    var self = this;
    var groupkey;
    if (typeof(self.forms) === 'undefined') {
      return;
    }
    self.time.start('2. bindForms');
    // unset invalid forms
    jQuery.each (self.forms, function (f) {
      if ($('#' + f).length < 1) {
        delete self.forms[f];
      }
    });
    jQuery.each (self.forms, function(f) {
      var errorel = self.prefix + f + '-errors';
      // Remove any existing validation stuff
      if (self.validators[f]) {
        // Doesn't work :: $('#' + f).rules('remove');
        var form = $('#' + f).get(0);
        if (typeof(form) !== 'undefined') {
          jQuery.removeData(form, 'validator');
        }
      }

      if('checkboxrules' in self.forms[f]){
        self.time.start('checkboxrules_groups');
        groupkey = "";
        jQuery.each (self.forms[f].checkboxrules, function(r) {
          groupkey = r + '_group';
          self.groups[f][groupkey] = [];
          jQuery.each(this, function(){
            $(this[2]).find('input[type=checkbox]').each(function(){
              self.groups[f][groupkey].push($(this).attr('name'));
            });
          });
        });
        self.time.stop('checkboxrules_groups');
      }

      if('daterangerules' in self.forms[f]){
        self.time.start('daterangerules');
        groupkey = "";
        jQuery.each (self.forms[f].daterangerules, function(r) {
          groupkey = r + '_group';
          self.groups[f][groupkey] = [];
          jQuery.each(this, function(){
            $('#' + f + ' #' + r + ' :input').not('input[type=image]').each(function(){
              self.groups[f][groupkey].push($(this).attr('name'));
            });
          });
        });
        self.time.stop('daterangerules');
      }

      if('dateminrules' in self.forms[f]){
        self.time.start('dateminrules');
        groupkey = "";
        jQuery.each (self.forms[f].dateminrules, function(r) {
          groupkey = r + '_group';
          self.groups[f][groupkey] = [];
          jQuery.each(this, function(){
            $('#' + f + ' #' + r + ' :input').not('input[type=image]').each(function(){
              self.groups[f][groupkey].push($(this).attr('name'));
            });
          });
        });
        self.time.stop('dateminrules');
      }

      if('datemaxrules' in self.forms[f]){
        self.time.start('datemaxrules');
        groupkey = "";
        jQuery.each (self.forms[f].datemaxrules, function(r) {
          groupkey = r + '_group';
          self.groups[f][groupkey] = [];
          jQuery.each(this, function(){
            $('#' + f + ' #' + r + ' :input').not('input[type=image]').each(function(){
              self.groups[f][groupkey].push($(this).attr('name'));
            });
          });
        });
        self.time.stop('datemaxrules');
      }


      // Add basic settings
      // todo: find cleaner fix
      // ugly fix for nodes in colorbox
      if(typeof $('#' + f).validate === 'function') {
        var validate_options = {
          errorClass: 'error',
          groups: self.groups[f],
          errorElement: self.forms[f].general.errorElement,
          unhighlight: function(element, errorClass, validClass) {
            var tab;
            // Default behavior
            $(element).removeClass(errorClass).addClass(validClass);

            // Sort the classes out for the tabs - we only want to remove the
            // highlight if there are no inputs with errors...
            var fieldset = $(element).parents('fieldset.vertical-tabs-pane');
            if (fieldset.size() && fieldset.find('.' + errorClass).not('label').size() === 0) {
              tab = self.findVerticalTab(element);
              if (tab) {
                tab.removeClass(errorClass).addClass(validClass);
              }
            }

            // Same for horizontal tabs
            fieldset = $(element).parents('fieldset.horizontal-tabs-pane');
            if (fieldset.size() && fieldset.find('.' + errorClass).not('label').size() === 0) {
              tab = self.findHorizontalTab(element);
              if (tab) {
                tab.removeClass(errorClass).addClass(validClass);
              }
            }
          },
          highlight: function(element, errorClass, validClass) {
            // Default behavior
            $(element).addClass(errorClass).removeClass(validClass);

            // Sort the classes out for the tabs
            var tab = self.findVerticalTab(element);
            if (tab) {
              tab.addClass(errorClass).removeClass(validClass);
            }
            tab = self.findHorizontalTab(element);
            if (tab) {
              tab.addClass(errorClass).removeClass(validClass);
            }
          },
          invalidHandler: function(form, validator) {
            var tab;
            if (validator.errorList.length > 0) {
              // Check if any of the errors are in the selected tab
              var errors_in_selected = false;
              for (var i = 0; i < validator.errorList.length; i++) {
                tab = self.findVerticalTab(validator.errorList[i].element);
                if (tab && tab.parent().hasClass('selected')) {
                  errors_in_selected = true;
                  break;
                }
              }

              // Only focus the first tab with errors if the selected tab doesn't have
              // errors itself. We shouldn't hide a tab that contains errors!
              if (!errors_in_selected) {
                tab = self.findVerticalTab(validator.errorList[0].element);
                if (tab) {
                  tab.click();
                }
              }

              // Same for vertical tabs
              // Check if any of the errors are in the selected tab
              errors_in_selected = false;
              for (i = 0; i < validator.errorList.length; i++) {
                tab = self.findHorizontalTab(validator.errorList[i].element);
                if (tab && tab.parent().hasClass('selected')) {
                  errors_in_selected = true;
                  break;
                }
              }

              // Only focus the first tab with errors if the selected tab doesn't have
              // errors itself. We shouldn't hide a tab that contains errors!
              if (!errors_in_selected) {
                tab = self.findHorizontalTab(validator.errorList[0].element);
                if (tab) {
                  tab.click();
                }
              }
              if (self.forms[f].general.scrollTo) {
                if (!$('html, body').hasClass('cv-scrolling')) {
                  var x;
                  if ($("#" + errorel).length) {
                    $("#" + errorel).show();
                    x = $("#" + errorel).offset().top - $("#" + errorel).height() - 100; // provides buffer in viewport
                  }
                  else {
                    x = $(validator.errorList[0].element).offset().top - $(validator.errorList[0].element).height() - 100;
                  }
                  $('html, body').addClass('cv-scrolling').animate(
                    {scrollTop: x},
                    {
                      duration: self.forms[f].general.scrollSpeed,
                      complete: function () {
                        $('html, body').removeClass('cv-scrolling')
                      }
                    }
                  );
                  $('.wysiwyg-toggle-wrapper a').each(function() {
                    $(this).click();
                    $(this).click();
                  });
                }
              }

              /**
               * Notify that the form contains errors.
               * @event clientsideValidationFormHasErrors
               * @name clientsideValidationFormHasErrors
               * @memberof Drupal.clientsideValidation
               */
              jQuery.event.trigger('clientsideValidationFormHasErrors', [form.target]);
            }
          }
        };

        switch (parseInt(self.forms[f].errorPlacement, 10)) {
          case 0: // CLIENTSIDE_VALIDATION_JQUERY_SELECTOR
            if ($(self.forms[f].errorJquerySelector).length) {
              if (!$(self.forms[f].errorJquerySelector + ' #' + errorel).length) {
                $('<div id="' + errorel + '" class="messages error clientside-error"><ul></ul></div>').prependTo(self.forms[f].errorJquerySelector).hide();
              }
            }
            else if (!$('#' + errorel).length) {
              $('<div id="' + errorel + '" class="messages error clientside-error"><ul></ul></div>').insertBefore('#' + f).hide();
            }
            validate_options.errorContainer = '#' + errorel;
            validate_options.errorLabelContainer = '#' + errorel + ' ul';
            validate_options.wrapper = 'li';
            break;
          case 1: // CLIENTSIDE_VALIDATION_TOP_OF_FORM
            if (!$('#' + errorel).length) {
              $('<div id="' + errorel + '" class="messages error clientside-error"><ul></ul></div>').insertBefore('#' + f).hide();
            }
            validate_options.errorContainer = '#' + errorel;
            validate_options.errorLabelContainer = '#' + errorel + ' ul';
            validate_options.wrapper = 'li';
            break;
          case 2: // CLIENTSIDE_VALIDATION_BEFORE_LABEL
            validate_options.errorPlacement = function(error, element) {
              var parents;
              if (element.is(":radio")) {
                parents = element.parents(".form-type-checkbox-tree");
                if(parents.length) {
                  error.insertBefore(parents.find("label").first());
                }
                else {
                  parents = element.parents('.form-radios').prev('label');
                  if (!parents.length) {
                    parents = 'label[for="'+ element.attr('id') +'"]';
                  }
                  error.insertBefore(parents);
                }
              }
              else if (element.is(":checkbox")) {
                parents = element.parents(".form-type-checkbox-tree");
                if(parents.length) {
                  error.insertBefore(parents.find("label").first());
                }
                else {
                  parents = element.parents('.form-radios').prev('label');
                  if (!parents.length) {
                    parents = 'label[for="'+ element.attr('id') +'"]';
                  }
                  error.insertBefore(parents);
                }
              }
              else {
                error.insertBefore('label[for="'+ element.attr('id') +'"]');
              }
            };
            break;
          case 3: // CLIENTSIDE_VALIDATION_AFTER_LABEL
            validate_options.errorPlacement = function(error, element) {
              var parents;
              if (element.is(":radio")) {
                parents = element.parents(".form-type-checkbox-tree");
                if(parents.length) {
                  error.insertAfter(parents.find("label").first());
                }
                else {
                  parents = element.parents('.form-radios').prev('label');
                  if (!parents.length) {
                    parents = 'label[for="'+ element.attr('id') +'"]';
                  }
                  error.insertAfter(parents);
                }
              }
              else if (element.is(":checkbox")) {
                parents = element.parents(".form-type-checkbox-tree");
                if(parents.length) {
                  error.insertAfter(parents.find("label").first());
                }
                else {
                  parents = element.parents('.form-checkboxes').prev('label');
                  if (!parents.length) {
                    parents = 'label[for="'+ element.attr('id') +'"]';
                  }
                  error.insertAfter(parents);
                }
              }
              else {
                error.insertAfter('label[for="'+ element.attr('id') +'"]');
              }
            };
            break;
          case 4: // CLIENTSIDE_VALIDATION_BEFORE_INPUT
            validate_options.errorPlacement = function(error, element) {
              error.insertBefore(element);
            };
            break;
          case 5: // CLIENTSIDE_VALIDATION_AFTER_INPUT
            validate_options.errorPlacement = function(error, element) {
              var parents;
              if (element.is(":radio")) {
                parents = element.parents(".form-type-checkbox-tree");
                if(parents.length) {
                  error.insertAfter(parents);
                }
                else {
                  parents = element.parents('.form-radios');
                  if (!parents.length) {
                    parents = element;
                  }
                  error.insertAfter(parents);
                }
              }
              else if (element.is(":checkbox")) {
                parents = element.parents(".form-type-checkbox-tree");
                if(parents.length) {
                  error.insertAfter(parents);
                }
                else {
                  parents = element.parents('.form-checkboxes');
                  if (!parents.length) {
                    parents = element;
                  }
                  error.insertAfter(parents);
                }
              }
              else if (element.next('div.grippie').length) {
                error.insertAfter(element.next('div.grippie'));
              } else {
                error.insertAfter(element);
              }
            };
            break;
          case 6: // CLIENTSIDE_VALIDATION_TOP_OF_FIRST_FORM
            if ($('div.messages.error').length) {
              if ($('div.messages.error').attr('id').length) {
                errorel = $('div.messages.error').attr('id');
              }
              else {
                $('div.messages.error').attr('id', errorel);
              }
            }
            else if (!$('#' + errorel).length) {
              $('<div id="' + errorel + '" class="messages error clientside-error"><ul></ul></div>').insertBefore('#' + f).hide();
            }
            validate_options.errorContainer = '#' + errorel;
            validate_options.errorLabelContainer = '#' + errorel + ' ul';
            validate_options.wrapper = 'li';
            break;
          case 7: // CLIENTSIDE_VALIDATION_CUSTOM_ERROR_FUNCTION
            validate_options.errorPlacement = function (error, element) {
              var func = self.forms[f].customErrorFunction;
              Drupal.myClientsideValidation[func](error, element);
            };
            break;
        }

        if (!self.forms[f].includeHidden) {
          validate_options.ignore = ':input:hidden';
        }
        else {
          validate_options.ignore = '';
        }
        if(self.forms[f].general.validateTabs) {
          if($('.vertical-tabs-pane input').length) {
            validate_options.ignore += ' :not(.vertical-tabs-pane :input, .horizontal-tabs-pane :input)';
          }
        }
        else {
          validate_options.ignore += ', .horizontal-tab-hidden :input';
        }
        //Since we can only give boolean false to onsubmit, onfocusout and onkeyup, we need
        //a lot of if's (boolean true can not be passed to these properties).
        if (!Boolean(parseInt(self.forms[f].general.validateOnSubmit, 10))) {
          validate_options.onsubmit = false;
        }
        if (!Boolean(parseInt(self.forms[f].general.validateOnBlur, 10))) {
          validate_options.onfocusout = false;
        }
        if (Boolean(parseInt(self.forms[f].general.validateOnBlurAlways, 10))) {
          validate_options.onfocusout = function(element) {
            if ( !this.checkable(element) ) {
              this.element(element);
            }
          };
        }
        if (!Boolean(parseInt(self.forms[f].general.validateOnKeyUp, 10))) {
          validate_options.onkeyup = false;
        }
        // Only apply this setting if errorplacement is set to the top of the form
        if (parseInt(self.forms[f].general.showMessages, 10) > 0 && parseInt(self.forms[f].errorPlacement, 10) === 1) {
          var showMessages = parseInt(self.forms[f].general.showMessages, 10);
          // Show only last message
          if (showMessages === 2) {
            validate_options.showErrors = function() {
              var allErrors = this.errors();
              var i;
              this.toHide = allErrors;
              $(':input.' + this.settings.errorClass).removeClass(this.settings.errorClass);
              for ( i = this.errorList.length -1; this.errorList[i]; i++ ) {
                var error = this.errorList[i];
                this.settings.highlight && this.settings.highlight.call( this, error.element, this.settings.errorClass, this.settings.validClass );
                this.showLabel( error.element, error.message );
              }
              if( this.errorList.length ) {
                this.toShow = this.toShow.add( this.containers );
              }
              if (this.settings.success) {
                for ( i = 0; this.successList[i]; i++ ) {
                  this.showLabel( this.successList[i] );
                }
              }
              if (this.settings.unhighlight) {
                var elements;
                for ( i = 0, elements = this.validElements(); elements[i]; i++ ) {
                  this.settings.unhighlight.call( this, elements[i], this.settings.errorClass, this.settings.validClass );
                }
              }
              this.toHide = this.toHide.not( this.toShow );
              this.hideErrors();
              this.addWrapper( this.toShow ).show();
            };
          }
          // Show only first message
          else if(showMessages === 1) {
            validate_options.showErrors = function() {
              var allErrors = this.errors();
              var i;
              var elements;
              if (this.settings.unhighlight) {
                var firstErrorElement = this.clean($(allErrors[0]).attr('for'));
                //for attr points to name or id
                if (typeof firstErrorElement === 'undefined') {
                  firstErrorElement = this.clean('#' + $(allErrors[0]).attr('for'));
                }
                for (i = 0, elements = this.elements().not($(firstErrorElement)); elements[i]; i++) {
                  this.settings.unhighlight.call( this, elements[i], this.settings.errorClass, this.settings.validClass );
                }
              }

              for ( i = 0; this.errorList[i] && i<1; i++ ) {
                var error = this.errorList[i];
                this.settings.highlight && this.settings.highlight.call( this, error.element, this.settings.errorClass, this.settings.validClass );
                this.showLabel( error.element, error.message );
              }
              if( this.errorList.length ) {
                this.toShow = this.toShow.add( this.containers );
              }
              if (this.settings.success) {
                for ( i = 0; this.successList[i]; i++ ) {
                  this.showLabel( this.successList[i] );
                }
              }
              if (this.settings.unhighlight) {
                for ( i = 0, elements = this.validElements(); elements[i]; i++ ) {
                  this.settings.unhighlight.call( this, elements[i], this.settings.errorClass, this.settings.validClass );
                }
              }

              this.toHide = this.toHide.not( this.toShow );
              this.hideErrors();
              this.addWrapper( this.toShow ).show();
              allErrors = this.errors();
              allErrors.splice(0,1);
              this.toHide = allErrors;
              this.hideErrors();
            };
          }
        }
        self.validators[f] = $('#' + f).validate(validate_options);

        // Disable HTML5 validation
        if (!Boolean(parseInt(self.forms[f].general.disableHtml5Validation, 10))) {
          $('#' + f).removeAttr('novalidate');
        }
        else {
          $('#' + f).attr('novalidate', 'novalidate');
        }
        // Bind all rules
        self.bindRules(f);

      }
    });
  self.time.stop('2. bindForms');
  };

  /**
   * Bind all rules.
   * @memberof Drupal.clientsideValidation
   */
  Drupal.clientsideValidation.prototype.bindRules = function(formid){
    var self = this;
    self.time.start('3. bindRules');
    var $form = $('#' + formid);
    var hideErrordiv = function(){
      //wait just one milisecond until the error div is updated
      window.setTimeout(function(){
        var visibles = 0;
        // @TODO: check settings
        $(".clientside-error ul li").each(function(){
          if($(this).is(':visible')){
            visibles++;
          }
          else {
            $(this).remove();
          }
        });
        if(visibles < 1){
          $(".clientside-error").hide();
        }
      }, 1);
    };
    if('checkboxrules' in self.forms[formid]){
      self.time.start('checkboxrules');
      jQuery.each (self.forms[formid].checkboxrules, function(r) {
        var $checkboxes = $form.find(this.checkboxgroupminmax[2]).find('input[type="checkbox"]');
        if ($checkboxes.length) {
          var identifier = 'require-one-' + this.checkboxgroupminmax[2].substring(1);
          var min = this.checkboxgroupminmax[0];
          var message = this.messages.checkboxgroupminmax;
          $checkboxes.addClass(identifier);
          $checkboxes.each(function(){
            var $checkbox = $(this);
            var newrule = {
              require_from_group: [min, '.' + identifier]
            };
            $checkbox.rules("add", newrule);
            $checkbox.change(hideErrordiv);

            if (typeof self.validators[formid].settings.messages[$checkbox.attr('name')] === 'undefined') {
              self.validators[formid].settings.messages[$checkbox.attr('name')] = {};
            }
            $.extend(self.validators[formid].settings.messages[$checkbox.attr('name')], {
              require_from_group: message
            });
          });

          if (typeof self.validators[formid].settings.messages['.' + identifier] === 'undefined') {
            self.validators[formid].settings.messages['.' + identifier] = {};
          }
          $.extend(self.validators[formid].settings.messages['.' + identifier], {
            require_from_group: message
          });
        }
      });
      self.time.stop('checkboxrules');
    }
    if('daterangerules' in self.forms[formid]){
      self.time.start('daterangerules');
      jQuery.each (self.forms[formid].daterangerules, function(r) {
        $form.find('#' + r).find('input, select').not('input[type=image]').each(function(){
          // Make sure we are working with the copy of rules object.
          var rule = jQuery.extend(true, {}, self.forms[formid].daterangerules[r]);
          if (typeof self.validators[formid].settings.messages[r] === 'undefined') {
            self.validators[formid].settings.messages[r] = {};
          }
          $.extend(self.validators[formid].settings.messages[r], rule.messages);
          delete rule.messages;
          $(this).rules("add", rule);
          $(this).blur(hideErrordiv);
        });
      });
      self.time.stop('daterangerules');
    }

    if('dateminrules' in self.forms[formid]){
      self.time.start('dateminrules');
      jQuery.each (self.forms[formid].dateminrules, function(r) {
        $form.find('#' + r).find('input, select').not('input[type=image]').each(function(){
          // Make sure we are working with the copy of rules object.
          var rule = jQuery.extend(true, {}, self.forms[formid].dateminrules[r]);
          if (typeof self.validators[formid].settings.messages[r] === 'undefined') {
            self.validators[formid].settings.messages[r] = {};
          }
          $.extend(self.validators[formid].settings.messages[r], rule.messages);
          delete rule.messages;
          $(this).rules("add", rule);
          $(this).blur(hideErrordiv);
        });
      });
      self.time.stop('dateminrules');
    }

    if('datemaxrules' in self.forms[formid]){
      self.time.start('datemaxrules');
      jQuery.each (self.forms[formid].datemaxrules, function(r) {
        $form.find('#' + r).find('input, select').not('input[type=image]').each(function(){
          // Make sure we are working with the copy of rules object.
          var rule = jQuery.extend(true, {}, self.forms[formid].datemaxrules[r]);
          if (typeof self.validators[formid].settings.messages[r] === 'undefined') {
            self.validators[formid].settings.messages[r] = {};
          }
          $.extend(self.validators[formid].settings.messages[r], rule.messages);
          delete rule.messages;
          $(this).rules("add", rule);
          $(this).blur(hideErrordiv);
        });
      });
      self.time.stop('datemaxrules');
    }

    if ('rules' in self.forms[formid]) {
      self.time.start('rules');
      // Make sure we are working with the copy of rules object.
      var rules = jQuery.extend(true, {}, self.forms[formid].rules);
      // :input can be slow, see http://jsperf.com/input-vs-input/2
      $form.find('input, textarea, select').each(function(idx, elem) {
        var rule = rules[elem.name];
        if (rule) {
          var $elem = $(elem);
          if (typeof self.validators[formid].settings.messages[elem.name] === 'undefined') {
            self.validators[formid].settings.messages[elem.name] = {};
          }
          $.extend(self.validators[formid].settings.messages[elem.name], rule.messages);
          delete rule.messages;
          $elem.rules("add",rule);
          $elem.change(hideErrordiv);
        }
      });
      self.time.stop('rules');
    }
    self.time.stop('3. bindRules');
  };

  /**
   * Add extra rules.
   * @memberof Drupal.clientsideValidation
  */
  Drupal.clientsideValidation.prototype.addExtraRules = function(){
    var self = this;

    jQuery.validator.addMethod("numberDE", function(value, element) {
      return this.optional(element) || /^-?(?:\d+|\d{1,3}(?:\.\d{3})+)(?:,\d+)?$/.test(value);
    });

    jQuery.validator.addMethod("min_comma", function(value, element, param) {
      var real_val = Number(value.replace(',', '.'));
      return this.optional(element) || real_val >= param;
    });

    jQuery.validator.addMethod("max_comma", function(value, element, param) {
      var real_val = Number(value.replace(',', '.'));
      return this.optional(element) || real_val <= param;
    });

    jQuery.validator.addMethod("range_comma", function(value, element, param) {
      var real_val = Number(value.replace(',', '.'));
      return this.optional(element) || (real_val >= param[0] && real_val <= param[1]);
    });

    // Min a and maximum b checkboxes from a group
    jQuery.validator.addMethod("checkboxgroupminmax", function(value, element, param) {
      var amountChecked = $(param[2]).find('input:checked').length;
      return (amountChecked >= param[0] && amountChecked <= param[1]);
    }, jQuery.format('Minimum {0}, maximum {1}'));

    // Allow integers, same as digits but including a leading '-'
    jQuery.validator.addMethod("digits_negative", function(value, element) {
      return this.optional(element) || /^-?\d+$/.test(value);
    }, jQuery.format('Please enter only digits.'));

    // One of the values
    jQuery.validator.addMethod("oneOf", function(value, element, param) {
      for (var p in param.values) {
        if (param.values[p] === value && param.caseSensitive) {
          return !param.negate;
        }
        else if (param.values[p].toLowerCase() === value.toLowerCase() && !param.caseSensitive) {
          return !param.negate;
        }
      }
      return param.negate;
    }, jQuery.format(''));

    jQuery.validator.addMethod("specificVals", function(value, element, param){
      for (var i in value) {
        if(param.indexOf(value[i]) === -1) {
            return false;
        }
      }
      return true;
    });

    jQuery.validator.addMethod("blacklist", function(value, element, param) {
      if (typeof(value) !== 'object') {
        value = value.split(' ');
      }
      for (var i in value) {
        if(param.values.indexOf(value[i]) !== -1) {
            return param.negate;
        }
      }
      return !param.negate;
    });

    // Default regular expression support
    var ajaxPCREfn = function(value, element, param) {
      var result = false;
      jQuery.ajax({
        'url': Drupal.settings.basePath + 'clientside_validation/ajax',
        'type': "POST",
        'data': {
          'value': value,
          'param': param
        },
        'dataType': 'json',
        'async': false,
        'success': function(res){
          result = res;
        }
      });
      if (result.result === false) {
        if (result.message.length) {
          jQuery.extend(jQuery.validator.messages, {
            "regexMatchPCRE": result.message
          });
        }
      }
      return result.result;
    };

    // Regular expression support using XRegExp
    var xregexPCREfn = function(value, element, param) {
      if (window.XRegExp && XRegExp.version ) {
        try {
          var result = true;
          for (var i = 0; i < param.expressions.length; i++) {
            var reg = param.expressions[i];
            var delim = reg.lastIndexOf(reg.charAt(0));
            // Only allow supported modifiers
            var modraw = reg.substr(delim + 1) || '';
            var mod = '';
            if (mod !== '') {
              for (var l = 0; l < 6; l++) {
                if (modraw.indexOf('gimnsx'[l]) !== -1) {
                  mod += 'gimnsx'[l];
                }
              }
            }
            reg = reg.substring(1, delim);
            if (!(new XRegExp(reg, mod).test(value))) {
              result = false;
              if (param.messages[i].length) {
                jQuery.extend(jQuery.validator.messages, {
                  "regexMatchPCRE": param.messages[i]
                });
              }
            }
          }
          return result;
        }
        catch (e) {
          return ajaxPCREfn(value, element, param);
        }
      }
      else {
        return ajaxPCREfn(value, element, param);
      }
    };

    // Decide which one to use
    if (self.data.general.usexregxp) {
      jQuery.validator.addMethod("regexMatchPCRE", xregexPCREfn, jQuery.format('The value does not match the expected format.'));
    }
    else {
      jQuery.validator.addMethod("regexMatchPCRE", ajaxPCREfn, jQuery.format('The value does not match the expected format.'));
    }

    // Unique values
    jQuery.validator.addMethod("notEqualTo", function(value, element, param) {
      var ret = true;
      jQuery.each(param, function (index, selector){
        var $target = $(selector);
        $target.unbind(".validate-notEqualTo").bind("blur.validate-notEqualTo", function() {
          $(element).valid();
        });
        ret = ret && ($target.val() !== value);
      });
      return ret;
    }, jQuery.format('Please don\'t enter the same value again.'));

    jQuery.validator.addMethod("regexMatch", function(value, element, param) {
      if (this.optional(element) && value === '') {
        return this.optional(element);
      }
      else {
        var modifier = param.regex[1];
        var valid_modifiers = ['i', 'g', 'm'];
        if (jQuery.inArray(modifier, valid_modifiers) === -1) {
          modifier = '';
        }
        var regexp = new RegExp(param.regex[0], modifier);
        if(regexp.test(value)){
          return !param.negate;
        }
        return param.negate;
      }

    }, jQuery.format('The value does not match the expected format.'));

    jQuery.validator.addMethod("captcha", function (value, element, param) {
      var result = false;
      var sid = $(element).closest('.captcha').find('input[name=captcha_sid]').val();
      jQuery.ajax({
        'url': Drupal.settings.basePath + 'clientside_validation/captcha',
        'type': "POST",
        'data': {
          'value': value,
          'param': [sid, param]
        },
        'dataType': 'json',
        'async': false,
        'success': function(res){
          result = res;
        }
      });
      if (result.result === false) {
        if (typeof result.message !== 'undefined' && result.message.length) {
          jQuery.extend(jQuery.validator.messages, {
            "captcha": result.message
          });
        }
      }
      return result.result;
    }, jQuery.format('Wrong answer.'));

    jQuery.validator.addMethod("rangewords", function(value, element, param) {
      return this.optional(element) || (param[0] <= jQuery.trim(value).split(/\s+/).length && value.split(/\s+/).length <= param[1]);
    }, jQuery.format('The value must be between {0} and {1} words long'));

    jQuery.validator.addMethod("minwords", function(value, element, param) {
      return this.optional(element) || param <= jQuery.trim(value).split(/\s+/).length;
    }, jQuery.format('The value must be more than {0} words long'));

    jQuery.validator.addMethod("maxwords", function(value, element, param) {
      return this.optional(element) || jQuery.trim(value).split(/\s+/).length <= param;
    }, jQuery.format('The value must be fewer than {0} words long'));

    jQuery.validator.addMethod("plaintext", function(value, element, param){
      var result = param.negate ? (value !== strip_tags(value, param.tags)) : (value === strip_tags(value, param.tags));
      return this.optional(element) || result;
    }, jQuery.format('The value must be plaintext'));

    jQuery.validator.addMethod("selectMinlength", function(value, element, param) {
      var result = $(element).find('option:selected').length >= param.min;
      if (param.negate) {
        result = !result;
      }
      return this.optional(element) || result;
    }, jQuery.format('You must select at least {0} values'));

    jQuery.validator.addMethod("selectMaxlength", function(value, element, param) {
      var result = $(element).find('option:selected').length <= param.max;
      if (param.negate) {
        result = !result;
      }
      return this.optional(element) || result;
    }, jQuery.format('You must select a maximum of {0} values'));

    jQuery.validator.addMethod("selectRangelength", function(value, element, param) {
      var result = ($(element).find('option:selected').length >= param.range[0] && $(element).find('option:selected').length <= param.range[1]);
      if (param.negate) {
        result = !result;
      }
      return this.optional(element) || result;
    }, jQuery.format('You must select at between {0} and {1} values'));

    jQuery.validator.addMethod("datemin", function(value, element, param) {
      //Assume [month], [day], and [year] ??
      var dayelem, monthelem, yearelem, name, $form, element_name;
      $form = $(element).closest('form');
      element_name = $(element).attr('name');
      if (element_name.indexOf('[day]') > 0) {
        dayelem = $(element);
        name = dayelem.attr('name').replace('[day]', '');
        monthelem = $form.find("[name='" + name + "[month]']");
        yearelem = $form.find("[name='" + name + "[year]']");
      }
      else if (element_name.indexOf('[month]') > 0) {
        monthelem = $(element);
        name = monthelem.attr('name').replace('[month]', '');
        dayelem = $form.find("[name='" + name + "[day]']");
        yearelem = $form.find("[name='" + name + "[year]']");
      }
      else if ($(element).attr('name').indexOf('[year]') > 0) {
        yearelem = $(element);
        name = yearelem.attr('name').replace('[year]', '');
        dayelem = $form.find("[name='" + name + "[day]']");
        monthelem = $form.find("[name='" + name + "[month]']");
      }

      if (parseInt(yearelem.val(), 10) < parseInt(param[0], 10)) {
        return false;
      }
      else if (parseInt(yearelem.val(), 10) === parseInt(param[0], 10)){
        if (parseInt(monthelem.val(), 10) < parseInt(param[1], 10)){
          return false;
        }
        else if (parseInt(monthelem.val(), 10) === parseInt(param[1], 10)){
          if(parseInt(dayelem.val(), 10) < parseInt(param[2], 10)) {
            return false;
          }
        }
      }
      yearelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      monthelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      dayelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      return true;
    });

    jQuery.validator.addMethod("datemax", function(value, element, param) {
      //Assume [month], [day], and [year] ??
      var dayelem, monthelem, yearelem, name, $form, element_name;
      $form = $(element).closest('form');
      element_name = $(element).attr('name');
      if (element_name.indexOf('[day]') > 0) {
        dayelem = $(element);
        name = dayelem.attr('name').replace('[day]', '');
        monthelem = $form.find("[name='" + name + "[month]']");
        yearelem = $form.find("[name='" + name + "[year]']");
      }
      else if (element_name.indexOf('[month]') > 0) {
        monthelem = $(element);
        name = monthelem.attr('name').replace('[month]', '');
        dayelem = $form.find("[name='" + name + "[day]']");
        yearelem = $form.find("[name='" + name + "[year]']");
      }
      else if (element_name.indexOf('[year]') > 0) {
        yearelem = $(element);
        name = yearelem.attr('name').replace('[year]', '');
        dayelem = $form.find("[name='" + name + "[day]']");
        monthelem = $form.find("[name='" + name + "[month]']");

      }

      if (parseInt(yearelem.val(), 10) > parseInt(param[0], 10)) {
        return false;
      }
      else if (parseInt(yearelem.val(), 10) === parseInt(param[0], 10)){
        if (parseInt(monthelem.val(), 10) > parseInt(param[1], 10)){
          return false;
        }
        else if (parseInt(monthelem.val(), 10) === parseInt(param[1], 10)){
          if(parseInt(dayelem.val(), 10) > parseInt(param[2], 10)) {
            return false;
          }
        }
      }
      yearelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      monthelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      dayelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      return true;
    });

    jQuery.validator.addMethod("daterange", function(value, element, param) {
      //Assume [month], [day], and [year] ??
      var dayelem, monthelem, yearelem, name, $form, element_name;
      $form = $(element).closest('form');
      element_name = $(element).attr('name');
      if (element_name.indexOf('[day]') > 0) {
        dayelem = $(element);
        name = dayelem.attr('name').replace('[day]', '');
        monthelem = $form.find("[name='" + name + "[month]']");
        yearelem = $form.find("[name='" + name + "[year]']");
      }
      else if (element_name.indexOf('[month]') > 0) {
        monthelem = $(element);
        name = monthelem.attr('name').replace('[month]', '');
        dayelem = $form.find("[name='" + name + "[day]']");
        yearelem = $form.find("[name='" + name + "[year]']");
      }
      else if (element_name.indexOf('[year]') > 0) {
        yearelem = $(element);
        name = yearelem.attr('name').replace('[year]', '');
        dayelem = $form.find("[name='" + name + "[day]']");
        monthelem = $form.find("[name='" + name + "[month]']");
      }

      if (parseInt(yearelem.val(), 10) < parseInt(param[0][0], 10)) {
        return false;
      }
      else if (parseInt(yearelem.val(), 10) === parseInt(param[0][0], 10)){
        if (parseInt(monthelem.val(), 10) < parseInt(param[0][1], 10)){
          return false;
        }
        else if (parseInt(monthelem.val(), 10) === parseInt(param[0][1], 10)){
          if(parseInt(dayelem.val(), 10) < parseInt(param[0][2], 10)) {
            return false;
          }
        }
      }

      if (parseInt(yearelem.val(), 10) > parseInt(param[1][0], 10)) {
        return false;
      }
      else if (parseInt(yearelem.val(), 10) === parseInt(param[1][0], 10)){
        if (parseInt(monthelem.val(), 10) > parseInt(param[1][1], 10)){
          return false;
        }
        else if (parseInt(monthelem.val(), 10) === parseInt(param[1][1], 10)){
          if(parseInt(dayelem.val(), 10) > parseInt(param[1][2], 10)) {
            return false;
          }
        }
      }
      yearelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      monthelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      dayelem.once('daterange', function() {
        $(this).change(function(){$(this).trigger('focusout').trigger('blur');});
      }).removeClass('error');
      return true;
    });

    jQuery.validator.addMethod("dateFormat", function(value, element, param) {
      try{
        var parts = value.split(param.splitter);
        var expectedpartscount = 0;
        var day = parseInt(parts[param.daypos], 10);

        var month = parseInt(parts[param.monthpos], 10);
        if (isNaN(month)) {
          var date_parts = param.format.split(param.splitter);
          var full_idx = date_parts.indexOf("F");
          var abbr_idx = date_parts.indexOf("M");
          var mopos = Math.max(full_idx, abbr_idx);
          if (parseInt(mopos) > -1) {
            param.monthpos = mopos;
            date = new Date(parts[param.monthpos] + " 1, 2000");
            month = date.getMonth();
          }
          else {
            if (typeof Drupal.settings.clientsideValidation.general.months[parts[param.monthpos]] !== 'undefined') {
              month = Drupal.settings.clientsideValidation.general.months[parts[param.monthpos]];
            }
            else {
              month = new Date(parts[param.monthpos] + " 1, 2000");
              month = month.getMonth();
            }
          }
        }
        else {
          month--;
        }

        var year = parseInt(parts[param.yearpos], 10);
        var date = new Date();
        var result = true;
        if (param.daypos !== false && parts[param.daypos].toString().length !== parts[param.daypos].length){
          result = false;
        }
        if (param.monthpos !== false && parts[param.monthpos].toString().length !== parts[param.monthpos].length){
          result = false;
        }
        if (param.yearpos !== false && parts[param.yearpos].toString().length !== parts[param.yearpos].length){
          result = false;
        }
        if (param.yearpos !== false){
          expectedpartscount++;
          date.setFullYear(year);
          if (year !== date.getFullYear()) {
            result = false;
          }
        }
        if (param.monthpos !== false) {
          expectedpartscount++;
          date.setMonth(month, 1);
          if (month !== date.getMonth()) {
            result = false;
          }
        }
        if (param.daypos !== false) {
          expectedpartscount++;
          date.setDate(day);
          if (day !== date.getDate()) {
            result = false;
          }
        }
        if (expectedpartscount !== parts.length) {
          result = false;
        }
        return this.optional(element) || result;
      } catch(e) {
        return this.optional(element) || false;
      }
    }, jQuery.format('The date is not in a valid format'));

    // Require one of several
    jQuery.validator.addMethod("requireOneOf", function(value, element, param) {
      var ret = false;
      if (value === "") {
        jQuery.each(param, function(index, name) {
          // @TODO: limit to current form
          if (!ret && $("[name='" + name + "']").val().length) {
            ret = true;
          }
        });
      }
      else {
        $(element).removeClass("error");
        ret = true;
      }
      $(element).blur(function () {
        jQuery.each(param, function(index, name) {
          // @TODO: limit to current form
          $("[name='" + name + "']").valid();
        });
      });
      return ret;
    }, jQuery.format('Please fill in at least one of the fields'));

    // Support for Drupal urls.
    jQuery.validator.addMethod("drupalURL", function(value, element) {
      var result = false;
      if (this.settings['name_event'] == 'onkeyup') {
        return true;
      }
      if (jQuery.validator.methods.url.call(this, value, element)) {
        return true;
      }
      jQuery.ajax({
        'url': Drupal.settings.basePath + 'clientside_validation/drupalURL',
        'type': "POST",
        'data': {
          'value': value
        },
        'dataType': 'json',
        'async': false,
        'success': function(res){
          result = res;
        }
      });
      return result.result;
    }, jQuery.format('Please fill in a valid url'));

    // Support for phone
    jQuery.validator.addMethod("phone", function(value, element, param) {
      var country_code = param;
      var result = false;
      jQuery.ajax({
        'url': Drupal.settings.basePath + 'clientside_validation/phone',
        'type': "POST",
        'data': {
          'value': value,
          'country_code': country_code
        },
        'dataType': 'json',
        'async': false,
        'success': function(res){
          result = res;
        }
      });
      return this.optional(element) || result.result;

    }, jQuery.format('Please fill in a valid phone number'));

    // EAN code
    jQuery.validator.addMethod("validEAN", function(value, element) {
      if (this.optional(element) && value === '') {
        return this.optional(element);
      }
      else {
        if (value.length > 13) {
          return false;
        }
        else if (value.length !== 13) {
          value = '0000000000000'.substr(0, 13 - value.length).concat(value);
        }
        if (value === '0000000000000') {
          return false;
        }
        if (isNaN(parseInt(value, 10)) || parseInt(value, 10) === 0) {
          return false;
        }
        var runningTotal = 0;
        for (var c = 0; c < 12; c++) {
          if (c % 2 === 0) {
            runningTotal += 3 * parseInt(value.substr(c, 1), 10);
          }
          else {
            runningTotal += parseInt(value.substr(c, 1), 10);
          }
        }
        var rem = runningTotal % 10;
        if (rem !== 0) {
          rem = 10 - rem;
        }

        return rem === parseInt(value.substr(12, 1), 10);

      }
    }, jQuery.format('Not a valid EAN number.'));

    jQuery.validator.addMethod("require_from_group", function(value, element, options) {
      var $fields = $(options[1], element.form),
        $fieldsFirst = $fields.eq(0),
        validator = $fieldsFirst.data("valid_req_grp") ? $fieldsFirst.data("valid_req_grp") : $.extend({}, this),
        isValid = $fields.filter(function() {
          return validator.elementValue(this);
        }).length >= options[0];

      // Store the cloned validator for future validation
      $fieldsFirst.data("valid_req_grp", validator);

      // If element isn't being validated, run each require_from_group field's validation rules
      if (!$(element).data("being_validated")) {
        $fields.data("being_validated", true);
        $fields.each(function() {
          validator.element(this);
        });
        $fields.data("being_validated", false);
      }
      return isValid;
    }, jQuery.validator.format("Please fill at least {0} of these fields."));

    /**
     * Allow other modules to add more rules.
     * @event clientsideValidationAddCustomRules
     * @name clientsideValidationAddCustomRules
     * @memberof Drupal.clientsideValidation
     */
    jQuery.event.trigger('clientsideValidationAddCustomRules');


    /**
     * strip illegal tags
     * @memberof Drupal.clientsideValidation
     * @private
     */
    function strip_tags (input, allowed) {
      allowed = (((allowed || "") + "").toLowerCase().match(/<[a-z][a-z0-9]*>/g) || []).join(''); // making sure the allowed arg is a string containing only tags in lowercase (<a><b><c>)
      var tags = /<\/?([a-z][a-z0-9]*)\b[^>]*>/gi,
          commentsAndPhpTags = /<!--[\s\S]*?-->|<\?(?:php)?[\s\S]*?\?>/gi;
      return input.replace(commentsAndPhpTags, '').replace(tags, function ($0, $1) {
        return allowed.indexOf('<' + $1.toLowerCase() + '>') > -1 ? $0 : '';
      });
    }
  };

  Drupal.behaviors.ZZZClientsideValidation = {
    attach: function () {
      function changeAjax(ajax_el) {
        var origBeforeSubmit = Drupal.ajax[ajax_el].options.beforeSubmit;
        Drupal.ajax[ajax_el].options.beforeSubmit = function (form_values, element, options) {
          var ret = origBeforeSubmit(form_values, element, options);
          // If this function didn't return anything, just set the return value to true.
          // If it did return something, allow it to prevent submit if necessary.
          if (typeof ret === 'undefined') {
            ret = true;
          }
          var id = element.is('form') ? element.attr('id') : element.closest('form').attr('id');
          if (id && Drupal.myClientsideValidation.validators[id]) {
            Drupal.myClientsideValidation.validators[id].onsubmit = false;
            ret = ret && Drupal.myClientsideValidation.validators[id].form();
            if (!ret) {
              Drupal.ajax[ajax_el].ajaxing = false;
            }
          }
          return ret;
        };
      }
      // Set validation for ctools modal forms
      for (var ajax_el in Drupal.ajax) {
        if (Drupal.ajax.hasOwnProperty(ajax_el) && typeof Drupal.ajax[ajax_el] !== 'undefined') {
          var $ajax_el = jQuery(Drupal.ajax[ajax_el].element);
          var ajax_form = $ajax_el.is('form') ? $ajax_el.attr('id') : $ajax_el.closest('form').attr('id');
          var change_ajax = true;
          if (typeof Drupal.myClientsideValidation.forms[ajax_form] !== 'undefined') {
            change_ajax = Boolean(parseInt(Drupal.myClientsideValidation.forms[ajax_form].general.validateBeforeAjax, 10));
          }
          if (!$ajax_el.hasClass('cancel') && change_ajax) {
            changeAjax(ajax_el);
          }
        }
      }
    }
  };
})(jQuery);
