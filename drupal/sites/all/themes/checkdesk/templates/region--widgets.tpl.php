<header id="partner-header">
	<div id="partner-header-inner">
	  <?php if ($header_image): ?>
	    <?php print $header_image; ?>
	  <?php endif; ?>
	  <?php if ($header_slogan): ?>
	    <div id="partner-header-slogan">
	      <?php print $header_slogan; ?>
	    </div>
	  <?php endif; ?>
	</div>
</header>
<?php print $content; ?>