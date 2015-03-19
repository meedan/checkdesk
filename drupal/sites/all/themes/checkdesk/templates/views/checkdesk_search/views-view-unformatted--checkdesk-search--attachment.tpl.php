<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
	$total = count($rows) - 1;
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<ul class="page-results list">
	<?php foreach ($rows as $id => $row): ?>
		<?php if($total > 1 && $id != $total && $id != 1) : ?>
	  	<li<?php if ($classes_array[$id]) { print ' class="result ' . $classes_array[$id] .'"';  } ?>>
	    	<?php print $row . t(','); ?>
	  	</li>
	  <?php elseif($total == 2 && $id == 1) : ?>
	  	<li<?php if ($classes_array[$id]) { print ' class="result ' . $classes_array[$id] .'"';  } ?>>
	    	<?php print $row . t(', and'); ?>
	  	</li>
	  <?php elseif($total == 1 && $id == 0) : ?>
	  	<li<?php if ($classes_array[$id]) { print ' class="result ' . $classes_array[$id] .'"';  } ?>>
	    	<?php print $row . t(' and'); ?>
	  	</li>
	 	<?php elseif($id == $total) : ?>
	  	<li<?php if ($classes_array[$id]) { print ' class="result ' . $classes_array[$id] .'"';  } ?>>
            <?php print $row /* . t(' found')*/; ?>
	  	</li>
	  <?php else : ?>
	  	<li<?php if ($classes_array[$id]) { print ' class="result ' . $classes_array[$id] .'"';  } ?>>
	    	<?php print $row; ?>
	  	</li>
		<?php endif; ?>
	<?php endforeach; ?>
</ul>
<div class="search-reset-filters">
  <?php print l(t('Reset all filters'), 'search', array('attributes' => array('class' => array('search-reset')))); ?>
</div>
