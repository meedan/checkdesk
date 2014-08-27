<?php 
  $heartbeat_row = $node->heartbeat_row;
?>

<div class="activity-item-content-wrapper item-content-wrapper <?php if (isset($status_class)) { print $status_class; } ?>">
  <span class="activity-item-content item-content">
      
    <?php print render($content['field_link']); ?>

    <?php if ($heartbeat_row->heartbeat_activity_message_id == 'checkdesk_comment_on_report') : ?>
      <?php if (isset($content['report_verification_footnote'])) : ?>
        <div class="report-verification-footnote">
          <?php print render($content['report_verification_footnote']); ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>

  </span> <!-- /activity-item-content -->
</div> <!-- /activity-item-content-wrapper -->

<div class="item-nested-content-wrapper">
  <div class="activity-item-controls item-controls">
    <div class="meta">
      <?php if (isset($media_activity_report_count)) : ?>
        <?php print $media_activity_report_count . ' ' . t('verification footnotes'); ?>
      <?php endif; ?>
    </div>
    <div class="actions" role="toolbar">
      <span class="icon-share"></span>
      <span class="icon-flag-o"></span>
      <span class="icon-plus-square-o"></span>
    </div>
  </div> <!-- /activity-item-controls -->
  <div class="item-nested-content">
    <!-- add report verification log -->
  </div>
</div>
