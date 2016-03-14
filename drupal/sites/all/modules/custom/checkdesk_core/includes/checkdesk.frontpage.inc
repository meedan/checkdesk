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
        $title = t('New and updated stories');
        $output .= _checkdesk_container_markup($title, $view_output);
    }
    // Most popular stories
    $most_popular = _checkdesk_most_popular_stories(TRUE);
    if (count($most_popular)) {
        // $output .= '<h3>' . t('Most popular') . '</h3>';
        $title = t('Most popular');
        $view_output = views_embed_view('most_popular', 'block', implode('+', $most_popular));

        $output .= _checkdesk_container_markup($title, $view_output);
    }
    return $output;
}


/**
 * Return view output with container markup
 * @param $title
 * @param $view_output
 * @return html output
 */
function _checkdesk_container_markup($title, $view_output) {
    $output = '';
    $output .= '<section class="cd-container">';
    $output .= '<div class="cd-container-inner">';
    if (!empty($title)) {
        $output .= '<div class="cd-container-header">';
        $output .= '<h2 class="cd-container-header-title">' . $title . '</h2>';
        $output .= '</div>';
    }
    $output .= '<div class="cd-container-body">';
    $output .= $view_output;
    $output .= '</div>';
    $output .= '</section>';

    return $output;
}
