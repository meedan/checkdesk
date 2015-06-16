<?php
// determine what kind of media it is
if (isset($fields['field_rating']->content)) {
  $status_class = str_replace(' ', '_', strtolower($fields['field_rating']->content));
}
// Use google getFavicon service http://getfavicon.appspot.com/
$favicon = NULL;
if (isset($fields['source_url'])) {
  $favicon_url = url('http://g.etfv.co/'. $fields['source_url']->raw, array('absolute' => TRUE));
  $favicon = theme('image', array('path' => $favicon_url));
}
?>
<div class="report-row-container<?php if (isset($media_type_class)) { print ' ' . $media_type_class; } ?>" id="report-<?php print $fields['nid']->raw; ?>">
	<?php if ($report_published) { ?>
		<div class="report-published" title="<?php print $report_published; ?>">
			<span><?php print $report_published; ?></span>
		</div>
	<?php } ?>
	<div class="report-content">
    <?php print $fields['field_link']->content; ?>
	</div>
	<a class="report-attributes<?php if (isset($status_class)) { print ' ' . $status_class; } ?>"  href="<?php print url('node/' . $fields['nid']->raw); ?>">
		<div class="report-meta">
			<?php if ($favicon) : ?>
		      <div class="favicon"><?php print $favicon; ?></div>
		    <?php endif ?>
			<div class="report-created-at">
				<?php print $fields['created']->content; ?>
			</div>
		</div>
		<?php if(isset($fields['field_rating']->content) && $fields['field_rating']->content != 'Not Applicable') { ?>
			<div class="report-status">
				<span><?php print $name_i18n; ?></span>
			</div>
		<?php } ?>
	</a>
</div> 
