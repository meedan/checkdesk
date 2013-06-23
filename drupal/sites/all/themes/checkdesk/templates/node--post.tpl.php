<?php
  // dsm($content);
  // dsm($node);
?>
<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <a name="update-<?php print $node->nid; ?>" class="scroll"></a>
  <article class="update">
    <div class="update-body">
      <?php print render($content['body']); ?>
    </div>
    <div class="update-footer">
      <ul class="update-meta">
        <li class="update-at">
          <span class="icon-time"></span> <?php print $created_at; ?>
        </li>
        <li class="update-by">
          <?php if (isset($user_avatar)) : ?>
            <?php print $user_avatar; ?>
          <?php endif; ?>
          <?php print $created_by; ?>
        </li>
        <!-- <li class="share">
          <a href="#"><span class="icon-share"></span> <?php print t('Share'); ?></a>
        </li> -->
      </ul>
    </div>
  </article>
</section>
