<div class="activity-item-content-wrapper item-content-wrapper update-added <?php if (isset($title)) { print ' with-title'; } else { ' no-title'; }?>">
  <span class="activity-item-content item-content">
    <div class="media-holder media-inline-holder">
      <div class="media-content">
      
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
        
      </div> <!-- /media-content -->  
    </div> <!-- /media-holder -->

  </span> <!-- /activity-item-content -->
</div> <!-- /activity-item-content-wrapper -->

<div class="item-nested-content-wrapper">
  <div class="activity-item-controls item-controls">
    <div class="meta">
      <?php if(!empty($content['update_reports_count'])): ?>
        <?php print render($content['update_reports_count']); ?>
      <?php endif; ?>
    </div>
    <div class="actions" role="toolbar">
      <?php print render($content['links']); ?>
      <?php if (node_access('update', $node, $user)) : ?>
        <div class="update-edit">
        <?php print l('<span class="icon-pencil-square-o"></span>', 'node/' . $node->nid . '/edit', array('query' => drupal_get_destination(), 'html'=>TRUE)); ?>
        </div>
      <?php endif; ?>
    </div>
  </div> <!-- /activity-item-controls -->
  <div class="item-nested-content">
    <!-- add report verification log -->
  </div>
</div>