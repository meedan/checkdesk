<?php 
  $heartbeat_row = $node->heartbeat_row;
?>
<section id="node-<?php print $node->nid; ?>" class="item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="activity-item-content-wrapper item-content-wrapper<?php if (isset($status_class)) { print ' ' . $status_class; } ?>">
    <span class="activity-item-content item-content">
      <div class="inline-attachment <?php print $provider_class_name; ?>">
        <div class="inline-attachment-wrapper">
          <div class="inline-attachment-bar"><div class="indent"></div></div>
          <?php print render($content['field_link']); ?>
        </div>
      </div> <!-- /inline-attachment -->
      <?php if ($heartbeat_row->heartbeat_activity_message_id == 'checkdesk_comment_on_report') : ?>
        <?php if (isset($content['report_verification_footnote'])) : ?>
          <div class="report-verification-footnote activity-item-content-text item-content-text">
            <?php print render($content['report_verification_footnote']); ?>
          </div>
        <?php endif; ?>
      <?php endif; ?>
    </span> <!-- /activity-item-content -->
  </div> <!-- /activity-item-content-wrapper -->

  <?php print $report_activity; ?>
  
</section>