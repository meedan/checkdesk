<div>
 <div>
   <h1 class="title"><?php print t('Checkdesk'); ?></h1>
   <div><?php print t('Sign in or create an account'); ?></div>
 </div>
  <?php if(isset($links['twitter'])) : ?>
    <div class="cd-twitter">
      <?php print $links['twitter'] ?>
    </div>
  <?php endif; ?>

  <?php if(isset($links['facebook'])) : ?>
    <div class="cd-facebook">
      <?php print $links['facebook'] ?>
    </div>
  <?php endif; ?>

  <div class="cd-login">
    <?php print $links['login'] ?>
  </div>

  <div class="or">
    <span><?php print t('or'); ?></span>
  </div>

  <div class="cd-register">
    <?php print $links['register'] ?>
  </div>

</div>