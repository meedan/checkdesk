<div id="source-activity-node-<?php print $node->nid; ?>" class="source-activity-node-<?php print $node->nid; ?> item-nested-content-wrapper <?php print $collapsed ?>">
  <div class="activity-item-controls item-controls">
    <div class="meta source-activity-count-node-<?php print $node->nid;?> populated">
      <span><?php print $source_activity_count; ?></span>
    </div>
    <div class="actions" role="toolbar">
       <div class="media-links-node-<?php print $node->nid;?>">
        <?php print render($content['links']); ?>
       </div>
    </div>
  </div> <!-- /activity-item-controls -->

  <?php if($show_activity && isset($source_activity)) : ?>
    <div class="activity nested item-nested-content">
      <div class="media-activity-node-<?php print $nid; ?>">
        <?php print $source_activity; ?>
      </div>
      <?php print render($content['comments']); ?>
    </div>
  <?php endif; ?>

</div>
