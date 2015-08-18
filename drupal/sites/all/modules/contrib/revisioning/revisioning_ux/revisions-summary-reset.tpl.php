<?php
/**
 * @file
 * revisions-summary-reset.tpl.php
 * Removes the items added by revisions/revisions-summary.tpl.php, which
 * adds the submenu that appears above the summary of node revisions.
 * We replace that submenu with buttons at the bottom of the revisions
 * summary in revisioning_ux_page_alter.
 *
 * Variables available:
 * - $submenu_links: an array of <a>-tags
 * - $content: summary of node revisions (as a table)
 */
?>
<?php print $content;
