<div class="report-row-container<?php if (isset($media_type_class)) { print ' ' . $media_type_class; } ?>" id="report-<?php print $fields['nid']->raw; ?>">
	<div class="report-content">
		<?php print $fields['field_link']->content; ?>
	</div>
	<?php if(isset($fields['field_rating']) && $fields['field_rating']->content != 'Not Applicable') { ?>
		<?php
			$status_class = str_replace(' ', '_', strtolower($fields['field_rating']->content));
		?>
		<div class="report-status <?php print $status_class; ?>">
			<span><?php print $name_i18n; ?></span>
		</div>
	<?php } ?>
	<div class="report-detail-link">
		<?php
    print l(t('Details'), 'node/'. $fields['nid']->raw);
    ?>
	</div>
</div> 
