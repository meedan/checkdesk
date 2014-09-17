<?php $view = views_get_current_view(); ?>
<div class="activity-content item-content <?php print $classes;?>"<?php print $attributes; ?>> 
  <?php if ($view && $view->name == 'my_notifications') { ?>
  	<div class="activity-data">
  		<div class="activity-data-image">
  			<?php print render($content['avatar']); ?>
  		</div>
  		<div class="activity-data-message">
  			<?php print render($content['message']); ?>
  		</div>
  	</div>
  	<div class="activity-meta">
  		<?php print render($content['time']); ?>
  	</div>
  <?php } else { ?>
  	<?php print render($content['message']); ?>
  <?php } ?>
</div>