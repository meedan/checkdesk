<section id="node-<?php print $node->nid; ?>" class="default-view-node-<?php print $node->nid; ?> item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="report item<?php if (isset($status_class)) { print ' ' . $status_class; } ?>">
    <div class="item-wrapper">
      <section class="media-holder item-content-wrapper<?php if (isset($media_type_class)) { print ' ' . $media_type_class; } ?>">
        <?php if(isset($field_link_lazy_load)) { print $field_link_lazy_load; } ?>
      </section>
      <?php print $report_activity; ?>
      <?php if (!empty($published_stories)) : ?>
        <section class="report-detail">
          <div class="checkdesk-story-wrapper">
            <?php print t('Posted to !published', array('!published' => $published_stories)); ?>
          </div>
        </section>
      <?php endif; ?>
    </div>
  </article>

  <aside class="report-footer">
    <!-- tag list -->
    <?php if(isset($content['field_tags'])) : ?>
      <?php print render($content['field_tags']); ?>
    <?php endif ?>
  </aside>

  <?php if (isset($modal_class_hack)): ?>
    <?php print $modal_class_hack; ?>
  <?php endif; ?>

</section>
