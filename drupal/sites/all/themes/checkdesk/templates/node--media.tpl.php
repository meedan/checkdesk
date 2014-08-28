<section id="node-<?php print $node->nid; ?>" class="item node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="report item <?php if (isset($status_class)) { print $status_class; } ?>">   
    <div class="item-wrapper">
      <section class="media-holder item-content-wrapper">
        <div class="media">
          <?php if(isset($field_link_lazy_load)) { print $field_link_lazy_load; } ?>
        </div>
      </section> 
      <section id="report-activity-node-<?php print $node->nid; ?>" class="report-activity item-nested-content-wrapper open">
          <header<?php if (isset($status_class)) { print ' class="' . $status_class . '"'; } ?>>
            <div class="report-activity-header item-controls" href="#">
              <div class="meta">
                <?php if(isset($media_activity_report_count)) : ?>
                  <?php print $media_activity_report_count . t(' verification footnotes'); ?>
                <?php endif; ?>
              </div>
              <div class="actions" role="toolbar">
                <?php print render($content['links']); ?>
              </div>
            </div>
          </header>
          <?php if(isset($media_activity_report)) : ?>
            <div class="activity nested item-nested-content">
              <?php print $media_activity_report; ?>
              <?php print render($content['comments']); ?>
              <?php if ($media_activity_footer) : ?>
                <div class="activity-list-footer-wrapper">
                  <div class="activity-list-footer">
                    <?php print $media_activity_footer; ?>
                  </div>
                </div>
              <?php endif; ?>
            </div>
          <?php endif; ?>
      </section>
    </div>
  </article>

  <?php if (isset($modal_class_hack)): ?>
    <?php print $modal_class_hack; ?>
  <?php endif; ?>

</section>