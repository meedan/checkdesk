<?php

/**
 * @file
 * Default theme implementation to display a flag link, and a message after the action
 * is carried out.
 *
 * Available variables:
 *
 * - $flag: The flag object itself. You will only need to use it when the
 *   following variables don't suffice.
 * - $flag_name_css: The flag name, with all "_" replaced with "-". For use in 'class'
 *   attributes.
 * - $flag_classes: A space-separated list of CSS classes that should be applied to the link.
 *
 * - $action: The action the link is about to carry out, either "flag" or "unflag".
 * - $status: The status of the item; either "flagged" or "unflagged".
 *
 * - $link_href: The URL for the flag link.
 * - $link_text: The text to show for the link.
 * - $link_title: The title attribute for the link.
 *
 * - $message_text: The long message to show after a flag action has been carried out.
 * - $after_flagging: This template is called for the link both before and after being
 *   flagged. If displaying to the user immediately after flagging, this value
 *   will be boolean TRUE. This is usually used in conjunction with immedate
 *   JavaScript-based toggling of flags.
 *
 * NOTE: This template spaces out the <span> tags for clarity only. When doing some
 * advanced theming you may have to remove all the whitespace.
 */

  ctools_include('modal');
  ctools_include('ajax');
  ctools_modal_add_js();
?>

<?php if ($link_href): ?>
  <?php
    // dd($link_href);
  	$url = parse_url($link_href);
  	$path = 'node/' . str_replace("/checkdesk/drupal/", "", $url['path']) . '/nojs';

    //dd($path);
  ?>
  <!-- <a href="<?php print $path; ?>" title="<?php print $link_title; ?>" class="<?php print $flag_classes ?> ctools-modal-checkdesk-style" rel="nofollow"><?php print $link_text; ?></a> -->
  <?php print ctools_modal_text_button($link_text, $path, $link_title, $flag_classes . ' ctools-modal-checkdesk-style'); ?>
<?php else: ?>
  <?php print $link_text; ?>
<?php endif; ?>
<?php if ($after_flagging): ?>
  <?php 
  	// set message
  	drupal_set_message($message_text, 'warning');
  	drupal_add_js('(function($){ Drupal.ajax["checkdesk_core_message_settings"].setMessages(); })(jQuery);', array('type' => 'inline'));
  ?>
<?php endif; ?>