<div id="updates">
<?php foreach ($rows as $id => $row): ?>
  <div class="update-row <?php print $classes_array[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
</div>