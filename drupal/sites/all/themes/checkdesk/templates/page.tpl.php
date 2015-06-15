

  <!-- ______________________ HEADER _______________________ -->
<header id="header">
  <?php if ($secondary_nav): ?>
    <?php print $secondary_nav; ?>
  <?php endif; ?>

  <?php if ($title): ?>
  <div id="page-title">
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
        } elseif (arg(0) == 'user' && is_numeric(arg(1))) {
          $account = user_load(arg(1));
          if (arg(2) == 'notifications') {
            print t('Receive notifications');
          }
          else {
            print t('<strong>@user\'s</strong> reports', array('@user' => $account->name));
          }
        } else {
          print $title;
        }
      ?>
    </h1>
  </div>
  <?php endif; ?>

  <?php if ($page['navigation']) : ?>
    <?php print render($page['navigation']); ?>
  <?php endif; ?>
</header>


  <!-- ______________________ MAIN _______________________ -->

<div id="main" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($page['sidebar_first']): ?>
    <div id="sidebar-first" class="column sidebar first">
      <div id="sidebar-first-inner" class="inner">
        <?php print render($page['sidebar_first']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($page['widgets'] && checkdesk_widgets_visibility()): ?>
    <aside id="widgets" class="column widgets">
      <div id="widgets-inner" class="inner">
        <?php print render($page['widgets']); ?>
      </div>
     </aside>
  <?php endif; ?> 

  <div id="content">
      <?php if ($page['header']): ?>
        <div id="header-region">
          <?php print render($page['header']); ?>
        </div>
      <?php endif; ?>

      <?php if ($messages || $tabs || $action_links): ?>
        <div id="content-header">

          <?php print render($title_suffix); ?>
          <div id="messages-container">
            <?php print $messages; ?>
          </div>
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

      <?php // print $feed_icons; ?>
  </div> <!-- /content -->

  <?php if ($page['sidebar_second']): ?>
    <aside id="sidebar-second" class="column sidebar-second">
      <div id="sidebar-second-inner" class="inner">
        <?php print render($page['sidebar_second']); ?>
      </div>
    </aside>
  <?php endif; ?> <!-- /sidebar-second -->

  <!-- ______________________ FOOTER _______________________ -->

  <?php if (checkdesk_footer_visibility()) : ?>        
  <?php if (isset($information_nav) || isset($footer_nav)): ?>
    <footer id="footer">
      <div id="footer-inner" class="inner">
        <?php if($page['footer']): ?>
          <?php print render($page['footer']); ?>
        <?php endif; ?>
        <?php //if ($footer_nav): ?>
          <?php //print $footer_nav; ?>
        <?php //endif; ?>
        <?php if ($information_nav): ?>
          <?php print $information_nav; ?>
        <?php endif; ?>
      </div>
    </footer> <!-- /footer -->
  <?php endif; ?>
  <?php endif; ?>

</div> <!-- /main -->