<?php // dsm($content); ?>
<?php // dsm($node); ?>

<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="post">
    <p class="post-by"><?php print $post_creation_info; ?></p>
    <div class="post-body">
      <?php print render($content['body']); ?>
    </div>

  </article>
</section>