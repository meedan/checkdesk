(function ($) {

	/**
	   * Provide the HTML to create the modal dialog.
	  */
	  Drupal.theme.prototype.CToolsModalDialog = function () {
	    var html = '';


	    html += '<div id="ctools-modal">';
	    html += '<div class="ctools-modal-content">';
	    html += '<div class="modal">';
	    html += '  <div class="modal-header">';
	    html += '   <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>';
	    html += '   <h4><span id="modal-title" class="modal-title"></span></h4>';
	    html += '  </div>';
	    html += ' <div class="modal-body">';
	    html += '   <div id="modal-content" class="modal-content"></div>';
	    html += ' </div>';
	    html += '</div>';
	    html += '</div>';
	    html += '</div>';

	    return html;

	  }

	Drupal.behaviors.reports = {
		attach: function (context, settings) {
			// show report activity
			$('.report-activity > header').unbind('click').click(function(event) {
				var target = $(this);
				var element = target.parent().attr('id');
        		if ($('#'+ element + ' .activity-wrapper').is(':visible')) {
				  $('#'+ element + ' .activity-wrapper').slideUp('fast');
				  $('#'+ element).removeClass('open');
		        }
		        else {
				  $('#'+ element + ' .activity-wrapper').slideDown('fast');
				  $('#'+ element).addClass('open');
        		}
				return false;
			});

			$('a.twitter').click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href');
				// set title 
				var title  = $(this).attr('title');
				// open a window
				openShareWindow('twitter', loc, title);
			});

			$('a.facebook').click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href');
				// set title 
				var title  = $(this).attr('title');
				// open a window
				openShareWindow('facebook', loc, title);
			});

			$('a.google').click(function(event) {
				event.preventDefault();
				// set URL
				var loc = $(this).attr('href');
				// set title 
				var title  = $(this).attr('title');
				// open a window
				openShareWindow('google', loc, title);
			});
			
			function openShareWindow(service, loc, title) {
				if(service == 'twitter') {
					window.open('http://twitter.com/share?url=' + loc + '&text=' + title, 'twitterwindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');	
				}
				if(service == 'facebook') {
					window.open('https://www.facebook.com/sharer.php?u=' + loc + '&t=' + title, 'facebookwindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');		
				}
				if(service == 'google') {
					window.open('https://plus.google.com/share?url=' + loc + '&t=' + title, 'googlewindow', 'height=450, width=550, top='+($(window).height()/2 - 225) +', left='+$(window).width()/2 +', toolbar=0, location=0, menubar=0, directories=0, scrollbars=0');		
				}
			}
			
		}
	};


	// filters for reports inside sidebar
	Drupal.behaviors.reportFilters = {
		attach: function (context, settings) {
			$('.panel-toggle').unbind('click').click(function(event) {
				var target = $(this);
				var element = target.parent().attr('id');
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
			// set the height of the sidebar
			// var bodyHeight = $(window).height();
			// 	buffer = 300;
			// var bodyHeight = bodyHeight - buffer;
			// $('#incoming-reports').height(bodyHeight);
			
			// $(window).resize(function(){
			// 	var bodyHeight = $(window).height();
			// 	var bodyHeight = bodyHeight - buffer;
			// 	console.log(bodyHeight);
			// 	$('#incoming-reports').height(bodyHeight);
			// });

			// close panel
			$('#close').click(function(event) {
				$('.panel-content').hide();
			});

		}
	};

})(jQuery);
