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
        drupal_add_js('
        jQuery(function() {
            jQuery(".view-recent-stories-by-tag li").hover(
                function () {
                    jQuery(this).find("div.cd-item-content").toggleClass("u-faux-block-link-hover")
                }
            )
        });
        ', 'inline');
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
