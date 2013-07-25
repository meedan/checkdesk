<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ MAIN _______________________ -->
  <div id="main" class="clearfix">
    <div id="content" class="clearfix">
      <div id="content-inner" class="inner column center">

        <div id="content-area">
          <?php print render($page['content']); ?>
        </div>

      </div>
    </div> <!-- /content-inner /content -->

    <div id="footer">
      <div id="footer-inner" class="inner">
        <a href="<?php print $content_url; ?>" class="factcheck-cta btn btn-large"><span class="icon-comments-alt"></span> Help verify this report</a>

        <?php if ($page['footer']): ?>
          <?php print render($page['footer']); ?>
        <?php endif; ?>
      </div>
    </div> <!-- /footer -->

  </div> <!-- /main -->

</div> <!-- /page -->
