<div class="media-holder">
  <div class="media">
    <div class="tweet-holder">
      <?php print $embed->html; ?>
    </div>
  </div>
  <?php if(isset($report_status['status'])) : ?>
    <span class="media-status">
      <?php print $report_status['status']; ?>
    </span>
  <?php endif; ?>
</div> <!-- /media-holder -->