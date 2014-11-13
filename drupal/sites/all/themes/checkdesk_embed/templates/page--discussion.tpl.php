<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ MAIN _______________________ -->

  <div id="main" class="clearfix">

    <div id="content">
      <div id="content-inner" class="inner column center">

        <div id="content-area">
          <?php print render($page['content']); ?>
        </div>

        <?php // print $feed_icons; ?>

      </div>
    </div> <!-- /content-inner /content -->


   <div id="footer">
      <div id="footer-inner" class="inner">
        <?php if ($factcheck_cta): ?>
          <?php print render($factcheck_cta); ?>
        <?php endif; ?>

        <?php if ($page['footer']): ?>
          <?php print render($page['footer']); ?>
        <?php endif; ?>
      </div>
    </div> <!-- /footer -->

  </div> <!-- /main -->
</div> <!-- /page -->
