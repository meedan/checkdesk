<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
	if(isset($latest_story->file_managed_field_data_field_lead_image_uri)) {
		$lead_image_path = image_style_url('item_image_large', $latest_story->file_managed_field_data_field_lead_image_uri);
	}
    $term = taxonomy_term_load($fields['tid']->raw);
    $i18n_term = i18n_taxonomy_term_name($term);
?>

<div class="cd-item cd-item-section tone-section-item">
    <div class="cd-item-container cd-item-background-image-container" <?php if(isset($lead_image_path)) : ?>style="background-image: url('<?php print $lead_image_path ?>')" <?php endif; ?>>
        <div class="cd-item-content">
            <div class="cd-item-header">
                <h2 class="cd-item-title cd-item-section-title">
                    <?php print $i18n_term; ?>
                </h2>
            </div>
        </div>
        <?php print l($i18n_term, 'taxonomy/term/' . $fields['tid']->raw, array('attributes' => array('class' => array('u-faux-block-link-overlay')))); ?>
    </div>
</div>