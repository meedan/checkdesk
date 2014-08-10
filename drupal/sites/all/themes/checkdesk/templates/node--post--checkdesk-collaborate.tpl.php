
<section class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update <?php if (isset($title)) { print ' with-title'; } else { ' no-title'; }?>">

    <div class="update-body">
      <?php if (isset($title)) { ?>
        <h2 class="update-title"><?php print $title; ?></h2>
      <?php } ?>
      <?php print render($content['body']); ?>
      <?php print render($content['update_reports']); ?>
    </div>

    <div class="collaborate-update-footer">
        <ul class="collaborate-update">
           <?php if(!empty($content['update_reports_count'])): ?>
              <li class="update-reports-count"><?php print render($content['update_reports_count']); ?></li>
           <?php endif ?>
           <li class="update-share"><?php print render($content['links']); ?></li>
           <?php if (in_array('administrator', $user->roles) || in_array('journalist', $user->roles)) : ?>
           <li class="update-edit">
            <?php print l('<span class="icon-pencil-square"></span>'. t('Edit'), 'node/' . $node->nid . '/edit', array('query' => drupal_get_destination(), 'html'=>TRUE)); ?>
           </li>
           <?php endif; ?>
        </ul>
    </div>

  </article>
</section>
