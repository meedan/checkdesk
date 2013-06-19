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
      // Show report activity
      $('.report-activity > header').unbind('click').click(function(event) {
        var target = $(this),
            element = target.parent();
        if (element.find('.activity-wrapper').is(':visible')) {
          element.find('.activity-wrapper').slideUp('fast');
          element.removeClass('open');
        }
        else {
          element.find('.activity-wrapper').slideDown('fast');
          element.addClass('open');
        }
        return false;
      });

      // Remove duplicates added incrementally by views_autorefresh after loading more content with views_load_more
      $('.view-liveblog').unbind('views_load_more.new_content').bind('views_load_more.new_content', function(event, content) {
        $(content).find('section.node-post').each(function() {
          $('.view-liveblog #' + $(this).attr('id')).eq(0).parents('.views-row').remove();
        });
      });
      $('.view-desk-reports').unbind('views_load_more.new_content').bind('views_load_more.new_content', function(event, content) {
        $(content).find('.report-row-container').each(function() {
          $('.view-desk-reports #' + $(this).attr('id')).eq(0).parents('.views-row').remove();
        });
      });

      // If a new update incrementally added has the same story as the next update, group them
      $('.view-liveblog', context).unbind('autorefresh.incremental').bind('autorefresh.incremental', function(event, count) {
        if (count > 0) {
          var first_new = $(this).find('.posts:eq(0) .desk').eq(count - 1);
          var first_old = $(this).find('.posts:eq(1) .desk:first');
          if (first_new.find('.post-row').data('story-nid') === first_old.find('.post-row').data('story-nid')) {
            first_old.next('.related-updates').remove();
            first_old.remove();
          }
        }
      });

      // scroll to the bottom of modal when interacting with report actions
      // $('#modalContent #report-actions a').click(function (event) {
      // 	$('.modal-body').animate({
      //       scrollTop: 400
      //     }, 'slow');
      // });

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

      // Resize reports sidebar
      $(window).resize(function() {
        var $sidebar = $('#sidebar-first'),
            offset = $sidebar.offset(),
            total = $(window).height(),
            height = total - offset.top;
        $sidebar.find('.view-desk-reports').height(height);
      });
      $(window).trigger('resize');

      // close panel
      $('#close').click(function(event) {
        $('.panel-content').hide();
      });

    }
  };

}(jQuery));
