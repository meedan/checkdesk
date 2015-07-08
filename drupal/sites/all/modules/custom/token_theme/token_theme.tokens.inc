<?php

/**
 * Implementation of hook_token_info().
 */
function token_theme_token_info() {
	$theme = variable_get('theme_default');
	theme_get_setting('default_logo', $theme);
	$theme_settings = &drupal_static('theme_get_setting', array());
	$type = array(
		'name' => t('Theme'),
		'description' => t('Tokens related to current theme.'),
	);
	$tokens = array();
	foreach ($theme_settings[$theme] as $key => $value) {
		$tokens[$key] = array(
			'name' => $key,
			'description' => t('The value of theme setting !setting.', array('!setting' => $key)),
		);
	}
	return array(
		'types' => array('theme' => $type),
		'tokens' => array('theme' => $tokens),
	);
}

/**
 * Implementation of hook_tokens().
 */
function token_theme_tokens($type, $tokens, array $data = array(), array $options = array()) {
	if ($type !== 'theme') return array();
	$theme = variable_get('theme_default');
	theme_get_setting('default_logo', $theme);
	$theme_settings = &drupal_static('theme_get_setting', array());
	$replacements = array();
	foreach ($tokens as $name => $original) {
		if (array_key_exists($name, $theme_settings[$theme])) {
			$value = $theme_settings[$theme][$name];
			// Logos etc. have a scheme://target path and need to be converted to URLs.
			$url = file_create_url($value);
			$replacements[$original] = $url ? $url : $value;
		}
	}
	return $replacements;
}
