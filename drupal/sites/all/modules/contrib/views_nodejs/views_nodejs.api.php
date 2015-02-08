<?php

/**
 * @file
 * Views with node.js API Documentation
 */

/**
 * One can change some settings which are going to node.js.
 *
 * @param object $data
 *   Object with settings which are going to node.js channel.
 */
function hook_views_nodejs_channel_alter(&$data) {

  // For example one can change js callback for some view.
  if ($data->view_id == 'my_view') {
    $data->callback = 'mymoduleNewCallback';
  }

}
