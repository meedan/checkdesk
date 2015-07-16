/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';
  
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
          // top position of sidebar
          var top = parseInt($('#sidebar-first').css('top'), 10);
          // get height of view pager and header
          var pagerHeight = $('.view-desk-reports .pager-load-more').not('.pager-load-more-empty').outerHeight(true);
          var headerHeight = $('.view-desk-reports #incoming-reports-filters').outerHeight(true) + $('.view-desk-reports .view-header').outerHeight(true);
          // minus view pager and filter height out of the top value
          var difference = top + pagerHeight + headerHeight;
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

}(jQuery));


