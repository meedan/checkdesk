<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

	$section_rows = array_chunk($rows, 4, true);

?>

<section class="cd-container">
	<div class="cd-container-inner">
		<div class="cd-container-header">
	  	<h2 class="cd-container-header-title"><?php print t('Sections'); ?></h2>
		</div>
	<div class="cd-container-body">
		<?php foreach ($section_rows as $s_rows) : ?>
			<?php if (count($s_rows) == 4): ?>
		  	<div class="cd-slice-wrapper">
					<ul class="cd-slice l-row l-row-cols-4 u-unstyled">
						<?php foreach ($s_rows as $id => $row): ?>
						  <li class="cd-slice-item l-row-item l-row-item-span-1<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id];  } ?>">
						    <?php print $row; ?>
						  </li>
						<?php endforeach; ?>
					</ul>
				</div>
			<?php else : ?>
				<div class="cd-slice-wrapper">
					<div class="cd-linkslist-container">
						<ul class="cd-slice cd-linkslist l-list l-list-columns-4 u-unstyled">
							<?php foreach ($s_rows as $id => $row): ?>
							  <li class="cd-slice-item l-list-item l-list-item-span-1<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id];  } ?>">
							    <?php print $row; ?>
							  </li>
							<?php endforeach; ?>
						</ul>
					</div>
				</div>
			<?php endif; ?>
    <?php endforeach; ?>
	</div>
</section>