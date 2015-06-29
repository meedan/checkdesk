<?php
	$navigation = _checkdesk_main_navigation();
?>

<?php if(isset($navigation)) : ?>
	<nav role="navigation">
		<?php print $navigation; ?>
	</nav>
<?php endif; ?>