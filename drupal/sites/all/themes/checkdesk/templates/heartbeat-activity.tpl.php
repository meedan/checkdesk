<?php $view = views_get_current_view(); ?>
<div class="activity-content <?php print $classes;?>"<?php print $attributes; ?>> 
  <?php print (($view && $view->name == 'my_notifications') ? render($content) : render($content['message'])); ?>
</div>
