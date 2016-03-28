<section id="node-<?php print $node->nid; ?>" class="default-view-node-<?php print $node->nid; ?> item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="source">
    <div class="item-wrapper">
      <section class="source-holder item-content-wrapper">

        <div><?php print render($content['field_username']); ?></div>
        <div><?php print render($content['field_source_url']); ?></div>
        <div><?php print render($content['field_source_status']); ?></div>

      </section>
      <?php if (isset($content['metadata_fields'])) : ?>
        <?php print $content['metadata_fields']; ?>
      <?php endif; ?>
      <?php print $source_activity; ?>
    </div>
  </article>

  <aside class="report-footer">
    <!-- tag list -->
    <?php if(isset($content['field_source_tags'])) : ?>
      <?php print render($content['field_source_tags']); ?>
    <?php endif ?>
  </aside>

</section>
