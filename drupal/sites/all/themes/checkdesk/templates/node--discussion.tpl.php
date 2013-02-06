<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="story">
    <?php if($content['links']['checkdesk']['#links']) { ?>
      <div id="story-actions">
        <?php print render($content['links']); ?>
      </div>
    <?php } ?>

  	<?php print render($content['story_status']); ?>
  	<?php print render($content['story_drafts']); ?>
  	<?php print render($content['story_blogger']); ?>

  	<div class="story-body">
  		<?php print render($content['body']); ?>
  	</div>

  </article>
</section>
