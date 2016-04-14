/**
 * Created by melsawy on 4/27/15.
 */
(function ($) {
    'use strict';

    jQuery('#edit-field-stories-und').change(function() {
        var story_id = jQuery(this).val();
        var report_id = 0;
        if (typeof Drupal.settings.checkdesk_reports_duplicates !== 'undefined') {
            report_id = Drupal.settings.checkdesk_reports_duplicates.report_nid;
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

    // Function to retrieve a media preview from a URL.
    function getMediaPreview() {
        var $input = $('#edit-field-link-und-0-url'),
            url = $input.val().trim();

        var report_id = 0;
        if (typeof Drupal.settings.checkdesk_reports_duplicates !== 'undefined') {
            report_id = Drupal.settings.checkdesk_reports_duplicates.report_nid;
        }
        var story_id = jQuery('#edit-field-stories-und').val();
        $.ajax({
            url: Drupal.settings.basePath + Drupal.settings.pathPrefix + 'checkdesk/media-preview?' + parseInt(Math.random() * 1000000000, 10),
            data: { url : url, report_id : report_id, story_id : story_id },
            dataType: 'json',
            success: function (data) {
                if (data.error) {
                } else {

                    // Fix geolocation Google maps grey area bug.
                    try {
                        $.each(Drupal.settings.geolocation.defaults, function(i) {
                            google.maps.event.trigger(Drupal.geolocation.maps[i], "resize");
                        });
                    }
                    catch (e) {
                        // no maps, nothing to do.
                    }

                    $('#checkdesk_report_duplicate').hide();
                    if (data.duplicates.duplicate) {
                        $('#checkdesk_report_duplicate').show().html(data.duplicates.msg);
                        if (data.duplicates.duplicate_story) {
                            // Report already exists in same story
                            // Hide submit button
                            $('#edit-submit').hide();
                        }
                    }
                }
            },
            complete: function (xhr, textStatus) {
            }
        });
    }

    Drupal.behaviors.checkdeskBookmarklet = {
        attach: function(context, settings) {
            // Disable submit button if link field is empty
            $('#edit-submit', context).click(function() {
                if (!$('#edit-field-link-und-0-url').val()) {
                    return false;
                }
            });
        }
    };

})(jQuery);
