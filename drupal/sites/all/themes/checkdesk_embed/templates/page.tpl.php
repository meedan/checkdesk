<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ MAIN _______________________ -->
  <div id="main" class="clearfix">
    <div id="content">
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

<!-- For the embedded theme, force all links to open in a new window.
     Note, this is carefully crafted to run as soon as possible (even before
     jQuery ready). -->
<script>
(function ($) {
  var addTargetBlank = function (context) { $('a[href]', context).attr('target', '_blank'); },
      // See: http://stackoverflow.com/a/11546242/806988
      MutationObserver = window.MutationObserver || window.WebKitMutationObserver,
      observer;

  // Run immediately
  addTargetBlank();

  // Also, run on any DOM change
  if (MutationObserver) {
    observer = new MutationObserver(function(mutations, ob) { console.log(mutations); addTargetBlank(mutations); });
    observer.observe(document, { childList: true, attributes: false });
  }
}(jQuery));
</script>
