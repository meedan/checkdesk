<?php

/**
 * @file
 * Default theme implementation to provide an HTML container for comments.
 *
 * Available variables:
 * - $content: The array of content-related elements for the node. Use
 *   render($content) to print them all, or
 *   print a subset such as render($content['comment_form']).
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default value has the following:
 *   - comment-wrapper: The current template type, i.e., "theming hook".
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $comment_form_placement (string): Indicates if the comment form should be
 *   placed above the comments when they are sorted newest to oldest, or below
 *   the comments when they are sorted oldest to newest, the Drupal default.
 * - $labels (array): An array of labels that can be configured in the content
 *   type edit form in the comment vertical tab.
 *   - form_label: The label above the new comment form.
 *   - section_label: The label above the list of comments.
 *
 * The following variables are provided for contextual information.
 * - $node: Node object the comments are attached to.
 * The constants below the variables show the possible values and should be
 * used for comparison.
 * - $display_mode
 *   - COMMENT_MODE_FLAT
 *   - COMMENT_MODE_THREADED
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_comment_wrapper()
 * @see theme_comment_wrapper()
 */
?>
<div id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if ($comment_form_placement == 'top') : ?>
    <?php if ($content['comment_form']): ?>
      <h2 class="title comment-form"><?php print $labels['form_label']; ?></h2>
      <?php print render($content['comment_form']); ?>
    <?php endif; ?>
  <?php endif; ?>

  <?php if ($content['comments'] && $node->type != 'forum'): ?>
    <?php print render($title_prefix); ?>
    <h2 class="title"><?php print $labels['section_label']; ?></h2>
    <?php print render($title_suffix); ?>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php if (empty($comment_form_placement) || $comment_form_placement == 'bottom') : ?>
    <?php if ($content['comment_form']): ?>
      <h2 class="title comment-form"><?php print $labels['form_label']; ?></h2>
      <?php print render($content['comment_form']); ?>
    <?php endif; ?>
  <?php endif; ?>
</div>
