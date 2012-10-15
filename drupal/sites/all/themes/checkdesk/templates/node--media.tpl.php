<section id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  
  <article class="report">
    <header>
      <h3>
        <?php print render($content['report_source']); ?>
      </h3>
      <ul class="report-actions">
        <li class=""><a href="<?php print url('<front>') . 'node/' . $node->nid ?>/edit"><i class="icon-edit"></i> Edit</a></li>
        <li class="dropdown">
          <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-flag"></i> Flag as</a>
          <ul class="dropdown-menu">
            <li><a href="#">Flag spam</a></li>
            <li><a href="#">Flag graphic content</a></li>
            <li><a href="#">Flag for fact-checking</a></li>
          </ul>
        </li>
        <li class="dropdown">
          <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-share"></i> Share on</a>
          <ul class="dropdown-menu">
            <li><a href="#">Share on Facebook</a></li>
            <li><a href="#">Share on Twitter</a></li>
            <li><a href="#">Share on Google+</a></li>
          </ul>
        </li>
        <li class="dropdown">
          <a href="#" class="dropdown-toggle" data-toggle="dropdown"><i class="icon-plus-sign"></i> Add to</a>
          <ul class="dropdown-menu">
            <li><a href="#">Share on Facebook</a></li>
            <li><a href="#">Share on Twitter</a></li>
            <li><a href="#">Share on Google+</a></li>
          </ul>
        </li>
      </ul>
    </header>

    <section class="report-content">
      <div class="report-media">
        <div class="container">
          <?php print render($content['field_link']); ?>
        </div>
      </div>
      <p>
        <?php
          if(!empty($node->picture)) {
            $user_avatar = theme('image_style', array('path' => $node->picture->uri, 'alt' => t(check_plain($node->name)), 'style_name' => 'navigation_avatar'));
          }
        ?>
        <a class="gravatar" href="<?php print url('<front>') . 'user/' . $node->uid ?>">
          <?php print $user_avatar; ?>
        </a>
        <a href="<?php print url('<front>') . 'user/' . $node->uid ?>"><?php print $node->name; ?></a> added this <time class="time-ago" pubdate datetime="<?php print format_date($created, 'custom', 'Y-m-d\TH:i:sP'); ?>"><?php print format_interval(time()-$created); ?> ago</time>
      </p>
      <div class="description"><?php print render($content['body']); ?></div>
    </section>


    <section id="report-activity-node-<?php print $node->nid; ?>" class="report-activity">

      <?php
        $view = views_get_view('activity_report');
        $view->set_arguments(array($node->nid));
        $view_output = $view->preview('block');
        $total_rows = count($view->result);
        $view->destroy();
      ?>

      <?php if($total_rows > 0) : ?>

        <?php 
          $status = taxonomy_term_load($node->field_rating['und'][0]['tid']);
          if($status->name == 'Verified') {
            $status_class = 'verified';
            $icon = '<i class="icon-ok-sign"></i> ';
          }
          if($status->name == 'Undetermined') {
            $status_class = 'undetermined';
            $icon = '<i class="icon-question-sign"></i> ';
          }
          if($status->name == 'False') {
            $status_class = 'false';
            $icon = '<i class="icon-remove-sign"></i> ';
          }
          if($status->name == 'Not Applicable') {
            $status_class = '';
          }
        ?>

        <header class="<?php print $status_class; ?>">
          <a href="#">
            <h3><?php print $total_rows; ?> fact-checking comments</h3>
            <div class="report-status">
                <?php print $icon . $status->name; ?>
            </div>
          </a>
        </header>

        <?php print $view_output; ?>
      <?php endif; ?>

<!--       <div class="comment-form">
        
      </div>

      <footer>
        Something in small 
      </footer> -->
    </section>

  </article>

</section>