<div class="inline-attachment">
  <div class="inline-attachment-wrapper">
    <div class="update-reports-authors">
      <?php print $reports_author; ?>
    </div>
    <div class="inline-attachment-bar"><div class="indent"></div></div>
    <div class="media-holder media-inline-holder">
      <div class="media-content">
          <div class="collaborate-update-reports">
            <?php foreach ($reports as $report): ?>
              <div class="checkdesk-collaborate-report">
                <?php if (!empty($report['favicon_link'])): ?>
                  <?php print $report['favicon_link']; ?>
                <?php endif; ?>
               <?php print $report['title']; ?>
              </div>
            <?php endforeach; ?>
          </div>
        </div>
    </div>
  </div>
</div> <!-- /inline-attachment -->