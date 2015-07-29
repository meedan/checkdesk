<?php $view = views_get_current_view(); ?>
<div class="activity-content item-content <?php print $classes;?>"<?php print $attributes; ?>> 
  <?php if ($view && $view->name == 'my_notifications') { ?>
  	<div class="activity-data">
      <?php if(render($content['avatar'])) : ?>
  		<div class="activity-data-image">
  			<?php print render($content['avatar']); ?>
  		</div>
      <?php endif; ?>
  		<div class="activity-data-message">
  			<?php print render($content['message']); ?>
        <div class="activity-meta">
          <?php print render($content['time']); ?>
        </div>
  		</div>
  	</div>
  <?php } else { ?>
  	<?php print render($content['message']); ?>
  <?php } ?>
</div>