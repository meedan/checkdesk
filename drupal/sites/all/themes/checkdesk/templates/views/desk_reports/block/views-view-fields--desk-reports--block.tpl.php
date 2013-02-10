<?php
	// determine what kind of media it is
	$url = $fields['source_url']->raw;
	$url = parse_url($url);
	$media_type = $url['host'];
	$media_type_class = str_replace('.', '_', $media_type);
?>
<div class="report-row-container <?php print $media_type_class; ?>">
	<div class="report-content">
		<?php if($media_type != 'twitter.com') { ?>
			<!-- display thumbnail -->
			<div class="report-type-thumbnail">
				<div class="report-thumbnail">
					<?php print $fields['field_link']->content; ?>
				</div>
				<div class="report-title">
					<?php print $fields['title']->content; ?>
				</div>
			</div>
		<?php } else { ?>
			<!-- display full oembed object -->
			<div class="report-type-tweet">
				<?php print $fields['field_link_1']->content; ?>
			</div>
		<?php } ?>
	</div>
	<?php if($fields['field_rating']->content != 'Not Applicable') { ?>
		<div class="report-status">
			<?php print $fields['field_rating']->content; ?>
		</div>
	<?php } ?>
	<div class="report-detail-link">
		<?php 
			$link['attributes']['class'] = array('ctools-use-modal', 'ctools-modal-modal-popup-report');
	    	$link['attributes']['data-toggle'] = 'dropdown';
	    	$link['href'] = 'report-view-modal/nojs/' . $fields['nid']->raw;
	        print l(t('Details'), $link['href'], $link);
		?>
	</div>
</div> 