<div class="meta media-activity-count-node-<?php print $nid; ?><?php if ($count) : ?> populated<?php endif;?>">
  <?php if ($count) : ?>
    <span class="count">
      <?php if ($link_count): ?>
        <?php print l($count . ' ' . t('verification footnotes'), 'node/'. $nid); ?>
      <?php else: ?>
        <?php print $count . ' ' . t('verification footnotes'); ?>
      <?php endif; ?>
    </span>
  <?php endif; ?>
</div>