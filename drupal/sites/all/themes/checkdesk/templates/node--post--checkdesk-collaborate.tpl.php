
<section class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update <?php if (isset($title)) { print ' with-title'; } else { ' no-title'; }?>">
    <div class="update-body">
      <?php if (isset($title)) { ?>
        <h2 class="update-title"><?php print $title; ?></h2>
      <?php } ?>
      <?php print render($content['body']); ?>
    </div>
     <?php if (isset($update_reports)) { ?>
    <div class="checkdesk-update-reports">
     <?php print $update_reports; ?>
    </div>
    <div class="checkdesk-update-reports-count">
     <?php print $update_reports_count; ?>
    </div>
    <?php } ?>
  </article>
</section>
