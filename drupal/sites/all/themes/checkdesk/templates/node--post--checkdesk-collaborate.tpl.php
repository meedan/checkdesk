
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
    <div class="collaborate-update-footer">
        <ul class="collaborate-update">
           <li class="update-reports-count"><?php print $update_reports_count; ?></li>
           <li class="update-share"><?php print render($content['links']); ?></li>
           <?php if (in_array('administrator', $user->roles) || in_array('journalist', $user->roles)) { ?>
           <li class="update-edit">
            <?php print l('<span class="icon-pencil-square"></span>'. t('Edit'), 'node/' . $node->nid . '/edit', array('query' => drupal_get_destination(), 'html'=>TRUE)); ?>
           </li>
           <?php } ?>
        </ul>
    </div>
    <?php } ?>
  </article>
</section>
