<?php

/**
 * Implementation of hook_token_info().
 */
function checkdesk_oembed_token_info() {
	$node['checkdesk-image'] = array(
		'name' => t('Checkdesk image'),
		'description' => t('An image that is representative of the content, suitable for embedding.'),
	);

	return array(
		'tokens' => array('node' => $node),
	);
}

/**
 * Implementation of hook_tokens().
 */
function checkdesk_oembed_tokens($type, $tokens, array $data = array(), array $options = array()) {
	if ($type !== 'node' || empty($data['node'])) return array();

	$replacements = array();
	$node = $data ['node'];
	foreach ($tokens as $name => $original) {
		switch ($name) {
			case 'checkdesk-image':
				$replacements[$original] = checkdesk_oembed__token_image($node);
				break;
		}
	}
	return $replacements;
}

function checkdesk_oembed__token_image($node) {
	$image = token_replace('[theme:frontpage_logo_path]', array());
	switch ($node->type) {
		case 'discussion': // story
			if (!empty($node->field_lead_image[LANGUAGE_NONE][0]['uri'])) {
				$image = token_replace('[node:field_lead_image]', array('node' => $node));
			}
			break;
		case 'media': // report
			if (!empty($node->embed->thumbnail_url)) {
				$image = $node->embed->thumbnail_url;
			}
			break;
		case 'post': // update
			// TODO
			break;
	}
	return $image;
}
