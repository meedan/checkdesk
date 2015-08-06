<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<section class="cd-container cd-container-section">
	<div class="cd-container-inner">
	<?php if (!empty($title)): ?>
		<div class="cd-container-header">
	  	<h2 class="cd-container-header-title"><?php print $title; ?></h2>
		</div>
	<?php endif; ?>
	<div class="cd-container-body">
		<div class="cd-slice-wrapper">
			<?php if (count($rows) > 4): ?> 
					<ul class="cd-slice l-row l-row-cols-4 u-unstyled">
						<?php foreach ($rows as $id => $row): ?>
						  <li class="cd-slice-item l-row-item l-row-item-span-1<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id];  } ?>">
						    <?php print $row; ?>
						  </li>
						<?php endforeach; ?>
					</ul>
			<?php else : ?>
				<div class="cd-linkslist-container">
					<ul class="cd-slice cd-linkslist l-list l-list--columns-4 u-unstyled">
						<?php foreach ($rows as $id => $row): ?>
						  <li class="cd-slice-item l-list-item l-list-item-span-1<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id];  } ?>">
						    <?php print $row; ?>
						  </li>
						<?php endforeach; ?>
					</ul>
				</div>
			<?php endif; ?>
		</div>
	</div>
</section>