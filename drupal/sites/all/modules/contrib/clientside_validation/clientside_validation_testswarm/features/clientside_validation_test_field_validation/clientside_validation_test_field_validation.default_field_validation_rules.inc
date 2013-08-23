<?php
/**
 * @file
 * clientside_validation_test_field_validation.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function clientside_validation_test_field_validation_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_blacklist';
  $rule->name = 'cv_blacklist';
  $rule->field_name = 'field_blacklist';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_blacklist_validator';
  $rule->settings = array(
    'data' => 'black,list',
    'errors' => 0,
  );
  $rule->error_message = 'Field can not contain the words \'black\' or \'list\'';
  $export['cv_blacklist'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_email';
  $rule->name = 'cv_email';
  $rule->field_name = 'field_cv_email';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_email_validator';
  $rule->settings = array(
    'errors' => 0,
  );
  $rule->error_message = 'Field must be a valid email address';
  $export['cv_email'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_max_length';
  $rule->name = 'cv_max_length';
  $rule->field_name = 'field_max_length';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '10',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be maximum 10 letters';
  $export['cv_max_length'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_max_words';
  $rule->name = 'cv_max_words';
  $rule->field_name = 'field_max_words';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_words_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '10',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be maximum 10 words long';
  $export['cv_max_words'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_min_length';
  $rule->name = 'cv_min_length';
  $rule->field_name = 'field_min_length';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '5',
    'max' => '',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be minimum 5 letters';
  $export['cv_min_length'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_min_words';
  $rule->name = 'cv_min_words';
  $rule->field_name = 'field_min_words';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_words_validator';
  $rule->settings = array(
    'min' => '5',
    'max' => '',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be minimum 5 words long';
  $export['cv_min_words'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_must_be_empty';
  $rule->name = 'cv_must_be_empty';
  $rule->field_name = 'field_empty';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_must_be_empty_validator';
  $rule->settings = array(
    'errors' => 0,
  );
  $rule->error_message = 'Field must be empty';
  $export['cv_must_be_empty'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_numeric';
  $rule->name = 'cv_numeric';
  $rule->field_name = 'field_numeric';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_numeric2_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be numeric';
  $export['cv_numeric'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_numeric_max';
  $rule->name = 'cv_numeric_max';
  $rule->field_name = 'field_numeric_max';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_numeric2_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '10',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be numeric & smaller than 10';
  $export['cv_numeric_max'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_numeric_min';
  $rule->name = 'cv_numeric_min';
  $rule->field_name = 'field_numeric_min';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_numeric2_validator';
  $rule->settings = array(
    'min' => '5',
    'max' => '',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be numeric & greater than 5';
  $export['cv_numeric_min'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_numeric_range';
  $rule->name = 'cv_numeric_range';
  $rule->field_name = 'field_numeric_range';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_numeric2_validator';
  $rule->settings = array(
    'min' => '5',
    'max' => '10',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be numeric and between 5 and 10';
  $export['cv_numeric_range'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_plain_text';
  $rule->name = 'cv_plain_text';
  $rule->field_name = 'field_plain_text';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_plain_text_validator';
  $rule->settings = array(
    'errors' => 0,
  );
  $rule->error_message = 'Field must be plain text';
  $export['cv_plain_text'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_range_length';
  $rule->name = 'cv_range_length';
  $rule->field_name = 'field_range_length';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_length_validator';
  $rule->settings = array(
    'min' => '5',
    'max' => '10',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be between 5 and 10 characters long';
  $export['cv_range_length'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_range_words';
  $rule->name = 'cv_range_words';
  $rule->field_name = 'field_range_words';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_words_validator';
  $rule->settings = array(
    'min' => '5',
    'max' => '10',
    'errors' => 0,
  );
  $rule->error_message = 'Field must be between 5 and 10 words long';
  $export['cv_range_words'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_regex';
  $rule->name = 'cv_regex';
  $rule->field_name = 'field_regex';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_regex_validator';
  $rule->settings = array(
    'data' => '[a-z0-9_]+$',
    'errors' => 0,
  );
  $rule->error_message = 'Must be a valid machine readable name';
  $export['cv_regex'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_select_max';
  $rule->name = 'cv_select_max';
  $rule->field_name = 'field_select_max';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_number_of_selections_validator';
  $rule->settings = array(
    'min' => '',
    'max' => '5',
    'errors' => 0,
  );
  $rule->error_message = 'You can\'t select more than 5 options';
  $export['cv_select_max'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_select_min';
  $rule->name = 'cv_select_min';
  $rule->field_name = 'field_select_min';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_number_of_selections_validator';
  $rule->settings = array(
    'min' => '2',
    'max' => '',
    'errors' => 0,
  );
  $rule->error_message = 'You must select at least 2 options';
  $export['cv_select_min'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_select_range';
  $rule->name = 'cv_select_range';
  $rule->field_name = 'field_select_range';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_number_of_selections_validator';
  $rule->settings = array(
    'min' => '2',
    'max' => '5',
    'errors' => 0,
  );
  $rule->error_message = 'You must select between 2 and 5 options';
  $export['cv_select_range'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_specific_value';
  $rule->name = 'cv_specific_value';
  $rule->field_name = 'field_specific_val';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_specific_value_validator';
  $rule->settings = array(
    'data' => 'abc-123',
    'errors' => 0,
  );
  $rule->error_message = 'Field must equal \'abc-123\'';
  $export['cv_specific_value'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'cv_url';
  $rule->name = 'cv_url';
  $rule->field_name = 'field_url';
  $rule->col = 'value';
  $rule->entity_type = 'node';
  $rule->bundle = 'cv_test_field_validation';
  $rule->validator = 'field_validation_url_validator';
  $rule->settings = array(
    'external' => 1,
    'internal' => 0,
    'errors' => 0,
  );
  $rule->error_message = 'Field must be a valid url';
  $export['cv_url'] = $rule;

  return $export;
}
