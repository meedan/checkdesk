<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>

<section class="cd-container">
	<div class="cd-container-inner">
		<div class="cd-container-header">
	  	<h2 class="cd-container-header-title"><?php print t('Sections'); ?></h2>
		</div>
	<div class="cd-container-body">
  	<div class="cd-slice-wrapper">
			<ul class="cd-slice l-row l-row-cols-4 u-unstyled">
				<?php foreach ($rows as $id => $row): ?>
				  <li class="cd-slice-item l-row-item l-row-item-span-1<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id];  } ?>">
				    <?php print $row; ?>
				  </li>
				<?php endforeach; ?>
			</ul>
		</div>
	</div>
</section>