<?php
// Group consecutive updates together by desk
$this_desk_nid = 0;
$last_desk_nid = 0;
$desk_wrapper_needs_close = FALSE;
?>
<div class="posts">

  <?php foreach ($rows as $id => $row): ?>
    <?php
      $this_desk_nid = $view->result[$id]->node_field_data_field_desk_nid;

      if ($this_desk_nid) {
        // The first update on this desk
        if ($this_desk_nid != $last_desk_nid) {
          // Close the previous opened wrapper
          if ($desk_wrapper_needs_close) {
            echo '</div>';
            echo theme('checkdesk_related_updates_bar', array('story' => node_load($this_desk_nid)));
          }

          $desk_wrapper_needs_close = TRUE; // We are about to open a new <div class="desk">

          echo '<div class="desk">';
          echo   '<article class="story">';
          echo     '<h2>';
          echo       '<span class="field-content">';
          echo         l($view->result[$id]->node_field_data_field_desk_title, "node/$this_desk_nid");
          echo       '</span>';
          echo     '</h2>';

          if (isset($view->result[$id]->field_body)) {
            echo   '<div class="story-body">' . render($view->result[$id]->field_body) . '</div>';  
          }

          echo   '</article>';
          echo   '<div class="post-row ' . $classes_array[$id] . '" data-story-nid="' . $this_desk_nid . '">';
          echo     $row;
          echo   '</div>';
        }
        // All other updates on this desk
        else {
          echo '<div class="desk">';
          echo   '<h2>BELONGS WITH PREVIOUS</h2>';
          echo  $row;
          echo '</div>';
        }
      }
      // If an update is not related to any story, just print it
      else {
        // Close the previous opened wrapper
        if ($desk_wrapper_needs_close) {
          echo '</div>';
          echo theme('checkdesk_related_updates_bar', array('story' => node_load($this_desk_nid)));
        }

        $desk_wrapper_needs_close = FALSE;

        echo '<div class="desk">';
        echo   '<div class="post-row ' . $classes_array[$id] . '" data-story-nid="0">';
        echo     $row;
        echo   '</div>';
        echo '</div>';
      }
    ?>

    <?php $last_desk_nid = $this_desk_nid; ?>

  <?php endforeach; ?>

  <?php
    // Close the previous opened wrapper
    if ($desk_wrapper_needs_close) {
      echo '</div>';
      echo theme('checkdesk_related_updates_bar', array('story' => node_load($this_desk_nid)));
    }
  ?>

</div>
