<div class="user-info">

  <div class="user-info-picture">
    <?php print $user_picture; ?>
  </div>

  <div class="linked-accounts">
    <?php print $linked_accounts; ?>
  </div>

  <div class="profile-links">
     <?php if ($edit_profile): ?>
       <?php print $edit_profile; ?>
     <?php endif; ?>

     <?php if (isset($edit_notifications)): ?>
       <?php print $edit_notifications; ?>
     <?php endif; ?>
  </div>

</div>
