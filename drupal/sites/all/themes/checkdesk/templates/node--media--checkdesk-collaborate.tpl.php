<?php 
  // set embed media type class
  if(isset($node->embed->provider_name)) {
    $provider = strtolower($node->embed->provider_name);
    $provider_class_name = str_replace('.', '_', $provider) . '-wrapper';
  }
  $heartbeat_row = $node->heartbeat_row;
?>

<div class="activity-item-content-wrapper <?php if (isset($status_class)) { print $status_class; } ?>">
  <span class="activity-item-content">
    <div class="inline-attachment <?php print $provider_class_name; ?>">
      <div class="inline-attachment-wrapper">
        <div class="inline-attachment-bar"><div class="indent"></div></div>
        <div class="media-holder media-inline-holder">
          <?php if (isset($content['field_link'])) : ?>
            <!-- render as inline thumbnail -->
            <div class="media-content">
              <?php print render($content['field_link']); ?> 
            </div>
          <?php endif; ?>

          <div class="media-info">
            <span class="title"><?php print l($title, 'node/' . $node->nid , array('html' => TRUE)); ?></span>
            <?php if(isset($author_name)) : ?><span class="author"><?php print $author_name ?></span><?php endif; ?>
            <span>
              <?php if(isset($favicon_link)) : ?><span class="provider-icon"><?php print $favicon_link ?></span><?php endif; ?> <span class="ts"><?php print $media_creation_info; ?></span>
            </span>
          </div>
          <?php if ($heartbeat_row->heartbeat_activity_message_id == 'status_report') : ?>
            <span class="inline-attachment-status media-status">
              <?php print render($content['report_activity_status']); ?>
            </span>
          <?php endif; ?>
          <?php if ($heartbeat_row->heartbeat_activity_message_id == 'checkdesk_report_suggested_to_story') : ?>
            <!-- render as full view -->
            <div class="media-content">
              <div class="media video video-16by9 <?php print $provider_class_name; ?>">
                <?php print render(field_view_field('node', $node, 'field_link', array('type' => 'oembed_default'))); ?>
              </div>
            </div>
          <?php endif; ?>
          
        </div> <!-- /media-holder -->
      </div>
    </div> <!-- /inline-attachment -->

    <?php if ($heartbeat_row->heartbeat_activity_message_id == 'checkdesk_comment_on_report') : ?>
      <?php if (isset($content['report_verification_footnote'])) : ?>
        <div class="report-verification-footnote">
          <?php print render($content['report_verification_footnote']); ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>

  </span> <!-- /activity-item-content -->
</div> <!-- /activity-item-content-wrapper -->

<div class="activity-item-footer ">
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
</div> <!-- /activity-item-footer -->
