
jQuery(function() {
    jQuery("#edit-cd-field-old-stories").chosen();

    if (jQuery('#edit-cd-field-old-stories-check').is(':checked')) {
        jQuery('#edit-cd-field-old-stories').attr('disabled', false).trigger("chosen:updated");
        jQuery('#edit-field-desk-und').attr('disabled', true).trigger("chosen:updated");
        jQuery('#edit-field-stories-und').attr('disabled', true).trigger("chosen:updated");

    }
    else {
        jQuery('#edit-field-desk-und').attr('disabled', false).trigger("chosen:updated");
        jQuery('#edit-field-stories-und').attr('disabled', false).trigger("chosen:updated");
        jQuery('#edit-cd-field-old-stories').attr('disabled', true).trigger("chosen:updated");
    }
    // Js for post form
    jQuery('#edit-cd-field-old-stories-check').click(function(e) {
        if (jQuery(this).is(':checked')) {
            jQuery('#edit-field-desk-und').val('_none');
            jQuery('#edit-field-desk-und').attr('disabled', true).trigger("chosen:updated");
            jQuery('#edit-cd-field-old-stories').attr('disabled', false).trigger("chosen:updated");
        }
        else {
            jQuery('#edit-cd-field-old-stories').val('_none');
            jQuery('#edit-field-desk-und').attr('disabled', false).trigger("chosen:updated");
            jQuery('#edit-cd-field-old-stories').attr('disabled', true).trigger("chosen:updated");
        }
    });
    // Js for media form
    jQuery('#edit-cd-field-old-stories-check').click(function(e) {
        if (jQuery(this).is(':checked')) {
            jQuery('#edit-field-stories-und').val('_none');
            jQuery('#edit-field-stories-und').attr('disabled', true).trigger("chosen:updated");
            jQuery('#edit-cd-field-old-stories').attr('disabled', false).trigger("chosen:updated");
        }
        else {
            jQuery('#edit-cd-field-old-stories').val('_none');
            jQuery('#edit-field-stories-und').attr('disabled', false).trigger("chosen:updated");
            jQuery('#edit-cd-field-old-stories').attr('disabled', true).trigger("chosen:updated");
        }
    });
});
