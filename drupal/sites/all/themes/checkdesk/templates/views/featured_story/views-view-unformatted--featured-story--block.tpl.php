<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

?>

<section class="cd-container cd-container-section cd-container-first">
	<div class="cd-container-inner">
	<?php if (!empty($title)): ?>
		<div class="cd-container-header">
	  	<h2 class="cd-container-header-title"><?php print $title; ?></h2>
		</div>
	<?php endif; ?>
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