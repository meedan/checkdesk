
<section id="node-<?php print $node->nid; ?>" class="item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
<div class="activity-item-content-wrapper item-content-wrapper<?php if (isset($status_class)) { print ' ' . $status_class; } ?>">
  <span class="activity-item-content item-content">
      
    <?php print render($content['field_link']); ?>


  </span> <!-- /activity-item-content -->
</div> <!-- /activity-item-content-wrapper -->

<?php print $report_activity; ?>

</section>