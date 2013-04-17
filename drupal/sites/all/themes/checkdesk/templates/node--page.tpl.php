<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="static-page">
    <div class="static-page-body">
      <?php print render($content['body']); ?>
    </div>
  </article>
</section>
