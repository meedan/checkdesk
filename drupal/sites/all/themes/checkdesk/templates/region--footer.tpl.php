<ul id="footer-menu">
	<?php if ($footer_image): ?>
	<li>
		<a class="partner-logo" href="<?php print $partner_url; ?>" target="_blank">
			<?php print t('Blogged by '); ?><span><?php print $footer_image; ?></span>
		</a>
	</li>
	<?php endif; ?>
	<li><a class="checkdesk" href="http://checkdesk.org" target="_blank"><?php print t('Powered by '); ?></a></li>
</ul>