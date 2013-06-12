<?php
  // dsm($content);
  // dsm($node);
?>

<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update">
    <div class="update-footer">
      <div class="update-info">
        Update <b>#1</b>
      </div>
      <ul class="update-meta">
        <li class="update-at">
          <span class="icon-time"></span> <?php print $update_created_at; ?>
        </li>
        <li class="update-by">
          <?php if (isset($user_avatar)) : ?>
            <?php print $user_avatar; ?>
          <?php endif; ?>
          <?php print $update_created_by; ?>
        </li>
        <!-- <li class="update-actions"> -->
          <?php // print render($content['links']); ?>
        <!-- </li> -->
        <!-- <li class="update-comments"> -->
          <?php // print render($content['custom_comments']); ?>
        <!-- </li> -->
      </ul>
    </div>
    <div class="update-body">
      <?php print render($content['body']); ?>
    </div>
  </article>
</section>
