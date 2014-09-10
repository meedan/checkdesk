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

  $links = array();
  $url = url('node/' . $fields['nid']->raw, array('absolute' => TRUE, 'alias' => TRUE, 'language' => $language));
  $layout = checkdesk_core_direction_settings();
  $share_links = checkdesk_core_share_links($url, $fields['title']->raw);
  foreach ($share_links as $id => $link) {
    $links[$id] = $link;
  }
  // theme share links into a dropdown
  if (isset($links['checkdesk-share-facebook']) || 
      isset($links['checkdesk-share-twitter']) || 
      isset($links['checkdesk-share-google'])
  ) {
    $share_link = '';
    // Share on
    $share_link .= '<li class="share-on">';

    $share_link .= '<a href="#" class="dropdown-toggle" data-toggle="dropdown"><span class="icon-share">' . t('Share') . '</span></a>';
    $share_link .= '<ul class="dropdown-menu pull-'. $layout['omega'] .'">';
    if (isset($links['checkdesk-share-facebook'])) {
      $share_link .= '<li>' . l($links['checkdesk-share-facebook']['title'], $links['checkdesk-share-facebook']['href'], $links['checkdesk-share-facebook']) . '</li>';
    }
    if (isset($links['checkdesk-share-twitter'])) {
      $share_link .= '<li>' . l($links['checkdesk-share-twitter']['title'], $links['checkdesk-share-twitter']['href'], $links['checkdesk-share-twitter']) . '</li>';
    }
    if (isset($links['checkdesk-share-google'])) {
      $share_link .= '<li>' . l($links['checkdesk-share-google']['title'], $links['checkdesk-share-google']['href'], $links['checkdesk-share-google']) . '</li>';
    }
    $share_link .= '</ul></li>'; 
  }

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
      <ul class="content-actions">
        <?php print $share_link; ?>
      </ul>
    </div>

    <div class="story-body">
      <?php print render($fields['body']->content); ?>
    </div>

    <?php if(isset($fields['field_lead_image']->content)) { ?>
      <figure>
        <?php print render($fields['field_lead_image']->content); ?>
      </figure>
    <?php } ?>

    <div class="story-updates-wrapper">
      <?php print $updates; ?>
    </div>

    <a class="story-footer" href="<?php print url('node/' . $fields['nid']->raw); ?>">
      <div class="story-continue">
        <span class="link"></span> <span class="permalink"><?php print t('Go to story'); ?></span>
      </div>
      <div class="story-updated-at">
        <?php print t('Updated at ') . render($fields['changed']->content) . ' ' . $timezone; ?>
      </div>
    </a>
  </article>
</div>
