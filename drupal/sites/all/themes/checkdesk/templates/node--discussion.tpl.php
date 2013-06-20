<?php
  // dsm($content);
  // dsm($node);
?>

<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="story">


    <div class="story-meta">
      <div class="story-at">
        <?php if (isset($user_avatar)) : ?>
          <?php print $user_avatar; ?>
        <?php endif; ?>
        <?php print $creation_info; ?>
      </div>
    </div>

    <?php if(isset($content['links']['checkdesk']['#links'])) { ?>
      <div id="story-actions">
        <?php print render($content['links']); ?>
      </div>
    <?php } ?>

  	<?php // print render($content['story_status']); ?>
  	<?php // print render($content['story_drafts']); ?>
  	<?php // print render($content['story_blogger']); ?>

  	<div class="story-body">
  		<?php print render($content['body']); ?>
  	</div>

    <div class="story-footer">
      <?php print t('Updated at ') . $updated_at; ?>
    </div>

  </article>
</section>
