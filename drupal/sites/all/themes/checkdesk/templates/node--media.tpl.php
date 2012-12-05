<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php dsm($node); ?>
  <article class="report">
    <header>
      <h3>
        <?php print render($content['report_source']); ?>
      </h3>
      <?php print render($content['links']); ?>
    </header>



    <section class="report-content">
      <?php print render($content['meedan_sensitive_content']); ?>
      <div class="report-media">
        <div class="container">
          <?php print render($content['field_link']); ?>
        </div>
      </div>
      <p>
        <?php if (isset($user_avatar)) : ?>
            <?php print $user_avatar; ?>
        <?php endif; ?>
        <?php print $media_creation_info; ?>
      </p>
      <div class="description"><?php print render($content['body']); ?></div>
    </section>



  <?php if (isset($media_activity_report_count)) : ?>
    <section id="report-activity-node-<?php print $node->nid; ?>" class="report-activity">
        <header class="<?php print $status_class; ?>">
          <a class="report-activity-header" href="#">
            <h3><?php print $media_activity_report_count . ' ' . t('fact-checking footnotes'); ?></h3>
            <?php if ($status_icon): ?>
              <div class="report-status">
                  <?php print $status_icon; ?>
              </div>
            <?php endif; ?>
          </a>
        </header>
        <div class="activity-wrapper">
          <?php print $media_activity_report; ?>
          <?php print render($content['comments']); ?>
        </div>

    </section>
  <?php endif; ?>
<!--       <footer>
        Something in small 
      </footer> -->

  </article>

</section>
