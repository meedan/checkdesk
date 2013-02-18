<div class="posts">
	<?php foreach ($rows as $id => $row): ?>
	  <div class="post-row <?php print $classes_array[$id]; ?>">
	    <?php print $row; ?>
	  </div>
	<?php endforeach; ?>
</div>
