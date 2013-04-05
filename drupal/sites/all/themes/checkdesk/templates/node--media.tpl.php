<?php 
  // set embed media type class
  if(isset($node->embed->provider_url)) {
    $url = $node->embed->provider_url;
    $url = parse_url($url);
    $media_type = $url['host'];
    $media_type_class = str_replace('.', '_', $media_type);
  }
?>

<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="report">   
    <section class="report-content">
      <div class="report-media">
        <div class="container <?php print $media_type_class; ?>">
          <?php if(isset($content['meedan_sensitive_content'])) { print render($content['meedan_sensitive_content']); }  ?>
          <?php if(isset($content['field_link'])) { print render($content['field_link']); } ?>
        </div>
      </div>
      <p>
        <?php if (isset($user_avatar)) : ?>
            <?php print $user_avatar; ?>
        <?php endif; ?>
        <?php print $media_creation_info; ?>
      </p>
      <?php if (isset($content['body'])) : ?>
        <div class="description">
          <?php print render($content['body']); ?>
        </div>
      <?php endif; ?>
    </section>

    <footer>
      <h3>
        <span class="icon-flag"></span>
      </h3>
      <div id="report-actions">
        <?php print render($content['links']); ?>
      </div>
    </footer>

    <?php if (isset($media_activity_report_count)) : ?>
      <section id="report-activity-node-<?php print $node->nid; ?>" class="report-activity">
          <header<?php if ($status_class) print ' class="' . $status_class . '"'; ?>>
            <h3><?php print $media_activity_report_count . ' ' . t('fact-checking footnotes'); ?></h3>
            <div class="report-status">
              <a class="report-activity-header" href="#">
                <?php if ($status): ?>
                  <?php print $status; ?>
                <?php endif; ?>
              </a>
            </div>
          </header>
          <div class="activity-wrapper">
            <?php print $media_activity_report; ?>
            <?php print render($content['comments']); ?>
          </div>

      </section>
    <?php endif; ?>
  </article>

</section>
