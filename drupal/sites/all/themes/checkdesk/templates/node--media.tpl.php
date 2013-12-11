<?php 
  // set embed media type class
  if(isset($node->embed->provider_name)) {
    $provider = strtolower($node->embed->provider_name);
    $provider_class_name = str_replace('.', '_', $provider) . '-wrapper';
  }
?>

<section id="node-<?php print $node->nid; ?>" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="report <?php if (isset($status_class)) { print $status_class; } ?>">   
    <section class="report-content">
      <div class="report-media">
        <div class="container <?php print $provider_class_name; ?>">
          <?php if(isset($field_link_lazy_load)) { print $field_link_lazy_load; } ?>
        </div>
      </div>
      <?php if (isset($content['body'])) : ?>
        <div class="description">
          <?php print render($content['body']); ?>
        </div>
      <?php endif; ?>
      <div class="report-attributes">
        <div class="added-by">
          <?php if (isset($user_avatar)) : ?>
              <?php print $user_avatar; ?>
          <?php endif; ?>
          <?php print $media_creation_info; ?>
        </div>
      </div>
    </section>


      <div id="report-actions">
        <?php print render($content['links']); ?>
      </div>

    <?php if (isset($media_activity_report_count)) : ?>
      <section id="report-activity-node-<?php print $node->nid; ?>" class="report-activity">
          <header<?php if ($status_class) print ' class="' . $status_class . '"'; ?>>
            <div class="report-activity-header" href="#">
              <h3 class="report-footnotes-count"><span><?php print $media_activity_report_count . '</span> ' . t('fact-checking footnotes'); ?></h3>
              <div class="report-status">
                <?php if ($status): ?>
                  <?php print $status; ?>
                <?php endif; ?>
              </div>
            </div>
          </header>
          <div class="activity-wrapper">
            <?php print $media_activity_report; ?>
            <?php print render($content['comments']); ?>
            <p class="activity-list-footer"><?php print $media_activity_footer; ?></p>
          </div>

      </section>
    <?php endif; ?>
  </article>

  <?php if (isset($modal_class_hack)): ?>
    <?php print $modal_class_hack; ?>
  <?php endif; ?>

</section>