<ul id="footer-menu">
	<?php if ($partner_name): ?>
	<li>
		<a class="partner-logo" href="<?php print $partner_url; ?>" target="_blank">
			<span><?php print t('Blogged by '); ?></span><?php print $partner_name; ?>
		</a>
	</li>
	<?php endif; ?>
	<li><a class="checkdesk" href="http://checkdesk.org" target="_blank"><span><?php print t('Powered by Checkdesk'); ?></span></a></li>
</ul>