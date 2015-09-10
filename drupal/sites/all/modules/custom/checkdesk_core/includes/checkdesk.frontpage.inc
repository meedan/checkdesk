<?php


/**
 * 
 */
function _checkdesk_front_page() {
  $output = '';
  // Featured story
  $output .= views_embed_view('featured_story', 'block');
  // New and updated stories
  $output .= views_embed_view('recent_stories_by_tag', 'block', 'all');
  // Most popular stories
  $most_popular = _checkdesk_most_popular_stories(TRUE);
  if (count($most_popular)) {
    $output .= views_embed_view('most_popular', 'block', implode('+', $most_popular));
  }
  return $output;
}
