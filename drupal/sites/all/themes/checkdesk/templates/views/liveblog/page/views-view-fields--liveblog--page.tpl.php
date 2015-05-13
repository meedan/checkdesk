<?php
  global $language;

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
  }
  $author = t('<a class="contributor" href="@user">!user</a>', array(
    '@user' => url('user/'. $user->uid),
    '!user' => $user->name,
  ));
  
  // get timezone information to display in timestamps e.g. Cairo, Egypt
  $site_timezone = checkdesk_get_timezone();
  $timezone = t('!city, !country', array('!city' => t($site_timezone['city']), '!country' => t($site_timezone['country'])));
  // FIXME: Ugly hack
  if ($site_timezone['city'] == 'Jerusalem') {
    $timezone = t('Jerusalem, Palestine');
  }

?>
<div class="desk" id="desk-<?php print $fields['nid']->raw; ?>" style="clear: both;">
  <article class="story">

    <h1><?php print l($fields['title']->raw, 'node/' . $fields['nid']->raw); ?></h1>

    <div class="story-meta">
      <div class="story-attributes">
        <?php print $author; ?> <span class="separator">&#9679;</span> <?php print render($fields['created']->content); ?>
        <?php if (isset($story_commentcount)) { ?>
          <div class="story-commentcount">
            <a href="<?php print url('node/' . $fields['nid']->raw, array('fragment' => 'story-comments-' . $fields['nid']->raw)); ?>">
              <span class="icon-comment-o"><?php print render($story_commentcount); ?></span>
            </a>
          </div>
        <?php } ?>
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

    <?php if (isset($follow_story)) : ?>
      <div class="story-follow">
        <?php print $follow_story; ?>
      </div>
    <?php endif; ?>

    <div class="story-updates-wrapper">
      <?php print $updates; ?>
    </div>
  </article>
</div>
