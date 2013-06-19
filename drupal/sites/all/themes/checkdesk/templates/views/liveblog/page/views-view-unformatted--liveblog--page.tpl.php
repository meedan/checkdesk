<?php
// Group consecutive updates together by desk
$this_desk_nid = 0;
$last_desk_nid = 0;
?>
<div class="posts">
  <div class="desk">

  <?php foreach ($rows as $id => $row): ?>
    <?php
      $this_desk_nid = $view->result[$id]->node_field_data_field_desk_nid;

      if ($this_desk_nid != $last_desk_nid) {
        if ($last_desk_nid) {
          echo "</article></div> <!-- /desk -->\n";
          echo "<div class=\"desk\">\n";
        }

        echo '<article class="story">';
        echo '<h2>';
        echo   '<span class="field-content">';
        echo     l($view->result[$id]->node_field_data_field_desk_title, "node/$this_desk_nid");
        echo   '</span>';
        echo '</h2>';

        if (isset($view->result[$id]->field_body)) {
          echo '<div class="story-body">' . render($view->result[$id]->field_body) . '</div>';  
        }

        echo '<div class="post-row ' . $classes_array[$id] . '" data-story-nid="' . $this_desk_nid . '">';
        echo $view->style_plugin->rendered_fields[$id]['rendered_entity'];
        echo '</div>';
      }
      else {
        echo '<div class="post-row ' . $classes_array[$id] . '" data-story-nid="' . $this_desk_nid . '">';
        echo $row;
        echo '</div>';
      }

    ?>

    <?php $last_desk_nid = $this_desk_nid; ?>

  <?php endforeach; ?>

</div>
