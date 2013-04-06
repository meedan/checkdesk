<?php
/**
 * @file
 * Default template file for Twitter oembed data
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <a href="<?php print $original_url; ?>"<?php print $title_attributes; ?>><?php print render($title); ?></a>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>

  <?php if ($favicon_link) : ?>
    <div class="favicon"><?php print $favicon_link ?></div>
  <?php endif ?>
  <?php if ($embed->author_name) : ?>
    <div class="author"><?php print $embed->author_url ? l($embed->author_name, $embed->author_url) : $embed->author_name; ?></div>
  <?php endif ?>
  <?php if (isset($embed_error)) : ?>
    <div class="embederror"><?php print $embed_error ?></div>
  <?php endif ?>
</div>
