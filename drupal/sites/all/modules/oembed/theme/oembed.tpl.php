<?php
/**
 * @file
 * Default template file for oembed data
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <a href="<?php print $original_url; ?>"<?php print $title_attributes; ?>><?php print render($title); ?></a>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <span<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </span>
</div>
