<?php

/**
 * @file
 * Checkdesk duplicates reports template.
 *
 * Variables available:
 * - $reports: associative array with report nid and report data as associative array (user and story)
 * - $duplicate_report_nid: The report nid for the one exists in same story
 *
 */
?>

<div class="activity cd-duplicates-reports">
<?php foreach ($reports as $nid => $data) : ?>
  <div class="activity-item item duplicates-reports-row <?php print ($nid == $duplicate_report_nid) ? 'cd-report-existing' : '' ?>">
    <?php print $data['avatar']; ?>
    <div class="activity-item-wrapper item-wrapper">
      <div class="activity-item-message item-message">
        <time class="timestamp"><?php print $data['created_at']; ?></time>
        <?php print $data['author']; ?>
        <?php if (!empty($data['story'])) : ?>
          <?php print t('added this link to'); ?>
          <?php print $data['story']; ?>
        <?php endif; ?>
      </div>
      <div class="activity-item-content-wrapper item-content-wrapper">
        <span class="activity-item-content item-content">
          <div class="item-content-actions form-actions">
            <?php print l(t('View the link'), 'node/' . $nid, array('attributes' => array('target'=>'_blank', 'class' => array('btn', 'btn-primary')))); ?>
            <?php print l(t('Cancel'), '#', array('attributes' => array('class' => array('btn', 'btn-default')))); ?>
          </div>
        </span>
      </div>
    </div>
  </div>
<?php endforeach;?>
</div>
