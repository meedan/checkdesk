<div class="cd-pass-reset">
  <div>
    <strong><?php print t('We sent you an email to reset the password'); ?></strong>
  </div>
  <div>
    <?php print t('find it in your inbox (or junk).'); ?>
  </div>
  <?php if(!empty($resend)) : ?>
  <div>
    <span style="padding: 10px;"><?php print $resend; ?></span>
    <span style="padding: 10px;">
      <a href="#" onclick="jQuery('div.cd-pass-reset').parent().remove();return;"><?php print t('DONE'); ?></a>
    </span>
  </div>
  <?php endif; ?>
</div>