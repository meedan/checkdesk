<?php 
  // dsm($fields);
  // prep user picture
  $user = user_load($fields['uid']->raw);
  // dsm($user);
  $avatar = l('', 'user/'. $user->uid, array('html' => TRUE, 'attributes' => array('class' => array('avatar', 'thumb-60'), 'title' => $user->name, 'style' => 'background-image: url("' . image_style_url('activity_avatar', $user->picture->uri). '")')));
?>

<?php print $avatar; ?>
<div class="activity-item-wrapper report-status-change">
  <a class="actor" href="/users/">John Hodgman</a> <?php print $fields['message_1']->content; ?> <time class="timestamp"><?php print $fields['created_at']->content; ?></time>
  <span class="activity-item-content">
    <div class="inline-attachment">
      <div class="inline-attachment-wrapper">
        <div class="inline-attachment-bar"><div class="indent"></div></div>
        <div class="content">
          <div class="inline-holder inline-img-thumb-holder">
            <img class="inline-img-thumb" src="https://dl.dropboxusercontent.com/u/450152/cover-photo.png" />
          </div>
          <div class="content-details">
            <span class="title">Explosion in Daraa Village Said to Kill Activists</span>
            <span class="author">Domino Recording Co.</span>
            <span><span class="icon-youtube-play"></span> <span class="ts">Tue, July 8th at 4:03 PM</span></span>
          </div>
          <span class="inline-attachment-status report-status"><span class="icon-check-circle verified"> <strong>Verified</strong></span> by Bellingcat</span>
        </div>
      </div>
    </div> <!-- /inline-attachment -->

    Given the weight of reporting in world media, the number of photos and videos from different angles, and an “apology” from the perpetrator, we can say this is “verified”, though questions certainly remain as to the identity of the man being kicked.

  </span> <!-- /activity-item-content -->
</div> <!-- /activity-item-wrapper -->
<div class="activity-item-footer">
  <div class="meta">
    4 verification footnotes
  </div>
  <div class="actions" role="toolbar">
    <span class="icon-share"></span>
    <span class="icon-flag-o"></span>
    <span class="icon-plus-square-o"></span>
  </div>
</div> <!-- /activity-item-footer -->