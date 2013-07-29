<?php
  // dsm($content);
  // dsm($node);
?>

<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <h1><?php print check_plain($node->title); ?></h1>

  <article class="story">
    <div class="story-meta">
      <div class="story-at">
        <?php if (isset($user_avatar)) : ?>
          <?php print $user_avatar; ?>
        <?php endif; ?>
        <?php print $creation_info; ?>
      </div>
      <?php if (isset($story_commentcount)) { ?>
        <div class="story-commentcount">
          <a href="<?php print url('node/' . $node->nid, array('fragment' => 'story-comments-' . $node->nid)); ?>">
            <?php print render($story_commentcount); ?>
          </a>
        </div>
      <?php } ?>
    </div>


    <?php // print render($content['story_status']); ?>
    <?php // print render($content['story_drafts']); ?>
    <?php // print render($content['story_blogger']); ?>

    <?php if(isset($content['field_lead_image'])) { ?>
      <figure>
        <?php print render(field_view_field('node', $node, 'field_lead_image', 'featured_image')); ?>
      </figure>
    <?php } ?>

    <div class="story-body">
      <?php print render($content['body']); ?>
    </div>

    <div class="participants">
      <?php print t('12 Participants'); ?>
      <div class="participant-avatar"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="participant-avatar"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="participant-avatar"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="participant-avatar"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="participant-avatar"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="participant-avatar"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="participant-avatar"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="participant-avatar"><img src="http://example.com/stub.png" width="24" height="24"></div>
    </div>

    <div class="reports">
      <?php print t('Reviewing'); ?>
      <div class="report-icon"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="report-icon"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="report-icon"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="report-icon"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="report-icon"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="report-icon"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="report-icon"><img src="http://example.com/stub.png" width="24" height="24"></div>
      <div class="report-icon"><img src="http://example.com/stub.png" width="24" height="24"></div>
    </div>

  </article>
</section>
