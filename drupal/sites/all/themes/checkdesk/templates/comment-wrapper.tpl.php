<section id="comment-form" class="<?php print $classes; ?>">
	<?php hide($content['comments']); ?>
	<?php if(isset($node->comment_count) && $node->comment == 2) { ?>		
		<?php 
			hide($content['comment_form']['author']);
			hide($content['comment_form']['comment_body']['und']['0']['format']);
			print render($content['comment_form']); 
		?>
	<?php } ?>
	<?php if(isset($node->comment_count) && $node->comment == 1) { ?>
		<div class="messages status">Comments are closed.</div>
	<?php } ?>
</section> <!-- /comment-form -->