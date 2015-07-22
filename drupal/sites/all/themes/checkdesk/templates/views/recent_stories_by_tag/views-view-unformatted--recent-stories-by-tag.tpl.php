<ul class="cd-slice l-row u-unstyled">
	<?php foreach ($rows as $id => $row): ?>
  	<li class="cd-slice-item l-row-item-span-1<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id];  } ?>">
    	<?php print $row; ?>
  	</li>
	<?php endforeach; ?>
</ul>