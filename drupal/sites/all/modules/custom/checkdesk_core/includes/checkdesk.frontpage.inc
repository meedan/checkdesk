<?php


/**
 * 
 */
function _checkdesk_front_page() {
  $output = '';
  // Featured story
  $output .= views_embed_view('featured_story', 'block');
  // Sections
  $output .= '<h3>'. t('Sections') . '</h3>';
  $output .= views_embed_view('frontpage_sections', 'block');
  // New and updated stories
  $output .= '<h3>'. t('New and updated stories') . '</h3>';
  $output .= views_embed_view('recent_stories_by_tag', 'block', 'all');
  // Most popular stories
  $most_popular = _checkdesk_most_popular_stories(TRUE);
  if (count($most_popular)) {
    $output .= '<h3>'. t('Most popular') . '</h3>';
    $output .= views_embed_view('most_popular', 'block', implode('+', $most_popular));
  }
  return $output;
}
