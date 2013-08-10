<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>" <?php print $attributes; ?>>
  <h1><?php print check_plain($node->title); ?></h1>

  <article class="story">
    <div class="story-meta">
      <div class="story-at">
        <?php if (isset($user_avatar)) : ?>
          <?php print $user_avatar; ?>
        <?php endif; ?>
        <?php print $creation_info; ?>
        <!-- RESULT SHOULD BE LIKE: <img src="#"/> <span class="">username</span> <span class="timestamp">Friday Jul 12, 2013 at 7:07</span> -->
      </div>

      <?php if (isset($story_commentcount)) { ?>
        <div class="story-comment-count">
          <a href="<?php print url('node/' . $node->nid, array('fragment' => 'story-comments-' . $node->nid)); ?>">
            <?php print render($story_commentcount); ?>
          </a>
        </div>
      <?php } ?>
    </div>

    <?php if(isset($content['field_lead_image'])) { ?>
      <figure class="story-featured-image">
        <?php print render(field_view_field('node', $node, 'field_lead_image', 'featured_image')); ?>
      </figure>
    <?php } ?>

    <div class="story-description">
      <?php print render($content['body']); ?>
    </div>

    <div class="story-participants">
      <?php print t('12 Participants'); ?>
      <div class="participant-avatar"><img alt="" src="http://placehold.it/24x24/0eafff/ffffff.png" /></div>
      <div class="participant-avatar"><img alt="" src="http://placehold.it/24x24/0eafff/ffffff.png" /></div>
      <div class="participant-avatar"><img alt="" src="http://placehold.it/24x24/0eafff/ffffff.png" /></div>
      <div class="participant-avatar"><img alt="" src="http://placehold.it/24x24/0eafff/ffffff.png" /></div>
      <div class="participant-avatar"><img alt="" src="http://placehold.it/24x24/0eafff/ffffff.png" /></div>
      <div class="participant-avatar"><img alt="" src="http://placehold.it/24x24/0eafff/ffffff.png" /></div>
      <div class="participant-avatar"><img alt="" src="http://placehold.it/24x24/0eafff/ffffff.png" /></div>
      <div class="participant-avatar"><img alt="" src="http://placehold.it/24x24/0eafff/ffffff.png" /></div>
    </div>

    <div class="story-reports">
      <?php print t('Reviewing'); ?>
      <div class="report-icon"><img alt="" src="http://placehold.it/24x24/0dafff/ffffff.png" /></div>
      <div class="report-icon"><img alt="" src="http://placehold.it/24x24/0dafff/ffffff.png" /></div>
      <div class="report-icon"><img alt="" src="http://placehold.it/24x24/0dafff/ffffff.png" /></div>
    </div>

    <div class="story-slogan">
      View our fact-checking progress on <a href="http://meedan.checkdesk.org">Checkdesk</a>.
    </div>

    <div class="story-status">
      <?php // print render($content['story_status']); ?>
    </div>

    <div class="story-drafts">
      <?php // print render($content['story_drafts']); ?>
    </div>

  </article>
</section>
