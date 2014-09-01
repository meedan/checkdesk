<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
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

      <?php if(isset($content['links']['checkdesk']['#links'])) { ?>
        <?php print render($content['links']); ?>
      <?php } ?>
    </div>


    <div class="story-body">
      <?php print render($content['body']); ?>
    </div>
    <!-- ARK use this to render with specific image style -->
    <?php print render(field_view_field('node', $node, 'field_lead_image', array(
      'type' => 'image',
      'settings' => array('image_style' => 'report_thumbnail'),
    ))); ?>
    <!-- ARK use this to render default image display -->
    <!--
    <?php if(isset($content['field_lead_image'])) { ?>
      <figure>
        <?php print render($content['field_lead_image']); ?>
      </figure>
    <?php } ?>
   -->
  </article>
</section>
