<section id="node-<?php print $node->nid; ?>" class="source-row-container node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
    <div class="item-content-wrapper<?php if (isset($status_class)) { print ' ' . $status_class; } ?>">
      <span class="item-content">
          <div class="media">
            <div class="inline-holder inline-img-thumb-holder">
              <?php print render($content['field_image']); ?>
            </div>
          </div>
          <div class="source-content">
            <span class="title"><?php print l($pender->data->title, 'node/' . $node->nid , array('html' => TRUE)); ?></span>
            <span class="username"><?php print $username_link; ?></span>
            <span class="description expandable"><?php print render($content['body']); ?></span>
          </div>
      </span> <!-- /item-content -->
    </div> <!-- /content-wrapper -->
  <?php print $source_activity; ?>
</section>
