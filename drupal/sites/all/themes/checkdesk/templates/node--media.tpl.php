<?php 
  // set embed media type class
  if(isset($node->embed->provider_name)) {
    $provider = strtolower($node->embed->provider_name);
    $provider_class_name = str_replace('.', '_', $provider) . '-wrapper';
  }
?>

<section id="node-<?php print $node->nid; ?>" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="report <?php if (isset($status_class)) { print $status_class; } ?>">   
    <section class="media-holder">
      <div class="media-content">
        <div class="media video video-16by9 <?php print $provider_class_name; ?>">
          <?php if(isset($field_link_lazy_load)) { print $field_link_lazy_load; } ?>
        </div>
      </div>
      <?php if (isset($content['body'])) : ?>
        <div class="media-description">
          <?php print render($content['body']); ?>
        </div>
      <?php endif; ?>
      
      <div class="media-details">
        <span class="title"><?php print l($title, 'node/' . $node->nid , array('html' => TRUE)); ?></span>
        <?php if(isset($author_name)) : ?><span class="author"><?php print $author_name ?></span><?php endif; ?>
        <span>
          <?php if(isset($favicon_link)) : ?><span class="provider-icon"><?php print $favicon_link ?></span><?php endif; ?> <span class="ts"><?php print $media_timestamp; ?></span>
        </span>
        <?php if (isset($media_creation_info)) : ?>
          <span class="added-by">
            <?php print $media_creation_info; ?>
          </span>
        <?php endif; ?>
      </div>
      <?php if ($status): ?>
        <span class="media-status"><?php print $status; ?></span>
      <?php endif; ?>

    </section>

    <?php if (isset($media_activity_report_count)) : ?>
      <section id="report-activity-node-<?php print $node->nid; ?>" class="report-activity open">
          <header<?php if (isset($status_class)) { print ' class="' . $status_class . '"'; } ?>>
            <div class="report-activity-header" href="#">
              <div class="report-footnotes-count">
                <h3><span><?php print $media_activity_report_count . '</span> ' . t('verification footnotes'); ?></h3>
              </div>
              <div class="report-actions" role="toolbar">
                <?php print render($content['links']); ?>
              </div>
            </div>
          </header>
          <div class="activity-wrapper">
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

      </section>
    <?php endif; ?>
  </article>

  <?php if (isset($modal_class_hack)): ?>
    <?php print $modal_class_hack; ?>
  <?php endif; ?>

</section>
