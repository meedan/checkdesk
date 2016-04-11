<section id="node-<?php print $node->nid; ?>" class="default-view-node-<?php print $node->nid; ?> item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="source">
    <div class="item-wrapper">
      <section class="source-holder item-content-wrapper">

        <div><?php print render($content['field_username']); ?></div>
        <div><?php print render($content['field_image']); ?></div>
        <div><?php print render($content['body']); ?></div>
        <div><?php print render($content['field_source_url']); ?></div>
        <div><?php print render($content['field_source_status']); ?></div>
        <?php if (count($source_metadata)) : ?>
          <?php foreach($source_metadata as $k => $metadata) : ?>
            <div> <?php print render($content[$metadata]); ?> </div>
          <?php endforeach; ?>
        <?php endif; ?>
      </section>

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
