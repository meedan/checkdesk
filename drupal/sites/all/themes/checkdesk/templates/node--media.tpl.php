<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($content['meedan_sensitive_content']); ?>  
  <article class="report">
    <header>
      <h3>
        <?php print render($content['report_source']); ?>
      </h3>
      <?php print render($content['links']); ?>
    </header>


    <section class="report-content">
      <div class="report-media">
        <div class="container">
          <?php print render($content['field_link']); ?>
        </div>
      </div>
      <p>
     <?php if ($user_avatar) : ?>
        <a class="gravatar" href="<?php print url('<front>') . 'user/' . $node->uid ?>">
          <?php print $user_avatar; ?>
        </a> 
     <?php endif; ?>
        <a href="<?php print url('<front>') . 'user/' . $node->uid ?>"><?php print $node->name; ?></a> added this <time class="time-ago" pubdate datetime="<?php print format_date($created, 'custom', 'Y-m-d\TH:i:sP'); ?>"><?php print format_interval(time()-$created); ?> ago</time>
      </p>
      <div class="description"><?php print render($content['body']); ?></div>
    </section>



  <?php if ($media_activity_report_count) : ?>
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
