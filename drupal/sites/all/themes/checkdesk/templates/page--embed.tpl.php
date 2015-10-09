<div class="cd-embed">
  <?php print render($page['content']); ?>
  <?php if ($factcheck_cta): ?>
		<div class="cd-embed-footer">
			<?php print render($cd_embed_footer); ?>
			<a class="checkdesk" href="http://checkdesk.org" target="_blank"><span><?php print t('Powered by Checkdesk'); ?></span></a>
		</div>
	 <?php endif; ?>
</div>
