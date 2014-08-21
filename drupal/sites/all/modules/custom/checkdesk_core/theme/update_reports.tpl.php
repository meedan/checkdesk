<div class="checkdesk-update-reports-wrapper">
  <div class="update-reports-authors">
    <?php print $reports_author; ?>
  </div>

  <div class="collaborate-update-reports">
    <?php foreach ($reports as $report): ?>
      <div class="checkdesk-collaborate-report">
        <?php if (!empty($report['favicon_link'])): ?>
          <div class="update-report collaborate-update-report-favicon"><?php print $report['favicon_link']; ?> </div>
        <?php endif; ?>

        <div class="update-report collaborate-update-report-title"><?php print $report['title']; ?> </div>

        <?php if (!empty($report['description'])): ?>
          <div class="update-report collaborate-update-report-favicon"><?php print $report['description']; ?> </div>
        <?php endif; ?>
      </div>
    <?php endforeach; ?>
  </div>
</div>