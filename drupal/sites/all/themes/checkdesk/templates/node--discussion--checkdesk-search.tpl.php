<div class="activity-item-content-wrapper item-content-wrapper">
  <span class="activity-item-content item-content">
      
    <div class="inline-attachment">
      <div class="inline-attachment-wrapper">
        <div class="inline-attachment-bar"><div class="indent"></div></div>
        <div class="media-holder media-inline-holder">
          <div class="media-content">
            <?php if(isset($inline_thumbnail)) : ?>
              <div class="media">
                <div class="inline-holder inline-img-thumb-holder">
                  <?php print $inline_thumbnail; ?>
                </div>
              </div>
            <?php endif; ?>
            <?php if ($status) : ?>
              <span class="story-published"><?php print t('Published '); ?></span>
            <?php else: ?>
               <span class="story-draft"><?php print t('Draft'); ?></span>
            <?php endif; ?>
            <span> <?php print t('liveblog'); ?></span>
            </span>
            <span class="title"><?php print l($node->title, 'node/' . $node->nid , array('html' => TRUE)); ?></span>
            <?php if(isset($node->name)) : ?><span class="author"><?php print $node->name; ?></span><?php endif; ?>
            <?php if (isset($content['field_tags'])) :?>
              <span class="story-tag"><?php print render($content['field_tags']); ?></span>
            <?php endif; ?>
            <span>
              <span class="ts"><?php print $media_creation_info; ?></span>
            </span>
          </div>
        </div> <!-- /media-holder -->
      </div>
    </div> <!-- /inline-attachment -->

  </span> <!-- /activity-item-content -->
</div> <!-- /activity-item-content-wrapper -->

<div class="item-nested-content-wrapper">
  <div class="activity-item-controls item-controls">
    <div class="meta">
      <?php print $content['story_updates_count']; ?>
      <?php print $content['story_collaborators_count']; ?>
    </div>
    <div class="actions" role="toolbar">
      <?php print render($content['links']); ?>
    </div>
  </div> <!-- /activity-item-controls -->
</div>

