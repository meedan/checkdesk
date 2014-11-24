<div id="report-activity-node-<?php print $node->nid; ?>" class="item-nested-content-wrapper <?php print $collapsed ?>">
  <div class="activity-item-controls item-controls">
    <?php print $media_activity_report_count; ?>
    <div class="actions" role="toolbar">
       <div class="media-links-node-<?php print $node->nid;?>">
        <?php print render($content['links']); ?>
       </div>
    </div>
  </div> <!-- /activity-item-controls -->
  <?php if(isset($media_activity_report)) : ?>
    <div class="activity nested item-nested-content">
      <?php print $media_activity_report; ?>
      <?php print render($content['comments']); ?>
      <?php if ($media_activity_footer) : ?>
        <div class="item-nested-footer">
          <?php print $media_activity_footer; ?>
        </div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>