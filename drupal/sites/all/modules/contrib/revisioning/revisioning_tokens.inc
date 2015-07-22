<?php

/**
 * @file
 * Add tokens pertaining to the Revisioning module.
 *
 * @ingroup token
 */

/**
 * Implements hook_token_info().
 */
function revisioning_token_info() {
  $info = array();
  // First specify token type(s).
  $info['types']['revision'] = array(
    'name' => t("Revisions"),
    'description' => t('Tokens related to revisions of individual content items, or "node revisions".'),
    'needs-data' => 'node',
  );
  // Then specify the tokens.
  $info['tokens']['revision']['revision-author'] = array(
    'name' => t("Revision author"),
    'description' => t("The author (or editor) of the revision"),
    'type' => 'user',
  );
  $info['tokens']['revision']['revision-body'] = array(
    'name' => t("Revision body"),
    'description' => t("The main body text of the revision"),
  );
  $info['tokens']['revision']['revision-created'] = array(
    'name' => t("Revision timestamp"),
    'description' => t("The date and time the revision was created."),
    'type' => 'date',
  );
  $info['tokens']['revision']['revision-title'] = array(
    'name' => t("Revision title"),
    'description' => t("The title of the revision"),
  );
  $info['tokens']['revision']['revision-vid'] = array(
    'name' => t("Revision ID"),
    'description' => t("The unique ID of the revision"),
  );
  return $info;
}

/**
 * Implements hook_tokens().
 */
function revisioning_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if (!empty($data['revision'])) {
    $revision = $data['revision'];
  }
  elseif (!empty($data['entity']) && $data['entity_type'] == 'node') {
    // When Token module is enabled.
    $revision = $data['entity'];
  }
  elseif (!empty($data['node'])) {
    $revision = $data['node'];
  }
  else {
    return $replacements;
  }

  $sanitize = !empty($options['sanitize']);

  foreach ($tokens as $name => $original) {
    switch ($name) {

      case 'revision-title':
        $title = $revision->title;
        $replacements[$original] = $sanitize ? check_plain($title) : $title;
        break;

      case 'revision-body':
        $text = reset($revision->body);
        $text = $text[0]['value'];
        $replacements[$original] = $sanitize ? check_plain($text) : $text;
        break;

      case 'revision-vid':
        $replacements[$original] = $revision->vid;
        break;

      // Default values for the chained tokens handled below.
      case 'revision-author':
        $author = user_load($revision->revision_uid);
        $name = format_username($author);
        $replacements[$original] = $sanitize ? check_plain($name) : $name;
        break;

      case 'revision-created':
        $langcode = empty($options['language']->language) ? LANGUAGE_NONE : $options['language']->language;
        $replacements[$original] = format_date($revision->revision_timestamp, 'medium', '', NULL, $langcode);
        break;
    }
  }
  // Chained tokens for revision author and revision timestamp.
  // These fan out into sub-token fields, e.g revision-author:mail etc.
  if ($author_tokens = token_find_with_prefix($tokens, 'revision-author')) {
    $author = user_load($revision->revision_uid);
    $replacements += token_generate('user', $author_tokens, array('user' => $author), $options);
  }
  if ($created_tokens = token_find_with_prefix($tokens, 'revision-created')) {
    $replacements += token_generate('date', $created_tokens, array('date' => $revision->revision_timestamp), $options);
  }
  return $replacements;
}
