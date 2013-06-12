<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update">
    <div class="update-footer">
      <div class="update-by">
        <?php if (isset($user_avatar)) : ?>
              <?php print $user_avatar; ?>
          <?php endif; ?>
        <?php print $update_creation_info; ?>
      </div>
      <div class="update-actions">
        <?php print render($content['links']); ?>
      </div>
      <div class="update-comments">
        <?php print render($content['custom_comments']); ?>
      </div>
    </div>
    
    <div class="update-body">
      <?php print render($content['body']); ?>
    </div>
    
  </article>
</section>
