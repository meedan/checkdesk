<div class="item-content-wrapper item-type-update update-added <?php if (isset($title)) { print ' with-title'; } else { ' no-title'; }?>">
  <span class="item-content">
    <div class="media-holder media-inline-holder">
      <div class="media-content">
        
        <span class="media-label">
          <?php if ($status) : ?>
            <span class="published"><?php print t('Published '); ?></span>
          <?php else: ?>
             <span class="draft"><?php print t('Draft'); ?></span>
          <?php endif; ?>
          <span class="media-type"> <?php print t('Liveblog update'); ?></span>
        </span>
        
        <?php if (isset($title)) { ?>
          <span class="title">
            <a href="<?php print $update_link; ?>"><?php print $title; ?></a>
          </span>
        <?php } ?>

        <?php 
          $update_body_text = render($content['body']);
          if (drupal_strlen($update_body_text) > 260) {
            $update_body_text = text_summary($update_body_text, 1, 260) . '<p><a href="' . $update_link . '">[&hellip;]</a></p>';
          }
          // pattern to check for empty paragraphs
          $empty_paragraphs = '/<p[^>]*>[\s|&nbsp;]*<\/p>/';
        ?>

        <?php if($update_body_text): ?>
          <div class="item-body-text">
            <?php print preg_replace($empty_paragraphs, '', $update_body_text); ?>
          </div>
        <?php endif; ?>

        <?php if(!empty($content['update_reports'])): ?>
          <?php print render($content['update_reports']); ?>
        <?php endif; ?>

        <?php if(isset($node->name)) : ?>
          <span class="author"><?php print $node->name; ?></span>
        <?php endif; ?>

        <?php if (isset($content['body'])) : ?>
          <?php print render($content['body']); ?>
        <?php endif; ?>

        <span class="ts"><?php print $media_creation_info; ?></span>
      </div> <!-- /media-content -->  
    </div> <!-- /media-holder -->
  </span> <!-- /item-content -->
</div> <!-- /item-content-wrapper -->

<div class="item-nested-content-wrapper">
  <div class="item-controls">
    <div class="meta">
      <?php if(!empty($content['update_reports_count'])): ?>
        <a class="count count-reports" href="<?php print $update_link; ?>">
          <?php print render($content['update_reports_count']); ?>
        </a>
      <?php endif; ?>
    </div>
    <div class="actions" role="toolbar">
      <?php print render($content['links']); ?>
      <?php if (in_array('administrator', $user->roles) || in_array('journalist', $user->roles)) : ?>
        <div class="update-edit">
        <?php print l('<span class="icon-pencil-square-o"></span>', 'node/' . $node->nid . '/edit', array('query' => drupal_get_destination(), 'html'=>TRUE)); ?>
        </div>
      <?php endif; ?>
    </div>
  </div> <!-- /item-controls -->
</div>