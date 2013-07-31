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
<div class="widgets-wrapper">
	<?php
	  // get featured stories
	  $block = block_load('views', 'featured_stories-block');
	  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
	  if(isset($render_array['views_featured_stories-block'])) {
	    $featured_stories = render($render_array);  
	  }
	?>
	<?php if(isset($featured_stories)) : ?>
		<div id="featured-stories">
			<?php print $featured_stories; ?>
		</div>
	<?php endif; ?>
	<?php print $content; ?>
</div>