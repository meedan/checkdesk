<div class="stories">
<?php foreach ($rows as $id => $row): ?>
  <div class="story-row <?php print $classes_array[$id]; ?>">
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
</div>