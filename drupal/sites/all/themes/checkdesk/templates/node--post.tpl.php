<?php
  // dsm($content);
  // dsm($node);
?>
<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update">
    <div class="update-body">
      <?php print render($content['body']); ?>
    </div>
    <div class="update-footer">
      <ul class="update-meta">
        <li class="update-at">
          <a name="update-<?php print $node->nid; ?>"><span class="icon-time"></span> <?php print $created_at; ?></a>
        </li>
        <li class="update-by">
          <?php if (isset($user_avatar)) { ?>
            <?php print $user_avatar; ?>
          <?php } ?>
          <?php print $created_by; ?>
        </li>
        <!-- <li class="share">
          <a href="#"><span class="icon-share"></span> <?php print t('Share'); ?></a>
        </li> -->
        <?php if (user_access('administer nodes')) { ?>
          <li class="update-edit">
            <?php print l('<span class="icon-edit-sign"></span>'. t('Edit'), 'node/' . $node->nid . '/edit', array('html'=>TRUE)); ?>
          </li>
        <?php } ?>
      </ul>
    </div>
  </article>
</section>
