<div class="media-holder media-inline-holder<?php if (isset($media_type_class)) { print ' ' . $media_type_class; } ?>">
  <div class="media">
    <?php if(isset($embed->html)) : ?>
      <div class="inline-holder inline-imgur-holder imgur-holder">
        <?php print $embed->html; ?>
      </div>
    <?php elseif (isset($full_image)) : ?>
      <div class="img-holder">
        <?php print $full_image; ?>
      </div>
    <?php endif ;?>
  </div>
  <div class="media-content">
    <span class="title"><?php print l($node->title, 'node/' . $node->nid , array('html' => TRUE)); ?></span>
    <?php if(isset($media_description)) : ?><span class="description expandable"><?php print $media_description; ?></span><?php endif; ?>
    <?php if(isset($author_name)) : ?>
      <span class="author"><?php print $author_name ?></span>
    <?php elseif(isset($provider_name)) : ?>
      <span class="provider"><?php print $provider_name ?></span>
    <?php endif; ?>
    <span>
      <?php if(isset($favicon_link)) : ?><span class="provider-icon"><?php print $favicon_link ?></span><?php endif; ?> <span class="ts"><?php print $media_creation_info; ?></span>
    </span>
  </div>
  <?php if(isset($report_status['status'])) : ?>
    <span class="inline-attachment-status media-status">
      <?php print $report_status['status']; ?>
    </span>
  <?php endif; ?>
</div> <!-- /media-holder -->