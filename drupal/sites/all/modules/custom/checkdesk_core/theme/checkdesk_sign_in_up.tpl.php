<div class="modal-dialog modal-dialog-signin">
  <div class="branding"></div>
  <div class="modal-dialog-description"><?php print t('Sign in or create an account'); ?></div>
  <div class="modal-dialog-actions">
    <?php if(isset($links['twitter'])) : ?>
      <?php print $links['twitter'] ?>
    <?php endif; ?>

    <?php if(isset($links['facebook'])) : ?>
      <?php print $links['facebook'] ?>
    <?php endif; ?>

    <?php print $links['login'] ?>

    <div class="or">
      <span><?php print t('or'); ?></span>
    </div>

    <?php print $links['register'] ?>
  </div>
</div>