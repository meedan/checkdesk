<section id="node-<?php print $node->nid; ?>" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="story">

    <h1 class="title">
      <?php print render($node->title); ?>
    </h1>


    <div class="story-meta">
      <div class="story-attributes">
        <?php if (isset($user_avatar)) : ?>
          <?php print $user_avatar; ?>
        <?php endif; ?>
        <?php print $creation_info_short; ?>
        <?php if (isset($story_commentcount)) { ?>
        <div class="story-commentcount">
          <a href="<?php print url('node/' . $node->nid, array('fragment' => 'story-comments-' . $node->nid)); ?>">
            <span class="icon-comment-o"><?php print render($story_commentcount); ?></span>
          </a>
        </div>
      <?php } ?>
      </div>
    </div>

  	<div class="story-body">
      <?php print render($content['body']); ?>
    </div>

    <?php if (isset($follow_story)) : ?>
      <div class="story-follow">
        <?php print $follow_story; ?>
      </div>
    <?php endif; ?>

    <?php if(isset($content['field_lead_image'])) { ?>
      <figure>
        <?php print render($content['field_lead_image']); ?>
      </figure>
    <?php } ?>

    <div class="story-tabs-wrapper">
      <?php print $story_tabs; ?>
    </div>

    <?php if (isset($updates)) { ?>
      <div class="story-updates-wrapper">
        <?php print $updates; ?>
      </div>
    <?php } ?>

    <aside class="story-footer">
      <section class="cd-container cd-container--first">
        <div clas="cd-container__inner">
          <div class="story-updated-at pull-<?php print $layout['alpha']; ?>">
            <span class="icon-clock-o"></span><span class="story-updated-at-text"><?php print t('Updated at ') . $updated_at; ?></span>
          </div>
          <?php if(isset($content['links']['checkdesk']['#links'])) { ?>
            <div class="story-links pull-<?php print $layout['omega']; ?>">
              <?php print render($content['links']); ?>
            </div>
          <?php } ?>
        </div>
      </section>

      <?php if(isset($content['field_tags'])) { ?>
        <!-- tag list -->
        <section id="media-tags" class="cd-container">
          <div class="cd-container__inner">
            <div class="submeta">
              <h2 class="submeta__header"><?php print t('Published in'); ?></h2>
              <?php print render($content['field_tags']); ?>
            </div>
          </div>
        </section>
      <?php } ?>

    </aside>

    <!-- story comments -->
    <div class="story-comments" id="story-comments-<?php print $node->nid; ?>">
      <?php if (isset($content['custom_comments'])) print render($content['custom_comments']); ?>
    </div>

  </article>
</section>
