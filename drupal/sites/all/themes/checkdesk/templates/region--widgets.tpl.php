<header id="partner-header">
	<div id="partner-header-inner">
	  <?php if ($frontpage_logo): ?>
	    <?php print $frontpage_logo; ?>
	  <?php endif; ?>
	  <?php if ($header_slogan): ?>
	    <div id="partner-header-slogan">
	      <?php print $header_slogan; ?>
	    </div>
	  <?php endif; ?>
	</div>
</header>
<div class="widgets-wrapper">
	<?php print $content; ?>
</div>