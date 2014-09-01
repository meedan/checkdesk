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
        <?php if (isset($follow_story)) : ?>
          <?php print $follow_story; ?>
        <?php endif; ?>
    </div>

    <?php if(isset($content['field_lead_image'])) { ?>
      <figure>
        <?php print render($content['field_lead_image']); ?>
      </figure>
    <?php } ?>
        
    <div class="story-tabs-wrapper">
        <?php print $story_tabs; ?>
    </div>

    
    <!-- collaboration -->
    <div class="story-collaboration-header-wrapper">
      <?php print $story_links; ?>
      <?php if(isset($story_collaborators)) { ?>    
         <?php print $story_collaborators; ?>
      <?php  } ?>
    </div>

    <div class="story-collaboration-activity-wrapper">
      <?php if(isset($story_collaboration)) { ?>    
        <?php print $story_collaboration; ?>
      <?php  } ?>
    </div>

    <!-- story comments -->
    <div class="story-comments" id="story-comments-<?php print $node->nid; ?>">
      <?php if (isset($content['custom_comments'])) print render($content['custom_comments']); ?>
    </div>

  </article>
</section>
