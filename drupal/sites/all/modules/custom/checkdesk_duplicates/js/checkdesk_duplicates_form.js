/**
 * Created by melsawy on 4/27/15.
 */
jQuery(function() {
    jQuery('#edit-field-stories-und').change(function() {
        var story_id = jQuery(this).val();
        var report_id = 0;
        if (typeof Drupal.settings.checkdesk_duplicates !== 'undefined') {
            report_id = Drupal.settings.checkdesk_duplicates.report_nid;
        }
        jQuery('#checkdesk_report_story_duplicate').hide();
        jQuery('#edit-submit').show();
        var url = jQuery('#edit-field-link-und-0-url').val().trim();
        jQuery.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'checkdesk/duplicate-report-story?' + parseInt(Math.random() * 1000000000, 10),
            data: { url : url, report_id : report_id, story_id : story_id },
            dataType: 'json',
            success: function (data) {
                if (data.duplicate) {
                    jQuery('#checkdesk_report_story_duplicate').show().addClass('error').html(data.msg);
                    jQuery('#edit-submit').hide();
                }
            },
            error: function (xhr, textStatus, error) {
 
            },
            complete: function (xhr, textStatus) {

            }
        });
    });
});