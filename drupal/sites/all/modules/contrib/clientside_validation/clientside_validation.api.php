<?php
/**
 * @file
 * This is the api documentation for clientside validation hooks.
 */

/**
 * Some modules allow users to define extra validation rules defined in a hook.
 * (e.g hook_webform_validation_validators()). To support these custom rules,
 * clientside validation has its own hook, hook_clientside_validation_rule_alter.
 * We had to use an 'alter' hook because module_invoke and module_invoke_all
 * does not support passing arguments by reference, drupal_alter does.
 *
 * If you want to add support for your custom validation rules defined for
 * webform_validation, fapi_validation or field_validation, you can use this
 * hook. Every validation rule that is defined for any of these modules and
 * is not implemented as standard by clientside_validation is passed through to
 * this hook (given that the related clientside validation module is enabled and
 * that clientside validation is enabled for the specific form).
 *
 * The first parameter to this hook is an array. This array, consitently named
 * $js_rules, is passed by reference throughout the entire module and is the key
 * to the entire functionality of this module.
 *
 * The second parameter is the form element or webform component (dependend on
 * third parameter)
 *
 * The third parameter, named $context, is a structured array. It consists of
 * the following keys:
 *  'type':       The type of form validation we are dealing with. Can be either
 *                'webform', 'fapi', 'field_validation' or 'element_validate'.
 *  'rule':       An array representing the webform validation, fapi validation or
 *                field validation rule. Only present when 'type' is 'webform', 'fapi'
 *                or 'field_validation'.
 *  'functions':  An array of functions found in the '#element_validate' of the element.
 *                Only present if type is 'element_validate'.
 *  'message':    The default error message for when this rule does not pass
 *                validation.Only present when 'type' is 'webform', 'fapi'
 *                or 'field_validation'.
 *
 * @param array $js_rules
 * An array structured like this:
 * $js_rules[$inputname][$rulename] = $parameters;
 * $js_rules[$inputname]['messages'][$rulename] = $message;
 * Where $inputname is the name attribute of the input element, $rulename is
 * the name of the rule (e.g. 'email'), $parameters is either TRUE (e.g. for
 * 'email') or an array (e.g. for 'range': array(2, 10) or 'max_length' array(10)) and
 * $message is the error message displayed when the validation does not pass.
 * @param array $element
 * Either a form element or a webform component.
 * @param array $context
 * A structured array consiting of the following keys:
 *  'type':       The type of form validation we are dealing with. Can be either
 *                'webform', 'fapi', 'field_validation' or 'element_validate'.
 *  'rule':       An array representing the webform validation, fapi validation or
 *                field validation rule. Only present when 'type' is 'webform', 'fapi'
 *                or 'field_validation'.
 *  'functions':  An array of functions found in the '#element_validate' of the element.
 *                Only present if type is 'element_validate'.
 *  'message':    The default error message for when this rule does not pass
 *                validation.Only present when 'type' is 'webform', 'fapi'
 *                or 'field_validation'.
 *
 * In the example below we use validations that are already implemented as usage
 * examples. In the example the following rules are implemented for clientside
 * validation:
 *  - minimum length for webform_validation
 *  - specific characters for fapi_validation
 *  - regular expression for field_validation
 */
function hook_clientside_validation_rule_alter(&$js_rules, $element, $context) {
  switch ($context['type']) {
    case 'webform':
      if ($context['rule']['validator'] == 'min_length') {
        _clientside_validation_set_minmaxlength($component['element_name'], $component['element_title'], $context['rule']['data'], '', $js_rules, $context['message']);
      }
      break;

    case 'fapi':
      if ($context['rule']['callback'] == 'fapi_validation_rule_chars') {
        _clientside_validation_set_specific_values($element['#name'], $element['#title'], $context['params'], $js_rules);
      }
      break;

    case 'field_validation':
      if ($context['rule']['validator'] == 'regex') {
        _clientside_validation_set_regex($element['#name'], $element['#title'], $js_rules, $context['rule']['data'], $context['message']);
      }
      break;

    case 'element_validate':
      if (in_array('_container_validate', $context['functions'])) {
        _clientside_validation_set_not_equal(
          $element['textfield_one']['#name'],
          $element['textfield_one']['#title'],
          array(
            array(
            'form_key' => $element['textfield_two']['#name'],
            'name' => $element['textfield_two']['#title']
            ),
          ),
          $js_rules,
          t("The two fields cannot have the same value")
        );
      }
      break;

    default:
      break;
  }
}
