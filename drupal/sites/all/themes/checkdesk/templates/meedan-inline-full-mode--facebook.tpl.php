<div class="inline-attachment <?php print $provider_class_name; ?>">
  <div class="inline-attachment-wrapper">
    <div class="inline-attachment-bar"><div class="indent"></div></div>
    <div class="media-holder media-inline-holder">
      <div class="media">
        <?php if(isset($embed->html)) : ?>
          <div class="inline-holder inline-facebook-holder facebook-holder">
            <?php print $embed->html; ?>
          </div>
        <?php elseif (isset($full_image)) : ?>
          <div class="img-holder">
            <?php print $full_image; ?>
          </div>
        <?php endif ;?>
      </div>
      <?php if(isset($report_status['status'])) : ?>
        <span class="inline-attachment-status media-status">
          <?php print $report_status['status']; ?>
        </span>
      <?php endif; ?>
    </div> <!-- /media-holder -->
  </div>
</div> <!-- /inline-attachment -->