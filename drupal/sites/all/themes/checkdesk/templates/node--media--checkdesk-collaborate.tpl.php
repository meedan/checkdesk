<?php 
  $heartbeat_row = $node->heartbeat_row;
?>
<section id="node-<?php print $node->nid; ?>" class="item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
<div class="activity-item-content-wrapper item-content-wrapper <?php if (isset($status_class)) { print $status_class; } ?>">
  <span class="activity-item-content item-content">
      
    <?php print render($content['field_link']); ?>

    <?php if ($heartbeat_row->heartbeat_activity_message_id == 'checkdesk_comment_on_report') : ?>
      <?php if (isset($content['report_verification_footnote'])) : ?>
        <div class="report-verification-footnote activity-item-content-text item-content-text">
          <?php print render($content['report_verification_footnote']); ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>

  </span> <!-- /activity-item-content -->
</div> <!-- /activity-item-content-wrapper -->

<div id="report-activity-node-<?php print $node->nid; ?>" class="item-nested-content-wrapper">
  <div class="activity-item-controls item-controls">
    <div class="meta">
      <?php if (isset($media_activity_report_count)) : ?>
        <?php print $media_activity_report_count . ' ' . t('verification footnotes'); ?>
      <?php endif; ?>
    </div>
    <div class="actions" role="toolbar">
      <?php print render($content['links']); ?>
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
</section>