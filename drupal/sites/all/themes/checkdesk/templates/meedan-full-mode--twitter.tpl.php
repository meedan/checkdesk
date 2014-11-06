<div class="media-holder">
  <div class="media">
    <div class="tweet-holder">
      <?php if (isset($embed->html)) : ?>
        <?php print $embed->html; ?>
      <?php else: ?>
        <?php print theme('image', array('path' => $embed->thumbnail_url)); ?>
      <?php endif; ?>
    </div>
  </div>
  <?php if(isset($media_description)) : ?>
    <div class="media-content">
      <span class="description expandable"><?php print $media_description; ?></span>
    </div>
  <?php endif; ?>
  <?php if(isset($report_status['status'])) : ?>
    <span class="media-status">
      <?php print $report_status['status']; ?>
    </span>
  <?php endif; ?>
</div> <!-- /media-holder -->
