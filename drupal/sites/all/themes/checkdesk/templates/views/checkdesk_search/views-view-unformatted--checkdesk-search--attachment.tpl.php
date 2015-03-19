<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<ul class="page-results">
	<?php foreach ($rows as $id => $row): ?>
  	<li<?php if ($classes_array[$id]) { print ' class="result ' . $classes_array[$id] .'"';  } ?>>
    	<?php print $row; ?>
  	</li>
	<?php endforeach; ?>
</ul>
<div class="search-reset-filters">
  <?php print l(t('Reset all filters'), 'search', array('attributes' => array('class' => array('search-reset')))); ?>
</div>