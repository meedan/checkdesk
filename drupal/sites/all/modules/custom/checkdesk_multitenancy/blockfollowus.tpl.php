<div class="elsewhere">
<h2><?php print t('Follow us') ?></h2>
  <ul>
    <?php if (!empty($facebook)) { ?>
      <li><a href="<?php print $facebook; ?>"><span class="icon-facebook"></span></a></li>
    <?php } ?>
    
    <?php if (!empty($twitter)) { ?>
      <li><a href="<?php print $twitter; ?>"><span class="icon-twitter"></span></a></li>
    <?php } ?>

    <?php if (!empty($gplus)) { ?>
      <li><a href="<?php print $gplus; ?>"><span class="icon-google-plus"></span></a></li>
    <?php } ?>
  </ul>
</div>
