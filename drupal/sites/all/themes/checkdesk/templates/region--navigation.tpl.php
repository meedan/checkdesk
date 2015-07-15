<?php
	$navigation = _checkdesk_main_navigation();
?>

<?php if(isset($navigation)) : ?>
	<nav role="navigation" class="nav-collapse">
		<?php print $navigation; ?>
	</nav>
<?php endif; ?>