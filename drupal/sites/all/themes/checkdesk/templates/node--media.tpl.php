<section id="node-<?php print $node->nid; ?>" class="item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="report item <?php if (isset($status_class)) { print $status_class; } ?>">   
    <div class="item-wrapper">
      <section class="media-holder item-content-wrapper">
        <div class="media">
          <?php if(isset($field_link_lazy_load)) { print $field_link_lazy_load; } ?>
        </div>
      </section>

      <?php if (isset($media_activity_report_count)) : ?>
        <div id="report-activity-node-<?php print $node->nid; ?>" class="item-nested-content-wrapper open">
          <div class="activity-item-controls item-controls">
            <div class="meta">
              <?php if (isset($media_activity_report_count)) : ?>
                <?php print $media_activity_report_count . ' ' . t('verification footnotes'); ?>
              <?php endif; ?>
            </div>
            <div class="actions" role="toolbar">
              <?php print render($content['links']); ?>
            </div>
          </div> <!-- /activity-item-controls -->
          <?php if(isset($media_activity_report)) : ?>
            <div class="activity nested item-nested-content">
              <?php print $media_activity_report; ?>
              <?php print render($content['comments']); ?>
              <?php if ($media_activity_footer) : ?>
                <div class="item-nested-footer">
                  <?php print $media_activity_footer; ?>
                </div>
              <?php endif; ?>
            </div>
          <?php endif; ?>
        </div>
      <?php endif; ?>

      <?php if (isset($content['field_stories'])) : ?>
      <section class="report-detail">
        <?php if(isset($content['field_stories'])): ?>
          <div class="checkdesk-story-wrapper">
            Published in <?php print render($content['field_stories']); ?>
          </div>
        <?php endif ?>
      </section>
      <?php endif; ?>
    </div>
  </article>

  <?php if (isset($modal_class_hack)): ?>
    <?php print $modal_class_hack; ?>
  <?php endif; ?>

</section>
