<?php // dsm($content); ?>
<?php // dsm($node); ?>

<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update">
    <p class="update-by"><?php print $update_creation_info; ?></p>
    <div class="update-body">
      <?php print render($content['body']); ?>
    </div>

  </article>
</section>