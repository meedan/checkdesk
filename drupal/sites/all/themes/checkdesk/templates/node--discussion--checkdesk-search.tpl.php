<div class="item-content-wrapper item-type-story">
  <span class="item-content">
      <div class="media-holder media-inline-holder">

          <?php if(isset($inline_thumbnail) && !empty($inline_thumbnail)) : ?>
            <div class="media">
              <div class="inline-holder inline-img-thumb-holder">
                <?php print $inline_thumbnail; ?>
              </div>
            </div>
          <?php endif; ?>

          <div class="media-content">            
            <span class="media-label">
              <?php if ($status) : ?>
                <span class="published"><?php print t('Published '); ?></span>
              <?php else: ?>
                 <span class="draft"><?php print t('Draft'); ?></span>
              <?php endif; ?>
              <span class="media-type"> <?php print t('Liveblog'); ?></span>
            </span>

            <span class="title"><?php print l($node->title, 'node/' . $node->nid , array('html' => TRUE)); ?></span>
            <?php if(isset($node->name)) : ?>
              <span class="author"><?php print $node->name; ?></span>
            <?php endif; ?>

            <?php if (isset($content['field_tags'])) :?>
              <span class="story-tag"><?php print render($content['field_tags']); ?></span>
            <?php endif; ?>
            <span class="ts"><?php print $media_creation_info; ?></span>

          </div> <!-- /media-content -->
        </div> <!-- /media-holder -->

  </span> <!-- /item-content -->
</div> <!-- /item-content-wrapper -->

<div class="item-nested-content-wrapper">
  <div class="item-controls">
    <div class="meta">
      <?php if(!empty($content['story_updates_count'])): ?>
        <a class="count count-updates" href="<?php print url('node/'. $node->nid); ?>">
          <span><?php print $content['story_updates_count']; ?></span>
        </a>
      <?php endif; ?>
      <?php if(!empty($content['story_collaborators_count'])): ?>
        <a class="count count-collaborators" href="<?php print url('node/'. $node->nid . '/collaboration'); ?>">
          <?php print $content['story_collaborators_count']; ?>
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