<div class="inline-attachment <?php print $provider_class_name; ?>">
  <div class="inline-attachment-wrapper">
    <div class="inline-attachment-bar"><div class="indent"></div></div>
    <div class="media-holder media-inline-holder">
      <div class="media">
        <div class="inline-holder inline-tweet-holder tweet-holder">
          <?php if (isset($embed->html)) : ?>
            <?php print $embed->html; ?>
          <?php else: ?>
            <?php print theme('image', array('path' => $embed->thumbnail_url)); ?>
          <?php endif; ?>
        </div>
        <?php if(isset($media_description)) : ?>
          <div class="media-content">
            <span class="description expandable"><?php print $media_description; ?></span>
          </div>
        <?php endif; ?>
      </div>
      <?php if(isset($report_status['status'])) : ?>
        <span class="inline-attachment-status media-status">
          <?php print $report_status['status']; ?>
        </span>
      <?php endif; ?>
    </div> <!-- /media-holder -->
  </div>
</div> <!-- /inline-attachment -->
