<div class="meta media-activity-count-node-<?php print $nid; ?><?php if ($count) : ?> populated<?php endif;?>">
  <?php if ($count) : ?>
    <?php if ($link_count): ?>
    	<?php $count = '<span>' . $count . '</span>'; ?>
      <?php print l($count . ' ' . t('comments'), 'node/'. $nid, array('html' => TRUE, 'attributes' => array('class' => array('count', 'count-footnotes')))); ?>
    <?php else: ?>
      <?php print '<span>' . $count . ' ' . t('comments') . '</span>'; ?>
    <?php endif; ?>
  <?php endif; ?>
</div>