<?php
/**
 * @file
 * Checkdesk duplicates reports template.
 *
 * Variables available:
 * - $reports: associative array with report nid and report data as associative array (user and story)
 * - $duplicate_report_nid: The report nid for the one exists in same story
 * - $avatar: checkdesk avatar
 */
?>
<div class="activity cd-duplicates-reports">
<?php foreach ($reports as $nid => $data) : ?>
  <div class="activity-item item duplicates-reports-row <?php print ($nid == $duplicate_report_nid) ? 'cd-report-existing' : '' ?>">
    <?php print $avatar; ?>
    <div class="activity-item-wrapper item-wrapper">
      <div class="activity-item-message item-message">
        <time class="timestamp"><?php print $data['created_at']; ?></time>
        <?php if (!empty($data['story'])) : ?>
          <?php print t('!user has already added this link to !story', array('!user' => $data['author'], '!story' => $data['story'])); ?>
        <?php else: ?>
          <?php print t('!user has already added this link', array('!user' => $data['author'])); ?>
        <?php endif; ?>
    </div>
      <div class="activity-item-content-wrapper item-content-wrapper">
        <span class="activity-item-content item-content">
          <div class="item-content-actions form-actions">
            <?php print l(t('View the link'), 'node/' . $nid, array('attributes' => array('target'=>'_blank', 'class' => array('btn', 'btn-default')))); ?>
          </div>
        </span>
      </div>
    </div>
  </div>
<?php endforeach;?>
</div>
