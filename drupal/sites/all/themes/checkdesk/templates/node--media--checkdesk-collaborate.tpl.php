<?php 
  
  // dsm($node);

  // set embed media type class
  if(isset($node->embed->provider_name)) {
    $provider = strtolower($node->embed->provider_name);
    $provider_class_name = str_replace('.', '_', $provider) . '-wrapper';
  }
?>

<div class="activity-item-content-wrapper <?php if (isset($status_class)) { print $status_class; } ?>">
  <span class="activity-item-content">
    <div class="inline-attachment <?php print $provider_class_name; ?>">
      <div class="inline-attachment-wrapper">
        <div class="inline-attachment-bar"><div class="indent"></div></div>
        <div class="content">
          <?php if (isset($node->uaid)) : ?>
            <?php print render(field_view_field('node', $node, 'field_link', array('type' => 'meedan_oembed_thumbnail'))); ?>
          <?php endif; ?>
          
          <div class="content-details">
            <?php if (isset($node->uaid)) : ?><span class="title"><?php print $title; ?></span><?php endif; ?>
            <?php if(isset($author_name)) : ?><span class="author"><?php print $author_name ?></span><?php endif; ?>
            <span>
              <?php if(isset($favicon_link)) : ?><span class="provider-icon"><?php print $favicon_link ?></span><?php endif; ?> <span class="ts"><?php print $media_creation_info; ?></span>
            </span>
          </div>
          <?php if (isset($node->uaid)) : ?>
            <span class="inline-attachment-status report-status">
              <?php print render($content['report_activity_status']); ?>
            </span>
          <?php endif; ?>
        </div>
      </div>
    </div> <!-- /inline-attachment -->

    <?php if (isset($node->uaid)) : ?>
      <?php if (isset($content['report_verification_footnote'])) : ?>
        <div class="report-verification-footnote">
          <?php print render($content['report_verification_footnote']); ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>

  </span> <!-- /activity-item-content -->
</div> <!-- /activity-item-content-wrapper -->

<div class="activity-item-footer">
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
