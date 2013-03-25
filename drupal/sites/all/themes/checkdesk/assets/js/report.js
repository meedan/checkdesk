/*jslint nomen: true, plusplus: true, todo: true, white: true, browser: true, indent: 2 */
(function ($) {
  'use strict';

	Drupal.behaviors.reports = {
		attach: function (context) {
		  // Show report activity
      $('.report-activity > header', context).unbind('click').click(function(event) {
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
      $('.view-liveblog', context).unbind('views_load_more.new_content').bind('views_load_more.new_content', function(event, content) {
        $(content).find('section.node-post').each(function() {
          $('.view-liveblog #' + $(this).attr('id')).eq(0).parents('.views-row').remove();
        });
      });
      $('.view-desk-reports', context).unbind('views_load_more.new_content').bind('views_load_more.new_content', function(event, content) {
        $(content).find('.report-row-container').each(function() {
          $('.view-desk-reports #' + $(this).attr('id')).eq(0).parents('.views-row').remove();
        });
      });

			$('a.twitter', context).click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href'),
				    // set title
				    title  = $(this).attr('title');
				// open a window
				openShareWindow('twitter', loc, title);
			});

			$('a.facebook', context).click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href'),
				    // set title
				    title  = $(this).attr('title');
				// open a window
				openShareWindow('facebook', loc, title);
			});

			$('a.google', context).click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href'),
				    // set title
				    title  = $(this).attr('title');
				// open a window
				openShareWindow('google', loc, title);
			});

			function openShareWindow(service, loc, title) {
				if(service === 'twitter') {
					window.open('http://twitter.com/share?url=' + loc + '&text=' + title, 'twitterwindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
				}
				if(service === 'facebook') {
					window.open('https://www.facebook.com/sharer.php?u=' + loc + '&t=' + title, 'facebookwindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
				}
				if(service === 'google') {
					window.open('https://plus.google.com/share?url=' + loc + '&t=' + title, 'googlewindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');
				}
			}

		}
	};


	// filters for reports inside sidebar
	Drupal.behaviors.reportFilters = {
		attach: function (context) {
			$('.panel-toggle', context).unbind('click').click(function(event) {
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
      // FIXME: Using $(document) here will not work when behavior is
      //        re-attached. Need to make use of context or use a static variable.
			// hide when clicked outside
			$(document).mouseup(function(event){
				var container = $('.panel-content');
				if (container.has(event.target).length === 0) {
					container.hide();
				}
			});
			// set the height of the sidebar
			var bodyHeight = $(window).height(),
				  buffer = 160;
			bodyHeight = bodyHeight - buffer;
			$('#sidebar-first.column .view-desk-reports', context).height(bodyHeight);

      // FIXME: Using $(window) here will not work when behavior is
      //        re-attached. Need to make use of context or use a static variable.
			$(window).resize(function(){
				var bodyHeight = $(window).height();
				bodyHeight = bodyHeight - buffer;
				// console.log(bodyHeight);
				$('#sidebar-first.column .view-desk-reports', context).height(bodyHeight);
			});

      // FIXME: Using $(window) here will not work when behavior is
      //        re-attached. Need to make use of context or use a static variable.
			// close panel
			$('#close', context).click(function(event) {
				$('.panel-content').hide();
			});

		}
	};

}(jQuery));
