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

      if ($this_desk_nid) {
        if ($this_desk_nid != $last_desk_nid) {
          if ($last_desk_nid) {
            echo "</div> <!-- /desk -->\n";
            echo theme('checkdesk_related_updates_bar', array('story' => node_load($last_desk_nid)));
            echo "<div class=\"desk\">\n";
          }

          echo '<article class="story">';
          echo '<h1>';
          echo   '<span class="field-content">';
          echo     l($view->result[$id]->node_field_data_field_desk_title, "node/$this_desk_nid");
          echo   '</span>';
          echo '</h1>';

          if(isset($view->result[$id]->field_body)) {
            echo '<div class="story-body">' . render($view->result[$id]->field_body) . '</div>';  
          }

          echo '</article>';
          echo '<div class="updates">';
          echo '<div class="update-row ' . $classes_array[$id] . '" data-story-nid="' . $this_desk_nid . '">';
          echo $row;
          echo '</div>';
          echo '</div>';
        }
      }

      // If an update is not related to any story, just print it
      else {
        if ($last_desk_nid) {
          echo '</div>';
        }
        echo '<div class="post-row ' . $classes_array[$id] . '" data-story-nid="0">';
        echo $row;
        echo '</div>';
      }
    ?>

    <?php $last_desk_nid = $this_desk_nid; ?>

  <?php endforeach; ?>

  </div> <!-- /desk -->

  <?php if ($last_desk_nid): // At least one desk is needed ?>
    <?php echo theme('checkdesk_related_updates_bar', array('story' => node_load($last_desk_nid))); ?>
  <?php endif; ?>

</div>
