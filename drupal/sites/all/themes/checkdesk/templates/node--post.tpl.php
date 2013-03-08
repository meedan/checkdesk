<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update">
    <p class="update-by">
    	<?php if (isset($user_avatar)) : ?>
            <?php print $user_avatar; ?>
        <?php endif; ?>
    	<?php print $update_creation_info; ?>
    </p>
    <div class="update-body">
      <?php print render($content['body']); ?>
    </div>
    <p><?php print render($content['field_desk']); ?></p>
    <div class="update-comments">
     <?php print render($content['custom_comments']); ?>
    </div>
  </article>
</section>
