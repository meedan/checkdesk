<?php

/**
 *
 */
function _checkdesk_story_tabs($nid) {
  $items = array();
  $items[] = array(
    'data' => l(t('Updates'), 'node/'. $nid),
    'class' => array('story-tab-updates'),
  );
  $items[] = array(
    'data' => l(t('Collaboration'), 'story-collaboration/'. $nid),
    'class' => array('story-tab-collaboration'),
  );
  return theme('item_list', array('items' => $items, 'title' => '', 'attributes' => array('class' => 'story-tabs')));
}

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
    $items[] = array(
      'data' => l(t('Compose update'), 'node/add/post', array('query' => array('story' => $nid, drupal_get_destination()))),
      'class' => array('compose-update'),
    );
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
    WHERE nid_target = :nid
    ', array(':nid' => arg(1)))->fetchAll();
  if (count($users)) {
    $title = format_plural(count($users), '1 collaborator', '@count collaborators');
    $uitems = $pitems = array();
    foreach ($users as $user) {
      $uitems[] = l($user->name, 'user/'. $user->uid);
      $avatar = theme('image_style', array('style_name' => 'activity_avatar', 'path' => $user->uri, 'getsize' => TRUE, 'attributes' => array('class' => 'user-avatar')));
      $pitems[] = l($avatar, 'user/'. $user->uid, array('html' => TRUE));
    }
    $output .= theme('item_list', array('items' => $uitems, 'title' => $title, 'attributes' => array('class' => 'story-collaborators-users')));
    $output .= theme('item_list', array('items' => $pitems, 'title' => '', 'attributes' => array('class' => 'story-collaborators-avatars')));
  }
  return $output;
}
