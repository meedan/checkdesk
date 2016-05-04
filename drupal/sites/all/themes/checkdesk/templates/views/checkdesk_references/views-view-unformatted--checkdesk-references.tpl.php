<?php

/**
 * Display reports in search results format but in a container
 * with just 2 items per row
 * single item takes up entire row
 */
?>
  
<ul class="cd-slice l-row l-row-cols-4 u-unstyled">
  <li class="cd-slice-item l-row-item l-row-item-span-1">
    <ul class="l-list l-list-columns-2 u-unstyled">
      <?php foreach ($rows as $id => $row): ?>
        <li class="cd-slice-item l-list-item l-row-item l-row-item-span-1<?php if ($classes_array[$id]) { print ' ' . $classes_array[$id]; } ?>">
          <div class="cd-item"><?php print $row; ?></div>
        </li>
      <?php endforeach; ?>
    </ul>
  </li>
</ul>