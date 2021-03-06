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
            <?php if ($is_current && $status) : ?>
              <span class="media-label published"><?php print t('Published '); ?>
            <?php else: ?>
              <span class="media-label draft"><?php print t('Draft'); ?>
            <?php endif; ?>
            <span class="media-type"> <?php print t('Story'); ?></span></span>

            <div class="title">
              <?php if(isset($content['field_section'])) : ?>
                <span class="content-labels section-label"><?php print render($content['field_section']); ?></span>
              <?php endif; ?>
              <span class="title-text"><?php print $story_link; ?></span>
            </div>

            <?php if(isset($node->name)) : ?>
              <span class="author"><?php print $story_authors; ?></span>
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
      <?php if (node_access('update', $node, $user)) : ?>
        <div class="update-edit">
          <?php print l('<span class="icon-pencil-square-o"></span>', 'node/' . $node->nid . '/edit', array('query' => drupal_get_destination(), 'html'=>TRUE)); ?>
        </div>
      <?php endif; ?>
    </div>
  </div> <!-- /item-controls -->
</div>