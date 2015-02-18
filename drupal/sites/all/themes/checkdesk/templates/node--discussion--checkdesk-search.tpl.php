<section id="node-<?php print $node->nid; ?>" class="node-<?php print $node->nid; ?> <?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="story">

    <h1 class="title">
      <?php print l(render($node->title), 'node/'. $node->nid); ?>
    </h1>

    <?php //print submitted; ?>
      <?php if (isset($content['field_tags'])) : ?>
          <?php print render($content['field_tags']); ?>
      <?php endif; ?>

      <div class="story-meta">
          <div class="story-attributes">
              <?php print $media_creation_info; ?>
              <?php if (isset($story_commentcount)) : ?>
                  <div class="story-commentcount">
                      <span class="icon-comment-o"><?php print render($story_commentcount); ?></span>
                  </div>
              <?php endif; ?>
          </div>
      </div>

    <?php if(isset($content['field_lead_image'])) { ?>
      <figure>
        <?php print render($content['field_lead_image']); ?>
      </figure>
    <?php } ?>


  </article>
</section>
