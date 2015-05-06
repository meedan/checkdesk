/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';
  // NOTE: This code is intentionally NOT inside a Drupal behavior
  $(function () {
    // On initial page load, check to see if a modal should and can be restored.
    var hash  = window.location.hash.replace('#', ''),
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
      // Remove duplicates added incrementally by views_autorefresh after loading more content with views_load_more
      $('.view-desk-reports').unbind('views_load_more.new_content').bind('views_load_more.new_content', function(event, content) {
        $(content).find('.report-row-container').each(function() {
          $('.view-desk-reports #' + $(this).attr('id')).eq(0).parents('.views-row').remove();
        });
      });

      // Remove duplicates added incrementally by views_autorefresh after loading more content with views_load_more
      $('.view-liveblog').unbind('views_load_more.new_content').bind('views_load_more.new_content', function(event, content) {
        $(content).find('.desk').each(function() {
          $('.view-liveblog #' + $(this).attr('id')).eq(0).remove();
        });
      });

      // If an updated story already exists, remove it
      $('.view-liveblog', context).unbind('autorefresh.incremental').bind('autorefresh.incremental', function(event, count) {
        if (count > 0) {
          $(this).find('.posts:eq(0) .desk').each(function(desk) {
            $('.posts + .posts #' + $(this).attr('id')).remove();
          });
        }
      });

      // add class when end of fact-checking log is reached
      // and also when there is no pager
      $('.report-activity .view').bind('scroll', function() {
        if(($(this).scrollTop() + $(this).innerHeight() >= $(this)[0].scrollHeight) && $(this).children('.item-list').is(':empty')) {
          $(this).parents('.report-activity').addClass('end');
        } else if (($(this).scrollTop() + $(this).innerHeight() >= $(this)[0].scrollHeight) && $(this).children('.item-list').length == 0) {
          $(this).parents('.report-activity').addClass('end');
        }
        else {
          $(this).parents('.report-activity').removeClass('end');
        }
      });

      $('a.twitter').click(function(event) {
        event.preventDefault();
        // set URL
        var loc = $(this).attr('href'),
            // set title
            title  = $(this).attr('title');
        // open a window
        window.open('http://twitter.com/share?url=' + loc + '&text=' + title, 'twitterwindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
      });

      $('a.facebook').click(function(event) {
        event.preventDefault();
        // set URL
        var loc = $(this).attr('href'),
            // set title
            title  = $(this).attr('title');
        // open a window
        window.open('https://www.facebook.com/sharer.php?u=' + loc + '&t=' + title, 'facebookwindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
      });

      $('a.google').click(function(event) {
        event.preventDefault();
        // set URL
        var loc = $(this).attr('href'),
            // set title
            title  = $(this).attr('title');
        // open a window
        window.open('https://plus.google.com/share?url=' + loc + '&t=' + title, 'googlewindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
      });
    }
  };

  // filters for reports inside sidebar
  Drupal.behaviors.reportFilters = {
    attach: function (context, settings) {
      $('.panel-toggle').unbind('click').click(function(event) {
        var target = $(this),
            element = target.parent().attr('id');
        if ($('#'+ element + ' .panel-content').is(':visible')) {
          $('#'+ element + ' .panel-content').fadeOut('fast');
          $('#'+ element).removeClass('open');
        } else {
          $('#'+ element + ' .panel-content').fadeIn('fast');
          $('#'+ element).addClass('open');
        }
      });

      // hide when clicked outside
      $(document).mouseup(function(event){
        var container = $('.panel-content');
        if (container.has(event.target).length === 0) {
          container.hide();
        }
      });

      // Incoming reports sidebar
      $(window).resize(function() {
        if ($('.view-desk-reports .view-content').length) {
           // add fixed pixels to difference to adjust load more for ar
          var difference = $('#messages-container').offset().top + $('.view-desk-reports .pager').outerHeight(true) + 20;
          var height = $(window).height() - difference;
          $('.view-desk-reports .view-content').height(height);
        }
      });
      $(window).trigger('resize');
      $('.view-desk-reports').unbind('autorefresh.incremental').bind('autorefresh.incremental', function(event, count) {
        if (count > 0) {
          var $counter = $('.view-desk-reports .filters-summary p');
          var value = parseInt($counter.find('span').html(), 10) + count;
          $counter.html(Drupal.formatPlural(value, '<span>1</span> result. You can drag and drop it.', '<span>@count</span> results. Drag and drop the best ones.'));
          $(window).trigger('resize');
        }
      });

      // close panel
      $('#close').click(function(event) {
        $('.panel-content').hide();
      });

    }
  };

  // On the report log, group activities that were triggered by the same actor
  // It's hard to do it on the backend because of pagination
  Drupal.behaviors.groupReportActivities = {

    group: function(content) {
      var $previous = null;
      var $comment = null;
      var $status = null;
      var $delete_footnote = null;
      content.find('.activity-content:not(activity-grouped)').each(function() {
        // set comment
        if($(this).hasClass('new_comment_report')) {
          $comment = $(this);
        }
        // set status
        if($(this).hasClass('status_report')) {
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

    attach: function(context, settings) {

      // Group activities on page load
      Drupal.behaviors.groupReportActivities.group($('.view-activity-report', context));

      // Group activities when new content is loaded
      $('.view-activity-report', context).unbind('views_load_more.new_content').bind('views_load_more.new_content', function(event, content) {
        Drupal.behaviors.groupReportActivities.group($('.view-activity-report', context));
      });

      // Display the "Edit status" as a popover
      $('.report-activity-edit-status:not(.popover)', context).each(function() {

        // Create the popover for each radios group
        var $pop = $(this);
        $pop.hide();
        var $link = $('<span class="edit-status">' + Drupal.t('Edit Status') + '</span>');
        var $current = $pop.find('.current-status');
        $pop.parents('.comment-form').find('.form-submit').before($link);
        $pop.parents('.comment-form').find('.form-submit').before($current);
        $pop.addClass('popover');

        // Each status inside the popover
        $pop.find('label.option').each(function() {
          var name = $(this).prev('input').attr('value').toLowerCase().trim().replace(/\s+/, '-');
          $(this).attr('rel', name);
          $(this).addClass(name);
          $(this).parent().addClass(name);

          // A status is clicked
          $(this).click(function() {
            var rating = $(this).text(),
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
        $link.click(function(event) {
          $(this).toggleClass('active');
          $(this).parents('.comment-form').find('.popover').toggle();
          event.stopPropagation();
          return false;
        });
      });

      // Close all "edit status" popovers
      $('html').click(function() {
        $('.comment-form').find('.edit-status').removeClass('active');
        $('.comment-form').find('.popover').hide();
      });
    }
  };

  Drupal.behaviors.footnotes = {
    attach: function(context, settings) {
      $('textarea[class*=expanding]', context).filter(":visible").expanding();
    }
  }

  // This callback is invoked when a new footnote is added
  $.fn.footnoteCallback = function(nid, output) {
    var $form = $('#node-' + nid + ' .open section#comment-form');
    $form.hide();
    $form.appendTo($('html'));
    $('.open#report-activity-node-' + nid).replaceWith(output);
    $('.open#report-activity-node-' + nid + ' .item-nested-content').append($form);
    $form.show();
    $form.find('textarea').val('');
    //destory then re-assign expanding to fix issue #2119.
    $form.find('textarea[class*=expanding]').expanding('destroy');
    $form.find('textarea[class*=expanding]').expanding();
    // Scroll to new footnote
    $('html, body').animate({
        scrollTop: $('.open#report-activity-node-' + nid).offset().top - 150
    }, 'slow');
    Drupal.attachBehaviors($('#node-' + nid));
  };

}(jQuery));
