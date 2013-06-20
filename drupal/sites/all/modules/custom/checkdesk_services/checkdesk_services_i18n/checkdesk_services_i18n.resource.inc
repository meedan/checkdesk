<?php

/**
 * Deferred implementation of hook_services_resources().
 */
function _checkdesk_services_i18n_services_resources() {
  return array(

    'i18n' => array(
      'operations' => array(

        'index' => array(
          'file' => array('type' => 'inc', 'module' => 'checkdesk_services_i18n', 'name' => 'checkdesk_services_i18n.resource'),
          'callback' => '_checkdesk_services_i18n_translation_index',
          'args' => array(
            array(
              'name' => 'textgroup',
              'optional' => FALSE,
              'type' => 'string',
              'description' => 'The textgroup to fetch translations for.',
              'default value' => NULL,
              'source' => array('param' => 'textgroup'),
            ),
            array(
              'name' => 'lang',
              'optional' => TRUE,
              'type' => 'string',
              'description' => 'The language to fetch translations for.',
              'source' => array('param' => 'lang'),
            ),
            array(
              'name' => 'angular',
              'optional' => TRUE,
              'type' => 'int',
              'description' => 'When set to \'1\' angular compatible formatting will be used. The \'lang\' parameter must be supplied in this case.',
              'source' => array('param' => 'angular'),
              'default value' => FALSE,
            ),
          ),
          'access arguments' => array('access content'),
        ),
        'create' => array(
          'file' => array('type' => 'inc', 'module' => 'checkdesk_services_i18n', 'name' => 'checkdesk_services_i18n.resource'),
          'callback' => '_checkdesk_services_i18n_translation_create',
          'args' => array(
            array(
              'name' => 'translation',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'The data used to create a translation.',
              'type' => 'array',
            ),
          ),
          'access arguments' => array('translate interface'),
        ),
        'update' => array(
          'file' => array('type' => 'inc', 'module' => 'checkdesk_services_i18n', 'name' => 'checkdesk_services_i18n.resource'),
          'callback' => '_checkdesk_services_i18n_translation_update',
          'args' => array(
            array(
              'name' => 'lid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => 'The ID of a translation.',
            ),
            array(
              'name' => 'translation',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'The translation data to update.',
              'type' => 'array',
            ),
          ),
          'access arguments' => array('translate interface'),
        ),
        'delete' => array(
          'file' => array('type' => 'inc', 'module' => 'checkdesk_services_i18n', 'name' => 'checkdesk_services_i18n.resource'),
          'callback' => '_checkdesk_services_i18n_translation_delete',
          'args' => array(
            array(
              'name' => 'lid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => 'The ID of a translation.',
            ),
          ),
          'access arguments' => array('translate interface'),
        ),
      ), // END 'operations'

    ),
  );
}

/**
 * Retrieves a list of translations for a translation textgroup.
 *
 * @return (array) $translations
 *  A list of translations.
 */
function _checkdesk_services_i18n_translation_index($textgroup, $language = NULL, $angular = FALSE) {
  _checkdesk_services_i18n_validate_textgroup($textgroup);

  if ($angular && !$language) {
    return services_error(t('When \'angular\' mode is enabled the \'lang\' parameter must be supplied.'), 406);
  }

  $conditions = array('s.textgroup' => $textgroup);
  if ($language) {
    $conditions['t.language'] = $language;
  }

  $select = _checkdesk_services_i18n_translation_query($conditions);
  $result = $select->execute();

  $translations = array();
  while ($translation = $result->fetchAssoc()) {
    if ($angular) {
      $translations[$translation['source']] = $translation['translation'];
    }
    else {
      $translations[$translation['language']][] = $translation;
    }
  }

  return $translations;
}

/**
 * Creates a new translation.
 *
 * The minimum data payload to create a translation is:
 *   array(
 *     'language'        => 'VALID_LANGCODE',
 *     'source'          => 'THE_SOURCE_IN_ENGLISH',
 *     'translation'     => 'THE_TRANSLATION',
 *     'textgroup'       => 'A_VALID_AND_ALLOWED_TEXTGROUP',
 *   )
 *
 * Complete example:
 *   array(
 *     'language'        => 'VALID_LANGCODE',
 *     'context'         => 'ADDITIONAL_CUSTOM_DATA',
 *     'source'          => 'THE_SOURCE_IN_ENGLISH',
 *     'translation'     => 'THE_TRANSLATION',
 *     'textgroup'       => 'A_VALID_AND_ALLOWED_TEXTGROUP',
 *     'location'        => 'LOCATION_CONTEXT_OF_TRANSLATION_EG_URL_OR_FILE',
 *     'plid'            => 'LID_OF_PLURAL_PARENT',
 *     'plural'          => 'PLURALIZATION_NUMBER',
 *   )
 *
 * @return (array) $translation
 *  The created translation object.
 */
function _checkdesk_services_i18n_translation_create($translation) {
  _checkdesk_services_i18n_validate_textgroup($translation['textgroup']);

  $report = array();
  $lids = array();

  // TODO: Should API connections be allowed to set all values on the translation like this?.
  $lid = _locale_import_one_string_db(
    $report,
    (string) $translation['language'],
    (string) $translation['context'],
    (string) $translation['source'],
    (string) $translation['translation'],
    (string) $translation['textgroup'],
    (string) $translation['location'],
    LOCALE_IMPORT_OVERWRITE,
    (int) $translation['plid'],
    (int) $translation['plural']
  );

  if ($lid) {
    $select = _checkdesk_services_i18n_translation_query(array('s.lid' => $lid));
    return $select->execute()->fetchAssoc();
  }

  return services_error(t('Failed to create/update translation.'), 500);
}

/**
 * Updates a translation.
 *
 * @return (array) $translation
 *  The updated translation object.
 */
function _checkdesk_services_i18n_translation_update($lid, $translation) {
  // Not strictly necessary but may be handy in the future
  $translation->lid = $lid;

  return _checkdesk_services_i18n_translation_create($translation);
}

/**
 * Deletes a translation.
 *
 * @return (array) $result
 *  Returns array(TRUE) when translation was deleted successfully.
 */
function _checkdesk_services_i18n_translation_delete($translation) {
  // TODO: Implement _checkdesk_services_i18n_translation_delete.
  return array(TRUE);
}

/**
 * Returns a query to fetch translations.
 */
function _checkdesk_services_i18n_translation_query($conditions) {
  $select = db_select('locales_source', 's');
  $select->fields('s', array('lid', 'source', 'textgroup'));
  $select->fields('t', array('language', 'translation', 'plid', 'plural'));
  $select->join('locales_target', 't', 's.lid = t.lid');

  foreach($conditions as $column => $value) {
    $select->condition($column, $value);
  }

  $select->orderBy('t.language');
  $select->orderBy('s.lid');

  return $select;
}

/**
 * Ensures that a textgroup is allowed.
 */
function _checkdesk_services_i18n_validate_textgroup($textgroup) {
  // TODO: Make checkdesk_services_i18n_textgroups admin configurable.
  if (!in_array($textgroup, variable_get('checkdesk_services_i18n_textgroups', array('ui')))) {
    return services_error(t("The textgroup @textgroup is not allowed.", array('@textgroup' => $textgroup)), 406);
  }
}
