<?php

/**
 * @file
 * Checkdesk duplicates reports template.
 *
 * Variables available:
 * - $reports: associative array with report nid and report data in format [User1 added this link to story X]
 * - $duplicate_report_nid: The report nid for the one exists in same story
 *
 */
?>

<div class="cd-duplicates-reports">
<?php foreach ($reports as $nid => $data) : ?>
  <!--
   Added  "report-existing" class if the report exists in same story
   @ark I think we should highlighted this one as user will not be allowed to add the current report
   based on requirement [If at least one duplicate report exists in same story: prevent submission by disabling submit button]
   -->
  <div class="duplicates-reports-row <?php print ($nid == $duplicate_report_nid) ? 'cd-report-existing' : '' ?>">
    <?php print $data; ?>
    <span class="cd-report-link ">
      <?php print l(t('View the link'), 'node/' . $nid, array('attributes' => array('target'=>'_blank'))); ?>
    </span>
  </div>
<?php endforeach;?>
</div>
