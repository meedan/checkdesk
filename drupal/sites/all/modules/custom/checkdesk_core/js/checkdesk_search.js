jQuery(function() {

    jQuery('#views-exposed-form-checkdesk-search-page .form-item-type .form-item div a').each(function() {
        var href = jQuery(this).attr('href');
        var new_href = href.split("?")[0].split("#")[0];
        if (href.indexOf('type=') != -1) {
            var type = href.match(/type=([^&]+)/)[1];
            new_href = new_href + '?type=' + type;
        }
        jQuery(this).attr('href', new_href);
    });

});