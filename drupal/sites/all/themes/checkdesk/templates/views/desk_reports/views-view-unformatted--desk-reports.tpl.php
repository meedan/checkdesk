<?php foreach ($rows as $id => $row): ?>
  <div class="report-row <?php print $classes_array[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
