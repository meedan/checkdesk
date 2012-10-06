<?php

/**
 * Returns navigational links based on a menu tree
 */
function checkdesk_menu_navigation_links($tree, $lvl = 0) {
  $result = array();

  if(count($tree) > 0) {
	foreach($tree as $id => $item) {
	  $new_item = array('title' => $item['link']['title'], 'link_path' => $item['link']['link_path'], 'href' => $item['link']['href']);
	  
	  // Dont do drugs and don't do any levels deeper then 1
	  if($lvl < 1)
		$new_item['below'] = checkdesk_menu_navigation_links($item['below'], $lvl+1);
	  
	  $result['menu-'. $item['link']['mlid']] = $new_item;
	}
  }
  
  return $result;
}