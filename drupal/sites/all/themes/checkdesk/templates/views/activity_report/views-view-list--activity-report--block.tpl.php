<ul class="activity-list">
	<?php foreach ($rows as $id => $row): ?>
		<li class="activity <?php print $classes_array[$id]; ?>">
	    	<?php print $row; ?>
	    </li>
	<?php endforeach; ?>
</ul>