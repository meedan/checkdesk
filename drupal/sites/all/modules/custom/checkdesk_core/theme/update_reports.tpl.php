<div class="checkdesk-update-reports-wrapper">
  <div class="update-reports-authors">
    <?php print $reports_author; ?>
  </div>

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