<div class="user-info">

  <?php if (isset($user_picture)): ?>
  <div class="user-info-picture">
    <?php print $user_picture; ?>
  </div>
  <?php endif; ?>

  <?php if (isset($linked_accounts)): ?>
  <div class="linked-accounts">
    <?php print $linked_accounts; ?>
  </div>
  <?php endif; ?>

  <?php if (isset($followed_stories)): ?>
  <div class="followed-stories">
    <?php print $followed_stories; ?>
  </div>
  <?php endif; ?>

  <?php if (isset($edit_profile) && isset($edit_notifications)): ?>
  <div class="profile-links">
     <?php if (isset($edit_profile)): ?>
       <?php print $edit_profile; ?>
     <?php endif; ?>

     <?php if (isset($edit_notifications)): ?>
       <?php print $edit_notifications; ?>
     <?php endif; ?>
  </div>
  <?php endif; ?>

</div>
