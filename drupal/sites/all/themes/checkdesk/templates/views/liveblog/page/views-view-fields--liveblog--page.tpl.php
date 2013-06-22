<?php
  $user = user_load($fields['uid']->raw);
  $user_picture = $user->picture;
  if (!empty($user_picture)) {
    $options = array(
      'html' => TRUE,
      'attributes' => array(
        'class' => 'gravatar'
      )    
    );
    $user_avatar = l(theme('image_style', array('path' => $user_picture->uri, 'alt' => t(check_plain($user->name)), 'style_name' => 'navigation_avatar')), 'user/'. $user->uid, $options);
    $author = t('<a href="@user">!user</a>', array(
      '@user' => url('user/'. $user->uid),
      '!user' => $user->name,
    ));
  }
?>
<div class="desk" id="desk-<?php print $fields['nid']->raw; ?>" style="clear: both;">
  <article class="story">
    <h1><?php print l($fields['title']->raw, 'node/' . $fields['nid']->raw); ?></h1>

    <div class="story-meta">
      <div class="story-at">
        <?php if (isset($user_avatar)) : ?>
          <?php print $user_avatar; ?>
        <?php endif; ?>
        <?php print $author; ?> <span class="separator">&#9679;</span> <?php print render($fields['created']->content); ?>
      </div>
    </div>

    <?php if(isset($fields['field_lead_image']->content)) { ?>
      <figure>
        <?php print render($fields['field_lead_image']->content); ?>
      </figure>
    <?php } ?>

    <div class="story-body">
      <?php print render($fields['body']->content); ?>
    </div>
    
    <?php print $updates; ?>

    <div class="story-footer">
      <?php print l(t('Updated at ') . render($fields['changed']->content), 'node/' . $fields['nid']->raw); ?>
    </div>

  </article>
</div>
