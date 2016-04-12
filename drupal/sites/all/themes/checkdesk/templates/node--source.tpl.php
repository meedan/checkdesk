<section id="node-<?php print $node->nid; ?>" class="default-view-node-<?php print $node->nid; ?> item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="source">
    <div class="item-wrapper">
      <section class="source-holder item-content-wrapper">

        <div class="source-avatar"><?php print render($content['field_image']); ?></div>
        <div class="source-content">
          <span class="title"><?php print l($pender->data->title, 'node/' . $node->nid , array('html' => TRUE)); ?></span>
          <span class="username"><?php print $username_link; ?></span>
          <span class="description expandable"><?php print render($content['body']); ?></span>
        </div>
        <div class="source-metadata">
          <?php if (count($source_metadata)) : ?>
            <?php foreach($source_metadata as $k => $metadata) : ?>
              <div class="source-metadata-item"><?php print render($content[$metadata]); ?></div>
            <?php endforeach; ?>
          <?php endif; ?>
        </div>
        
        <?php if(isset($references)) : ?>
          <?php print $references; ?>
        <?php endif ?>

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
