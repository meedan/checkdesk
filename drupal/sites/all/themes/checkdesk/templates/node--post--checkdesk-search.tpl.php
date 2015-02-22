<?php
  global $language;
  $parent_story_id = $node->field_desk[LANGUAGE_NONE][0]['target_id'];
  $update_anchor = 'update-' . $node->nid;
  $update_link = url('node/'.$parent_story_id, array('fragment' => $update_anchor, 'language' => $language));
?>

<div class="activity-item-content-wrapper item-content-wrapper update-added <?php if (isset($title)) { print ' with-title'; } else { ' no-title'; }?>">
  <span class="activity-item-content item-content">
    <?php if ($status) : ?>
      <span class="story-published"><?php print t('Published '); ?></span>
    <?php else: ?>
      <span class="story-draft"><?php print t('Draft'); ?></span>
    <?php endif; ?>
    <span> <?php print t('liveblog update'); ?></span>
    <?php if (isset($title)) { ?>
      <h3 class="update-title">
        <a href="<?php print $update_link; ?>"><?php print $title; ?></a>
      </h3>
    <?php } ?>
    <?php if(!empty($content['body'])): ?>
      <div class="item-body-text">
        <?php 
          $update_body_text = render($content['body']);
          if (drupal_strlen($update_body_text) > 260) {
            print text_summary($update_body_text, 1, 260);
            print '<p>[&hellip;]</p>';
          } else {
            print $update_body_text;
          } 
        ?>
      </div>
    <?php endif; ?>
    <?php if(!empty($content['update_reports'])): ?>
      <?php print render($content['update_reports']); ?>
    <?php endif; ?>

    <?php if(isset($node->name)) : ?>
      <span class="author"><?php print $node->name; ?></span>
    <?php endif; ?>

    <span>
      <span class="ts"><?php print $media_creation_info; ?></span>
     </span>
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
      <?php if (in_array('administrator', $user->roles) || in_array('journalist', $user->roles)) : ?>
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