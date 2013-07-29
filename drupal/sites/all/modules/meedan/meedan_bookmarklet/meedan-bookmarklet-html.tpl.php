<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
  "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>" id="meedan_bookmarklet_html">
<head>
  <?php print $head; ?>
  <title><?php print (!empty($title) ? strip_tags($title) : $head_title); ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>
<body id="meedan_bookmarklet" style="padding: 1em;" class="<?php print (isset($body_class) ? $body_class : ''); ?>">
  <div id="main" class="clearfix">
    <?php if (!empty($meedan_bookmarklet_close)) { ?>
      <?php print $meedan_bookmarklet_close; ?>
    <?php } ?>

    <?php if (!empty($meedan_bookmarklet_title)) { ?>
      <h2><?php print $meedan_bookmarklet_title; ?></h2>
    <?php } ?>
    <?php if (!empty($meedan_bookmarklet_messages) && is_array($meedan_bookmarklet_messages)) { ?>
      <ul id="meedan_bookmarklet_messages">
        <?php foreach ($meedan_bookmarklet_messages as $message) { ?>
          <li><?php print $message; ?></li>
        <?php } ?>
      </ul>
    <?php } ?>
    <div class="clear-block">
      <?php print $page; ?>
    </div>
    <div class="footer">
      <?php if (isset($footer)) print $footer; ?>
    </div>
  </div>
</body>
</html>
