<?php 
	$update_number = count(array_reverse($rows));
?>
<div class="updates">
	<?php foreach ($rows as $id => $row): ?>
	  <div class="update-row <?php print $classes_array[$id]; ?>">
	  	<header class="update-info">
	    	<?php print t('Update'); ?> <b>#<?php print $update_number; ?></b>
	    </header>
	    <?php print $row; ?>
	  </div>
	  <?php $update_number--; ?>
	<?php endforeach; ?>
</div>