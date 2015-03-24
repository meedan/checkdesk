<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $options['type'] will either be ul or ol.
 * @ingroup views_templates
 */
$total = count($rows) - 1;
?>
<?php print $wrapper_prefix; ?>
  <?php if (!empty($title)) : ?>
    <h3><?php print $title; ?></h3>
  <?php endif; ?>
  <?php print $list_type_prefix; ?>
    <?php foreach ($rows as $id => $row): ?>
      <?php
          $separator = '';
          if($total > 1 && $id != $total && $id != 1) {
            $separator = t(',');
          }
          elseif($total == 2 && $id == 1) {
            $separator = t(', and');
          }
          elseif($total == 1 && $id == 0) {
            $separator = t(' and');
          }
          elseif($id == $total) {
            $separator = t(' found');
          }
      ?>
      <li class="<?php print $classes_array[$id]; ?>"><?php print $row . $separator; ?></li>
    <?php endforeach; ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>

<div class="search-reset-filters">
  <?php print l(t('Reset all filters'), 'search', array('attributes' => array('class' => array('search-reset')))); ?>
</div>
