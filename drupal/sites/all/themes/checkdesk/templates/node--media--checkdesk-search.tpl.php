<section id="node-<?php print $node->nid; ?>" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
	<div class="item-content-wrapper<?php if (isset($status_class)) { print ' ' . $status_class; } ?>">
	  <span class="item-content">
	    <?php print render($content['field_link']); ?>
	  </span> <!-- /item-content -->
	</div> <!-- /content-wrapper -->

    <?php if (isset($content['body'])) : ?>
      <?php print render($content['body']); ?>
    <?php endif; ?>
  
   <?php print $report_activity; ?>
</section>