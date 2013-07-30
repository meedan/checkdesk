<?php
/**
 * @file
 * Custom template file for oembed data
 * This is the template that is used to display rendered embedded media
 * It includes Youtube, Twitter etc.
 */
  if(isset($embed->provider_name)) {
    $provider = strtolower($embed->provider_name);
    $provider_class_name = str_replace('.', '_', $provider);
  }
?>
<div class="<?php print $classes . ' ' . $provider_class_name; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <a href="<?php print $original_url; ?>"<?php print $title_attributes; ?>><?php print render($title); ?></a>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>

  <div class="embed-attributes">
    <?php if ($favicon_link) : ?>
      <div class="favicon"><?php print $favicon_link ?></div>
    <?php endif ?>
    <?php if (isset($embed->author_name)) : ?>
      <div class="author"><?php print $embed->author_url ? l($embed->author_name, $embed->author_url) : $embed->author_name; ?></div>
    <?php endif ?>
    <?php if (isset($embed->original_url)) : ?>
      <div class="permalink">
        <?php print l('<span class="icon-link"></span>', $embed->original_url, array('attributes' => array('title' => t('View original')), 'html' => TRUE)); ?>
      </div>
    <?php endif ?>
  </div>
  <?php if (isset($embed_error)) : ?>
    <div class="embederror"><?php print $embed_error ?></div>
  <?php endif ?>
</div>
