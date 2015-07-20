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
    <?php
      // the "and" shit
      if (count($rows) == 2) {
        $results = $rows[0] . ' ' . t('and') . ' ' . $rows[1];
      }
      else if (count($rows) > 2) {
        $rows[ count($rows) - 1 ] = t('and') . ' ' . $rows[ count($rows) - 1 ];
        $results = implode(t(',') . ' ', $rows);
      }
      else {
        $results = $rows[0];
      }
      $result_text = t('!results found', array('!results' => $results));
      print $result_text;
    ?>
  <?php print $list_type_suffix; ?>
<?php print $wrapper_suffix; ?>

<div class="search-reset-filters">
  <?php print l(t('Reset all filters'), 'search', array('attributes' => array('class' => array('search-reset')))); ?>
</div>
