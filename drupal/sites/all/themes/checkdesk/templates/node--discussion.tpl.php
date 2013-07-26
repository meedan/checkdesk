<?php
  // dsm($content);
  // dsm($node);
?>

<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="story">
    <div class="story-meta">
      <div class="story-attributes">
        <?php if (isset($user_avatar)) : ?>
          <?php print $user_avatar; ?>
        <?php endif; ?>
        <?php print $creation_info; ?>
        <?php if (isset($story_commentcount)) { ?>
        <div class="story-commentcount">
          <a href="<?php print url('node/' . $node->nid, array('fragment' => 'story-comments-' . $node->nid)); ?>">
            <span class="icon-comment"><?php print render($story_commentcount); ?></span>
          </a>
        </div>
      <?php } ?> 
      </div>
       
      <?php if(isset($content['links']['checkdesk']['#links'])) { ?>
        <?php print render($content['links']); ?>
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

    <?php
      // get compose update form
      $block = block_load('checkdesk_core', 'post');
      $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
      if(isset($render_array['checkdesk_core_post'])) {
        $compose_update_form = render($render_array);  
      }
    ?>
    
    <?php if(isset($compose_update_form)) { ?>
      <div class="compose-update-form">
        <div class="compose-update-header"><a href="#"><?php print t('Compose Update'); ?></a></div>
        <?php print $compose_update_form; ?>
      </div>
    <?php } ?>

    <div class="story-updates-wrapper">
      <?php print $updates; ?>
    </div>

    <div class="story-footer">
      <div class="story-updated-at">
        <?php print t('Updated at ') . $updated_at; ?>
      </div>
    </div>

    <!-- story comments -->
    <div class="story-comments" id="story-comments-<?php print $node->nid; ?>">
      <?php if (isset($content['custom_comments'])) print render($content['custom_comments']); ?>
    </div>

  </article>
</section>
