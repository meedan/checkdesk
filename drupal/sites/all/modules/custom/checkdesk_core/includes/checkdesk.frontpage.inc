<?php


/**
 * 
 */
function _checkdesk_front_page() {
    $output = '';
    // Featured story
    $output .= views_embed_view('featured_story', 'block');
    // Sections
    $view = views_get_view('frontpage_sections');
    $view->get_total_rows = TRUE;
    $view_output = $view->preview('block');
    $total_rows = $view->total_rows;
    $view->destroy();
    if ($total_rows) {
        $output .= '<h3>' . t('Sections') . '</h3>';
        $output .= $view_output;
    }
    // New and updated stories
    $view = views_get_view('recent_stories_by_tag');
    $view->set_arguments(array('all'));
    $view->get_total_rows = TRUE;
    $view_output = $view->preview('block');
    $total_rows = $view->total_rows;
    $view->destroy();
    if ($total_rows) {
        $output .= '<h3>' . t('New and updated stories') . '</h3>';
        $output .= $view_output;
    }
    // Most popular stories
    $most_popular = _checkdesk_most_popular_stories(TRUE);
    if (count($most_popular)) {
        $output .= '<h3>' . t('Most popular') . '</h3>';
        $output .= views_embed_view('most_popular', 'block', implode('+', $most_popular));
    }
    return $output;
}
