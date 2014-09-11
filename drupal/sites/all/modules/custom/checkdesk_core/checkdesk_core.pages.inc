<?php


/**
 * Render collaborate page.
 *
 * @parm object $node
 *    story node object
 *
 * @return  
 *   Return a story collaboration page.
 */
function _checkdesk_story_collaboration($node) {
  $output = drupal_render(node_view($node, 'checkdesk_collaborate'));
  return $output;
}

/**
 *
 *
 */
function _checkdesk_story_links($nid) {
  global $user;
  $items = array();
  if ($user->uid) {
    $items[] = array(
      'data' => l(t('Add a report'), 'node/add/media', array('query' => array('ref_nid' => $nid, drupal_get_destination()))),
      'class' => array('submit-report'),
    );

    if (user_access('create post content')) {
      $items[] = array(
        'data' => l(t('Compose update'), 'node/add/post', array('query' => array('story' => $nid, drupal_get_destination()))),
        'class' => array('compose-update'),
      );
    }
  }
  return theme('item_list', array('items' => $items, 'title' => '', 'attributes' => array('class' => 'story-collaborate-links')));
}

/**
 * List story collaborators 
 *  @param story_nid
 *
 */
function _checkdesk_story_get_collaborators($nid) {
  $output = '';
  //ToDO check node type
  $users = db_query('
    SELECT DISTINCT ha.uid, u.name, f.fid, f.uri 
    FROM {heartbeat_activity} ha 
    INNER JOIN {users} u ON ha.uid = u.uid 
    LEFT JOIN {file_managed} f ON u.picture = f.fid 
    WHERE nid_target = :nid AND message_id != :message_id
    ', array(':nid' => arg(1), ':message_id' => 'checkdesk_follow_story'))->fetchAll();
  if (count($users)) {
    $title = format_plural(count($users), '1 collaborator', '@count collaborators');
    $uitems = $pitems = array();
    foreach ($users as $user) {
      // split user name into first name and last
      $fullname = explode(' ', $user->name);
      $fname = array_shift($fullname);
      $uitems[] = l($fname, 'user/'. $user->uid);
      if (!empty($user->uri)) {
        $pitems[] = l('', 'user/'. $user->uid, array('html' => TRUE, 'attributes' => array('style' => 'background-image: url("' . image_style_url('activity_avatar', $user->uri). '")')));
      }
    }
    $output .= '<div class="story-collaborators-wrapper"><div class="story-collaborators"><span class="sc-users"><h3>' . $title . '</h3>' . implode(', ', $uitems) . '</span>';
    $output .= '<span class="sc-avatars">';
    foreach ($pitems as $pitem) {
      $output .= $pitem;
    }
    $output .= '</span></div></div>';
  }
  return $output;
}
