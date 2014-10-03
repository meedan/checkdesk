<?php 
// dsm($fields);
// prep user picture
$account = user_load($fields['uid']->raw);

?>

<?php print _set_user_avatar_bg($account, array('avatar', 'thumb-60')); ?>
<div class="activity-item-wrapper item-wrapper">
  <div class="activity-item-message item-message">
    <time class="timestamp"><?php print $fields['created_at']->content; ?></time>
    <?php print $fields['message_1']->content; ?>
  </div> <!-- /activity-item-messsage -->
  <?php print $fields['message_id']->content; ?>
</div> <!-- /activity-item-wrapper -->
