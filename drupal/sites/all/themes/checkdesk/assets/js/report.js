/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';
  // NOTE: This code is intentionally NOT inside a Drupal behavior
  $(function () {
    // On initial page load, check to see if a modal should and can be restored.
    var hash = window.location.hash.replace('#', ''),
            parts = hash ? hash.split('-') : null,
            $link;

    if (parts && parts[0] === 'report' && !isNaN(parseInt(parts[1], 10))) {
      $link = $('#' + hash + ' .report-detail-link a');

      if ($link) {
        $link.click();
      }
    }
  });

  Drupal.behaviors.reports = {
    attach: function (context, settings) {
      // add class when end of fact-checking log is reached
      // and also when there is no pager
      $('.report-activity .view').bind('scroll', function () {
        if (($(this).scrollTop() + $(this).innerHeight() >= $(this)[0].scrollHeight) && $(this).children('.item-list').is(':empty')) {
          $(this).parents('.report-activity').addClass('end');
        } else if (($(this).scrollTop() + $(this).innerHeight() >= $(this)[0].scrollHeight) && $(this).children('.item-list').length == 0) {
          $(this).parents('.report-activity').addClass('end');
        }
        else {
          $(this).parents('.report-activity').removeClass('end');
        }
      });

      $('a.twitter').click(function (event) {
        event.preventDefault();
        // set URL
        var loc = $(this).attr('href'),
                // set title
                title = $(this).attr('title');
        // open a window
        window.open('http://twitter.com/share?url=' + loc + '&text=' + title, 'twitterwindow', 'height=450, width=550, top=' + ($(window).height() / 2 - 225) + ', left=' + $(window).width() / 2 + ', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
      });

      $('a.facebook').click(function (event) {
        event.preventDefault();
        // set URL
        var loc = $(this).attr('href'),
                // set title
                title = $(this).attr('title');
        // open a window
        window.open('https://www.facebook.com/sharer.php?u=' + loc + '&t=' + title, 'facebookwindow', 'height=450, width=550, top=' + ($(window).height() / 2 - 225) + ', left=' + $(window).width() / 2 + ', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
      });

      $('a.google').click(function (event) {
        event.preventDefault();
        // set URL
        var loc = $(this).attr('href'),
                // set title
                title = $(this).attr('title');
        // open a window
        window.open('https://plus.google.com/share?url=' + loc + '&t=' + title, 'googlewindow', 'height=450, width=550, top=' + ($(window).height() / 2 - 225) + ', left=' + $(window).width() / 2 + ', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
      });
    }
  };

  // filters for reports inside sidebar
  Drupal.behaviors.reportFilters = {
    attach: function (context, settings) {
      
      // Hide filters and show filter button on incoming reports sidebar
      if ($('.view-display-id-incoming_reports').length) {
        // Show filters toggle button
          $('.content-filter .filters-toggle').removeClass('element-hidden');
          // By default collapse all filters
          $('.content-filter .filters-toggle').parent().find('.filter-list').children().not('#edit-keys-wrapper').hide();

      }

      // Incoming reports sidebar
      $(window).resize(function () {
        if ($('.view-display-id-incoming_reports .view-content').length) {
          // top position of sidebar
          var top = parseInt($('#sidebar-first').css('top'), 10);
          // get height of view pager and header
          var pagerHeight = $('.view-display-id-incoming_reports .pager-load-more').not('.pager-load-more-empty').outerHeight(true);
          var headerHeight = $('.view-display-id-incoming_reports .view-filters').outerHeight(true) + $('.view-display-id-incoming_reports .control-container').outerHeight(true);
          // minus view pager and filter height out of the top value
          var difference = top + pagerHeight + headerHeight;
          var height = $(window).height() - difference;
          $('.view-display-id-incoming_reports .view-content').height(height);
        }
      });
      $(window).trigger('resize');

      // close panel
      $('#close').click(function (event) {
        $('.panel-content').hide();
      });

    }
  };

  // On the report log, group activities that were triggered by the same actor
  // It's hard to do it on the backend because of pagination
  Drupal.behaviors.groupReportActivities = {
    group: function (content) {
      var $previous = null;
      var $comment = null;
      var $status = null;
      var $delete_footnote = null;
      content.find('.activity-content:not(activity-grouped)').each(function () {
        // set comment
        if ($(this).hasClass('new_comment_report')) {
          $comment = $(this);
        }
        // set status
        if ($(this).hasClass('status_report')) {
          $status = $(this);
        }

        // group if actor and timestamps are the same
        if ($status !== null && $comment !== null && $comment.hasClass('new_comment_report') && $status.hasClass('status_report') &&
                $comment.find('.actor').text() === $status.find('.actor').text() && $comment.find('.timestamp').attr('datetime') === $status.find('.timestamp').attr('datetime')) {
          $comment.find('.actor').html('');
          $comment.find('.timestamp').html('');
          $comment.find('.report-verification-footnote').parent().parent().addClass('grouped-item');
          // $comment.parents('.views-row').css('border-top', '0 none');
          $status.addClass('activity-parent');
          $comment.addClass('activity-grouped');
          // move the status before the comment
          $comment.parent().before($status.parent());

          // move the trash icon for deleting comments to the parent
          // Currently doesn't delete both items
          // $status.find('.timestamp').after($comment.find('.inline-delete-item'));
        }
      });
    },
    attach: function (context, settings) {

      // Group activities on page load
      Drupal.behaviors.groupReportActivities.group($('.view-activity-report', context));

      // Group activities when new content is loaded
      $('.view-activity-report', context).unbind('views_load_more.new_content').bind('views_load_more.new_content', function (event, content) {
        Drupal.behaviors.groupReportActivities.group($('.view-activity-report', context));
      });

      // Display the "Edit status" as a popover
      $('.report-activity-edit-status:not(.popover)', context).each(function () {

        // Create the popover for each radios group
        var $pop = $(this);
        $pop.hide();
        var $link = $('<span class="edit-status">' + Drupal.t('Edit Status') + '</span>');
        var $current = $pop.find('.current-status');
        $pop.parents('.comment-form').find('.form-submit').before($link);
        $pop.parents('.comment-form').find('.form-submit').before($current);
        $pop.addClass('popover');

        // Each status inside the popover
        $pop.find('label.option').each(function () {
          var name = $(this).prev('input').attr('value').toLowerCase().trim().replace(/\s+/, '-');
          $(this).attr('rel', name);
          $(this).addClass(name);
          $(this).parent().addClass(name);

          // A status is clicked
          $(this).click(function () {
            var rating = $(this).html(),
                    rel = $(this).attr('rel'),
                    $link = $(this).parents('.comment-form').find('.edit-status'),
                    $pop = $(this).parents('.comment-form').find('.popover'),
                    $current = $(this).parents('.comment-form').find('.current-status');
            $current.html(rating);
            $current.attr('class', 'current-status');
            $current.addClass(rel);
            $current.css('display', 'inline-block');
            $link.html(Drupal.t('New Status'));
            if (!$pop.hasClass('updated')) {
              $pop.addClass('updated');
            }
            $link.click();
          });
        });

        // 'Edit Status' link is clicked
        $link.click(function (event) {
          $(this).toggleClass('active');
          $(this).parents('.comment-form').find('.popover').toggle();
          event.stopPropagation();
          return false;
        });
      });

      // Close all "edit status" popovers
      $('html').click(function () {
        $('.comment-form').find('.edit-status').removeClass('active');
        $('.comment-form').find('.popover').hide();
      });
    }
  };

  Drupal.behaviors.footnotes = {
    attach: function (context, settings) {
      $('textarea[class*=expanding]', context).filter(":visible").expanding();
    }
  }

  // This callback is invoked when a new footnote is added
  $.fn.footnoteCallback = function (nid, output,  type) {
    var $form = $('#node-' + nid + ' .open section#comment-form');
    $form.hide();
    $form.appendTo($('html'));
    $('.open#' + type + '-activity-node-' + nid).replaceWith(output);
    $('.open#' + type + '-activity-node-' + nid + ' .item-nested-content').append($form);
    $form.show();
    $form.find('textarea').val('');
    //destory then re-assign expanding to fix issue #2119.
    $form.find('textarea[class*=expanding]').expanding('destroy');
    $form.find('textarea[class*=expanding]').expanding();
    // Scroll to new footnote
    $('html, body').animate({
      scrollTop: $('.open#' + type + '-activity-node-' + nid).offset().top - 150
    }, 'slow');
    Drupal.attachBehaviors($('#node-' + nid));
  };

}(jQuery));
