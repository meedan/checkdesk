<?php
//echo "melsawy";
//print_r($content);
//exit;
  // dsm($node);
  global $language;
  $parent_story_id = $node->field_desk[LANGUAGE_NONE][0]['target_id'];
  $update_anchor = 'update-' . $node->nid;
  $update_link = url('node/'.$parent_story_id, array('fragment' => $update_anchor, 'language' => $language));
?>
<section class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <article class="update <?php if (isset($title)) { print ' with-title'; } else { ' no-title'; }?>">
    <div class="update-body">
      <?php if (isset($title)) { ?>
        <h2 class="update-title"><?php print $title; ?></h2>
      <?php } ?>
      <?php print render($content['body']); ?>
    </div>
    <div class="update-footer">
      <ul class="update-meta">
        <li class="update-at">
          <a href="<?php print $update_link; ?>"><span class="icon-clock-o"></span><?php print $created_at; ?></a>
        </li>
        <li class="update-by">
          <?php if (isset($user_avatar)) { ?>
            <?php print $user_avatar; ?>
          <?php } ?>
          <?php print $created_by; ?>
        </li>
        <li class="update-share">
           <?php print render($content['links']); ?>
        </li>
       <?php if (in_array('administrator', $user->roles) || in_array('journalist', $user->roles)) { ?>
          <li class="update-edit">
            <?php print l('<span class="icon-pencil-square"></span>'. t('Edit'), 'node/' . $node->nid . '/edit', array('html'=>TRUE)); ?>
          </li>
        <?php } ?>
      </ul>
    </div>
  </article>
</section>
