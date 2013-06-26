<?php
  // dsm($content);
  // dsm($node);
  // $parent_story_id = $node->field_desk[LANGUAGE_NONE][0]['target_id'];
  // $parent_story_link = url('node/'.$parent_story_id);
  // $update_anchor = 'update-' . $node->nid;
  // $update_link = url($parent_story_link, array('fragment' => $update_anchor));
?>
<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update">
    <div class="update-body">
      <?php if (isset($title)) { ?>
        <h2 class="update-title"><?php print $title; ?></h2>
      <?php } ?>
      <?php print render($content['body']); ?>
    </div>
    <div class="update-footer">
      <ul class="update-meta">
        <li class="update-at">
          <span class="icon-time"></span> <?php print $created_at; ?>
        </li>
        <li class="update-by">
          <?php if (isset($user_avatar)) { ?>
            <?php print $user_avatar; ?>
          <?php } ?>
          <?php print $created_by; ?>
        </li>
        <!-- <li class="share">
          <a href="#"><span class="icon-share"></span> <?php print t('Share'); ?></a>
        </li> -->
        <?php if (user_access('administer nodes')) { ?>
          <li class="update-edit">
            <?php print l('<span class="icon-edit-sign"></span>'. t('Edit'), 'node/' . $node->nid . '/edit', array('html'=>TRUE)); ?>
          </li>
        <?php } ?>
      </ul>
    </div>
  </article>
</section>
