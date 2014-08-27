<?php 
  // dsm($fields);
  // prep user picture
  $user = user_load($fields['uid']->raw);
  // dsm($user);
  $avatar = l('', 'user/'. $user->uid, array('html' => TRUE, 'attributes' => array('class' => array('avatar', 'thumb-60'), 'title' => $user->name, 'style' => 'background-image: url("' . image_style_url('activity_avatar', $user->picture->uri). '")')));
?>

<?php print $avatar; ?>
<div class="activity-item-wrapper item-wrapper">
  <div class="activity-item-message item-message">
    <time class="timestamp"><?php print $fields['created_at']->content; ?></time>
    <?php print $fields['message_1']->content; ?>
  </div> <!-- /activity-item-messsage -->
  <?php print $fields['message_id']->content; ?>
</div> <!-- /activity-item-wrapper -->