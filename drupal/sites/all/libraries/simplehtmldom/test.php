<?php
// example of how to use basic selector to retrieve HTML contents
include('simple_html_dom.php');
 
// get DOM from URL or file
$html = file_get_html('http://www.facebook.com/AhmadMAbdullah/posts/10151075975752806');
print_r($html);

