<div class="media-holder media-inline-holder">
  <?php if (isset($embed->html)) : ?>
    <div class="media">
      <div class="tweet-holder">
        <?php print $embed->html; ?>
      </div>  
    </div>
  <?php elseif($embed->type == 'photo') : ?>
    <div class="media">
      <div class="inline-holder inline-img-thumb-holder">
        <?php print $inline_thumbnail; ?>
      </div>
    </div>
  <?php endif; ?>
  <div class="media-content">
    <span class="title"><?php print l($node->title, 'node/' . $node->nid , array('html' => TRUE)); ?></span>
    <?php if(isset($media_description)) : ?><span class="description expandable"><?php print $media_description; ?></span><?php endif; ?>
    <?php if(isset($author_name)) : ?><span class="author"><?php print $author_name ?></span><?php endif; ?>
    <span>
      <?php if(isset($favicon_link)) : ?><span class="provider-icon"><?php print $favicon_link ?></span><?php endif; ?> <span class="ts"><?php print $media_creation_info; ?></span>
    </span>

    <?php if(isset($report_status['status'])) : ?>
      <div class="inline-attachment-status media-status">
        <?php print $report_status['status']; ?>
      </div>
    <?php endif; ?>
  </div>
  
</div> <!-- /media-holder -->