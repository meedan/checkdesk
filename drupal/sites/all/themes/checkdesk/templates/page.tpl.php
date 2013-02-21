<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <!-- ______________________ HEADER _______________________ -->

  <header id="navbar" role="banner" class="navbar navbar-fixed-top">
    <div class="navbar-inner">
      <div class="container">
          <nav role="navigation">
            <?php if ($primary_nav): ?>
              <?php print $primary_nav; ?>
            <?php endif; ?>

            <?php if ($secondary_nav): ?>
              <?php print $secondary_nav; ?>
            <?php endif; ?>

            <?php if ($page['navigation']): ?>
              <div id="navigation-region">
                <?php print render($page['navigation']); ?>
              </div>
            <?php endif; ?>
          </nav>
      </div>
    </div>
  </header>

  <!-- ______________________ MAIN _______________________ -->

  <div id="main" class="clearfix">
    <?php if ($page['sidebar_first']): ?>
      <div id="sidebar-first" class="column sidebar first">
        <div id="sidebar-first-inner" class="inner">
          <?php print render($page['sidebar_first']); ?>
        </div>
      </div>
    <?php endif; ?> <!-- /sidebar-first -->

    <div id="content">
      <div id="content-inner" class="inner column center">
        <?php if ($title|| $messages || $tabs || $action_links): ?>
          <div id="content-header">

            <?php if ($title): ?>
              <h1 class="title">
                <?php
                  if (arg(0) == 'user' && arg(1) == 'register') {
                    print t('Create an account');
                  } elseif (arg(0) == 'user' && arg(1) == 'password') {
                    print t('Retrieve lost password');
                  } elseif (arg(0) == 'user' && arg(1) == 'login') {
                    print t('Sign In');
                  } elseif (arg(0) == 'user' && arg(1) == '') {
                    print t('Sign In');
                  } else {
                    print $title;
                  }
                ?>
              </h1>
            <?php endif; ?>

            <?php print render($title_suffix); ?>
            <?php print $messages; ?>
            <?php print render($page['help']); ?>

            <?php if ($tabs): ?>
              <div class="tabs"><?php print render($tabs); ?></div>
            <?php endif; ?>

            <?php if ($action_links): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
            <?php endif; ?>
            
          </div> <!-- /#content-header -->
        <?php endif; ?>

        <div id="content-area">
          <?php print render($page['content']); ?>
        </div>

        <?php print $feed_icons; ?>

      </div>
    </div> <!-- /content-inner /content -->

    <?php if ($page['sidebar_second']): ?>
      <div id="sidebar-second" class="column sidebar second">
        <div id="sidebar-second-inner" class="inner">
          <?php print render($page['sidebar_second']); ?>
        </div>
      </div>
    <?php endif; ?> <!-- /sidebar-second -->

  </div> <!-- /main -->

  <!-- ______________________ FOOTER _______________________ -->

  <?php if ($page['footer']): ?>
    <div id="footer">
      <?php print render($page['footer']); ?>
    </div> <!-- /footer -->
  <?php endif; ?>

</div> <!-- /page -->
