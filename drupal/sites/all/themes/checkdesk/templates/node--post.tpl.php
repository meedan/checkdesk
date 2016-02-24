<?php
  global $language;
  $parent_story_id = $node->field_desk[LANGUAGE_NONE][0]['target_id'];
  $update_anchor = 'update-' . $node->nid;
  $update_link = url('node/'.$parent_story_id, array('fragment' => $update_anchor, 'language' => $language));
?>

<div class="update-body">
  <?php if ($node->status == 0) : ?>
    <span class="media-label draft"><?php print t('Draft'); ?></span>
  <?php endif; ?>
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
   <?php if (node_access("update", $node, $user)) { ?>
      <li class="update-edit">
        <?php print l('<span class="icon-pencil-square"></span>'. t('Edit'), 'node/' . $node->nid . '/edit', array('html'=>TRUE)); ?>
      </li>
    <?php } ?>
  </ul>
</div>